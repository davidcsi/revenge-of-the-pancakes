#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int flipPancakes(string stack)
{
    int flips_made = 0;

    // Let's go through the stack
    for(int j=1;j< stack.length() ;j++)
    {
        // If current pancake is not like the one before, we will need to make a change
        if( stack[j] != stack[j-1] )
        {
            flips_made += 1;
        }
    }

    // If the last pancake is not "OK", we will need to make a change, otherwise return the flips made until now.
    if( stack[stack.length()-1] == '+')
    {
        return flips_made;
    } else {
        return flips_made + 1;
    }
}

int main()
{
    string line;
    int lines, flips;

    // Open file and check it's open
    try {

        ifstream file("sample.in");
        // Let's get the number of tests
        if( getline(file,line) )
        {
            lines = atoi(line.c_str());
            cout << "Lines: " << lines << endl;

            if(lines>0){
                for( int x=1; x<=lines; x++ )
                {
                    getline(file,line);
                    flips = flipPancakes(line);
                    cout << "Case [" << line  << "] #" << x << ": " << flips << endl;
                }
            }

        } else {
            cout << "Could not get the number of samples from the first line!" << std::endl;
        }

    } catch ( const ifstream::failure& e) {
        cout << "Could not open the samples file!" << std::endl;
    }
    return 0;
}