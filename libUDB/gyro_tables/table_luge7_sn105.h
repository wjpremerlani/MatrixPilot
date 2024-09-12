

#ifndef TABLE_LUGE7_SN105_H
#define TABLE_LUGE7_SN105_H

// used in LUGE7_SN105 partition size 64

//#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64



#define TABLE_ORIGIN ( -11660)

int16_t residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry gyro_offset_table[] = {
{1952,-1171,-1582},
{1958,-1172,-1565},
{1959,-1184,-1543},
{1950,-1196,-1545},
{1942,-1206,-1545},
{1950,-1211,-1528},
{1959,-1210,-1520},
{1961,-1221,-1521},
{1966,-1228,-1516},
{1967,-1235,-1514},
{1966,-1242,-1514},
{1959,-1248,-1507},
{1957,-1255,-1506},
{1963,-1258,-1505},
{1964,-1256,-1498},
{1963,-1260,-1491},
{1963,-1268,-1480},
{1962,-1268,-1478},
{1959,-1272,-1473},
{1952,-1277,-1465},
{1947,-1280,-1454},
{1946,-1288,-1444},
{1951,-1292,-1443},
{1954,-1299,-1442},
{1952,-1312,-1446},
{1944,-1309,-1440},
{1934,-1314,-1429},
{1932,-1329,-1431},
{1922,-1338,-1434},
{1913,-1348,-1429},
{1916,-1348,-1423},
{1922,-1354,-1428},
{1930,-1367,-1429},
{1929,-1368,-1425},
{1916,-1369,-1416},
{1907,-1374,-1404},
{1904,-1386,-1412},
{1898,-1398,-1414},
{1900,-1396,-1409},
{1904,-1395,-1409},
{1904,-1407,-1406},
{1891,-1418,-1400},
{1525,-1391,-1384},
{1591,-1397,-1388},
{1943,-1441,-1398},
{1868,-1458,-1395},
{1864,-1467,-1391},
{1857,-1460,-1380},
{1849,-1466,-1375},
{1847,-1479,-1376},
{1844,-1494,-1387},
{1837,-1519,-1393},
{1829,-1526,-1382},
{1825,-1533,-1379},
{1820,-1548,-1388},
{1819,-1551,-1391},
{1819,-1559,-1394},
{1808,-1570,-1391},
{1793,-1576,-1384},
{1786,-1584,-1388},
{1775,-1597,-1387},
{1763,-1607,-1375},
{1758,-1609,-1361},
{1755,-1612,-1358},
{1749,-1624,-1366},
{1741,-1637,-1365},
{1734,-1638,-1360},
{1724,-1641,-1360},
{1707,-1652,-1358},
{1698,-1662,-1353},
{1691,-1674,-1356},
{1684,-1687,-1368},
{1672,-1689,-1364},
{1656,-1689,-1358},
{1648,-1690,-1360},
{1633,-1692,-1360},
{1620,-1700,-1356},
{1612,-1706,-1355},
{1598,-1707,-1355},
{1589,-1712,-1355},
{1578,-1714,-1350},
{1563,-1709,-1341},
{1554,-1710,-1340},
{1543,-1709,-1333},
{1525,-1705,-1322},
{1501,-1710,-1322},
{1478,-1707,-1324},
{1463,-1704,-1330},
{1446,-1713,-1339},
{1433,-1710,-1344},
{1415,-1702,-1336},
{1383,-1700,-1323},
{1361,-1697,-1312},
{1343,-1696,-1310},
{1325,-1691,-1314},
{1312,-1684,-1307},
{1290,-1680,-1301},
{1263,-1676,-1308},
{1242,-1675,-1317},
{1222,-1673,-1319},
{1198,-1679,-1322},
{1170,-1679,-1325},
{1141,-1666,-1322},
{1123,-1658,-1312},
{1105,-1659,-1303},
{1079,-1658,-1301},
{1050,-1643,-1298},
{1020,-1640,-1301},
{1001,-1637,-1300},
{981,-1624,-1294},
{958,-1622,-1297},
{937,-1613,-1294},
{913,-1603,-1285},
{890,-1598,-1286},
{871,-1593,-1284},
{849,-1596,-1276},
{826,-1591,-1270},
{802,-1583,-1269},
{781,-1578,-1272},
{765,-1578,-1277},
{744,-1577,-1284},
{724,-1569,-1280},
{708,-1564,-1277},
{690,-1563,-1273},
{667,-1561,-1268},
{644,-1553,-1266},
{626,-1544,-1262},
{608,-1541,-1261},
{590,-1541,-1271},
{570,-1540,-1275},
{553,-1536,-1272},
{540,-1528,-1267},
{516,-1520,-1257},
{492,-1514,-1259},
{479,-1513,-1265},
{466,-1522,-1268},
{448,-1529,-1267},
{432,-1522,-1262},
{410,-1514,-1263},
{385,-1512,-1273},
{363,-1511,-1274},
{343,-1505,-1264},
{328,-1502,-1265},
{317,-1504,-1272},
{301,-1505,-1275},
{282,-1499,-1270},
{262,-1493,-1270},
{237,-1494,-1273},
{212,-1497,-1268},
{193,-1494,-1265},
{180,-1489,-1262},
{167,-1484,-1265},
{147,-1479,-1266},
{126,-1479,-1262},
{105,-1477,-1263},
{86,-1473,-1261},
{67,-1468,-1257},
{41,-1469,-1256},
{21,-1474,-1261},
{9,-1474,-1263},
{-15,-1471,-1262},
{-43,-1470,-1260},
{-62,-1471,-1262},
{-78,-1470,-1268},
{-93,-1468,-1267},
{-114,-1464,-1262},
{-132,-1463,-1263},
{-149,-1464,-1272},
{-170,-1458,-1274},
{-190,-1446,-1271},
{-207,-1441,-1268},
{-224,-1442,-1268},
{-249,-1439,-1269},
{-271,-1439,-1274},
{-288,-1441,-1280},
{-305,-1442,-1280},
{-325,-1444,-1281},
{-342,-1445,-1288},
{-352,-1447,-1291},
{-366,-1445,-1292},
{-386,-1442,-1292},
{-410,-1441,-1290},
{-427,-1440,-1294},
{-440,-1440,-1296},
{-460,-1438,-1297},
{-482,-1433,-1298},
{-502,-1431,-1299},
{-524,-1433,-1300},
{-545,-1433,-1301},
{-563,-1431,-1296},
{-576,-1418,-1290},
{-590,-1413,-1294},
{-607,-1421,-1303},
{-629,-1421,-1302},
{-654,-1415,-1296},
{-676,-1406,-1292},
{-700,-1412,-1293},
{-721,-1418,-1293},
{-736,-1417,-1293},
{-751,-1416,-1298},
{-770,-1417,-1305},
{-794,-1418,-1304},
{-816,-1412,-1302},
{-837,-1411,-1306},
{-858,-1409,-1308},
{-877,-1407,-1308},
{-893,-1405,-1305},
{-910,-1398,-1305},
{-929,-1394,-1304},
{-951,-1397,-1305},
{-971,-1399,-1307},
{-992,-1402,-1308},
{-1017,-1405,-1310},
{-1037,-1400,-1308},
{-1058,-1395,-1306},
{-1073,-1394,-1313},
{-1077,-1393,-1319},
{-1090,-1389,-1318},
{-1111,-1377,-1316},
{-1136,-1373,-1316},
{-1155,-1373,-1311},
{-1167,-1371,-1311},
{-1190,-1370,-1315},
{-1213,-1370,-1316},
{-1230,-1372,-1318},
{-1247,-1369,-1318},
{-1262,-1361,-1322},
{-1275,-1362,-1326},
{-1288,-1362,-1325},
{-1309,-1363,-1325},
{-1333,-1369,-1330},
{-1350,-1369,-1332},
{-1371,-1367,-1333},
{-1396,-1364,-1337},
{-1416,-1360,-1337},
{-1430,-1354,-1332},
{-1442,-1352,-1330},
{-1461,-1354,-1332},
{-1477,-1354,-1335},
{-1488,-1343,-1333},
{-1507,-1339,-1331},
{-1526,-1340,-1336},
{-1543,-1338,-1338},
{-1562,-1340,-1343},
{-1585,-1341,-1349},
{-1605,-1339,-1349},
{-1618,-1336,-1345},
{-1631,-1337,-1346},
{-1648,-1332,-1350},
{-1670,-1330,-1355},
{-1692,-1332,-1360},
{-1711,-1331,-1357},
{-1730,-1333,-1354},
{-1744,-1334,-1358},
{-1756,-1333,-1368},
{-1769,-1332,-1373},
{-1783,-1333,-1374},
{-1800,-1330,-1375},
{-1825,-1328,-1375},
{-1845,-1332,-1375},
{-1858,-1330,-1369},
{-1874,-1325,-1363},
{-1890,-1321,-1365},
{-1899,-1318,-1372},
{-1911,-1311,-1378},
{-1928,-1309,-1378},
{-1948,-1315,-1380},
{-1967,-1317,-1382},
{-1985,-1316,-1377},
{-2001,-1313,-1379},
{-2015,-1315,-1387},
{-2031,-1312,-1386},
{-2047,-1306,-1384},
{-2059,-1307,-1385},
{-2079,-1310,-1385},
{-2104,-1312,-1389},
{-2120,-1317,-1393},
{-2134,-1317,-1392},
{-2146,-1311,-1392},
{-2157,-1310,-1390},
{-2166,-1308,-1388},
{-2183,-1309,-1392},
{-2205,-1314,-1396},
};


