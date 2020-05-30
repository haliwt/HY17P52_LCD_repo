sdcc -v
if exist ".\obj\ADC_LCD.asm " del ".\obj\ADC_LCD.asm" 
 sdcc   -I "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P"  -S -pHY17P52 ".\ADC_LCD.c"
 							 
if exist "ADC_LCD.asm"  ( 
 copy "ADC_LCD.asm" obj
del "ADC_LCD.asm" 							 
) else ( 
copy ".\ADC_LCD.asm" obj 
 del ".\ADC_LCD.asm" 
)

if exist "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\obj\error.txt" ( exit ) 

if exist ".\obj\ADC_52.asm " del ".\obj\ADC_52.asm" 
 sdcc   -I "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P"  -S -pHY17P52 "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"
 							 
if exist "ADC_52.asm"  (
 copy "ADC_52.asm" obj 
 del "ADC_52.asm" 							
) else ( copy "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.asm" obj 
 del "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.asm" 
)

if exist "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\obj\error.txt" ( exit ) 

if exist ".\obj\display.asm " del ".\obj\display.asm" 
 sdcc   -I "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P"  -S -pHY17P52 ".\display.c"
 							 
if exist "display.asm"  ( 
 copy "display.asm" obj
del "display.asm" 							 
) else ( 
copy ".\display.asm" obj 
 del ".\display.asm" 
)

if exist "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\obj\error.txt" ( exit ) 

if exist ".\obj\LED.asm " del ".\obj\LED.asm" 
 sdcc   -I "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P"  -S -pHY17P52 "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"
 							 
if exist "LED.asm"  (
 copy "LED.asm" obj 
 del "LED.asm" 							
) else ( copy "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.asm" obj 
 del "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.asm" 
)

if exist "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\obj\error.txt" ( exit ) 

if exist ".\obj\GPIO.asm " del ".\obj\GPIO.asm" 
 sdcc   -I "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P"  -S -pHY17P52 "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\GPIO.c"
 							 
if exist "GPIO.asm"  (
 copy "GPIO.asm" obj 
 del "GPIO.asm" 							
) else ( copy "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\GPIO.asm" obj 
 del "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\GPIO.asm" 
)

if exist "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\obj\error.txt" ( exit ) 

if exist ".\obj\ADC_LCD.rel " del ".\obj\ADC_LCD.rel"
 sdashya -l -s -o -y ".\obj\ADC_LCD.asm"

if exist "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\obj\error.txt" ( exit ) 

if exist ".\obj\ADC_52.rel " del ".\obj\ADC_52.rel"
 sdashya -l -s -o -y ".\obj\ADC_52.asm"

if exist "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\obj\error.txt" ( exit ) 

if exist ".\obj\display.rel " del ".\obj\display.rel"
 sdashya -l -s -o -y ".\obj\display.asm"

if exist "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\obj\error.txt" ( exit ) 

if exist ".\obj\LED.rel " del ".\obj\LED.rel"
 sdashya -l -s -o -y ".\obj\LED.asm"

if exist "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\obj\error.txt" ( exit ) 

if exist ".\obj\GPIO.rel " del ".\obj\GPIO.rel"
 sdashya -l -s -o -y ".\obj\GPIO.asm"

if exist "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\obj\error.txt" ( exit ) 

sdld -u -m -i -y -h08d -nx  ".\obj\ADC_LCD.ihx"  ".\obj\ADC_LCD.rel" ".\obj\ADC_52.rel" ".\obj\display.rel" ".\obj\LED.rel" ".\obj\GPIO.rel"   -l HY17PSDCC.LIB -l HY17P52ADCSetting.lib -l HY17P52WR3.lib 

