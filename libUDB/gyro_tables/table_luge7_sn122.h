

#ifndef TABLE_LUGE7_SN122_H
#define TABLE_LUGE7_SN122_H

// used in LUGE7_SN122 partition size 64

#define X_CROSS_COUPLING 40
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64



#define TABLE_ORIGIN ( -11278)

int16_t residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry gyro_offset_table[] = {
{-882,-1537,165},
{-909,-1547,153},
{-901,-1574,149},
{-813,-1591,175},
{-787,-1602,180},
{-798,-1619,168},
{-796,-1633,175},
{-799,-1640,178},
{-782,-1614,184},
{-763,-1626,183},
{-766,-1667,172},
{-762,-1670,175},
{-745,-1673,182},
{-732,-1678,182},
{-716,-1694,168},
{-717,-1695,171},
{-717,-1688,188},
{-706,-1690,192},
{-695,-1687,188},
{-688,-1689,185},
{-677,-1698,189},
{-667,-1709,187},
{-663,-1717,181},
{-656,-1717,180},
{-649,-1717,183},
{-642,-1723,188},
{-630,-1724,188},
{-619,-1722,186},
{-614,-1721,187},
{-603,-1729,187},
{-597,-1749,183},
{-595,-1756,181},
{-595,-1753,185},
{-596,-1763,192},
{-587,-1773,193},
{-574,-1771,189},
{-563,-1768,188},
{-561,-1772,192},
{-561,-1766,189},
{-554,-1765,182},
{-540,-1784,186},
{-528,-1797,193},
{-526,-1799,199},
{-525,-1792,201},
{-522,-1789,201},
{-515,-1792,197},
{-504,-1794,194},
{-497,-1802,192},
{-490,-1803,194},
{-487,-1808,201},
{-488,-1822,203},
{-491,-1825,203},
{-496,-1827,204},
{-496,-1827,203},
{-495,-1826,204},
{-494,-1829,205},
{-490,-1838,207},
{-490,-1840,212},
{-501,-1841,214},
{-501,-1843,215},
{-494,-1847,213},
{-491,-1859,205},
{-496,-1860,206},
{-508,-1855,210},
{-505,-1848,212},
{-502,-1848,217},
{-511,-1853,221},
{-515,-1853,218},
{-524,-1846,217},
{-532,-1840,218},
{-536,-1844,215},
{-542,-1848,210},
{-545,-1845,214},
{-553,-1842,222},
{-561,-1839,221},
{-571,-1836,221},
{-585,-1832,222},
{-596,-1827,220},
{-603,-1836,217},
{-606,-1847,212},
{-609,-1849,217},
{-615,-1852,222},
{-628,-1857,220},
{-641,-1858,221},
{-653,-1850,219},
{-663,-1845,216},
{-668,-1842,214},
{-678,-1837,212},
{-687,-1834,219},
{-692,-1831,226},
{-705,-1833,221},
{-718,-1833,217},
{-722,-1828,217},
{-728,-1824,215},
{-739,-1827,215},
{-752,-1817,217},
{-759,-1799,218},
{-766,-1793,220},
{-774,-1791,224},
{-780,-1787,229},
{-792,-1789,230},
{-802,-1797,225},
{-803,-1797,220},
{-805,-1788,222},
{-810,-1790,226},
{-819,-1791,227},
{-828,-1782,228},
{-829,-1782,226},
{-833,-1782,228},
{-841,-1778,226},
{-852,-1781,224},
{-858,-1787,224},
{-855,-1788,222},
{-856,-1782,223},
{-864,-1786,225},
{-872,-1788,223},
{-879,-1790,220},
{-882,-1796,220},
{-893,-1790,221},
{-901,-1782,220},
{-904,-1776,225},
{-913,-1773,232},
{-922,-1775,234},
{-929,-1775,232},
{-936,-1778,230},
{-944,-1772,233},
{-956,-1764,235},
{-964,-1759,232},
{-965,-1758,233},
{-969,-1764,235},
{-975,-1761,234},
{-985,-1757,234},
{-998,-1761,238},
{-1007,-1761,239},
{-1013,-1761,232},
{-1014,-1764,228},
{-1016,-1766,232},
{-1017,-1768,238},
{-1022,-1773,240},
{-1038,-1777,239},
{-1049,-1772,240},
{-1053,-1760,240},
{-1060,-1754,240},
{-1068,-1755,242},
{-1073,-1764,244},
{-1075,-1773,248},
{-1081,-1771,246},
{-1085,-1768,242},
{-1087,-1768,241},
{-1099,-1767,240},
{-1115,-1766,238},
{-1125,-1767,236},
{-1130,-1765,237},
{-1138,-1764,243},
{-1144,-1760,246},
{-1151,-1761,244},
{-1160,-1767,244},
{-1173,-1765,241},
{-1181,-1764,240},
{-1189,-1761,237},
{-1197,-1762,237},
{-1197,-1776,244},
{-1205,-1779,251},
{-1219,-1769,255},
{-1227,-1769,252},
{-1233,-1761,247},
{-1236,-1759,246},
{-1243,-1770,244},
{-1251,-1768,246},
{-1254,-1771,253},
{-1261,-1774,254},
{-1268,-1777,252},
{-1279,-1779,251},
{-1291,-1772,249},
{-1297,-1770,250},
{-1301,-1771,250},
{-1302,-1772,250},
{-1306,-1783,253},
{-1317,-1785,251},
{-1332,-1777,250},
{-1343,-1773,251},
{-1352,-1779,249},
{-1360,-1786,245},
{-1363,-1787,244},
{-1365,-1785,248},
{-1370,-1790,252},
{-1376,-1805,251},
{-1382,-1805,250},
{-1391,-1805,249},
{-1400,-1800,245},
{-1407,-1792,243},
{-1411,-1799,242},
{-1418,-1804,246},
{-1425,-1811,254},
{-1428,-1816,255},
{-1436,-1814,254},
{-1444,-1814,254},
{-1449,-1810,252},
{-1456,-1810,249},
{-1469,-1803,248},
{-1480,-1796,254},
{-1483,-1811,260},
{-1487,-1819,260},
{-1494,-1816,261},
{-1502,-1817,258},
{-1512,-1814,255},
{-1520,-1813,253},
{-1526,-1814,248},
{-1536,-1811,247},
{-1544,-1814,253},
{-1552,-1822,257},
{-1558,-1825,256},
{-1566,-1825,252},
{-1578,-1829,246},
{-1592,-1826,244},
{-1600,-1819,242},
{-1604,-1819,243},
{-1611,-1826,250},
{-1616,-1827,252},
{-1622,-1829,249},
{-1633,-1833,249},
{-1641,-1830,247},
{-1648,-1826,246},
{-1660,-1822,245},
{-1669,-1822,245},
{-1677,-1824,248},
{-1690,-1818,248},
{-1699,-1815,244},
{-1704,-1826,239},
{-1711,-1826,236},
{-1721,-1817,232},
{-1730,-1823,229},
{-1736,-1826,231},
{-1745,-1828,232},
{-1756,-1835,229},
{-1766,-1831,229},
{-1775,-1826,230},
{-1785,-1828,228},
{-1793,-1835,222},
{-1801,-1829,214},
{-1810,-1819,212},
{-1818,-1821,220},
{-1825,-1824,224},
{-1832,-1828,213},
{-1846,-1823,207},
{-1860,-1815,206},
{-1867,-1819,206},
{-1877,-1818,204},
{-1891,-1820,204},
{-1903,-1823,209},
{-1912,-1816,209},
{-1922,-1808,204},
{-1935,-1806,199},
{-1944,-1813,196},
{-1951,-1822,197},
{-1960,-1824,197},
{-1971,-1821,197},
{-1982,-1821,201},
{-1988,-1825,198},
{-1994,-1828,191},
{-2005,-1825,190},
{-2015,-1821,189},
{-2026,-1823,186},
{-2037,-1823,186},
{-2045,-1819,190},
{-2057,-1816,195},
{-2071,-1812,196},
{-2080,-1813,192},
{-2086,-1823,187},
{-2093,-1828,184},
{-2101,-1833,182},
{-2110,-1833,180},
{-2114,-1830,181},
{-2117,-1835,185},
{-2126,-1838,187},
};


