#include  "Apps/SystemTask.h"
uint8 SERVO_MAPPING[10] = {1,2,3,4,5,6,7,8,9,10};
uint8 auto_pilot_index = 0;
//机器人动作初始化
void init(){
    MFSetServoPos(3,512,256);
    MFSetServoPos(4,512,256);
    MFSetServoPos(5,550,256);
    MFSetServoPos(6,550,256);
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
    MFSetServoRotaSpd(1,-520);
    MFSetServoRotaSpd(2,540);
    MFServoAction();
    DelayMS(400);
}

//后退
void go_back(){
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
    MFSetServoPos(5,910,768);
    MFSetServoPos(9,90,768);
    MFSetServoPos(6,570,768);
    MFSetServoPos(10,512,768);
    MFServoAction();
}

//后倒，重新站起动作1，肘部外伸
void back_1(){
    MFSetServoPos(5,910,768);
    MFSetServoPos(9,90,768);
    MFSetServoPos(6,570,768);
    MFSetServoPos(10,512,768);
    MFServoAction();
}

//前倒，重新站起动作2，肩部后顶
void front_2(){
    MFSetServoPos(4,140,768);
    MFSetServoPos(8,170,768);
    MFServoAction();
}

//后倒，重新站起动作2，肩部后顶
void back_2(){
    MFSetServoPos(4,880,768);
    MFSetServoPos(8,870,768);
    MFServoAction();
}

//前倒，站起动作3手部向下顶，腿部内弯，肩部往外一点
void front_3(){
    MFSetServoPos(6,130,768);
    MFSetServoPos(10,900,768);
    MFServoAction();
}

//后倒，站起动作3手部向下顶
void back_3(){
    MFSetServoPos(6,130,768);
    MFSetServoPos(10,900,768);
    MFServoAction();
}

//前倒，重新站起动作4，手部伸直，肘部伸直，腿部伸直
void front_4(){
    MFSetServoPos(5,700,768);
    MFSetServoPos(6,342,768);
    MFSetServoPos(9,346,768);
    MFSetServoPos(10,710,768);
    MFSetServoPos(3,803,512);
    MFSetServoPos(7,810,512);
    MFServoAction();
}

//后倒，重新站起动作4，手部伸直，肘部伸直
void back_4(){
    MFSetServoPos(5,700,768);
    MFSetServoPos(6,342,768);
    MFSetServoPos(9,346,768);
    MFSetServoPos(10,710,768);
    MFSetServoPos(3,221,512);
    MFSetServoPos(7,214,512);
    MFServoAction();
}

//前倒，重新站起动作5，手部往外一点，肩部往下一点，腿部后弯
void front_5(){
    MFSetServoPos(5,550,768);
    MFSetServoPos(9,512,768);
    MFSetServoPos(6,520,768);
    MFSetServoPos(10,512,768);
    MFSetServoPos(4,512,768);
    MFSetServoPos(8,512,768);
    MFSetServoPos(3,512,300);
    MFSetServoPos(7,512,300);
    MFSetServoRotaSpd(1,-700);
    MFSetServoRotaSpd(2,740);
    MFServoAction();
    DelayMS(200);
    MFSetServoRotaSpd(1,-310);
    MFSetServoRotaSpd(2,330);
    MFServoAction();
    DelayMS(750);
    stop();
    MFServoAction();
}

//后倒，重新站起动作5，腿部伸直，肩部伸直，移动轮子平衡重心
void back_5(){
    MFSetServoPos(5,550,768);
    MFSetServoPos(9,512,768);
    MFSetServoPos(6,520,768);
    MFSetServoPos(10,512,768);
    MFSetServoPos(4,512,768);
    MFSetServoPos(8,512,768);
    MFSetServoPos(3,512,300);
    MFSetServoPos(7,512,300);
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
    front_1();
    DelayMS(600);
    front_2();
    DelayMS(600);
    front_3();
    DelayMS(1000);
    front_4();
    DelayMS(1400);
    front_5();
    DelayMS(1000);
}

// 后倒站起
void back_stand(){
    back_1();
    DelayMS(600);
    back_2();
    DelayMS(600);
    back_3();
    DelayMS(1000);
    back_4();
    DelayMS(1400);
    back_5();
    DelayMS(1000);
}

// 打击动作1，手抬起
void hit_1(){
    MFSetServoPos(4,170,512);
    MFSetServoPos(5,550,256);
    MFSetServoPos(6,530,256);
    MFSetServoPos(8,885,512);
    MFSetServoPos(9,512,256);
    MFSetServoPos(10,512,256);
    MFServoAction();
}

//打击动作2，前方散开攻击
void hit_2(){
    MFSetServoPos(4,160,512);
    MFSetServoPos(8,250,512);
    MFSetServoPos(5,320,256);
    MFSetServoPos(6,270,256);
    MFSetServoPos(9,740,256);
    MFSetServoPos(10,780,256);
    //forward();
    DelayMS(600);
    MFSetServoPos(5,630,768);
    MFSetServoPos(6,580,768);
    MFSetServoPos(9,430,768);
    MFSetServoPos(10,470,768);
    //go_back();
}

