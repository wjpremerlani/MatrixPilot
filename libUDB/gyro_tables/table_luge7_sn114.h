

#ifndef TABLE_LUGE7_SN114_H
#define TABLE_LUGE7_SN114_H

// used in LUGE7_SN114 partition size 64

#define X_CROSS_COUPLING 30
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64



#define TABLE_ORIGIN ( -12175)

int16_t residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry gyro_offset_table[] = {
{-2248,62,-32},
{-1844,-65,36},
{-1431,-184,111},
{-1416,-180,118},
{-1401,-182,121},
{-1382,-174,130},
{-1363,-172,139},
{-1349,-170,144},
{-1333,-160,145},
{-1323,-153,145},
{-1314,-149,146},
{-1298,-144,140},
{-1287,-136,149},
{-1270,-124,160},
{-1255,-109,162},
{-1241,-99,168},
{-1227,-90,169},
{-1212,-78,174},
{-1193,-72,183},
{-1180,-68,189},
{-1168,-59,192},
{-1155,-57,189},
{-1147,-52,188},
{-1135,-33,198},
{-1123,-19,206},
{-1108,-7,201},
{-1091,0,203},
{-1085,5,213},
{-1082,11,223},
{-1072,18,232},
{-1053,28,232},
{-1036,36,234},
{-1036,46,239},
{-1035,58,240},
{-1020,61,238},
{-994,69,237},
{-979,82,242},
{-979,91,253},
{-973,126,265},
{-962,136,261},
{-954,119,261},
{-942,126,267},
{-928,134,267},
{-907,146,277},
{-893,157,281},
{-894,165,280},
{-887,173,280},
{-876,178,280},
{-862,189,288},
{-845,197,291},
{-835,203,288},
{-825,216,294},
{-820,220,291},
{-815,219,289},
{-810,224,298},
{-804,235,301},
{-791,246,304},
{-784,255,315},
{-778,265,318},
{-771,270,312},
{-763,274,312},
{-764,271,316},
{-766,273,323},
{-763,278,326},
{-759,278,321},
{-748,283,324},
{-743,291,326},
{-734,301,325},
{-718,307,333},
{-714,306,339},
{-706,314,341},
{-694,328,342},
{-689,335,341},
{-689,343,344},
{-688,350,348},
{-680,354,349},
{-676,364,346},
{-668,374,349},
{-658,382,357},
{-653,391,364},
{-651,401,367},
{-648,412,372},
{-640,419,380},
{-634,427,382},
{-631,440,381},
{-626,451,383},
{-620,461,386},
{-615,473,391},
{-616,485,394},
{-616,496,397},
{-611,502,400},
{-610,508,405},
{-613,514,402},
{-614,523,399},
{-613,539,404},
{-615,551,404},
{-619,555,399},
{-622,565,402},
{-621,577,409},
{-620,588,411},
{-621,601,411},
{-620,612,416},
{-619,623,421},
{-634,633,422},
{-648,645,424},
{-653,657,419},
{-661,662,417},
{-673,673,417},
{-682,687,419},
{-687,700,421},
{-691,717,424},
{-699,728,427},
{-706,738,426},
{-715,753,429},
{-723,765,431},
{-731,778,433},
{-737,794,438},
{-745,805,440},
{-757,812,438},
{-763,827,438},
{-773,846,438},
{-781,857,439},
{-783,863,442},
{-791,872,445},
{-797,885,447},
{-802,897,447},
{-805,915,446},
{-808,934,450},
{-812,947,457},
{-813,959,458},
{-819,969,456},
{-822,979,457},
{-824,989,459},
{-828,998,463},
{-832,1010,465},
{-840,1022,461},
{-849,1034,462},
{-852,1049,466},
{-851,1060,466},
{-854,1070,471},
{-860,1082,469},
{-866,1091,465},
{-871,1102,469},
{-872,1115,470},
{-873,1126,469},
{-880,1134,472},
{-888,1146,473},
{-891,1157,472},
{-894,1168,477},
{-895,1181,481},
{-898,1188,481},
{-904,1200,482},
{-910,1218,482},
{-918,1226,483},
{-923,1230,488},
{-927,1241,490},
{-930,1249,493},
{-933,1256,494},
{-939,1272,495},
{-944,1288,501},
{-945,1299,502},
{-943,1310,504},
{-942,1320,505},
{-946,1327,502},
{-954,1336,505},
{-958,1344,507},
{-958,1354,508},
{-963,1369,510},
{-972,1380,512},
{-976,1387,515},
{-974,1396,514},
{-980,1404,512},
{-989,1412,514},
{-993,1423,517},
{-997,1436,516},
{-1000,1449,517},
{-1005,1459,520},
{-1005,1469,520},
{-1006,1477,517},
{-1014,1483,514},
{-1020,1493,517},
{-1022,1503,522},
{-1027,1509,524},
{-1037,1516,520},
{-1046,1522,515},
{-1055,1531,515},
{-1058,1541,515},
{-1057,1552,519},
{-1065,1559,522},
{-1076,1566,522},
{-1082,1577,523},
{-1084,1586,524},
{-1086,1596,530},
{-1091,1604,535},
{-1098,1612,538},
{-1104,1621,539},
{-1108,1628,534},
{-1113,1636,532},
{-1117,1644,538},
{-1122,1656,542},
{-1128,1666,544},
{-1130,1672,547},
{-1134,1680,548},
{-1141,1687,546},
{-1146,1695,549},
{-1148,1706,551},
{-1153,1717,550},
{-1158,1728,549},
{-1163,1737,551},
{-1166,1745,553},
{-1170,1755,552},
{-1177,1763,550},
{-1183,1772,554},
{-1189,1777,555},
{-1192,1787,554},
{-1194,1798,553},
{-1202,1804,553},
{-1210,1811,557},
{-1219,1815,560},
{-1225,1823,559},
{-1227,1832,560},
{-1232,1838,563},
{-1236,1850,562},
{-1237,1862,561},
{-1242,1868,560},
{-1248,1875,560},
{-1252,1882,565},
{-1263,1887,566},
{-1275,1893,564},
{-1288,1898,565},
{-1295,1906,565},
{-1291,1918,566},
{-1291,1929,570},
{-1299,1937,573},
{-1306,1939,573},
{-1314,1939,570},
{-1320,1938,571},
{-1325,1941,572},
{-1332,1951,570},
{-1338,1962,574},
{-1343,1972,579},
{-1351,1982,578},
{-1359,1992,577},
{-1363,1998,581},
{-1367,2004,585},
{-1377,2007,587},
{-1387,2013,587},
{-1392,2025,589},
{-1395,2031,588},
{-1402,2034,585},
{-1412,2036,583},
{-1421,2039,581},
{-1429,2045,583},
{-1438,2052,586},
{-1445,2059,586},
{-1450,2066,586},
{-1455,2074,589},
{-1462,2081,591},
{-1468,2090,591},
{-1476,2097,590},
{-1487,2099,590},
{-1494,2098,590},
{-1502,2100,586},
{-1512,2104,582},
{-1521,2109,586},
{-1530,2118,590},
{-1533,2126,589},
{-1541,2130,596},
{-1553,2134,601},
{-1558,2141,601},
{-1572,2146,602},
{-1584,2154,605},
{-1583,2160,607},
{-1588,2162,607},
{-1597,2165,606},
{-1605,2169,605},
{-1616,2173,604},
{-1625,2176,603},
{-1629,2183,605},
{-1637,2191,608},
{-1645,2197,612},
{-1650,2199,616},
{-1655,2203,619},
{-1664,2212,620},
{-1678,2219,620},
{-1690,2218,621},
{-1700,2220,621},
{-1704,2226,620},
{-1707,2228,622},
{-1712,2232,625},
{-1717,2241,629},
{-1726,2246,631},
{-1735,2252,631},
{-1741,2266,631},
{-1747,2278,630},
{-1755,2284,633},
};


