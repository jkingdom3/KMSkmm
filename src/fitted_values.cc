#include "../include/kmm.h"

#include <KMSdata-1.0/data.h>

#include <vector>


/// Returns fitted values i.e. \f$ E\left(log\left(m_{x,c}\right)\right) \f$
Data<double> Kmm::fitted_values() const {

    Data<double> y_bar;

    y_bar.insert("E(log_mx)", this->log_mx[0] +
            this->epsilon0.at(this->cohort[0]));

    for (unsigned int k = 1; k < this->age.size(); k++) {
        if (this->cohort[k] == this->cohort[k-1]) {
            y_bar.push_back("E(log_mx)",
                    y_bar["E(log_mx)"][k-1] -
                    this->delta_temp.at(this->year[k-1]) +
                    this->beta +
                    this->gamma.at(this->cohort[k]) +
                    this->delta_temp.at(this->year[k]) +
                    this->delta.at(this->year[k]) +
                    this->theta.at(this->age[k]));}
        else {
            y_bar.push_back("E(log_mx)",
                    this->log_mx[k] +
                    this->epsilon0.at(this->cohort[k]));}}

    return y_bar;
}


/// Returns fitted values i.e. \f$ E\left(log\left(m_{x,c}\right)\right) \f$
std::vector<double> Kmm::fitted_values(
        const std::vector<double>& params) const {

    std::vector<double> y_bar;
    y_bar.reserve(this->age.size());

    y_bar.push_back(this->log_mx[0] +
            this->epsilon0.at(this->cohort[0]));

    for (unsigned int k = 1; k < this->age.size(); k++) {
        if (this->cohort[k] == this->cohort[k-1]) {
            y_bar.push_back(
                    y_bar[k-1] -
                    this->delta_temp.at(this->year[k-1]) +
                    this->beta +
                    this->gamma.at(this->cohort[k]) +
                    this->delta_temp.at(this->year[k]) +
                    this->delta.at(this->year[k]) +
                    this->theta.at(this->age[k]));}
        else {
            y_bar.push_back(
                    this->log_mx[k] +
                    this->epsilon0.at(this->cohort[k]));}}

    return y_bar;
}
