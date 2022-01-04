#include <iostream>
#include<sstream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <SFML/Window.hpp> 
#include <ctime>
#include <cstdlib>
using namespace std;
using namespace sf;
//void initialize() {
//    //Sprite RedCandy, Sprite BlueCandy, Sprite GreenCandy, Sprite YellowCandy, Sprite PurpleCandy, Sprite OrangeCandy, Sprite StripedRedCandy, Sprite StripedBlueCandy, Sprite StripedGreenCandy, Sprite StripedYellowCandy, Sprite StripedPurpleCandy, Sprite StripedOrangeCandy, Sprite WrappedRedCandy, Sprite WrappedBlueCandy, Sprite WrappedGreenCandy, Sprite WrappedYellowCandy, Sprite WrappedPurpleCandy, Sprite WrappedOrangeCandy, Sprite ColorBomb   
//}

//current errors
//sideways T doesn't work for rule 3
int main() {
    bool allcrush = false;
    bool colorbombSwapped = false;
    bool colorbombclear = false;
    bool colorbombxstriped = false;
    bool colorbombxwrapped = false;
    bool plainxwrapped = false;
    bool stripedxwrapped = false;
    bool wrappedxwrapped = false;
    bool continueFlag = false;
    int swap[2];
    int colorbombSwap = 0;
    int grid[9][9];
    bool loadingScreenFlag = true, startGameFlag = false;
    int clickedx[2];
    int clickedy[2];
    Text score, moves, target, scoreCount, moveCount;
    Text New, Continue;
    
    RenderWindow window(VideoMode(800, 600), "Candy Crush");
    Font font;
    if (!font.loadFromFile("Candice.ttf"))
    {
        cout << "Cant find text";
    }

    int onetwo = 0;
    int total = 0, move = 20;

    Texture redCandy;
    if (!redCandy.loadFromFile("Candies/Red-0.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite RedCandy;
    RedCandy.setTexture(redCandy);
    Texture blueCandy;
    if (!blueCandy.loadFromFile("Candies/Blue-0.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite BlueCandy;
    BlueCandy.setTexture(blueCandy);
    Texture greenCandy;
    if (!greenCandy.loadFromFile("Candies/Green-0.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite GreenCandy;
    GreenCandy.setTexture(greenCandy);
    Texture yellowCandy;
    if (!yellowCandy.loadFromFile("Candies/Yellow-0.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite YellowCandy;
    YellowCandy.setTexture(yellowCandy);
    Texture purpleCandy;
    if (!purpleCandy.loadFromFile("Candies/Purple-0.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite PurpleCandy;
    PurpleCandy.setTexture(purpleCandy);
    Texture orangeCandy;
    if (!orangeCandy.loadFromFile("Candies/Orange-0.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite OrangeCandy;
    OrangeCandy.setTexture(orangeCandy);
    Texture stripedredCandy;
    if (!stripedredCandy.loadFromFile("Candies/Striped_red.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite StripedRedCandy;
    StripedRedCandy.setTexture(stripedredCandy);
    Texture stripedblueCandy;
    if (!stripedblueCandy.loadFromFile("Candies/Striped_blue.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite StripedBlueCandy;
    StripedBlueCandy.setTexture(stripedblueCandy);
    Texture stripedgreenCandy;
    if (!stripedgreenCandy.loadFromFile("Candies/Striped_green.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite StripedGreenCandy;
    StripedGreenCandy.setTexture(stripedgreenCandy);
    Texture stripedyellowCandy;
    if (!stripedyellowCandy.loadFromFile("Candies/Striped_yellow.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite StripedYellowCandy;
    StripedYellowCandy.setTexture(stripedyellowCandy);
    Texture stripedpurpleCandy;
    if (!stripedpurpleCandy.loadFromFile("Candies/Striped_purple.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite StripedPurpleCandy;
    StripedPurpleCandy.setTexture(stripedpurpleCandy);
    Texture stripedorangeCandy;
    if (!stripedorangeCandy.loadFromFile("Candies/Striped_orange.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite StripedOrangeCandy;
    StripedOrangeCandy.setTexture(stripedorangeCandy);
    Texture wrappedredCandy;
    if (!wrappedredCandy.loadFromFile("Candies/Wrapped_red.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite WrappedRedCandy;
    WrappedRedCandy.setTexture(wrappedredCandy);
    Texture wrappedblueCandy;
    if (!wrappedblueCandy.loadFromFile("Candies/Wrapped_blue.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite WrappedBlueCandy;
    WrappedBlueCandy.setTexture(wrappedblueCandy);
    Texture wrappedgreenCandy;
    if (!wrappedgreenCandy.loadFromFile("Candies/Wrapped_green.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite WrappedGreenCandy;
    WrappedGreenCandy.setTexture(wrappedgreenCandy);
    Texture wrappedyellowCandy;
    if (!wrappedyellowCandy.loadFromFile("Candies/Wrapped_yellow.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite WrappedYellowCandy;
    WrappedYellowCandy.setTexture(wrappedyellowCandy);
    Texture wrappedpurpleCandy;
    if (!wrappedpurpleCandy.loadFromFile("Candies/Wrapped_purple.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite WrappedPurpleCandy;
    WrappedPurpleCandy.setTexture(wrappedpurpleCandy);
    Texture wrappedorangeCandy;
    if (!wrappedorangeCandy.loadFromFile("Candies/Wrapped_orange.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite WrappedOrangeCandy;
    WrappedOrangeCandy.setTexture(wrappedorangeCandy);
    Texture colorBomb;
    if (!colorBomb.loadFromFile("Candies/ColourBomb.png"))
    {
        cout << "Error cannot load red candy";
    }
    Sprite ColorBomb;
    ColorBomb.setTexture(colorBomb);

    Texture loadingscreen;
    if (!loadingscreen.loadFromFile("candycrush.bmp"))
    {
        cout << "image doesn't load";
    }
    Sprite LoadingScreen;
    LoadingScreen.setTexture(loadingscreen);
    
    window.display();
    while (window.isOpen()) {
        Event e;


        while (window.pollEvent(e))
        {
            if (loadingScreenFlag == true) {
               
                window.draw(LoadingScreen);



                


                New.setFont(font);
                New.setString("Click here to Start New Game");
                New.setCharacterSize(34);
                New.setFillColor(Color::Black);
                New.setStyle(Text::Bold | Text::Underlined);
                New.setPosition(150.f, 300.f);
                Continue.setFont(font);
                Continue.setString("Click here to Continue");
                Continue.setCharacterSize(34);
                Continue.setFillColor(Color::Black);
                Continue.setStyle(Text::Bold | Text::Underlined);
                Continue.setPosition(150.f, 400.f);
                window.draw(New);
                window.draw(Continue);

            }
            // "close requested" event: we close the window
            if (e.type == e.Closed) {
                ofstream fout;
                fout.open("CandyState.txt");
                fout << total << " " << move;
                fout << endl;
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        fout << grid[i][j] << " ";
                    }
                    fout << endl;
                }
                fout.close();
                window.close();
            }
            if (e.type == Event::MouseButtonPressed && loadingScreenFlag == true)
            {

                if (e.mouseButton.x > 150.f && e.mouseButton.x < 400.f && e.mouseButton.y>400.f && e.mouseButton.y < 450.f)
                {
                    ifstream fin;

                    fin.open("CandyState.txt");
                    if (!fin) {
                        //no save file found
                        Text noSave;

                        noSave.setFont(font);
                        noSave.setString("Sorry. No Save file Found!");
                        noSave.setCharacterSize(34);
                        noSave.setFillColor(Color::Black);
                        noSave.setStyle(Text::Bold | Text::Underlined);
                        noSave.setPosition(150.f, 200.f);
                        loadingScreenFlag = true;
                        window.draw(noSave);
                    }
                    else {
                        fin >> total >> move;
                        for (int i = 0; i < 9; i++) {
                            for (int j = 0; j < 9; j++) {
                                fin >> grid[i][j];
                            }

                        }
                        startGameFlag = true;
                        loadingScreenFlag = false;
                    }
                    fin.close();

                }

            }
            //new game
            if (e.type == Event::MouseButtonPressed && loadingScreenFlag == true)
            {

                if (e.mouseButton.x > 150.f && e.mouseButton.x < 400.f && e.mouseButton.y>300.f && e.mouseButton.y < 350.f)
                {
                    srand((unsigned int)time(NULL));
                    int candytype;
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            candytype = (unsigned int)rand() % 6;
                            switch (candytype) {

                            case 0: {
                                RedCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                                window.draw(RedCandy);
                                grid[i][j] = 0;
                                break;
                            }
                            case 1: {
                                BlueCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                                window.draw(BlueCandy);
                                grid[i][j] = 1;
                                break;
                            }
                            case 2: {
                                GreenCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                                window.draw(GreenCandy);
                                grid[i][j] = 2;
                                break;
                            }
                            case 3: {
                                YellowCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                                window.draw(YellowCandy);
                                grid[i][j] = 3;
                                break;
                            }
                            case 4: {
                                PurpleCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                                window.draw(PurpleCandy);
                                grid[i][j] = 4;
                                break;
                            }
                            case 5: {
                                OrangeCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                                window.draw(OrangeCandy);
                                grid[i][j] = 5;
                                break;
                            }

                            }

                        }
                    }
                    loadingScreenFlag = false;


                }
            }
            srand((unsigned int)time(NULL));
            //game conditions
            if (startGameFlag) {
                if (move == 0 && total < 5000) {


                    Text lost;


                    lost.setFont(font);
                    lost.setString("Sorry. lost!");
                    lost.setCharacterSize(60);
                    lost.setFillColor(Color::Black);
                    lost.setStyle(Text::Bold | Text::Underlined);
                    lost.setPosition(250.f, 300.f);
                    startGameFlag = false;
                    loadingScreenFlag = true;
                    window.draw(lost);

                }
                if (total >= 5000 && move==0) {

                    Text won;


                    won.setFont(font);
                    won.setString("You won!");
                    won.setCharacterSize(60);
                    won.setFillColor(Color::Black);
                    won.setStyle(Text::Bold | Text::Underlined);
                    won.setPosition(250.f, 300.f);
                    startGameFlag = false;
                    loadingScreenFlag = true;
                    window.draw(won);

                }


                //special case
                if (allcrush) {
                    sleep(milliseconds(2000));
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            
                            if (grid[i][j] == 0)
                                total = total + 30;
                            else if (grid[i][j] == 1)
                                total = total + 30;
                            else if (grid[i][j] == 2)
                                total = total + 40;
                            else if (grid[i][j] == 3)
                                total = total + 30;
                            else if (grid[i][j] == 5)
                                total = total + 60;
                            grid[i][j] = (unsigned int)rand() % 6;
                        }
                    }
                    allcrush = false;
                }
                //rule 12 implementation
                if (wrappedxwrapped) {
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (swap[0] == 8)
                                swap[0] -= 2;
                            if (swap[1] == 8)
                                swap[1] -= 2;
                            if ((i > swap[0] - 3 && i < swap[0] + 3) && (j > swap[1] - 3 && j < swap[1] + 3)) {
                                int n = j - 3;
                                int k = j + 2;
                                while (n >= 0) {
                                    if (grid[i][k] == 0)
                                        total = total + 30;
                                    else if (grid[i][k] == 1)
                                        total = total + 30;
                                    else if (grid[i][k] == 2)
                                        total = total + 40;
                                    else if (grid[i][k] == 3)
                                        total = total + 30;
                                    else if (grid[i][k] == 5)
                                        total = total + 60;
                                    grid[i][k] = grid[i][n];
                                    n--;
                                    k--;
                                }
                                while (k >= 0) {
                                    grid[i][k] = (unsigned int)rand() % 6;
                                    k--;
                                }
                            }
                        }
                    }
                    wrappedxwrapped = false;
                }



                //rule 11 implementation
                if (stripedxwrapped) {
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (swap[0] == 8)
                                swap[0]--;
                            if (i == swap[0] - 1 || i == swap[0] || i == swap[0] + 1) {
                                for (int k = 0; k < 9; k++) {
                                    if (grid[i][k] == 0)
                                        total = total + 30;
                                    else if (grid[i][k] == 1)
                                        total = total + 30;
                                    else if (grid[i][k] == 2)
                                        total = total + 40;
                                    else if (grid[i][k] == 3)
                                        total = total + 30;
                                    else if (grid[i][k] == 5)
                                        total = total + 60;
                                    grid[i][k] = (unsigned int)rand() % 6;
                                }
                            }
                            if (swap[1] == 8)
                                swap[1]--;
                            if (j == swap[1] - 1 || j == swap[1] || j == swap[1] + 1) {
                                for (int k = 0; k < 9; k++) {
                                    if (grid[i][k] == 0)
                                        total = total + 30;
                                    else if (grid[i][k] == 1)
                                        total = total + 30;
                                    else if (grid[i][k] == 2)
                                        total = total + 40;
                                    else if (grid[i][k] == 3)
                                        total = total + 30;
                                    else if (grid[i][k] == 5)
                                        total = total + 60;
                                    grid[k][j] = (unsigned int)rand() % 6;
                                }
                            }
                        }
                    }
                    stripedxwrapped = false;
                }


                //rule 10 implementation
                if (colorbombxwrapped) {
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (grid[i][j] < 6) {
                                grid[i][j] = grid[i][j] + 12;

                            }

                        }
                    }
                    colorbombxwrapped = false;
                    allcrush = true;
                }



                //rule 9 implementation
                if (colorbombxstriped) {
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (grid[i][j] < 6) {
                                grid[i][j] = grid[i][j] + 6;
                            }

                        }
                    }
                    colorbombxstriped = false;
                    allcrush = true;

                }



                //rule 8 implementation
                if (colorbombclear) {
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (grid[i][j] == 0)
                                total = total + 30;
                            else if (grid[i][j] == 1)
                                total = total + 30;
                            else if (grid[i][j] == 2)
                                total = total + 40;
                            else if (grid[i][j] == 3)
                                total = total + 30;
                            else if (grid[i][j] == 5)
                                total = total + 60;

                            grid[i][j] = (unsigned int)rand() % 6;
                            
                        }
                    }
                    colorbombclear = false;
                }



                //rule 7 implementation
                if (colorbombSwapped) {
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (grid[i][j] == colorbombSwap) {
                                if (grid[i][j] == 0)
                                    total = total + 30;
                                else if (grid[i][j] == 1)
                                    total = total + 30;
                                else if (grid[i][j] == 2)
                                    total = total + 40;
                                else if (grid[i][j] == 3)
                                    total = total + 30;
                                else if (grid[i][j] == 5)
                                    total = total + 60;
                                grid[i][j] = (unsigned int)rand() % 6;
                                
                            }
                        }
                    }
                    colorbombSwapped = false;
                }



                //rule 6 implementation
                for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 9; j++) {
                        if ((grid[i][j] == grid[i + 1][j]) && (grid[i + 2][j] == grid[i][j] + 12)) {
                            for (int x = i + 1; x < i + 4; x++) {
                                int n = j - 2;
                                int k = j + 1;

                                if (j == 8)
                                    j--;
                                while (n >= 0) {
                                    if (grid[x][k] == 0)
                                        total = total + 30;
                                    else if (grid[x][k] == 1)
                                        total = total + 30;
                                    else if (grid[x][k] == 2)
                                        total = total + 40;
                                    else if (grid[x][k] == 3)
                                        total = total + 30;
                                    else if (grid[x][k] == 5)
                                        total = total + 60;
                                    grid[x][k] = grid[x][n];
                                   
                                    n--;
                                    k--;
                                }
                                while (k >= 0) {
                                    grid[x][k] = (unsigned int)rand() % 6;
                                    k--;
                                }
                            }
                        }
                        else if ((grid[i][j] == grid[i + 2][j]) && (grid[i + 1][j] == grid[i][j] + 12)) {
                            for (int x = i; x < i + 3; x++) {
                                int n = j - 2;
                                int k = j + 1;

                                if (j == 8)
                                    j--;
                                while (n >= 0) {
                                    if (grid[x][k] == 0)
                                        total = total + 30;
                                    else if (grid[x][k] == 1)
                                        total = total + 30;
                                    else if (grid[x][k] == 2)
                                        total = total + 40;
                                    else if (grid[x][k] == 3)
                                        total = total + 30;
                                    else if (grid[x][k] == 5)
                                        total = total + 60;
                                    grid[x][k] = grid[x][n];
                                   
                                    n--;
                                    k--;
                                }
                                while (k >= 0) {

                                    grid[x][k] = (unsigned int)rand() % 6;
                                    k--;
                                }
                            }
                        }
                        else if ((grid[i + 1][j] == grid[i + 2][j]) && (grid[i][j] == grid[i + 1][j] + 12)) {
                            for (int x = i - 1; x < i + 2; x++) {
                                int n = j - 2;
                                int k = j + 1;

                                if (j == 8)
                                    j--;
                                while (n >= 0) {
                                    if (grid[x][k] == 0)
                                        total = total + 30;
                                    else if (grid[x][k] == 1)
                                        total = total + 30;
                                    else if (grid[x][k] == 2)
                                        total = total + 40;
                                    else if (grid[x][k] == 3)
                                        total = total + 30;
                                    else if (grid[x][k] == 5)
                                        total = total + 60;
                                    grid[x][k] = grid[x][n];
                                    
                                    n--;
                                    k--;
                                }
                                while (k >= 0) {

                                    grid[x][k] = (unsigned int)rand() % 6;
                                    k--;
                                }
                            }
                        }
                    }

                }
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 7; j++) {
                        if ((grid[i][j] == grid[i][j + 1]) && (grid[i][j + 2] == grid[i][j] + 12)) {
                            for (int x = i - 1; x < i + 2; x++) {
                                int n = j;
                                int k = j + 3;

                                if (i == 8)
                                    i--;
                                while (n >= 0) {
                                    
                                    if (grid[x][k] == 0)
                                        total = total + 30;
                                    else if (grid[x][k] == 1)
                                        total = total + 30;
                                    else if (grid[x][k] == 2)
                                        total = total + 40;
                                    else if (grid[x][k] == 3)
                                        total = total + 30;
                                    else if (grid[x][k] == 5)
                                        total = total + 60;
                                    grid[x][k] = grid[x][n];
                                    n--;
                                    k--;
                                }
                                while (k >= 0) {

                                    grid[x][k] = (unsigned int)rand() % 6;
                                    k--;
                                }
                            }
                        }
                        else if ((grid[i][j] == grid[i][j + 2]) && (grid[i][j + 1] == grid[i][j] + 12)) {
                            for (int x = i - 1; x < i + 2; x++) {
                                int n = j - 2;
                                int k = j + 2;

                                if (i == 8)
                                    i--;
                                while (n >= 0) {
                                    if (grid[x][k] == 0)
                                        total = total + 30;
                                    else if (grid[x][k] == 1)
                                        total = total + 30;
                                    else if (grid[x][k] == 2)
                                        total = total + 40;
                                    else if (grid[x][k] == 3)
                                        total = total + 30;
                                    else if (grid[x][k] == 5)
                                        total = total + 60;
                                    grid[x][k] = grid[x][n];
                                    n--;
                                    k--;
                                }
                                while (k >= 0) {

                                    grid[x][k] = (unsigned int)rand() % 6;
                                    k--;
                                }
                            }
                        }
                        else if ((grid[i][j + 1] == grid[i][j + 2]) && (grid[i][j] == grid[i][j + 1] + 12)) {
                            for (int x = i - 1; x < i + 2; x++) {
                                int n = j - 2;
                                int k = j + 1;

                                if (i == 8)
                                    i--;
                                while (n >= 0) {
                                    if (grid[i][k] == 0)
                                        total = total + 30;
                                    else if (grid[i][k] == 1)
                                        total = total + 30;
                                    else if (grid[i][k] == 2)
                                        total = total + 40;
                                    else if (grid[i][k] == 3)
                                        total = total + 30;
                                    else if (grid[i][k] == 5)
                                        total = total + 60;
                                    grid[x][k] = grid[x][n];
                                    n--;
                                    k--;
                                }
                                while (k >= 0) {
                                    grid[x][k] = (unsigned int)rand() % 6;
                                    k--;
                                }
                            }
                        }
                    }
                }
                //rule 5 implementation

            //horizontal
                for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 9; j++) {
                        if ((grid[i][j] == grid[i + 1][j]) && (grid[i + 2][j] == grid[i][j] + 6)) {


                            for (int k = 0; k < 9; k++) {
                                grid[i + 2][k] = (unsigned int)rand() % 6;
                                if (grid[i + 2][j] == 0)
                                    total = total + 30;
                                else if (grid[i + 2][k] == 1)
                                    total = total + 30;
                                else if (grid[i + 2][k] == 2)
                                    total = total + 40;
                                else if (grid[i + 2][k] == 3)
                                    total = total + 30;
                                else if (grid[i + 2][k] == 5)
                                    total = total + 60;

                            }
                        }
                        else if ((grid[i][j] == grid[i + 2][j]) && (grid[i + 1][j] == grid[i][j] + 6)) {
                            for (int k = 0; k < 9; k++) {
                                grid[i + 1][k] = (unsigned int)rand() % 6;
                                if (grid[i + 1][k] == 0)
                                    total = total + 30;
                                else if (grid[i + 1][k] == 1)
                                    total = total + 30;
                                else if (grid[i + 1][k] == 2)
                                    total = total + 40;
                                else if (grid[i + 1][k] == 3)
                                    total = total + 30;
                                else if (grid[i + 1][k] == 5)
                                    total = total + 60;

                            }
                        }
                        else if ((grid[i + 1][j] == grid[i + 2][j]) && (grid[i][j] == grid[i + 1][j] + 6)) {
                            for (int k = 0; k < 9; k++) {
                                grid[i][k] = (unsigned int)rand() % 6;
                                if (grid[i][k] == 0)
                                    total = total + 30;
                                else if (grid[i][k] == 1)
                                    total = total + 30;
                                else if (grid[i][k] == 2)
                                    total = total + 40;
                                else if (grid[i][k] == 3)
                                    total = total + 30;
                                else if (grid[i][k] == 5)
                                    total = total + 60;

                            }
                        }
                    }
                }
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 7; j++) {
                        if ((grid[i][j] == grid[i][j + 1]) && (grid[i][j + 1] == grid[i][j] + 6)) {
                            for (int k = 0; k < 9; k++) {
                                grid[i][k] = (unsigned int)rand() % 6;
                                if (grid[i][k] == 0)
                                    total = total + 30;
                                else if (grid[i][k] == 1)
                                    total = total + 30;
                                else if (grid[i][k] == 2)
                                    total = total + 40;
                                else if (grid[i][k] == 3)
                                    total = total + 30;
                                else if (grid[i][k] == 5)
                                    total = total + 60;

                            }
                        }
                        else if ((grid[i][j] == grid[i][j + 2]) && (grid[i][j + 1] == grid[i][j] + 6)) {
                            for (int k = 0; k < 9; k++) {
                                grid[i][k] = (unsigned int)rand() % 6;
                                if (grid[i][k] == 0)
                                    total = total + 30;
                                else if (grid[i][k] == 1)
                                    total = total + 30;
                                else if (grid[i][k] == 2)
                                    total = total + 40;
                                else if (grid[i][k] == 3)
                                    total = total + 30;
                                else if (grid[i][k] == 5)
                                    total = total + 60;

                            }
                        }
                        else if ((grid[i][j + 1] == grid[i][j + 2]) && (grid[i][j] == grid[i][j + 1] + 6)) {
                            for (int k = 0; k < 9; k++) {
                                grid[i][k] = (unsigned int)rand() % 6;
                                if (grid[i][k] == 0)
                                    total = total + 30;
                                else if (grid[i][k] == 1)
                                    total = total + 30;
                                else if (grid[i][k] == 2)
                                    total = total + 40;
                                else if (grid[i][k] == 3)
                                    total = total + 30;
                                else if (grid[i][k] == 5)
                                    total = total + 60;

                            }
                        }
                    }
                }
                //rule 4 implementation

                //for horizontal
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 9; j++) {
                        if ((grid[i][j] == grid[i + 1][j]) && (grid[i][j] == grid[i + 2][j]) && (grid[i][j] == grid[i + 3][j]) && (grid[i][j] == grid[i + 4][j])) {
                            grid[i][j] = 18;
                            if (grid[i][j] == 0)
                                total = total + 150;
                            else if (grid[i][j] == 1)
                                total = total + 150;
                            else if (grid[i][j] == 2)
                                total = total + 200;
                            else if (grid[i][j] == 3)
                                total = total + 150;
                            else if (grid[i][j] == 5)
                                total = total + 300;

                            for (int x = i + 1; x < i + 5; x++) {
                                int n = j - 1;
                                int k = j;
                                while (n >= 0) {
                                    grid[x][k] = grid[x][n];
                                    k--;
                                    n--;
                                }
                                grid[x][0] = (unsigned int)rand() % 6;
                            }

                        }
                    }
                }
                //for vertical
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 5; j++) {
                        if ((grid[i][j] == grid[i][j + 1]) && (grid[i][j] == grid[i][j + 2]) && (grid[i][j] == grid[i][j + 3]) && (grid[i][j] == grid[i][j + 4])) {
                            grid[i][j + 4] = 18;
                            if (grid[i][j] == 0)
                                total = total + 150;
                            else if (grid[i][j] == 1)
                                total = total + 150;
                            else if (grid[i][j] == 2)
                                total = total + 200;
                            else if (grid[i][j] == 3)
                                total = total + 150;
                            else if (grid[i][j] == 5)
                                total = total + 300;
                            int n = j - 1;
                            int k = j + 3;
                            while (n >= 0) {
                                grid[i][k] = grid[i][n];
                                n--;
                                k--;
                            }
                            while (k >= 0) {
                                grid[i][k] = (unsigned int)rand() % 6;
                                k--;
                            }

                        }
                    }
                }
                ////rule 3 implementation

                for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 9; j++) {
                        if ((grid[i][j] == grid[i + 1][j]) && (grid[i][j] == grid[i + 2][j])) {
                            for (int x = i; x < i + 3; x++) {
                                if (j < 7) {
                                    if ((grid[x][j] == grid[x][j + 1]) && (grid[x][j] == grid[x][j + 2])) {
                                        grid[x][j + 2] = grid[x][j + 2] + 12;
                                        if (grid[i][j] == 0)
                                            total = total + 150;
                                        else if (grid[i][j] == 1)
                                            total = total + 150;
                                        else if (grid[i][j] == 2)
                                            total = total + 200;
                                        else if (grid[i][j] == 3)
                                            total = total + 150;
                                        else if (grid[i][j] == 5)
                                            total = total + 300;
                                        if (x == i) {
                                            int n = j - 1;
                                            int k = j;
                                            while (n >= 0) {
                                                grid[i + 1][k] = grid[i + 1][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i + 1][0] = (unsigned int)rand() % 6;
                                            n = j - 1;
                                            k = j;
                                            while (n >= 0) {
                                                grid[i + 2][k] = grid[i + 2][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i + 2][0] = (unsigned int)rand() % 6;

                                            n = j - 1;
                                            k = j + 1;
                                            while (n >= 0) {
                                                grid[i][k] = grid[i][n];
                                                n--;
                                                k--;
                                            }
                                            while (k >= 0) {
                                                grid[i][k] = (unsigned int)rand() % 6;
                                                k--;
                                            }
                                        }
                                        else if (x == i + 1) {
                                            int n = j - 1;
                                            int k = j;
                                            while (n >= 0) {
                                                grid[i][k] = grid[i][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i][0] = (unsigned int)rand() % 6;
                                            while (n >= 0) {
                                                grid[i + 2][k] = grid[i + 2][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i + 2][0] = (unsigned int)rand() % 6;
                                            n = j - 1;
                                            k = j + 1;
                                            while (n >= 0) {
                                                grid[i + 1][k] = grid[i + 1][n];
                                                n--;
                                                k--;
                                            }
                                            while (k >= 0) {
                                                grid[i + 1][k] = (unsigned int)rand() % 6;
                                                k--;
                                            }
                                        }
                                        else if (x == i + 2) {
                                            int n = j - 1;
                                            int k = j;
                                            while (n >= 0) {
                                                grid[i + 1][k] = grid[i + 1][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i + 1][0] = (unsigned int)rand() % 6;
                                            n = j - 1;
                                            k = j;
                                            while (n >= 0) {
                                                grid[i][k] = grid[i][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i][0] = (unsigned int)rand() % 6;

                                            n = j - 1;
                                            k = j + 1;
                                            while (n >= 0) {
                                                grid[i + 2][k] = grid[i + 2][n];
                                                n--;
                                                k--;
                                            }
                                            while (k >= 0) {
                                                grid[i + 2][k] = (unsigned int)rand() % 6;
                                                k--;
                                            }
                                        }
                                    }
                                }
                                if (j > 2) {
                                    if ((grid[x][j] == grid[x][j - 1]) && (grid[x][j] == grid[x][j - 2])) {
                                        if (grid[i][j] == 0)
                                            total = total + 150;
                                        else if (grid[i][j] == 1)
                                            total = total + 150;
                                        else if (grid[i][j] == 2)
                                            total = total + 200;
                                        else if (grid[i][j] == 3)
                                            total = total + 150;
                                        else if (grid[i][j] == 5)
                                            total = total + 300;
                                        grid[x][j] = grid[x][j] + 12;
                                        if (x == i) {
                                            int n = j - 1;
                                            int k = j;
                                            while (n >= 0) {
                                                grid[i + 1][k] = grid[i + 1][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i + 1][0] = (unsigned int)rand() % 6;
                                            n = j - 1;
                                            k = j;
                                            while (n >= 0) {
                                                grid[i + 2][k] = grid[i + 2][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i + 2][0] = (unsigned int)rand() % 6;

                                            n = j - 3;
                                            k = j - 1;
                                            while (n >= 0) {
                                                grid[i][k] = grid[i][n];
                                                n--;
                                                k--;
                                            }
                                            while (k >= 0) {
                                                grid[i][k] = (unsigned int)rand() % 6;
                                                k--;
                                            }
                                        }
                                        else if (x == i + 1) {
                                            int n = j - 1;
                                            int k = j;
                                            while (n >= 0) {
                                                grid[i][k] = grid[i][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i][0] = (unsigned int)rand() % 6;
                                            while (n >= 0) {
                                                grid[i + 2][k] = grid[i + 2][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i + 2][0] = (unsigned int)rand() % 6;
                                            n = j - 3;
                                            k = j - 1;
                                            while (n >= 0) {
                                                grid[i + 1][k] = grid[i + 1][n];
                                                n--;
                                                k--;
                                            }
                                            while (k >= 0) {
                                                grid[i + 1][k] = (unsigned int)rand() % 6;
                                                k--;
                                            }
                                        }
                                        else if (x == i + 2) {
                                            int n = j - 1;
                                            int k = j;
                                            while (n >= 0) {
                                                grid[i + 1][k] = grid[i + 1][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i + 1][0] = (unsigned int)rand() % 6;
                                            n = j - 1;
                                            k = j;
                                            while (n >= 0) {
                                                grid[i][k] = grid[i][n];
                                                k--;
                                                n--;
                                            }
                                            grid[i][0] = (unsigned int)rand() % 6;

                                            n = j - 3;
                                            k = j - 1;
                                            while (n >= 0) {
                                                grid[i + 2][k] = grid[i + 2][n];
                                                n--;
                                                k--;
                                            }
                                            while (k >= 0) {
                                                grid[i + 2][k] = (unsigned int)rand() % 6;
                                                k--;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }


                //rule 2 implementation
                //for horizontal
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 9; j++) {
                        if ((grid[i][j] == grid[i + 1][j]) && (grid[i][j] == grid[i + 2][j]) && (grid[i][j] == grid[i + 3][j])) {
                            grid[i][j] = grid[i][j] + 6;
                            // Calculating New Player Score 
                            if (grid[i][j] == 0)
                                total = total + 120;
                            else if (grid[i][j] == 1)
                                total = total + 120;
                            else if (grid[i][j] == 2)
                                total = total + 160;
                            else if (grid[i][j] == 3)
                                total = total + 120;
                            else if (grid[i][j] == 5)
                                total = total + 240;

                            for (int x = i + 1; x < i + 4; x++) {
                                int n = j - 1;
                                int k = j;
                                while (n >= 0) {
                                    grid[x][k] = grid[x][n];
                                    k--;
                                    n--;
                                }
                                grid[x][0] = (unsigned int)rand() % 6;;
                            }

                        }
                    }
                }
                //for vertical
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 6; j++) {
                        if ((grid[i][j] == grid[i][j + 1]) && (grid[i][j] == grid[i][j + 2]) && (grid[i][j] == grid[i][j + 3])) {
                            grid[i][j + 3] = grid[i][j] + 6;
                            if (grid[i][j] == 0)
                                total = total + 120;
                            else if (grid[i][j] == 1)
                                total = total + 120;
                            else if (grid[i][j] == 2)
                                total = total + 160;
                            else if (grid[i][j] == 3)
                                total = total + 120;
                            else if (grid[i][j] == 5)
                                total = total + 240;
                            int n = j - 1;
                            int k = j + 2;
                            while (n >= 0) {
                                grid[i][k] = grid[i][n];
                                n--;
                                k--;
                            }
                            while (k >= 0) {
                                grid[i][k] = (unsigned int)rand() % 6;
                                k--;
                            }

                        }
                    }
                }
                //rule 1 implementation
                //for horizontal
                for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 9; j++) {
                        if ((grid[i][j] == grid[i + 1][j]) && (grid[i][j] == grid[i + 2][j])) {
                            // Calculating New Player Score 
                            if (grid[i][j] == 0)
                                total = total + 90;
                            else if (grid[i][j] == 1)
                                total = total + 90;
                            else if (grid[i][j] == 2)
                                total = total + 120;
                            else if (grid[i][j] == 3)
                                total = total + 90;
                            else if (grid[i][j] == 5)
                                total = total + 180;

                            for (int x = i; x < i + 3; x++) {
                                int n = j - 1;
                                int k = j;
                                while (n >= 0) {
                                    grid[x][k] = grid[x][n];
                                    k--;
                                    n--;
                                }
                                grid[x][0] = (unsigned int)rand() % 6;
                            }



                        }
                    }
                }
                //for vertical
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 7; j++) {
                        if ((grid[i][j] == grid[i][j + 1]) && (grid[i][j] == grid[i][j + 2])) {
                            if (grid[i][j] == 0)
                                total = total + 90;
                            else if (grid[i][j] == 1)
                                total = total + 90;
                            else if (grid[i][j] == 2)
                                total = total + 120;
                            else if (grid[i][j] == 3)
                                total = total + 90;
                            else if (grid[i][j] == 5)
                                total = total + 180;
                            int n = j;
                            int k = j + 3;
                            while (n >= 0) {
                                grid[i][k] = grid[i][n];
                                n--;
                                k--;
                            }
                            while (k >= 0) {
                                grid[i][k] = (unsigned int)rand() % 6;
                                k--;
                            }

                        }
                    }
                }

            }
            //candy clicked
            if (e.type == Event::MouseButtonPressed && loadingScreenFlag == false) {
                if (startGameFlag == true) {
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (Mouse::getPosition(window).x > (50 * i) && Mouse::getPosition(window).x < (50 * (i + 1)) && Mouse::getPosition(window).y >(50 * j) && Mouse::getPosition(window).y < (50 * (j + 1))) {
                                clickedx[onetwo] = i;
                                clickedy[onetwo] = j;
                                cout << " Coordinates are " << "x:" << i << " " << "y:" << j << endl;
                                onetwo++;

                            }
                        }
                    }
                }
                startGameFlag = true;
            }
            if (onetwo == 2) {
                if (grid[clickedx[0]][clickedy[0]] != grid[clickedx[1]][clickedy[1]]) {
                    if ((clickedx[0] == clickedx[1] + 1 || clickedx[0] == clickedx[1] - 1 || clickedx[0] == clickedx[1]) && (clickedy[0] == clickedy[1] + 1 || clickedy[0] == clickedy[1] - 1 || clickedy[0] == clickedy[1]) && (clickedy[0] == clickedy[1] || clickedx[0] == clickedx[1])) {
                        if (clickedx[0] != clickedx[1] || clickedy[0] != clickedy[1]) {
                            //do the swappy 
                            cout << "swappy";
                            if (grid[clickedx[0]][clickedy[0]] == 18 && grid[clickedx[1]][clickedy[1]] < 6) {
                                colorbombSwapped = true;
                                colorbombSwap = grid[clickedx[1]][clickedy[1]];
                                grid[clickedx[0]][clickedy[0]] = grid[clickedx[1]][clickedy[1]];
                            }
                            if (grid[clickedx[1]][clickedy[1]] == 18 && grid[clickedx[0]][clickedy[0]] < 6) {
                                colorbombSwapped = true;
                                colorbombSwap = grid[clickedx[0]][clickedy[0]];
                                grid[clickedx[0]][clickedy[0]] = grid[clickedx[1]][clickedy[1]];
                            }
                            if (grid[clickedx[0]][clickedy[0]] == 18 && grid[clickedx[1]][clickedy[1]] == 18) {
                                colorbombclear = true;
                            }
                            if ((grid[clickedx[0]][clickedy[0]] > 5 && grid[clickedx[0]][clickedy[0]] < 12) && (grid[clickedx[1]][clickedy[1]] == 18)) {
                                colorbombxstriped = true;
                                grid[clickedx[1]][clickedy[1]] = (unsigned int)rand() % 6;
                                grid[clickedx[0]][clickedy[0]] = (unsigned int)rand() % 6;
                            }
                            if ((grid[clickedx[1]][clickedy[1]] > 5 && grid[clickedx[1]][clickedy[1]] < 12) && (grid[clickedx[0]][clickedy[0]] == 18)) {
                                colorbombxstriped = true;
                                grid[clickedx[0]][clickedy[0]] = (unsigned int)rand() % 6;
                                grid[clickedx[1]][clickedy[1]] = (unsigned int)rand() % 6;
                            }
                            if ((grid[clickedx[0]][clickedy[0]] > 11 && grid[clickedx[0]][clickedy[0]] < 18) && (grid[clickedx[1]][clickedy[1]] == 18)) {
                                colorbombxwrapped = true;
                                grid[clickedx[0]][clickedy[0]] = (unsigned int)rand() % 6;
                                grid[clickedx[1]][clickedy[1]] = (unsigned int)rand() % 6;
                            }
                            if ((grid[clickedx[1]][clickedy[1]] > 11 && grid[clickedx[1]][clickedy[1]] < 18) && (grid[clickedx[0]][clickedy[0]] == 18)) {
                                colorbombxwrapped = true;
                                grid[clickedx[0]][clickedy[0]] = (unsigned int)rand() % 6;
                                grid[clickedx[1]][clickedy[1]] = (unsigned int)rand() % 6;
                            }
                            if ((grid[clickedx[0]][clickedy[0]] > 5 && grid[clickedx[0]][clickedy[0]] < 12) && (grid[clickedx[1]][clickedy[1]] > 11 && grid[clickedx[1]][clickedy[1]] < 18)) {
                                stripedxwrapped = true;
                                grid[clickedx[0]][clickedy[0]] = (unsigned int)rand() % 6;
                                grid[clickedx[1]][clickedy[1]] = (unsigned int)rand() % 6;
                                swap[0] = clickedx[0];
                                swap[1] = clickedy[0];
                            }
                            if ((grid[clickedx[1]][clickedy[1]] > 5 && grid[clickedx[1]][clickedy[1]] < 12) && (grid[clickedx[0]][clickedy[0]] > 11 && grid[clickedx[0]][clickedy[0]] < 18)) {
                                stripedxwrapped = true;

                                swap[0] = clickedx[1];
                                swap[1] = clickedy[1];

                            }
                            if ((grid[clickedx[0]][clickedy[0]] > 11 && grid[clickedx[0]][clickedy[0]] < 18) && (grid[clickedx[1]][clickedy[1]] > 11 && grid[clickedx[1]][clickedy[1]] < 18)) {
                                wrappedxwrapped = true;

                                swap[0] = clickedx[1];
                                swap[1] = clickedy[1];
                            }
                            int temp = grid[clickedx[0]][clickedy[0]];
                            grid[clickedx[0]][clickedy[0]] = grid[clickedx[1]][clickedy[1]];
                            grid[clickedx[1]][clickedy[1]] = temp;
                            move--;
                        }
                        else
                            cout << "You clicked the same block twice\n";

                    }
                    else
                        cout << "Not next to each other\n";

                }
                else
                    cout << "The same colour\n";

                onetwo = 0;
            }
            if (loadingScreenFlag == false) {
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {

                        switch (grid[i][j]) {

                        case 0: {
                            RedCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(RedCandy);

                            break;
                        }
                        case 1: {
                            BlueCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(BlueCandy);

                            break;
                        }
                        case 2: {
                            GreenCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(GreenCandy);

                            break;
                        }
                        case 3: {
                            YellowCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(YellowCandy);

                            break;
                        }
                        case 4: {
                            PurpleCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(PurpleCandy);

                            break;
                        }
                        case 5: {
                            OrangeCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(OrangeCandy);

                            break;
                        }
                        case 6: {
                            StripedRedCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(StripedRedCandy);
                            break;
                        }
                        case 7: {
                            StripedBlueCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(StripedBlueCandy);
                            break;
                        }
                        case 8: {
                            StripedGreenCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(StripedGreenCandy);
                            break;
                        }
                        case 9: {
                            StripedYellowCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(StripedYellowCandy);
                            break;
                        }
                        case 10: {
                            StripedPurpleCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(StripedPurpleCandy);
                            break;

                        }
                        case 11: {
                            StripedOrangeCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(StripedOrangeCandy);
                            break;
                        }
                        case 12: {
                            WrappedRedCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(WrappedRedCandy);
                            break;
                        }
                        case 13: {
                            WrappedBlueCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(WrappedBlueCandy);
                            break;
                        }
                        case 14: {
                            WrappedGreenCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(WrappedGreenCandy);
                            break;
                        }
                        case 15: {
                            WrappedYellowCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(WrappedYellowCandy);
                            break;
                        }
                        case 16: {
                            WrappedPurpleCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(WrappedPurpleCandy);
                            break;
                        }
                        case 17: {
                            WrappedOrangeCandy.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(WrappedOrangeCandy);
                            break;
                        }
                        case 18: {
                            ColorBomb.setPosition(Vector2f(50.f * i, 50.f * j));
                            window.draw(ColorBomb);
                            break;

                        }

                        }

                    }


                }
            }
            // Scoreboard
            
            
            if (!loadingScreenFlag)
            {


                
                stringstream ss;

                // Displaying Target Score
                target.setFont(font);
                target.setString("Target Score: \n 5000");
                target.setCharacterSize(34);
                target.setFillColor(Color::Black);
                target.setStyle(Text::Bold | Text::Underlined);
                target.setPosition(500.f, 50.f);

                // Displaying Player Score
                score.setFont(font);
                score.setString("Your Score: ");
                score.setCharacterSize(34);
                score.setFillColor(Color::Black);
                score.setStyle(Text::Bold | Text::Underlined);
                score.setPosition(500.f, 150.f);

                ss << total;
                scoreCount.setFont(font);
                scoreCount.setString(ss.str());
                scoreCount.setCharacterSize(34);
                scoreCount.setFillColor(Color::Black);
                scoreCount.setStyle(Text::Bold | Text::Underlined);
                scoreCount.setPosition(500.f, 190.f);

                // Displaying Moves Left for Player
                stringstream SS;
                SS << move;
                moveCount.setFont(font);
                moveCount.setString(SS.str());
                moveCount.setCharacterSize(34);
                moveCount.setFillColor(Color::Black);
                moveCount.setStyle(Text::Bold | Text::Underlined);
                moveCount.setPosition(500.f, 290.f);

                moves.setFont(font);
                moves.setString("Moves Left: ");
                moves.setCharacterSize(34);
                moves.setFillColor(Color::Black);
                moves.setStyle(Text::Bold | Text::Underlined);
                moves.setPosition(500.f, 250.f);

                window.draw(target);
                window.draw(score);
                window.draw(scoreCount);
                window.draw(moves);
                window.draw(moveCount);
            }





            window.display();
            window.clear(Color(255, 165, 0));


            // clear the window with orang color

        }
    }
}




