

#ifndef TABLE_LUGE7_SN165_H
#define TABLE_LUGE7_SN165_H

// used in LUGE7_SN165 partition size 64

//#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64



#define TABLE_ORIGIN ( -11762)

int16_t residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry gyro_offset_table[] = {
{-2179,819,-44},
{-1268,429,-102},
{-349,37,-165},
{-342,31,-166},
{-346,31,-170},
{-331,39,-182},
{-310,49,-192},
{-297,55,-198},
{-275,60,-196},
{-253,52,-198},
{-242,46,-206},
{-238,43,-211},
{-222,36,-210},
{-208,38,-212},
{-198,38,-223},
{-186,44,-233},
{-182,46,-235},
{-167,47,-240},
{-161,39,-251},
{-156,34,-257},
{-145,33,-262},
{-143,28,-267},
{-125,36,-273},
{-99,50,-277},
{-80,58,-274},
{-66,52,-270},
{-48,47,-279},
{-38,50,-288},
{-34,46,-287},
{-17,49,-291},
{0,54,-291},
{13,50,-291},
{38,45,-299},
{52,43,-306},
{53,44,-311},
{57,42,-317},
{65,41,-320},
{79,40,-321},
{92,41,-326},
{103,44,-332},
{124,52,-339},
{139,56,-343},
{140,50,-345},
{145,48,-351},
{158,51,-360},
{166,52,-367},
{169,55,-371},
{178,57,-374},
{192,54,-380},
{208,59,-385},
{210,57,-388},
{226,52,-389},
{248,56,-392},
{248,59,-407},
{250,59,-423},
{264,60,-422},
{283,68,-413},
{290,78,-404},
{297,84,-409},
{321,87,-411},
{327,90,-409},
{327,88,-412},
{338,85,-414},
{350,89,-420},
{364,93,-425},
{372,93,-432},
{377,93,-440},
{379,97,-447},
{379,100,-450},
{390,99,-458},
{397,99,-467},
{407,102,-471},
{424,113,-472},
{432,120,-474},
{437,120,-476},
{441,124,-479},
{445,129,-483},
{454,128,-490},
{454,126,-496},
{452,130,-503},
{462,132,-511},
{469,132,-513},
{473,138,-516},
{476,144,-526},
{477,146,-532},
{473,147,-529},
{463,151,-532},
{460,157,-536},
{468,168,-531},
{476,175,-532},
{469,174,-540},
{458,178,-544},
{459,193,-550},
{458,200,-560},
{442,199,-571},
{433,208,-578},
{433,215,-571},
{422,217,-572},
{411,221,-580},
{402,228,-582},
{391,235,-588},
{380,243,-590},
{371,249,-592},
{358,257,-599},
{328,267,-603},
{302,281,-604},
{290,289,-606},
{281,291,-616},
{272,303,-623},
{262,315,-627},
{258,321,-631},
{262,332,-634},
{262,342,-638},
{251,345,-640},
{247,349,-641},
{245,355,-643},
{240,363,-646},
{230,370,-649},
{227,379,-652},
{236,395,-658},
{236,406,-662},
{232,413,-665},
{232,421,-669},
{222,423,-673},
{214,426,-674},
{210,432,-676},
{202,438,-678},
{194,441,-680},
{193,443,-685},
{195,447,-693},
{193,449,-698},
{189,453,-699},
{189,457,-703},
{179,456,-709},
{158,453,-712},
{135,455,-713},
{135,467,-713},
{155,476,-715},
{160,478,-720},
{157,482,-724},
{147,486,-725},
{135,486,-725},
{127,486,-728},
{130,493,-734},
{137,499,-740},
{136,500,-739},
{133,504,-741},
{131,510,-746},
{123,512,-749},
{121,515,-752},
{117,517,-753},
{105,518,-756},
{103,527,-757},
{104,537,-757},
{104,543,-758},
{104,547,-765},
{105,549,-770},
{99,552,-770},
{95,555,-777},
{97,561,-780},
{99,567,-779},
{100,568,-781},
{87,570,-787},
{72,572,-794},
{67,575,-795},
{72,579,-798},
{68,581,-803},
{67,588,-806},
{75,598,-809},
{73,603,-808},
{70,609,-811},
{64,612,-820},
{58,615,-822},
{55,618,-822},
{51,621,-828},
{50,625,-834},
{56,629,-835},
{58,632,-840},
{57,636,-845},
{60,638,-850},
{63,638,-855},
{62,637,-855},
{61,641,-856},
{57,647,-860},
{51,655,-862},
{51,665,-864},
{51,671,-867},
{45,673,-871},
{34,674,-873},
{17,674,-879},
{12,677,-884},
{24,683,-886},
{32,685,-889},
{33,689,-893},
{31,693,-895},
{26,696,-898},
{15,701,-903},
{7,702,-908},
{1,703,-912},
{-1,707,-912},
{2,720,-911},
{2,732,-912},
{-2,737,-915},
{-8,742,-922},
{-15,746,-927},
{-25,747,-928},
{-34,751,-930},
{-36,755,-936},
{-34,756,-940},
{-37,760,-942},
{-47,762,-948},
{-47,767,-955},
{-44,774,-957},
{-50,776,-957},
{-55,776,-960},
{-59,779,-966},
{-54,787,-967},
{-44,799,-967},
{-47,806,-970},
{-54,808,-973},
{-57,812,-978},
{-61,818,-979},
{-74,824,-979},
{-80,828,-982},
{-76,829,-985},
{-84,829,-989},
{-90,834,-992},
{-88,841,-993},
{-97,843,-992},
{-97,848,-993},
{-97,852,-997},
{-104,856,-999},
{-99,869,-999},
{-95,880,-1006},
{-100,883,-1009},
{-105,884,-1008},
{-114,886,-1010},
{-121,890,-1015},
{-124,895,-1021},
{-125,900,-1024},
{-123,903,-1026},
{-124,906,-1032},
{-123,912,-1035},
{-132,912,-1036},
{-144,912,-1037},
{-145,918,-1036},
{-145,925,-1037},
{-150,930,-1040},
{-154,938,-1041},
{-153,949,-1044},
{-150,956,-1046},
{-153,960,-1049},
{-160,963,-1055},
{-171,967,-1057},
{-177,971,-1054},
{-179,973,-1054},
{-176,974,-1055},
{-173,976,-1057},
{-179,979,-1062},
{-181,983,-1065},
{-183,987,-1067},
{-192,987,-1066},
{-195,990,-1068},
{-195,998,-1073},
{-196,1009,-1076},
{-191,1020,-1077},
{-194,1024,-1079},
{-203,1024,-1076},
{-204,1027,-1071},
{-201,1031,-1073},
{-203,1034,-1078},
{-213,1038,-1080},
{-219,1040,-1084},
{-212,1042,-1087},
{-206,1046,-1090},
{-211,1049,-1096},
{-215,1054,-1101},
{-217,1058,-1106},
{-222,1059,-1109},
};


