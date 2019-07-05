//// hangman.cpp -- some string methods
#include"stdafx.h"     /* �µ�����Ϸ C++ Primer Plus 662 */
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
//        string target = wordlist[std::rand() % NUM];  // �����һ����Ҫ ��� ���µ��ַ���(�µ�Ŀ��)
//        int length = target.length();
//        string attempt(length, '-');   // ����Ŀ���ַ����ĳ��� ����һ���µ� string ����(�� '-'��ʼ��)��������ʾ ��� �µ���Ϣ
//        string badchars;   // ���ڴ洢�´��˵��ַ�
//        int guesses = 6;   // Ŀ���ַ������ÿ���ַ� ��6�βµĻ���
//        cout << "Guess my secret word. It has " << length
//            << " letters, and you guess\n"
//            << "one letter at a time. You get " << guesses
//            << " wrong guesses.\n";
//        cout << "Your word: " << attempt << endl;
//        while (guesses > 0 && attempt != target)  // ���²��������0 ���� �µ��ַ��� ������ Ŀ���ַ��� ʱ (ѭ���²�)
//        {
//            char letter;
//            cout << "Guess a letter: ";
//            cin >> letter;
//            if (badchars.find(letter) != string::npos     // ��� ��� �²���ַ� �ڴ����ַ��� ���� �µ��ַ��� �� ���еģ������²²�
//                || attempt.find(letter) != string::npos)
//            {
//                cout << "You already guessed that. Try again.\n";
//                    continue;
//            }
//            int loc = target.find(letter);  // ������ֻ�������ֿ��ܣ��µ��ַ� ��Ŀ���ַ��������еģ�����û��
//            if (loc == string::npos)
//            {						// �� ��Ҳµ��ַ��� Ŀ���ַ����� û��ʱ������´��ˣ�������һ������������ַ�����
//                cout << "Oh, bad guess!\n";
//                --guesses;
//                badchars += letter; // add to string
//            }
//            else
//            {   // �µ��ַ� ��Ŀ���ַ����� ���еģ�����¶��ˣ�������ַ���Ŀ���ַ�������±꣬�ڲµ��ַ�������ʾ����
//                cout << "Good guess!\n";
//                attempt[loc]=letter;
//                // check if letter appears again
//                loc = target.find(letter, loc + 1);   // ��������Ŀ���ַ����� ��ֻ��һ���ַ�(�ж����ͬ���ַ�)��������Ŀ���ַ��������(��ǰ������)
//                while (loc != string::npos)  
//                {   // �����Ȼ�� Ŀ���ַ����� �ҵõ��������ڲµ��ַ�������ʾ���ַ�����������  ֱ����Ŀ���ַ������Ҳ�������ַ�
//                    attempt[loc]=letter;
//                    loc = target.find(letter, loc + 1);
//                }
//           }
//            cout << "Your word: " << attempt << endl;
//            if (attempt != target)  // �� �µ��ַ��� ������ Ŀ���ַ��� ���� �����ַ�������ַ����� ����0 ʱ ��ʾ�����ַ���
//            {
//                if (badchars.length() > 0)
//                    cout << "Bad choices: " << badchars << endl;
//                cout << guesses << " bad guesses left\n";
//            }
//        }
//        if (guesses > 0)  // ���е����� ֻ���������������Ҳ¶��ˣ���һ��������� ����û�¶�
//            cout << "That's right!\n";
//        else
//            cout << "Sorry, the word is " << target << ".\n";
//
//        cout << "Will you play another? <y/n> ";
//        cin >> play;
//        play = tolower(play);   // ��Ҫ���� ���� y
//    }
//
//    cout << "Bye\n";
//
//    return 0; 
//}
