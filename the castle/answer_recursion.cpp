#include <algorithm>
#include <stack>
#include <cstring>
#include <iostream>

using namespace std;

int r, c;
int rooms[50][50];
int color[50][50];

int maxRoomArea = 0, roomNum = 0;
int roomArea;

void dfs(int i, int j) {
	// visited room (i,j)
	if(color[i][j])
		return;
	roomArea++;
	color[i][j] = roomNum;
	if((rooms[i][j] & 1) == 0) // west 
		dfs(i,j-1);
	if((rooms[i][j] & 2) == 0) // north
		dfs(i-1,j); 
	if((rooms[i][j] & 4) == 0) // east
		dfs(i,j+1);
	if((rooms[i][j] & 8) == 0) // south
		dfs(i+1,j);
}

int main()
{
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> rooms[i][j];
    // initialize color
    memset(color, 0, sizeof(color));

    for(int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (!color[i][j]) {
                roomNum++;
                roomArea = 0;
                dfs(i, j);
                if (roomArea > maxRoomArea)
                    maxRoomArea = roomArea;
            }
    cout << roomNum << endl;
    cout << maxRoomArea << endl;
}