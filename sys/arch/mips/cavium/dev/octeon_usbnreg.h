/*	$NetBSD: octeon_usbnreg.h,v 1.1 2015/04/29 08:32:01 hikaru Exp $	*/

/*
 * Copyright (c) 2007 Internet Initiative Japan, Inc.
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
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * USBN Registers
 */

#ifndef _OCTEON_USBNREG_H_
#define _OCTEON_USBNREG_H_

/* ---- register addresses */

#define	USBN_INT_SUM				0x0001180068000000ULL
#define	USBN_INT_ENB				0x0001180068000008ULL
#define	USBN_CLK_CTL				0x0001180068000010ULL
#define	USBN_USBP_CTL_STATUS			0x0001180068000018ULL
#define	USBN_BIST_STATUS			0x00011800680007f8ULL
#define	USBN_CTL_STATUS				0x00016F0000000800ULL
#define	USBN_DMA_TEST				0x00016F0000000808ULL
#define	USBN_DMA0_INB_CHN0			0x00016F0000000818ULL
#define	USBN_DMA0_INB_CHN1			0x00016F0000000820ULL
#define	USBN_DMA0_INB_CHN2			0x00016F0000000828ULL
#define	USBN_DMA0_INB_CHN3			0x00016F0000000830ULL
#define	USBN_DMA0_INB_CHN4			0x00016F0000000838ULL
#define	USBN_DMA0_INB_CHN5			0x00016F0000000840ULL
#define	USBN_DMA0_INB_CHN6			0x00016F0000000848ULL
#define	USBN_DMA0_INB_CHN7			0x00016F0000000850ULL
#define	USBN_DMA0_OUTB_CHN0			0x00016F0000000858ULL
#define	USBN_DMA0_OUTB_CHN1			0x00016F0000000860ULL
#define	USBN_DMA0_OUTB_CHN2			0x00016F0000000868ULL
#define	USBN_DMA0_OUTB_CHN3			0x00016F0000000870ULL
#define	USBN_DMA0_OUTB_CHN4			0x00016F0000000878ULL
#define	USBN_DMA0_OUTB_CHN5			0x00016F0000000880ULL
#define	USBN_DMA0_OUTB_CHN6			0x00016F0000000888ULL
#define	USBN_DMA0_OUTB_CHN7			0x00016F0000000890ULL

/* ---- register bits */

