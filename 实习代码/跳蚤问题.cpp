#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int n, m;
vector<vector <int> > ans; // �洢�����������Ŀ�Ƭ

// շת����������Լ��
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// �����������
void dfs(int dep, vector<int> now) {
    if (dep == n + 1) { // �ﵽ��ֹ����������Ƭѡ�����
        int a = now[0], b = m;
        for (int i = 1; i <= n; i++)
            a = gcd(a, now[i]);
        if (a == 1)
            ans.push_back(now); // ��Ƭ����������������б�
        return;
    }
    for (int i = 1; i <= m; i++) {
        now.push_back(i); // ����ѡ��� dep �ſ�Ƭ
        dfs(dep + 1, now); // �ݹ������һ�ſ�Ƭ��ѡ��
        now.pop_back(); // ����ѡ�񣬽�����һ��ѡ��
    }
}

int main() {
    cout << "������N��M��" << endl;
    cin >> n >> m;

    vector<int> now;
    now.push_back(m); // ��ʼ��Ƭѡ��

    dfs(1, now); // �ӵ�һ�ſ�Ƭ��ʼ����ѡ��

    cout << "�����������Ŀ�Ƭ����" ;
    cout << ans.size() << endl;

    cout << "����Ŀ�Ƭ�У�" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "(";
        for (int j = 0; j < n; j++)
            cout << ans[i][j + 1] << ","; // ���ÿ����Ƭ����ֵ
        cout << m << ")" << endl;
    }
    return 0;
}