#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -12175)

int16_t accel_residual_offset[] = { 26,-9,-7 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-17,15,15},
{-17,15,14},
{-17,14,13},
{-17,14,12},
{-17,13,11},
{-16,13,16},
{-15,13,20},
{-15,12,18},
{-14,12,18},
{-14,12,18},
{-14,12,18},
{-14,11,18},
{-14,11,18},
{-14,11,18},
{-13,10,18},
{-13,10,18},
{-13,10,18},
{-13,10,18},
{-13,9,18},
{-13,9,18},
{-13,9,18},
{-13,9,18},
{-12,8,18},
{-12,8,18},
{-12,7,17},
{-12,7,17},
{-12,7,17},
{-11,6,17},
{-11,6,17},
{-11,6,17},
{-11,5,17},
{-11,5,17},
{-11,5,17},
{-11,5,17},
{-11,4,17},
{-10,4,17},
{-10,4,17},
{-10,4,18},
{-10,3,18},
{-10,3,18},
{-10,3,19},
{-10,3,18},
{-10,2,18},
{-11,2,18},
{-11,1,18},
{-11,1,18},
{-11,1,17},
{-11,0,16},
{-11,0,16},
{-11,0,16},
{-11,0,16},
{-11,0,16},
{-11,0,15},
{-11,0,15},
{-11,0,15},
{-11,0,15},
{-11,0,15},
{-11,0,15},
{-10,0,15},
{-10,-1,15},
{-10,-1,15},
{-10,-1,15},
{-10,-1,14},
{-10,-1,14},
{-10,-2,14},
{-10,-2,14},
{-9,-2,14},
{-9,-2,14},
{-9,-3,14},
{-9,-3,14},
{-9,-3,14},
{-9,-3,14},
{-9,-4,13},
{-9,-3,13},
{-9,-3,14},
{-8,-4,13},
{-8,-4,13},
{-8,-4,13},
{-8,-4,13},
{-8,-5,13},
{-8,-5,13},
{-8,-5,13},
{-8,-4,13},
{-8,-4,13},
{-7,-5,13},
{-7,-5,13},
{-7,-5,13},
{-7,-5,13},
{-7,-5,13},
{-7,-5,13},
{-7,-5,13},
{-6,-6,13},
{-6,-5,13},
{-6,-5,13},
{-6,-6,13},
{-6,-6,13},
{-6,-6,13},
{-6,-6,13},
{-6,-6,13},
{-6,-6,13},
{-6,-6,13},
{-5,-6,13},
{-5,-6,13},
{-5,-6,13},
{-5,-7,13},
{-5,-7,13},
{-5,-7,13},
{-5,-7,13},
{-5,-7,13},
{-5,-7,13},
{-5,-8,13},
{-5,-8,13},
{-5,-8,13},
{-5,-8,13},
{-5,-9,13},
{-5,-9,13},
{-5,-9,13},
{-5,-9,12},
{-5,-9,12},
{-5,-10,12},
{-5,-10,12},
{-5,-10,12},
{-5,-11,11},
{-5,-11,11},
{-5,-11,11},
{-5,-12,11},
{-4,-12,11},
{-4,-12,11},
{-4,-12,11},
{-4,-12,11},
{-4,-12,11},
{-4,-12,11},
{-4,-12,11},
{-4,-12,11},
{-4,-13,11},
{-4,-13,12},
{-4,-13,12},
{-4,-13,12},
{-4,-13,12},
{-4,-13,12},
{-4,-13,12},
{-4,-14,12},
{-4,-14,12},
{-3,-14,12},
{-3,-14,13},
{-3,-14,13},
{-4,-14,13},
{-4,-14,13},
{-4,-14,14},
{-3,-15,14},
{-3,-15,14},
{-3,-15,14},
{-3,-15,14},
{-3,-15,15},
{-3,-15,15},
{-3,-15,15},
{-3,-16,15},
{-3,-16,16},
{-3,-16,16},
{-3,-16,16},
{-3,-16,16},
{-3,-16,17},
{-3,-16,17},
{-3,-16,17},
{-3,-17,17},
{-3,-17,17},
{-3,-17,18},
{-3,-17,18},
{-3,-17,18},
{-3,-17,18},
{-2,-17,19},
{-2,-17,19},
{-2,-18,19},
{-2,-18,20},
{-2,-18,20},
{-2,-18,20},
{-2,-18,20},
{-2,-18,20},
{-2,-19,21},
{-2,-19,21},
{-2,-19,21},
{-2,-19,22},
{-2,-19,22},
{-2,-20,22},
{-2,-20,22},
{-2,-20,23},
{-2,-20,23},
{-2,-20,24},
{-2,-20,24},
{-2,-20,24},
{-2,-21,24},
{-2,-21,24},
{-1,-21,25},
{-1,-21,25},
{-1,-21,25},
{-1,-21,26},
{-1,-22,26},
{-1,-22,26},
{-1,-22,26},
{-1,-22,27},
{-1,-22,27},
{-1,-22,27},
{-1,-22,28},
{-1,-22,28},
{-1,-23,28},
{-1,-23,28},
{0,-23,29},
{0,-23,29},
{0,-23,29},
{0,-23,30},
{0,-23,30},
{0,-24,30},
{0,-24,30},
{0,-24,31},
{0,-24,31},
{0,-24,31},
{0,-25,31},
{0,-25,32},
{0,-25,32},
{0,-25,32},
{0,-25,33},
{0,-25,33},
{0,-25,33},
{0,-25,34},
{0,-26,34},
{0,-26,34},
{0,-26,35},
{0,-26,35},
{0,-26,35},
{0,-26,35},
{0,-27,36},
{0,-27,36},
{0,-27,36},
{0,-27,37},
{0,-27,37},
{0,-27,37},
{0,-28,38},
{0,-28,38},
{0,-28,38},
{0,-28,39},
{0,-28,39},
{0,-28,39},
{0,-28,40},
{0,-29,40},
{0,-29,41},
{0,-29,41},
{0,-29,41},
{0,-29,42},
{0,-29,42},
{0,-29,43},
{0,-29,43},
{0,-30,43},
{0,-30,44},
{0,-30,44},
{0,-30,44},
{0,-30,44},
{0,-30,45},
{0,-31,45},
{1,-31,45},
{1,-31,46},
{1,-31,46},
{1,-31,47},
{1,-31,47},
{1,-31,47},
{1,-31,48},
{1,-31,48},
{1,-31,49},
{1,-32,49},
{1,-32,49},
{1,-32,50},
{1,-32,50},
{1,-32,51},
{1,-32,51},
{1,-32,52},
{1,-32,52},
{1,-32,52},
{1,-33,53},
{1,-33,54},
{1,-33,54},
{1,-33,54},
{1,-33,55},
{1,-33,55},
{1,-33,56},
{1,-33,56},
{1,-33,57},
{1,-33,57},
{1,-33,57},
{1,-33,58},
{1,-33,58},
{1,-34,59},
{1,-34,59},
{1,-34,59},
{1,-34,60},
{1,-34,60},
{1,-34,61},
{1,-34,61},
};

#endif /* TABLE_LUGE7_SN114_H */