/* for USBN_INT_SUM and USBN_INT_ENB */
#define USBN_INT_XXX_63_38			UINT64_C(0xffffffc000000000)
#define	USBN_INT_ND4O_DPF			UINT64_C(0x0000002000000000)
#define	USBN_INT_ND4O_DPE			UINT64_C(0x0000001000000000)
#define	USBN_INT_ND4O_RPF			UINT64_C(0x0000000800000000)
#define	USBN_INT_ND4O_RPE			UINT64_C(0x0000000400000000)
#define USBN_INT_LTL_F_PF			UINT64_C(0x0000000200000000)
#define USBN_INT_LTL_F_PE			UINT64_C(0x0000000100000000)
#define USBN_INT_U2N_C_PE			UINT64_C(0x0000000080000000)
#define USBN_INT_U2N_C_PF			UINT64_C(0x0000000040000000)
#define USBN_INT_U2N_D_PF			UINT64_C(0x0000000020000000)
#define USBN_INT_U2N_D_PE			UINT64_C(0x0000000010000000)
#define USBN_INT_N2U_PE				UINT64_C(0x0000000008000000)
#define USBN_INT_N2U_PF				UINT64_C(0x0000000004000000)
#define USBN_INT_UOD_PF				UINT64_C(0x0000000002000000)
#define USBN_INT_UOD_PE				UINT64_C(0x0000000001000000)
#define USBN_INT_RQ_Q3_E			UINT64_C(0x0000000000800000)
#define USBN_INT_RQ_Q3_F			UINT64_C(0x0000000000400000)
#define USBN_INT_RQ_Q2_E			UINT64_C(0x0000000000200000)
#define USBN_INT_RQ_Q2_F			UINT64_C(0x0000000000100000)
#define USBN_INT_RG_FI_F			UINT64_C(0x0000000000080000)
#define USBN_INT_RG_FI_E			UINT64_C(0x0000000000040000)
#define USBN_INT_LT_FI_F			UINT64_C(0x0000000000020000)
#define USBN_INT_LT_FI_E			UINT64_C(0x0000000000010000)
#define USBN_INT_L2C_A_F			UINT64_C(0x0000000000008000)
#define USBN_INT_L2C_S_E			UINT64_C(0x0000000000004000)
#define USBN_INT_DCRED_F			UINT64_C(0x0000000000002000)
#define USBN_INT_DCRED_E			UINT64_C(0x0000000000001000)
#define USBN_INT_LT_PU_F			UINT64_C(0x0000000000000800)
#define USBN_INT_LT_PO_E			UINT64_C(0x0000000000000400)
#define USBN_INT_NT_PU_F			UINT64_C(0x0000000000000200)
#define USBN_INT_NT_PO_E			UINT64_C(0x0000000000000100)
#define USBN_INT_PT_PU_F			UINT64_C(0x0000000000000080)
#define USBN_INT_PT_PO_E			UINT64_C(0x0000000000000040)
#define USBN_INT_LR_PU_F			UINT64_C(0x0000000000000020)
#define USBN_INT_LR_PO_E			UINT64_C(0x0000000000000010)
#define USBN_INT_NR_PU_F			UINT64_C(0x0000000000000008)
#define USBN_INT_NR_PO_E			UINT64_C(0x0000000000000004)
#define USBN_INT_PR_PU_F			UINT64_C(0x0000000000000002)
#define USBN_INT_PR_PO_E			UINT64_C(0x0000000000000001)

#define USBN_CLK_CTL_XXX_63_18			UINT64_C(0xfffffffffffc0000)
#define USBN_CLK_CTL_HCLK_RST			UINT64_C(0x0000000000020000)
#define USBN_CLK_CTL_P_X_ON			UINT64_C(0x0000000000010000)
#define USBN_CLK_CTL_P_RCLK			UINT64_C(0x0000000000008000)
#define USBN_CLK_CTL_P_XENBN			UINT64_C(0x0000000000004000)
#define USBN_CLK_CTL_P_COM_ON			UINT64_C(0x0000000000002000)
#define USBN_CLK_CTL_P_C_SEL			UINT64_C(0x0000000000001800)
#define  SET_USBN_CLK_CTL_P_C_SEL(v) (((v)<<11) & USBN_CLK_CTL_P_C_SEL)
#define  GET_USBN_CLK_CTL_P_C_SEL(v) (((v) & USBN_CLK_CTL_P_C_SEL) >> 11)
#define USBN_CLK_CTL_CDIV_BYP			UINT64_C(0x0000000000000400)
#define USBN_CLK_CTL_SD_MODE			UINT64_C(0x0000000000000300)
#define USBN_CLK_CTL_S_BIST			UINT64_C(0x0000000000000080)
#define USBN_CLK_CTL_POR			UINT64_C(0x0000000000000040)
#define USBN_CLK_CTL_ENABLE			UINT64_C(0x0000000000000020)
#define USBN_CLK_CTL_PRST			UINT64_C(0x0000000000000010)
#define USBN_CLK_CTL_HRST			UINT64_C(0x0000000000000008)
#define USBN_CLK_CTL_DIVIDE			UINT64_C(0x0000000000000007)
#define  SET_USBN_CLK_CTL_DIVIDE(v) (((v)<<0) & USBN_CLK_CTL_DIVIDE)
#define  GET_USBN_CLK_CTL_DIVIDE(v) (((v) & USBN_CLK_CTL_DIVIDE) >> 0)
/* CN50xx extension */
#define USBN_CLK_CTL_DIVIDE2			UINT64_C(0x00000000000c0000)
#define  SET_USBN_CLK_CTL_DIVIDE2(v) (((v)<<18) & USBN_CLK_CTL_DIVIDE2)
#define  GET_USBN_CLK_CTL_DIVIDE2(v) (((v) & USBN_CLK_CTL_DIVIDE2) >> 18)
#define USBN_CLK_CTL_P_RTYPE			UINT64_C(0x000000000000c000)
#define  SET_USBN_CLK_CTL_P_RTYPE(v) (((v)<<14) & USBN_CLK_CTL_P_RTYPE)
#define  GET_USBN_CLK_CTL_P_RTYPE(v) (((v) & USBN_CLK_CTL_P_RTYPE) >> 14)

