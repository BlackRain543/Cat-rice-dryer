#include "beep.h"
#include "hk32f030m_beep.h" 
#include "delay.h"

void HKBEEP_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BEEPER, ENABLE ); 
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOD, ENABLE);
	
	RCC_LSICmd(ENABLE);
	while(!(RCC->CSR & RCC_CSR_LSIRDY));
	
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL;	
	GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin_1;
	GPIO_Init( GPIOD, &GPIO_InitStructure );
	 
	//GPIO_PinAFConfig(GPIOD,GPIO_PinSource1,GPIO_AF_6); 
	/*BEEP_InitTypeDef BEEP_InitStructure;

	BEEP_InitStructure.BEEP_Prescaler = 255	;
	BEEP_InitStructure.BEEP_Clock 		= BEEP_CLOCK_LSI;
	BEEP_InitStructure.BEEP_TRGOCmd 	= ENABLE;
	BEEP_Init(&BEEP_InitStructure);
	BEEP_Cmd(ENABLE);	*/
	
}

void SetPrescaler(uint8_t BEEP_Prescaler)
{
	BEEP_SetPrescaler(BEEP_Prescaler);
}

void Beep_1s(void){
	for(uint16_t i = 0;i < 385;i++){
			Sound(440);
			Delay_10us(10);	
	}	
	Sound(1);
}

void Sound(uint16_t  frq){
	uint32_t time;
	
	if(frq != 1)
	{
		time = 50000/((uint32_t)frq);
		GPIO_SetBits( GPIOD, GPIO_Pin_1);
		Delay_10us(time);
		GPIO_ResetBits( GPIOD, GPIO_Pin_1);
		Delay_10us(time);
	}else{
		Delay_10us(100);
	}
}

void PowerOn(void){
	//              	 低7  1   2   3   4   5   6   7  高1 高2 高3 高4 高5 高6 高7 高1 高2  高3  不发音
	uint16_t tone[20] = {247,262,294,330,349,392,440,494,523,587,659,698,784,880,988,1046,1175,1318,1,554};//音频数据表
	
	/*---开机音乐---*/
	//音调
	uint8_t music[]	= {	5,8,9,10,  6, 5,9,10,12,13, 9,7,3,6,19, 18};
	
	//节拍		2:半拍；4：一拍
	uint8_t time[] 	= { 4,4,4,8,  8, 4,4,4,4,8, 4,4,2,2,10, 8};	
		
		
	uint32_t yanshi;
	uint16_t i,e;
	yanshi = 10;
								
	for(i=0;i<sizeof(music)/sizeof(music[0]);i++){
		for(e=0;e<((uint16_t)time[i]*3/4)*tone[music[i]]/yanshi;e++){
			Sound((uint32_t)tone[music[i]]);
		}	
	}
}

void PowerOff(void){
	//音频数据表:       低7  1   2   3   4   5   6   7  高1 高2 高3 高4 高5 高6 高7 高1 高2  高3  不发音
	uint16_t tone[19] = {247,262,294,330,349,392,440,494,523,587,659,698,784,880,988,1046,1175,1318,1};//
	
	/*---关机音乐---*/
	//音调
	uint8_t music[]	= {	8,5,1,2, 18};
	
	//节拍		2:半拍；4：一拍
	uint8_t time[] 	= { 4,4,4,8,  8};	
		
		
	uint32_t yanshi;
	uint16_t i,e;
	yanshi = 10;
								
	for(i=0;i<sizeof(music)/sizeof(music[0]);i++){
		for(e=0;e<((uint16_t)time[i]*1/2)*tone[music[i]]/yanshi;e++){
			Sound((uint32_t)tone[music[i]]);
		}	
	}
}

void play_music(void){
	//              	 低7  1   2   3   4   5   6   7  高1 高2 高3 高4 高5 高6 高7 高1 高2  高3  不发音
	uint16_t tone[19] = {247,262,294,330,349,392,440,494,523,587,659,698,784,880,988,1046,1175,1318,1};//音频数据表
	
	/*---起风了---*/
	//音调
	uint8_t music[]	= {	8,9,10,8,  13,12,13, 14,13,14, 14,13,14,10, 15,16,15,14,13,12, 
											13,12,13,  12,13,12, 13,12, 9,12,10
										};
	
	//节拍		2:半拍；4：一拍
	uint8_t time[] 	= { 4,4,4,4,  4,2,10, 4,2,10, 4,2,8,2, 2,2,2,2,4,4,
										  4,2,4, 2,2,2, 4,2, 4,4,20};	
		
		
	uint32_t yanshi;
	uint16_t i,e;
	yanshi = 10;
								
	for(i=0;i<sizeof(music)/sizeof(music[0]);i++){
		for(e=0;e<((uint16_t)time[i])*tone[music[i]]/yanshi;e++){
			Sound((uint32_t)tone[music[i]]);
		}	
	}
}


/*//红尘情歌
	uint8_t music[]={	5,5,6,8,7,6,5,6,13,13,//音调
										5,5,6,8,7,6,5,3,13,13,
										2,2,3,5,3,5,6,3,2,1,
										6,6,5,6,5,3,6,5,13,13,

										5,5,6,8,7,6,5,6,13,13,
										5,5,6,8,7,6,5,3,13,13,
										2,2,3,5,3,5,6,3,2,1,
										6,6,5,6,5,3,6,1,	

										13,8,9,10,10,9,8,10,9,8,6,
										13,6,8,9,9,8,6,9,8,6,5,
										13,2,3,5,5,3,5,5,6,8,7,6,
										6,10,9,9,8,6,5,6,8};
	
	uint8_t time[] = {2,4,2,2,2,2,2,8,4,4, //节拍		2:半拍；4：一拍
										2,4,2,2,2,2,2,8,4, 4, 
										2,4,2,4,2,2,4,2,2,8,
										2,4,2,2,2,2,2,8,4 ,4, 

										2,4,2,2,2,2,2,8,4, 4, 
										2,4,2,2,2,2,2,8,4, 4, 
										2,4,2,4,2,2,4,2,2,8,
										2,4,2,2,2,2,2,8,

										4,2,2,2, 4, 2,2,2, 2,2,8,
										4,2,2,2,4,2,2,2,2,2,8,
										4,2,2,2,4,2,2,5,2,6,2,4,
										2,2,2,4,2,4,2,2,12};	*/

		/*---打上花火---*/
	/*//音调
	uint8_t music[]	= {	10,12,10, 9,8,6,8,9,18, 10,12,10, 9,8,6,8,8,18,
											10,12,10, 9,18,10,12,12, 13,12,11,10,18, 
		
											10,12,10, 9,8,6,8,9,18, 10,12,10, 9,8,6,8,8,18, 
											8,7,6,7,  6,6,9, 7,6,7,7, 8,18};
	
	//节拍		2:半拍；4：一拍
	uint8_t time[] 	= { 4,2,2,  4,4,2,4,6,4, 4,2,2, 4,4,2,4,6,4,
											4,2,2,  4,4,2,4,4, 6,2,2,20,4,
		
											4,2,2,  4,4,2,4,6,4, 4,2,2, 4,4,2,4,6,4,
										  2,2,2,2, 6,2,8, 4,4,4,8, 20,8 };*/
	

