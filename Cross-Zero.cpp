
#include <iostream>
using namespace std;
enum GameCell
{
    EMPTY = '_',
    CROSS = 'X',
    ZERO = 'O'
};

enum GameProgress
{
    HUMAN_WON,
    AI_WON,
    IN_PROGRESS,
    DRAW
};

struct GameField
{
    const size_t SIZE = 3;
    size_t nTurn = 0;
    GameCell** ppField = nullptr;
    GameCell human;
    GameCell ai;
    GameProgress progress = IN_PROGRESS;

};

struct FieldCoord
{
    size_t y = 0;
    size_t x = 0;
};

void initField(GameField& rf)
{
    rf.ppField = new GameCell * [rf.SIZE];
    for (size_t y = 0; y < rf.SIZE; y++)
    {
        rf.ppField[y] = new GameCell[rf.SIZE];
    }

    for (size_t y = 0; y < rf.SIZE; y++)
    {
        for (size_t x = 0; x < rf.SIZE; x++)
        {
            rf.ppField[y][x] = EMPTY;
        }
    }
    bool InvalidInput = true;
    while(InvalidInput)
    { 
        InvalidInput = false;
        cout  << "1.Cross" << endl << "2.Zero" << endl << "3.Random" << endl << "Enter: ";
        cin >> rf.nTurn;

        if (rf.nTurn == 3)
        {
            rf.nTurn = rand() % 2 + 1;
        }
        switch (rf.nTurn)
        {
        case 1:
            rf.nTurn = 1;
            rf.human = CROSS;
            rf.ai = ZERO;
            break;
        case 2:
            rf.nTurn = 2;
            rf.human = ZERO;
            rf.ai = CROSS;
            break;

        default:
            cout << "Invalid input" << endl;
            InvalidInput = true;
            break;
        }
    }
    
}

void deinitField(GameField& rf)
{
    for (size_t y = 0; y < rf.SIZE; y++)
    {
        delete[] rf.ppField[y];
    }
    delete[] rf.ppField;
    rf.ppField = nullptr;
}

void clearScr()
{
    system("cls");
}

void drawField(const GameField& rf)
{
    clearScr();
    cout << "    ";
    for (size_t x = 0; x < rf.SIZE; x++)
    {
        cout << x+1 << "   ";
    }
    cout << endl;
    for (size_t y = 0; y < rf.SIZE; y++)
    {
        cout << y + 1 << " | ";
        for (size_t x = 0; x < rf.SIZE; x++)
        {
            cout << (char)rf.ppField[y][x] << " | ";
        }
        cout << endl;
    }

    cout << endl << "Human: " << (char)rf.human << endl;
    cout << "AI: " << (char)rf.ai << endl << endl;
}



GameProgress isWon(const GameField& rf)
{
    for (size_t y = 0; y < rf.SIZE; y++)
    {
        if (rf.ppField[y][0] == rf.ppField[y][1] && rf.ppField[y][0] == rf.ppField[y][2])
        {
            if (rf.ppField[y][0] == rf.human)
            {
                return HUMAN_WON;
            }
            if (rf.ppField[y][0] == rf.ai)
            {
                return AI_WON;
            }
        }
    }

    for (size_t x = 0; x < rf.SIZE; x++)
    {
        if (rf.ppField[0][x] == rf.ppField[1][x] && rf.ppField[0][x] == rf.ppField[2][x])
        {
            if (rf.ppField[0][x] == rf.human)
            {
                return HUMAN_WON;
            }
            if (rf.ppField[0][x] == rf.ai)
            {
                return AI_WON;
            }
        }
    }

    if (rf.ppField[0][0] == rf.ppField[1][1] && rf.ppField[0][0] == rf.ppField[2][2])
    {
        if (rf.ppField[0][0] == rf.human)
        {
            return HUMAN_WON;
        }
        if (rf.ppField[0][0] == rf.ai)
        {
            return AI_WON;
        }
    }

    if (rf.ppField[0][2] == rf.ppField[1][1] && rf.ppField[0][2] == rf.ppField[2][0])
    {
        if (rf.ppField[0][2] == rf.human)
        {
            return HUMAN_WON;
        }
        if (rf.ppField[0][2] == rf.ai)
        {
            return AI_WON;
        }
    }

    bool draw = true;
    for (size_t y = 0; y < rf.SIZE; y++)
    {
        for (size_t x = 0; x < rf.SIZE; x++)
        {
            if (rf.ppField[y][x] == EMPTY)
            {
                
                draw = false;
                break;
            }

            if (!draw)
            {
                break;
            }
        }
    }

    if (draw)
    {
        return DRAW;
    }
    return IN_PROGRESS;
}

