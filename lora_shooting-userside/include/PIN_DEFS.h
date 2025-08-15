#define USER_ADDRESS (0) // Set user device address
// GPS_PORT
#ifdef TTGO_T_BEAM_V1_1
#define GPS_RX_PIN 34
#define GPS_TX_PIN 12
#else
#define GPS_RX_PIN 9
#define GPS_TX_PIN 8
#define GPS_WAKEUP_PIN 7
#define GPS_1PPS_PIN 6
#endif
// BUZZER_PORT
#define BUZZER_PORT 32
// ENCODER_PORT
#ifdef TTGO_T_BEAM_V1_1
#define CHANNEL_A 15
#define CHANNEL_B 35
// BUTTON_PORT
#define button_channel 38 // Button change channel
// #define button_channel 25
#else
#define CHANNEL_A 48
#define CHANNEL_B 21
#endif
// ENCODER_PORT
#ifdef TTGO_T_BEAM_V1_1
#define PMU_SCL 22
#define PMU_SDA 21
#else
#define PMU_SCL 41
#define PMU_SDA 42
#endif

#ifdef TTGO_T_BEAM_V1_1
#else
#define LORA_SCK 12
#define LORA_MISO 13
#define LORA_MOSI 11
#define LORA_CS 10
#endif

// USE SPI
#define SPI_MOSI (35)

#define SPI_SCK (36)

#define SPI_MISO (37)

#define IMU_CS (34)

#define IMU_INT (33)
