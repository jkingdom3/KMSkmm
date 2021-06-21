#include <KMSdata-1.0/data.h>
#include <KMSkmm-1.0/kmm.h>
#include <KMSoptim-1.0/optim.h>

#include <assert.h>

#include <vector>


int main() {

    Data<double> X {data::file_to_double("data.csv")};
    Kmm M(X);

    std::vector<double> minimum_values;
    minimum_values.reserve(M.derive_transfer_vector_size());
    std::vector<double> maximum_values;
    maximum_values.reserve(M.derive_transfer_vector_size());

    for (auto k = 0; k < M.derive_transfer_vector_size(); k++) {
        minimum_values.push_back(-0.5);
        maximum_values.push_back(0.5);}

    std::vector<double> starting_vector(M.derive_transfer_vector_size());
    bool print_progress {true};
    double parameter_tol=1e-4;
    double objective_tol=1e-3;
    unsigned int iteration_limit {200};

    M.fit(model::errors, maths::ssq,
            optim::golden_section_multiple, minimum_values, maximum_values,
            print_progress, parameter_tol, objective_tol, iteration_limit,
            starting_vector);

    return 0;
}
