#include <UnitTest++/UnitTest++.h>
#include "shifr.h"
#include <codecvt>
#include <locale>
#include <string>
#include <iostream>
SUITE(ShifrTests)
{
    TEST(ValidKeyTest) {
        Shifr shifr(5);
        int result = shifr.getValidKey(5);
        int expected = 5;
        if (result != expected) {
            std::cout << "Expected: " << expected << " but got: " << result << std::endl;
        }
        CHECK_EQUAL(expected, result);
    }

    TEST(InvalidKeyTest) {
        Shifr shifr(5);
        try {
            shifr.getValidKey(-1);
            CHECK(false);
        } catch (const cipher_error& e) {
            CHECK(true);
        }

        try {
            shifr.getValidKey(0);
            CHECK(false);
        } catch (const cipher_error& e) {
            CHECK(true);
        }

        try {
            shifr.getValidKey('A');
            CHECK(false);
        } catch (const cipher_error& e) {
            CHECK(true);
        }
    }
    TEST(EncryptTest) {
        Shifr shifr(3);
        std::wstring result = shifr.encrypt(L"Пример текста для шифрования");
        std::wstring expected = L"ИРЕТД ФВИ РЕТС ЯИОН ПМ КАЛШРАЯ";

        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::string result_str = converter.to_bytes(result);
        std::string expected_str = converter.to_bytes(expected);

        CHECK_EQUAL(expected_str, result_str);
    }
    TEST(DecryptTest) {
        Shifr shifr(3);
        std::wstring encrypted = shifr.encrypt(L"Пример текста");
        std::wstring result = shifr.decrypt(encrypted);
        std::wstring expected = L"ПРИМЕР ТЕКСТА";

        // Конвертация в std::string для сравнения с CHECK_EQUAL
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::string result_str = converter.to_bytes(result);
        std::string expected_str = converter.to_bytes(expected);
        CHECK_EQUAL(expected_str, result_str);
    }

    TEST(ValidOpenTextTest) {
        Shifr shifr(3);
        std::wstring result = shifr.getValidOpenText(L"пример текста");
        std::wstring expected = L"ПРИМЕР ТЕКСТА";

        // Конвертация в std::string для сравнения с CHECK_EQUAL
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::string result_str = converter.to_bytes(result);
        std::string expected_str = converter.to_bytes(expected);

        CHECK_EQUAL(expected_str, result_str);
    }

    TEST(ValidCipherTextTest) {
        Shifr shifr(3);
        std::wstring result = shifr.getValidCipherText(L"ШИФРОВАННЫЙ ТЕКСТ");
        std::wstring expected = L"ШИФРОВАННЫЙ ТЕКСТ";

        // Конвертация в std::string для сравнения с CHECK_EQUAL
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::string result_str = converter.to_bytes(result);
        std::string expected_str = converter.to_bytes(expected);

        CHECK_EQUAL(expected_str, result_str);
    }

    TEST(InvalidCipherTextTest) {
        Shifr shifr(3);
        CHECK_THROW(shifr.getValidCipherText(L"Шифр с цифрами: 123456"), cipher_error);
    }

}

int main()
{
    std::locale::global(std::locale("ru_RU.UTF-8"));
    return UnitTest::RunAllTests();
}
