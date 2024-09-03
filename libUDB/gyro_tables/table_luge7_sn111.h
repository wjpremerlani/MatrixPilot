

#ifndef TABLE_LUGE7_SN111_H
#define	TABLE_LUGE7_SN111_H

// used in LUGE7_SN111 partition size 64

#define X_CROSS_COUPLING 50
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64



#define TABLE_ORIGIN ( -12337)

int16_t residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry gyro_offset_table[] = {
{918,362,438},
{918,367,433},
{917,376,414},
{919,376,398},
{931,370,388},
{948,361,372},
{961,359,362},
{964,356,353},
{956,353,347},
{947,353,341},
{958,350,330},
{972,347,320},
{967,340,312},
{965,337,303},
{964,331,303},
{958,323,293},
{962,328,283},
{969,335,280},
{968,328,265},
{967,319,248},
{971,320,234},
{978,324,228},
{980,326,229},
{980,326,226},
{985,320,215},
{984,310,198},
{982,302,190},
{991,299,186},
{995,293,173},
{997,285,165},
{1004,280,160},
{1003,281,147},
{1002,282,137},
{1001,278,133},
{1003,271,127},
{1003,263,119},
{1008,258,105},
{1016,267,94},
{1024,270,92},
{1028,261,82},
{1023,251,64},
{1019,244,56},
{1014,245,56},
{1011,238,51},
{1013,236,44},
{1018,234,38},
{1021,227,31},
{1026,221,23},
{1031,219,9},
{1031,217,5},
{1028,211,4},
{1028,209,-5},
{1030,208,-14},
{1029,200,-20},
{1037,196,-29},
{1046,199,-40},
{1043,195,-49},
{1045,190,-53},
{1045,190,-61},
{1044,188,-75},
{1047,182,-85},
{1052,178,-90},
{1056,178,-96},
{1055,167,-107},
{1054,164,-118},
{1053,171,-123},
{1053,162,-126},
{1059,157,-132},
{1065,159,-135},
{1069,156,-137},
{1075,155,-144},
{1072,145,-162},
{1068,140,-173},
{1066,139,-167},
{1063,138,-172},
{1065,141,-185},
{1063,137,-193},
{1058,127,-191},
{1051,115,-192},
{1047,111,-206},
{1042,103,-215},
{1036,97,-216},
{1031,99,-221},
{1021,91,-232},
{1019,82,-242},
{1016,73,-250},
{1001,68,-260},
{989,68,-269},
{982,64,-278},
{967,53,-286},
{948,44,-291},
{936,41,-299},
{920,34,-306},
{903,25,-310},
{889,19,-322},
{871,21,-333},
{851,19,-334},
{828,13,-333},
{804,12,-341},
{782,11,-353},
{758,9,-366},
{733,4,-374},
{708,3,-376},
{682,4,-384},
{655,4,-392},
{628,8,-400},
{597,14,-410},
{569,20,-421},
{544,22,-427},
{521,23,-433},
{493,31,-440},
{458,34,-450},
{423,33,-462},
{389,37,-470},
{356,44,-477},
{324,50,-494},
{296,54,-509},
{271,58,-523},
{247,62,-535},
{226,64,-537},
{207,71,-545},
{180,76,-558},
{152,80,-566},
{127,85,-577},
{109,88,-587},
{96,94,-595},
{83,97,-603},
{65,97,-612},
{41,101,-620},
{20,106,-625},
{-2,105,-642},
{-26,107,-656},
{-43,114,-667},
{-57,118,-678},
{-71,119,-688},
{-87,123,-698},
{-103,125,-705},
{-123,125,-713},
{-141,128,-721},
{-159,129,-734},
{-178,131,-749},
{-193,139,-762},
{-206,142,-771},
{-220,144,-777},
{-236,149,-787},
{-254,151,-798},
{-272,155,-809},
{-287,158,-815},
{-303,161,-823},
{-318,165,-835},
{-334,167,-843},
{-350,170,-851},
{-364,170,-862},
{-382,172,-871},
{-401,175,-877},
{-416,173,-889},
{-427,172,-903},
{-442,173,-912},
{-458,175,-921},
{-474,177,-929},
{-489,178,-934},
{-507,180,-944},
{-528,183,-957},
{-543,184,-968},
{-557,185,-979},
{-570,187,-988},
{-583,188,-996},
{-597,188,-1008},
{-611,191,-1019},
{-631,191,-1026},
{-652,190,-1034},
{-665,190,-1044},
{-678,190,-1051},
{-694,190,-1058},
{-706,191,-1068},
{-720,193,-1077},
{-737,195,-1091},
{-754,198,-1100},
{-770,200,-1108},
{-786,199,-1119},
{-802,198,-1130},
{-814,200,-1137},
{-827,201,-1143},
{-843,202,-1153},
{-856,201,-1164},
{-869,203,-1175},
{-888,204,-1182},
{-904,202,-1191},
{-916,201,-1200},
{-927,202,-1204},
{-939,203,-1209},
{-952,203,-1215},
{-966,203,-1221},
{-981,205,-1231},
{-997,206,-1241},
{-1016,206,-1252},
{-1030,204,-1264},
{-1042,201,-1274},
{-1054,203,-1283},
{-1067,204,-1296},
{-1082,203,-1305},
{-1095,203,-1315},
{-1114,204,-1329},
{-1130,203,-1336},
{-1139,204,-1341},
{-1153,204,-1349},
{-1168,202,-1359},
{-1182,200,-1370},
{-1197,205,-1381},
{-1212,208,-1389},
{-1227,206,-1398},
{-1240,207,-1410},
{-1251,206,-1421},
{-1264,205,-1432},
{-1280,203,-1438},
{-1293,202,-1446},
{-1305,205,-1459},
{-1318,208,-1468},
{-1333,207,-1473},
{-1349,203,-1482},
{-1362,202,-1494},
{-1374,200,-1499},
{-1387,198,-1505},
{-1399,197,-1516},
{-1410,196,-1525},
{-1422,197,-1529},
{-1439,196,-1532},
{-1451,195,-1542},
{-1461,192,-1551},
{-1472,193,-1556},
{-1480,194,-1565},
{-1485,193,-1576},
{-1495,191,-1578},
{-1511,189,-1580},
{-1528,191,-1589},
{-1541,192,-1598},
{-1548,190,-1606},
{-1555,189,-1611},
{-1566,189,-1620},
{-1573,187,-1632},
{-1581,188,-1639},
{-1590,195,-1642},
{-1602,194,-1649},
{-1614,192,-1656},
{-1626,192,-1665},
{-1640,190,-1672},
{-1650,192,-1676},
{-1657,193,-1686},
{-1667,190,-1696},
{-1680,187,-1703},
{-1693,185,-1710},
{-1702,181,-1715},
{-1711,176,-1718},
{-1721,172,-1722},
{-1729,172,-1731},
{-1738,172,-1742},
{-1747,172,-1749},
{-1757,175,-1754},
{-1769,178,-1762},
{-1782,177,-1772},
{-1790,174,-1781},
{-1799,171,-1789},
{-1809,169,-1794},
{-1815,171,-1797},
{-1819,177,-1799},
{-1828,178,-1803},
{-1840,179,-1808},
{-1851,179,-1817},
{-1859,176,-1825},
{-1864,175,-1830},
{-1870,176,-1837},
{-1878,177,-1850},
{-1888,178,-1860},
{-1898,179,-1863},
{-1910,179,-1866},
{-1918,178,-1871},
{-1922,178,-1880},
{-1928,181,-1888},
{-1939,182,-1893},
{-1952,180,-1901},
{-1962,181,-1911},
{-1971,182,-1916},
{-1977,180,-1919},
{-1982,179,-1924},
{-1988,180,-1927},
{-1996,180,-1931},
{-2004,181,-1939},
{-2012,179,-1949},
};


