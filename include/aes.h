#include <cstdint> // uint8_t
#include <cstring> // memcpy

namespace aes {
    constexpr int BlockLength = 16;
    constexpr int KeyLength = 32;

    class Context {
        static constexpr int KeyExpSize = 240;

        uint8_t roundKey[KeyExpSize];
        uint8_t iv[BlockLength];

    public:
        Context();
        Context(uint8_t * key, uint8_t * iv);

        /**
         * Set the key.
         * @param key The key.
         */
        void setKey(uint8_t * key);

        /**
         * Set the initialization vector.
         * @param iv The initialize vector.
         */
        void setIV(uint8_t * iv) {
            memcpy(this->iv, iv, sizeof(this->iv));
        }

        void encrypt(uint8_t * buffer, uint32_t length);
        void decrypt(uint8_t * buffer, uint32_t length);
    };
}
