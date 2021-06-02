#include "../include/kmm.h"

#include <vector>


/// Extracts the parameters of the model in transfer vector format
/**
 * The vector elements get transferred as follows:
 * - params[0] <- beta
 * - params[...] <- gamma
 * - params[...] <- delta
 * - params[...] <- delta_temp
 * - params[...] <- theta
 * - params[...] <- epsilon0
**/
std::vector<double> Kmm::get_transfer_vector() {

    std::vector<double> transfer_vector;
    transfer_vector.reserve(this->derive_transfer_vector_size());


    transfer_vector.push_back(this->beta);

    for (auto it = this->gamma.begin(); it != this->gamma.end(); it++) {
        transfer_vector.push_back(it->second);}

    for (auto it = this->delta.begin(); it != this->delta.end(); it++) {
        transfer_vector.push_back(it->second);}

    for (auto it = this->delta_temp.begin();
            it != this->delta_temp.end(); it++) {
        transfer_vector.push_back(it->second);}

    for (auto it = this->theta.begin(); it != this->theta.end(); it++) {
        transfer_vector.push_back(it->second);}

    for (auto it = this->epsilon0.begin(); it != this->epsilon0.end(); it++) {
        transfer_vector.push_back(it->second);}


    return transfer_vector;
}
