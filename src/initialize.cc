#include "../include/kmm.h"

#include <assert.h>


/// Used by constructors
void Kmm::initialize(
        unsigned int min_cohort, unsigned int max_cohort,
        unsigned int min_year, unsigned int max_year,
        unsigned int min_age, unsigned int max_age) {

    assert(!this->init_bool);

    this->beta = 0;
    this->gamma.clear();
    this->delta.clear();
    this->delta_temp.clear();
    this->theta.clear();
    this->epsilon0.clear();

    for (unsigned int k = min_cohort; k <= max_cohort; k++) {
        this->gamma[k] = 0;
        this->epsilon0[k] = 0;}

    for (unsigned int k = min_year+1; k <= max_year; k++) {
        this->delta[k] = 0;}

    for (unsigned int k = min_year; k <= max_year; k++) {
        this->delta_temp[k] = 0;}

    for (unsigned int k = min_age+1; k <= max_age; k++) {
        this->theta[k] = 0;}

    this->init_bool = true;
}
