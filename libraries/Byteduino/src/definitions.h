//Tag types
#define HEARTBEAT "-1"
#define UPDATE_MESSENGER_KEY "-2"
#define GET_RECIPIENT_KEY "-3"

//string sizes
#define TAG_LENGTH 10
#define MAX_SIGNING_PATH_SIZE 20
#define MAX_HUB_STRING_SIZE 30
#define MAX_DEVICE_NAME_STRING_SIZE 25
#define MAX_PAIRING_SECRET_STRING_SIZE 25

//objects
#define MAX_KEYS_COUNT 8
#define MAX_KEY_SIZE 30

//Flash map
#define PREVIOUS_PRV_MESSENGER_KEY 0
#define PREVIOUS_PUB_MESSENGER_KEY 32

#define PAIRED_DEVICES 78
#define PAIRED_DEVICES_FLASH_SIZE 500

#define WALLETS_CREATED 78 + PAIRED_DEVICES_FLASH_SIZE
#define WALLETS_CREATED_FLASH_SIZE 500

#define TOTAL_USED_FLASH 78 + PAIRED_DEVICES_FLASH_SIZE + WALLETS_CREATED_FLASH_SIZE

//messages
#define TO_BE_SENT true
#define RECEIVED false

//time
#define SECONDS_BETWEEN_KEY_ROTATION 3600

//cosigners
#define MAX_COSIGNERS 6

//timeout
#define REQUEST_KEY_TIME_OUT 4

//device specific
#ifdef ESP8266
	#define UNIQUE_WEBSOCKET 1
	#define FEED_WATCHDOG ESP.wdtFeed()
	#define RANDOM_REGISTER 0x3FF20E44
	#define GET_CYCLE_COUNT ESP.getCycleCount()
	#define MAX_MESSAGE_LENGTH 9000
	#define MAX_MESSAGE_COUNT 1
	#define SENT_PACKAGE_BUFFER_SIZE 1000
	#define JSON_BUFFER_SIZE_FOR_RECEIVED_PACKAGE 6500
	#define RECEIVED_PACKAGE_BUFFER_SIZE 7000
	#define RANDOM_POOL_TICKER_RESET 1600
#endif

#ifdef ESP32
	#define UNIQUE_WEBSOCKET 0
	#define FEED_WATCHDOG if (watchdogTimer != NULL) {timerWrite(watchdogTimer, 0);}
	#define RANDOM_REGISTER 0x3FF75144
	#define GET_CYCLE_COUNT ESP.getCycleCount()
	#define MAX_MESSAGE_LENGTH 40000
	#define MAX_MESSAGE_COUNT 1
	#define SENT_PACKAGE_BUFFER_SIZE 5000
	#define JSON_BUFFER_SIZE_FOR_RECEIVED_PACKAGE 30000
	#define RECEIVED_PACKAGE_BUFFER_SIZE 31000
	#define RANDOM_POOL_TICKER_RESET 700
#endif

//return codes
#define SUCCESS 0
#define TEXT_TOO_LONG 1
#define WRONG_PUBKEY_SIZE 2
#define HUB_URL_TOO_LONG 3
#define BUFFER_NOT_FREE 4