#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11660)

int16_t accel_residual_offset[] = { -2,2,6 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{0,-5,0},
{0,-5,0},
{-1,-5,0},
{-1,-5,-1},
{0,-6,4},
{0,-6,8},
{1,-6,7},
{1,-7,7},
{1,-7,6},
{2,-7,6},
{2,-8,6},
{2,-8,5},
{2,-8,5},
{3,-9,4},
{3,-9,4},
{3,-10,4},
{3,-10,3},
{3,-10,2},
{3,-11,2},
{4,-11,2},
{4,-11,1},
{4,-12,0},
{4,-12,0},
{4,-12,0},
{5,-12,-1},
{5,-13,-1},
{5,-13,-1},
{5,-13,-2},
{5,-13,-3},
{5,-14,-3},
{5,-14,-4},
{5,-14,-4},
{5,-14,-4},
{5,-14,-4},
{5,-15,-5},
{6,-15,-5},
{6,-15,-6},
{6,-16,-6},
{6,-16,-7},
{7,-16,-7},
{7,-17,-7},
{7,-17,-7},
{5,-17,-12},
{5,-17,-12},
{6,-17,-7},
{6,-17,-7},
{6,-18,-8},
{5,-18,-8},
{5,-18,-9},
{4,-18,-9},
{4,-18,-10},
{4,-18,-11},
{5,-18,-11},
{5,-19,-11},
{5,-19,-11},
{5,-19,-11},
{5,-19,-12},
{5,-19,-12},
{5,-20,-12},
{5,-20,-12},
{5,-20,-13},
{6,-20,-13},
{6,-20,-13},
{6,-20,-13},
{6,-20,-13},
{6,-20,-14},
{6,-20,-14},
{6,-20,-14},
{6,-21,-14},
{6,-21,-14},
{6,-21,-14},
{7,-20,-15},
{7,-20,-15},
{7,-21,-15},
{7,-21,-15},
{7,-21,-15},
{7,-21,-16},
{7,-21,-16},
{8,-21,-16},
{8,-21,-16},
{8,-21,-16},
{8,-21,-17},
{8,-21,-17},
{8,-21,-17},
{8,-21,-17},
{9,-21,-17},
{9,-21,-18},
{9,-21,-18},
{9,-21,-18},
{9,-21,-19},
{9,-21,-19},
{9,-21,-19},
{9,-21,-19},
{10,-21,-20},
{10,-21,-20},
{10,-21,-20},
{10,-21,-20},
{10,-21,-20},
{10,-21,-21},
{10,-21,-21},
{10,-22,-21},
{10,-22,-21},
{10,-22,-21},
{10,-22,-22},
{10,-22,-22},
{10,-22,-22},
{10,-23,-23},
{10,-23,-23},
{10,-23,-23},
{10,-23,-23},
{11,-23,-24},
{11,-24,-24},
{11,-24,-24},
{11,-24,-24},
{11,-24,-25},
{11,-24,-25},
{11,-25,-25},
{11,-25,-25},
{11,-25,-26},
{11,-25,-26},
{11,-25,-26},
{11,-25,-26},
{11,-26,-27},
{11,-26,-27},
{11,-26,-27},
{12,-26,-27},
{12,-26,-27},
{12,-26,-27},
{12,-26,-28},
{12,-26,-28},
{12,-27,-28},
{12,-27,-28},
{12,-27,-28},
{12,-27,-28},
{12,-27,-28},
{12,-27,-28},
{12,-27,-28},
{12,-27,-28},
{12,-27,-28},
{12,-27,-29},
{12,-27,-29},
{13,-27,-29},
{13,-28,-29},
{13,-28,-29},
{13,-28,-29},
{13,-28,-29},
{13,-28,-29},
{13,-28,-30},
{13,-28,-30},
{13,-29,-30},
{13,-29,-30},
{13,-29,-30},
{13,-29,-30},
{13,-29,-30},
{13,-29,-30},
{13,-29,-30},
{13,-29,-30},
{13,-29,-31},
{13,-29,-31},
{14,-29,-31},
{14,-30,-31},
{14,-30,-31},
{14,-30,-31},
{14,-30,-31},
{14,-30,-31},
{14,-30,-31},
{14,-30,-31},
{14,-30,-31},
{14,-30,-31},
{14,-30,-31},
{14,-30,-31},
{14,-30,-31},
{14,-31,-32},
{14,-31,-32},
{14,-31,-32},
{14,-31,-32},
{14,-31,-32},
{14,-31,-32},
{14,-31,-32},
{14,-31,-32},
{14,-31,-32},
{15,-31,-32},
{15,-32,-32},
{15,-32,-32},
{15,-32,-32},
{15,-32,-32},
{15,-32,-32},
{15,-32,-32},
{15,-32,-32},
{15,-32,-32},
{15,-32,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-33,-32},
{16,-34,-32},
{16,-34,-33},
{16,-34,-33},
{17,-34,-33},
{17,-34,-33},
{17,-34,-33},
{17,-34,-33},
{17,-34,-33},
{17,-34,-33},
{17,-34,-33},
{17,-34,-33},
{17,-34,-33},
{17,-35,-32},
{17,-35,-32},
{17,-35,-32},
{17,-35,-33},
{17,-35,-33},
{17,-35,-33},
{18,-35,-33},
{18,-35,-33},
{18,-35,-33},
{18,-35,-33},
{18,-35,-33},
{18,-36,-33},
{18,-36,-32},
{18,-36,-32},
{18,-36,-32},
{18,-36,-32},
{18,-36,-32},
{19,-36,-32},
{19,-36,-32},
{19,-36,-32},
{19,-36,-32},
{19,-36,-32},
{19,-36,-32},
{19,-36,-32},
{19,-36,-32},
{19,-36,-32},
{19,-37,-32},
{19,-37,-32},
{20,-37,-32},
{20,-37,-32},
{20,-37,-32},
{20,-37,-32},
{20,-37,-32},
{20,-37,-32},
{20,-37,-32},
{20,-37,-32},
{20,-37,-32},
{21,-37,-32},
{21,-37,-32},
{21,-37,-32},
{21,-37,-32},
{21,-37,-31},
{21,-37,-31},
{21,-37,-31},
{21,-37,-31},
{21,-37,-31},
{21,-37,-31},
{21,-37,-31},
{21,-37,-31},
{21,-37,-31},
{21,-37,-31},
{21,-37,-31},
{21,-37,-30},
{21,-37,-30},
{21,-37,-30},
{21,-37,-30},
{21,-37,-30},
{21,-37,-30},
{21,-37,-30},
{22,-37,-30},
{22,-37,-30},
{22,-38,-29},
{22,-37,-29},
{22,-37,-29},
{22,-37,-29},
{22,-37,-29},
};

#endif /* TABLE_LUGE7_SN105_H */