#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11762)

int16_t accel_residual_offset[] = { -25,-19,-189 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{68,-2,67},
{63,-3,82},
{58,-4,97},
{57,-4,97},
{57,-4,96},
{58,-4,102},
{59,-5,107},
{59,-5,104},
{59,-5,104},
{59,-5,103},
{59,-6,103},
{59,-6,103},
{59,-7,103},
{60,-7,102},
{60,-7,102},
{60,-7,102},
{60,-8,102},
{60,-8,102},
{60,-9,102},
{60,-9,102},
{60,-9,102},
{60,-9,102},
{60,-9,101},
{59,-10,101},
{59,-11,101},
{60,-11,101},
{59,-11,101},
{59,-11,101},
{59,-11,101},
{60,-11,102},
{60,-12,102},
{60,-12,102},
{60,-12,102},
{60,-12,103},
{60,-13,103},
{60,-13,103},
{59,-13,103},
{59,-13,103},
{60,-14,103},
{59,-14,103},
{59,-14,103},
{59,-14,103},
{59,-15,103},
{59,-15,104},
{59,-16,104},
{59,-16,104},
{59,-16,104},
{59,-16,104},
{59,-16,104},
{58,-16,104},
{57,-17,105},
{57,-17,105},
{58,-17,104},
{58,-17,104},
{57,-18,105},
{56,-18,105},
{55,-18,106},
{55,-18,106},
{56,-18,106},
{56,-19,107},
{56,-19,106},
{56,-19,105},
{56,-19,106},
{56,-19,106},
{56,-19,106},
{56,-20,106},
{56,-20,107},
{56,-20,107},
{55,-20,107},
{55,-20,107},
{55,-20,108},
{55,-20,108},
{54,-20,109},
{54,-20,109},
{54,-20,109},
{54,-20,109},
{54,-20,110},
{54,-20,110},
{54,-20,110},
{54,-20,111},
{54,-20,111},
{54,-20,111},
{53,-20,111},
{53,-20,112},
{54,-20,112},
{54,-20,112},
{54,-19,112},
{54,-19,113},
{54,-19,113},
{53,-19,113},
{53,-19,113},
{53,-19,114},
{53,-19,114},
{54,-19,114},
{53,-19,115},
{53,-18,115},
{53,-18,115},
{53,-18,115},
{53,-18,116},
{53,-19,116},
{53,-19,116},
{53,-19,117},
{52,-19,117},
{52,-19,117},
{52,-19,117},
{52,-19,117},
{52,-19,118},
{51,-20,118},
{51,-20,118},
{51,-20,118},
{51,-20,118},
{51,-21,119},
{51,-21,119},
{51,-21,119},
{50,-21,119},
{50,-21,119},
{50,-21,119},
{50,-22,119},
{50,-22,119},
{50,-22,119},
{50,-22,120},
{50,-22,120},
{49,-22,120},
{49,-22,121},
{49,-22,121},
{49,-22,121},
{49,-22,122},
{49,-23,122},
{49,-23,122},
{49,-23,123},
{49,-23,123},
{49,-23,123},
{49,-23,124},
{48,-23,124},
{48,-23,125},
{48,-23,125},
{48,-23,125},
{48,-23,126},
{48,-23,126},
{48,-24,126},
{48,-24,126},
{47,-24,127},
{47,-24,127},
{47,-24,128},
{47,-24,128},
{47,-24,128},
{47,-24,129},
{47,-25,129},
{47,-25,129},
{47,-25,129},
{47,-25,130},
{46,-25,130},
{46,-25,131},
{46,-25,131},
{46,-25,132},
{46,-26,132},
{46,-26,132},
{46,-26,133},
{45,-26,133},
{45,-26,133},
{45,-26,133},
{45,-26,134},
{45,-26,134},
{45,-26,135},
{45,-27,135},
{45,-27,135},
{45,-27,136},
{45,-27,136},
{45,-27,136},
{44,-27,137},
{44,-27,137},
{44,-27,137},
{44,-28,137},
{44,-28,138},
{44,-28,138},
{44,-28,138},
{44,-28,138},
{43,-29,139},
{43,-29,139},
{43,-29,139},
{43,-29,140},
{43,-29,140},
{42,-29,140},
{42,-29,140},
{42,-29,141},
{42,-29,141},
{42,-30,141},
{42,-30,142},
{42,-30,142},
{42,-30,142},
{42,-30,143},
{42,-30,143},
{42,-31,143},
{42,-31,143},
{42,-31,144},
{41,-31,144},
{41,-31,144},
{41,-31,144},
{41,-31,145},
{41,-31,145},
{41,-32,145},
{41,-32,146},
{40,-32,146},
{40,-32,146},
{40,-32,146},
{40,-33,147},
{40,-33,147},
{40,-33,147},
{39,-33,147},
{39,-33,148},
{39,-33,148},
{39,-33,148},
{39,-34,149},
{38,-34,149},
{38,-34,149},
{38,-34,149},
{38,-34,150},
{38,-34,150},
{38,-34,150},
{38,-34,151},
{38,-34,151},
{38,-34,152},
{38,-34,152},
{37,-34,152},
{37,-35,152},
{37,-35,153},
{37,-35,153},
{37,-35,153},
{37,-35,154},
{36,-36,154},
{36,-35,154},
{36,-35,155},
{36,-36,155},
{36,-36,155},
{36,-36,156},
{36,-36,156},
{36,-36,156},
{36,-36,157},
{35,-36,157},
{35,-36,157},
{35,-36,158},
{35,-36,158},
{35,-36,158},
{35,-36,159},
{35,-36,159},
{35,-36,159},
{35,-37,160},
{34,-37,160},
{34,-37,161},
{34,-37,161},
{34,-37,161},
{34,-37,162},
{34,-37,162},
{33,-37,163},
{33,-37,163},
{33,-37,163},
{33,-37,164},
{33,-37,164},
{33,-38,164},
{33,-38,165},
{33,-38,165},
{32,-38,166},
{32,-38,166},
{32,-38,167},
{32,-38,167},
{32,-38,167},
{32,-38,168},
{32,-38,168},
{32,-38,169},
{31,-38,169},
{31,-38,170},
{31,-38,170},
{31,-38,171},
{31,-38,171},
{31,-38,172},
{31,-38,172},
{31,-38,173},
{31,-38,173},
{31,-38,174},
};

#endif /* TABLE_LUGE7_SN165_H */

