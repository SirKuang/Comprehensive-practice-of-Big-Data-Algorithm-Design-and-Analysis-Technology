#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int n, m;
vector<vector <int> > ans; // 存储可以完成任务的卡片

// 辗转相除法求最大公约数
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 深度优先搜索
void dfs(int dep, vector<int> now) {
    if (dep == n + 1) { // 达到终止条件，即卡片选择完成
        int a = now[0], b = m;
        for (int i = 1; i <= n; i++)
            a = gcd(a, now[i]);
        if (a == 1)
            ans.push_back(now); // 卡片满足条件，加入答案列表
        return;
    }
    for (int i = 1; i <= m; i++) {
        now.push_back(i); // 尝试选择第 dep 张卡片
        dfs(dep + 1, now); // 递归进行下一张卡片的选择
        now.pop_back(); // 撤销选择，进行下一种选择
    }
}

int main() {
    cout << "请输入N和M：" << endl;
    cin >> n >> m;

    vector<int> now;
    now.push_back(m); // 初始卡片选择

    dfs(1, now); // 从第一张卡片开始进行选择

    cout << "可以完成任务的卡片数：" ;
    cout << ans.size() << endl;

    cout << "具体的卡片有：" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "(";
        for (int j = 0; j < n; j++)
            cout << ans[i][j + 1] << ","; // 输出每个卡片的数值
        cout << m << ")" << endl;
    }
    return 0;
}

