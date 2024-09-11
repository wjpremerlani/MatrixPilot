

#ifndef TABLE_LUGE7_SN089_H
#define	TABLE_LUGE7_SN089_H

// used in LUGE7_SN089 partition size 64

#define STEP_SIZE 64


#define TABLE_ORIGIN ( -10969)

int16_t residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry gyro_offset_table[] = {
{-680,-1402,-2093},
{-677,-1402,-2087},
{-659,-1399,-2064},
{-645,-1402,-2047},
{-621,-1414,-2037},
{-603,-1426,-2024},
{-608,-1430,-2012},
{-590,-1432,-2003},
{-571,-1447,-1990},
{-563,-1455,-1967},
{-557,-1460,-1957},
{-543,-1472,-1952},
{-518,-1470,-1939},
{-491,-1469,-1917},
{-488,-1486,-1914},
{-491,-1497,-1909},
{-482,-1495,-1898},
{-478,-1498,-1893},
{-467,-1507,-1871},
{-452,-1509,-1849},
{-439,-1512,-1841},
{-429,-1532,-1831},
{-421,-1545,-1821},
{-415,-1544,-1812},
{-417,-1554,-1810},
{-410,-1565,-1807},
{-389,-1570,-1791},
{-373,-1578,-1779},
{-355,-1586,-1764},
{-346,-1597,-1756},
{-335,-1603,-1751},
{-326,-1607,-1740},
{-336,-1622,-1736},
{-337,-1632,-1728},
{-332,-1628,-1719},
{-320,-1624,-1708},
{-298,-1626,-1691},
{-276,-1623,-1670},
{-264,-1620,-1652},
{-255,-1611,-1625},
{-242,-1608,-1606},
{-237,-1611,-1601},
{-237,-1614,-1596},
{-232,-1624,-1593},
{-211,-1626,-1579},
{-199,-1627,-1563},
{-206,-1634,-1561},
{-213,-1647,-1565},
{-207,-1656,-1555},
{-190,-1663,-1532},
{-187,-1669,-1523},
{-190,-1677,-1526},
{-186,-1686,-1523},
{-187,-1688,-1520},
{-171,-1690,-1500},
{-157,-1692,-1480},
{-159,-1698,-1476},
{-154,-1709,-1461},
{-149,-1713,-1448},
{-132,-1715,-1433},
{-111,-1721,-1416},
{-114,-1727,-1413},
{-110,-1730,-1406},
{-103,-1736,-1401},
{-102,-1745,-1398},
{-101,-1752,-1388},
{-98,-1756,-1379},
{-98,-1761,-1374},
{-101,-1767,-1369},
{-106,-1771,-1358},
{-108,-1776,-1350},
{-109,-1781,-1343},
{-115,-1784,-1333},
{-115,-1785,-1320},
{-113,-1789,-1309},
{-112,-1787,-1295},
{-119,-1787,-1289},
{-130,-1794,-1290},
{-125,-1794,-1273},
{-125,-1792,-1252},
{-142,-1793,-1248},
{-162,-1798,-1244},
{-182,-1798,-1230},
{-194,-1795,-1222},
{-210,-1795,-1220},
{-238,-1797,-1216},
{-260,-1796,-1210},
{-290,-1792,-1206},
{-332,-1795,-1203},
{-362,-1790,-1190},
{-389,-1777,-1170},
{-421,-1768,-1159},
{-461,-1765,-1160},
{-503,-1764,-1154},
{-541,-1757,-1132},
{-579,-1746,-1117},
{-619,-1736,-1112},
{-654,-1727,-1105},
{-687,-1720,-1097},
{-732,-1712,-1091},
{-774,-1706,-1086},
{-797,-1701,-1066},
{-820,-1694,-1049},
{-851,-1692,-1046},
{-880,-1687,-1043},
{-903,-1681,-1028},
{-918,-1682,-1017},
{-928,-1678,-1008},
{-935,-1676,-999},
{-947,-1675,-989},
{-962,-1672,-979},
{-977,-1669,-973},
{-995,-1668,-964},
{-1014,-1666,-958},
{-1023,-1661,-941},
{-1027,-1659,-925},
{-1034,-1656,-917},
{-1038,-1648,-906},
{-1052,-1648,-898},
{-1073,-1654,-885},
{-1082,-1654,-874},
{-1098,-1648,-873},
{-1117,-1644,-863},
{-1124,-1642,-842},
{-1125,-1641,-823},
{-1134,-1643,-823},
{-1161,-1646,-831},
{-1184,-1647,-824},
{-1192,-1644,-808},
{-1205,-1649,-803},
{-1217,-1654,-798},
{-1229,-1653,-788},
{-1237,-1646,-780},
{-1244,-1641,-771},
{-1259,-1641,-764},
{-1278,-1638,-752},
{-1299,-1641,-747},
{-1309,-1645,-746},
{-1309,-1640,-729},
{-1315,-1635,-712},
{-1323,-1635,-702},
{-1344,-1646,-710},
{-1366,-1655,-710},
{-1366,-1651,-692},
{-1369,-1646,-678},
{-1391,-1644,-666},
{-1405,-1637,-651},
{-1399,-1626,-627},
{-1399,-1623,-613},
{-1408,-1621,-605},
{-1417,-1615,-592},
{-1436,-1619,-586},
{-1461,-1630,-587},
{-1479,-1632,-581},
{-1486,-1627,-563},
{-1489,-1622,-551},
{-1497,-1624,-545},
{-1510,-1630,-541},
{-1523,-1627,-539},
{-1540,-1624,-532},
{-1556,-1623,-519},
{-1566,-1623,-505},
{-1574,-1618,-492},
{-1578,-1616,-480},
{-1580,-1622,-476},
{-1587,-1627,-468},
{-1602,-1623,-457},
{-1619,-1616,-449},
{-1636,-1612,-447},
{-1657,-1614,-448},
{-1671,-1610,-439},
{-1675,-1603,-424},
{-1690,-1608,-418},
{-1702,-1612,-413},
{-1704,-1612,-398},
{-1727,-1617,-400},
{-1750,-1617,-399},
{-1755,-1605,-378},
{-1766,-1603,-362},
{-1784,-1607,-356},
{-1796,-1605,-351},
{-1802,-1604,-342},
{-1813,-1599,-334},
{-1832,-1598,-325},
{-1854,-1606,-324},
{-1868,-1609,-321},
{-1876,-1604,-305},
{-1889,-1600,-295},
{-1898,-1598,-286},
{-1903,-1598,-275},
{-1909,-1597,-259},
{-1910,-1591,-242},
{-1915,-1589,-235},
{-1932,-1591,-228},
{-1953,-1590,-219},
{-1972,-1591,-215},
{-1978,-1592,-213},
{-1978,-1591,-204},
{-1985,-1589,-190},
{-2004,-1588,-185},
{-2026,-1590,-188},
{-2040,-1590,-183},
{-2055,-1588,-175},
{-2057,-1584,-161},
{-2061,-1584,-151},
{-2080,-1590,-150},
{-2099,-1598,-148},
{-2111,-1599,-142},
{-2112,-1593,-127},
{-2113,-1587,-107},
{-2120,-1583,-93},
{-2134,-1584,-90},
{-2146,-1589,-95},
{-2150,-1589,-90},
{-2155,-1585,-81},
{-2158,-1578,-72},
{-2159,-1568,-56},
{-2164,-1564,-41},
{-2170,-1565,-29},
{-2173,-1564,-27},
{-2175,-1560,-30},
{-2186,-1563,-33},
{-2199,-1567,-34},
{-2196,-1562,-27},
{-2186,-1554,-19},
{-2171,-1548,-24},
{-2145,-1541,-28},
{-2122,-1536,-19},
{-2107,-1535,-13},
{-2102,-1538,-6},
{-2108,-1546,5},
{-2124,-1552,6},
{-2138,-1551,11},
{-2143,-1549,29},
{-2154,-1552,42},
{-2165,-1555,49},
{-2169,-1552,59},
{-2180,-1549,70},
{-2196,-1549,69},
{-2213,-1550,73},
{-2221,-1551,82},
{-2219,-1545,97},
{-2217,-1539,123},
{-2219,-1536,140},
{-2223,-1534,147},
{-2234,-1531,152},
{-2250,-1523,155},
{-2266,-1524,160},
{-2286,-1527,160},
{-2304,-1522,167},
{-2318,-1519,175},
{-2323,-1515,182},
{-2323,-1513,200},
{-2336,-1516,209},
{-2347,-1514,214},
{-2360,-1512,217},
{-2375,-1513,220},
{-2383,-1513,232},
{-2388,-1511,243},
{-2399,-1513,241},
{-2405,-1515,244},
{-2406,-1515,254},
{-2412,-1513,268},
{-2422,-1508,285},
{-2436,-1512,290},
{-2445,-1517,299},
{-2457,-1514,312},
{-2471,-1517,313},
{-2473,-1522,317},
{-2472,-1525,330},
{-2482,-1528,336},
{-2491,-1531,346},
{-2494,-1534,363},
{-2496,-1532,381},
{-2500,-1526,396},
{-2506,-1522,398},
{-2505,-1524,389},
{-2504,-1532,388},
{-2516,-1539,395},
{-2532,-1539,403},
{-2544,-1538,416},
{-2546,-1535,429},
{-2543,-1524,452},
{-2545,-1517,470},
{-2551,-1519,478},
{-2566,-1517,485},
};


