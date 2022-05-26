#include"mm.h"

int main() {
    std::vector<std::string> out;
    read_file("C://Users//jason//Desktop//mm1.txt",out);
    std::map<std::string, int> key_map;
    initial_key_map(key_map);
    for (auto text : out) {
        std::cout << text << std::endl;
        analyse(text, key_map);
    }
    return 0;
}