#include "mlkem.h"
#include "esp_log.h"
#include "esp_heap_caps.h"
#include "esp_timer.h"
#include "randombytes.h"
#include <string.h>

static const char *TAG = "ML-KEM";

// ML-KEM-512 parameter sizes
#define MLKEM512_PUBLICKEY_BYTES  800
#define MLKEM512_SECRETKEY_BYTES  1632
#define MLKEM512_CIPHERTEXT_BYTES 768
#define MLKEM512_SHAREDSECRET_BYTES 32

// Simplified placeholder functions for now
static int simple_keypair(uint8_t *pk, uint8_t *sk) {
    // Generate random key material (placeholder)
    randombytes(pk, MLKEM512_PUBLICKEY_BYTES);
    randombytes(sk, MLKEM512_SECRETKEY_BYTES);
    return 0;
}

static int simple_enc(uint8_t *ct, uint8_t *ss, const uint8_t *pk) {
    // Generate random ciphertext and shared secret (placeholder)
    randombytes(ct, MLKEM512_CIPHERTEXT_BYTES);
    randombytes(ss, MLKEM512_SHAREDSECRET_BYTES);
    return 0;
}

static int simple_dec(uint8_t *ss, const uint8_t *ct, const uint8_t *sk) {
    // For now, just generate the same "shared secret" (placeholder)
    randombytes(ss, MLKEM512_SHAREDSECRET_BYTES);
    return 0;
}

void mlkem_test(void) {
    ESP_LOGI(TAG, "Starting ML-KEM-512 test (simplified implementation)...");
    
    // Allocate buffers in PSRAM
    uint8_t *pk = heap_caps_malloc(MLKEM512_PUBLICKEY_BYTES, MALLOC_CAP_SPIRAM);
    uint8_t *sk = heap_caps_malloc(MLKEM512_SECRETKEY_BYTES, MALLOC_CAP_SPIRAM);
    uint8_t *ct = heap_caps_malloc(MLKEM512_CIPHERTEXT_BYTES, MALLOC_CAP_SPIRAM);
    uint8_t *ss1 = heap_caps_malloc(MLKEM512_SHAREDSECRET_BYTES, MALLOC_CAP_SPIRAM);
    uint8_t *ss2 = heap_caps_malloc(MLKEM512_SHAREDSECRET_BYTES, MALLOC_CAP_SPIRAM);
    
    if (!pk || !sk || !ct || !ss1 || !ss2) {
        ESP_LOGE(TAG, "Failed to allocate memory in PSRAM");
        goto cleanup;
    }
    
    ESP_LOGI(TAG, "Memory allocated successfully in PSRAM");
    ESP_LOGI(TAG, "Key sizes - Public: %d, Secret: %d, Ciphertext: %d, Shared Secret: %d", 
             MLKEM512_PUBLICKEY_BYTES, MLKEM512_SECRETKEY_BYTES, 
             MLKEM512_CIPHERTEXT_BYTES, MLKEM512_SHAREDSECRET_BYTES);
    
    // Key generation
    ESP_LOGI(TAG, "Generating keypair...");
    uint64_t start_time = esp_timer_get_time();
    
    if (simple_keypair(pk, sk) != 0) {
        ESP_LOGE(TAG, "Key generation failed");
        goto cleanup;
    }
    
    uint64_t keygen_time = esp_timer_get_time() - start_time;
    ESP_LOGI(TAG, "Key generation took %llu microseconds", keygen_time);
    
    // Encapsulation
    ESP_LOGI(TAG, "Performing encapsulation...");
    start_time = esp_timer_get_time();
    
    if (simple_enc(ct, ss1, pk) != 0) {
        ESP_LOGE(TAG, "Encapsulation failed");
        goto cleanup;
    }
    
    uint64_t enc_time = esp_timer_get_time() - start_time;
    ESP_LOGI(TAG, "Encapsulation took %llu microseconds", enc_time);
    
    // Decapsulation  
    ESP_LOGI(TAG, "Performing decapsulation...");
    start_time = esp_timer_get_time();
    
    if (simple_dec(ss2, ct, sk) != 0) {
        ESP_LOGE(TAG, "Decapsulation failed");
        goto cleanup;
    }
    
    uint64_t dec_time = esp_timer_get_time() - start_time;
    ESP_LOGI(TAG, "Decapsulation took %llu microseconds", dec_time);
    
    ESP_LOGI(TAG, "Framework test completed successfully!");
    ESP_LOGI(TAG, "Performance summary - Keygen: %llu μs, Enc: %llu μs, Dec: %llu μs", 
             keygen_time, enc_time, dec_time);
    ESP_LOGI(TAG, "Note: This is a framework test with placeholder crypto functions");
    
cleanup:
    if (pk) free(pk);
    if (sk) free(sk);
    if (ct) free(ct);
    if (ss1) free(ss1);
    if (ss2) free(ss2);
}