FieldCoord getHumanCoord(const GameField& rf)
{
    FieldCoord f;
    bool flagCorrectCoord = true;
   
    do {
        cout << " X coord(1...3): ";
        cin >> f.x;
        cout << " Y coord(1...3): ";
        cin >> f.y;

        if (f.y > 3 || f.x > 3 || f.x < 1 || f.y < 1)
        {
            cout << "Coordinates are incorrect" << endl;
            continue;
        }
        if (rf.ppField[f.y-1][f.x-1] != EMPTY)
        {
            cout << "The cell is used" << endl;
            continue;
            
        }
        flagCorrectCoord = false;

    } while (flagCorrectCoord);
    
     return { f.y - 1, f.x - 1 };
}


FieldCoord getAICoord(GameField& rf)
{
    FieldCoord f;

    for (size_t y = 0; y < rf.SIZE; y++)
    {
        for (size_t x = 0; x < rf.SIZE; x++)
        {

            if (rf.ppField[y][x] == EMPTY)
            {
                rf.ppField[y][x] = rf.ai;
                if (isWon(rf) == AI_WON)
                {
                    rf.ppField[y][x] = EMPTY;
                    return { y, x };

                }
                rf.ppField[y][x] = EMPTY;
            }

            if (rf.ppField[y][x] == EMPTY)
            {
                rf.ppField[y][x] = rf.ai;
                if (isWon(rf) == HUMAN_WON)
                {
                    rf.ppField[y][x] = EMPTY;
                    return { y, x };
                }
                rf.ppField[y][x] = EMPTY;
            }
            
        }
    }



    //центр
    if (rf.ppField[1][1] == EMPTY)
    {
        return { 1, 1 };
    }

    //углы
    if (rf.ppField[0][0] == EMPTY)
    {
        return { 0, 0 };
    }

    if (rf.ppField[2][0] == EMPTY)
    {
        return { 2, 0 };
    }

    if (rf.ppField[2][2] == EMPTY)
    {
        return { 2, 2 };
    }

    if (rf.ppField[0][2] == EMPTY)
    {
        return { 0, 2 };
    }
    

    //не углы
    if (rf.ppField[0][1] == EMPTY)
    {
        return { 0, 1 };
    }

    if (rf.ppField[2][1] == EMPTY)
    {
        return { 2, 1 };
    }

    if (rf.ppField[1][0] == EMPTY)
    {
        return { 1, 0 };
    }

    if (rf.ppField[1][2] == EMPTY)
    {
        return { 1, 2 };
    }

    
}


int main()
{
    GameField f;

    
        initField(f);
        drawField(f);
        
    do {

        if ((f.nTurn % 2) != 0)
        {
            //Human
            FieldCoord c = getHumanCoord(f);
            f.ppField[c.y][c.x] = f.human;
        }
        else
        {
            //AI
            FieldCoord c = getAICoord(f);
            f.ppField[c.y][c.x] = f.ai;
        }

        drawField(f);
        f.nTurn++;
        f.progress = isWon(f);

    } while (f.progress == IN_PROGRESS);
    
    if (f.progress == HUMAN_WON)
    {
        cout << "You won!";
    }
    else if (f.progress == AI_WON)
    {
        cout << "You lost :(";
    }
    else if (f.progress == DRAW)
    {
        cout << "DRAW!";
    }

    deinitField(f);

}


