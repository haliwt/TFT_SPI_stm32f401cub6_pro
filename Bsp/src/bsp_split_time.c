#include "bsp.h"

//static void TFT_Donnot_Set_Timer_Time(void);

void TimeTimer_Pro_Handler(void)
{
 
  
  switch(pro_t.timer_mode_item){


   case works_time://1

		if(gctl_t.gTimer_ctl_disp_works_time_second > 59 ){
			TFT_Display_WorksTime();
		}

		//TFT_Donnot_Set_Timer_Time();

	break;

	case timer_time: //01 ->timer_time 
		if(gctl_t.gTimer_ctl_set_timer_time_senconds >59 ){

		
			gctl_t.gTimer_ctl_set_timer_time_senconds =0;

			gctl_t.gSet_timer_minutes --;

			if(gctl_t.gSet_timer_minutes <0){
			gctl_t.gSet_timer_minutes =59;
			gctl_t.gSet_timer_hours --;
			}

			
			if(gctl_t.gSet_timer_hours < 0){

			pro_t.gPower_On = power_off;
			pro_t.power_off_flag=1;
			pro_t.run_process_step=0xff;
			 TFT_BACKLIGHT_OFF();
				LED_Mode_Key_Off();
			    LED_Power_Key_Off();

			}
			TFT_Disp_Set_TimerTime(0);
		}
		
		TFT_DonnotDisp_Works_Time();

		
	break;

	

	 case timer_set_time://02

		if(pro_t.gTimer_pro_mode_long_key > 2){
            pro_t.gTimer_pro_mode_long_key =0;  
			gctl_t.mode_longk_key_flag =0;  
		
			if(gctl_t.gSet_timer_hours >0 ){
           
				pro_t.timer_mode_item = timer_time;
				pro_t.mode_key_run_item_step =0xff;
				gctl_t.gTimer_ctl_set_timer_time_senconds =0;
			
				gctl_t.gSet_timer_minutes =0;
				//TFT_Disp_Chinese_Timer_96_24(100,150);
				 TFT_Disp_Chinese_Timer_23_23(TIMER_X0,TIMER_Y,0);
				   TFT_Disp_Chinese_Timer_23_23(TIMER_X1,TIMER_Y,1);
				   TFT_Disp_Chinese_Timer_23_23(TIMER_X2,TIMER_Y,2);
				   TFT_Disp_Chinese_Timer_23_23(TIMER_X3,TIMER_Y,3);
				    TFT_Only_Disp_Set_Timer_Blink();
					HAL_Delay(100);
					TFT_Disp_Onley_Set_TimerTime_Value();
					
					
			}
			else{
				
		  
				if(wifi_link_net_state()==1 && gctl_t.beijing_time_flag==1){
					pro_t.mode_key_run_item_step =0xff;
					pro_t.timer_mode_item = works_time;//pro_t.timer_mode_item
					TFT_Disp_Chinese_BeiJing_Time_23_23(TIMER_X0,TIMER_Y,0);
					TFT_Disp_Chinese_BeiJing_Time_23_23(TIMER_X1,TIMER_Y,1);
					TFT_Disp_Chinese_BeiJing_Time_23_23(TIMER_X2,TIMER_Y,2);
					TFT_Disp_Chinese_BeiJing_Time_23_23(TIMER_X3,TIMER_Y,3);
					TFT_Display_WorksTime();

				}
				else{

					pro_t.mode_key_run_item_step =0xff;
					pro_t.timer_mode_item = works_time;//pro_t.timer_mode_item
					//TFT_Disp_Chinese_WorksTime_96_24(100,150);
					TFT_Disp_Chinese_WorkTime_23_23(TIMER_X0,TIMER_Y,0);
					TFT_Disp_Chinese_WorkTime_23_23(TIMER_X1,TIMER_Y,1);
					TFT_Disp_Chinese_WorkTime_23_23(TIMER_X2,TIMER_Y,2);
					TFT_Disp_Chinese_WorkTime_23_23(TIMER_X3,TIMER_Y,3);
					TFT_Display_WorksTime();


				}



			}
			
		
			pro_t.mode_key_select_label =0;
               
		}
	


	  break;
	}



}


/**********************************************************************************************************
    **
    *Function Name:TFT_Donnot_Set_Timer_Time();
    *Function : 记录设置的定时时间，
    *Input Ref:
    *Return Ref:NO
    *
*********************************************************************************************************/
#if 0
static void TFT_Donnot_Set_Timer_Time(void)
{
    if(pro_t.timer_mode_item == timer_time ){

	if(gctl_t.gTimer_ctl_set_timer_time_senconds >59){
		gctl_t.gTimer_ctl_set_timer_time_senconds =0;

		gctl_t.gSet_timer_minutes --;

		if(gctl_t.gSet_timer_minutes <0){
		gctl_t.gSet_timer_minutes =59;
		gctl_t.gSet_timer_hours --;


		}
		if(gctl_t.gSet_timer_hours < 0){

			pro_t.gPower_On = power_off;

		}

	}

   }

}
#endif
