#include <iostream>

using namespace std;

// 포션 및 스탯 관리 함수
// 포인터를 사용하여 메인 변수의 값을 직접 수정합니다.
void setPotion(int menu, int* p_HPPotion, int* p_MPPotion, int status[]) {
    switch (menu) {
    case 1: // HP UP
        if (*p_HPPotion > 0) {
            status[0] += 20;
            (*p_HPPotion)--;
            cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 HP: " << status[0] << endl;
            cout << "남은 포션 수: " << *p_HPPotion << endl;
        }
        else {
            cout << "* 포션이 부족하여 사용할 수 없습니다!" << endl;
        }
        break;

    case 2: // MP UP
        if (*p_MPPotion > 0) {
            status[1] += 20;
            (*p_MPPotion)--;
            cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 MP: " << status[1] << endl;
            cout << "남은 포션 수: " << *p_MPPotion << endl;
        }
        else {
            cout << "* 포션이 부족하여 사용할 수 없습니다!" << endl;
        }
        break;

    case 3: // 공격력 UP (2배)
        status[2] *= 2;
        cout << "* 공격력이 2배로 증가되었습니다." << endl;
        cout << "현재 공격력: " << status[2] << endl;
        break;

    case 4: // 방어력 UP (2배)
        status[3] = status[3] + status[3]; // 덧셈을 이용한 2배 구현
        cout << "* 방어력이 2배로 증가되었습니다." << endl;
        cout << "현재 방어력: " << status[3] << endl;
        break;

    case 5: // 현재 능력치 출력
        cout << "* HP : " << status[0] << ", MP : " << status[1]
            << ", 공격력 : " << status[2] << ", 방어력 : " << status[3] << endl;
        break;

    case 6: // Level UP (포션 보충)
        (*p_HPPotion)++;
        (*p_MPPotion)++;
        cout << "* 레벨업! HP/MP 포션이 지급됩니다." << endl;
        cout << "남은 HP/MP 포션 수 : " << *p_HPPotion << "/" << *p_MPPotion << endl;
        break;
    }
}

int main() {
    // 1. 캐릭터 스탯 상자 (배열 선언 및 초기화)
    int status[4] = { 0, 0, 0, 0 }; // 0:HP, 1:MP, 2:공격력, 3:방어력
    int hpPotion = 5, mpPotion = 5;
    int choice;

    // 2. 깐깐한 입력 검사 (HP/MP)
    while (true) {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> status[0] >> status[1];
        if (status[0] > 50 && status[1] > 50) break;
        cout << "* 하나라도 50 이하를 입력하면 안됩니다. 다시 입력해주세요." << endl;
    }

    // 깐깐한 입력 검사 (공격력/방어력)
    while (true) {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> status[2] >> status[3];
        if (status[2] > 0 && status[3] > 0) break;
        cout << "* 하나라도 0 이하를 입력하면 안됩니다. 다시 입력해주세요." << endl;
    }

    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;

    // 3. 메뉴판 무한 루프
    while (true) {
        cout << "=============================================" << endl;
        cout << "<스탯 관리 시스템>" << endl;
        cout << "1. HP UP\n2. MP UP\n3. 공격력 UP\n4. 방어력 UP\n5. 현재 능력치\n6. Level UP\n0. 나가기" << endl;
        cout << "번호를 선택해주세요: ";
        cin >> choice;

        if (choice == 0) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else if (choice >= 1 && choice <= 6) {
            setPotion(choice, &hpPotion, &mpPotion, status);
        }
        else {
            cout << "* 잘못된 번호입니다. 다시 선택해주세요." << endl;
        }
    }

    return 0;
}
