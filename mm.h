#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>
//sssssssssssssssssss
inline void split(const std::string& in,
    std::vector<std::string>& out,
    std::string token)
{
    out.clear();
    std::string temp;
    for (int i = 0; i < int(in.size()); i++)
    {
        std::string test = in.substr(i, token.size());

        if (test == token)
        {
            if (!temp.empty())
            {
                out.push_back(temp);
                temp.clear();
                i += (int)token.size() - 1;
            }
            else
            {
                // out.push_back("");
            }
        }
        else if (i + token.size() >= in.size())
        {
            temp += in.substr(i, token.size());
            out.push_back(temp);
            break;
        }
        else
        {
            temp += in[i];
        }
    }
}
int get_file_length(std::ifstream& file) {
    file.seekg(0, std::ios::end);
    int length = file.tellg();
    file.seekg(0, 0);
    return length;
}
bool read_file(std::string Path, std::vector<std::string>& out) {

    std::ifstream file(Path, std::ios::binary);

    if (!file.is_open())
        return false;
    int flength = get_file_length(file);

    char* file_text = (char*)malloc((flength+1) * sizeof(char));
    if (file_text == nullptr)
        return false;
    file.read(file_text, flength);
    file_text[flength] = '\0';

    std::string tt = "\r\n";
    split(file_text, out, tt);
    file.close();
    return true;

}
void  initial_key_map(std::map<std::string, int>& key_map) {
    //1: 标识符 2.运算符 3.界限符 4. 字符串 5.变量名 6.数字 7.转义字符
    key_map.insert(std::map<std::string, int>::value_type("if", 1));
    key_map.insert(std::map<std::string, int>::value_type("else", 1));
    key_map.insert(std::map<std::string, int>::value_type("while", 1));
    key_map.insert(std::map<std::string, int>::value_type("signed", 1));
    key_map.insert(std::map<std::string, int>::value_type("throw", 1));
    key_map.insert(std::map<std::string, int>::value_type("union", 1));
    key_map.insert(std::map<std::string, int>::value_type("this", 1));
    key_map.insert(std::map<std::string, int>::value_type("int", 1));
    key_map.insert(std::map<std::string, int>::value_type("char", 1));
    key_map.insert(std::map<std::string, int>::value_type("double", 1));
    key_map.insert(std::map<std::string, int>::value_type("unsigned", 1));
    key_map.insert(std::map<std::string, int>::value_type("const", 1));
    key_map.insert(std::map<std::string, int>::value_type("goto", 1));
    key_map.insert(std::map<std::string, int>::value_type("virtual", 1));
    key_map.insert(std::map<std::string, int>::value_type("for", 1));
    key_map.insert(std::map<std::string, int>::value_type("float", 1));
    key_map.insert(std::map<std::string, int>::value_type("break", 1));
    key_map.insert(std::map<std::string, int>::value_type("auto", 1));
    key_map.insert(std::map<std::string, int>::value_type("class", 1));
    key_map.insert(std::map<std::string, int>::value_type("operator", 1));
    key_map.insert(std::map<std::string, int>::value_type("case", 1));
    key_map.insert(std::map<std::string, int>::value_type("do", 1));
    key_map.insert(std::map<std::string, int>::value_type("long", 1));
    key_map.insert(std::map<std::string, int>::value_type("typedef", 1));
    key_map.insert(std::map<std::string, int>::value_type("static", 1));
    key_map.insert(std::map<std::string, int>::value_type("friend", 1));
    key_map.insert(std::map<std::string, int>::value_type("template", 1));
    key_map.insert(std::map<std::string, int>::value_type("default", 1));
    key_map.insert(std::map<std::string, int>::value_type("new", 1));
    key_map.insert(std::map<std::string, int>::value_type("void", 1));
    key_map.insert(std::map<std::string, int>::value_type("register", 1));
    key_map.insert(std::map<std::string, int>::value_type("extern", 1));
    key_map.insert(std::map<std::string, int>::value_type("return", 1));
    key_map.insert(std::map<std::string, int>::value_type("enum", 1));
    key_map.insert(std::map<std::string, int>::value_type("inline", 1));
    key_map.insert(std::map<std::string, int>::value_type("try", 1));
    key_map.insert(std::map<std::string, int>::value_type("short", 1));
    key_map.insert(std::map<std::string, int>::value_type("continue", 1));
    key_map.insert(std::map<std::string, int>::value_type("sizeof", 2));
    key_map.insert(std::map<std::string, int>::value_type("switch", 1));
    key_map.insert(std::map<std::string, int>::value_type("private", 1));
    key_map.insert(std::map<std::string, int>::value_type("protected", 1));
    key_map.insert(std::map<std::string, int>::value_type("asm", 1));
    key_map.insert(std::map<std::string, int>::value_type("while", 1));
    key_map.insert(std::map<std::string, int>::value_type("catch", 1));
    key_map.insert(std::map<std::string, int>::value_type("delete", 1));
    key_map.insert(std::map<std::string, int>::value_type("public", 1));
    key_map.insert(std::map<std::string, int>::value_type("volatile", 1));
    key_map.insert(std::map<std::string, int>::value_type("struct", 1));
    key_map.insert(std::map<std::string, int>::value_type("[", 2));
    key_map.insert(std::map<std::string, int>::value_type("]", 2));
    key_map.insert(std::map<std::string, int>::value_type("(", 2));
    key_map.insert(std::map<std::string, int>::value_type(")", 2));
    key_map.insert(std::map<std::string, int>::value_type(".", 2));
    key_map.insert(std::map<std::string, int>::value_type("->", 2));
    key_map.insert(std::map<std::string, int>::value_type("-", 2));
    key_map.insert(std::map<std::string, int>::value_type("++", 2));
    key_map.insert(std::map<std::string, int>::value_type("--", 2));
    key_map.insert(std::map<std::string, int>::value_type("*", 2));
    key_map.insert(std::map<std::string, int>::value_type("::", 2));
    key_map.insert(std::map<std::string, int>::value_type("&", 2));
    key_map.insert(std::map<std::string, int>::value_type("!", 2));
    key_map.insert(std::map<std::string, int>::value_type("~", 2));
    key_map.insert(std::map<std::string, int>::value_type("/", 2));
    key_map.insert(std::map<std::string, int>::value_type("%", 2));
    key_map.insert(std::map<std::string, int>::value_type("+", 2));
    key_map.insert(std::map<std::string, int>::value_type("-", 2));
    key_map.insert(std::map<std::string, int>::value_type("<<", 2));
    key_map.insert(std::map<std::string, int>::value_type(">>", 2));
    key_map.insert(std::map<std::string, int>::value_type(">", 2));
    key_map.insert(std::map<std::string, int>::value_type("<", 2));
    key_map.insert(std::map<std::string, int>::value_type(">=", 2));
    key_map.insert(std::map<std::string, int>::value_type("==", 2));
    key_map.insert(std::map<std::string, int>::value_type("!=", 2));
    key_map.insert(std::map<std::string, int>::value_type("&&", 2));
    key_map.insert(std::map<std::string, int>::value_type("||", 2));
    key_map.insert(std::map<std::string, int>::value_type("|", 2));
    key_map.insert(std::map<std::string, int>::value_type("^", 2));
    key_map.insert(std::map<std::string, int>::value_type("?:", 2));
    key_map.insert(std::map<std::string, int>::value_type("=", 2));
    key_map.insert(std::map<std::string, int>::value_type("/=", 2));
    key_map.insert(std::map<std::string, int>::value_type("*=", 2));
    key_map.insert(std::map<std::string, int>::value_type("%=", 2));
    key_map.insert(std::map<std::string, int>::value_type("+=", 2));
    key_map.insert(std::map<std::string, int>::value_type("-=", 2));
    key_map.insert(std::map<std::string, int>::value_type("<<=", 2));
    key_map.insert(std::map<std::string, int>::value_type(">>=", 2));
    key_map.insert(std::map<std::string, int>::value_type("&=", 2));
    key_map.insert(std::map<std::string, int>::value_type("^=", 2));
    key_map.insert(std::map<std::string, int>::value_type("|=", 2));
    key_map.insert(std::map<std::string, int>::value_type(",", 2));
    key_map.insert(std::map<std::string, int>::value_type(":", 2));


    key_map.insert(std::map<std::string, int>::value_type("{", 3));
    key_map.insert(std::map<std::string, int>::value_type("}", 3));
    key_map.insert(std::map<std::string, int>::value_type(";", 3));

    key_map.insert(std::map<std::string, int>::value_type("\"", 4));
    key_map.insert(std::map<std::string, int>::value_type("\'", 4));

}
int find_key_word(std::string token, std::map<std::string, int>& key_map) {
    std::string ss = "if";
    std::map<std::string, int >::iterator m_iter;;
    m_iter = key_map.find(token);
    if (m_iter == key_map.end()) {
        //不是系统定义符号
        //std::cout << "we do not find " << std::endl;

        return 0;
    }
    else {
        //std::cout << "we find " << (*m_iter).second << std::endl;
        return (*m_iter).second;
    }
    return 0;

}
void analyse(std::string text, std::map<std::string, int>& key_map) {
    //TODO 每次读入一个字母，入栈，然后判断一次，循环往复
    char indicator = '0';
    std::string token = "";
    std::string output="";
    for (int i = 0; i < text.size(); i++) {
        indicator = text[i];
        if (indicator == ' ') {
            continue;
        }
        token.push_back(indicator);
        if ((indicator < 91 && indicator>64) || (indicator < 123 && indicator>96) || indicator == 95) {
            //标识符
            i++;
            indicator = text[i];
            while ((indicator < 91 && indicator>64) || (indicator < 123 && indicator>96) || indicator == 95 || (indicator > 47 && indicator < 58)&&i<text.size()) {
                token.push_back(indicator);
                i++;
                indicator = text[i];
            }
            i--;
            int temp = find_key_word(token, key_map);
            if (temp == 1) {
                output.append("(").append(token).append(",1)\n");
            }
            else {
                output.append("(").append(token).append(",5)\n");
            }
            token.clear();
            continue;
        }
        else if ((indicator > 48 && indicator < 58)) {
            //非0数字
            while (!(indicator > 47 && indicator < 58)) {
                i++;
                if (i == text.size())
                    break;
                indicator = text[i];
                token.push_back(indicator);
            }
            
            //find_key_word(token);
            //return 不为0数字
            output.append("(").append(token).append(",").append("6)\n");
            token.clear();
            continue;
        }
        else if (indicator == '0') {
            //return 为数字0;
            output.append("(").append(token).append(",").append("6)\n");
            token.clear();
            continue;
        }

        else if (indicator == '\\') {
            //是转义字符
            i++;
            indicator = text[i];
            token.push_back(indicator);
            output.append("(").append(token).append(",").append("7)\n");
            token.clear();
            continue;

        }
        else {

            int flag_key = find_key_word(token, key_map);
            if (flag_key == 2) {
                //是算符
                i++;
                indicator = text[i];
                token.push_back(indicator);
                if (indicator == '/') {

                    token.append(text.substr(i+1));
                    i = text.size();
                    output.append("(").append(token).append(",").append("8)\n");
                    token.clear();
                    
                    continue;
                }
                while (find_key_word(token, key_map) == 2&&i<text.size()) {
                    token.push_back(indicator);
                    i++;
                    indicator = text[i];
                }
                if (i != text.size()) {
                    i--;
                    token.pop_back();
                }
                output.append("(").append(token).append(",").append("2)\n");
                token.clear();
                continue;
            }
            else if (flag_key == 3) {
                //是界限符
                output.append("(").append(token).append(",").append("3)\n");
                token.clear();
                continue;
            }
            else if (flag_key == 4) {
                //是字符串
                i++;
                indicator = text[i];
                token.push_back(indicator);
                while (find_key_word(std::string("").append(1,indicator), key_map) != 4 && i < text.size()) {
                    i++;
                    indicator = text[i];
                    token.push_back(indicator);
                }


                output.append("(").append(token).append(",").append("4)\n");
                token.clear();
                continue;
            }
            else {
                //TODO 不知道是什么万一
                output.append("未知").append(token).append("\n");
                token.clear();
                continue;
            }
        }
    }
    std::cout << output << std::endl;
}
#pragma once
