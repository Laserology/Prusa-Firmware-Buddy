// window_qr.hpp

#pragma once

#include "window.hpp"

class window_qr_t : public AddSuperWindow<window_t> {
public:
    window_qr_t(window_t *parent, Rect16 rect, uint16_t error_num, Align_t align = Align_t::Center());
    window_qr_t(window_t *parent, Rect16 rect, const char *txt);
    window_qr_t(window_t *parent, Rect16 rect, Align_t align = Align_t::LeftTop());

    static constexpr uint16_t MAX_LEN_4QR = 256;
    void SetQRHeader(uint16_t err_num);
    void SetText(const char *txt);
    const char *GetQRShortText();
    const char *GetQRLongText();

protected:
    /// Defines maximal size of QR code and buffers needed for generating. Keep it low.
    static constexpr uint8_t qr_version_max = 9;

    // QR Header vars
    char text[MAX_LEN_4QR + 1];
    uint16_t error_num;
    // 8 bit
    uint8_t border; /// border size in pixels; same for all sides
    uint8_t px_per_module; /// width/height of module (single colored square)
    Align_t align; /// alignment of QR code in the window
    // other
    bool scale; /// changes px_per_module so the QR code is the biggest that fits in the window

protected:
    virtual void unconditionalDraw() override;
};
