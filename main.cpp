#include "game.h"

int main()
{
    std::cout << "Welcome to Impasse!\n\nFor game rules enter 'howto' or visit: https://www.marksteeregames.com/Impasse_rules.pdf\n\nEngine and AI implemented by: Balazs Horvath (https://bghorvath.dev)" << std::endl;
    bool play = true;
    while (play)
    {
        // if savegame is available from previous session, ask if user wants to continue
        std::string answer;
        std::ofstream newfile;
        newfile.open(".savegame", std::ios::in);
        if (newfile.is_open())
        {
            std::cout << "Do you want to load the last saved game? (yes/no): ";
            std::cin >> answer;
            if (answer == "yes")
            {
                Game game = Game();
            }
            else
            {
                // otherwise start a new game
                goto newgame;
            }
        }
        else
        {
        newgame:
            int player = 0;
            // ask to choose player and time limit
            while (player == 0)
            {
                std::cout << "Choose your color (white/black): ";
                std::cin >> answer;
                if (answer == "white")
                {
                    player = 1;
                }
                else if (answer == "black")
                {
                    player = -1;
                }
                else
                {
                    std::cout << "Invalid answer" << std::endl;
                };
            };
            int timemin = 10;
            std::cout << "Choose time limit per player (minutes): ";
            std::cin >> answer;
            try
            {
                timemin = std::stoi(answer);
            }
            catch (const std::exception &e)
            {
                std::cout << "Invalid answer, defaulting to 10 minutes" << std::endl;
            };
            Game game = Game(player, timemin);
        };
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Would you like to play again? (yes/no): ";
        std::cin >> answer;
        play = answer == "yes";
    };
    std::cout << "Thank you for playing!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    return 0;
}