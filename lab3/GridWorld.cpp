#include <iostream>
#include <cctype> // for touppper()
using namespace std;


class Player {
    public:
    bool alive;
    char input;
    int x;
    int y;
    
    Player() {
        alive = true;
        x = 2;
        y = 2;
    }

    void move_north() {
        y--;
    }
    void move_east() {
        x++;
    }
    void move_south() {
        y++;
    }
    void move_west() {
        x--;
    }
};
class World {
    public:
    bool win;
    bool quit;
    Player player;
    char map[5][5];

    World() {
    win = false;
    quit = false;
    player = Player();
    //'#' - used as wall which player can't move through
    //'D' - Pit
    //'#' - Goal
    map[0][0] = '#';
	map[0][1] = '#';
	map[0][2] = '#';
	map[0][3] = '#';
	map[0][4] = '#';

    map[1][0] = '#';
	map[1][1] = 'G';
	map[1][2] = ' ';
	map[1][3] = 'D';
	map[1][4] = '#';

    map[2][0] = '#';
	map[2][1] = ' ';
	map[2][2] = ' ';
	map[2][3] = ' ';
	map[2][4] = '#';

    map[3][0] = '#';
	map[3][1] = ' ';
	map[3][2] = ' ';
	map[3][3] = 'D';
	map[3][4] = '#';

    map[4][0] = '#';
	map[4][1] = '#';
	map[4][2] = '#';
	map[4][3] = '#';
	map[4][4] = '#';
    }

    void Update() {
        if (toupper(player.input) == 'Q') {
            quit = true;
        }
        if (player.alive && !win) {
            if (map[player.x][player.y] == 'G') {
                win = true;
                cout << "You Win";
            }
            else if (map[player.x][player.y] == 'D') {
                player.alive = false;
                cout << "You've fallen down a pit \n You've died !!!!";
            }
            else if ((player.input != ' ') && (toupper(player.input) != 'Q')) {
                cout << "You can move";

                if (map[player.y - 1][player.x] != '#')
                    cout << " N";
                if (map[player.y + 1][player.x] != '#')
                    cout << " S";
                if (map[player.y][player.x + 1] != '#')
                    cout << " E";
                if (map[player.y][player.x - 1] != '#')
                    cout << " W";

                cout << ">>> ";
                player.input = ' ';
            }
        }
		
    }

};

static World world;


int main() {
    World world = World();
    cout << "Welcome to GridWorld" << endl;
	cout << "Valid commands: N, E, S and W for direction. Q to quit the game." << endl;

    char input = ' ';
    //Game Loop
    while ((toupper(input) != 'Q') && world.player.alive && world.win == false) {
        //Update
        world.Update();
        //User Input
        if (world.player.alive && world.win == false) {
            cin >> input;
            world.player.input = input;
            if (toupper(input) == 'N') {
                if (world.map[world.player.y - 1][world.player.x] != '#') {
                    world.player.move_north();
                }	
            }
            else if (toupper(input) == 'S') {
                if (world.map[world.player.y + 1][world.player.x] != '#') {
                    world.player.move_south();
                }	
            }
            else if (toupper(input) == 'E') {
                if (world.map[world.player.y][world.player.x + 1] != '#') {
                    world.player.move_east();
                }	
            }
            else if (toupper(input) == 'W') {
                if (world.map[world.player.y][world.player.x - 1] != '#') {
                    world.player.move_west();
                }	
        }
        }
    }

    
    
    
    return 0;
}