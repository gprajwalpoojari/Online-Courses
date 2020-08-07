#ifndef _MOVIES_H_
#def _MOVIES_H_
#include <vector>
#include "Movie.h"

class Movies {
 private:
    std::vector <Movie> my_movies;
 public:
    void add_movie(std::string name, std::string rating, int num_watched);
    void increment_watched(std::string name);
    Movies(std::vector my_movies);
};