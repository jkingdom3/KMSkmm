#include <KMSdata-1.0/data.h>
#include <KMSkmm-1.0/kmm.h>


int main() {
    // Test 1
    Data<double> X {data::file_to_double("data.csv")};

    //Kmm M(calibration_data);

    //auto [X, Y] {M.extract_calibration_data(calibration_data)};

    //Matrix Y_bar = M.fitted_values(X);
/*
    // Test that epsilon has been calculated correctly
    Y_bar.save(KMS + "/kmm/test/methods/fitted_values/" +
            "output/fitted_values.csv", true, false);
    system(("diff " + KMS + "/kmm/test/methods/fitted_values/" +
            "output/fitted_values.csv " +
            KMS + "/kmm/test/methods/fitted_values/target_output/" +
            "fitted_values.csv").c_str());
*/}
