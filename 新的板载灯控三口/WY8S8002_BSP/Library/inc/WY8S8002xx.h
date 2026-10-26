/**
	******************************************************************************
													 (C) COPYRIGHT WAY-ON, INC.
																	1996 - 2021
  ******************************************************************************
  * @file    WY8S8002xx.h
  * @author  wayon
  * @version V1.0.0
  * @date    2021/12/9
  * @brief   WY8S8003xx寄存器文件
  ******************************************************************************
  * @attention
  * 
  * 本文件仅用于对WY8S8003xx寄存器定义。
  *
  ******************************************************************************
  */

#ifndef _WY8S8002_H__
#define _WY8S8002_H__
#include <intrins.h>
typedef char int8_t;
typedef int  int16_t;
typedef long int32_t;
typedef unsigned char uint8_t;
typedef unsigned int  uint16_t;
typedef unsigned long	uint32_t;
typedef char int8;
typedef int  int16;
typedef long int32;
typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long	uint32;
/* Page0 BYTE Register */
sfr P0          = 0x80;
sfr SP          = 0x81;
sfr DPL         = 0x82;
sfr DPH         = 0x83;
sfr OPA0CON     = 0x86;
sfr PCON        = 0x87;
sfr TCON        = 0x88;
sfr TMOD        = 0x89;
sfr TL0         = 0x8A;
sfr TL1         = 0x8B;
sfr TH0         = 0x8C;
sfr TH1         = 0x8D;
sfr SWTCON      = 0x8E;
sfr SWTR        = 0x8F;
sfr SWTRDATA    = 0xF3;
sfr P1          = 0x90;
sfr P1DIR       = 0x91;
sfr P1OD        = 0x92;
sfr P1RD        = 0x93;
sfr P1UP        = 0x94;
sfr P1DRL       = 0x95;
sfr P1DRH       = 0x96;
sfr SCKS        = 0x97;
sfr SCON        = 0x98;
sfr SBUF        = 0x99;

