#include "../include/kmm.h"

#include <KMScommon-1.0/common.h>

#include <boost/lexical_cast.hpp>

#include <string>


/// Saves a model in a given folder
/**
 * Saves the following files:
 * - beta.csv
 * - gamma.csv
 * - delta.csv
 * - delta_temp.csv
 * - theta.csv
 * - epsilon0.csv
*/
void Kmm::save(const string folder) const {
    if (!common::file_exists(folder)) {
        system(string("mkdir " + folder).c_str());}

    system(string("echo " + boost::lexical_cast<std::string>(this->beta) +
            " > " + folder + "/beta.csv").c_str());

    common::write_file(gamma, folder + "/gamma.csv");
    common::write_file(delta, folder + "/delta.csv");
    common::write_file(delta_temp, folder + "/delta_temp.csv");
    common::write_file(theta, folder + "/theta.csv");
    common::write_file(epsilon0, folder + "/epsilon0.csv");

//    Data<double> beta_output;
//    beta_output.insert("beta", this->beta);

//    auto save_as_matrix = [this](const map<unsigned int, double>& x,
//            const vector<string> colnames, const string filename) {
//        Matrix X(x.size(), 2);
//        unsigned int k = 0;
//        for (auto it = x.begin(); it != x.end(); it++) {
//            X.set(k, 0, double {it->first});
//            X.set(k, 1, it->second);
//            k++;}
//        X.set_colnames(colnames);
//        X.save(filename, true, false);};

//    save_as_matrix(this->gamma, vector<string> {"Cohort", "gamma"},
//            folder + "/gamma.csv");

//    save_as_matrix(this->delta, vector<string> {"Year", "delta_temp"},
//            folder + "/delta.csv");

//    save_as_matrix(this->delta_temp, vector<string> {"Year", "delta_temp"},
//            folder + "/delta_temp.csv");

//    save_as_matrix(this->theta, vector<string> {"Age", "Theta"},
//            folder + "/theta.csv");

//    save_as_matrix(this->epsilon0, vector<string> {"Cohort", "epsilon0"},
//            folder + "/epsilon0.csv");
}
