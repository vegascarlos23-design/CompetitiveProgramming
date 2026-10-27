#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<string> canvas;

void drawSierpinski(int level, int x, int y, int size) {
    if (level == 1) {
        canvas[y][x] = '/';
        canvas[y][x + 1] = '\\';
        canvas[y + 1][x - 1] = '/';
        canvas[y + 1][x] = '_';
        canvas[y + 1][x + 1] = '_';
        canvas[y + 1][x + 2] = '\\';
    } else {
        int newSize = size / 2;
        drawSierpinski(level - 1, x, y, newSize);
        drawSierpinski(level - 1, x - newSize, y + newSize, newSize);
        drawSierpinski(level - 1, x + newSize, y + newSize, newSize);
    }
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int size = 1ll<<n;  
        int width = size*2;
        int height = size;
        
        canvas.clear();
        canvas.resize(height, string(width, ' '));
        
        drawSierpinski(n, size - 1, 0, size);
        
        for (int i = 0; i < height; i++) {
            string line = canvas[i];
            int end = line.find_last_not_of(' ');
            if (end != string::npos) {
                cout << line.substr(0, end + 1) << endl;
            } else {
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}