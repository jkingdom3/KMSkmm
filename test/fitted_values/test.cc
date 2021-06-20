#include <KMSdata-1.0/data.h>
#include <KMSkmm-1.0/kmm.h>

#include <assert.h>


int main() {
    // Test 1
    Data<double> X {data::file_to_double("data.csv")};
    Kmm M(X);

    Data<double> Y_bar = M.fitted_values();

    Data<double> solution {data::file_to_double("solution.csv")};

    for (unsigned int k = 0; k < Y_bar.nrows(); k++) {
        assert(abs(Y_bar["E(log_mx)"][k] - solution["E(log_mx)"][k]) < 1e-6);}
}
