#include "../include/kmm.h"

#include <KMSdata-1.0/data.h>

#include <vector>


/// Loads mortality data into the Kmm model
/**
 * The vector elements get transferred as follows:
 * - params[0] <- beta
 * - params[...] <- gamma
 * - params[...] <- delta
 * - params[...] <- delta_temp
 * - params[...] <- theta
 * - params[...] <- epsilon0
**/
void Kmm::load_data(Data<double> X) {

    std::vector<double> c;
    c.reserve(X.nrows());

    for (auto it_c = c.begin(), it_y = X["Year"], it_a = Y["Age"];
            it_c != c.end(); it_c++, it_y++, it_a++) {

        *it_c = *it_y - *it_a;}
    //X.sort_by()
}
