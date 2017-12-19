/* $NetBSD: cpu_fdt.c,v 1.1.2.1 2017/06/21 18:10:40 snj Exp $ */

/*-
 * Copyright (c) 2017 Jared McNeill <jmcneill@invisible.ca>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: cpu_fdt.c,v 1.1.2.1 2017/06/21 18:10:40 snj Exp $");

#include <sys/param.h>
#include <sys/bus.h>
#include <sys/device.h>
#include <sys/systm.h>
#include <sys/kernel.h>

#include <dev/fdt/fdtvar.h>

#include <arm/cpu.h>

static int	cpu_fdt_match(device_t, cfdata_t, void *);
static void	cpu_fdt_attach(device_t, device_t, void *);

struct cpu_fdt_softc {
	device_t		sc_dev;
	int			sc_phandle;
};

CFATTACH_DECL_NEW(cpu_fdt, sizeof(struct cpu_fdt_softc),
	cpu_fdt_match, cpu_fdt_attach, NULL, NULL);

static int
cpu_fdt_match(device_t parent, cfdata_t cf, void *aux)
{
	const char * const compatible[] = {
		"arm,cortex-a5",
		"arm,cortex-a7",
		"arm,cortex-a8",
		"arm,cortex-a9",
		"arm,cortex-a12",
		"arm,cortex-a15",
		"arm,cortex-a17",
		"arm,cortex-a53",
		"arm,cortex-a57",
		"arm,cortex-a72",
		"arm,cortex-a73",
		NULL
	};
	struct fdt_attach_args * const faa = aux;
	int is_compatible;
	bus_addr_t mpidr;

	is_compatible = of_match_compatible(faa->faa_phandle, compatible);
	if (!is_compatible)
		return 0;

	/* XXX NetBSD requires all CPUs to be in the same cluster */
	if (fdtbus_get_reg(faa->faa_phandle, 0, &mpidr, NULL) != 0)
		return 0;
	const uint32_t bp_mpidr = armreg_mpidr_read();
	const u_int bp_clid = __SHIFTOUT(bp_mpidr, CORTEXA9_MPIDR_CLID);
	const u_int clid = __SHIFTOUT(mpidr, CORTEXA9_MPIDR_CLID);
	if (bp_clid != clid)
		return 0;

	return is_compatible;
}

static void
cpu_fdt_attach(device_t parent, device_t self, void *aux)
{
	struct cpu_fdt_softc * const sc = device_private(self);
	struct fdt_attach_args * const faa = aux;
	bus_addr_t mpidr;

	sc->sc_dev = self;
	sc->sc_phandle = faa->faa_phandle;

	if (fdtbus_get_reg(sc->sc_phandle, 0, &mpidr, NULL) != 0) {
		aprint_error(": missing 'reg' property\n");
		return;
	}

	/* Attach the CPU */
	cpu_attach(self, __SHIFTOUT(mpidr, CORTEXA9_MPIDR_CPUID));
}