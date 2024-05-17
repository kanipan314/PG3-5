#include <stdio.h>
#include <iostream>
#include <list>
#include <cstring>

// �w���̍ő咷
const int MAX_NAME_LENGTH = 50;

int main() {
    // �R����̉w�̃��X�g
    std::list<const char*> yamanoteLine = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani",
        "Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka",
        "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku",
        "Yoyogi", "Harajuku", "Shibuya", "Ebisu", "Meguro", "Gotanda",
        "Osaki", "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi",
        "Yurakucho"
    };

    // �������ɕ\��
    std::cout << "1970�N�R���:\n";
    for (auto it = yamanoteLine.begin(); it != yamanoteLine.end(); it++) {
        std::cout << *it;
        if (std::next(it) != yamanoteLine.end()) {
            std::cout << " <-> ";
        }
    }

    //�����闢��ǉ�
    auto Nishi_it = std::find_if(yamanoteLine.begin(), yamanoteLine.end(), [](const char* station) {
        return strcmp(station, "Nippori") == 0;
    });
    if (Nishi_it != yamanoteLine.end()) {
        Nishi_it++; //���̈ʒu�Ɉړ�
        yamanoteLine.insert(Nishi_it, "Nishi-Nippori");
    }

    // �������ɕ\��
    std::cout << "\n2019�N�R���:\n";
    for (auto it = yamanoteLine.begin(); it != yamanoteLine.end(); it++) {
        std::cout << *it;
        if (std::next(it) != yamanoteLine.end()) {
            std::cout << " <-> ";
        }
    }

    //���փQ�[�g�E�F�C��ǉ�
    auto it = std::find_if(yamanoteLine.begin(), yamanoteLine.end(), [](const char* station) {
        return strcmp(station, "Shinagawa") == 0;
        });
    if (it != yamanoteLine.end()) {
        ++it; // �i��̎��̈ʒu�Ɉړ�
        yamanoteLine.insert(it, "Takanawa Gateway");
    }

    // �������ɕ\��
    std::cout << "2022�N�R���:\n";
    for (auto it = yamanoteLine.begin(); it != yamanoteLine.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != yamanoteLine.end()) {
            std::cout << " <-> ";
        }
    }
    std::cout << std::endl;


    return 0;
}