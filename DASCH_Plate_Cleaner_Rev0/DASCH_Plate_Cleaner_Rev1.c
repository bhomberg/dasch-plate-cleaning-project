#include <pololu/orangutan>
#include <i2cmaster.h>
#include <stdlib.h> 



#define I2C1  0x40     // device address of First PCA9555 chip (Motors)
#define I2C2  0x42     // device address of Second PCA9555 chip (Outputs)
#define I2C3  0x44	   // device address of Third PCA9555 chip (Inputs)




void * operator new(size_t size); 
void operator delete(void * ptr); 

void * operator new(size_t size) 
{ 
  return malloc(size); 
} 

void operator delete(void * ptr) 
{ 
  free(ptr); 
} 

__extension__ typedef int __guard __attribute__((mode (__DI__))); 

extern "C" int __cxa_guard_acquire(__guard *); 
extern "C" void __cxa_guard_release (__guard *); 
extern "C" void __cxa_guard_abort (__guard *); 

int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);}; 
void __cxa_guard_release (__guard *g) {*(char *)g = 1;}; 
void __cxa_guard_abort (__guard *) {}; 

extern "C" void __cxa_pure_virtual(void); 
void __cxa_pure_virtual(void) {}; 

union u_motorByte0_tag{
	struct {
		unsigned int m1Step : 1;
		unsigned int m1Dir : 1;
		unsigned int m1Drop : 1;
		unsigned int m2Step : 1;
		unsigned int m2Dir : 1;
		unsigned int m2Drop : 1;
		unsigned int m3Step : 1;
		unsigned int m3Dir : 1;
	} bits_in_motorByte0;
	char motorByte0;
} u_motorByte0;


union u_motorByte1_tag{
	struct {
		unsigned int m3Drop : 1;
		unsigned int m4Step : 1;
		unsigned int m4Dir : 1;
		unsigned int m4Drop : 1;
		unsigned int m5Step : 1;
		unsigned int m5Dir : 1;
		unsigned int m5Drop : 1;
		unsigned int mNull17 : 1;
	} bits_in_motorByte1;
	char motorByte1;
} u_motorByte1;

union u_outputByte0_tag{
	struct {
		unsigned int ACPower : 1;
		unsigned int blowerPulse : 1;
		unsigned int plateStop : 1;
		unsigned int raiseFixture : 1;
		unsigned int lowerFixture : 1;
		unsigned int brush1Raise : 1;
		unsigned int brush1Lower : 1;
		unsigned int brush2Raise : 1;
	} bits_in_outputByte0;
	char outputByte0;
} u_outputByte0;


union u_outputByte1_tag{
	struct {
		unsigned int brush2Lower : 1;
		unsigned int ptRaise : 1;
		unsigned int ptLower : 1;
		unsigned int airKnife : 1;
		unsigned int oNull14 : 1;
		unsigned int oNull15 : 1;
		unsigned int oNull16 : 1;
		unsigned int oNull17 : 1;
	} bits_in_outputByte1;
	char outputByte1;
} u_outputByte1;

union u_inputByte0_tag{
	struct {
		unsigned int plate : 1;
		unsigned int fixtureLift : 1;
		unsigned int fixtureHome : 1;
		unsigned int fixturePlate : 1;
		unsigned int fixtureBrush1 : 1;
		unsigned int fixtureBrush2 : 1;
		unsigned int fixtureDry1 : 1;
		unsigned int fixtureDry2 : 1;
	} bits_in_inputByte0;
	char inputByte0;
} u_inputByte0;


union u_inputByte1_tag{
	struct {
		unsigned int iNull10 : 1;
		unsigned int iNull11 : 1;
		unsigned int iNull12 : 1;
		unsigned int iNull13 : 1;
		unsigned int iNull14 : 1;
		unsigned int iNull15 : 1;
		unsigned int iNull16 : 1;
		unsigned int iNull17 : 1;
	} bits_in_inputByte1;
	char inputByte1;
} u_inputByte1;
  
