

#ifndef TABLE_LUGE7_SN155_H
#define TABLE_LUGE7_SN155_H

// used in LUGE7_SN155 partition size 64

#define X_CROSS_COUPLING 40
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64



#define TABLE_ORIGIN ( -12743)

int16_t residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry gyro_offset_table[] = {
{-2008,-320,1342},
{-2001,-328,1337},
{-1993,-337,1332},
{-1992,-346,1326},
{-1979,-356,1323},
{-1953,-355,1342},
{-1934,-354,1356},
{-1927,-359,1356},
{-1923,-371,1365},
{-1905,-383,1368},
{-1893,-390,1356},
{-1887,-393,1345},
{-1878,-395,1343},
{-1865,-398,1344},
{-1853,-406,1326},
{-1845,-417,1299},
{-1833,-426,1280},
{-1825,-431,1260},
{-1816,-434,1279},
{-1810,-443,1293},
{-1802,-451,1278},
{-1790,-456,1270},
{-1783,-460,1257},
{-1778,-462,1254},
{-1765,-470,1270},
{-1753,-484,1291},
{-1745,-500,1296},
{-1732,-497,1289},
{-1725,-497,1279},
{-1716,-506,1273},
{-1703,-506,1244},
{-1694,-519,1220},
{-1684,-533,1221},
{-1672,-546,1219},
{-1662,-558,1221},
{-1652,-564,1215},
{-1642,-568,1203},
{-1633,-575,1192},
{-1625,-585,1195},
{-1618,-593,1214},
{-1610,-609,1232},
{-1599,-617,1237},
{-1590,-622,1222},
{-1586,-626,1198},
{-1573,-632,1176},
{-1560,-642,1168},
{-1550,-652,1164},
{-1541,-658,1165},
{-1534,-661,1191},
{-1528,-676,1193},
{-1523,-690,1165},
{-1515,-702,1169},
{-1506,-710,1183},
{-1493,-714,1184},
{-1483,-718,1180},
{-1482,-721,1177},
{-1476,-734,1160},
{-1466,-748,1137},
{-1457,-750,1127},
{-1446,-750,1124},
{-1441,-758,1133},
{-1438,-769,1147},
{-1435,-779,1138},
{-1427,-788,1115},
{-1423,-793,1118},
{-1419,-797,1138},
{-1415,-793,1124},
{-1410,-794,1107},
{-1401,-801,1117},
{-1398,-811,1124},
{-1400,-829,1122},
{-1399,-837,1121},
{-1390,-830,1127},
{-1391,-825,1122},
{-1395,-839,1096},
{-1389,-851,1100},
{-1380,-853,1107},
{-1381,-853,1074},
{-1381,-858,1056},
{-1375,-864,1059},
{-1374,-867,1058},
{-1372,-871,1054},
{-1374,-881,1058},
{-1380,-884,1050},
{-1382,-882,1040},
{-1380,-888,1038},
{-1382,-897,1032},
{-1391,-899,1025},
{-1395,-896,1019},
{-1399,-904,1017},
{-1410,-912,1014},
{-1416,-913,1008},
{-1423,-916,1012},
{-1435,-920,1022},
{-1448,-919,1012},
{-1461,-918,999},
{-1476,-924,999},
{-1493,-926,1009},
{-1509,-923,1006},
{-1522,-923,980},
{-1536,-924,965},
{-1553,-927,959},
{-1567,-926,959},
{-1581,-923,959},
{-1594,-929,963},
{-1609,-936,969},
{-1626,-935,954},
{-1640,-936,944},
{-1654,-939,930},
{-1669,-944,918},
{-1680,-946,927},
{-1689,-941,931},
{-1698,-940,918},
{-1708,-938,918},
{-1718,-942,922},
{-1723,-948,910},
{-1728,-949,891},
{-1739,-952,880},
{-1749,-947,883},
{-1754,-946,878},
{-1762,-951,873},
{-1772,-952,878},
{-1780,-952,876},
{-1784,-951,880},
{-1791,-961,879},
{-1799,-967,874},
{-1808,-969,868},
{-1817,-972,868},
{-1824,-975,859},
{-1829,-978,847},
{-1835,-979,846},
{-1841,-984,842},
{-1849,-990,832},
{-1859,-992,812},
{-1868,-988,809},
{-1870,-985,810},
{-1873,-987,809},
{-1882,-997,803},
{-1889,-1003,791},
{-1898,-1003,796},
{-1908,-1002,795},
{-1913,-1005,780},
{-1920,-1006,774},
{-1929,-1012,771},
{-1934,-1023,772},
{-1937,-1032,771},
{-1946,-1030,763},
{-1956,-1028,752},
{-1966,-1038,748},
{-1976,-1046,740},
{-1984,-1049,730},
{-1993,-1052,735},
{-2002,-1057,736},
{-2011,-1060,731},
{-2017,-1064,729},
{-2022,-1068,725},
{-2029,-1068,709},
{-2036,-1069,704},
{-2044,-1075,702},
{-2052,-1084,697},
{-2062,-1091,703},
{-2071,-1095,702},
{-2079,-1101,700},
{-2087,-1108,691},
{-2094,-1114,682},
{-2102,-1124,672},
{-2110,-1127,663},
{-2117,-1125,666},
{-2125,-1127,665},
{-2132,-1132,665},
{-2140,-1136,660},
{-2151,-1137,648},
{-2159,-1145,642},
{-2164,-1160,634},
{-2174,-1166,626},
{-2182,-1170,622},
{-2188,-1181,624},
{-2196,-1185,622},
{-2205,-1186,613},
{-2213,-1192,609},
{-2222,-1200,609},
{-2229,-1200,598},
{-2235,-1202,589},
{-2246,-1214,588},
{-2255,-1222,584},
{-2263,-1225,580},
{-2272,-1229,575},
{-2280,-1232,572},
{-2287,-1236,568},
{-2296,-1239,561},
{-2305,-1241,552},
{-2309,-1243,548},
{-2316,-1247,550},
{-2327,-1252,549},
{-2336,-1258,541},
{-2344,-1263,533},
{-2351,-1270,531},
{-2358,-1286,525},
{-2366,-1294,516},
{-2372,-1290,517},
{-2379,-1296,517},
{-2386,-1311,508},
{-2394,-1322,507},
{-2401,-1334,501},
{-2409,-1346,486},
{-2420,-1352,479},
{-2429,-1353,475},
{-2438,-1354,473},
{-2444,-1357,475},
{-2449,-1361,471},
{-2458,-1366,462},
{-2466,-1375,458},
{-2472,-1385,453},
{-2480,-1392,449},
{-2489,-1397,441},
{-2498,-1403,438},
{-2507,-1409,442},
{-2517,-1413,439},
{-2527,-1417,432},
{-2537,-1424,425},
{-2547,-1429,419},
{-2554,-1438,413},
{-2564,-1447,408},
{-2573,-1449,407},
{-2582,-1447,407},
{-2593,-1451,403},
{-2604,-1459,396},
{-2614,-1468,391},
{-2621,-1475,385},
{-2629,-1478,381},
{-2639,-1478,376},
{-2648,-1483,372},
{-2656,-1493,370},
{-2664,-1503,369},
{-2673,-1513,365},
{-2683,-1518,357},
{-2694,-1527,351},
{-2706,-1541,342},
{-2715,-1542,334},
{-2723,-1538,330},
{-2734,-1547,331},
{-2745,-1560,330},
{-2753,-1567,324},
{-2764,-1572,318},
{-2774,-1575,315},
{-2782,-1575,313},
{-2792,-1584,312},
{-2802,-1596,313},
{-2812,-1603,311},
{-2823,-1608,305},
{-2833,-1615,300},
{-2843,-1624,297},
{-2854,-1624,292},
{-2866,-1626,284},
{-2878,-1632,281},
{-2886,-1637,280},
{-2896,-1640,276},
{-2907,-1643,270},
{-2917,-1647,265},
{-2929,-1652,261},
{-2941,-1665,258},
{-2949,-1683,253},
{-2956,-1689,250},
{-2967,-1691,249},
{-2975,-1700,250},
{-2985,-1705,246},
{-2995,-1710,239},
{-3004,-1713,232},
{-3016,-1705,224},
{-3028,-1713,220},
{-3036,-1735,217},
{-3048,-1738,217},
{-3061,-1737,219},
{-3070,-1745,216},
{-3080,-1748,211},
{-3088,-1756,207},
{-3097,-1765,201},
{-3107,-1771,196},
{-3116,-1777,190},
{-3128,-1780,188},
{-3140,-1786,191},
{-3149,-1794,192},
{-3156,-1802,188},
{-3165,-1805,178},
{-3176,-1803,169},
{-3185,-1807,163},
{-3191,-1816,159},
{-3199,-1824,160},
{-3209,-1825,160},
{-3218,-1830,154},
{-3225,-1843,147},
{-3234,-1851,140},
{-3239,-1853,135},
};


