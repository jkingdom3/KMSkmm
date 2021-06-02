#ifndef KMSKMM_H
#define KMSKMM_H

#include <KMSdata-1.0/data.h>
#include <KMSmodel-1.0/model.h>

#include <map>
#include <string>
#include <vector>


/// A Model sub-class for the Kingdom Mortality Model (KMM)
/**
 * The KMM is given as:\n\n
 * \f$ \bar{y}_{x,c} = \bar{y}_{x-1,c} + \beta + \gamma\left(c\right)
 * + \delta\left(t\right) + \delta_{temp}\left(t\right)
 * + \theta\left(x\right) \f$\n\n
 * where \f$ y = logit\left(\mu\right) \f$ and \f$ t = x + c \f$,
 * and where \f$ \bar{y}_{x-1,c} \f$ exists, or\n\n
 * \f$ \bar{y}_{x,c} = \bar{y}_{x,c} + \epsilon_{0}\left(c\right) \f$\n\n
 * where \f$ \bar{y}_{x-1,c} \f$ does not exist.
**/

class Kmm: virtual public Model {

protected:
    bool init_bool = false;

    double beta = 0;
    std::map<unsigned int, double> gamma;
    std::map<unsigned int, double> delta;
    std::map<unsigned int, double> delta_temp;
    std::map<unsigned int, double> theta;
    std::map<unsigned int, double> epsilon0;

    std::vector<double> age;
    std::vector<double> year;
    std::vector<double> cohort;
    std::vector<double> log_mx;

public:
    // Get variables
    //double get_beta() const;
    //double get_gamma(const unsigned int cohort) const;
    //double get_delta(const unsigned int year) const;
    //double get_delta_temp(const unsigned int year) const;
    //double get_theta(const unsigned int age) const;
    //double get_epsilon0(const unsigned int cohort_) const;

    // Set variables
    //void set_beta(const double val);
    //void set_gamma(const unsigned int cohort_, const double val);
    //void set_delta(const unsigned int year_, const double val);
    //void set_delta_temp(const unsigned int year_, const double val);
    //void set_theta(const unsigned int age_, const double val);
    //void set_epsilon0(const unsigned int cohort_, const double val);

    // Constructors
    Kmm();
    Kmm(int min_cohort, int max_cohort,
        int min_year, int max_year,
        unsigned int min_age, unsigned int max_age);

    void load_data(Data<double>& X);

    // From parent class model - pure virtual functions
    Data<double> fitted_values() const;
    std::vector<double> fitted_values(const std::vector<double>& params) const;
    void transfer(const std::vector<double>& params);
    void save(const std::string location) const;

    // Other
    //void normalize();
    size_t derive_transfer_vector_size();
    std::vector<double> get_transfer_vector();
    //vector<double> derive_starting_vector(
    //        const bool print_progress = false) const;
};

#endif