#define USBN_USBP_CTL_STATUS_XXX_63_38		UINT64_C(0xffffffc000000000)
#define USBN_USBP_CTL_STATUS_BIST_DONE		UINT64_C(0x0000002000000000)
#define USBN_USBP_CTL_STATUS_BIST_ERR		UINT64_C(0x0000001000000000)
#define USBN_USBP_CTL_STATUS_TDATA_OUT		UINT64_C(0x0000000f00000000)
#define USBN_USBP_CTL_STATUS_SPARES		UINT64_C(0x00000000e0000000)
#define USBN_USBP_CTL_STATUS_USBC_END		UINT64_C(0x0000000010000000)
#define USBN_USBP_CTL_STATUS_USBP_BIST		UINT64_C(0x0000000008000000)
#define USBN_USBP_CTL_STATUS_TCLK		UINT64_C(0x0000000004000000)
#define USBN_USBP_CTL_STATUS_DP_PULLD		UINT64_C(0x0000000002000000)
#define USBN_USBP_CTL_STATUS_DM_PULLD		UINT64_C(0x0000000001000000)
#define USBN_USBP_CTL_STATUS_HST_MODE		UINT64_C(0x0000000000800000)
#define USBN_USBP_CTL_STATUS_TUNING		UINT64_C(0x0000000000780000)
#define USBN_USBP_CTL_STATUS_TX_BS_ENH		UINT64_C(0x0000000000040000)
#define USBN_USBP_CTL_STATUS_TX_BS_EN		UINT64_C(0x0000000000020000)
#define USBN_USBP_CTL_STATUS_LOOP_ENB		UINT64_C(0x0000000000010000)
#define USBN_USBP_CTL_STATUS_VTEST_ENB		UINT64_C(0x0000000000008000)
#define USBN_USBP_CTL_STATUS_BIST_ENB		UINT64_C(0x0000000000004000)
#define USBN_USBP_CTL_STATUS_TDATA_SEL		UINT64_C(0x0000000000002000)
#define USBN_USBP_CTL_STATUS_TADDR_IN		UINT64_C(0x0000000000001e00)
#define USBN_USBP_CTL_STATUS_TDATA_IN		UINT64_C(0x00000000000001fe)
#define USBN_USBP_CTL_STATUS_ATE_RESET		UINT64_C(0x0000000000000001)
/* CN50xx extension */
#define USBN_USBP_CTL_STATUS_TXRISETUNE		UINT64_C(0x8000000000000000)
#define USBN_USBP_CTL_STATUS_TXVREFTUNE		UINT64_C(0x7800000000000000)
#define USBN_USBP_CTL_STATUS_TXFSLSTUNE		UINT64_C(0x0780000000000000)
#define USBN_USBP_CTL_STATUS_TXHSXVTUNE		UINT64_C(0x0060000000000000)
#define USBN_USBP_CTL_STATUS_SQRXTUNE		UINT64_C(0x001c000000000000)
#define USBN_USBP_CTL_STATUS_COMPDISTUNE	UINT64_C(0x0003800000000000)
#define USBN_USBP_CTL_STATUS_OTGTUNE		UINT64_C(0x0000700000000000)
#define USBN_USBP_CTL_STATUS_OTGDISABLE		UINT64_C(0x0000080000000000)
#define USBN_USBP_CTL_STATUS_PORTRESET		UINT64_C(0x0000040000000000)
#define USBN_USBP_CTL_STATUS_DRVVBUS		UINT64_C(0x0000020000000000)
#define USBN_USBP_CTL_STATUS_LSBIST		UINT64_C(0x0000010000000000)
#define USBN_USBP_CTL_STATUS_FSBIST		UINT64_C(0x0000008000000000)
#define USBN_USBP_CTL_STATUS_HSBIST		UINT64_C(0x0000004000000000)

