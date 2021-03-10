#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void getWordsFromLine(string word, int index, vector<string> &memory) {
    string newWord;
    for (int i = index; i < word.length(); i++) {
        if (word[i] == ')' || word[i] == '(' || word[i] == '.' || word[i] == ',' || word[i] == '=' || word[i] == '?' || word[i] == '!') {
            i++;
            getWordsFromLine(word, i, memory);
            break;
        }
        else {
            newWord += word[i];
        }
    }
    memory.push_back(newWord);
}

int main() {
    int ok;
    do
    {
    ifstream input;
    ofstream output;
    string word, line;
    char startOfWord;
    char symbol;

    cout << "I wanna find words starting with symbol: \n";

    cin >> startOfWord;

    int lineNumber = 0;

    input.open("f.txt");
    output.open("f1.txt");

    while (getline(input, line)) {
        ++lineNumber;
        istringstream iss(line);
        while (iss >> word) {
            if (word.length() > 40) {
                continue;
            }
            vector<string> words;
            getWordsFromLine(word, 0, words);
            for (int i = 0; i < words.size(); i++) {
                if (words[i][0] == startOfWord) {
                    output << words[i] << ' ' << lineNumber << '\n';
                }
            }
        }
    }

    input.close();
    output.close();
    cout<<"Continue (1) / Stop (0)"<<endl;
    cin>>ok;
    } while (ok==1);
    return 0;
}