sfr WDTCON      = 0x9B;
sfr WDTMOD      = 0x9C;
sfr BODCON      = 0x9D;
sfr CLKCON      = 0x9E;
sfr SYSRST      = 0x9F;
sfr P2          = 0xA0;
sfr P2DIR       = 0xA1;
sfr AUXR        = 0xA2;
sfr P2RD        = 0xA3;
sfr P2UP        = 0xA4;
sfr P2DR        = 0xA5;
sfr P2OD        = 0xA6;
sfr PWMDTFBC    = 0xA7;
sfr IE          = 0xA8;
sfr EI1         = 0xA9;
sfr PIO0EICFGH  = 0xAA;
sfr PIO0EICFGL  = 0xAB;
sfr PIO1EICFGH  = 0xAC;
sfr PIO1EICFGL  = 0xAD;
sfr ADCCON0     = 0xAE;
sfr ADCMPL      = 0xAF;
sfr PWMLOAD     = 0xB0;
sfr ADCCON1     = 0xB1;
sfr ADCCON2     = 0xB2;
sfr ADDLYL      = 0xB3;
sfr ADCRH       = 0xB4;
sfr ADCRL       = 0xB5;
sfr ADCMPH      = 0xB6;
sfr EI2         = 0xB7;
sfr IP          = 0xB8;
sfr IP1         = 0xB9;
sfr IP2         = 0xBA;
sfr SPICFG      = 0xBB;
sfr SPIMOD      = 0xBC;
sfr SPISR       = 0xBD;
sfr SPIRDR      = 0xBE;
sfr SPITDR      = 0xBF;
sfr PIO0IF      = 0xC0;
sfr PWMCON      = 0xC1;
sfr PWMPSC01    = 0xC2;
sfr PWMCNTM     = 0xC3;
sfr PWMSODW     = 0xC4;
sfr PWMP0H      = 0xC5;
sfr PWMP0L      = 0xC6;
sfr PWMP3L      = 0xC7;
sfr PIO1IF      = 0xC8;
sfr PWM23DT     = 0xC9;
sfr PWMP3H      = 0xCA;
sfr PWMINTY     = 0xCB;
sfr PWMD2L      = 0xCC;
sfr PWMSO0DATA = 0xCD;
sfr PWMSO1DATA = 0xCE;
sfr PWMOUTD     = 0xCF;
sfr PSW         = 0xD0;
sfr PWM01DT     = 0xD1;
sfr PWMPSC23    = 0xD2;
sfr PWMOUTC     = 0xD3;
sfr PWMD0L      = 0xD4;
sfr PWMD0H      = 0xD5;
sfr PWMD1L      = 0xD6;
sfr PWMD1H      = 0xD7;
sfr PWMINTF     = 0xD8;
sfr PWMD2H      = 0xD9;
sfr PWMD3L      = 0xDA;
sfr PWMD3H      = 0xDB;
sfr PWMP1H      = 0xDC;
sfr PWMP1L      = 0xDD;
sfr PWMP2H      = 0xDE;
sfr PWMP2L      = 0xDF;
sfr ACC         = 0xE0;
sfr ADCSMP      = 0xE1;
sfr WAITSTS     = 0xE2;
sfr FTPTEST     = 0xE3;
sfr TESTMODESEL = 0xE4;
sfr HRCFTUNE    = 0xE5;
sfr HRCCFG      = 0xE6;
sfr Trim2       = 0xE7;
sfr Trim3       = 0xE8;
sfr Trim4       = 0xE9;
sfr IAPFD0     = 0xEA;
sfr IAPFD1     = 0xEB;
sfr IAPFD2     = 0xEC;
sfr IAPFD3     = 0xED;
sfr IAPAL       = 0xEE;
sfr IAPAH       = 0xEF;
sfr B           = 0xF0;
sfr OCDEN       = 0xF1;
sfr IAPCON      = 0xF2;
sfr TA          = 0xF3;
sfr T3CON       = 0xF4;
sfr T3RH        = 0xF5;
sfr T3RL        = 0xF6;
sfr TESTMODEEN  = 0xF7;
sfr SCON_1      = 0xF8;
sfr SBUF_1      = 0xF9;
sfr P0DIR       = 0xFA;
sfr P0OD        = 0xFB;
sfr P0RD        = 0xFC;
sfr P0UP        = 0xFD;
sfr P0DR        = 0xFE;
sfr16 HRCFTUNE16  = 0xE5;
/* Page0 BIT Register  */
/*  P0  */
sbit P07        = 0x87;
sbit P06        = 0x86;
sbit P05        = 0x85;
sbit P04        = 0x84;
sbit P03        = 0x83;
sbit P02        = 0x82;
sbit P01        = 0x81;
sbit P00        = 0x80;
/*  TCON  */
sbit TF1        = 0x8F;
sbit TR1        = 0x8E;
sbit TF0        = 0x8D;
sbit TR0        = 0x8C;
sbit IE1        = 0x8B;
sbit IT1        = 0x8A;
sbit IE0        = 0x89;
sbit IT0        = 0x88;
/*  P1  */
sbit P17        = 0x97;
sbit P16        = 0x96;
sbit P15        = 0x95;
sbit P14        = 0x94;
sbit P13        = 0x93;
sbit P12        = 0x92;
sbit P11        = 0x91;
sbit P10        = 0x90;
/*  SCON  */
sbit SM0        = 0x9F;
sbit SM1        = 0x9E;
sbit SM2        = 0x9D;
sbit REN        = 0x9C;
sbit TB8        = 0x9B;
sbit RB8        = 0x9A;
sbit TI         = 0x99;
sbit RI         = 0x98;
/*  P2  */
sbit P25        = 0xA5;
sbit P24        = 0xA4;
sbit P23        = 0xA3;
sbit P22        = 0xA2;
sbit P21        = 0xA1;
sbit P20        = 0xA0;
/*  IE   */
sbit EA         = 0xAF;
sbit ET6        = 0xAE;
sbit ET5        = 0xAD;
sbit ET4        = 0xAC;
sbit ET3        = 0xAB;
sbit ET2        = 0xAA;
sbit ET1        = 0xA9;
sbit ET0        = 0xA8;
/* ADCCON0 */
sbit ADCEN      = 0xB7;
sbit ADCIF      = 0xB6;
sbit ADCSC      = 0xB5;
sbit ADCSWS     = 0xB4;
sbit ADFBEN     = 0xB2;
sbit ADCMPPS    = 0xB1;
sbit ADCMPO     = 0xB0;
/*  IP   */ 
sbit PS1        = 0xBE;
sbit PT1        = 0xBD;
sbit PS         = 0xBC;
sbit PT0        = 0xBB;
sbit PX1        = 0xBA;
sbit PBOD       = 0xB9;
sbit PX0        = 0xB8;
/*  PIO0IF   */ 
sbit PIO0IF7    = 0xC7;
sbit PIO0IF6    = 0xC6;
sbit PIO0IF5    = 0xC5;
sbit PIO0IF4    = 0xC4;
sbit PIO0IF3    = 0xC3;
sbit PIO0IF2    = 0xC2;
sbit PIO0IF1    = 0xC1;
sbit PIO0IF0    = 0xC0;

/*  PIO1IF   */ 
sbit PIO1IF7    = 0xCF;
sbit PIO1IF6    = 0xCE;
sbit PIO1IF5    = 0xCD;
sbit PIO1IF4    = 0xCC;
sbit PIO1IF3    = 0xCB;
sbit PIO1IF2    = 0xCA;
sbit PIO1IF1    = 0xC9;
sbit PIO1IF0    = 0xC8;