#define USBN_BIST_STATUS_XXX_63_3		UINT64_C(0xfffffffffffffff8)
#define USBN_BIST_STATUS_USBC_BIS		UINT64_C(0x0000000000000004)
#define USBN_BIST_STATUS_NIF_BIS		UINT64_C(0x0000000000000002)
#define USBN_BIST_STATUS_NOF_BIS		UINT64_C(0x0000000000000001)
/* CN50xx extension */
#define USBN_BIST_STATUS_U2NC_BIS		UINT64_C(0x0000000000000040)
#define USBN_BIST_STATUS_U2NF_BIS		UINT64_C(0x0000000000000020)
#define USBN_BIST_STATUS_E2HC_BIS		UINT64_C(0x0000000000000010)
#define USBN_BIST_STATUS_N2UF_BIS		UINT64_C(0x0000000000000008)

#define USBN_CTL_STATUS_XXX_63_6		UINT64_C(0xffffffffffffffc0)
#define USBN_CTL_STATUS_DMA_0PAG		UINT64_C(0x0000000000000020)
#define USBN_CTL_STATUS_DMA_STT			UINT64_C(0x0000000000000010)
#define USBN_CTL_STATUS_DMA_TEST		UINT64_C(0x0000000000000008)
#define USBN_CTL_STATUS_INV_A2			UINT64_C(0x0000000000000004)
#define USBN_CTL_STATUS_L2C_EMOD		UINT64_C(0x0000000000000003)

#define USBN_DMA_TEST_XXX_63_40			UINT64_C(0xffffff0000000000)
#define USBN_DMA_TEST_DONE			UINT64_C(0x0000008000000000)
#define USBN_DMA_TEST_REQ			UINT64_C(0x0000004000000000)
#define USBN_DMA_TEST_F_ADDR			UINT64_C(0x0000003ffff00000)
#define USBN_DMA_TEST_COUNT			UINT64_C(0x00000000000ffe00)
#define USBN_DMA_TEST_CHANNEL			UINT64_C(0x00000000000001f0)
#define USBN_DMA_TEST_BURST			UINT64_C(0x000000000000000f)

/* for USBN_DMA0_INB_CHN(0..7) */
#define USBN_DMA0_INB_CHNX_XXX_63_36		UINT64_C(0xfffffff000000000)
#define USBN_DMA0_INB_CHNX_ADDR			UINT64_C(0x0000000fffffffff)

/* for USBN_DMA0_OUTB_CHN(0..7) */
#define USBN_DMA0_OUTB_CHNX_XXX_63_36		UINT64_C(0xfffffff000000000)
#define USBN_DMA0_OUTB_CHNX_ADDR		UINT64_C(0x0000000fffffffff)

/* ---- snprintb */

