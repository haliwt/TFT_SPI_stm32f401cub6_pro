
#include "bsp.h"

#define HORIZON   1

//#define LCD_TOTAL_BUF_SIZE (240*320*2)
//#define LCD_Buf_Size 1152

uint8_t spi_tx_buffer[1];


static uint8_t SPI_WriteByte(uint8_t *txdata,uint16_t size);






uint8_t spi_it_tx[1];



/*******************************************************************************
 * 
 * Function Name: uint8_t SPI_WriteByte(uint8_t *txdata,uint16_t size)
 * Function : to write data to TFT register
 * Input Ref: need write data, data of length
 * Return Ref: 0--success 1 - fail
 * 
***********************************************************************************/
static uint8_t SPI_WriteByte(uint8_t *txdata,uint16_t size)
{
    

	//HAL_SPI_Receive_DMA

		// __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_TE);
		// __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_NO_XFER);
		// __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_TIMEOUT);
		// __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_PARAM);
		// __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_BUSY);
		// __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_NOT_SUPPORTED);
		// __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_SYNC);
		// __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_REQGEN);
  

//if (__HAL_DMA_GET_FLAG(&hspi1,DMA_FLAG_TE1) || __HAL_DMA_GET_FLAG(&hspi1,DMA_FLAG_TE2) )
//{
//   __HAL_DMA_CLEAR_FLAG(&hspi1, HAL_DMA_ERROR_TE);
//   __HAL_DMA_CLEAR_FLAG(&hspi1, DMA_FLAG_TE1);
//   __HAL_DMA_CLEAR_FLAG(&hspi1, DMA_FLAG_TE2);
//    __HAL_DMA_CLEAR_FLAG(&hspi1, DMA_FLAG_TC1);
//    __HAL_DMA_CLEAR_FLAG(&hspi1, DMA_FLAG_TC2);
//	__HAL_DMA_CLEAR_FLAG(&hspi1, DMA_FLAG_GI1 );
//	__HAL_DMA_CLEAR_FLAG(&hspi1, DMA_FLAG_HT1);
//    __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_TE);
//    __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_TIMEOUT);
//    __HAL_DMA_CLEAR_FLAG(DMA1, HAL_DMA_ERROR_NO_XFER);
//   
//}
	
	return HAL_SPI_Transmit_DMA(&hspi1,txdata,1);
	//return HAL_SPI_Transmit(&hspi1,txdata,1,0xffff);
	

}
void LCD_GPIO_Reset(void)
{


	LCD_RST_SetLow();
    HAL_Delay(100);
    LCD_RST_SetHigh();
	HAL_Delay(100);

}
/*******************************************************************************
 * 
 * Function Name: static void LCD_Write_Cmd(uint8_t cmd)
 * Function : to write data to TFT register
 * Input Ref: write data 
 * Return Ref: NO
 * 
***********************************************************************************/
void LCD_Write_Cmd(uint8_t cmd)
{
   LCD_NSS_SetHigh();
	LCD_NSS_SetLow();
    TFT_DCX_CMD();
    pro_t.spi_error_flag=SPI_WriteByte(&cmd,1);

}

void LCD_Write_Data(uint8_t data)
{
    LCD_NSS_SetHigh(); //To write data to TFT is high level
    LCD_NSS_SetLow();
	TFT_DCX_DATA();
    SPI_WriteByte(&data,1);
}

void LCD_Write_16bit_Data(uint16_t data)
{

    LCD_Write_Data(data >> 8);
    LCD_Write_Data(data);
    

}

