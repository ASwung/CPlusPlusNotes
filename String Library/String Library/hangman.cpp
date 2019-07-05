//// hangman.cpp -- some string methods
#include"stdafx.h"     /* 猜单词游戏 C++ Primer Plus 662 */
//#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//#include <cctype>
//using std::string;
//const int NUM = 26;
//const string wordlist[NUM] = {"apiary", "beetle", "cereal",
//    "danger", "ensign", "florid", "garage", "health", "insult",
//    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
//    "plaid", "quilt", "remote", "stolid", "train", "useful",
//    "valid", "whence", "xenon", "yearn", "zippy"};
//
//int main()
//{
//    using std::cout;
//    using std::cin;
//    using std::tolower;
//    using std::endl;
//    
//    std::srand(std::time(0));
//    char play;
//    cout << "Will you play a word game? <y/n> ";
//    cin >> play;
//    play = tolower(play);
//    while (play == 'y')
//    {
//        string target = wordlist[std::rand() % NUM];  // 随机出一个需要 玩家 来猜的字符串(猜的目标)
//        int length = target.length();
//        string attempt(length, '-');   // 根据目标字符串的长度 创建一个新的 string 对象(用 '-'初始化)，用来显示 玩家 猜的信息
//        string badchars;   // 用于存储猜错了的字符
//        int guesses = 6;   // 目标字符串里的每个字符 有6次猜的机会
//        cout << "Guess my secret word. It has " << length
//            << " letters, and you guess\n"
//            << "one letter at a time. You get " << guesses
//            << " wrong guesses.\n";
//        cout << "Your word: " << attempt << endl;
//        while (guesses > 0 && attempt != target)  // 当猜测次数大于0 并且 猜的字符串 不等于 目标字符串 时 (循环猜测)
//        {
//            char letter;
//            cout << "Guess a letter: ";
//            cin >> letter;
//            if (badchars.find(letter) != string::npos     // 如果 玩家 猜测的字符 在错误字符串 或者 猜的字符串 里 是有的，就重新猜测
//                || attempt.find(letter) != string::npos)
//            {
//                cout << "You already guessed that. Try again.\n";
//                    continue;
//            }
//            int loc = target.find(letter);  // 到这里只会有两种可能，猜的字符 在目标字符串里是有的，或者没有
//            if (loc == string::npos)
//            {						// 当 玩家猜的字符在 目标字符串里 没有时，代表猜错了，次数减一，添加至错误字符串里
//                cout << "Oh, bad guess!\n";
//                --guesses;
//                badchars += letter; // add to string
//            }
//            else
//            {   // 猜的字符 在目标字符串里 是有的，代表猜对了，获得其字符在目标字符串里的下标，在猜的字符串里显示出来
//                cout << "Good guess!\n";
//                attempt[loc]=letter;
//                // check if letter appears again
//                loc = target.find(letter, loc + 1);   // 但可能在目标字符串里 不只这一个字符(有多个相同的字符)，继续在目标字符串里查找(当前索引后)
//                while (loc != string::npos)  
//                {   // 如果依然在 目标字符串里 找得到，继续在猜的字符串里显示其字符，继续查找  直至在目标字符串里找不到这个字符
//                    attempt[loc]=letter;
//                    loc = target.find(letter, loc + 1);
//                }
//           }
//            cout << "Your word: " << attempt << endl;
//            if (attempt != target)  // 当 猜的字符串 不等于 目标字符串 并且 错误字符串里的字符个数 大于0 时 显示错误字符串
//            {
//                if (badchars.length() > 0)
//                    cout << "Bad choices: " << badchars << endl;
//                cout << guesses << " bad guesses left\n";
//            }
//        }
//        if (guesses > 0)  // 运行到这里 只会有两种情况，玩家猜对了，玩家机会用完了 并且没猜对
//            cout << "That's right!\n";
//        else
//            cout << "Sorry, the word is " << target << ".\n";
//
//        cout << "Will you play another? <y/n> ";
//        cin >> play;
//        play = tolower(play);   // 如要继续 输入 y
//    }
//
//    cout << "Bye\n";
//
//    return 0; 
//}
