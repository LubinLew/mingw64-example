#include <windows.h>

#include <http.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    auto download_url {"https://curl.se/logo/curl-logo.svg"};

    auto sotre_path   {"curl.svg"};

    http_get(download_url, sotre_path);

    return 0;
}
