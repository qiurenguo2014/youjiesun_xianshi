/*************************************************************************
#    FileName: bsp_dac.c
#      Author: Allen
#       Email: qiurenguo@gmail.com
#    HomePage: Allen
#       Brief: 
#  LastChange: 2014-05-12 16:06:27
*************************************************************************/
/* Includes ------------------------------------------------------------*/
#include "stm32f10x.h"
#include "bsp_dac.h"
/* Types ---------------------------------------------------------------*/
/* Constants -----------------------------------------------------------*/
/* Define --------------------------------------------------------------*/
#define DAC_DHR12R2_Address		0x40007414
#define DAC_SINNUM 2048
/* Variables -----------------------------------------------------------*/
uint16_t Esin12bit[DAC_SINNUM];
const uint16_t Escalator12bit[DAC_SINNUM] = 
{
2045,2051,2057,2063,2070,2076,2082,2088,2095,2101,2107,2114,2120,2126,2132,2139,2145,2151,2157,2164,
2170,2176,2182,2189,2195,2201,2207,2214,2220,2226,2232,2239,2245,2251,2257,2264,2270,2276,2282,2289,
2295,2301,2307,2313,2320,2326,2332,2338,2345,2351,2357,2363,2369,2376,2382,2388,2394,2400,2406,2413,
2419,2425,2431,2437,2443,2450,2456,2462,2468,2474,2480,2486,2493,2499,2505,2511,2517,2523,2529,2535,
2541,2547,2554,2560,2566,2572,2578,2584,2590,2596,2602,2608,2614,2620,2626,2632,2638,2644,2650,2656,
2662,2668,2674,2680,2686,2692,2698,2704,2710,2716,2722,2728,2733,2739,2745,2751,2757,2763,2769,2775,
2780,2786,2792,2798,2804,2810,2815,2821,2827,2833,2839,2844,2850,2856,2862,2867,2873,2879,2885,2890,
2896,2902,2907,2913,2919,2925,2930,2936,2941,2947,2953,2958,2964,2970,2975,2981,2986,2992,2997,3003,
3009,3014,3020,3025,3031,3036,3042,3047,3052,3058,3063,3069,3074,3080,3085,3090,3096,3101,3107,3112,
3117,3123,3128,3133,3139,3144,3149,3154,3160,3165,3170,3175,3181,3186,3191,3196,3201,3207,3212,3217,
3222,3227,3232,3237,3242,3248,3253,3258,3263,3268,3273,3278,3283,3288,3293,3298,3303,3308,3313,3317,
3322,3327,3332,3337,3342,3347,3352,3356,3361,3366,3371,3375,3380,3385,3390,3394,3399,3404,3409,3413,
3418,3422,3427,3432,3436,3441,3445,3450,3455,3459,3464,3468,3473,3477,3482,3486,3491,3495,3499,3504,
3508,3513,3517,3521,3526,3530,3534,3539,3543,3547,3551,3556,3560,3564,3568,3572,3576,3581,3585,3589,
3593,3597,3601,3605,3609,3613,3617,3621,3625,3629,3633,3637,3641,3645,3649,3653,3657,3661,3664,3668,
3672,3676,3680,3683,3687,3691,3695,3698,3702,3706,3709,3713,3716,3720,3724,3727,3731,3734,3738,3741,
3745,3748,3752,3755,3759,3762,3765,3769,3772,3776,3779,3782,3786,3789,3792,3795,3799,3802,3805,3808,
3811,3814,3818,3821,3824,3827,3830,3833,3836,3839,3842,3845,3848,3851,3854,3857,3860,3863,3865,3868,
3871,3874,3877,3880,3882,3885,3888,3890,3893,3896,3898,3901,3904,3906,3909,3912,3914,3917,3919,3922,
3924,3927,3929,3931,3934,3936,3939,3941,3943,3946,3948,3950,3952,3955,3957,3959,3961,3964,3966,3968,
3970,3972,3974,3976,3978,3980,3982,3984,3986,3988,3990,3992,3994,3996,3998,4000,4001,4003,4005,4007,
4009,4010,4012,4014,4015,4017,4019,4020,4022,4024,4025,4027,4028,4030,4031,4033,4034,4036,4037,4038,
4040,4041,4043,4044,4045,4046,4048,4049,4050,4051,4053,4054,4055,4056,4057,4058,4059,4060,4062,4063,
4064,4065,4065,4066,4067,4068,4069,4070,4071,4072,4073,4073,4074,4075,4076,4076,4077,4078,4078,4079,
4080,4080,4081,4081,4082,4082,4083,4083,4084,4084,4085,4085,4086,4086,4086,4087,4087,4087,4088,4088,
4088,4088,4089,4089,4089,4089,4089,4089,4089,4089,4089,4089,4089,4089,4089,4089,4089,4089,4089,4089,
4089,4089,4089,4088,4088,4088,4088,4087,4087,4087,4086,4086,4086,4085,4085,4084,4084,4083,4083,4082,
4082,4081,4081,4080,4080,4079,4078,4078,4077,4076,4076,4075,4074,4073,4073,4072,4071,4070,4069,4068,
4067,4066,4065,4065,4064,4063,4062,4060,4059,4058,4057,4056,4055,4054,4053,4051,4050,4049,4048,4046,
4045,4044,4043,4041,4040,4038,4037,4036,4034,4033,4031,4030,4028,4027,4025,4024,4022,4020,4019,4017,
4015,4014,4012,4010,4009,4007,4005,4003,4001,4000,3998,3996,3994,3992,3990,3988,3986,3984,3982,3980,
3978,3976,3974,3972,3970,3968,3966,3964,3961,3959,3957,3955,3952,3950,3948,3946,3943,3941,3939,3936,
3934,3931,3929,3927,3924,3922,3919,3917,3914,3912,3909,3906,3904,3901,3898,3896,3893,3890,3888,3885,
3882,3880,3877,3874,3871,3868,3865,3863,3860,3857,3854,3851,3848,3845,3842,3839,3836,3833,3830,3827,
3824,3821,3818,3814,3811,3808,3805,3802,3799,3795,3792,3789,3786,3782,3779,3776,3772,3769,3765,3762,
3759,3755,3752,3748,3745,3741,3738,3734,3731,3727,3724,3720,3716,3713,3709,3706,3702,3698,3695,3691,
3687,3683,3680,3676,3672,3668,3664,3661,3657,3653,3649,3645,3641,3637,3633,3629,3625,3621,3617,3613,
3609,3605,3601,3597,3593,3589,3585,3581,3576,3572,3568,3564,3560,3556,3551,3547,3543,3539,3534,3530,
3526,3521,3517,3513,3508,3504,3499,3495,3491,3486,3482,3477,3473,3468,3464,3459,3455,3450,3445,3441,
3436,3432,3427,3422,3418,3413,3409,3404,3399,3394,3390,3385,3380,3375,3371,3366,3361,3356,3352,3347,
3342,3337,3332,3327,3322,3317,3313,3308,3303,3298,3293,3288,3283,3278,3273,3268,3263,3258,3253,3248,
3242,3237,3232,3227,3222,3217,3212,3207,3201,3196,3191,3186,3181,3175,3170,3165,3160,3154,3149,3144,
3139,3133,3128,3123,3117,3112,3107,3101,3096,3090,3085,3080,3074,3069,3063,3058,3052,3047,3042,3036,
3031,3025,3020,3014,3009,3003,2997,2992,2986,2981,2975,2970,2964,2958,2953,2947,2941,2936,2930,2925,
2919,2913,2907,2902,2896,2890,2885,2879,2873,2867,2862,2856,2850,2844,2839,2833,2827,2821,2815,2810,
2804,2798,2792,2786,2780,2775,2769,2763,2757,2751,2745,2739,2733,2728,2722,2716,2710,2704,2698,2692,
2686,2680,2674,2668,2662,2656,2650,2644,2638,2632,2626,2620,2614,2608,2602,2596,2590,2584,2578,2572,
2566,2560,2554,2547,2541,2535,2529,2523,2517,2511,2505,2499,2493,2486,2480,2474,2468,2462,2456,2450,
2443,2437,2431,2425,2419,2413,2406,2400,2394,2388,2382,2376,2369,2363,2357,2351,2345,2338,2332,2326,
2320,2313,2307,2301,2295,2289,2282,2276,2270,2264,2257,2251,2245,2239,2232,2226,2220,2214,2207,2201,
2195,2189,2182,2176,2170,2164,2157,2151,2145,2139,2132,2126,2120,2114,2107,2101,2095,2088,2082,2076,
2070,2063,2057,2051,2045,2039,2033,2027,2020,2014,2008,2002,1995,1989,1983,1976,1970,1964,1958,1951,
1945,1939,1933,1926,1920,1914,1908,1901,1895,1889,1883,1876,1870,1864,1858,1851,1845,1839,1833,1826,
1820,1814,1808,1801,1795,1789,1783,1777,1770,1764,1758,1752,1745,1739,1733,1727,1721,1714,1708,1702,
1696,1690,1684,1677,1671,1665,1659,1653,1647,1640,1634,1628,1622,1616,1610,1604,1597,1591,1585,1579,
1573,1567,1561,1555,1549,1543,1536,1530,1524,1518,1512,1506,1500,1494,1488,1482,1476,1470,1464,1458,
1452,1446,1440,1434,1428,1422,1416,1410,1404,1398,1392,1386,1380,1374,1368,1362,1357,1351,1345,1339,
1333,1327,1321,1315,1310,1304,1298,1292,1286,1280,1275,1269,1263,1257,1251,1246,1240,1234,1228,1223,
1217,1211,1205,1200,1194,1188,1183,1177,1171,1165,1160,1154,1149,1143,1137,1132,1126,1120,1115,1109,
1104,1098,1093,1087,1081,1076,1070,1065,1059,1054,1048,1043,1038,1032,1027,1021,1016,1010,1005,1000,
994,989,983,978,973,967,962,957,951,946,941,936,930,925,920,915,909,904,899,894,
889,883,878,873,868,863,858,853,848,842,837,832,827,822,817,812,807,802,797,792,
787,782,777,773,768,763,758,753,748,743,738,734,729,724,719,715,710,705,700,696,
691,686,681,677,672,668,663,658,654,649,645,640,635,631,626,622,617,613,608,604,
599,595,591,586,582,577,573,569,564,560,556,551,547,543,539,534,530,526,522,518,
514,509,505,501,497,493,489,485,481,477,473,469,465,461,457,453,449,445,441,437,
433,429,426,422,418,414,410,407,403,399,395,392,388,384,381,377,374,370,366,363,
359,356,352,349,345,342,338,335,331,328,325,321,318,314,311,308,304,301,298,295,
291,288,285,282,279,276,272,269,266,263,260,257,254,251,248,245,242,239,236,233,
230,227,225,222,219,216,213,210,208,205,202,200,197,194,192,189,186,184,181,178,
176,173,171,168,166,163,161,159,156,154,151,149,147,144,142,140,138,135,133,131,
129,126,124,122,120,118,116,114,112,110,108,106,104,102,100,98,96,94,92,90,
89,87,85,83,81,80,78,76,75,73,71,70,68,66,65,63,62,60,59,57,
56,54,53,52,50,49,47,46,45,44,42,41,40,39,37,36,35,34,33,32,
31,30,28,27,26,25,25,24,23,22,21,20,19,18,17,17,16,15,14,14,
13,12,12,11,10,10,9,9,8,8,7,7,6,6,5,5,4,4,4,3,
3,3,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,2,2,2,2,3,3,3,4,4,4,5,5,6,
6,7,7,8,8,9,9,10,10,11,12,12,13,14,14,15,16,17,17,18,
19,20,21,22,23,24,25,25,26,27,28,30,31,32,33,34,35,36,37,39,
40,41,42,44,45,46,47,49,50,52,53,54,56,57,59,60,62,63,65,66,
68,70,71,73,75,76,78,80,81,83,85,87,89,90,92,94,96,98,100,102,
104,106,108,110,112,114,116,118,120,122,124,126,129,131,133,135,138,140,142,144,
147,149,151,154,156,159,161,163,166,168,171,173,176,178,181,184,186,189,192,194,
197,200,202,205,208,210,213,216,219,222,225,227,230,233,236,239,242,245,248,251,
254,257,260,263,266,269,272,276,279,282,285,288,291,295,298,301,304,308,311,314,
318,321,325,328,331,335,338,342,345,349,352,356,359,363,366,370,374,377,381,384,
388,392,395,399,403,407,410,414,418,422,426,429,433,437,441,445,449,453,457,461,
465,469,473,477,481,485,489,493,497,501,505,509,514,518,522,526,530,534,539,543,
547,551,556,560,564,569,573,577,582,586,591,595,599,604,608,613,617,622,626,631,
635,640,645,649,654,658,663,668,672,677,681,686,691,696,700,705,710,715,719,724,
729,734,738,743,748,753,758,763,768,773,777,782,787,792,797,802,807,812,817,822,
827,832,837,842,848,853,858,863,868,873,878,883,889,894,899,904,909,915,920,925,
930,936,941,946,951,957,962,967,973,978,983,989,994,1000,1005,1010,1016,1021,1027,1032,
1038,1043,1048,1054,1059,1065,1070,1076,1081,1087,1093,1098,1104,1109,1115,1120,1126,1132,1137,1143,
1149,1154,1160,1165,1171,1177,1183,1188,1194,1200,1205,1211,1217,1223,1228,1234,1240,1246,1251,1257,
1263,1269,1275,1280,1286,1292,1298,1304,1310,1315,1321,1327,1333,1339,1345,1351,1357,1362,1368,1374,
1380,1386,1392,1398,1404,1410,1416,1422,1428,1434,1440,1446,1452,1458,1464,1470,1476,1482,1488,1494,
1500,1506,1512,1518,1524,1530,1536,1543,1549,1555,1561,1567,1573,1579,1585,1591,1597,1604,1610,1616,
1622,1628,1634,1640,1647,1653,1659,1665,1671,1677,1684,1690,1696,1702,1708,1714,1721,1727,1733,1739,
1745,1752,1758,1764,1770,1777,1783,1789,1795,1801,1808,1814,1820,1826,1833,1839,1845,1851,1858,1864,
1870,1876,1883,1889,1895,1901,1908,1914,1920,1926,1933,1939,1945,1951,1958,1964,1970,1976,1983,1989,
1995,2002,2008,2014,2020,2027,2033,2039,
};

