

#ifndef TABLE_LUGE7_SN087_H
#define	TABLE_LUGE7_SN087_H

// used in LUGE7_SN087 partition size 64

#define STEP_SIZE 64


#define TABLE_ORIGIN ( -10143)

int16_t residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry gyro_offset_table[] = {
{1525,-2750,615},
{1534,-2766,618},
{1553,-2795,626},
{1567,-2815,636},
{1576,-2831,636},
{1593,-2847,639},
{1604,-2862,644},
{1611,-2873,638},
{1618,-2883,640},
{1625,-2895,650},
{1636,-2909,647},
{1643,-2917,635},
{1649,-2924,631},
{1657,-2939,623},
{1663,-2947,620},
{1670,-2953,621},
{1676,-2966,617},
{1685,-2979,608},
{1701,-2986,598},
{1710,-2990,592},
{1715,-2993,587},
{1724,-3001,595},
{1736,-3008,580},
{1741,-3007,557},
{1745,-3012,556},
{1756,-3023,565},
{1760,-3034,599},
{1757,-3044,623},
{1757,-3050,617},
{1759,-3056,608},
{1763,-3057,601},
{1769,-3056,590},
{1774,-3060,590},
{1777,-3057,591},
{1788,-3062,583},
{1796,-3078,572},
{1810,-3080,529},
{1831,-3077,483},
{1837,-3083,474},
{1841,-3092,476},
{1847,-3105,461},
{1856,-3114,448},
{1868,-3115,443},
{1880,-3117,434},
{1883,-3128,423},
{1892,-3132,410},
{1897,-3131,407},
{1894,-3137,397},
{1899,-3142,385},
{1904,-3143,383},
{1908,-3146,379},
{1912,-3156,374},
{1918,-3167,369},
{1923,-3168,365},
{1923,-3167,355},
{1925,-3169,342},
{1933,-3175,330},
{1941,-3188,328},
{1946,-3199,315},
{1946,-3208,310},
{1945,-3211,310},
{1945,-3206,292},
{1946,-3207,283},
{1947,-3215,277},
{1944,-3219,272},
{1943,-3220,270},
{1937,-3231,266},
{1929,-3243,258},
{1925,-3249,247},
{1919,-3251,228},
{1911,-3249,212},
{1906,-3252,209},
{1892,-3261,216},
{1878,-3262,213},
{1870,-3263,200},
{1856,-3266,191},
{1840,-3260,181},
{1825,-3254,170},
{1799,-3255,160},
{1771,-3253,152},
{1736,-3253,180},
{1700,-3252,183},
{1671,-3250,134},
{1632,-3249,121},
{1594,-3251,128},
{1556,-3245,110},
{1513,-3234,90},
{1465,-3231,80},
{1410,-3227,67},
{1354,-3218,65},
{1312,-3205,56},
{1271,-3193,38},
{1224,-3184,20},
{1176,-3184,9},
{1134,-3179,-1},
{1092,-3167,-14},
{1048,-3163,-30},
{1019,-3160,-49},
{992,-3158,-41},
{961,-3152,-57},
{937,-3143,-86},
{918,-3145,-95},
{895,-3149,-106},
{875,-3152,-121},
{866,-3145,-140},
{855,-3137,-153},
{839,-3139,-164},
{823,-3138,-178},
{803,-3133,-192},
{792,-3132,-205},
{780,-3137,-207},
{754,-3138,-218},
{738,-3137,-235},
{728,-3139,-250},
{710,-3133,-267},
{692,-3131,-275},
{677,-3133,-276},
{664,-3136,-282},
{655,-3134,-297},
{648,-3129,-307},
{635,-3129,-312},
{618,-3132,-314},
{603,-3136,-325},
{590,-3139,-344},
{582,-3141,-356},
{581,-3133,-356},
{573,-3130,-366},
{552,-3139,-383},
{531,-3144,-393},
{519,-3147,-399},
{510,-3151,-416},
{501,-3151,-440},
{483,-3149,-450},
{461,-3147,-457},
{448,-3152,-464},
{434,-3159,-466},
{424,-3159,-473},
{415,-3153,-482},
{404,-3157,-490},
{394,-3161,-505},
{383,-3157,-518},
{373,-3157,-529},
{357,-3159,-547},
{338,-3162,-558},
{319,-3164,-566},
{307,-3164,-580},
{295,-3165,-601},
{283,-3164,-616},
{275,-3167,-619},
{265,-3167,-630},
{253,-3167,-643},
{244,-3168,-658},
{236,-3169,-674},
{224,-3170,-678},
{211,-3165,-684},
{202,-3164,-703},
{196,-3167,-716},
{186,-3168,-717},
{170,-3169,-721},
{155,-3169,-737},
{139,-3173,-751},
{123,-3179,-767},
{113,-3184,-787},
{101,-3183,-793},
{88,-3181,-803},
{78,-3187,-818},
{68,-3190,-827},
{58,-3191,-840},
{46,-3194,-858},
{33,-3197,-870},
{21,-3202,-877},
{14,-3205,-890},
{7,-3208,-903},
{-5,-3213,-905},
{-17,-3217,-909},
{-34,-3217,-923},
{-52,-3215,-946},
{-61,-3218,-973},
{-72,-3219,-988},
{-85,-3217,-993},
{-96,-3218,-1001},
{-105,-3220,-1017},
{-114,-3218,-1035},
{-123,-3225,-1047},
{-131,-3229,-1061},
{-140,-3228,-1077},
{-146,-3231,-1087},
{-156,-3236,-1094},
{-170,-3236,-1104},
{-176,-3239,-1116},
{-187,-3243,-1122},
{-205,-3241,-1132},
{-220,-3242,-1144},
{-233,-3246,-1154},
{-241,-3244,-1170},
{-247,-3245,-1188},
{-256,-3249,-1204},
{-266,-3250,-1214},
{-273,-3248,-1223},
{-280,-3250,-1234},
{-287,-3256,-1254},
{-291,-3255,-1277},
{-299,-3256,-1294},
{-308,-3260,-1307},
{-317,-3255,-1322},
{-325,-3249,-1324},
{-336,-3248,-1320},
{-352,-3251,-1330},
{-366,-3261,-1346},
{-376,-3267,-1352},
{-382,-3268,-1360},
{-387,-3270,-1376},
{-393,-3271,-1390},
{-398,-3271,-1409},
{-404,-3270,-1424},
{-408,-3275,-1434},
{-411,-3282,-1441},
{-412,-3280,-1445},
{-412,-3276,-1452},
{-411,-3278,-1458},
{-407,-3281,-1456},
{-401,-3282,-1461},
{-389,-3284,-1468},
{-369,-3286,-1464},
{-356,-3294,-1457},
{-361,-3301,-1463},
{-370,-3300,-1470},
{-381,-3300,-1475},
{-391,-3304,-1482},
{-397,-3306,-1494},
{-409,-3306,-1509},
{-425,-3311,-1514},
{-439,-3320,-1519},
{-450,-3328,-1533},
{-458,-3335,-1545},
{-469,-3341,-1554},
{-481,-3349,-1560},
{-491,-3354,-1570},
{-502,-3352,-1587},
{-518,-3349,-1606},
{-536,-3356,-1617},
{-551,-3356,-1626},
{-564,-3351,-1644},
{-576,-3354,-1661},
{-588,-3354,-1683},
{-602,-3357,-1700},
{-613,-3360,-1713},
{-623,-3361,-1731},
{-629,-3361,-1746},
{-636,-3360,-1758},
{-651,-3361,-1770},
{-666,-3362,-1784},
{-679,-3363,-1800},
{-691,-3366,-1813},
{-700,-3367,-1824},
{-716,-3373,-1829},
{-737,-3381,-1837},
{-751,-3385,-1852},
{-761,-3385,-1867},
{-776,-3385,-1887},
{-790,-3387,-1908},
{-801,-3389,-1923},
{-812,-3387,-1934},
{-821,-3387,-1953},
{-831,-3389,-1969},
{-846,-3387,-1978},
{-859,-3386,-1995},
{-873,-3387,-2011},
{-891,-3392,-2021},
};


