#ifndef AALTO_ELEC_CPP_AVIARY_CLASS
#define AALTO_ELEC_CPP_AVIARY_CLASS

#include <iostream>
#include <stdexcept>

#include "bird.hpp"

/**
 * \brief Class for storing different birds and interacting with them.
 *
 * If somebody tries to copy an instance of this class, the compilation must
 * fail i.e. TODO: disallow copying
 */
class Aviary {
 public:
  Aviary() {}
  ~Aviary();
  /**
   * \brief TODO: method Add adds the given bird to the aviary.
   *
   * If the pointer is NULL, std::logic_error is thrown. When a bird is added
   * to the aviary, it's ownership is transferred. When the aviary is
   * destroyed, all the birds are destroyed too.
   *
   * \param bird A pointer to a bird object.
   * \return nothing
   */

  void Add(Bird* bird);

  /**
   * \brief TODO: method SpeakAll calls the Speak method with the given
   * parameter on all birds in the aviary.
   *
   * Does not modify the object, thus it should be const.
   *
   * \param os A reference to the desired ostream.
   * \return nothing
   */
  
  void SpeakAll(std::ostream& out);

  /**
   * \brief TODO: method Size returns the number of birds in the aviary.
   *
   * Method takes no arguments and does not modify the object, thus it should
   * be const.
   *
   * \return How many birds there are in the aviary.
   */
  
  int Size();

  /**
   * \brief TODO: non-const version of the indexing operator [].
   *
   * If the index is out of bounds, std::out_of_range is thrown.
   *
   * \param idx desired index as an size_t integer value.
   * \return A pointer to the bird (Bird*) at the index given as an argument
   */
  
  Bird* operator[](size_t idx);

  /**
   * \brief TODO: const version of the indexing operator [].
   *
   * If the index is out of bounds, std::out_of_range is thrown.
   *
   * \param idx desired index as an size_t integer value.
   * \return A pointer to the bird (const Bird*) at the index given as an
   * argument
   */
  
  const Bird* operator[](size_t idx) const;

  /**
   * \brief TODO: destructor. Takes no parameters.
   *
   * \return nothing
   */

  private:
  Aviary(const Aviary&) { }
  Aviary& operator=(const Aviary&) {
    return *this;
  }

   std::vector<Bird*> inhabitants_;

  // TODO: declare the required members
  
};

#endif