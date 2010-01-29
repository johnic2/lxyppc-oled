/*******************************************************************************
* File Name          : main.c
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 09-11-21
* Description        : Main program body
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
#include "bsp.h"
#include "SSD1303.h"
#include "Graphics\Graphics.h"  // Graphic primitives layer
#include "ClockUI.h"
#include "ClockSet.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
//#define   RTCClockSource_LSI
#define   RTCClockSource_LSE

/* Private macro -------------------------------------------------------------*/
#define WAIT_UNTIL_FINISH(x) (x)

/* Private variables ---------------------------------------------------------*/
static vu32 TimeDisplay = 0;
static const FontData world[2] = {
    /* Char  Code  width, height,  {data}  */
    {/* ��  0x0000*/      16,    16, {
                   0x20,0x20,0x20,0xFE,0x20,0x20,0xFE,0x20,
                   0x20,0x20,0x20,0xFE,0x20,0x20,0x20,0x00,
                   0x00,0x00,0x00,0x3F,0x20,0x20,0x27,0x22,
                   0x22,0x22,0x22,0x27,0x30,0x20,0x00,0x00,
                   }},
    {/* ��  0x0001*/      16,    16, {
                   0x00,0x00,0x00,0xFF,0x49,0x49,0x49,0xFF,
                   0xC9,0x49,0x49,0x49,0xFF,0x00,0x00,0x00,
                   0x00,0x08,0x08,0x84,0x44,0x22,0x1D,0x00,
                   0x00,0xFD,0x02,0x02,0x04,0x0C,0x04,0x00,
                   }},
};

/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration(void);
void NVIC_Configuration(void);
void SSD1303_IO_Configuration(void);
void SSD1303_Controller_Init(void);
void CCW_Rotate(unsigned char *des, const unsigned char *src);
void RTC_Configuration(void);
void Initial_Tim2(void);

