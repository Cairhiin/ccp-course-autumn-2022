#pragma once

#include <iostream>
#include <list>
#include <string>
#include "dragon.hpp"

/**
 * \brief The DragonCave class is a sort of storage class for Dragons.
 *
 * The class stores pointers of Dragon objects in a list. The class allows basic
 * manipulation of the Dragon pointer list through the functions described
 * below.
 *
 * The class has a list of Dragon pointers as a private member. This class is
 * not copyable (also means not assignable), so copy and assignment operations
 * for this class should be prevented.
 *
 * You will need to implement the following methods:
 *
 * The DragonCave class has a parameterless constructor that default constructs
 * the members i.e. uses the parameterless constructor to initialize them.
 *
 * The destructor of the DragonCave class deletes all the Dragons in the
 * the DragonCave's Dragon* list.
 *
 * GetDragons: the function returns a const reference to the DragonCave's
 * list of Dragon pointers. The function takes no parameters and does not change
 * the DragonCave's state, i.e. the function should be const.
 *
 * Accommodate: takes a Dragon pointer as a parameter and adds it to the end of
 * the DragonCave's Dragon pointer list. The function returns nothing.
 *
 * Evict: takes a Dragon's name as a const string reference as a parameter.
 * Tries to find a dragon with a matching name from the DragonCaves Dragon
 * pointer list. Erases the first Dragon pointer with a matching name from the
 * list. If there is no Dragon with a matching name in the list, the function
 * does nothing. Note that the function only erases the pointer from the list,
 * but DOES NOT delete the Dragon object. The function returns nothing.
 */

class DragonCave {
    public: 
        DragonCave() {};
        ~DragonCave();

        const std::list<Dragon*>& GetDragons() const;        
        void Accommodate(Dragon* dragon);
        void Evict(const std::string& name);
        friend std::ostream& operator<<(std::ostream& out, const DragonCave& dragonCave);

    private:
        DragonCave(const DragonCave& dragonCave);
        DragonCave& operator= (const DragonCave& d);
        std::list<Dragon*> inhabitants_;
};

/**
 * \brief TODO: operator << overloads the << stream operator for printing
 * DragonCaves to a desired ostream.
 *
 * The DragonCave should be printed to the parameter ostream in the following
 * format:
DragonCave dwellers:\n
\n
<First Dragon in the dragons list>\n
<Second Dragon in the dragons list>\n
...
<Last Dragon in the dragons list>
 *
 * NOTE: The dragons in the dragon list are printed in the same format as the
overloaded
 *       << stream operator for Dragons prints them. Also note that there is an
additional
 *       end line character after each dragon except for the last one.
 * \param os reference to the output stream to which the information is printed
(ostream).
 * \param cave the DragonCave whose information should be printed (const
DragonCave&).
 *
 * \return The output stream given as one of the arguments.
 *
 */
