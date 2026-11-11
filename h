#include <kipr/wombat.h>
void servomove();

//DECLARE VARIABLES
int servoport=1;
int bport=5;
int red=2;
int value=10;
int servoposition=69; 

int main()
{
    	camera_open_black(); 
    	camera_update(); 
    	msleep(200); 
    	while(digital(bport)==0)
        {
            enable_servos();
            camera_update();
            if(get_object_count(red) >=4)
            {
                 value=get_object_center_x(red,0);
            	 servoposition=(-0.746 * value)+1168;
           		 servomove();
               	 
            }
            else
            {
                ao(); 
            }
           	
        }
    	disable_servos(); 
    	camera_close();
        return 0;
}

void servomove()
{
    
    set_servo_position(servoport, servoposition);
    msleep(100);
    
    
}
