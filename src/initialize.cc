#include "../include/kmm.h"

#include <assert.h>


/// Used by constructors
void Kmm::initialize(
        unsigned int min_cohort_, unsigned int max_cohort_,
        unsigned int min_year_, unsigned int max_year_,
        unsigned int min_age_, unsigned int max_age_) {

    assert(!this->init_bool);

    this->min_cohort = min_cohort_;
    this->max_cohort = max_cohort_;
    this->min_year = min_year_;
    this->max_year = max_year_;
    this->min_age = min_age_;
    this->max_age = max_age_;

    this->beta = 0;
    this->gamma.clear();
    this->delta.clear();
    this->delta_temp.clear();
    this->theta.clear();
    this->epsilon0.clear();

    for (unsigned int k = this->min_cohort; k <= this->max_cohort; k++) {
        this->gamma[k] = 0;
        this->epsilon0[k] = 0;}

    for (unsigned int k = this->min_year+1; k <= this->max_year; k++) {
        this->delta[k] = 0;}

    for (unsigned int k = this->min_year; k <= this->max_year; k++) {
        this->delta_temp[k] = 0;}

    for (unsigned int k = this->min_age+1; k <= this->max_age; k++) {
        this->theta[k] = 0;}

    this->init_bool = true;
}
