#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class CryptoSquare {
private:
    string limpiar(string text) {
        string clean;
        for (char c : text) {
            if (isalnum(c)) {
                clean += tolower(c);
            }
        }
        return clean;
    }
public:
    string encode(string plaintext) {
        string clean = limpiar(plaintext);
        int n = clean.size();
        if (n == 0) return "";
        int cols = ceil(sqrt(n));
        int rows = ceil((double)n / cols);
        string result = "";
        for (int c = 0; c < cols; c++) {
            if (c > 0) result += " ";
            for (int r = 0; r < rows; r++) {
                int index = r * cols + c;
                if (index < n) {
                    result += clean[index];
                }
            }
        }
        return result;
    }
};
int main() {
    CryptoSquare cs;
    string plaintext;
    cout << "Enter text to encode: ";
    getline(cin, plaintext);
    string encoded = cs.encode(plaintext);
    cout << "Encoded text: " << encoded << endl;
    return 0;
}