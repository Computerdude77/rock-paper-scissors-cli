#include <iostream>
using namespace std;
char parseUserThrow(char userInput)
{
    return tolower(userInput, locale());
}
char getComputerThrow()
{
    int random;
    srand (time(NULL));
    random = rand() % 3 + 1;
    if (random == 1)
        return 'r';
    if (random == 2)
        return 'p';
    if (random == 3)
        return 's';
}
int compareThrows(char user, char computer)
{
    if (user == computer)
        return 0;
    if ((user == 'r' && computer == 's') || (user == 'p' && computer == 'r') || (user == 's' && computer == 'p'))
        return 1;
    if ((computer == 'r' && user == 's') || (computer == 'p' && user == 'r') || (computer == 's' && user == 'p'))
        return -1;
}
int main(int argc, char ** argv)
{
if (argc == 1){
    cout << "You need to throw R for rock, P for paper, or S for scissors." << endl;
    return -2;}
if (argc >= 3){
    cout << "You only need to give me R,P, or S." << endl;
    return -3;}
char userThrow = parseUserThrow(argv[1][0]);
char computerThrow = getComputerThrow();
int result = compareThrows(userThrow, computerThrow);
if (result == 0)
    cout << "You tied!" << endl;
if (result == 1)
    cout << "You win!" << endl;
if (result == -1)
    cout << "You lose!" << endl;
return result;
}