#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;

void replaceLine(std::string &filename, std::string s1, std::string s2)
{
    std::ifstream infile(filename);
    if (!infile)
    {
        cout << "Error opening file" << endl;
        return ;
    }
    std::ofstream outfile(filename + ".replace");
    if (!outfile)
    {
        cout << "Error opening file" << endl;
        return ;
    }
    std::string line;

    while (std::getline(infile, line))
    {
        int start_pos = 0;
        int pos = 0;
        std::string new_line;
        while ((pos = line.find(s1, start_pos)) != std::string::npos)
            {
                new_line += line.substr(start_pos, pos - start_pos);
                new_line += s2;
                start_pos = pos + s1.length();
            }
        new_line += line.substr(start_pos, line.length() - start_pos);
        outfile << new_line << endl;
    }
    infile.close();
    outfile.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        cout << "Wrong number of arguments" << endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    replaceLine(filename, s1, s2);
    return (0);
}