int main()   
{
    
    unsigned char ret1, ret2, ret3;
	int steplength1 = 1, steplength2 = 1, steplength3 = 1, steplength4 = 1, steplength5 = 1;
	int totallength1 = 2, totallength2 = 2;
	int totallength3 = 2, totallength4 = 2, totallength5 = 2;
	int m2HalfPlate = 100, m2WholePlate = 100, m1LoadPlate = 100, m2HomeFix = 100;
	int m2Brush1Step = 100, m2Brush2Step = 100, m2Dry1Step = 100, m2Dry2Step = 100;
	int m2LoadBack = 100,
    
	u_motorByte0.motorByte0 = 0;  // initialize motorByte0
	u_motorByte1.motorByte1 = 0;  // initialize motorByte1
	u_outputByte0.outputByte0 = 255;  // initialize outputByte0
	u_outputByte1.outputByte1 = 255;  // initialize outputByte1
	u_inputByte0.inputByte0 = 0;  // initialize inputByte0
	u_inputByte1.inputByte1 = 0;  // initialize inputByte1
	
	OrangutanLCD::clear();
	OrangutanLCD::print("BEGIN ");
	
	delay_ms(1000);

    i2c_init();                                // init I2C interface
	
    OrangutanLCD::print("INIT ");
	
    ret1 = i2c_start(I2C1+I2C_WRITE);       // set device address and write mode
	i2c_stop();
	ret2 = i2c_start(I2C2+I2C_WRITE);
	i2c_stop();
	ret3 = i2c_start(I2C3+I2C_WRITE);
	i2c_stop();
    
	OrangutanLCD::clear();
	OrangutanLCD::print("START ");
	
	if ( ret1 | ret2 | ret3 ) {
        /* failed to issue start condition, possibly no device found */
        
		OrangutanLCD::print("NAK ");
		i2c_stop();
		OrangutanLCD::print("STOP ");
    }
	else {
		OrangutanLCD::print("ACK ");
        /* issuing start condition ok, device accessible */
		OrangutanLCD::print("BINIT ");
		i2c_start(I2C1+I2C_WRITE);
		i2c_write(0x6);
		i2c_write(0x0);
		i2c_write(0x0);
		i2c_stop();
		
		i2c_start(I2C2+I2C_WRITE);
		i2c_write(0x6);
		i2c_write(0x0);
		i2c_write(0x0);
		i2c_stop();

		//u_motorByte0.bits_in_motorByte0.m1Drop = 1;
		u_motorByte0.bits_in_motorByte0.m2Drop = 1;
		/*u_motorByte1.bits_in_motorByte1.m3Drop = 1;
		u_motorByte1.bits_in_motorByte1.m4Drop = 1;
		u_motorByte1.bits_in_motorByte1.m5Drop = 1;*/

		delay_ms(1000);
		OrangutanLCD::clear();
		
		int m1 = 0, m2 = 0, m3 = 0, m4 = 0, m5 = 0;
		int state = 0;		
		int counter = 0;
		int print0 = 1, print6 = 1, print15 = 1, print24 = 1, print28 = 1, print35 = 1;
		int counterRef = 0, counterRef14 = 0, counterRef26 = 0, counterRefFive = 0, counterRef30 = 0;
		int pWait = 100, mWait = 100, kWait = 100;

		while(state != -1)
		{
			i2c_start(I2C3+I2C_WRITE);						// first start condition (write)
			i2c_write(0x0);								// write command byte
			i2c_start(I2C3+I2C_READ);						// second start condition (read)
			u_inputByte0.inputByte0 = i2c_readAck();				// read first byte and send Ack, requesting more
        	u_inputByte1.inputByte1 = i2c_readNak();				// read second byte and send stop condition
        	i2c_stop();								// set stop conditon = release bus 

			//state conversions

			if(state == 0 && counter > 5000/*&&  button pressed */){
				state = 1;
				counterRef = counter;
			}
			if(state == 1 && counter - counterRef > totallength1*m1LoadPlate/*&& u_inputByte0.bits_in_inputByte0.plate == 0*/){
				state = 2;
				counterRef = counter;
			}
			if(state == 2 && counter - counterRef > pWait){
				state = 3;
				counterRef = counter;
			}
			if(state == 3 && counter - counterRef > totallength2*m2HomeFix /*&& u_inputByte0.bits_in_inputByte0.fixtureLift == 0*/){
				state = 4;
				counterRef = counter;
			}
			if(state == 4 && counter - counterRef > 1000 /*&& u_inputByte0.bits_in_inputByte0.fixturePlate == 0*/){
				state = 5;
				counterRef = counter;
			}
			if(state == 5 && counter - counterRef > pWait){
				state = 6;
				counterRef = counter;
			}
			if(state == 6 && counter - counterRef > totallength2*m2Brush1Step /*&& u_inputByte0.bits_in_inputByte0.fixtureBrush1 == 0*/){
				state = 7;
				counterRef = counter;
			}
			if(state == 7 && counter - counterRef > mWait){
				state = 8;
				counterRef = counter;
			}
			if(state == 8 && counter - counterRef > pWait){
				state = 9;
				counterRef = counter;
			}
			if(state == 9 && counter - counterRef > totallength2*m2HalfPlate){
				state = 10;
				counterRef = counter;
			}
			if(state == 10 && counter - counterRef > pWait){
				state = 11;
			}
			if(state == 11 && counter - counterRef > totallength2*m2HalfPlate /*&& u_inputByte0.bits_in_inputByte0.fixtureBrush1 == 0*/){
				state = 12;
				counterRef = counter;
			}
			if(state == 12 && counter - counterRef > pWait){
				state = 13;
				counterRef = counter;
			}
			if(state == 13 && counter - counterRef > totallength2*m2HalfPlate){
				state = 14;
				counterRef14 = counter;
			}
			if(state == 14 && counter - counterRef > totallength2*m2Brush2Step /*&& u_inputByte0.bits_in_inputByte0.fixtureBrush2*/){
				state = 15;
				counterRef = counter;
			}
			if(state == 15 && counter - counterRef > mWait){
				state = 16;
				counterRef = counter;
			}
			if(state == 16 && counter - counterRef > pWait){
				state = 17;
				counterRef = counter;
			}
			if(state == 17 && counter - counterRef > totallength2*m2HalfPlate){
				state = 18;
				counterRef = counter;
			}
			if(state == 18 && counter - counterRef > pWait){
				state = 19;
				counterRef = counter;
			}
			if(state == 19 && counter - counterRef > totallength2*m2HalfPlate /*&& u_inputByte0.bits_in_inputByte0.fixtureBrush2 == 0*/){
				state = 20;
				counterRef = counter;
			}
			if(state == 20 && counter - counterRef > pWait){
				state = 21;
				counterRef = counter;
			}
			if(state == 21 && counter - counterRef > totallength2*m2HalfPlate){
				state = 22;
				counterRef = counter;
			}
			if(state == 22 && counter - counterRef > pWait){
				state = 23;
				counterRef = counter;
			}
			if(state == 23 && counter - counterRef > totallength2*m2Dry1Step /*&& u_inputByte0.bits_in_inputByte0.fixtureDry1 == 0*/){
				state = 24;
				counterRef = counter;
			}
			if(state == 24 && counter - counterRef > kWait){
				state = 25;
				counterRef = counter;
			}
			if(state == 25 && counter - counterRef > totallength2*m2WholePlate){
				state = 26;
				counterRef26 = counter;
			}
			if(state == 26 && counter - counterRef > totallength2*m2Dry2Step /*&& u_inputByte0.bits_in_inputByte0.fixtureDry2 == 0*/){
				state = 27;
				counterRefFive = counter;
			}
			if(state == 27 && counter - counterRefFive > mWait){
				state = 28;
				counterRef = counter;
			}
			if(state == 28 && counter - counterRef > pWait){
				state = 29;
				counterRef = counter;
			}
			if(state == 29 && counter - counterRef > totallength2*m2WholePlate){
				state = 30;
				counterRef30 = counter;
			}
			if(state == 30 && counter - counterRef > totallength2*m2LoadBack /*&& u_inputByte0.bits_in_inputByte0.fixturePlate == 0*/){
				state = 31;
				counterRef = counter;
			}
			if(state == 31 &&  counter - counterRef > 1000 /*&& u_inputByte0.bits_in_inputByte0.fixtureLift == 0*/){
				state = 32;
				counterRef = counter;
			}
			if(state == 32 && counter - counterRef > totallength2*m2HomeFix /*&& u_inputByte0.bits_in_inputByte0.fixtureHome == 0*/){
				state = 33;
				counterRef = counter;
			}
			if(state == 33 && counter - counterRef > pWait){
				state = 34;
				counterRef = counter;
			}
			if(state == 34 && counter - counterRef > totallength1*m1LoadPlate){
				state = 35;
				counterRef = counter;
			}
			if(state == 35 && counter - counterRef > 10){
				state = -1;
			}


			//state actions
						
			if(state == 0){
				if(u_inputByte0.bits_in_inputByte0.fixtureHome == 1){
					u_motorByte0.bits_in_motorByte0.m2Dir = 0;  //********* 0 is used as fixture backward ?cc?, 1 as forward ?c? **********
					m2 = 1;
				}
				else{
					u_motorByte0.bits_in_motorByte0.m2Drop = 0;
					m2 = 0;
					u_outputByte0.bits_in_outputByte0.lowerFixture = 0;
					if(print0 == 1){
						OrangutanLCD::clear();
						OrangutanLCD::print("PUSH TO START");
						print0 = 0;
					}
				}
			}
			if(state == 1){
				OrangutanLCD::clear();
				u_outputByte0.bits_in_outputByte0.ACPower = 0;
				if((counter % 200) < 100){
					u_outputByte0.bits_in_outputByte0.blowerPulse = 0;
				}
				else{
					u_outputByte0.bits_in_outputByte0.blowerPulse = 1;
				}
				m1 = 1;
				u_motorByte0.bits_in_motorByte0.m1Dir = 1;  //****** dir1 ******
				u_motorByte0.bits_in_motorByte0.m1Drop = 1;
				u_outputByte0.bits_in_outputByte0.plateStop = 0;
			}
			if(state == 2){
				u_outputByte0.bits_in_outputByte0.blowerPulse = 1;
				u_outputByte0.bits_in_outputByte0.lowerFixture = 1;
				u_outputByte0.bits_in_outputByte0.raiseFixture = 0;
				u_motorByte0.bits_in_motorByte0.m2Drop = 1;
				u_motorByte0.bits_in_motorByte0.m1Drop = 0;
			}
			if(state == 3){
				u_motorByte0.bits_in_motorByte0.m2Dir = 1;  // ****** dir2 *******
				m2 = 1;
			}
			if(state == 4){
				m2 = 0;
				u_motorByte0.bits_in_motorByte0.m2Drop = 0;
				u_outputByte0.bits_in_outputByte0.raiseFixture = 1;
			}
			if(state == 5){
				u_outputByte0.bits_in_outputByte0.lowerFixture = 0;
				u_motorByte0.bits_in_motorByte0.m2Drop = 1;
			}
			//*********************************************
			if(state == 6){
				u_motorByte0.bits_in_motorByte0.m2Dir = 1;  // ******* dir2 *******
				m2 = 1;
			}
			if(state == 7){
				m2 = 0;
				u_motorByte1.bits_in_motorByte1.m3Drop = 1;
				u_motorByte0.bits_in_motorByte0.m3Dir = 0;  // ******* dir3 *******
				if(print6 == 1){
					OrangutanLCD::clear();
					OrangutanLCD::print("Clean 1");
					print6 = 0;
				}
			}
			if(state == 8){
				m3 = 1;
				u_outputByte0.bits_in_outputByte0.brush1Lower = 1;
				u_outputByte0.bits_in_outputByte0.brush1Raise = 0;
			}
			if(state == 9){
				m2 = 1;
				u_motorByte0.bits_in_motorByte0.m2Dir = 0;  // ******* dir2 *******
			}
			if(state == 10){
				m2 = 0;
				m3 = 0;
				u_outputByte0.bits_in_outputByte0.brush1Lower = 0;
				u_outputByte0.bits_in_outputByte0.brush1Raise = 1;
			}
			if(state == 11){
				u_motorByte0.bits_in_motorByte0.m2Dir = 1;  // ******* dir2 *******
				m2 = 1;
			}
			if(state == 12){
				m2 = 0;
				u_motorByte0.bits_in_motorByte0.m3Dir = 0;  // ******* dir3 *******
				m3 = 1;
				u_outputByte0.bits_in_outputByte0.brush1Lower = 1;
				u_outputByte0.bits_in_outputByte0.brush1Raise = 0;
			}
			if(state == 13){
				m2 = 1;
			}
			if(state == 14){
				m3 = 0;
				u_outputByte0.bits_in_outputByte0.brush1Lower = 0;
				u_outputByte0.bits_in_outputByte0.brush1Raise = 1;
				u_motorByte1.bits_in_motorByte1.m3Drop = 0;
			}
			//*************************** may need to reverse order depending on dry station 1 positioning ***************************
			if(state == 15){
				m2 = 0;
				u_motorByte1.bits_in_motorByte1.m4Drop = 1;
				u_motorByte1.bits_in_motorByte1.m4Dir = 0;  // ******* dir4 *******
				if(print15 == 1){
					OrangutanLCD::clear();
					OrangutanLCD::print("Clean 2");
					print15 = 0;
				}
			}
			if(state == 16){
				m4 = 1;
				u_outputByte1.bits_in_outputByte1.brush2Lower = 1;
				u_outputByte0.bits_in_outputByte0.brush2Raise = 0;
			}
			if(state == 17){
				m2 = 1;
				u_motorByte0.bits_in_motorByte0.m2Dir = 0;  // ******* dir2 *******
			}
			if(state == 18){
				m2 = 0;
				m4 = 0;
				u_outputByte1.bits_in_outputByte1.brush2Lower = 0;
				u_outputByte0.bits_in_outputByte0.brush2Raise = 1;
			}
			if(state == 19){
				u_motorByte0.bits_in_motorByte0.m2Dir = 1;  // ******* dir2 *******
				m2 = 1;
			}
			if(state == 20){
				m2 = 0;
				u_motorByte1.bits_in_motorByte1.m4Dir = 0;  // ******* dir4 *******
				m4 = 1;
				u_outputByte1.bits_in_outputByte1.brush2Lower = 1;
				u_outputByte0.bits_in_outputByte0.brush2Raise = 0;
			}
			if(state == 21){
				m2 = 1;
			}
			if(state == 22){
				m4 = 0;
				m2 = 0;
				u_outputByte1.bits_in_outputByte1.brush2Lower = 0;
				u_outputByte0.bits_in_outputByte0.brush2Raise = 1;
				u_motorByte1.bits_in_motorByte1.m4Drop = 0;
			}
			//*************************************************
			if(state == 23){
				u_motorByte0.bits_in_motorByte0.m2Dir = 1;  // ******* dir2 *******
				m2 = 1;
			}
			if(state == 24){
				m2 = 0;
				u_outputByte1.bits_in_outputByte1.airKnife = 0;
				if(print24 == 1){
					OrangutanLCD::clear();
					OrangutanLCD::print("DRY AIR");
					print24 = 0;
				}
			}
			if(state == 25){
				u_motorByte0.bits_in_motorByte0.m2Dir = 0;  // ******* dir2 *******
				m2 = 1;
			}
			if(state == 26){
				u_outputByte1.bits_in_outputByte1.airKnife = 1;
			}
			if(state == 27){
				m2 = 0;
				u_motorByte1.bits_in_motorByte1.m5Drop = 1;
				u_motorByte1.bits_in_motorByte1.m5Dir = 0;
				m5 = 1;
			}
			if(state == 28){
				if(print28 == 1){
					OrangutanLCD::clear();
					OrangutanLCD::print("FINAL DRY");
					print28 = 0;
				}
				u_outputByte1.bits_in_outputByte1.ptRaise = 0;
			}
			if(state == 29){
				m2 = 1;
			}
			if(state == 30){
				m5 = 0;
				u_motorByte1.bits_in_motorByte1.m5Drop = 0;
				u_outputByte1.bits_in_outputByte1.ptRaise = 1;
				u_outputByte1.bits_in_outputByte1.ptLower = 0;
			}
			if(state == 31){
				m2 = 0;
				u_outputByte0.bits_in_outputByte0.raiseFixture = 0;
				u_outputByte0.bits_in_outputByte0.lowerFixture = 1;
			}
			if(state == 32){
				u_motorByte0.bits_in_motorByte0.m2Dir = 0;
				m2 = 1;
			}
			if(state == 33){
				m2 = 0;
				u_motorByte0.bits_in_motorByte0.m2Drop = 0;
				u_motorByte0.bits_in_motorByte0.m1Drop = 1;
				u_outputByte0.bits_in_outputByte0.raiseFixture = 1;
				u_outputByte0.bits_in_outputByte0.lowerFixture = 0;
			}
			if(state == 34){
				u_motorByte0.bits_in_motorByte0.m1Dir = 0;
				m1 = 1;
			}
			if(state == 35){
				m1 = 0;
				u_motorByte0.bits_in_motorByte0.m1Drop = 0;
				if(print35 == 1){
					OrangutanLCD::clear();
					OrangutanLCD::print("END OF CYCLE");
					print35 = 0;
				}
			}





			if( ((counter - counterRef) % (totallength1) ) < (steplength1) && m1)  //check if it is in the right period of the loop to send high
			{
				u_motorByte0.bits_in_motorByte0.m1Step = 1; // set bit 0
			}
			else
			{
				u_motorByte0.bits_in_motorByte0.m1Step = 0; // set bit 0
			}

			if( ((counter - counterRef) % (totallength2) ) < (steplength2) && m2)
			{
				u_motorByte0.bits_in_motorByte0.m2Step = 1; // set bit 1
			}
			else
			{
				u_motorByte0.bits_in_motorByte0.m2Step = 0; // set bit 1
			}

			if( ((counter - counterRef) % (totallength3) ) < (steplength3) && m3)
			{
				u_motorByte0.bits_in_motorByte0.m3Step = 1; // set bit 1
			}
			else
			{
				u_motorByte0.bits_in_motorByte0.m3Step = 0; // set bit 1
			}

			if( ((counter - counterRef) % (totallength4) ) < (steplength4) && m4)
			{
				u_motorByte1.bits_in_motorByte1.m4Step = 1; // set bit 1
			}
			else
			{
				u_motorByte1.bits_in_motorByte1.m4Step = 0; // set bit 1
			}

			if( ((counter - counterRefFive) % (totallength5) ) < (steplength5) && m5)
			{
				u_motorByte1.bits_in_motorByte1.m5Step = 1; // set bit 1
			}
			else
			{
				u_motorByte1.bits_in_motorByte1.m5Step = 0; // set bit 1
			}

			i2c_start(I2C1+I2C_WRITE);
			i2c_write(0x2);									// write command byte
			i2c_write(u_motorByte0.motorByte0);                       // write first byte of output
        	i2c_write(u_motorByte1.motorByte1);                       // write second byte of output
        	i2c_stop();                            // set stop conditon = release bus
			
			i2c_start(I2C2+I2C_WRITE);
			i2c_write(0x2);
			i2c_write(u_outputByte0.outputByte0);
			i2c_write(u_outputByte1.outputByte1);

			counter ++;
			delay_ms(1);
    	}
		u_motorByte0.bits_in_motorByte0.m1Drop = 0;
		u_motorByte0.bits_in_motorByte0.m2Drop = 0;
		u_motorByte1.bits_in_motorByte1.m3Drop = 0;
		u_motorByte1.bits_in_motorByte1.m4Drop = 0;
		u_motorByte1.bits_in_motorByte1.m5Drop = 0;
		
		i2c_start(I2C1+I2C_WRITE);
		i2c_write(0x2);
		i2c_write(u_motorByte0.motorByte0);
		i2c_write(u_motorByte1.motorByte1);
		i2c_stop();
	}
	OrangutanLCD::print("END");
    for(;;);	 
}
