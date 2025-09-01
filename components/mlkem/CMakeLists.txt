# Remove the existing PQClean copy and set up properly
file(REMOVE_RECURSE "${CMAKE_CURRENT_SOURCE_DIR}/PQClean")

# Get ML-KEM source files (excluding our wrapper)
file(GLOB PQCLEAN_SRCS 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)
# Remove our wrapper from the PQClean sources
list(REMOVE_ITEM PQCLEAN_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/mlkem.c")

idf_component_register(
    SRCS "mlkem.c" ${PQCLEAN_SRCS}
    INCLUDE_DIRS "include" "."
    REQUIRES mbedtls esp_timer
    PRIV_REQUIRES esp_psram
)

# Add optimization flags
target_compile_options(${COMPONENT_LIB} PRIVATE -O2 -fomit-frame-pointer)
