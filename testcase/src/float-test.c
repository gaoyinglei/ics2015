#include "trap.h"
#include "FLOAT.h"

int test_data[] = {1,-1,10, 2, 3, 4, 5, 6, 7, 8, 100, 200, 500, 438, 465454, 0x88888, -300, -600,  0x7fffffff, 0x80000000, 0x80000001, 0xfffffffe, 0xffffffff};

float test_data_float[] = {1.0, -1.0, 2.0, -2.0, 0.001, -0.001, 1000.01, -1000.01, 45641.0, 456878.0, 0xffffffff };

int ans_mul[] = {65536, -65536, 655360, 131072, 196608, 262144, 327680, 393216, 458752, 524288, 6553600, 13107200, 32768000, 28704768, 439222272, -2004353024, -19660800, -39321600, -65536, 0, 65536, -131072, -65536, -65536, 65536, -655360, -131072, -196608, -262144, -327680, -393216, -458752, -524288, -6553600, -13107200, -32768000, -28704768, -439222272, 2004353024, 19660800, 39321600, 65536, 0, -65536, 131072, 65536, 655360, -655360, 6553600, 1310720, 1966080, 2621440, 3276800, 3932160, 4587520, 5242880, 65536000, 131072000, 327680000, 287047680, 97320960, 1431044096, -196608000, -393216000, -655360, 0, 655360, -1310720, -655360, 131072, -131072, 1310720, 262144, 393216, 524288, 655360, 786432, 917504, 1048576, 13107200, 26214400, 65536000, 57409536, 878444544, 286261248, -39321600, -78643200, -131072, 0, 131072, -262144, -131072, 196608, -196608, 1966080, 393216, 589824, 786432, 983040, 1179648, 1376256, 1572864, 19660800, 39321600, 98304000, 86114304, 1317666816, -1718157312, -58982400, -117964800, -196608, 0, 196608, -393216, -196608, 262144, -262144, 2621440, 524288, 786432, 1048576, 1310720, 1572864, 1835008, 2097152, 26214400, 52428800, 131072000, 114819072, 1756889088, 572456960, -78643200, -157286400, -262144, 0, 262144, -524288, -262144, 327680, -327680, 3276800, 655360, 983040, 1310720, 1638400, 1966080, 2293760, 2621440, 32768000, 65536000, 163840000, 143523840, -2098855936, -1431961600, -98304000, -196608000, -327680, 0, 327680, -655360, -327680, 393216, -393216, 3932160, 786432, 1179648, 1572864, 1966080, 2359296, 2752512, 3145728, 39321600, 78643200, 196608000, 172228608, -1659633664, 858652672, -117964800, -235929600, -393216, 0, 393216, -786432, -393216, 458752, -458752, 4587520, 917504, 1376256, 1835008, 2293760, 2752512, 3211264, 3670016, 45875200, 91750400, 229376000, 200933376, -1220411392, -1145765888, -137625600, -275251200, -458752, 0, 458752, -917504, -458752, 524288, -524288, 5242880, 1048576, 1572864, 2097152, 2621440, 3145728, 3670016, 4194304, 52428800, 104857600, 262144000, 229638144, -781189120, 1144848384, -157286400, -314572800, -524288, 0, 524288, -1048576, -524288, 6553600, -6553600, 65536000, 13107200, 19660800, 26214400, 32768000, 39321600, 45875200, 52428800, 655360000, 1310720000, -1018167296, -1424490496, 973209600, 1425145856, -1966080000, 362807296, -6553600, 0, 6553600, -13107200, -6553600, 13107200, -13107200, 131072000, 26214400, 39321600, 52428800, 65536000, 78643200, 91750400, 104857600, 1310720000, -1673527296, -2036269056, 1446051840, 1946419200, -1444741120, 362807296, 725549056, -13107200, 0, 13107200, -26214400, -13107200, 32768000, -32768000, 327680000, 65536000, 98304000, 131072000, 163840000, 196608000, 229376000, 262144000, -1018167296, -2036269056, -795672576, 1467678720, 571146240, -1464401920, -1240596480, 1813774336, -32768000, 0, 32768000, -65536000, -32768000, 28704768, -28704768, 287047680, 57409536, 86114304, 114819072, 143523840, 172228608, 200933376, 229638144, -1424490496, 1446051840, 1467678720, -312082432, -891289600, -1746665472, -21626880, -43253760, -28704768, 0, 28704768, -57409536, -28704768, 439222272, -439222272, 97320960, 878444544, 1317666816, 1756889088, -2098855936, -1659633664, -1220411392, -781189120, 973209600, 1946419200, 571146240, -891289600, 1659961344, 1278803968, 1375338496, -1544355840, -439222272, 0, 439222272, -878444544, -439222272, -2004353024, 2004353024, 1431044096, 286261248, -1718157312, 572456960, -1431961600, 858652672, -1145765888, 1144848384, 1425145856, -1444741120, -1464401920, -1746665472, 1278803968, 65536, 19660800, 39321600, 2004353024, 0, -2004353024, -286261248, 2004353024, -19660800, 19660800, -196608000, -39321600, -58982400, -78643200, -98304000, -117964800, -137625600, -157286400, -1966080000, 362807296, -1240596480, -21626880, 1375338496, 19660800, 1603338240, -1088290816, 19660800, 0, -19660800, 39321600, 19660800, -39321600, 39321600, -393216000, -78643200, -117964800, -157286400, -196608000, -235929600, -275251200, -314572800, 362807296, 725549056, 1813774336, -43253760, -1544355840, 39321600, -1088290816, 2118451200, 39321600, 0, -39321600, 78643200, 39321600, -65536, 65536, -655360, -131072, -196608, -262144, -327680, -393216, -458752, -524288, -6553600, -13107200, -32768000, -28704768, -439222272, 2004353024, 19660800, 39321600, 65536, 0, -65536, 131072, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536, -65536, 655360, 131072, 196608, 262144, 327680, 393216, 458752, 524288, 6553600, 13107200, 32768000, 28704768, 439222272, -2004353024, -19660800, -39321600, -65536, 0, 65536, -131072, -65536, -131072, 131072, -1310720, -262144, -393216, -524288, -655360, -786432, -917504, -1048576, -13107200, -26214400, -65536000, -57409536, -878444544, -286261248, 39321600, 78643200, 131072, 0, -131072, 262144, 131072, -65536, 65536, -655360, -131072, -196608, -262144, -327680, -393216, -458752, -524288, -6553600, -13107200, -32768000, -28704768, -439222272, 2004353024, 19660800, 39321600, 65536, 0, -65536, 131072, 65536, };

