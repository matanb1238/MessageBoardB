
// #include "Direction.hpp"
// #include <map>
// #include <string>
// #define SIZE 10

// using namespace std;

// namespace ariel{
//     class Board{
//             map<pair<uint,uint>, char> board;
//             uint rowMax; //max row
//             uint colMax; // max col
//             uint rowMin; //min row
//             uint colMin; // min col
//         public:
//             Board(){
//                 rowMax = SIZE;
//                 colMax = SIZE;
//                 rowMin = 0;
//                 colMin = 0;
//             }
//             uint get_rowMax(){return rowMax;}
//             uint get_colMax(){return colMax;}
//             uint get_rowMin(){return rowMin;}
//             uint get_colMin(){return colMin;}
//             void post(u_int row, u_int col, Direction d, std::string str);
//             string read(u_int row, u_int col, Direction d, u_int length);
//             void show();
//     };
// }




#include "Direction.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>
#define SIZE 10

using namespace std;

namespace ariel{
 
    class Board{
        private:
            uint max_rows;
            uint max_cols;
            map<pair<uint, uint>, char> board; 
            // vector<vector<char>> board;
        public:
        Board(){
            // board = vector<vector<char>>(SIZE , vector<char> (SIZE, '_'));
            max_rows = SIZE;
            max_cols = SIZE;
        }
        uint get_max_rows(){return max_rows;};
        uint get_max_cols(){return max_cols;};
        void post(u_int row, u_int col, Direction d, std::string str);
        string read(u_int row, u_int col, Direction d, u_int length);
        void show();
    };
}
