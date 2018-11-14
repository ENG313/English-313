// Copyright (C) 2018 raodm@miamioh.edu.

#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Convenience for using methods in standard namespace
using namespace std;

/** An OS operation requires removal of all wildcards (.ie., ''
    characters) in each line of a given input stream.  Coplete teh
    following cleanUp method to remove all *' characters from a given
    string and rpint each line to a given output stream.

    \param[in] is The input stream from where lines are to be read.

    \param[out] os The output stream to where lines are to be written.
*/
void cleanUp(std::istream& is, std::ostream& os) {
    // Implement this method.
}

// Alias for an unordered map used in merge method below.
using UserMap = std::unordered_map<std::string, std::string>;

/** Complete the following method that merges values (with a '-'
   between values) with the same key in both maps (while ignoring keys
   that are not present in both). Example maps (in key, value format)
   are shown in the supplied document. NOTE: order of entries in the
   unordered maps is random.

   \param[in] m1 The first unordered map to be used for merging.

   \param[in] m2 The second unordered map to be used for merging.

   \return An unordered map with values merged with a '-' for keys
   present in both unordered maps (m1 and m2).
*/
UserMap merge(const UserMap& m1, const UserMap& m2) {
    // Implement this method. For now this method returns an empty map
    // to avoid compiler warnings
    return UserMap();
}

/** Complete the following method to run the Linux command 'head -num
    GPL.txt' with different values of 'num' supplied as the
    argument. For example, if numList = {1, 17, 3}, then this method
    should run head 3 times, in a serial manner, as: "head -1
    GPL.txt", "head -17 GPL.txt", "head -3 GPL.txt"
 
    @param[in] numList The list of numbers to be used to run the head
    command.
 */
void serial(std::vector<int> numList) {
    // Implement this method.
}
