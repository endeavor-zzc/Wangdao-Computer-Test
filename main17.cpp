//
// Created by endeavor on 2023/7/28.
//
/**
* 代理服务器
 *  使用代理服务器能够在一定程度上隐藏客户端信息，从而保护用户在互联网上的隐私。我们知道n个代理服务器的IP地址
 *  现在要用它们去访问m个服务器。这 m 个服务器的 IP 地址和访问顺序也已经给出
 *  系统在同一时刻只能使用一个代理服务器，并要求不能用代理服务器去访问和它 IP地址相同的服务器（不然客户端信息很有可能就会被泄露）
 *  在这样的条件下，找到一种使用代理服务器的方案，使得代理服务器切换的次数尽可能得少。
 * 输入描述：
 * 每个测试数据包括 n + m + 2 行。     第 1 行只包含一个整数 n，表示代理服务器的个数。
 * 第 2行至第n + 1行每行是一个字符串，表示代理服务器的 IP地址。这n个 IP地址两两不相同。
 * 第 n + 2 行只包含一个整数 m，表示要访问的服务器的个数。
 * 第 n + 3 行至第 n + m + 2 行每行是一个字符串，表示要访问的服务器的 IP 地址，按照访问的顺序给出。
 * 每个字符串都是合法的IP地址，形式为“xxx.yyy.zzz.www”，其中任何一部分均是0–255之间的整数。输入数据的任何一行都不包含空格字符。
 * 其中，1<=n<=1000，1<=m<=5000。
 * 输出描述：
 * 可能有多组测试数据，对于每组输入数据， 输出数据只有一行，包含一个整数s，表示按照要求访问服务器的过程中切换代理服务器
 * 的最少次数。第一次使用的代理服务器不计入切换次数中。若没有符合要求的安排方式，则输出-1。
 * 示例1
 * 输入：
 * 3
 * 166.111.4.100
 * 162.105.131.113
 * 202.112.128.69
 * 6
 * 72.14.235.104
 * 166.111.4.100
 * 207.46.19.190
 * 202.112.128.69
 * 162.105.131.113
 * 118.214.226.52
 * 输出：
 * 1
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main(){
    int n, m;
    string ip;
    vector<string> proxy;
    vector<string> server;
    while(cin >> n){
        for (int i = 0; i < n; ++i) {
            cin >> ip;
            proxy.push_back(ip);
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> ip;
            server.push_back(ip);
        }
        //输入信息完毕
        int flag = 1, count = 0, index = 0;
        while(flag && index < m){
            int max = 0;
            for (int i = 0; i < n; ++i) {
                int j = index;
                while((server[j] != proxy[i]) && j < m){
                    j++;
                }
                if (j -index > max){
                    max = j - index;
                }
            }
            if (max == 0)
                flag = 0;
            count++;
            index += max;
        }
        if (flag){
            cout << count - 1 << endl;
        } else
            cout << "-1" << endl;
    }
    return 0;
}