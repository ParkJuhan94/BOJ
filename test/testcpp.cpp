#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct A {
    int data; // ���Ұ�
    int pos;  // ���Ұ� ��ġ�� �ε���
};

int main() {
    /* cin, cout ����� �ӵ� ��� */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    deque<A> dq;
    for (int i = 0; i < N; ++i) {
        if (!dq.empty() && i == dq.front().pos + L) // ���� Ÿ�̹��� �� ģ���� �տ��� ������������ �������ش�. pop_front()
            dq.pop_front();
        while (!dq.empty() && dq.back().data > arr[i]) // arr[i] �� ������ �����ν� arr[i]���� Ŀ�� ������ �ּҰ� �� ���� ���� ���� ���� deque ���� ���ҵ��� �������ش�. pop_back()
            dq.pop_back();
        dq.push_back({ arr[i], i }); // arr[i] �� �߰��Ѵ�. (�� pop_back()���� ���Ͽ� arr[i]���� �� ū�� �� ���������Ƿ� �������� ������ ������ ä�� �ڿ� �߰��ǰ� �ȴ�.)
        cout << dq.front().data << " "; // deque �� �Ǿ� ���Ҹ� ����ϸ� �װ� �ٷ� ���� ����(i-L+1 ~ i)������ �ּҰ� 
    }
}