/*
    convert.cpp

    Convert the text

    Note: The "@concerns" are for pedagogical purposes only.

    * @concerns are assume to be [in], meaning they are predefined and used in the code
    * @concerns marked [out] meaning they are produced in that section
*/

#include <iostream>
#include <string>
#include <cctype>

// output character
// @concerns output format, std::cout, output[out]
void output(char c) {
    std::cout << c;
}

// output text
// @concerns output format, std::string, iteration, output, outputText()
void outputText(const std::string& s) {

    for (auto pc = s.cbegin(); pc != s.cend(); ++pc)
        output(*pc);
}

typedef void (*Conversion)(char& c);

// apply the function convert to each element in the range [begin, end)
// @concerns std::string, iteration, convert(), myforeach[out]
void myforeach(std::string::iterator begin, std::string::iterator end, Conversion convert) {

    for (auto pc = begin; pc != end; ++pc)
        convert(*pc);
}

// @concerns std::toupper, upper[out]
void upper(char& c) {
    c = std::toupper(c);
}

// @concerns std::tolower, lower[out]
void lower(char& c) {
    c = std::tolower(c);
}

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // @concerns input format, argc, argv, error handling, std::cerr
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // conversion option
    // @concerns input format, argv, std::string, option[out]
    std::string option(argv[1]);

    // input text
    // @concerns input format, argv, std::string, text[out]
    std::string text(argv[2]);

    // find the conversion to use
    // @concerns option, "--upper", "--lower", conversion[out]
    // @concerns upper(), lower()
    // @concerns error handling, std::cerr
    Conversion conversion = nullptr;
    if (option == "--upper") {

        conversion = upper;

    } else if (option == "--lower") {

        conversion = lower;

    } else {

        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }

    // convert the string
    // @concerns text, myforeach, std::string, conversion
    myforeach(text.begin(), text.end(), conversion);

    // output converted text
    // @concerns text, outputText()
    outputText(text);
    std::cout << '\n';

    return 0;
}
