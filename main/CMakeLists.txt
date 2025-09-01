idf_component_register(SRCS "mlkem_esp32.c"
                      INCLUDE_DIRS "."
                      REQUIRES mlkem esp_timer
                      PRIV_REQUIRES esp_psram)
