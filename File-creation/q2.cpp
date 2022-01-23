#include <iostream>
#include <fstream>
using namespace std;

void delete_line(const char *fn, int n1)
{
    ifstream ajex3(fn);
    ofstream ajex4;
    ajex3.open(fn);
    ajex4.open("test",ofstream::out);
    char c;
    int line_no = 1;
    while (ajex3.get(c))
    {
        // if a newline character
        if (c == '\n')
            line_no++;

        // file content not to be deleted
        if (line_no != n1)
            ajex4 << c;
    }
    ajex4.close();
    ajex3.close();
    remove(fn);
    rename("test", fn);
}
int main()
{
    ifstream ajex3;
    ofstream ajex4;
    ajex4.open("test");
    ajex4<<"test line 1\n";
    ajex4<<"test line 2\n";
    ajex4<<"test line 3\n";
    ajex4<<"test line 4\n";
    ajex4.close();
    const int n = 40;
    char a[n], a1[40];
    cout << "Enter the file name to be input in the form of .txt : " << endl;
    cin.getline(a1, 40);
    //ifstream ajex2;
    ajex3.open(a1);
    if (ajex3.good())
    {
        cout << "File found " << endl;
    }
    else
    {
        cout << "No file found " << endl;
    }
    ajex3.close();
    int N;
    cout << "Enter the line you want to remove : " << endl;
    cin >> N;
    delete_line("test", N);
    ajex3.open("test");
    while (ajex3)
    {
        ajex3.getline(a, n);
        cout << a << endl;
    }
    ajex3.close();

    return 0;
}