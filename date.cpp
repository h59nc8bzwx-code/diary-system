#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    system("mkdir diary"); // フォルダ作成（なければ）

    cout << "日付を入力してください。(例：2025-06-12)" << endl;
    string date;
    getline(cin, date);

    cout << "日記を書いてください。終了するには空行を入力してください。" << endl;
    string line, diary;
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        diary += line + "\n";
    }

    ofstream file("diary/" + date + ".txt");
    if (file.is_open()) {
        file << diary;
        file.close();
        cout << "日記を diary/" << date << ".txt に保存しました。" << endl;
    } else {
        cout << "ファイルを保存できませんでした。" << endl;
    }

    return 0;
}
