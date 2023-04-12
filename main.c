#include  "Apps/SystemTask.h"
uint8 SERVO_MAPPING[10] = {1,2,3,4,5,6,7,8,9,10};
uint8 auto_pilot_index = 0;
#define FORWARD 0,0,0,0
#define STOP 1,1,1,1
enum servoID{RWHEEL = 1, LWHEEL, LFOOT, LSHOULDER, LELBOW, LHAND, RFOOT, RSHOULDER, RELBOW, RHAND};
//机器人动作初始化
void init(){
    MFSetServoPos(LFOOT,512,512);
    MFSetServoPos(LELBOW,550,512);
    MFSetServoPos(LHAND,550,512);
    MFSetServoPos(RFOOT,512,512);
    MFSetServoPos(RELBOW,512,512);
    MFSetServoPos(RHAND,512,512);
    MFServoAction();
    DelayMS(600);
    MFSetServoPos(LSHOULDER,512,256);
    MFSetServoPos(RSHOULDER,512,256);
    MFServoAction();
}

//前进
void forward(){
    MFSetServoRotaSpd(RWHEEL,-330);
    MFSetServoRotaSpd(LWHEEL,350);
    MFServoAction();
    DelayMS(300);
}

//加速
void boost(){
    MFSetServoRotaSpd(RWHEEL,-480);
    MFSetServoRotaSpd(LWHEEL,520);
    MFServoAction();
    DelayMS(300);
}
//加速后退
void boost_back(){
    MFSetServoRotaSpd(RWHEEL,620);
    MFSetServoRotaSpd(LWHEEL,-660);
    MFServoAction();
    DelayMS(300);
}

//后退
void go_back(){
    MFSetServoRotaSpd(RWHEEL,450);
    MFSetServoRotaSpd(LWHEEL,-470);
    MFServoAction();
    DelayMS(400);
}

//左转
void turn_left(){
    MFSetServoRotaSpd(RWHEEL,-480);
    MFSetServoRotaSpd(LWHEEL,-505);
    MFServoAction();
    DelayMS(400);
}

//右转
void turn_right(){
    MFSetServoRotaSpd(RWHEEL,480);
    MFSetServoRotaSpd(LWHEEL,505);
    MFServoAction();
    DelayMS(400);
}

//停止
void stop(){
    MFSetServoRotaSpd(RWHEEL,0);
    MFSetServoRotaSpd(LWHEEL,0);
    MFServoAction();
}

//前倒，重新站起动作1，肘部外伸
void front_1(){
    MFSetServoPos(LELBOW,910,768);
    MFSetServoPos(RELBOW,90,768);
    MFSetServoPos(LHAND,570,768);
    MFSetServoPos(RHAND,512,768);
    MFServoAction();
}

//后倒，重新站起动作1，肘部外伸
void back_1(){
    MFSetServoPos(LELBOW,910,768);
    MFSetServoPos(RELBOW,90,768);
    MFSetServoPos(LHAND,570,768);
    MFSetServoPos(RHAND,512,768);
    MFServoAction();
}

//前倒，重新站起动作2，肩部后顶
void front_2(){
    MFSetServoPos(LSHOULDER,140,768);
    MFSetServoPos(RSHOULDER,170,768);
    MFServoAction();
}

//后倒，重新站起动作2，肩部后顶
void back_2(){
    MFSetServoPos(LSHOULDER,880,768);
    MFSetServoPos(RSHOULDER,870,768);
    MFServoAction();
}

//前倒，站起动作3手部向下顶，腿部内弯，肩部往外一点
void front_3(){
    MFSetServoPos(LHAND,130,768);
    MFSetServoPos(RHAND,900,768);
    MFServoAction();
}

//后倒，站起动作3手部向下顶
void back_3(){
    MFSetServoPos(LHAND,130,768);
    MFSetServoPos(RHAND,900,768);
    MFServoAction();
}

//前倒，重新站起动作4，手部伸直，肘部伸直，腿部伸直
void front_4(){
    MFSetServoPos(LELBOW,700,768);
    MFSetServoPos(LHAND,342,768);
    MFSetServoPos(RELBOW,346,768);
    MFSetServoPos(RHAND,710,768);
    MFSetServoPos(LFOOT,803,512);
    MFSetServoPos(RFOOT,810,512);
    MFServoAction();
}

