#ifndef MLKEM_H
#define MLKEM_H

#include <stdint.h>

// ML-KEM-512 parameters
#define MLKEM512_PUBLIC_KEY_BYTES 800
#define MLKEM512_SECRET_KEY_BYTES 1632
#define MLKEM512_CIPHERTEXT_BYTES 768
#define MLKEM512_SHARED_SECRET_BYTES 32

// Test function
void mlkem_test(void);

#endif // MLKEM_H
