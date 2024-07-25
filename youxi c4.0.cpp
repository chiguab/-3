#include <iostream>
using namespace std;

int main() {
    int playerHealth = 10;
    int computerHealth = 10;
    int playerBullets = 5;
    int computerBullets = 5;
    bool playerReflectShield = false;
    bool computerReflectShield = false;

    while (true) {
        int playerAction;
        int computerAction = rand() % 5 + 1; // 让电脑的动作随机

        cout << "选择你的动作：" << endl;
        cout << "1. 射击 (消耗1颗子弹)" << endl;
        cout << "2. 装填 (增加2颗子弹)" << endl;
        cout << "3. 治疗 (回复1点生命值)" << endl;
        cout << "4. 挥刀 (造成2点伤害)" << endl;
        cout << "5. 装备反弹盾 (反弹下一次攻击)" << endl;
        cin >> playerAction;

        // 玩家行动
        if (playerAction == 1) {
            if (playerBullets > 0) {
                cout << "玩家射击！" << endl;
                playerBullets--;
                if (!computerReflectShield) { // 如果电脑没有装备反弹盾
                    computerHealth--;
                } else {
                    cout << "电脑反弹了子弹！" << endl;
                    playerHealth--;
                    computerReflectShield = false; // 反弹盾使用后消失
                }
            } else {
                cout << "没有子弹了！" << endl;
            }
        }
        else if (playerAction == 2) {
            cout << "玩家装填子弹！" << endl;
            playerBullets += 2;
        }
        else if (playerAction == 3) {
            cout << "玩家治疗！" << endl;
            playerHealth += 1;
        }
        else if (playerAction == 4) {
            cout << "玩家挥刀攻击！" << endl;
            computerHealth -= 2; // 刀攻击伤害
        }
        if (playerAction == 5) {
            if (!playerReflectShield) { // 如果玩家之前没有反弹盾
                playerReflectShield = true;
                cout << "玩家装备了反弹盾。" << endl;
            } else {
                cout << "玩家已经有反弹盾了。" << endl;
            }
        }

        // 电脑行动
        if (computerAction == 1) {
            if (computerBullets > 0) {
                cout << "电脑射击！" << endl;
                computerBullets--;
                if (!playerReflectShield) { // 如果玩家没有装备反弹盾
                    playerHealth--;
                } else {
                    cout << "玩家反弹了子弹！" << endl;
                    computerHealth--;
                    playerReflectShield = false; // 反弹盾使用后消失
                }
            } else {
                cout << "电脑没有子弹了！" << endl;
            }
        }
        else if (computerAction == 2) {
            cout << "电脑装填子弹！" << endl;
            computerBullets += 2;
        }
        else if (computerAction == 3) {
            cout << "电脑治疗！" << endl;
            computerHealth += 1;
        }
        else if (computerAction == 4) {
            cout << "电脑挥刀攻击！" << endl;
            playerHealth -= 2; // 刀攻击伤害
        }
        if (computerAction == 5) {
            if (!computerReflectShield) { // 如果电脑之前没有反弹盾
                computerReflectShield = true;
                cout << "电脑装备了反弹盾。" << endl;
            } else {
                cout << "电脑已经有反弹盾了。" << endl;
            }
        }

        // 检查是否有一方获胜
        if (playerHealth <= 0) {
		    cout << "玩家输了！" << endl;
		    break; // 结束游戏
		} else if (computerHealth <= 0) {
		    cout << "电脑输了！" << endl;
		    break; // 结束游戏
		}
		cout << "玩家血量: " << playerHealth << ", 子弹数量: " << playerBullets << endl;
		cout << "电脑血量: " << computerHealth << ", 子弹数量: " << computerBullets << endl;
    }
    return 0;
}