#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -12743)

int16_t accel_residual_offset[] = { -24,-30,-119} ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{3,2,1},
{3,2,1},
{2,2,0},
{2,1,0},
{3,1,3},
{4,1,5},
{5,1,3},
{5,0,2},
{5,0,1},
{5,0,1},
{5,0,0},
{6,0,0},
{5,0,0},
{5,0,0},
{5,0,0},
{6,0,0},
{6,-1,0},
{5,-1,0},
{5,-1,0},
{6,-2,0},
{6,-2,0},
{7,-2,0},
{6,-2,0},
{6,-2,0},
{7,-2,0},
{7,-2,0},
{7,-3,0},
{7,-3,0},
{7,-3,0},
{7,-3,0},
{7,-3,0},
{7,-4,0},
{7,-4,0},
{8,-4,0},
{7,-4,1},
{7,-4,1},
{8,-4,1},
{8,-4,1},
{8,-5,1},
{8,-5,2},
{8,-5,2},
{9,-5,2},
{9,-5,2},
{9,-5,2},
{9,-6,3},
{9,-6,3},
{9,-6,3},
{10,-6,3},
{10,-7,3},
{10,-7,3},
{10,-7,4},
{10,-7,4},
{10,-7,4},
{11,-7,4},
{11,-7,4},
{11,-7,5},
{11,-8,5},
{11,-8,5},
{11,-8,6},
{11,-8,6},
{11,-8,6},
{11,-8,6},
{11,-9,6},
{12,-9,7},
{12,-9,7},
{12,-9,7},
{12,-9,7},
{12,-9,8},
{12,-9,8},
{12,-9,8},
{12,-10,9},
{12,-10,10},
{12,-9,10},
{13,-9,10},
{12,-9,10},
{11,-9,11},
{11,-10,12},
{11,-10,12},
{12,-10,12},
{12,-10,13},
{12,-10,13},
{12,-10,14},
{12,-10,14},
{11,-10,15},
{11,-9,16},
{12,-9,17},
{12,-9,17},
{11,-9,18},
{11,-9,18},
{12,-9,19},
{12,-9,20},
{12,-9,20},
{12,-9,21},
{12,-9,21},
{12,-8,22},
{12,-8,23},
{12,-8,23},
{12,-8,24},
{12,-8,24},
{13,-8,24},
{13,-8,25},
{13,-8,25},
{13,-8,26},
{13,-8,26},
{13,-8,27},
{14,-8,27},
{14,-8,27},
{14,-8,28},
{14,-8,28},
{14,-8,29},
{14,-9,29},
{14,-9,29},
{14,-9,30},
{15,-9,30},
{15,-9,30},
{15,-9,31},
{15,-9,31},
{15,-9,31},
{15,-9,32},
{15,-9,32},
{15,-9,33},
{15,-9,33},
{15,-9,33},
{16,-9,34},
{16,-9,34},
{16,-9,35},
{16,-10,35},
{16,-10,36},
{16,-10,36},
{16,-10,37},
{16,-10,37},
{17,-10,38},
{17,-10,38},
{17,-10,39},
{17,-10,39},
{17,-10,40},
{17,-10,40},
{17,-10,40},
{17,-10,41},
{17,-10,41},
{17,-11,42},
{18,-11,42},
{18,-11,43},
{18,-11,43},
{18,-11,44},
{18,-11,44},
{18,-11,45},
{18,-11,45},
{18,-11,45},
{19,-11,46},
{19,-11,46},
{19,-11,47},
{19,-11,47},
{19,-11,47},
{19,-11,48},
{19,-11,48},
{19,-12,49},
{19,-12,49},
{19,-12,49},
{20,-12,50},
{20,-12,50},
{20,-12,51},
{20,-12,51},
{20,-12,51},
{20,-12,52},
{20,-13,52},
{20,-13,53},
{20,-13,53},
{20,-13,54},
{20,-13,54},
{20,-13,54},
{21,-13,55},
{21,-13,55},
{21,-13,56},
{21,-14,56},
{21,-14,57},
{21,-14,57},
{21,-14,57},
{21,-14,57},
{22,-14,58},
{22,-14,58},
{22,-14,59},
{22,-14,59},
{22,-14,59},
{22,-15,60},
{22,-15,60},
{22,-15,60},
{23,-15,61},
{23,-15,61},
{23,-15,61},
{23,-15,62},
{23,-15,62},
{23,-15,62},
{23,-16,63},
{23,-16,63},
{23,-16,63},
{23,-16,64},
{23,-16,64},
{24,-16,65},
{24,-16,65},
{24,-16,65},
{24,-16,66},
{24,-16,66},
{24,-16,67},
{24,-16,67},
{24,-17,67},
{24,-17,68},
{24,-17,68},
{24,-17,69},
{24,-17,69},
{24,-17,69},
{24,-17,70},
{25,-17,70},
{25,-18,70},
{25,-18,71},
{25,-18,71},
{25,-18,72},
{25,-18,72},
{25,-18,72},
{25,-18,73},
{25,-18,73},
{25,-18,74},
{25,-18,74},
{25,-19,74},
{26,-19,74},
{26,-19,75},
{26,-19,75},
{26,-19,76},
{26,-19,76},
{26,-19,77},
{26,-19,77},
{26,-20,77},
{26,-20,77},
{26,-20,78},
{26,-20,78},
{26,-20,78},
{26,-20,79},
{26,-20,79},
{26,-20,80},
{26,-20,80},
{26,-20,80},
{26,-21,81},
{26,-21,81},
{26,-21,81},
{26,-21,82},
{26,-21,82},
{26,-21,82},
{26,-21,83},
{26,-21,83},
{26,-21,84},
{26,-21,84},
{26,-22,85},
{26,-22,85},
{26,-22,86},
{27,-22,86},
{27,-22,86},
{27,-22,87},
{27,-22,87},
{27,-22,88},
{27,-22,88},
{27,-22,88},
{27,-23,89},
{27,-23,89},
{27,-23,90},
{27,-23,90},
{27,-22,91},
{27,-22,91},
{27,-23,91},
{27,-23,91},
{27,-23,92},
{27,-23,92},
{27,-23,93},
{27,-23,93},
{27,-23,94},
{27,-23,94},
{27,-23,94},
{27,-23,95},
{27,-23,96},
{27,-23,96},
{27,-23,97},
{27,-23,97},
{27,-23,98},
{28,-23,98},
{28,-23,98},
{28,-23,99},
{28,-23,99},
{28,-23,99},
{28,-23,100},
{28,-23,100},
{28,-23,101},
{28,-23,101},
{28,-23,101},
{28,-23,102},
};

#endif /* TABLE_LUGE7_SN155_H */

