#include <iostream>
#include "Movie.h"


Movie::Movie(std::string name, std::string rating, int num_watched)
        :this->name {name}, this->rating {rating}, this->num_watched {num_watched} {
        
        }
        
Movie::Movie (const Movie &source)
        : Movie(source.name, source.rating, source.num_watched) {
            
        }
        
        
    