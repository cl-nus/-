// dfs with stack, no use of recursion
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

struct Room {
	int r, c;
	Room(int rr, int cc): r(rr),c(cc) {}
};

void dfs(int r, int c) {
	stack<Room> s;
	s.push(Room(r,c));
	while(!s.empty()) {
		Room room = s.top();
		int i = room.r;
		int j = room.c;
		if(color[i][j])
			s.pop();
		else {
			roomArea++;
			color[i][j] = roomNum;
			if((rooms[i][j] & 1) == 0) // west 
				s.push(Room(i,j-1));
			if((rooms[i][j] & 2) == 0) // north
				s.push(Room(i-1,j)); 
			if((rooms[i][j] & 4) == 0) // east
				s.push(Room(i,j+1));
			if((rooms[i][j] & 8) == 0) // south
				s.push(Room(i+1,j));
		}
	}
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