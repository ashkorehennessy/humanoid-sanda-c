#include  "Apps/SystemTask.h"
uint8 SERVO_MAPPING[10] = {1,2,3,4,5,6,7,8,9,10};
//机器人动作初始化
void init(){
    MFSetServoPos(3,512,256);
    MFSetServoPos(4,512,256);
    MFSetServoPos(5,550,256);
    MFSetServoPos(6,530,256);
    MFSetServoPos(7,512,256);
    MFSetServoPos(8,512,256);
    MFSetServoPos(9,512,256);
    MFSetServoPos(10,512,256);
    MFServoAction();
}

//前进
void forward(){
    MFSetServoRotaSpd(1,-310);
    MFSetServoRotaSpd(2,330);
    MFServoAction();
    DelayMS(400);
}

void boost(){
    MFSetServoRotaSpd(1,-580);
    MFSetServoRotaSpd(2,630);
    MFServoAction();
    DelayMS(400);
}

//后退
void back(){
    MFSetServoRotaSpd(1,450);
    MFSetServoRotaSpd(2,-470);
    MFServoAction();
    DelayMS(400);
}

//左转
void turn_left(){
    MFSetServoRotaSpd(1,-450);
    MFSetServoRotaSpd(2,-470);
    MFServoAction();
    DelayMS(400);
}

//右转
void turn_right(){
    MFSetServoRotaSpd(1,450);
    MFSetServoRotaSpd(2,470);
    MFServoAction();
    DelayMS(400);
}

//停止
void stop(){
    MFSetServoRotaSpd(1,0);
    MFSetServoRotaSpd(2,0);
    MFServoAction();
}

//前倒，重新站起动作1，肘部外伸
void front_1(){
    MFSetServoPos(5,790,768);
    MFSetServoPos(9,260,768);
    MFServoAction();
}

//后倒，重新站起动作1，肘部外伸
void back_1(){
    MFSetServoPos(5,800,768);
    MFSetServoPos(9,260,768);
    MFServoAction();
}

//前倒，重新站起动作2，肩部后顶
void front_2(){
    MFSetServoPos(4,170,768);
    MFSetServoPos(8,180,768);
    MFServoAction();
}

//后倒，重新站起动作2，肩部后顶
void back_2(){
    MFSetServoPos(4,860,768);
    MFSetServoPos(8,885,768);
    MFServoAction();
}

//前倒，站起动作3手部向下顶
void front_3(){
    MFSetServoPos(6,190,768);
    MFSetServoPos(10,840,768);
    MFServoAction();
}

//后倒，站起动作3手部向下顶
void back_3(){
    MFSetServoPos(6,190,768);
    MFSetServoPos(10,860,768);
    MFServoAction();
}

//前倒，重新站起动作4，手部伸直，肘部伸直
void front_4(){
    MFSetServoPos(6,490,768);
    MFSetServoPos(10,532,768);
    MFSetServoPos(5,520,768);
    MFSetServoPos(9,512,768);
    MFServoAction();
}

//后倒，重新站起动作4，手部伸直，肘部伸直
void back_4(){
    MFSetServoPos(6,490,768);
    MFSetServoPos(10,532,768);
    MFSetServoPos(5,550,768);
    MFSetServoPos(9,512,768);
    MFServoAction();
}

//前倒，重新站起动作5，手部往外一点，肩部往下一点，腿部后弯
void front_5(){
    MFSetServoPos(6,520,768);
    MFSetServoPos(10,512,768);
    MFSetServoPos(3,750,512);
    MFSetServoPos(7,750,512);
    MFSetServoPos(4,210,180);
    MFSetServoPos(8,240,180);
    MFServoAction();
}

//后倒，重新站起动作5，手部往外一点，肩部往下一点，腿部后弯
void back_5(){
    MFSetServoPos(6,520,768);
    MFSetServoPos(10,512,768);
    MFSetServoPos(3,250,512);
    MFSetServoPos(7,270,512);
    MFSetServoPos(4,750,180);
    MFSetServoPos(8,780,180);
    MFServoAction();
}

//前倒，重新站起动作6，腿部伸直，肩部伸直，移动轮子平衡重心
void front_6(){
    MFSetServoPos(3,512,300);
    MFSetServoPos(7,512,300);
    MFSetServoPos(4,512,180);
    MFSetServoPos(8,512,180);
    MFSetServoRotaSpd(1,-700);
    MFSetServoRotaSpd(2,740);
    MFServoAction();
    DelayMS(200);
    MFSetServoRotaSpd(1,-310);
    MFSetServoRotaSpd(2,330);
    MFServoAction();
    DelayMS(750);
    stop();
}

