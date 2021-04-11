// #include <iostream>
// #include <string>
// #include <climits>
// #include "Board.hpp"
// #include "Direction.hpp"

// namespace ariel{
//     void Board::post(u_int row, u_int col, Direction d, std::string str){
//         u_int i;
//         if (d == ariel::Direction::Horizontal){
//             if (col + str.length() > UINT_MAX - 1){
//                 throw std::length_error("Length is too much");
//             }for (i = 0; i < str.length(); i++){
//                 this->board[{row,col+i}] = str.at(i);
//                 // this->board.insert({{row,col+i},str.at(i)});
//             }
//         }else{
//             if (row + str.length() > UINT_MAX - 1){
//                 throw length_error("Length is too much");
//             }for (i = 0; i < str.length(); i++){
//                 this->board[{row+i,col}] = str.at(i);
//                 // this->board.insert({{row+i,col},str.at(i)});
//             }
//         }
//     }
//     string Board::read(u_int row, u_int col, Direction d, u_int length){
//         string word = "";
//         u_int i;
//         char c;
//         if (d == ariel::Direction::Horizontal){
//             if (col + length > UINT_MAX){
//                 throw length_error("Length is too much");
//             }for (i = 0; i < length; i++){
//                 try{
//                    c = this->board.at({row,col+i}); 
//                    word+=c;
//                 }catch(const std::exception& e){
//                     c = '_';
//                     word+=c;
//                 }
//             }
//         }else{
//             if (row + length > UINT_MAX){
//                 throw length_error("Length is too much");
//             }for (i = 0; i < length; i++){            
//                 try{
//                    c = this->board.at({row+i,col}); 
//                    word+=c;
//                 }catch(const std::exception& e){
//                     c = '_';
//                     word+=c;
//                 }
//             }
//         }
//         return word;
//     }
//     void Board::show(){
//         if(this->board.empty())
//         {
//             for (u_int i = 0; i < 10; i++){
//                 for (u_int j = 0; j < 10; j++)
//                 {
//                     cout << "_";
//                 }
//                 cout << "\n";
//             }
//         }
//         cout << "board is sized " << get_rowMax() - get_rowMin() << "X" << get_colMax() - get_colMin() << endl;
//         for (unsigned int i = get_rowMin(); i < get_rowMax() + 1; i++){
//             for (unsigned int j = get_colMin(); j < get_colMax() + 1; j++){
//                 char c = this->board.at({i,j});
//                 if (this->board.at({i,j}) == '\0'){
//                     cout << "_";
//                 }else{
//                     cout << this->board.at({i,j});
//                 }
//             }
//             cout << "\n";
//         }
//     }
// }




#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>
#include <climits>
#include "Board.hpp"

namespace ariel{
    void Board::post(u_int row, u_int col, Direction d, std::string str){  
        if (d == ariel::Direction::Vertical){
            if (row + str.length() > UINT_MAX - 1){
                throw std::length_error("Length is too much");
            }for (uint i = 0; i < str.length(); i++){
                this->board[{row+i,col}] = str.at(i);
                // this->board.insert({{row,col+i},str.at(i)});
            }
        }else{
            if (col + str.length() > UINT_MAX - 1){
                throw length_error("Length is too much");
            }for (uint i = 0; i < str.length(); i++){
                this->board[{row,col+i}] = str.at(i);
                // this->board.insert({{row+i,col},str.at(i)});
            }
        }
    }
    std::string Board::read(u_int row, u_int col, Direction d, u_int length){
        string s = "\0";
        char c = '\0';
        if (d == ariel::Direction::Vertical){
            if (row + length > UINT_MAX){
                throw length_error("The length need to be smaller");
            }for (uint i = 0; i < length; i++){
                try{
                   c = this->board.at({row+i,col}); 
                   s+=c;
                }catch(const std::exception& e){
                    c = '_';
                    s+=c;
                }
            }
        }else{
            if (col + length > UINT_MAX){
                throw length_error("The length need to be smaller");
            }for (uint i = 0; i < length; i++){            
                try{
                   c = this->board.at({row,col+i}); 
                   s+=c;
                }catch(const std::exception& e){
                    c = '_';
                    s+=c;
                }
            }
        }
        return s;
    }
    void Board::show(){
        if(this->board.empty())
        {
            for (u_int i = 0; i < 10; i++){
                for (u_int j = 0; j < 10; j++)
                {
                    cout << "_";
                }
                cout << "\n";
            }
        }
        int mone = 0;
        for(uint i = 0; i < get_max_rows() + 1; i++){
            for(uint j = 0; j < get_max_cols() + 1; j++){
                if(this->board.at({i,j}) != '\0'){
                    if(mone>0){
                        cout << " ";
                    }
                    cout << this->board.at({i,j});
                }
                else
                    mone++;
                if(j == get_max_cols() + 1){
                    cout << endl;
                }
                
            }
        }
        // for (unsigned int i = 0; i < get_max_rows() + 1; i++){
        //     for (unsigned int j = 0; j < get_max_cols() + 1; j++){
        //         char c = this->board.at({i,j});
        //         if (this->board.at({i,j}) == '\0'){
        //             cout << "_";
        //         }else{
        //              cout << this->board.at({i,j});
        //          }
        //      }
        //      cout << "\n";
        //  }
     }
}