int ans_div[] = {65536, 1, 6553, 32768, 21845, 16384, 13107, 10922, 9362, 8192, 655, 327, 131, 149, 9, 1, 1, 1, 1, -1, 65536, 1, 1, -65536, -2, -6554, -32768, -21846, -16384, -13108, -10923, -9363, -8192, -656, -328, -132, -150, -10, -2, -2, -2, -2, -1, -65536, -2, -2, 655360, 10, 65536, 327680, 218453, 163840, 131072, 109226, 93622, 81920, 6553, 3276, 1310, 1496, 97, 18, 10, 10, 10, -1, 655360, 10, 10, 131072, 2, 13107, 65536, 43690, 32768, 26214, 21845, 18724, 16384, 1310, 655, 262, 299, 19, 3, 2, 2, 2, -1, 131072, 2, 2, 196608, 3, 19660, 98304, 65536, 49152, 39321, 32768, 28086, 24576, 1966, 983, 393, 448, 29, 5, 3, 3, 3, -1, 196608, 3, 3, 262144, 4, 26214, 131072, 87381, 65536, 52428, 43690, 37449, 32768, 2621, 1310, 524, 598, 39, 7, 4, 4, 4, -1, 262144, 4, 4, 327680, 5, 32768, 163840, 109226, 81920, 65536, 54613, 46811, 40960, 3276, 1638, 655, 748, 48, 9, 5, 5, 5, -1, 327680, 5, 5, 393216, 6, 39321, 196608, 131072, 98304, 78643, 65536, 56173, 49152, 3932, 1966, 786, 897, 58, 11, 6, 6, 6, -1, 393216, 6, 6, 458752, 7, 45875, 229376, 152917, 114688, 91750, 76458, 65536, 57344, 4587, 2293, 917, 1047, 68, 13, 7, 7, 7, -1, 458752, 7, 7, 524288, 8, 52428, 262144, 174762, 131072, 104857, 87381, 74898, 65536, 5242, 2621, 1048, 1197, 78, 15, 8, 8, 8, -1, 524288, 8, 8, 6553600, 100, 655360, 3276800, 2184533, 1638400, 1310720, 1092266, 936228, 819200, 65536, 32768, 13107, 14962, 977, 187, 100, 100, 100, -1, 6553600, 100, 100, 13107200, 200, 1310720, 6553600, 4369066, 3276800, 2621440, 2184533, 1872457, 1638400, 131072, 65536, 26214, 29925, 1955, 375, 200, 201, 200, -1, 13107200, 200, 200, 32768000, 500, 3276800, 16384000, 10922666, 8192000, 6553600, 5461333, 4681142, 4096000, 327680, 163840, 65536, 74812, 4889, 937, 502, 504, 500, -1, 32768000, 500, 500, 28704768, 438, 2870476, 14352384, 9568256, 7176192, 5740953, 4784128, 4100681, 3588096, 287047, 143523, 57409, 65536, 4283, 821, 440, 442, 438, -1, 28704768, 438, 438, 439222272, 6702, 43922227, 219611136, 146407424, 109805568, 87844454, 73203712, 62746038, 54902784, 4392222, 2196111, 878444, 1002790, 65536, 12566, 6732, 6763, 6702, -1, 439222272, 6702, 6702, -1, -30585, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -57346, -30725, -30867, -30585, -1, -1, -30585, -30585, -1, -301, -1, -1, -1, -1, -1, -1, -1, -1, -196608, -98304, -39322, -44888, -2934, -563, -302, -303, -301, -1, -1, -301, -301, -1, -601, -1, -1, -1, -1, -1, -1, -1, -1, -393216, -196608, -78644, -89776, -5868, -1126, -603, -606, -601, -1, -1, -601, -601, -65536, -2, -6554, -32768, -21846, -16384, -13108, -10923, -9363, -8192, -656, -328, -132, -150, -10, -2, -2, -2, -2, -1, -65536, -2, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 65536, 1, 6553, 32768, 21845, 16384, 13107, 10922, 9362, 8192, 655, 327, 131, 149, 9, 1, 1, 1, 1, -1, 65536, 1, 1, -131072, -3, -13108, -65536, -43691, -32768, -26215, -21846, -18725, -16384, -1311, -656, -263, -300, -20, -4, -3, -3, -3, -1, -131072, -3, -3, -65536, -2, -6554, -32768, -21846, -16384, -13108, -10923, -9363, -8192, -656, -328, -132, -150, -10, -2, -2, -2, -2, -1, -65536, -2, -2};

