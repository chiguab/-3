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
        int computerAction = rand() % 5 + 1; // �õ��ԵĶ������

        cout << "ѡ����Ķ�����" << endl;
        cout << "1. ��� (����1���ӵ�)" << endl;
        cout << "2. װ�� (����2���ӵ�)" << endl;
        cout << "3. ���� (�ظ�1������ֵ)" << endl;
        cout << "4. �ӵ� (���2���˺�)" << endl;
        cout << "5. װ�������� (������һ�ι���)" << endl;
        cin >> playerAction;

        // ����ж�
        if (playerAction == 1) {
            if (playerBullets > 0) {
                cout << "��������" << endl;
                playerBullets--;
                if (!computerReflectShield) { // �������û��װ��������
                    computerHealth--;
                } else {
                    cout << "���Է������ӵ���" << endl;
                    playerHealth--;
                    computerReflectShield = false; // ������ʹ�ú���ʧ
                }
            } else {
                cout << "û���ӵ��ˣ�" << endl;
            }
        }
        else if (playerAction == 2) {
            cout << "���װ���ӵ���" << endl;
            playerBullets += 2;
        }
        else if (playerAction == 3) {
            cout << "������ƣ�" << endl;
            playerHealth += 1;
        }
        else if (playerAction == 4) {
            cout << "��һӵ�������" << endl;
            computerHealth -= 2; // �������˺�
        }
        if (playerAction == 5) {
            if (!playerReflectShield) { // ������֮ǰû�з�����
                playerReflectShield = true;
                cout << "���װ���˷����ܡ�" << endl;
            } else {
                cout << "����Ѿ��з������ˡ�" << endl;
            }
        }

        // �����ж�
        if (computerAction == 1) {
            if (computerBullets > 0) {
                cout << "���������" << endl;
                computerBullets--;
                if (!playerReflectShield) { // ������û��װ��������
                    playerHealth--;
                } else {
                    cout << "��ҷ������ӵ���" << endl;
                    computerHealth--;
                    playerReflectShield = false; // ������ʹ�ú���ʧ
                }
            } else {
                cout << "����û���ӵ��ˣ�" << endl;
            }
        }
        else if (computerAction == 2) {
            cout << "����װ���ӵ���" << endl;
            computerBullets += 2;
        }
        else if (computerAction == 3) {
            cout << "�������ƣ�" << endl;
            computerHealth += 1;
        }
        else if (computerAction == 4) {
            cout << "���Իӵ�������" << endl;
            playerHealth -= 2; // �������˺�
        }
        if (computerAction == 5) {
            if (!computerReflectShield) { // �������֮ǰû�з�����
                computerReflectShield = true;
                cout << "����װ���˷����ܡ�" << endl;
            } else {
                cout << "�����Ѿ��з������ˡ�" << endl;
            }
        }

        // ����Ƿ���һ����ʤ
        if (playerHealth <= 0) {
		    cout << "������ˣ�" << endl;
		    break; // ������Ϸ
		} else if (computerHealth <= 0) {
		    cout << "�������ˣ�" << endl;
		    break; // ������Ϸ
		}
		cout << "���Ѫ��: " << playerHealth << ", �ӵ�����: " << playerBullets << endl;
		cout << "����Ѫ��: " << computerHealth << ", �ӵ�����: " << computerBullets << endl;
    }
    return 0;
}
