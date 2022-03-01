#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

//Constant Variables declarations
const int IP[] = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };
const int RIP[] = { 40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25 };
const int PC1[] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
const int PC2[] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };

const int EP[] = { 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };
const int P[] = { 16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25 };

const int S1[][16] = { {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7}, {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8}, {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0}, {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13} };
const int S2[][16] = { {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10}, {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5}, {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15}, {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9} };
const int S3[][16] = { {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8}, {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1}, {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7}, {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12} };
const int S4[][16] = { {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15}, {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9}, {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4}, {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14} };

const int S5[][16] = { {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9}, {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6}, {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14}, {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3} };
const int S6[][16] = { {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11}, {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8}, {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6}, {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13} };
const int S7[][16] = { {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1}, {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6}, {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2}, {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12} };
const int S8[][16] = { {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7}, {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2}, {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8}, {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11} };

const int SHIFT[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

const int IP_OUT = 64, RIP_OUT = 64, PC1_OUT = 56, PC2_OUT = 48, EP_OUT = 48, P_OUT = 32;

// Functions Identifiers
string binaryEquivalentHex(string b);
string hexEquivalentBinary(char h);
string convertTo_BH(string x, string to);
string decimalToBinary(int d);
int binaryToDecimal(string b);
string permutation(string input, int n, string p_type);
string circularLeftShift(string k, int n);
string XOR(string i1, string i2);
string SBOX(string F);
string swap(string l, string r);

int main(int argc, char** argv)
{
    //Variables declarations
    string operation, input, key, output, lable;

    //Take input from user
    operation = argv[1];
    input = argv[2];
    key = argv[3];
    
    if (operation == "encrypt" || operation == "decrypt")
    {
   
        //convert the hexa number into binary
        input = convertTo_BH(input, "binary");
        key = convertTo_BH(key, "binary");

        //perform permutations on the binary input text & key
        input = permutation(input, IP_OUT, "IP"); //Initial Permutation
        key = permutation(key, PC1_OUT, "PC1"); //Permuted Choice 1

        //split the key
        string C = key.substr(0, 28);
        string D = key.substr(28, 28);

        //split the input
        string L = input.substr(0, 32);
        string R = input.substr(32, 32);
        string F;

        //calculate keys
        string keys[16];
        for (int i = 0; i < 16; i++)
        {
            C = circularLeftShift(C, SHIFT[i]);
            D = circularLeftShift(D, SHIFT[i]);

            key = C + D;
            key = permutation(key, PC2_OUT, "PC2"); //Permuted Choice 2
            keys[i] = key;
        }

        //start the rounds
        for (int i = 0; i < 16; i++)
        {
            key = (operation == "encrypt") ? keys[i] : keys[16 - i - 1];

            F = permutation(R, EP_OUT, "EP"); //Expansion Permutation
            F = XOR(F, key);
            F = SBOX(F);//S-Box
            F = permutation(F, P_OUT, "P"); //Permutation
            F = XOR(F, L);

            L = R;
            R = F;
        }

        output = swap(L, R);
        output = permutation(output, RIP_OUT, "RIP"); //Inverse Initial Permutation
        output = convertTo_BH(output, "hex"); //convert binary to hex
        lable = (operation == "encrypt") ? "cipher: " : "plain: ";
        cout << lable << output << "\n";
    }

    else
    {
        cout << "invalid request, make sure that the operation is encrypt or decrypt";
    }
    return 0;
}

// Functions Implementation
string permutation(string input, int n, string p_type)
{
    string output;
    output.resize(n);
    for (int i = 0, index = 0; i < n; i++) {
        if (p_type == "IP")    
            index = IP[i] - 1;

        else if (p_type == "PC1")
            index = PC1[i] - 1;

        else if (p_type == "PC2")
            index = PC2[i] - 1;

        else if (p_type == "EP")
            index = EP[i] - 1;
        
        else if (p_type == "P")
            index = P[i] - 1;

        else
            index = RIP[i] - 1;

        output[i] = input[index];
    }
    return output;
}

string SBOX(string t)
{
    string output = "", s_input, row_string;
    output.resize(32);
    int col = 0, row = 0, s = 0;

    for (int i = 0, s_num = 1; s_num <= 8; i += 6, s_num++)
    {
        s_input = t.substr(i, 6);
        col = binaryToDecimal(s_input.substr(1, 4));
        row_string = s_input[0];
        row_string += s_input[5];
        row = binaryToDecimal(row_string);

        switch (s_num)
        {
        case 1:
            s = S1[row][col];
            break;

        case 2:
            s = S2[row][col];
            break;
        
        case 3:
            s = S3[row][col];
            break;

        case 4:
            s = S4[row][col];
            break;

        case 5:
            s = S5[row][col];
            break;

        case 6:
            s = S6[row][col];
            break;

        case 7:
            s = S7[row][col];
            break;

        case 8:
            s = S8[row][col];
            break;
        }

        output = (i == 0)? decimalToBinary(s) : output + decimalToBinary(s);
    }

    return output;
}

string XOR(string i1, string i2)
{
    string output = "";
    int n = i1.length();

    for (int i = 0; i < n; i++)
    {
        output += to_string((i1[i] - 48) ^ (i2[i] - 48));
    }

    return output;
}

string swap(string l, string r)
{
    return r + l;
}

string circularLeftShift(string k, int n)
{
    string t = k.substr(0, n);
    k.erase(0, n);
    k += t;
    return k;
}

string decimalToBinary(int d)
{
    string output = "0000";

    for (int i = 0; d > 0; i++)
    {
        output[3 - i] = d % 2 + '0';
        d = d / 2;
    }

    return output;
}

int binaryToDecimal(string b)
{
    int size = b.length();
    int bit = 0, decimal = 0;

    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        bit = b[i] - '0';
        if (bit != 0)
            decimal += bit * pow(2, j);
    }
    
    return decimal;
}

string convertTo_BH(string x, string to) 
{
    string y = "";
    int l = x.length();
    if (to == "binary")
    {
        for (int i = 0; i < l; i++)
        {
            if (i == 0)
            {
                y = hexEquivalentBinary(x[i]);
            }
            else
            {
                y += hexEquivalentBinary(x[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < l; i += 4)
        {
            if (i == 0)
            {
                y = binaryEquivalentHex(x.substr(i, 4));
            }
            else
            {
                y += binaryEquivalentHex(x.substr(i, 4));
            }
        }

    }

    return y;
}

string hexEquivalentBinary(char h)
{
    string b = "";
    switch (h) {
    case 'A':
    case 'a':
        b = "1010";
        break;
    case 'B':
    case 'b':
        b = "1011";
        break;
    case 'C':
    case 'c':
        b = "1100";
        break;
    case 'D':
    case 'd':
        b = "1101";
        break;
    case 'E':
    case 'e':
        b = "1110";
        break;
    case 'F':
    case 'f':
        b = "1111";
        break;
    default:
        b = decimalToBinary(h - '0');
        break;
    }
    return b;
}

string binaryEquivalentHex(string b)
{
    string h;
    if (b == "1010")
    {
        h = 'A';
    }
    else if (b == "1011")
    {
        h = 'B';
    }
    else if (b == "1100")
    {
        h = 'C';
    }
    else if (b == "1101")
    {
        h = 'D';
    }
    else if (b == "1110")
    {
        h = 'E';
    }
    else if (b == "1111")
    {
        h = 'F';
    }
    else
    {
        h = binaryToDecimal(b) + '0';
    }

    return h;
}