#define	USBN_INT_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x25"		"ND4O_DPF\0" \
	"b\x24"		"ND4O_DPE\0" \
	"b\x23"		"ND4O_RPF\0" \
	"b\x22"		"ND4O_RPE\0" \
	"b\x21"		"LTL_F_PF\0" \
	"b\x20"		"LTL_F_PE\0" \
	"b\x1f"		"U2N_C_PE\0" \
	"b\x1e"		"U2N_C_PF\0" \
	"b\x1d"		"U2N_D_PF\0" \
	"b\x1c"		"U2N_D_PE\0" \
	"b\x1b"		"N2U_PE\0" \
	"b\x1a"		"N2U_PF\0" \
	"b\x19"		"UOD_PF\0" \
	"b\x18"		"UOD_PE\0" \
	"b\x17"		"RQ_Q3_E\0" \
	"b\x16"		"RQ_Q3_F\0" \
	"b\x15"		"RQ_Q2_E\0" \
	"b\x14"		"RQ_Q2_F\0" \
	"b\x13"		"RG_FI_F\0" \
	"b\x12"		"RG_FI_E\0" \
	"b\x11"		"LT_FI_F\0" \
	"b\x10"		"LT_FI_E\0" \
	"b\x0f"		"L2C_A_F\0" \
	"b\x0e"		"L2C_S_E\0" \
	"b\x0d"		"DCRED_F\0" \
	"b\x0c"		"DCRED_E\0" \
	"b\x0b"		"LT_PU_F\0" \
	"b\x0a"		"LT_PO_E\0" \
	"b\x09"		"NT_PU_F\0" \
	"b\x08"		"NT_PO_E\0" \
	"b\x07"		"PT_PU_F\0" \
	"b\x06"		"PT_PO_E\0" \
	"b\x05"		"LR_PU_F\0" \
	"b\x04"		"LR_PO_E\0" \
	"b\x03"		"NR_PU_F\0" \
	"b\x02"		"NR_PO_E\0" \
	"b\x01"		"PR_PU_F\0" \
	"b\x00"		"PR_PO_E\0"

#define	USBN_CLK_CTL_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"f\x12\x02"	"DIVIDE2\0" \
	"b\x11"		"HCLK_RST\0" \
	"b\x10"		"P_X_ON\0" \
	"b\x0f"		"P_RCLK\0" \
	"f\x0e\x02"	"P_RTYPE\0" \
	"b\x0e"		"P_XENBN\0" \
	"b\x0d"		"P_COM_ON\0" \
	"f\x0b\x02"	"P_C_SEL\0" \
	"b\x0a"		"CDIV_BYP\0" \
	"f\x08\x02"	"SD_MODE\0" \
	"b\x07"		"S_BIST\0" \
	"b\x06"		"POR\0" \
	"b\x05"		"ENABLE\0" \
	"b\x04"		"PRST\0" \
	"b\x03"		"HRST\0" \
	"f\x00\x03"	"DIVIDE\0"

#define	USBN_USBP_CTL_STATUS_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x3f"		"TXRISETUNE\0" \
	"f\x3b\x04"	"TXVREFTUNE\0" \
	"f\x37\x04"	"TXFSLSTUNE\0" \
	"f\x35\x02"	"TXHSXVTUNE\0" \
	"f\x32\x03"	"SQRXTUNE\0" \
	"f\x2f\x03"	"COMPDISTUNE\0" \
	"f\x2c\x03"	"OTGTUNE\0" \
	"b\x2b"		"OTGDISABLE\0" \
	"b\x2a"		"PORTRESET\0" \
	"b\x29"		"DRVVBUS\0" \
	"b\x28"		"LSBIST\0" \
	"b\x27"		"FSBIST\0" \
	"b\x26"		"HSBIST\0" \
	"b\x25"		"BIST_DONE\0" \
	"b\x24"		"BIST_ERR\0" \
	"f\x20\x04"	"TDATA_OUT\0" \
	"f\x1d\x03"	"SPARES\0" \
	"b\x1c"		"USBC_END\0" \
	"b\x1b"		"USBP_BIST\0" \
	"b\x1a"		"TCLK\0" \
	"b\x19"		"DP_PULLD\0" \
	"b\x18"		"DM_PULLD\0" \
	"b\x17"		"HST_MODE\0" \
	"f\x13\x04"	"TUNING\0" \
	"b\x12"		"TX_BS_ENH\0" \
	"b\x11"		"TX_BS_EN\0" \
	"b\x10"		"LOOP_ENB\0" \
	"b\x0f"		"VTEST_ENB\0" \
	"b\x0e"		"BIST_ENB\0" \
	"b\x0d"		"TDATA_SEL\0" \
	"f\x09\x04"	"TADDR_IN\0" \
	"f\x01\x08"	"TDATA_IN\0" \
	"b\x00"		"ATE_RESET\0"

