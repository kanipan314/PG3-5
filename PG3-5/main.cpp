#include <stdio.h>
#include <iostream>
#include <list>
#include <cstring>

// 駅名の最大長
const int MAX_NAME_LENGTH = 50;

int main() {
    // 山手線の駅のリスト
    std::list<const char*> yamanoteLine = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani",
        "Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka",
        "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku",
        "Yoyogi", "Harajuku", "Shibuya", "Ebisu", "Meguro", "Gotanda",
        "Osaki", "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi",
        "Yurakucho"
    };

    // 順方向に表示
    std::cout << "1970年山手線:\n";
    for (auto it = yamanoteLine.begin(); it != yamanoteLine.end(); it++) {
        std::cout << *it;
        if (std::next(it) != yamanoteLine.end()) {
            std::cout << " <-> ";
        }
    }

    //西日暮里を追加
    auto Nishi_it = std::find_if(yamanoteLine.begin(), yamanoteLine.end(), [](const char* station) {
        return strcmp(station, "Nippori") == 0;
    });
    if (Nishi_it != yamanoteLine.end()) {
        Nishi_it++; //次の位置に移動
        yamanoteLine.insert(Nishi_it, "Nishi-Nippori");
    }

    // 順方向に表示
    std::cout << "\n2019年山手線:\n";
    for (auto it = yamanoteLine.begin(); it != yamanoteLine.end(); it++) {
        std::cout << *it;
        if (std::next(it) != yamanoteLine.end()) {
            std::cout << " <-> ";
        }
    }

    //高輪ゲートウェイを追加
    auto it = std::find_if(yamanoteLine.begin(), yamanoteLine.end(), [](const char* station) {
        return strcmp(station, "Shinagawa") == 0;
        });
    if (it != yamanoteLine.end()) {
        ++it; // 品川の次の位置に移動
        yamanoteLine.insert(it, "Takanawa Gateway");
    }

    // 順方向に表示
    std::cout << "2022年山手線:\n";
    for (auto it = yamanoteLine.begin(); it != yamanoteLine.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != yamanoteLine.end()) {
            std::cout << " <-> ";
        }
    }
    std::cout << std::endl;


    return 0;
}