/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : main
* Description    : Main program
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int main(void)
{
  SHORT width, height;
  SHORT counter;
#ifdef DEBUG
  debug();
#endif

  /* System Clocks Configuration */
  RCC_Configuration();
  GPIO_AFIODeInit();
  GPIO_DeInit(GPIOB);
  
  /* NVIC configuration */
  NVIC_Configuration();
  
  /* Initialize the SSD1303 related IO */
  SSD1303_IO_Configuration();
  
  /* Initialize the SSD1303 */
  SSD1303_Init();
  
  /* Initialize the SSD1303 controller,
     which is simulated by STM32 DMA and systick*/
  SSD1303_Controller_Init();
  
  /* Initialize the RTC peripheral */
  RTC_Configuration();
  
  Device dev;
  InitialDevice(&dev,&SSD1303_Prop,fontBuffer_fixedsys);
  
  InitGraph();
  
  Initial_Tim2();
  
  u8  buf[8];
  for(u32 i=0;i<8;i++){
    buf[i] = fontBuffer_fixedsys['a'].data[i]>>4 | fontBuffer_fixedsys['a'].data[8+i]<<4;
  }
  
  while(0){
    SetColor(WHITE);
    for(counter=0; counter<GetMaxX(); counter+=20){
      DelayMs(500);
      WAIT_UNTIL_FINISH(Line(counter,0,GetMaxX()-1-counter,GetMaxY()-1));
    }
    
    DelayMs(2000);
    
    for(counter=10; counter<GetMaxY()>>1; counter+=10){
      DelayMs(500);
      WAIT_UNTIL_FINISH(Circle(GetMaxX()>>1,GetMaxY()>>1,counter));
    }
    
    DelayMs(2000);
    WAIT_UNTIL_FINISH(FillCircle(GetMaxX()>>1,GetMaxY()>>1,10));
    
    DelayMs(2000);
    WAIT_UNTIL_FINISH(FillCircle(GetMaxX()>>1,GetMaxY()>>1,20));
    
    DelayMs(2000);
    WAIT_UNTIL_FINISH(FillCircle(GetMaxX()>>1,GetMaxY()>>1,30));
    
    DelayMs(2000);
    SetColor(BLACK);
    ClearDevice();

    SetColor(WHITE);
    WAIT_UNTIL_FINISH(Bevel((GetMaxX()>>1)-30,(GetMaxY()>>1)-30,(GetMaxX()>>1)+30,(GetMaxY()>>1)+30,15));
    
    WAIT_UNTIL_FINISH(Bevel((GetMaxX()>>1)-20,(GetMaxY()>>1)-20,(GetMaxX()>>1)+20,(GetMaxY()>>1)+20,15));
    
    WAIT_UNTIL_FINISH(Bevel((GetMaxX()>>1)-10,(GetMaxY()>>1)-10,(GetMaxX()>>1)+10,(GetMaxY()>>1)+10,15));
    
    DelayMs(2000);
    SetColor(BLACK);
    ClearDevice();
    SetColor(WHITE);
    WAIT_UNTIL_FINISH(Arc((GetMaxX()>>1)-30,(GetMaxY()>>1)-30,(GetMaxX()>>1)+30,(GetMaxY()>>1)+30,10,15,0xFF));
    
    WAIT_UNTIL_FINISH(Arc((GetMaxX()>>1)-20,(GetMaxY()>>1)-20,(GetMaxX()>>1)+20,(GetMaxY()>>1)+20,10,15,0xFF));
    
    WAIT_UNTIL_FINISH(Arc((GetMaxX()>>1)-10,(GetMaxY()>>1)-10,(GetMaxX()>>1)+10,(GetMaxY()>>1)+10,10,15,0xFF));
    
    DelayMs(2000);
    SetColor(BLACK);
    ClearDevice();
    
    SetColor(WHITE);
    
    for(counter=0; counter<GetMaxY()>>1; counter+=4){
      DelayMs(500);
      WAIT_UNTIL_FINISH(Rectangle(GetMaxX()/2-counter,
                                  GetMaxY()/2-counter,
                                  GetMaxX()/2+counter,
                                  GetMaxY()/2+counter));
    }
    
    DelayMs(2000);
    SetColor(BLACK);
    ClearDevice();
    
    
      /* Draw a box */
    for(u32 x=0;x<128;x++){
      SetPoint(&dev,x,0);
      SetPoint(&dev,x,63);
    }
    for(u32 y=0;y<63;y++){
      SetPoint(&dev,0,y);
      SetPoint(&dev,127,y);
    }
    static u32 yPos = 1;
    yPos = 0;
    while(1){
      unsigned long xPos = 10;
      yPos++;
      if(yPos == 47){
        break;
      }
      /* Cleare previous display data */
      TextOut(&dev,xPos,yPos>1?yPos-1:46,"              ",0xff);
      /* Output the English characters "Hello" */
      xPos = TextOut(&dev,xPos,yPos,"Hello ",0xFF);
      /* Output the Chinese characters "����" */
      xPos = SpecTextOut(&dev,xPos,yPos,world,2);
      /* Output the '!' sign */
      //xPos = TextOut(&dev,xPos,yPos,"!",0xFF);
      
      TextOut(&dev,xPos + 8,8, (yPos & 2) ? (yPos&1 ? "\\" : "-" ) : (yPos&1 ? "/" : "|" ),0xFF);
      SSD1303_DrawBlock(xPos,yPos,8,8,buf);
      CCW_Rotate(buf,buf);
      
      for(u32 i=2000000;--i;);
    }
    SetColor(BLACK);
    ClearDevice();
    break;
  }
  Clock_DrawFace(GetMaxY()>>1,GetMaxY()>>1,GetMaxY()>>1);
  //Line(counter,0,GetMaxX()-1-counter,GetMaxY()-1);
  while(1){
    
    if(TimeDisplay){
      CheckConnection();
      vu16 ccr1 = TIM3->CCR1;
      Pos_t x = 6;
      Pos_t y = 3;
      TimeDisplay = 0;
      u32 TimeVar = RTC_GetCounter();
      u32 THH = 0, TMM = 0, TSS = 0;
      /* Compute  hours */
      THH = TimeVar / 3600;
      /* Compute minutes */
      TMM = (TimeVar % 3600) / 60;
      /* Compute seconds */
      TSS = (TimeVar % 3600) % 60;
      char tBuf[10] = {
        THH/10 + '0',THH%10 + '0',
        ':',
        TMM/10 + '0',TMM%10 + '0',
        ':',
        TSS/10 + '0',TSS%10 + '0',
      };
      x = TextOut(&dev,x,y,tBuf,0xff);
      Clock_UpdateTime(THH,TMM,TSS);
    }
  }
}

/*******************************************************************************
* Function Name  : CCW_Rotate
* Description    : Counter Clock Wise rotate the 8*8 bit map.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CCW_Rotate(unsigned char *des, const unsigned char *src)
{
  unsigned long x,y,t;
  x = (src[0] << 24) | (src[1] << 16) | (src[2] << 8) | src[3];
  y = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
  
  t = (x & 0xf0f0f0f0) | ((y >> 4) & 0x0f0f0f0f);
  y = ((x << 4) & 0xf0f0f0f0) | (y & 0x0f0f0f0f);
  x = t; 

  t = (x ^ (x >> 14)) & 0x0000cccc;
  x = x ^ t ^ (t << 14);
  t = (y ^ (y >> 14)) & 0x0000cccc;
  y = y ^ t ^ (t << 14);

  t = (x ^ (x >> 7)) & 0x00aa00aa;
  x = x ^ t ^ (t << 7);
  t = (y ^ (y >> 7)) & 0x00aa00aa;
  y = y ^ t ^ (t << 7);

  des[7] = x >> 24; des[6] = x >> 16; des[5] = x >> 8; des[4] = x;
  des[3] = y >> 24; des[2] = y >> 16; des[1] = y >> 8; des[0] = y; 
}

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configure the nested vectored interrupt controller.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Configuration(void)
{
#ifdef  VECT_TAB_RAM  
  /* Set the Vector Table base location at 0x20000000 */ 
  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0); 