/*******************************************************************************
 * 
 * Function Name: void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
 * Function : turn on TFT LCD back light
 * Input Ref: from x to y of point (x1,y1) to (x2,y2)
 * Return Ref: NO
 * 
***********************************************************************************/
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{

   if(HORIZON ==1){
     /* 指定X方向操作区域 */
	   LCD_Write_Cmd(0x2a); //display column
	   LCD_Write_Data(x1 >> 8);
	   LCD_Write_Data(x1);
	   LCD_Write_Data(x2 >> 8);
	   LCD_Write_Data(x2);
   
	   /* 指定Y方向操作区域 */
	   LCD_Write_Cmd(0x2b); //display row 
	   LCD_Write_Data(y1 >> 8);
	   LCD_Write_Data(y1);
	   LCD_Write_Data(y2 >> 8);
	   LCD_Write_Data(y2);
   
	   /* 发送该命令，LCD开始等待接收显存数据 */
	   LCD_Write_Cmd(0x2C);



   }
   else{
	/* 指定X方向操作区域 */
    LCD_Write_Cmd(0x2a); //display column
    LCD_Write_Data(x1 >> 8);
    LCD_Write_Data(x1);
    LCD_Write_Data(x2 >> 8);
    LCD_Write_Data(x2);

    /* 指定Y方向操作区域 */
    LCD_Write_Cmd(0x2b); //display row 
    LCD_Write_Data(y1 >> 8);
    LCD_Write_Data(y1);
    LCD_Write_Data(y2 >> 8);
    LCD_Write_Data(y2);

    /* 发送该命令，LCD开始等待接收显存数据 */
    LCD_Write_Cmd(0x2C);
   }

}

/*******************************************************************************
 * 
 * Function Name: static void LCD_Clear(uint16_t color)
 * Function : display TFT color
 * Input Ref: NO
 * Return Ref: NO
 * 
********************************************************************************/
void LCD_Clear(uint16_t color)
{

	uint16_t i, j;
    if(HORIZON == 0){
		LCD_Write_Cmd(0x2A);
		LCD_Write_Data(0);
		LCD_Write_Data(0);
		LCD_Write_Data(0);
		LCD_Write_Data(240);
		
		LCD_Write_Cmd(0X2B);
		LCD_Write_Data(0);
		LCD_Write_Data(0);
		LCD_Write_Data(0X01);
		LCD_Write_Data(0X40);
	
		LCD_Write_Cmd(0X2C);
	
		for (i = 0; i < 240; i++)
		{
			for (j = 0; j < 320; j++)
			{
				LCD_Write_Data(color >> 8);
				LCD_Write_Data(color);
			}
		}
		//lcd_display_on(); /* 开LCD显示 */
	   }
	   else{
           LCD_Write_Cmd(0x2A);
		   LCD_Write_Data(0);
		   LCD_Write_Data(0);
		   LCD_Write_Data(0x01);
		   LCD_Write_Data(0x3f); //320
		   
		   LCD_Write_Cmd(0X2B);
		   LCD_Write_Data(0);
		   LCD_Write_Data(0);
		   LCD_Write_Data(0);
		   LCD_Write_Data(0Xef); //240
	   
		   LCD_Write_Cmd(0X2C);
	   
		   for (i = 0; i < 320; i++)
		   {
			   for (j = 0; j < 240; j++)
			   {
				   LCD_Write_Data(color >> 8);
				   LCD_Write_Data(color);
			   }
		   }

		}

}



/*******************************************************************************
 * 
 * Function Name: void DISP_WINDOWS(void)
 * Function : display TFT color
 * Input Ref: NO
 * Return Ref: NO
 * 
********************************************************************************/
void DISP_WINDOWS(void)
{

         if(HORIZON ==1){
		   LCD_Write_Cmd(0x2A);
		   LCD_Write_Data(0);
		   LCD_Write_Data(0);
		   LCD_Write_Data(0x01);
		   LCD_Write_Data(0x3f); //320
		   
		   LCD_Write_Cmd(0X2B);
		   LCD_Write_Data(0);
		   LCD_Write_Data(0);
		   LCD_Write_Data(0);
		   LCD_Write_Data(0Xef); //240
	   
		   LCD_Write_Cmd(0X2C);
         }
		 else{
          
		 LCD_Write_Cmd(0x2A);
         LCD_Write_Data(0x00);
         LCD_Write_Data(0x00);
         LCD_Write_Data(0x00);
         LCD_Write_Data(0xEF);

         LCD_Write_Cmd(0x2B);
         LCD_Write_Data(0x00);
         LCD_Write_Data(0x00);
         LCD_Write_Data(0x01);
         LCD_Write_Data(0x3f);
         LCD_Write_Cmd(0x2C);
			 
		
        }
}