#endif	/* TABLE_LUGE7_SN089_H */



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -10969)

int16_t accel_residual_offset[] = { -36,-9,-131 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-1,-6,1},
{-1,-6,1},
{0,-6,11},
{1,-6,19},
{1,-7,16},
{1,-7,16},
{1,-7,16},
{2,-7,16},
{2,-7,17},
{3,-8,17},
{2,-8,18},
{2,-8,19},
{3,-9,20},
{3,-9,21},
{3,-9,21},
{4,-9,22},
{4,-9,23},
{4,-9,24},
{4,-10,24},
{5,-10,25},
{5,-10,26},
{5,-11,27},
{5,-11,27},
{5,-11,28},
{5,-12,29},
{6,-12,30},
{6,-12,30},
{6,-12,31},
{6,-13,32},
{7,-13,32},
{7,-13,32},
{7,-13,33},
{7,-13,34},
{7,-14,35},
{7,-14,35},
{7,-14,36},
{7,-14,36},
{7,-14,37},
{7,-15,37},
{7,-14,38},
{8,-14,38},
{8,-15,39},
{8,-15,39},
{9,-16,40},
{9,-16,40},
{9,-16,41},
{9,-16,42},
{9,-16,42},
{9,-16,43},
{10,-17,43},
{10,-17,44},
{10,-17,44},
{10,-17,45},
{10,-17,45},
{10,-17,46},
{10,-18,47},
{11,-18,47},
{11,-18,48},
{11,-18,48},
{12,-18,48},
{12,-19,49},
{12,-19,50},
{12,-19,50},
{12,-19,51},
{12,-19,51},
{13,-19,52},
{13,-19,52},
{13,-19,53},
{13,-19,53},
{13,-20,54},
{14,-20,54},
{14,-20,55},
{14,-20,55},
{14,-19,56},
{14,-19,57},
{14,-20,57},
{15,-20,58},
{15,-20,58},
{15,-20,58},
{15,-19,59},
{16,-19,60},
{15,-19,60},
{15,-19,61},
{16,-19,61},
{16,-19,62},
{16,-19,62},
{17,-18,63},
{17,-18,63},
{17,-18,64},
{17,-17,64},
{17,-17,65},
{17,-17,65},
{17,-17,65},
{17,-17,66},
{18,-17,67},
{18,-17,68},
{18,-18,68},
{17,-18,69},
{17,-18,69},
{18,-18,69},
{18,-19,70},
{18,-19,70},
{18,-19,70},
{18,-19,70},
{17,-20,70},
{17,-20,70},
{18,-20,70},
{18,-21,70},
{18,-21,71},
{18,-21,71},
{18,-21,72},
{18,-21,72},
{18,-21,72},
{18,-21,73},
{18,-22,73},
{18,-22,73},
{18,-22,74},
{19,-22,75},
{19,-22,75},
{19,-22,75},
{19,-22,76},
{19,-23,76},
{19,-23,76},
{19,-23,77},
{19,-23,78},
{19,-23,78},
{19,-23,79},
{20,-23,79},
{20,-24,79},
{20,-24,80},
{20,-24,80},
{20,-24,81},
{20,-24,81},
{20,-24,82},
{20,-24,82},
{21,-24,83},
{21,-25,83},
{21,-25,84},
{21,-25,84},
{21,-25,85},
{21,-25,85},
{21,-26,86},
{21,-26,86},
{21,-26,87},
{21,-26,87},
{21,-26,88},
{21,-26,88},
{21,-27,89},
{22,-27,90},
{22,-27,90},
{22,-27,91},
{22,-27,92},
{22,-28,92},
{22,-28,93},
{22,-28,93},
{22,-28,94},
{22,-28,95},
{22,-28,95},
{22,-28,96},
{22,-28,97},
{22,-29,97},
{22,-29,98},
{22,-29,99},
{22,-29,100},
{23,-29,100},
{23,-29,101},
{23,-29,102},
{23,-30,103},
{23,-30,103},
{23,-30,104},
{23,-30,104},
{23,-30,105},
{23,-31,106},
{23,-31,107},
{23,-31,107},
{24,-31,108},
{24,-31,109},
{24,-31,109},
{24,-31,110},
{24,-32,111},
{24,-32,112},
{24,-32,112},
{24,-32,113},
{24,-32,114},
{24,-32,115},
{25,-32,116},
{25,-32,117},
{25,-33,117},
{25,-33,118},
{25,-33,118},
{25,-33,119},
{25,-33,119},
{25,-33,120},
{25,-33,120},
{25,-34,121},
{25,-34,121},
{25,-34,122},
{25,-34,122},
{26,-34,123},
{26,-34,124},
{26,-35,124},
{25,-35,124},
{25,-35,125},
{25,-35,126},
{25,-35,127},
{26,-35,127},
{26,-35,128},
{26,-35,129},
{26,-35,130},
{26,-35,130},
{26,-35,131},
{26,-35,132},
{26,-36,133},
{26,-36,134},
{26,-36,135},
{26,-36,136},
{26,-36,137},
{26,-36,138},
{26,-36,139},
{26,-35,140},
{26,-35,141},
{26,-35,143},
{26,-35,144},
{26,-35,146},
{26,-35,147},
{25,-34,149},
{25,-33,151},
{25,-33,152},
{25,-32,153},
{25,-32,152},
{25,-33,152},
{25,-33,152},
{24,-33,152},
{24,-33,152},
{25,-34,152},
{25,-34,153},
{25,-34,153},
{25,-34,153},
{25,-35,153},
{25,-35,154},
{25,-35,154},
{25,-35,154},
{25,-36,154},
{24,-36,155},
{24,-36,155},
{25,-36,155},
{25,-36,155},
{25,-36,156},
{25,-37,156},
{25,-37,156},
{25,-37,157},
{25,-37,157},
{25,-38,158},
{25,-38,158},
{24,-38,159},
{24,-38,159},
{25,-38,159},
{25,-39,160},
{25,-39,161},
{25,-39,161},
{25,-39,162},
{25,-39,162},
{25,-39,163},
{24,-39,163},
{24,-40,164},
{24,-40,165},
{24,-40,166},
{24,-40,166},
{24,-40,167},
{23,-41,168},
{23,-41,169},
{23,-41,169},
{23,-41,170},
{23,-41,171},
{23,-42,171},
{24,-42,171},
{24,-41,171},
{24,-41,170},
{25,-42,169},
{25,-42,169},
{25,-42,169},
{25,-43,169},
{25,-43,169},
{25,-43,169},
{24,-43,169},
{24,-44,169},
};

