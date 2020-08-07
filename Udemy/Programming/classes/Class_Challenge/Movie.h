#ifndef _MOVIE_H_
#def _MOVIE_H_
#include <string>

class Movie {
private:
    std::string name;
    std::string rating;
    int num_watched;
    
public:
    Movie(std::string name, std::string rating, int num_watched);
    Movie(const Movie &source);
    void get_name() {return name;}
    void set_watched() {++num_watched;}
};