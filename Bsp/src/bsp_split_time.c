#include "bsp.h"

static void TFT_Donnot_Set_Timer_Time(void);

void TimeTimer_Pro_Handler(void)
{
 
  
  switch(pro_t.timer_mode_flag){


   case works_time://0

		if(gctl_t.gTimer_ctl_disp_works_time_second > 59 ){
			TFT_Display_WorksTime();
		}

		TFT_Donnot_Set_Timer_Time();

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

			}
			TFT_Disp_Set_TimerTime(0);
			}
		
		TFT_DonnotDisp_Works_Time();

		
	break;

	

	 case timer_set_time://02

	 	if(pro_t.gTimer_pro_mode_long_key > 3 ){
            	  
		
			if(gctl_t.gSet_timer_hours >0 ){
       
				pro_t.timer_mode_flag = timer_time;
				pro_t.mode_key_run_item_step =0xff;
				gctl_t.gTimer_ctl_set_timer_time_senconds =0;
			
				gctl_t.gSet_timer_minutes =0;
				TFT_Disp_Onley_Set_TimerTime_Value();
				
			}
			else{
				
		
				pro_t.mode_key_run_item_step =0xff;
				pro_t.timer_mode_flag = works_time;//pro_t.timer_mode_flag
				TFT_Display_WorksTime();



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
static void TFT_Donnot_Set_Timer_Time(void)
{
    if(pro_t.timer_mode_flag == timer_time ){

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
