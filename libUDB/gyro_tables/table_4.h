

#ifndef TABLE_4_H
#define	TABLE_4_H

// used in MINI6_SN2

#define STEP_SIZE 256
//#define LOOKUP_LSB_MASK 0x00FF
//#define MSB_SHIFT 8

int16_t residual_offset[] = { 68 , 104 , 185 } ;

#define TABLE_ORIGIN -13951

struct gyro_offset_table_entry gyro_offset_table[] = {    
{ 5208 , -7014 , 686 } , 
{ 5172 , -6865 , 686 } , 
{ 5136 , -6716 , 686 } , 
{ 5100 , -6567 , 686 } , 
{ 5064 , -6418 , 686 } ,    
{ 5028 , -6269 , 686 } , 
{ 4992 , -6120 , 686 } , 
{ 4956 , -5971 , 686 } , 
{ 4920 , -5822 , 686 } , 
{ 4884 , -5673 , 686 } ,    
{ 4848 , -5524 , 686 } , 
{ 4818 , -5401 , 709 } , 
{ 4804 , -5287 , 720 } , 
{ 4761 , -5123 , 713 } , 
{ 4726 , -4954 , 714 } , 
{ 4757 , -4862 , 726 } , 
{ 4627 , -4653 , 693 } , 
{ 4653 , -4555 , 701 } , 
{ 4547 , -4345 , 709 } , 
{ 4561 , -4236 , 690 } , 
{ 4489 , -4033 , 677 } , 
{ 4413 , -3862 , 681 } , 
{ 4439 , -3800 , 687 } , 
{ 4376 , -3658 , 659 } , 
{ 4332 , -3484 , 653 } , 
{ 4274 , -3316 , 637 } , 
{ 4272 , -3192 , 642 } , 
{ 4206 , -3038 , 613 } , 
{ 4131 , -2855 , 602 } , 
{ 4157 , -2763 , 606 } , 
{ 4105 , -2609 , 593 } , 
{ 4034 , -2449 , 575 } , 
{ 4010 , -2319 , 560 } , 
{ 3992 , -2188 , 574 } , 
{ 3942 , -2053 , 552 } , 
{ 3938 , -1920 , 530 } , 
{ 3871 , -1768 , 531 } , 
{ 3841 , -1621 , 517 } , 
{ 3789 , -1466 , 505 } , 
{ 3792 , -1352 , 486 } , 
{ 3687 , -1199 , 482 } , 
{ 3680 , -1068 , 467 } , 
{ 3635 , -922 , 463 } , 
{ 3564 , -784 , 437 } , 
{ 3550 , -653 , 422 } , 
{ 3453 , -508 , 417 } , 
{ 3412 , -364 , 403 } , 
{ 3373 , -219 , 384 } , 
{ 3287 , -86 , 374 } , 
{ 3196 , 51 , 363 } , 
{ 3161 , 171 , 357 } , 
{ 3062 , 297 , 326 } , 
{ 3000 , 419 , 315 } , 
{ 2948 , 533 , 310 } , 
{ 2858 , 644 , 300 } , 
{ 2851 , 772 , 276 } , 
{ 2770 , 873 , 271 } , 
{ 2741 , 1001 , 273 } , 
{ 2657 , 1105 , 252 } , 
{ 2632 , 1234 , 232 } , 
{ 2624 , 1354 , 231 } , 
{ 2536 , 1453 , 219 } , 
{ 2511 , 1590 , 225 } , 
{ 2460 , 1693 , 191 } , 
{ 2386 , 1814 , 187 } , 
{ 2354 , 1932 , 180 } , 
{ 2243 , 2024 , 176 } , 
{ 2164 , 2169 , 150 } , 
{ 2086 , 2288 , 128 }     
};

#endif	/* TABLE_4_H */

