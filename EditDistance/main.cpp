#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int minDistance(const string& word1, const string& word2);

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;
    return 0;
}

int minDistance(const string& word1, const string& word2) {
    auto matrix = new int*[word1.size() + 1];
    for(int i = 0; i <= word1.size(); ++i) {
        matrix[i] = new int[word2.size() + 1];
        memset(matrix[i], 0, sizeof(int)*(word2.size() + 1));
    }
    for(int i = 0; i <= word2.size(); ++i)
        matrix[0][i] = i;
    for(int i = 0; i <= word1.size(); ++i)
        matrix[i][0] = i;

    for(int i = 1; i <= word1.size(); ++i) {
        for(int j = 1; j <= word2.size(); ++j) {
            if(word1[i - 1] == word2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];
            else
                matrix[i][j] = 1 + min(matrix[i - 1][j - 1],
                        min(matrix[i - 1][j], matrix[i][j - 1]));
        }
    }
    return matrix[word1.size()][word2.size()];
}