#endif	/* TABLE_LUGE7_SN087_H */



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -10143)

int16_t accel_residual_offset[] = { -17,-31,97 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-5,0,-1},
{-3,0,7},
{-2,0,13},
{-1,0,11},
{-1,0,10},
{-1,0,10},
{-1,0,10},
{0,0,10},
{0,0,10},
{0,-1,10},
{0,-1,10},
{0,-1,10},
{0,-1,11},
{0,-1,11},
{0,-1,11},
{0,-1,12},
{0,-1,12},
{0,-2,13},
{0,-3,13},
{0,-3,13},
{1,-3,14},
{1,-3,14},
{1,-3,15},
{1,-3,15},
{1,-3,15},
{1,-3,16},
{2,-3,17},
{2,-4,17},
{2,-4,17},
{2,-4,18},
{1,-4,18},
{1,-4,18},
{2,-5,18},
{2,-5,19},
{2,-5,19},
{3,-5,19},
{2,-5,19},
{2,-5,20},
{3,-6,20},
{3,-5,21},
{3,-5,21},
{3,-6,22},
{3,-6,22},
{3,-6,22},
{4,-6,23},
{4,-7,23},
{4,-7,23},
{4,-7,23},
{4,-7,24},
{4,-7,24},
{4,-7,25},
{4,-7,25},
{4,-7,26},
{5,-7,26},
{4,-7,26},
{4,-8,26},
{5,-8,27},
{5,-8,27},
{5,-8,28},
{5,-8,28},
{5,-8,28},
{5,-8,29},
{6,-8,29},
{5,-8,29},
{5,-8,30},
{6,-8,30},
{6,-8,31},
{6,-8,31},
{6,-9,31},
{6,-9,31},
{6,-8,32},
{7,-8,32},
{7,-8,33},
{6,-8,33},
{6,-8,34},
{7,-8,34},
{7,-8,34},
{7,-8,35},
{7,-7,35},
{7,-7,36},
{7,-7,36},
{7,-7,37},
{7,-6,37},
{7,-6,37},
{7,-6,37},
{7,-6,38},
{7,-6,38},
{7,-6,38},
{7,-6,39},
{7,-6,40},
{7,-6,40},
{6,-6,40},
{6,-6,40},
{6,-6,40},
{6,-7,41},
{6,-7,41},
{6,-7,41},
{6,-7,42},
{6,-8,42},
{6,-8,42},
{6,-8,42},
{6,-8,43},
{6,-8,43},
{6,-8,43},
{6,-8,43},
{6,-9,44},
{6,-9,44},
{6,-9,44},
{6,-9,44},
{6,-9,45},
{6,-9,45},
{6,-9,45},
{6,-9,46},
{6,-9,46},
{6,-9,46},
{6,-9,47},
{6,-10,47},
{6,-10,47},
{6,-10,48},
{6,-10,48},
{6,-10,49},
{6,-10,49},
{6,-10,50},
{7,-10,50},
{6,-10,50},
{6,-10,51},
{7,-10,51},
{7,-11,52},
{7,-11,52},
{7,-11,52},
{7,-11,53},
{7,-11,53},
{7,-11,53},
{7,-11,54},
{7,-11,54},
{7,-11,55},
{7,-11,55},
{7,-11,55},
{7,-11,56},
{7,-12,56},
{7,-12,56},
{7,-12,56},
{7,-12,57},
{7,-12,58},
{7,-12,58},
{7,-12,58},
{7,-12,59},
{7,-12,59},
{8,-12,60},
{8,-12,60},
{8,-13,61},
{8,-13,61},
{8,-13,61},
{8,-13,62},
{8,-13,62},
{8,-13,63},
{8,-13,63},
{8,-13,64},
{8,-13,64},
{8,-14,65},
{8,-14,65},
{8,-14,66},
{8,-14,66},
{8,-14,67},
{8,-14,67},
{9,-14,68},
{9,-14,68},
{9,-14,69},
{9,-14,70},
{9,-15,70},
{9,-15,70},
{9,-15,71},
{9,-15,71},
{9,-15,72},
{9,-15,72},
{9,-15,73},
{9,-16,74},
{9,-16,75},
{9,-16,75},
{9,-16,76},
{9,-16,76},
{9,-16,77},
{9,-16,77},
{9,-16,78},
{9,-17,78},
{9,-17,78},
{9,-17,79},
{9,-17,79},
{9,-17,79},
{9,-17,80},
{9,-17,80},
{9,-17,81},
{9,-17,81},
{9,-17,82},
{9,-17,82},
{10,-17,82},
{10,-17,83},
{10,-17,83},
{10,-18,84},
{10,-18,84},
{10,-18,85},
{10,-18,85},
{10,-18,86},
{10,-18,86},
{10,-18,87},
{10,-18,87},
{10,-18,88},
{10,-18,88},
{10,-18,89},
{10,-18,90},
{10,-18,91},
{10,-18,91},
{10,-18,92},
{10,-18,92},
{10,-18,93},
{10,-17,94},
{10,-17,95},
{10,-17,95},
{10,-17,96},
{10,-17,97},
{10,-16,97},
{9,-16,98},
{9,-16,98},
{9,-15,99},
{9,-15,100},
{8,-15,101},
{8,-15,102},
{8,-15,103},
{8,-15,105},
{8,-15,107},
{8,-16,109},
{8,-16,110},
{8,-16,112},
{8,-16,113},
{8,-17,113},
{7,-17,114},
{7,-17,114},
{7,-17,115},
{7,-18,114},
{7,-18,114},
{7,-18,114},
{7,-18,114},
{7,-18,114},
{7,-19,114},
{7,-19,114},
{8,-19,114},
{8,-19,114},
{8,-19,114},
{8,-20,114},
{8,-20,114},
{8,-20,114},
{8,-20,115},
{8,-20,115},
{8,-20,115},
{8,-20,115},
{8,-21,115},
{8,-20,115},
{8,-20,115},
{8,-21,115},
{8,-21,115},
{8,-21,115},
{8,-21,116},
{8,-22,116},
{8,-22,116},
{8,-22,116},
{8,-22,117},
{8,-22,117},
{8,-22,117},
{8,-22,117},
};



