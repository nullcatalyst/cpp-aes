#pragma once

#include <cstdint> // uint8_t
#include <cstring> // memcpy

namespace aes {
    constexpr int BlockLength = 16;
    constexpr int KeyLength = 32;

    using Key = uint8_t[KeyLength];
    using IV = uint8_t[BlockLength];

    class Context {
        static constexpr int KeyExpSize = 240;

        uint8_t roundKey[KeyExpSize];
        IV iv;

    public:
        Context();
        Context(const Key key, const IV iv);

        /**
         * Set the key.
         * @param key The key.
         */
        void setKey(const Key key);

        /**
         * Set the initialization vector.
         * @param iv The initialize vector.
         */
        void setIV(const IV iv) {
            memcpy(this->iv, iv, sizeof(this->iv));
        }

        void encrypt(void * buffer, uint32_t length);
        void decrypt(void * buffer, uint32_t length);
    };
}