//后倒，重新站起动作4，手部伸直，肘部伸直
void back_4(){
    MFSetServoPos(LELBOW,700,768);
    MFSetServoPos(LHAND,342,768);
    MFSetServoPos(RELBOW,346,768);
    MFSetServoPos(RHAND,710,768);
    MFSetServoPos(LFOOT,221,512);
    MFSetServoPos(RFOOT,214,512);
    MFServoAction();
}

//前倒，重新站起动作5，手部往外一点，肩部往下一点，腿部后弯
void front_5(){
    MFSetServoPos(LELBOW,550,768);
    MFSetServoPos(RELBOW,512,768);
    MFSetServoPos(LHAND,520,768);
    MFSetServoPos(RHAND,512,768);
    MFSetServoPos(LSHOULDER,512,768);
    MFSetServoPos(RSHOULDER,512,768);
    MFSetServoPos(LFOOT,512,300);
    MFSetServoPos(RFOOT,512,300);
    MFSetServoRotaSpd(RWHEEL,-700);
    MFSetServoRotaSpd(LWHEEL,740);
    MFServoAction();
    DelayMS(200);
    MFSetServoRotaSpd(RWHEEL,-310);
    MFSetServoRotaSpd(LWHEEL,330);
    MFServoAction();
    DelayMS(750);
    stop();
    MFServoAction();
}

