#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;
char Ceaser(char letter, int number){
    int index = letter;
    int newIndex = 0;
    int step = number;
    do {
        if (step > 26){
            step -= 26;
        } else if(index + step > 122){
            newIndex = 97 + (index + step - 122);
        } else {
            newIndex = index + step;
        }
    } while (newIndex > 122 && newIndex < 97);
    char newLetter = newIndex;
    return newLetter;
}

string Scialata(string phrase, int lines){
    int columns = ((phrase.length() - 1) / lines) + 1;

    char array[columns][lines];

    int iter = 0;
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (iter < phrase.length()) {
                char aux = phrase.at(iter);
                array[i][j] = aux;
            }
            else array[i][j] = ' ';
            iter++;
        }
    }

    string newPhrase;
    int iterNew = 0;
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < lines; ++j) {
            if (iterNew <= phrase.length()) {
                char aux = array[j][i];
                newPhrase += aux;
            }
            iterNew++;
        }
    }

    return newPhrase;
}

char Polybius(char letter){
    int index = 0;
    int letterX = 0;
    int letterY = 0;
    char array[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (index != 9){
                array[i][j] = 97 + index;
                if (letter == array[i][j]){
                    letterX = j;
                    letterY = i;
                }
                index++;
            } else{
                array[i][j] = 97 + index;
                if (letter == array[i][j]){
                    letterX = j;
                    letterY = i;
                }
                index += 2;
            }
        }
    }

    if (letterY == 4){
        return array[letterY][0];
    } else{
        return array[letterY + 1][letterX];
    }

}

int main() {
    cout << Polybius('f') << endl;
    return 0;
}
