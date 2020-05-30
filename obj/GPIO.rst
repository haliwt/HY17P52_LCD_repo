001                     ;--------------------------------------------------------
002                     ; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
003                     ; Version 3.9.3 #4ad52972e (MSVC)
004                     ;--------------------------------------------------------
005                     ; Port for HYCON CPU
006                     ;--------------------------------------------------------
007                     ;	;CCFROM:"E:\HY17P52_TestSoft\HY17P52_LCD_soft"
008                     ;;	.file	"E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\GPIO.c"
009                     	.module GPIO
010                     	;.list	p=HY17P52
011                     ;--------------------------------------------------------
012                     ; overlayable items in internal ram 
013                     ;--------------------------------------------------------
014                     ;	udata_ovr
015                     .area CCODE (code,REL,CON) ; GPIO-code 
016                     ;--------------------------------------------------------
017                     ; external declarations
018                     ;--------------------------------------------------------
019                     
020                     	.globl WSAVE
021                     	.globl STK07
022                     	.globl STK07_SAVE
023                     	.globl STK06
024                     	.globl STK06_SAVE
025                     	.globl STK05
026                     	.globl STK05_SAVE
027                     	.globl STK04
028                     	.globl STK04_SAVE
029                     	.globl STK03
030                     	.globl STK03_SAVE
031                     	.globl STK02
032                     	.globl STK02_SAVE
033                     	.globl STK01
034                     	.globl STK01_SAVE
035                     	.globl STK00
036                     	.globl STK00_SAVE
037                     ;--------------------------------------------------------
038                     ; global -1 declarations
039                     ;--------------------------------------------------------
040                     
041                     	.globl	_memcpy
042                     ;--------------------------------------------------------
043                     ; global -2 definitions
044                     ;--------------------------------------------------------
045                     ;--------------------------------------------------------
046                     ; absolute symbol definitions
047                     ;--------------------------------------------------------
048                     ;--------------------------------------------------------
049                     ; compiler-defined variables
050                     ;--------------------------------------------------------
051                     	.area IDATA (DATA,REL,CON); pre-def
052                     	.area IDATAROM (CODE,REL,CON); pre-def
053                     	.area UDATA (DATA,REL,CON); pre-def
054                     ;--------------------------------------------------------
055                     ; initialized data
056                     ;--------------------------------------------------------
057                     ;--------------------------------------------------------
058                     ; initialized data - mirror
059                     ;--------------------------------------------------------
060                     	end