/*  PSW   */
sbit CY         = 0xD7;
sbit AC         = 0xD6;
sbit F0         = 0xD5;
sbit RS1        = 0xD4;
sbit RS0        = 0xD3;
sbit OV         = 0xD2;
sbit F1         = 0xD1;
sbit P          = 0xD0;

/*  PWMINTF   */
sbit PWMFBF     = 0xDC;
sbit PWMIF3     = 0xDB;
sbit PWMIF2     = 0xDA;
sbit PWMIF1     = 0xD9;
sbit PWMIF0     = 0xD8;
/*  ACC   */

/*  B   */

/*  SCON_1  */
sbit SM0_1      = 0xFF;
sbit SM1_1      = 0xFE;
sbit SM2_1      = 0xFD;
sbit REN_1      = 0xFC;
sbit TB8_1      = 0xFB;
sbit RB8_1      = 0xFA;
sbit TI_1       = 0xF9;
sbit RI_1       = 0xF8;

/*-----------XSFR(特殊功能寄存器)-------*/
#define PIO00CFG 	*(volatile unsigned char xdata *) 0xF000
#define PIO01CFG 	*(volatile unsigned char xdata *) 0xF001
#define PIO02CFG 	*(volatile unsigned char xdata *) 0xF002
#define PIO03CFG 	*(volatile unsigned char xdata *) 0xF003
#define PIO04CFG 	*(volatile unsigned char xdata *) 0xF004
#define PIO05CFG 	*(volatile unsigned char xdata *) 0xF005
#define PIO06CFG 	*(volatile unsigned char xdata *) 0xF006
#define PIO07CFG 	*(volatile unsigned char xdata *) 0xF007
#define PIO10CFG 	*(volatile unsigned char xdata *) 0xF008
#define PIO11CFG 	*(volatile unsigned char xdata *) 0xF009
#define PIO12CFG 	*(volatile unsigned char xdata *) 0xF00A
#define PIO13CFG 	*(volatile unsigned char xdata *) 0xF00B
#define PIO14CFG 	*(volatile unsigned char xdata *) 0xF00C
#define PIO15CFG 	*(volatile unsigned char xdata *) 0xF00D
#define PIO16CFG 	*(volatile unsigned char xdata *) 0xF00E
#define PIO17CFG 	*(volatile unsigned char xdata *) 0xF00F
#define PIO20CFG 	*(volatile unsigned char xdata *) 0xF010
#define PIO21CFG 	*(volatile unsigned char xdata *) 0xF011
#define PIO0SE      *(volatile unsigned char xdata *) 0xF012
#define PIO1SE      *(volatile unsigned char xdata *) 0xF013




#define T2RL        *(volatile unsigned char xdata *) 0xF020
#define T2RH        *(volatile unsigned char xdata *) 0xF021
#define RCMP2L      *(volatile unsigned char xdata *) 0xF022
#define RCMP2H      *(volatile unsigned char xdata *) 0xF023
#define T2CON       *(volatile unsigned char xdata *) 0xF024
#define T2MOD       *(volatile unsigned char xdata *) 0xF025
#define CAPCON0     *(volatile unsigned char xdata *) 0xF026
#define CAPCON1     *(volatile unsigned char xdata *) 0xF027
#define CAPCON2     *(volatile unsigned char xdata *) 0xF028
#define C0H         *(volatile unsigned char xdata *) 0xF029
#define C0L         *(volatile unsigned char xdata *) 0xF02A
#define C1H         *(volatile unsigned char xdata *) 0xF02B
#define C1L         *(volatile unsigned char xdata *) 0xF02C
#define C2H         *(volatile unsigned char xdata *) 0xF02D
#define C2L         *(volatile unsigned char xdata *) 0xF02E
#define C3H         *(volatile unsigned char xdata *) 0xF02F
#define C3L         *(volatile unsigned char xdata *) 0xF030

#define IRCON       *(volatile unsigned char xdata *) 0xF040
#define IRRCFG      *(volatile unsigned char xdata *) 0xF041
#define IRL1PRD1    *(volatile unsigned char xdata *) 0xF042
#define IRL1PRD2    *(volatile unsigned char xdata *) 0xF043
#define IRL0PRD1    *(volatile unsigned char xdata *) 0xF044
#define IRL0PRD2    *(volatile unsigned char xdata *) 0xF045
#define IRTWORDLO   *(volatile unsigned char xdata *) 0xF046
#define IRTWORDHI   *(volatile unsigned char xdata *) 0xF047
#define IRSTA       *(volatile unsigned char xdata *) 0xF048


#endif 
