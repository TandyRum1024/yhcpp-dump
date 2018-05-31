/*
    열혈CPP 문제 #01-1

    @ MjölkforDunk
*/

#include <iostream>
using namespace std;

/*
    사용자로부터 총 5개의 정수를 입력받아서 그 합을 출력하는 프로그램을 작성해 보시던가...
*/
#define NUM_INPUT 5

int main ()
{
    int sum = 0; // 합계
    int tmp; // TEMP 변수 - cin 의 값을 잠시동안 저장하기 위해 사용됨

    // 반복문을 위해 미리 i 변수 declare
    int i;
    for (i=0; i<5; i++)
    {
        cout << i << " 번째 정수를 입력해 주세요 : ";
        cin >> tmp;
        sum += tmp;
    }

    // 결과 출력
    cout << "\n=====================================\n";
    cout << "합계 : " << sum;
    return 0;
}
