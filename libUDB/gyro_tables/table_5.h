/* 
 * File:   table_1.h
 * Author: bill
 *
 * Created on December 24, 2022, 11:37 AM
 */

#ifndef TABLE_5_H
#define	TABLE_5_H

#define LOOKUP_LSB_MASK 0x00FF
#define MSB_SHIFT 8

int16_t residual_offset[] = { 0 , 0 , 0 } ;

#define TABLE_ORIGIN -11904

struct gyro_offset_table_entry gyro_offset_table[] = {
{ 3384 , -1704 , 496 } , 
{ 3352 , -1576 , 491 } , 
{ 3374 , -1471 , 465 } , 
{ 3164 , -1210 , 429 } , 
{ 3196 , -1075 , 415 } , 
{ 3303 , -1106 , 395 } , 
{ 3210 , -925 , 369 } , 
{ 3234 , -792 , 371 } , 
{ 3160 , -676 , 345 } , 
{ 3206 , -572 , 346 } , 
{ 3155 , -427 , 314 } , 
{ 3091 , -274 , 316 } , 
{ 3096 , -188 , 298 } , 
{ 3070 , -6 , 297 } , 
{ 3212 , -164 , 287 } , 
{ 3127 , 148 , 285 } , 
{ 3003 , 264 , 250 } , 
{ 2996 , 404 , 262 } , 
{ 3004 , 520 , 252 } , 
{ 2957 , 646 , 229 } , 
{ 2908 , 751 , 228 } , 
{ 2928 , 873 , 217 } , 
{ 2902 , 1005 , 211 } , 
{ 2866 , 1118 , 204 } , 
{ 2866 , 1246 , 194 } , 
{ 2855 , 1362 , 185 } , 
{ 2837 , 1453 , 159 } , 
{ 2828 , 1579 , 166 } , 
{ 2842 , 1713 , 151 } , 
{ 2784 , 1802 , 139 } , 
{ 2775 , 1939 , 129 } , 
{ 2764 , 2062 , 115 } , 
{ 2727 , 2164 , 116 } , 
{ 2737 , 2332 , 119 } , 
{ 2675 , 2435 , 106 } , 
{ 2610 , 2530 , 99 } , 
{ 2606 , 2680 , 102 } , 
{ 2571 , 2819 , 99 } , 
{ 2490 , 2905 , 95 } , 
{ 2474 , 3037 , 94 } , 
{ 2409 , 3142 , 91 } , 
{ 2343 , 3216 , 94 } , 
{ 2327 , 3361 , 98 } , 
{ 2275 , 3466 , 94 } , 
{ 2208 , 3507 , 105 } , 
{ 2190 , 3639 , 109 } , 
{ 2164 , 3722 , 112 } , 
{ 2121 , 3797 , 108 } , 
{ 2065 , 3838 , 112 } , 
{ 2047 , 3969 , 119 } , 
{ 1992 , 4009 , 121 } , 
{ 1963 , 4091 , 126 } , 
{ 1903 , 4147 , 124 } , 
{ 1881 , 4278 , 141 } , 
{ 1843 , 4320 , 139 } , 
{ 1801 , 4384 , 145 } , 
{ 1722 , 4421 , 149 } , 
{ 1698 , 4541 , 157 } , 
{ 1629 , 4628 , 177 } , 
{ 1570 , 4752 , 207 } , 
{ 1466 , 4761 , 232 }    
};

#endif	/* TABLE_5_H */

