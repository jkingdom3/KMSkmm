#include <KMSkmm-1.0/kmm.h>

#include <assert.h>


int main() {

    Kmm M(1900, 1930, 1950, 1980, 30, 80);

    int beta_size {1};
    int gamma_size {1980 - 1950 + 1};
    int delta_size {1980 - 1950 + 1 - 1};
    int delta_temp_size {1980 - 1950 + 1 - 1};
    int theta_size {80 - 30 + 1 - 1};
    int epsilon0_size {1980 - 1950 + 1};

    assert(M.derive_transfer_vector_size() ==
            beta_size + gamma_size + delta_size +
            delta_temp_size + theta_size + epsilon0_size);

    return 0;
}
