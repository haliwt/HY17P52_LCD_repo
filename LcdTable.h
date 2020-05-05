/*-----------------------------------------------------------------------------|
| 7-segment display for LCD0 ~ LCD5                                            |
| ----------------------------------------------------------------------------*/

                             //                a
#define  seg_a 0x10          //            ---------
#define  seg_b 0x20          //           |         |
#define  seg_c 0x40          //         f |         | b
#define  seg_d 0x08          //           |    g    |
#define  seg_e 0x04          //            ---------
#define  seg_f 0x01          //           |         |
#define  seg_g 0x02          //         e |         | c
#define  seg_h 0x80          //           |    d    |
                             //            ---------   O <- h

const unsigned char seg[]={
         seg_a+seg_b+seg_c+seg_d+seg_e+seg_f,        // char "0"  0x00
         seg_b+seg_c,                                // char "1"  0x01
         seg_a+seg_b+seg_d+seg_e+seg_g,              // char "2"  0x02
         seg_a+seg_b+seg_c+seg_d+seg_g,              // char "3"  0x03
         seg_b+seg_c+seg_f+seg_g,                    // char "4"  0x04
         seg_a+seg_c+seg_d+seg_f+seg_g,              // char "5"  0x05
         seg_a+seg_c+seg_d+seg_e+seg_f+seg_g,        // char "6"  0x06
         seg_a+seg_b+seg_c+seg_f,                    // char "7"  0x07
         seg_a+seg_b+seg_c+seg_d+seg_e+seg_f+seg_g,  // char "8"  0x08
         seg_a+seg_b+seg_c+seg_d+seg_f+seg_g,        // char "9"  0x09
         seg_a+seg_b+seg_c+seg_e+seg_f+seg_g,        // char "A"  0x0a
         seg_c+seg_d+seg_e+seg_f+seg_g,              // char "b"  0x0b
         seg_a+seg_d+seg_e+seg_f,                    // char "C"  0x0c
         seg_b+seg_c+seg_d+seg_e+seg_g,              // char "d"  0x0d
         seg_a+seg_d+seg_e+seg_f+seg_g,              // char "E"  0x0e
         seg_a+seg_e+seg_f+seg_g,                    // char "F"  0x0f
         seg_b+seg_c+seg_e+seg_f+seg_g,              // char "H"  0x10
         seg_c,                                      // char "i"  0x11
         seg_b+seg_c+seg_d+seg_g,                    // char "J"  0x12
         seg_d+seg_e+seg_f,                          // char "L"  0x13
         seg_c+seg_e+seg_g,                          // char "n"  0x14
         seg_c+seg_d+seg_e+seg_g,                    // char "o"  0x15
         seg_a+seg_b+seg_e+seg_f+seg_g,              // char "P"  0x16
         seg_a+seg_b+seg_c+seg_f+seg_g,              // char "q"  0x17
         seg_e+seg_g,                                // char "r"  0x18
         seg_d+seg_e+seg_f+seg_g,                    // char "t"  0x19
         seg_c+seg_e+seg_d,                          // char "u"  0x1a
         seg_b+seg_c+seg_d+seg_f+seg_g               // char "y"  0x1b
};

#define  Char_A  seg_a+seg_b+seg_c+seg_e+seg_f+seg_g // char "A"
#define  Char_B  seg_c+seg_d+seg_e+seg_f+seg_g       // char "b"
#define  Char_C  seg_a+seg_d+seg_e+seg_f             // char "C"
#define  Char_D  seg_b+seg_c+seg_d+seg_e+seg_g       // char "d"
#define  Char_E  seg_a+seg_d+seg_e+seg_f+seg_g       // char "E"
#define  Char_F  seg_a+seg_e+seg_f+seg_g             // char "F"
//Char_G                                             // char "G"
#define  Char_H  seg_b+seg_c+seg_e+seg_f+seg_g       // char "H"
#define  Char_I  seg_c                               // char "i"
#define  Char_J  seg_b+seg_c+seg_d+seg_g             // char "J"
//Char_K                                             // char "K"
#define  Char_L  seg_d+seg_e+seg_f                   // char "L"
//Char_M                                             // char "M"
#define  Char_N  seg_c+seg_e+seg_g                   // char "n"
#define  Char_O  seg_c+seg_d+seg_e+seg_g             // char "o"
#define  Char_P  seg_a+seg_b+seg_e+seg_f+seg_g       // char "P"
#define  Char_Q  seg_a+seg_b+seg_c+seg_f+seg_g       // char "q"
#define  Char_R  seg_e+seg_g                         // char "r"
#define  Char_S  seg_a+seg_c+seg_d+seg_f+seg_g       // char "S"
#define  Char_T  seg_d+seg_e+seg_f+seg_g             // char "t"
#define  Char_U  seg_c+seg_e+seg_d                   // char "u"
//Char_V                                             // char "V"
//Char_W                                             // char "W"
//Char_X                                             // char "X"
#define  Char_Y  seg_b+seg_c+seg_d+seg_f+seg_g       // char "y"
#define  Char_Z  seg_a+seg_b+seg_d+seg_e+seg_g       // char "Z"


//-----------------------------------------------------------------------------
// Define Symbols
//-----------------------------------------------------------------------------

#define  S_g         0x80  //&LCD5  g
#define  S_m         0x80  //&LCD6  m
#define  S_V         0x80  //&LCD7  V
#define  S_A         0x20  //&LCD7  A
#define  S_K         0x10  //&LCD7  K
#define  S_M         0x01  //&LCD7  M
#define  S_Ohm       0x40  //&LCD7  Ohm
#define  S_Zero      0x40  //&LCD6  Zero
#define  S_Tare      0x20  //&LCD6  Tare
#define  S_Minus     0x10  //&LCD6  Minus
#define  S_Temp      0x02  //&LCD7  Temp
#define  S_Temp_C    0x08  //&LCD7  Temp_C
#define  S_Temp_F    0x04  //&LCD7  Temp_F
#define  S_Arrow1    0x01  //&LCD8  Arrow1
#define  S_Arrow2    0x02  //&LCD8  Arrow2
#define  S_Arrow3    0x04  //&LCD8  Arrow3
#define  S_Arrow4    0x08  //&LCD8  Arrow4
#define  S_Battery0  0x01  //&LCD6  Battery0
#define  S_Battery1  0x08  //&LCD6  Battery1
#define  S_Battery2  0x04  //&LCD6  Battery2
#define  S_Battery3  0x02  //&LCD6  Battery3