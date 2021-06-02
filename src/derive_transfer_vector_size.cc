#include "../include/kmm.h"


/// Returns the size of the vector required for the transfer method
/**
 * Useful e.g. in specifying optim ranges as the size of the vector required
 * depends on the data
*/
size_t Kmm::derive_transfer_vector_size() {
    
    return 1 + this->gamma.size() +
            this->delta.size() + this->delta_temp.size() +
            this->theta.size() + this->epsilon0.size();
}
