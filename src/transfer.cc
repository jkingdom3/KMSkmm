#include "../include/kmm.h"

#include <assert.h>

#include <vector>


/// From parent class model
/**
 * The vector elements get transferred as follows:
 * - params[0] -> beta
 * - params[...] -> gamma
 * - params[...] -> delta
 * - params[...] -> delta_temp
 * - params[...] -> theta
 * - params[...] -> epsilon0
**/
void Kmm::transfer(const std::vector<double>& params) {

    assert(params.size() == this->derive_transfer_vector_size());

    this->beta = params[0];

    unsigned int k = 1;

    for (auto it = this->gamma.begin(); it != this->gamma.end(); it++) {
        it->second = params[k];
        k++;}

    for (auto it = this->delta.begin(); it != this->delta.end(); it++) {
        it->second = params[k];
        k++;}

    for (auto it = this->delta_temp.begin();
            it != this->delta_temp.end(); it++) {

        it->second = params[k];
        k++;}

    for (auto it = this->theta.begin(); it != this->theta.end(); it++) {
        it->second = params[k];
        k++;}

    for (auto it = this->epsilon0.begin(); it != this->epsilon0.end(); it++) {
        it->second = params[k];
        k++;}
}