/*******************************************************************************
 * 
 * Function Name: static void LCD_Clear(uint16_t color)
 * Function : display TFT color
 * Input Ref: NO
 * Return Ref: NO
 * 
***********************************************************************************/
void TFT_LCD_Init(void)
{
    /* 关闭睡眠模式 */
	LCD_GPIO_Reset();

	//TFT_BACKLIGHT_ON();
    LCD_Write_Cmd(0x11);
	HAL_Delay(120);
    
    /* 开始设置显存扫描模式，数据格式等 */
	
    LCD_Write_Cmd(0x36);//修改此处，可以改变屏幕的显示方向，横屏，竖屏等
    //LCD_Write_Data(0x00);  //竖屏
  //  LCD_Write_Data(0x60); //横屏
    LCD_Write_Data(0xA0); //横屏

 
    LCD_Write_Cmd(0xa0);
    /* RGB 5-6-5-bit格式  */
    LCD_Write_Cmd(0x3A);
    LCD_Write_Data(0x65);
    /* porch 设置 */
    LCD_Write_Cmd(0xB2);
    LCD_Write_Data(0x0C);//< Back porch in normal mode
    LCD_Write_Data(0x0C);//< Front porch in normal mode
    LCD_Write_Data(0x00);//< Disable separate porch control
    LCD_Write_Data(0x33);//< Back and front porch in idle mode
    LCD_Write_Data(0x33);//< Back and front porch in partial mode
    /* VGH设置 */
    LCD_Write_Cmd(0xB7);
    LCD_Write_Data(0x72);
    /* VCOM 设置 */
    LCD_Write_Cmd(0xBB);
    LCD_Write_Data(0x3D);
    /* LCM 设置 */
    LCD_Write_Cmd(0xC0);
    LCD_Write_Data(0x2C);
    /* VDV and VRH 设置 */
    LCD_Write_Cmd(0xC2);
    LCD_Write_Data(0x01);
    /* VRH 设置 */
    LCD_Write_Cmd(0xC3);
    LCD_Write_Data(0x19);
    /* VDV 设置 */
    LCD_Write_Cmd(0xC4);
    LCD_Write_Data(0x20);
    /* 普通模式下显存速率设置 60Mhz */
    LCD_Write_Cmd(0xC6);
    LCD_Write_Data(0x0F);
    /* 电源控制 */
    LCD_Write_Cmd(0xD0);
    LCD_Write_Data(0xA4);
    LCD_Write_Data(0xA1);
    /* 电压设置 */
    LCD_Write_Cmd(0xE0);
    LCD_Write_Data(0xD0);
    LCD_Write_Data(0x04);
    LCD_Write_Data(0x0D);
    LCD_Write_Data(0x11);
    LCD_Write_Data(0x13);
    LCD_Write_Data(0x2B);
    LCD_Write_Data(0x3F);
    LCD_Write_Data(0x54);
    LCD_Write_Data(0x4C);
    LCD_Write_Data(0x18);
    LCD_Write_Data(0x0D);
    LCD_Write_Data(0x0B);
    LCD_Write_Data(0x1F);
    LCD_Write_Data(0x23);
    /* 电压设置 */
    LCD_Write_Cmd(0xE1);
    LCD_Write_Data(0xD0);
    LCD_Write_Data(0x04);
    LCD_Write_Data(0x0C);
    LCD_Write_Data(0x11);
    LCD_Write_Data(0x13);
    LCD_Write_Data(0x2C);
    LCD_Write_Data(0x3F);
    LCD_Write_Data(0x44);
    LCD_Write_Data(0x51);
    LCD_Write_Data(0x2F);
    LCD_Write_Data(0x1F);
    LCD_Write_Data(0x1F);
    LCD_Write_Data(0x20);
    LCD_Write_Data(0x23);


	 LCD_Write_Cmd(0x2A);
     LCD_Write_Data(0x00);
     LCD_Write_Data(0x00);
     LCD_Write_Data(0x01);
     LCD_Write_Data(0x3f);

     LCD_Write_Cmd(0x2B);
     LCD_Write_Data(0x00);
     LCD_Write_Data(0x00);
     LCD_Write_Data(0x00);
     LCD_Write_Data(0xef);


	
    /* 显示开 */
	//LCD_Write_Cmd(0x21); // Display Inversion On
	LCD_Write_Cmd(0x20); // Display Inversion Off
    LCD_Write_Cmd(0x29); // display on 
    //LCD_Write_Cmd(0x28);  // display off ---WT.EDIT  

    /* 设置背景色 */
    LCD_Clear(BLACK);
	

    /*打开显示*/
 
}