#define	USBN_BIST_STATUS_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x06"		"U2NC_BIS\0" \
	"b\x05"		"U2NF_BIS\0" \
	"b\x04"		"E2HC_BIS\0" \
	"b\x03"		"N2UF_BIS\0" \
	"b\x02"		"USBC_BIS\0" \
	"b\x01"		"NIF_BIS\0" \
	"b\x00"		"NOF_BIS\0"

#define	USBN_CTL_STATUS_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x05"		"DMA_0PAG\0" \
	"b\x04"		"DMA_STT\0" \
	"b\x03"		"DMA_TEST\0" \
	"b\x02"		"INV_A2\0" \
	"f\x00\x02"	"L2C_EMOD\0"

#define	USBN_DMA_TEST_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x27"		"DONE\0" \
	"b\x26"		"REQ\0" \
	"f\x14\x12"	"F_ADDR\0" \
	"f\x09\x0b"	"COUNT\0" \
	"f\x04\x05"	"CHANNEL\0" \
	"f\x00\x04"	"BURST\0"

/* ---- bus_space */

#define	USBN_NUNITS				1
#define	USBN_BASE				0x0001180068000000ULL
#define USBN_SIZE				0x800

#define USBN_INT_SUM_OFFSET			0x00000000
#define USBN_INT_ENB_OFFSET			0x00000008
#define USBN_CLK_CTL_OFFSET			0x00000010
#define USBN_USBP_CTL_STATUS_OFFSET		0x00000018
#define USBN_BIST_STATUS_OFFSET			0x000007f8


/* ---- bus_space 2 */

#define	USBN_2_NUNITS				1
#define	USBN_2_BASE				0x00016F0000000800ULL
#define USBN_2_SIZE				0x098

#define USBN_CTL_STATUS_OFFSET			0x00000000
#define USBN_DMA_TEST_OFFSET			0x00000008
#define USBN_DMA0_INB_CHN0_OFFSET		0x00000018
#define USBN_DMA0_INB_CHN1_OFFSET		0x00000020
#define USBN_DMA0_INB_CHN2_OFFSET		0x00000028
#define USBN_DMA0_INB_CHN3_OFFSET		0x00000030
#define USBN_DMA0_INB_CHN4_OFFSET		0x00000038
#define USBN_DMA0_INB_CHN5_OFFSET		0x00000040
#define USBN_DMA0_INB_CHN6_OFFSET		0x00000048
#define USBN_DMA0_INB_CHN7_OFFSET		0x00000050
#define USBN_DMA0_OUTB_CHN0_OFFSET		0x00000058
#define USBN_DMA0_OUTB_CHN1_OFFSET		0x00000060
#define USBN_DMA0_OUTB_CHN2_OFFSET		0x00000068
#define USBN_DMA0_OUTB_CHN3_OFFSET		0x00000070
#define USBN_DMA0_OUTB_CHN4_OFFSET		0x00000078
#define USBN_DMA0_OUTB_CHN5_OFFSET		0x00000080
#define USBN_DMA0_OUTB_CHN6_OFFSET		0x00000088
#define USBN_DMA0_OUTB_CHN7_OFFSET		0x00000090

#endif /* _OCTEON_USBNREG_H_ */