#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11278)

int16_t accel_residual_offset[] = { -20,-29,-100 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{3,3,0},
{3,3,0},
{3,3,-1},
{4,3,6},
{4,3,16},
{4,2,18},
{4,2,20},
{3,1,21},
{3,1,21},
{3,1,22},
{3,1,24},
{4,0,25},
{4,0,25},
{4,0,26},
{3,0,26},
{3,0,27},
{3,0,27},
{3,0,27},
{3,0,28},
{4,0,29},
{4,-1,29},
{4,-1,29},
{4,-1,29},
{4,-1,29},
{4,-2,30},
{5,-2,30},
{5,-2,30},
{5,-3,31},
{6,-3,31},
{5,-3,31},
{5,-3,31},
{6,-3,31},
{6,-3,32},
{6,-4,33},
{6,-4,33},
{6,-4,34},
{6,-4,34},
{7,-5,34},
{7,-5,34},
{7,-5,35},
{8,-5,35},
{7,-5,35},
{7,-5,36},
{8,-6,36},
{8,-6,36},
{8,-6,37},
{8,-6,37},
{8,-6,37},
{9,-6,38},
{9,-6,38},
{9,-7,39},
{9,-7,39},
{9,-7,39},
{9,-7,39},
{10,-7,40},
{10,-7,40},
{10,-7,40},
{10,-7,41},
{10,-7,41},
{11,-7,42},
{11,-7,42},
{11,-7,43},
{11,-7,43},
{11,-7,43},
{12,-7,44},
{12,-7,44},
{12,-7,45},
{12,-7,45},
{12,-7,46},
{12,-7,46},
{12,-7,46},
{12,-8,47},
{13,-8,47},
{13,-8,48},
{13,-8,48},
{13,-8,49},
{13,-8,49},
{14,-8,50},
{14,-8,50},
{14,-8,50},
{14,-8,51},
{14,-9,51},
{15,-9,51},
{15,-9,51},
{15,-9,52},
{15,-9,52},
{15,-9,53},
{15,-10,53},
{16,-10,53},
{16,-10,54},
{16,-11,54},
{16,-11,54},
{16,-11,54},
{16,-11,55},
{16,-11,55},
{17,-11,55},
{17,-11,55},
{17,-12,56},
{17,-12,56},
{17,-12,57},
{17,-12,57},
{17,-12,57},
{18,-13,58},
{18,-13,58},
{18,-13,59},
{18,-13,59},
{18,-13,59},
{18,-13,60},
{18,-13,60},
{18,-14,61},
{18,-14,61},
{18,-14,62},
{19,-14,62},
{19,-14,63},
{19,-14,63},
{19,-15,64},
{19,-15,64},
{19,-15,65},
{19,-15,65},
{20,-15,66},
{20,-15,66},
{20,-15,67},
{20,-15,67},
{20,-15,68},
{20,-16,68},
{20,-16,69},
{20,-16,69},
{20,-16,69},
{20,-16,70},
{20,-17,70},
{20,-17,71},
{21,-17,71},
{21,-17,72},
{21,-17,72},
{21,-17,73},
{21,-17,73},
{21,-17,74},
{21,-18,74},
{21,-18,75},
{21,-18,75},
{21,-18,76},
{21,-19,76},
{21,-19,77},
{21,-19,77},
{22,-19,78},
{22,-19,79},
{22,-20,79},
{22,-20,80},
{22,-20,80},
{22,-20,80},
{22,-20,81},
{22,-20,82},
{22,-21,82},
{22,-21,82},
{23,-21,83},
{23,-21,83},
{23,-21,84},
{23,-22,84},
{23,-22,85},
{23,-22,85},
{23,-22,86},
{23,-23,86},
{23,-23,87},
{23,-23,87},
{23,-23,88},
{23,-23,88},
{23,-24,88},
{24,-24,89},
{24,-24,90},
{24,-24,90},
{24,-24,90},
{24,-25,91},
{24,-25,91},
{24,-25,92},
{24,-25,92},
{24,-26,93},
{24,-26,93},
{24,-26,93},
{24,-26,94},
{24,-26,94},
{25,-26,95},
{25,-27,95},
{25,-27,96},
{25,-27,96},
{25,-27,97},
{25,-27,97},
{25,-28,98},
{25,-28,98},
{25,-28,99},
{25,-28,99},
{25,-29,100},
{25,-29,100},
{25,-29,101},
{26,-29,101},
{26,-29,102},
{26,-30,102},
{26,-30,103},
{26,-30,103},
{26,-30,103},
{26,-31,104},
{26,-31,104},
{26,-31,105},
{26,-31,105},
{26,-32,106},
{26,-32,106},
{26,-32,106},
{26,-32,107},
{26,-33,108},
{26,-33,108},
{26,-33,109},
{26,-33,109},
{26,-34,110},
{26,-34,110},
{26,-34,110},
{26,-34,111},
{26,-35,111},
{26,-35,112},
{26,-35,112},
{26,-35,113},
{26,-35,113},
{26,-35,114},
{26,-36,114},
{26,-36,115},
{26,-36,115},
{26,-36,116},
{26,-36,116},
{27,-37,116},
{26,-37,117},
{26,-37,118},
{26,-37,118},
{27,-37,119},
{26,-38,119},
{26,-38,119},
{27,-38,120},
{27,-38,120},
{27,-38,121},
{26,-38,122},
{26,-39,122},
{27,-39,123},
{27,-39,123},
{27,-39,124},
{27,-40,124},
{27,-40,125},
{27,-40,125},
{27,-40,126},
{27,-40,126},
{27,-40,127},
{27,-41,127},
{27,-41,127},
{28,-41,128},
{28,-41,128},
{28,-41,129},
{28,-41,130},
{28,-41,130},
{28,-42,131},
{28,-42,131},
{28,-42,132},
{28,-42,132},
{28,-42,133},
{28,-42,133},
{28,-42,134},
{29,-42,134},
{29,-43,135},
{29,-43,135},
{29,-43,136},
{29,-43,136},
{29,-43,137},
{29,-43,137},
{29,-43,138},
{30,-43,138},
{30,-43,139},
{30,-43,140},
{30,-43,140},
{30,-44,141},
{30,-44,141},
};

#endif /* TABLE_LUGE7_SN122_H */

