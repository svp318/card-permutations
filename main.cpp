#include <string>
#include <iostream>

using namespace std;

string *cardValues;
string *positions;
int numberOfCards = 0;
int counter = 1;

// Function used to check if any cards are repeated in the current "positions" array
bool repeatedCards(string cards[]) {

    bool booleanValue = true;

    for (int i = 0; i < numberOfCards; i++) {
        for (int j = 0; j < numberOfCards; j++) {
            if (i != j && cards[i] == cards[j]) {
                booleanValue = false;
            }
        }
    }
    return booleanValue;
}


/* I use a recursive function, since nesting for loops inside
* each other requires us to know how many cards we will
* combine, and if we add more cards, we would need to nest more for loops. 
* Using a recursive method looks better, and gives us the freedom to combine as
* many cards as we want without changing code. */
void combinations(int locNumber) {

    for (int valueNumber = 0; valueNumber < numberOfCards; valueNumber++) {
        positions[locNumber] = cardValues[valueNumber];
        if (locNumber < (numberOfCards-1)) {
            combinations(locNumber + 1);
        }

        //This if statement grabs and displays card combinations in which no card value
        // is repeated in the current "positions" array. Since in a single deck,
        // there are no repeated cards. It also appends the combination count at the beginning.
        if (locNumber == (numberOfCards-1) && repeatedCards(positions)) {
            cout << counter << " ";
            for (int i = 0; i < numberOfCards; i++) {
                cout << positions[i] << " ";
            }
            cout << endl;
            counter++;
        }
    }
}

int main() {

    do {
        cout << "Enter number of cards to permute (from 1 to 10): ";
        cin >> numberOfCards;
        cout << endl;
    } while (numberOfCards < 1 || numberOfCards > 10);

    cardValues = new string[numberOfCards];
    positions = new string[numberOfCards];

    const string availableCards[] = {"AofSpades", "TwoofSpades", "ThreeofSpades", "FourofSpades", "FiveofSpades", "SixofSpades", "SevenofSpades", "EightofSpades", "NineofSpades", "TenofSpades"};

    for (int i = 0; i < numberOfCards; i++) {
        cardValues[i] = availableCards[i];
    }

    combinations(0);

    cout << endl;

    return 0;
}
