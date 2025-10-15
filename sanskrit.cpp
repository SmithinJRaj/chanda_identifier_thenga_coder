#include<bits/stdc++.h>
#include "utf8.h"
using namespace std;
using namespace utf8;

bool isCombiningMark(uint32_t cp) {
    return (cp == 0x0301 || cp == 0x0300);
}

string removeTones(const string &input) {
    string output;
    auto it = input.begin();
    auto end = input.end();

    while (it != end) {
        uint32_t cp = utf8::next(it, end);
        if (!isCombiningMark(cp)) {
            utf8::append(cp, back_inserter(output));
        }
    }
    return output;
}

auto peekAhead = [](auto it, auto end, int n) {
    auto temp = it;
    for (int i = 0; i < n && temp != end; i++) {
        utf8::next(temp, end);
    }
    return temp;
};

bool isVowel(uint32_t cp) {
    string vowels = u8"aāiīuūṛṝḷḹeoáàíìúùṛ́ṛ̀ḷ́ḷ̀ā́ā̀ī́ī̀ū́ū̀ṝ́ṝ̀éèóò";
    auto it = vowels.begin();
    auto end = vowels.end();
    while (it != end) {
        if (cp == utf8::next(it, end)) return true;
    }
    return false;
}

bool islongVowel(uint32_t cp) {
    string vowels = u8"āīūṝeoéā́ā̀ī́ī̀ū́ū̀ṝ́ṝ̀éèóò";
    auto it = vowels.begin();
    auto end = vowels.end();
    while (it != end) {
        if (cp == utf8::next(it, end)) return true;
    }
    return false;
}

bool iscons(uint32_t cp) {
    string vowels = u8"kgcjṭḍtdpb";
    auto it = vowels.begin();
    auto end = vowels.end();
    while (it != end) {
        if (cp == utf8::next(it, end)) return true;
    }
    return false;
}

int main()
{
    string LG;
    int n;
    cin >> n;
    getchar();
    for(int i=0; i<n; i++)
    {
        string line;
        getline(cin,line);
        istringstream iss(line);
        string word;
        while(iss >> word)
        {
            string temper = word;
            word = removeTones(temper);
            auto begin1 = word.begin();
            auto end1 = word.end();
            auto it = begin1;
            uint32_t cp;
            cp = next(it, end1);
            if(cp == '|')
            {
                if(LG[LG.length()-2] == 'L')
                {
                    LG[LG.length()-2] = 'G';
                }
                LG.push_back('|');
                LG.push_back(' ');
                break;
            }
            it = begin1;
            while(it!=end1)
            {
                cp = next(it, end1);
                if(isVowel(cp))
                {
                    break;
                }
            }
            int f=0;
            while(1)
            {
                int cn = 0;
                if(it==end1)
                {
                    if(islongVowel(cp))
                    {
                        LG.push_back('G');
                    }
                    else
                    {
                        LG.push_back('L');
                    }
                    f=1;
                    LG.push_back(' ');
                    break;
                }
                auto temp = it;
                uint32_t tempc = next(temp,end1);
                if(tempc == 'i' || tempc=='u' || islongVowel(cp) || tempc==0x00ED)
                {
                    LG.push_back('G');
                    f=1;
                    if(temp == end1 && (tempc == 'i' || tempc=='u' || tempc==0x00ED))
                    {
                        LG.push_back(' ');
                        break;
                    }
                    if(tempc == 'i' || tempc =='u' || tempc==0x00ED)
                    {
                        cp = next(it, end1);
                    }
                }
                while(1)
                {
                    cp = next(it, end1);
                    if(isVowel(cp))
                    {
                        break;
                    }
                    else
                    {
                        if(iscons(cp))
                        {
                            auto temp1 = it;
                            uint32_t tempc1;
                            if(temp1!= end1)
                            {
                                tempc1 = next(temp1,end1);
                            }
                            if(it == end1)
                            {
                                cn++;
                            }
                            else if(tempc1 == 'h')
                            {
                                cn++;
                                cp = next(it, end1);
                            }
                            else
                            {
                                cn++;
                            }
                        }
                        else
                        {
                            cn++;
                        }
                    }
                    if(it == end1)
                    {
                        break;
                    }
                }
                if(f == 0 && cn>=2)
                {
                    LG.push_back('G');
                }
                else if(f == 0 && cn>0 && it == end1 && !isVowel(cp))
                {
                    LG.push_back('G');
                }
                else if(f == 0)
                {
                    LG.push_back('L');
                }
                if(it == end1 && !isVowel(cp))
                {
                    LG.push_back(' ');
                    break;
                }
                f=0;
            }
        }
        if(LG[LG.length()-2] != '|')
        {
            LG.push_back('i');
            LG.push_back(' ');
        }
    }
    cout << LG << '\n';
    vector<int> patt;
    string LGplain;
    int count=0;
    for(int i=0; i<LG.length(); i++)
    {
        if(LG[i] == 'L' || LG[i] == 'G')
        {
            LGplain.push_back(LG[i]);
            count++;
        }
        if(LG[i] == '|' || LG[i] == 'i')
        {
            patt.push_back(count);
            count=0;
            if(i+1<LG.length() && LG[i+1]=='|')
            {
                break;
            }
        }
    }
    cout << LGplain << '\n';
    for(int i=0; i<patt.size(); i++)
    {
        cout << patt[i] << " ";
    }
    cout  << '\n';

    if(patt.size() == 3)
    {
        if(abs(patt[2] - 8) > abs(patt[2] - 12))
        {
            cout << "Ushnih Chanda" << "\n";
        }
        else
        {
            cout << "Gayatri Chanda" << "\n";
        }
    }
    else if(patt.size() == 4)
    {
        int a11=0,a12=0,a8=0;
        for(int i=0; i<4; i++)
        {
            if(patt[i] == 11)
            {
                a11++;
            }
            else if(patt[i] == 12)
            {
                a12++;
            }
            else if(patt[i] == 8)
            {
                a8++;
            }
        }
        if((a8>=2) || (abs(patt[0] - 8) <= 1 && abs(patt[1] - 8) <= 1 && abs(patt[2] - 8) <= 1 && abs(patt[3] - 8) <= 1))
        {
            cout << "Anushtubh Chanda" << "\n";
        }
        else if((a8>=2 && a12==1) || (abs(patt[0] - 8) <= 1 && abs(patt[1] - 8) <= 1 && abs(patt[2] - 12) <= 1 && abs(patt[3] - 8) <= 1))
        {
            cout << "Brihati Chanda" << "\n";
        }
        else 
        {
            if(a11 > a12)
            {
                cout << "Tristubh Chanda" << "\n";
            }
            else if(a11 < a12)
            {
                cout << "Jagati Chanda" << "\n";
            }
            else
            {
                int a = patt[0] + patt[1] + patt[2] + patt[3];
                if(a < 46)
                {
                    cout << "Tristubh Chanda" << "\n";
                }
                else
                {
                    cout << "Jagati Chanda" << "\n";
                }
            }
        }
    }
    else
    {
        cout << "Pankti Chanda" << "\n";
    }
}