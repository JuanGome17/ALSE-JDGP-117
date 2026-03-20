#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Spreadsheet {
private:
    vector<vector<int>> grid;
    int getCellValue(string s) {
        if (isdigit(s[0])) return stoi(s);
        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;
        return grid[row][col];
    }
public:
    Spreadsheet(int filas) {
        grid = vector<vector<int>>(filas, vector<int>(26, 0));
    }
    void setCell(string celda, int valor) {
        int col = celda[0] - 'A';
        int row = stoi(celda.substr(1)) - 1;
        grid[row][col] = valor;
    }
    void resetCell(string celda) {
        int col = celda[0] - 'A';
        int row = stoi(celda.substr(1)) - 1;
        grid[row][col] = 0;
    }
    int getValue(string formula) {
        if (formula[0] != '=') {
        return getCellValue(formula);
    }
    formula = formula.substr(1);
    int pos = formula.find('+');
    string left = formula.substr(0, pos);
    string right = formula.substr(pos + 1);
    return getCellValue(left) + getCellValue(right);
    }
};
int main() {
    Spreadsheet sheet(3);
    sheet.setCell("A1", 5);
    sheet.setCell("B1", 10);
    cout << "Valor de A1: " << sheet.getValue("A1") << endl;
    cout << "Valor de B1: " << sheet.getValue("B1") << endl;
    cout << "Valor de A1+B1: " << sheet.getValue("=A1+B1") << endl;
    sheet.resetCell("A1");
    cout << "Valor de A1 despues de reset: " << sheet.getValue("A1") << endl;
    return 0;
}