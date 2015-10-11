#include <iostream>
#include <algorithm>
using namespace std;

struct Plant
{
    int x, y;
    bool operator< (const Plant& p2) const { // binary_search 3rd argument const T& val
        if (x == p2.x)
            return y < p2.y;
        return x < p2.x;
    }
};

int r, c, n;
Plant plants[5000];

int searchPath(const Plant secPlant, const int dx, const int dy){
    Plant tmpPlant;
    int steps = 2;
    tmpPlant.x = secPlant.x + dx;
    tmpPlant.y = secPlant.y + dy;
    while( (tmpPlant.x <= r) && (tmpPlant.y >= 1 ) && (tmpPlant.y <= c) ) {
        if (!binary_search(plants, plants + n, tmpPlant)) {
            //每一步都必须踩倒水稻才算合理, 否则这就不是一条行走路径
            steps = 0;
            break;
        }
        steps++;

        
        // cout << tmpPlant.x << "," << tmpPlant.y << endl;

        tmpPlant.x += dx;
        tmpPlant.y += dy;
    }
    return steps;
}

int main()
{
    int dx, dy, px, py, max = 2, steps;
    cin >> r >> c;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> plants[i].x >> plants[i].y;
    sort(plants, plants + n);

    for (int i = 0; i < n-2; i++)
        for (int j = i+1; j < n-1; j++) {
            dx = plants[j].x - plants[i].x;
            dy = plants[j].y - plants[i].y;
            px = plants[i].x - dx;
            py = plants[i].y - dy;
            if ( (px>=1) && (py>=1) && (py<=c))
                continue;
            if (plants[i].x + (max-1)*dx > r)
                break;
            py = plants[i].y + (max-1)*dy;
            if ( (py<1) || (py>c) )
                continue;
            
            steps = searchPath(plants[j], dx, dy);

            if (steps > max)
                max = steps;
        }
    if (max == 2)
        max = 0;
    cout << max << endl;
    return 0;
}