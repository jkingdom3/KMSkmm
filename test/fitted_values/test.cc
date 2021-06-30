#include <KMSdata-1.0/data.h>
#include <KMSkmm-1.0/kmm.h>

#include <assert.h>

#include <vector>


int main() {
    // Test 1
    Data<double> X {data::file_to_double("data.csv")};
    Kmm M(X);

    Data<double> Y_bar = M.fitted_values();

    std::vector<double> params(M.derive_transfer_vector_size());
    std::vector<double> y_bar2 = M.fitted_values(params);
    Data<double> Y_bar2;
    Y_bar2.insert("E(log_mx)", y_bar2);
    Data<double> solution {data::file_to_double("solution.csv")};

    for (unsigned int k = 0; k < Y_bar.nrows(); k++) {
        assert(abs(Y_bar["E(log_mx)"][k] - solution["E(log_mx)"][k]) < 1e-6);
        assert(abs(Y_bar2["E(log_mx)"][k] - solution["E(log_mx)"][k]) < 1e-6);}
    assert(Y_bar.nrows() == 10120);
    assert(Y_bar.ncols() == 1);
    assert(Y_bar2.nrows() == 10120);
    assert(Y_bar2.ncols() == 1);
}
