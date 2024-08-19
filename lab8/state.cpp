#include <iostream>
#include <string>
using namespace std;

enum class STATES
{
    MAIN_MENU,
    ABOUT,
    HELP,
    SELECT_ADVENTURE,
    GAME_PLAY,
    NEW_HIGH_SCORE,
    VIEW_HALL_OF_FAME,
    QUIT,
    DONE
};

class State
{
public:
    virtual STATES update() = 0;
    virtual void render() = 0;
};

class About : public State
{
    STATES update() override
    {
        string command;
        getline(std::cin, command);
        while (!(command.empty() || command == "\x1B"))
        {
            cout << "Please enter your command again:/n (press enter or esc)";
            getline(std::cin, command);
        }
        return STATES::MAIN_MENU;
    }
    void render() override
    {
        cout << "Zorkish :: About" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
        cout << "Written By: Narongdech Soontornekajit" << endl;
        cout << endl;
        cout << "Press ESC or Enter to return to the Main Menu" << endl;
    }
};

class Help : public State
{
    STATES update() override
    {
        string command;
        getline(std::cin, command);
        while (!(command.empty() || command == "\x1B"))
        {
            cout << "Please enter your command again:/n (press enter or esc)";
            getline(std::cin, command);
        }
        return STATES::MAIN_MENU;
    }
    void render() override
    {
        cout << "Zorkish :: Help" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
        cout << "The following commands are supported:" << endl;
        cout << endl;
        cout << "\t"
             << "quit" << endl;
        cout << "\t"
             << "go _" << endl;
        cout << "\t"
             << "look at _ (in _) " << endl;
        cout << "\t"
             << "look in _" << endl;
        cout << "\t"
             << "take _ (from _)" << endl;
        cout << "\t"
             << "drop _" << endl;
        cout << "\t"
             << "attack _ (with _)" << endl;
        cout << "Press ESC or Enter to return to the Main Menu" << endl;
    }
};

class Select_Adventure : public State
{
    STATES update() override
    {
        string command;
        getline(std::cin, command);
        while (!(command == "1" || command == "2" || command == "3" || command.empty() || command == "\x1B"))
        {
            cout << "Please enter your command again:/n (valid command: 1, 2, 3, )";
            getline(std::cin, command);
        }
        if ((command == "1") || (command == "2") || (command == "3"))
        {
            return STATES::GAME_PLAY;
        }
        else if (command.empty() || command == "\x1B")
        {
            return STATES::MAIN_MENU;
        }
    }
    void render() override
    {
        cout << "Zorkish :: Select Adventure" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
        cout << "Choose your adventure" << endl;
        cout << endl;
        cout << "\t"
             << "1. Grass World" << endl;
        cout << "\t"
             << "2. Stone World" << endl;
        cout << "\t"
             << "3. Box World" << endl;
        cout << endl;
        cout << "Select 1-3, or press any key to return to the menu: " << endl;
    }
};

class Game_Play : public State
{
    STATES update() override
    {
        string command;
        getline(std::cin, command);
        while (!(command == "quit" || command == "hiscore"))
        {
            cout << "Please enter your command again:/n (valid command: quit, hiscore )";
            getline(std::cin, command);
        }
        if (command == "quit")
        {
            return STATES::MAIN_MENU;
        }
        else if (command == "hiscore")
        {
            return STATES::NEW_HIGH_SCORE;
        }
        return STATES::NEW_HIGH_SCORE;
    }
    void render() override
    {
        cout << "Welcome to Zorkish: Void World\n";
        cout << "This world is simple and pointless. Used it to test Zorkish phase 1 spec.\n";
        cout << ":> quit\n";
        cout << "Your adventure has ended without fame or fortune.\n";
        cout << ":> hiscore\n";
        cout << "You have entered the magic word and will now see the -New High Score- screen.\n";
    }
};

class New_High_Score : public State
{
    STATES update() override
    {
        string command;
        getline(std::cin, command);
        // doesn't take any value or do anythign, just allow user to enter their name for now :)
        return STATES::MAIN_MENU;
    }
    void render() override
    {
        cout << "Zorkish :: New High Score\n";
        cout << "--------------------------------------------------------\n";
        cout << "Congratulations!\n";
        cout << "You have made it to the Zorkish Hall Of Fame\n";
        cout << "Adventure: [the adventure world played]\n";
        cout << "Score: [the player's score]\n";
        cout << "Moves: [number of moves player made]\n";
        cout << "Please type your name and press enter:\n";
        cout << ":> ";
    }
};

