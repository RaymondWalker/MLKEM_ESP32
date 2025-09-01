#include <stdio.h>
#include <inttypes.h>
#include "esp_system.h"
#include "esp_psram.h"
#include "esp_log.h"
#include "esp_heap_caps.h"
#include "mlkem.h"

static const char *TAG = "MAIN";

void app_main(void)
{
    ESP_LOGI(TAG, "ML-KEM ESP32 Demo Starting...");
    
    // Check PSRAM
    if (esp_psram_is_initialized()) {
        ESP_LOGI(TAG, "PSRAM: %u bytes available", (unsigned int)esp_psram_get_size());
    }
    
    // Test ML-KEM
    mlkem_test();
    
    ESP_LOGI(TAG, "Demo completed");
}