//后倒，重新站起动作6，腿部伸直，肩部伸直，移动轮子平衡重心
void back_6(){
    MFSetServoPos(3,512,300);
    MFSetServoPos(7,512,300);
    MFSetServoPos(4,512,180);
    MFSetServoPos(8,512,180);
    MFSetServoRotaSpd(1,740);
    MFSetServoRotaSpd(2,-700);
    MFServoAction();
    DelayMS(200);
    MFSetServoRotaSpd(1,330);
    MFSetServoRotaSpd(2,-310);
    MFServoAction();
    DelayMS(750);
    stop();
}

//前倒站起
void front_stand(){
    DelayMS(1000);
    front_1();
    DelayMS(600);
    front_2();
    DelayMS(600);
    front_3();
    DelayMS(1000);
    front_4();
    DelayMS(800);
    front_5();
    DelayMS(800);
    front_6();
    DelayMS(1000);
}

// 后倒站起
void back_stand(){
    DelayMS(1000);
    back_1();
    DelayMS(600);
    back_2();
    DelayMS(600);
    back_3();
    DelayMS(1000);
    back_4();
    DelayMS(800);
    back_5();
    DelayMS(800);
    back_6();
    DelayMS(1000);
}

//和蔼
void szyf(){
    MFSetServoPos(4,239,512);
    MFSetServoPos(8,989,512);
    MFServoAction();
    DelayMS(500);
    MFSetServoPos(5,481,600);
    MFSetServoPos(6,402,600);
    MFSetServoPos(9,550,600);
    MFSetServoPos(10,629,600);
    MFServoAction();
}

//自动巡航
void autopilot(int L1, int L2, int R1, int R2) {
    int index=0;
    if(L1 == 1) {
        index += 1;
    }
    if(L2 == 1) {
        index += 2;
    }
    if(R1 == 1) {
        index += 4;
    }
    if(R2 == 1) {
        index += 8;
    }
    switch (index) {
        case 0: // 无悬空，前进
            forward();
            break;
        case 1: // 左前悬空，后退，右转*2
            back();
            turn_right();
            turn_right();
            forward();
            break;
        case 2: // 左后悬空，右转，前进
            turn_right();
            forward();
            break;
        case 3: // 左侧悬空，右转*2，前进
            turn_right();
            turn_right();
            forward();
            break;
        case 4: // 右前悬空，后退，左转*2，前进
            back();
            turn_left();
            turn_left();
            forward();
            break;
        case 5: // 前方悬空，后退，左转*4，前进
            back();
            turn_left();
            turn_left();
            turn_left();
            forward();
            break;
        case 8: // 右后悬空，左转，前进
            turn_left();
            forward();
            break;
        case 10: // 后方悬空，加速*2，前进
            boost();
            boost();
            forward();
            break;
        case 12: // 右侧悬空，左转*2，前进
            turn_left();
            turn_left();
            forward();
            break;
    }
}

int main()
{
    //检测到物体返回0，检测不到返回1
    int L1; // 左前
    int L2; // 左后
    int R1; // 右前
    int R2; // 右后

    int angle; // 倾角

    MFInit();
    MFInitServoMapping(&SERVO_MAPPING[0],10);
    MFSetPortDirect(0x00000FF0);
    MFSetServoMode(1,1);
    MFSetServoMode(2,1);
    MFSetServoMode(3,0);
    MFSetServoMode(4,0);
    MFSetServoMode(5,0);
    MFSetServoMode(6,0);
    MFSetServoMode(7,0);
    MFSetServoMode(8,0);
    MFSetServoMode(9,0);
    MFSetServoMode(10,0);
    DelayMS(3000);

    for(;MFGetAD(1) < 150;); //接近头部时跳出循环

    //初始化，上台
    init();
    DelayMS(2000);
    boost();
    DelayMS(1400);

    for(;;){
        L1 = MFGetDigiInput(0);
        L2 = MFGetDigiInput(1);
        R1 = MFGetDigiInput(2);
        R2 = MFGetDigiInput(3);
        angle = MFGetAD(0);

        if (angle > 700){
            stop();
            front_stand();
            continue;
        }
        if (angle < 170){
            stop();
            back_stand();
            continue;
        }
        autopilot(L1, L2, R1, R2);
    }
    return 0;
}