#else  /* VECT_TAB_FLASH  */
  /* Set the Vector Table base location at 0x08000000 */ 
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   
#endif
  /* 2 bits for pre-emption priority */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
}

/*******************************************************************************
* Function Name  : SSD1303_IO_Configuration
* Description    : Configure the IO used for SSD1303.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SSD1303_IO_Configuration(void)
{ 
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  
  /* Enable SPI1 and GPIO clocks */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  
  SPI_I2S_DeInit(SPI2);
  
  /* Configure SPI2 pins: SCK, MOSI */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  /* Configure SSD1303 pins: RES,A0*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* SPI1 configuration */
  SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  //SPI_Init(SPI1, &SPI_InitStructure);
  SPI_Init(SPI2, &SPI_InitStructure);
  
  SPI_I2S_DMACmd(SPI2, SPI_I2S_DMAReq_Tx, ENABLE);

  /* Enable SPI1  */
  SPI_Cmd(SPI2, ENABLE);
}

/*******************************************************************************
* Function Name  : SSD1303_Controller_Init
* Description    : Initialize the oled controller, which is simulated by STM32.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void  SSD1303_Controller_Init(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  DMA_InitTypeDef  DMA_InitStructure;
  
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  
  DMA_DeInit(DMA1_Channel5);
  DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&SPI2->DR);
  DMA_InitStructure.DMA_MemoryBaseAddr = 0;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 1;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel5, &DMA_InitStructure);
  
  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel5_IRQChannel;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  DMA_ITConfig(DMA1_Channel5, DMA_IT_TC, ENABLE);
  
  SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
  SysTick_SetReload(72000000/SSD1303_FPS);
  SysTick_ITConfig(ENABLE);
  SysTick_CounterCmd(SysTick_Counter_Enable);
}

/*******************************************************************************
* Function Name  : RTC_Configuration
* Description    : Initialize the RTC peripheral.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RTC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* Enable PWR and BKP clocks */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
  
  /* Allow access to BKP Domain */
  PWR_BackupAccessCmd(ENABLE);
  
  /* Reset Backup Domain */
  BKP_DeInit();
  
#ifdef RTCClockSource_LSI
  /* Enable LSI */ 
  RCC_LSICmd(ENABLE);
  /* Wait till LSI is ready */
  while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET)
  {
  }

  /* Select LSI as RTC Clock Source */
  RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);  
#elif defined	RTCClockSource_LSE  
  /* Enable LSE */
  RCC_LSEConfig(RCC_LSE_ON);
  /* Wait till LSE is ready */
  while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
  {
  }

  /* Select LSE as RTC Clock Source */
  RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);  
#endif
  
  NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQChannel;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  /* Enable RTC Clock */
  RCC_RTCCLKCmd(ENABLE);
  /* Wait for RTC registers synchronization */
  RTC_WaitForSynchro();

  /* Wait until last write operation on RTC registers has finished */
  RTC_WaitForLastTask();
  
  /* Enable the RTC Second */  
  RTC_ITConfig(RTC_IT_SEC, ENABLE);

  /* Wait until last write operation on RTC registers has finished */
  RTC_WaitForLastTask();
  
  /* Set RTC prescaler: set RTC period to 1sec */
#ifdef RTCClockSource_LSI
  RTC_SetPrescaler(31999); /* RTC period = RTCCLK/RTC_PR = (32.000 KHz)/(31999+1) */
#elif defined	RTCClockSource_LSE
  RTC_SetPrescaler(32767); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */
#endif
  
  /* Wait until last write operation on RTC registers has finished */
  RTC_WaitForLastTask();
}

/*******************************************************************************
* Function Name  : RTC_IRQHandler
* Description    : This function handles RTC global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RTC_IRQHandler(void)
{
  if (RTC_GetITStatus(RTC_IT_SEC) != RESET)
  {
    /* Clear the RTC Second interrupt */
    RTC_ClearITPendingBit(RTC_IT_SEC);

    /* Toggle GPIO_LED pin 6 each 1s */
    //GPIO_WriteBit(GPIOF, GPIO_Pin_6, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_6)));

    /* Enable time update */
    TimeDisplay = 1;

    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
    /* Reset RTC Counter when Time is 23:59:59 */
    if (RTC_GetCounter() == 0x00015180)
    {
      RTC_SetCounter(0x0);
      /* Wait until last write operation on RTC registers has finished */
      RTC_WaitForLastTask();
    }
  }
}

#ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