#endif	/* TABLE_LUGE7_SN111_H */



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11096)

int16_t accel_residual_offset[] = { -8+6 , -46-2 , -41-3 } ; 


//6,-2,-3

const struct gyro_offset_table_entry accel_offset_table[] = {
{1,7,-6},
{1,6,-6},
{1,6,-6},
{2,6,2},
{3,5,8},
{4,5,6},
{4,5,5},
{4,5,5},
{4,5,5},
{4,4,5},
{4,4,5},
{4,4,5},
{5,4,6},
{5,4,6},
{5,3,6},
{5,3,6},
{6,3,6},
{5,3,6},
{5,3,6},
{6,2,7},
{6,2,7},
{6,2,7},
{6,2,7},
{6,2,7},
{6,2,7},
{6,1,7},
{6,1,7},
{7,1,6},
{7,1,6},
{7,1,7},
{7,0,7},
{8,0,6},
{8,0,6},
{8,0,6},
{8,0,6},
{8,0,6},
{8,0,6},
{8,0,6},
{8,0,6},
{8,0,5},
{8,0,5},
{8,0,5},
{8,0,5},
{9,0,5},
{9,0,5},
{9,0,5},
{9,0,5},
{9,0,5},
{9,-1,5},
{9,0,6},
{9,0,6},
{9,0,6},
{9,-1,6},
{9,-1,6},
{9,-1,6},
{9,-1,6},
{9,-1,6},
{9,-1,6},
{9,0,7},
{9,0,7},
{10,-1,7},
{10,-1,7},
{10,-1,7},
{10,-1,7},
{10,-1,7},
{10,-1,7},
{10,0,7},
{10,0,7},
{10,-1,8},
{10,-1,7},
{10,-1,7},
{11,-1,7},
{11,-1,8},
{11,-1,8},
{11,-1,8},
{11,-1,8},
{11,-1,8},
{11,0,8},
{11,0,8},
{11,0,8},
{11,0,9},
{12,0,9},
{12,0,9},
{12,0,9},
{12,0,9},
{12,0,9},
{12,1,9},
{12,1,9},
{12,1,9},
{12,1,9},
{12,2,10},
{12,2,10},
{13,2,10},
{13,2,10},
{13,3,10},
{13,3,10},
{13,3,10},
{13,3,11},
{13,3,11},
{13,3,11},
{13,3,11},
{13,3,11},
{12,2,11},
{12,2,11},
{13,2,11},
{13,2,11},
{13,2,11},
{13,2,11},
{13,2,11},
{13,2,11},
{12,1,11},
{12,1,11},
{12,1,11},
{12,1,11},
{13,1,11},
{13,1,11},
{13,1,11},
{13,1,11},
{13,1,11},
{13,0,11},
{13,0,11},
{13,1,11},
{13,1,12},
{13,1,12},
{13,0,12},
{13,0,12},
{13,1,12},
{13,0,12},
{13,0,12},
{14,0,12},
{14,0,12},
{14,0,12},
{14,0,13},
{14,0,13},
{14,0,13},
{14,0,13},
{14,0,13},
{14,0,13},
{14,0,14},
{14,0,14},
{14,0,14},
{14,0,14},
{14,0,14},
{14,0,14},
{14,0,14},
{14,0,14},
{14,0,14},
{14,0,15},
{14,0,15},
{14,0,15},
{15,0,15},
{15,0,15},
{15,0,16},
{15,0,16},
{14,0,16},
{14,0,16},
{15,0,16},
{15,0,17},
{15,0,17},
{15,0,17},
{15,0,17},
{15,0,18},
{15,0,18},
{15,0,18},
{15,0,18},
{15,0,19},
{15,0,19},
{15,0,19},
{15,0,19},
{15,0,20},
{15,0,20},
{15,0,20},
{15,0,21},
{15,0,21},
{15,0,21},
{16,0,21},
{16,0,22},
{16,0,22},
{16,0,22},
{16,0,22},
{16,0,23},
{16,0,23},
{16,0,24},
{16,0,24},
{16,0,24},
{16,0,25},
{17,0,25},
{17,0,26},
{17,0,26},
{17,0,27},
{17,0,27},
{17,0,28},
{17,0,28},
{17,0,28},
{17,0,28},
{17,0,28},
{17,0,28},
{17,0,28},
{17,0,28},
{17,-1,29},
{17,-1,29},
{17,-1,29},
{17,-1,29},
{17,0,30},
{18,0,30},
{18,0,30},
{18,0,30},
{18,-1,30},
{18,-1,31},
{18,0,31},
{18,0,31},
{18,-1,31},
{18,-1,32},
{18,-1,32},
{18,-1,32},
{18,-1,33},
{18,-1,33},
{18,-1,33},
{18,-1,34},
{18,-1,34},
{18,-1,34},
{18,-1,35},
{18,-1,35},
{18,-1,35},
{18,0,36},
{18,0,36},
{18,0,37},
{18,0,38},
{18,0,38},
{18,0,39},
{18,0,40},
{18,0,40},
{18,0,41},
{18,0,41},
{17,0,42},
};