/* Functions prototypes ------------------------------------------------*/
/* Functions -----------------------------------------------------------*/
/*
@brief  关闭AC输出.
@param  None.
@retval None.
*/
void DA_StopACoutput (void)
{
	DMA_Cmd(DMA2_Channel4, DISABLE);
}
/*
@brief  开启AC输出.
@param  None.
@retval None.
*/
void DA_StartACoutput (void)
{
	DMA_Cmd(DMA2_Channel4, ENABLE);
}
/*
@brief  .
@param  None.
@retval None.
*/
void DA_SetDCoutput (uint16_t da)
{
	DA_StopACoutput ();
	DAC_SetChannel2Data (DAC_Align_12b_R,da);
}
/*BU508*/
void DA_SwitchAC (void)
{
	GPIO_WriteBit(VCLOSE_IO,VCLOSE_IO_Pin,Bit_SET);
}
void DA_SwitchDC (void)
{
	GPIO_WriteBit(VCLOSE_IO,VCLOSE_IO_Pin,Bit_RESET);
}
void DA_OpenDCMODEL (void)
{
	GPIO_WriteBit(HDC_12VOUT,HDC_12VOUT_Pin,Bit_RESET);
}
void DA_CloseDCMODEL (void)
{
	GPIO_WriteBit(HDC_12VOUT,HDC_12VOUT_Pin,Bit_SET);
}
/*
@brief  交流直流切换开关 BU508.
@param  None.
@retval None.
*/
void DA_AC_DC_Config (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin =  VCLOSE_IO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_Init(VCLOSE_IO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  HDC_12VOUT_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_Init(HDC_12VOUT, &GPIO_InitStructure);
	
	DA_SwitchDC ();
	DA_CloseDCMODEL ();
}
void DA_SetFre (float hz)
{
	uint16_t val;
	float hzs;
	if(hz == 0){
		DA_StopACoutput ();
	}else{
		hzs = hz*2048.0;
		val = 72000000/hzs;
		TIM_SetAutoreload(TIM6, val);//(现在输出25HZ,2048个点)
	}	
}
void DA_SetAmp (float amp)
{
	uint16_t i;
	if(amp >= 1){
		amp = 1;
	}
	for(i=0; i<DAC_SINNUM; i++){
		Esin12bit[i] = Escalator12bit[i]*amp;
	}
}
/*
@brief  .
@param  None.
@retval None.
*/
void DA_Configuration (void)
{
	
	DAC_InitTypeDef DAC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef	DMA_InitStructure; 	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	DA_AC_DC_Config ();
	/* Enable peripheral clocks ------------------------------------------------*/
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);
	/* GPIOA Periph clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	/* DAC Periph clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
	/* TIM6 Periph clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5;//GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure); 
	TIM_TimeBaseStructure.TIM_Period = 0x19;
	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

	TIM_PrescalerConfig(TIM6, 0x0, TIM_PSCReloadMode_Update);
	DA_SetFre (50);
	DA_SetAmp (1);
	//TIM_SetAutoreload(TIM6, 0x57e);//(现在输出25HZ,2048个点)  
	/* TIM6 TRGO selection */
	TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);
	/* DAC channel1 Configuration */
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_T6_TRGO;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Disable;
	DAC_Init(DAC_Channel_2, &DAC_InitStructure);
	DAC_Cmd(DAC_Channel_2, ENABLE);
	
	/* Enable DMA for DAC Channel1 */
	DAC_DMACmd(DAC_Channel_2, ENABLE);	
	DMA_DeInit(DMA2_Channel4);
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&Esin12bit;
	DMA_InitStructure.DMA_PeripheralBaseAddr = DAC_DHR12R2_Address;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
	DMA_InitStructure.DMA_BufferSize = DAC_SINNUM;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA2_Channel4, &DMA_InitStructure);
	/* Enable DMA2 Channel4 */
	//DMA_ITConfig (DMA2_Channel4, DMA_IT_TC, ENABLE);
	DMA_Cmd(DMA2_Channel4, DISABLE);	
	/* TIM6 enable counter */
	TIM_Cmd(TIM6, ENABLE);
	
	
}

/*********************************END OF FILE****************************/


