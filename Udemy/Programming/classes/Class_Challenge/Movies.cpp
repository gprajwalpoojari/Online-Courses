#include <iostream>
#include "Movies.h"
#include "Movie.h"

Movies::Movies()
        : my_movies{} {
            
        }

Movies::add_movie(std::string name, std::string rating, int num_watched) {
    Movie temp{name, rating, num_watched};
    for (Movie i : this->my_movies) {
        if (temp.get_name() == i.get_name()) {
            std::cout << "Movie already present" << std::endl;
            
        }
        else {
            this->my_movies.pushback(temp);
        }
    }
    
}

Movies::increment_watched(std::string name) {
    for (Movie i : this->my_movies) {
        if (i.get_name() == name) {
            i.set_watched();
        }
        else {
            std::cout << "Movie not found" << std::endl;
        }
    }
}