int ans_f[] = {2520, 2520, 26, 648, 289, 163, 104, 72, 53, 40, 1, 3, 2, 5, 1, 2520, 3, 3, 2520, 65536, 2520, 648, 2520};

int ans_Com[] = {0, -36124, 1283, -36611, -17935, -18059, 129872, -132635, -3195345, -271316, -17992, 36124, 0, 36611, -1283, 18059, 17935, 132635, -129872, -2580290, -238435, 17992, -1283, -36611, 0, -42265, -19299, -19403, 34431, -46793, -686456, -65284, -19355, 36611, 1283, 42265, 0, 19403, 19299, 46793, -34431, -714168, -75068, 19355, 17935, -18060, 19305, -19409, 0, -130, 3357181, -3366187, -65356075, -6144567, -60, 18060, -17935, 19409, -19305, 130, 0, 3366187, -3357181, -65332193, -6144560, 60, -129872, -132635, -34431, -46793, -3356581, -3365487, 0, -13122531, -54327, -5460, -3360384, 132635, 129872, 46793, 34431, 3365487, 3356581, 13122531, 0, -120928, -4195, 3360384, 3046123, 2580290, 686456, 714168, 65350106, 65330204, 54327, 120928, 0, 50458, 65340156, 271316, 238435, 65284, 75068, 6144567, 6144560, 5460, 4107, -50458, 0, 6144564, 17997, -17997, 19356, -19356, 60, -60, 3364484, -3364484, -65340156, -6144564, 0, };

#define NR_DATA (sizeof(test_data) / sizeof(test_data[0]))
#define NR_DATA_f (sizeof(test_data_float) / sizeof(test_data_float[0]))
FLOAT f(FLOAT x) { 
	/* f(x) = 1/(1+25x^2) */
	return F_div_F(int2F(1), int2F(1) + F_mul_int(F_mul_F(x, x), 25));
}
FLOAT computeT(int n, FLOAT a, FLOAT b, FLOAT (*fun)(FLOAT)) {
	int k;
	FLOAT s,h;
	h = F_div_int((b - a), n);
	s = F_div_int(fun(a) + fun(b), 2 );
	for(k = 1; k < n; k ++) {
		s += fun(a + F_mul_int(h, k));
	}
	s = F_mul_F(s, h);
	return s;
}

int main() {
	//int i, j;
	/*for(i = 0; i < NR_DATA; ++i)
	for(j = 0; j < NR_DATA; ++j){
	nemu_assert(F_div_F(int2F(test_data[i]), int2F(test_data[j])) == ans_div[NR_DATA * i + j]);
	nemu_assert(F_mul_F(int2F(test_data[i]), int2F(test_data[j])) == ans_mul[NR_DATA * i + j]);
	}

	for(i = 0; i < NR_DATA; ++i)
		nemu_assert(f(int2F(test_data[i])) == ans_f[i]);*/
	nemu_assert(computeT(10, f2F(1.0), f2F(-1.0), f) == -36124);

	HIT_GOOD_TRAP;

	return 0;
}