//后倒，重新站起动作5，腿部伸直，肩部伸直，移动轮子平衡重心
void back_5(){
    MFSetServoPos(LELBOW,550,768);
    MFSetServoPos(RELBOW,512,768);
    MFSetServoPos(LHAND,520,768);
    MFSetServoPos(RHAND,512,768);
    MFSetServoPos(LSHOULDER,512,768);
    MFSetServoPos(RSHOULDER,512,768);
    MFSetServoPos(LFOOT,512,300);
    MFSetServoPos(RFOOT,512,300);
    MFSetServoRotaSpd(RWHEEL,740);
    MFSetServoRotaSpd(LWHEEL,-700);
    MFServoAction();
    DelayMS(200);
    MFSetServoRotaSpd(RWHEEL,330);
    MFSetServoRotaSpd(LWHEEL,-310);
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
    init();
    DelayMS(500);
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

// 左手攻击，需要提前保持预警状态
void hit_left(){
    MFSetServoPos(LELBOW,630,968);
    MFSetServoPos(LHAND,580,968);
    MFSetServoRotaSpd(RWHEEL,-580);
    MFSetServoRotaSpd(LWHEEL,-605);
    MFServoAction();
    DelayMS(800);
    MFSetServoPos(LELBOW,680,612);
    MFSetServoPos(LHAND,630,612);
    MFSetServoRotaSpd(RWHEEL,330);
    MFSetServoRotaSpd(LWHEEL,350);
    MFServoAction();
}

// 右手攻击，需要提前保持预警状态
void hit_right(){
    MFSetServoPos(RELBOW,430,968);
    MFSetServoPos(RHAND,470,968);
    MFSetServoRotaSpd(RWHEEL,580);
    MFSetServoRotaSpd(LWHEEL,605);
    MFServoAction();
    DelayMS(800);
    MFSetServoPos(RELBOW,740,612);
    MFSetServoPos(RHAND,780,612);
    MFSetServoRotaSpd(RWHEEL,-330);
    MFSetServoRotaSpd(LWHEEL,-350);
    MFServoAction();
}
// 打击动作1，手抬起
void hit_1(){
    MFSetServoPos(LSHOULDER,170,512);
    MFSetServoPos(LELBOW,550,256);
    MFSetServoPos(LHAND,530,256);
    MFSetServoPos(RSHOULDER,885,512);
    MFSetServoPos(RELBOW,512,256);
    MFSetServoPos(RHAND,512,256);
    MFServoAction();
}

//打击动作2，前方散开攻击
void hit_2(){
    MFSetServoPos(LELBOW,630,968);
    MFSetServoPos(LHAND,580,968);
    MFSetServoPos(RELBOW,430,968);
    MFSetServoPos(RHAND,470,968);
    MFSetServoPos(LSHOULDER,160,512);
    MFSetServoPos(RSHOULDER,250,512);
    MFServoAction();
    DelayMS(600);
    MFSetServoPos(LELBOW,320,256);
    MFSetServoPos(LHAND,270,256);
    MFSetServoPos(RELBOW,740,256);
    MFSetServoPos(RHAND,780,256);
    MFServoAction();
    DelayMS(1000);
}
void hit_3_L(){
    MFSetServoRotaSpd(RWHEEL,-580);
    MFSetServoRotaSpd(LWHEEL,-605);
    MFServoAction();
    DelayMS(300);
    MFSetServoPos(LSHOULDER,240,812);
    MFSetServoPos(RSHOULDER,260,812);
    MFSetServoPos(LELBOW,680,812);
    MFSetServoPos(LHAND,630,812);
    MFSetServoPos(RELBOW,640,812);
    MFSetServoPos(RHAND,680,812);
    MFServoAction();
    DelayMS(600);
    MFSetServoRotaSpd(RWHEEL,480);
    MFSetServoRotaSpd(LWHEEL,505);
    MFServoAction();
    DelayMS(300);
    MFSetServoPos(LELBOW,420,812);
    MFSetServoPos(LHAND,370,812);
    MFSetServoPos(RELBOW,380,812);
    MFSetServoPos(RHAND,420,812);
    MFServoAction();
    DelayMS(600);
}
//打击动作3，雨刮式攻击
void hit_3_R(){
    MFSetServoRotaSpd(RWHEEL,580);
    MFSetServoRotaSpd(LWHEEL,605);
    MFServoAction();
    DelayMS(300);
    MFSetServoPos(LSHOULDER,240,812);
    MFSetServoPos(RSHOULDER,260,812);
    MFSetServoPos(LELBOW,420,812);
    MFSetServoPos(LHAND,370,812);
    MFSetServoPos(RELBOW,380,812);
    MFSetServoPos(RHAND,420,812);
    MFServoAction();
    DelayMS(600);
    MFSetServoRotaSpd(RWHEEL,-500);
    MFSetServoRotaSpd(LWHEEL,-535);
    MFServoAction();
    DelayMS(300);
    MFSetServoPos(LELBOW,680,812);
    MFSetServoPos(LHAND,630,812);
    MFSetServoPos(RELBOW,640,812);
    MFSetServoPos(RHAND,680,812);
    MFServoAction();
    DelayMS(600);
}

void hit_4(){
	
	MFSetServoPos(LELBOW,380,512);
    MFSetServoPos(LHAND,330,512);
    MFSetServoPos(RELBOW,340,512);
    MFSetServoPos(RHAND,380,512);
    MFServoAction();
    DelayMS(700);
	MFSetServoPos(LSHOULDER,170,768);
    MFSetServoPos(RSHOULDER,885,768);
    MFSetServoRotaSpd(RWHEEL,-500);
    MFSetServoRotaSpd(LWHEEL,-515);
    MFServoAction();
    DelayMS(1800);
}

// 预攻击姿势
void alert(){
    MFSetServoPos(LSHOULDER,170,812);
    MFSetServoPos(RSHOULDER,280,812);
    MFSetServoPos(LELBOW,320,256);
    MFSetServoPos(LHAND,270,256);
    MFSetServoPos(RELBOW,740,256);
    MFSetServoPos(RHAND,780,256);
    MFServoAction();
}

// 预攻击姿势
void alert_delay(){
    MFSetServoPos(LSHOULDER,170,812);
    MFSetServoPos(RSHOULDER,280,812);
    MFServoAction();
    DelayMS(600);
    MFSetServoPos(LELBOW,320,256);
    MFSetServoPos(LHAND,270,256);
    MFSetServoPos(RELBOW,740,256);
    MFSetServoPos(RHAND,780,256);
    MFServoAction();
}
void reinit(){
    MFInit();
    MFInitServoMapping(&SERVO_MAPPING[0],10);
    MFSetPortDirect(0x00000C00);
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
}

//和蔼
void szyf(){
    MFSetServoPos(LSHOULDER,239,512);
    MFSetServoPos(RSHOULDER,989,512);
    MFServoAction();
    DelayMS(500);
    MFSetServoPos(LELBOW,481,600);
    MFSetServoPos(LHAND,402,600);
    MFSetServoPos(RELBOW,550,600);
    MFSetServoPos(RHAND,629,600);
    MFServoAction();
}

void attack_back(){
    alert_delay();
    MFSetServoRotaSpd(RWHEEL, 400);
    MFSetServoRotaSpd(LWHEEL, -420);
    MFServoAction();
    DelayMS(1000);  //后退1000ms
    forward();
}
//自动巡航
void autopilot() {
    MFSetServoPos(LFOOT, 502, 256);
    MFSetServoPos(RFOOT, 502, 256);
    MFServoAction();
    auto_pilot_index = 0;
    if(MFGetDigiInput(0) == 1) {
        auto_pilot_index += 1;
    }
    if(MFGetDigiInput(1) == 1) {
        auto_pilot_index += 2;
    }
    if(MFGetDigiInput(2) == 1) {
        auto_pilot_index += 4;
    }
    if(MFGetDigiInput(3) == 1) {
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
        case 15: // 全部悬空，停止
            stop();
            break;
        default:break;
    }
}

int main()
{
    reinit();
    //检测到物体返回0，检测不到返回1
    int enemy_L1; // 左前方敌人检测
    int enemy_L2; // 左侧敌人检测
    int enemy_R1; // 右前方敌人检测
    int enemy_R2; // 右侧敌人检测
    int enemy_FRONT; // 前方敌人检测
    int enemy_BACK; // 后方敌人检测

    // AD传感器输入
    int angle; // 倾角数值
    int distance; // 距离数值，距离越近数值越大

    int attacking = 0; // 正在攻击
    int attack_times = 0;  //记录攻击次数，每一轮攻击超过3次自动后退逃跑

    MFInit();
    MFInitServoMapping(&SERVO_MAPPING[0],10);
    MFSetPortDirect(0x00000C00);
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
    DelayMS(1500);
    alert_delay();
    forward();

    for(;;){
        
        // 获取IO输入
        enemy_L1 = MFGetDigiInput(4);   // 检测左前敌人
        enemy_L2 = MFGetDigiInput(5);   // 检测左侧敌人
        enemy_R1 = MFGetDigiInput(6);   // 检测右前敌人
        enemy_R2 = MFGetDigiInput(7);   // 检测右侧敌人
        enemy_FRONT = MFGetDigiInput(8);   // 检测前方敌人
        enemy_BACK = MFGetDigiInput(9);   // 检测后方敌人及倒地预警

        // 获取AD输入
        angle = MFGetAD(0);
        distance = MFGetAD(1);

        // 前倒站起
        if (angle > 1000){
            stop();
            front_stand();
            reinit();
            alert_delay();
            forward();
            continue;
        }
        // 后倒站起
        if (angle < 400){
            stop();
            back_stand();
            reinit();
            alert_delay();
            forward();
            continue;
        }
        // 检测到敌人
        if (distance > 100 || enemy_FRONT == 0){
            if (attack_times % 3 == 0) {
                attack_back();
            } else {           
                MFSetServoPos(LFOOT,-482,650);
                MFSetServoPos(RFOOT,482,650);
                MFServoAction();
                hit_2();            
                MFSetServoPos(LFOOT,-502,512);
                MFSetServoPos(RFOOT,502,512);
                MFServoAction();
                stop();
            }
            attack_times++;
        } else { // 检测不到敌人
            attacking = 0;
            alert();
        }
        
        // 后方检测到敌人，向前逃跑防止被偷袭
        if (enemy_BACK == 0){
            turn_right();
            autopilot();
            continue;
        }

        // 左侧检测到敌人
        if (enemy_L2 == 0){
            hit_left();
            attack_times++;
            if (attack_times % 3 == 0) {
                attack_back();
            }
            autopilot();
            continue;
        }
        // 右侧检测到敌人
        if (enemy_R2 == 0){
            hit_right();
            attack_times++;
            if (attack_times % 3 == 0) {
                attack_back();
            }
            autopilot();
            continue;
        }
        // 左前方检测到敌人
        if (enemy_L1 == 0) {
            hit_3_L();
            attack_times++;
            if (attack_times % 3 == 0) {
                attack_back();
            }
            autopilot();
            continue;
        }
        // 右前方检测到敌人
        if (enemy_R1 == 0) {
            hit_3_R();
            attack_times++;
            if (attack_times % 3 == 0) {
                attack_back();
            }
            autopilot();
            continue;
        }
        // 自动巡航
        autopilot();
    }
    return 0;
}