class View_Hall_Of_Fame : public State
{
    STATES update() override
    {
        string command;
        getline(std::cin, command);
        while (!(command.empty() || command == "\x1B"))
        {
            cout << "Please enter your command again:/n (press enter or esc)";
            getline(std::cin, command);
        }
        return STATES::MAIN_MENU;
    }
    void render() override
    {
        cout << "Zorkish :: Hall Of Fame" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
        cout << "Top 10 Zorkish Champions" << endl;
        cout << endl;
        cout << "\t"
             << "1. Fred, Mountain World, 5000" << endl;
        cout << "\t"
             << "2. Mary, Mountain World, 4000" << endl;
        cout << "\t"
             << "3. Jow, Water World, 3000" << endl;
        cout << "\t"
             << "4. Henry, Mountain World, 2000" << endl;
        cout << "\t"
             << "5. Susan, Mountain World, 1000" << endl;
        cout << "\t"
             << "6. Alfred, Water World, 900" << endl;
        cout << "\t"
             << "7. Clark, Mountain World, 800" << endl;
        cout << "\t"
             << "8. Harold, Mountain World, 500" << endl;
        cout << "\t"
             << "9. Julie, Water World, 300" << endl;
        cout << "\t"
             << "10. Bill, Box World, -5" << endl;
        cout << endl;
        cout << "Press ESC or Enter to return to the Main Menu" << endl;
    }
};

class MainMenu : public State
{
public:
    STATES update() override
    {
        string command;
        getline(std::cin, command);
        while (!(command == "1" || command == "2" || command == "3" || command == "4" || command == "5"))
        {
            cout << "Please enter your command again:\n";
            getline(std::cin, command);
        }
        if (command == "1")
        {
            return STATES::SELECT_ADVENTURE;
        }
        else if (command == "2")
        {
            return STATES::VIEW_HALL_OF_FAME;
        }
        else if (command == "3")
        {
            return STATES::HELP;
        }
        else if (command == "4")
        {
            return STATES::ABOUT;
        }
        else if (command == "5")
        {
            return STATES::DONE;
        }
        else if (command.empty() || command == "\x1B")
        {
            return STATES::MAIN_MENU;
        }
        else
        {
            return STATES::MAIN_MENU;
        }
    }
    void render() override
    {

        cout << "Zorkish :: Main Menu" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
        cout << "Welcome to Zorkish Adventures" << endl;
        cout << "\t"
             << "1. Select Adventure and Play" << endl;
        cout << "\t"
             << "2. Hall of Fame" << endl;
        cout << "\t"
             << "3. Help" << endl;
        cout << "\t"
             << "4. About" << endl;
        cout << "\t"
             << "5. Quit" << endl;
        cout << endl;
        cout << "Select 1-5: " << endl;
    }
};

class StateManager
{
private:
    MainMenu _main_menu;
    About _about;
    Help _help;
    Select_Adventure _select_adventure;
    Game_Play _game_play;
    New_High_Score _new_high_score;
    View_Hall_Of_Fame _view_hall_of_fame;

    State *_current = &_main_menu;
    STATES _state = STATES::MAIN_MENU;

public:
    bool running() const
    {
        return (_state != STATES::DONE);
    }
    void update()
    {
        if (_state == STATES::ABOUT)
        {
            _current = &_about;
        }
        else if (_state == STATES::HELP)
        {
            _current = &_help;
        }
        else if (_state == STATES::SELECT_ADVENTURE)
        {
            _current = &_select_adventure;
        }
        else if (_state == STATES::VIEW_HALL_OF_FAME)
        {
            _current = &_view_hall_of_fame;
        }
        else if (_state == STATES::GAME_PLAY)
        {
            _current = &_game_play;
        }
        else if (_state == STATES::NEW_HIGH_SCORE)
        {
            _current = &_new_high_score;
        }
        else // if (_state == STATES::MAIN_MENU)
        {
            _current = &_main_menu;
        }
        // for initial debugging
        // std::cout << _current << "from update-------------(U)" << endl;
        _state = _current->update();
    }
    void render()
    {
        if (_state == STATES::ABOUT)
        {
            _current = &_about;
        }
        else if (_state == STATES::HELP)
        {
            _current = &_help;
        }
        else if (_state == STATES::SELECT_ADVENTURE)
        {
            _current = &_select_adventure;
        }
        else if (_state == STATES::VIEW_HALL_OF_FAME)
        {
            _current = &_view_hall_of_fame;
        }
        else if (_state == STATES::GAME_PLAY)
        {
            _current = &_game_play;
        }
        else if (_state == STATES::NEW_HIGH_SCORE)
        {
            _current = &_new_high_score;
        }
        else // if (_state == STATES::MAIN_MENU)
        {
            _current = &_main_menu;
        }
        // for initial debugging
        // std::cout << _current << "from render------------(R)" << endl;
        _current->render();
    }
};

int main()
{
    StateManager manager;
    while (manager.running())
    {
        manager.render();
        manager.update();
    }
    return 0;
}