//打击动作3，雨刮式攻击
void hit_3(){
    MFSetServoPos(4,170,512);
    MFSetServoPos(8,180,512);
    MFSetServoPos(5,420,512);
    MFSetServoPos(6,370,512);
    MFSetServoPos(9,380,512);
    MFSetServoPos(10,420,512);
    MFServoAction();
    DelayMS(1000);
    MFSetServoPos(5,680,512);
    MFSetServoPos(6,630,512);
    MFSetServoPos(9,640,512);
    MFSetServoPos(10,680,512);
    MFServoAction();
    DelayMS(1000);
}

void hit_4(){
	MFSetServoPos(8,885,768);
	MFSetServoPos(4,170,768);
	MFSetServoPos(5,680,512);
    MFSetServoPos(6,630,512);
    MFSetServoPos(9,640,512);
    MFSetServoPos(10,680,512);
    MFSetServoRotaSpd(1,-600);
    MFSetServoRotaSpd(2,-620);
    MFServoAction();
    DelayMS(1500);
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
    auto_pilot_index = 0;
    if(L1 == 1) {
        auto_pilot_index += 1;
    }
    if(L2 == 1) {
        auto_pilot_index += 2;
    }
    if(R1 == 1) {
        auto_pilot_index += 4;
    }
    if(R2 == 1) {
        auto_pilot_index += 8;
    }
    switch (auto_pilot_index) {
        case 0: // 无悬空，前进
            forward();
            break;
        case 1: // 左前悬空，后退，右转*2
            go_back();
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
            go_back();
            turn_left();
            turn_left();
            forward();
            break;
        case 5: // 前方悬空，后退，左转*4，前进
            go_back();
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
        default:break;
    }
}

//刷新传感器信号缓冲
void flush_sensor(){
    int i,j;
    for(j=0;j<10;j+=1){

        for(i=0;i<2;i+=1){
            MFGetAD(i);
        }
        for(i=0;i<4;i+=1){
            MFGetDigiInput(i);
        }
    }
}

int main()
{
    //检测到物体返回0，检测不到返回1
    int edge_L1; // 左前边缘检测
    int edge_L2; // 左后边缘检测
    int edge_R1; // 右前边缘检测
    int edge_R2; // 右后边缘检测
    int enemy_B1; // 左后方敌人检测
    int enemy_B2; // 右后方敌人检测
    int enemy_F1; // 左前方敌人检测
    int enemy_F2; // 右前方敌人检测

    // AD传感器输入
    int angle; // 倾角数值
    int distance; // 距离数值，距离越近数值越大

    int attacking = 0; // 正在攻击
    MFInit();
    MFInitServoMapping(&SERVO_MAPPING[0],10);
    MFSetPortDirect(0x00000F00);
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
    DelayMS(1000);

    for(;;){
        
        // 获取IO输入
        edge_L1 = MFGetDigiInput(0);
        edge_L2 = MFGetDigiInput(1);
        edge_R1 = MFGetDigiInput(2);
        edge_R2 = MFGetDigiInput(3);
        enemy_B1 = MFGetDigiInput(4);   // 检测左后方敌人
        enemy_B2 = MFGetDigiInput(5);   // 检测右后方敌人
        enemy_F1 = MFGetDigiInput(6);   // 检测左前方敌人
        enemy_F2 = MFGetDigiInput(7);   // 检测右前方敌人

        // 获取AD输入
        angle = MFGetAD(0);
        distance = MFGetAD(1);

        // 前倒站起
        if (angle > 700){
            stop();
            front_stand();
            flush_sensor();
            continue;
        }
        // 后倒站起
        if (angle < 170){
            stop();
            back_stand();
            flush_sensor();
            continue;
        }
        // 检测到敌人
        if (distance > 100){
            stop();
            if (attacking == 0){
                hit_1();
                DelayMS(500);
                attacking = 1;
            }
            hit_4();
        } else { // 检测不到敌人
            attacking = 0;
            init();
        }
        
        // 后方检测到敌人，仅转向
        if (enemy_B1 == 0 || enemy_B2 == 0) {
            if (attacking == 0){
                turn_right();
                DelayMS(300); //转太快容易倒
                turn_right();
            }
            continue;
        }

        // 左前方检测到敌人
        if (enemy_F1 == 0) {
            if (attacking == 0) {
                turn_left();
            }
            continue;
        }
        // 右前方检测到敌人
        if (enemy_F2 == 0) {
            if (attacking == 0) {
                turn_right();
            }
            continue;
        }
        // 自动巡航
        autopilot(edge_L1, edge_L2, edge_R1, edge_R2);
    }
    return 0;
}