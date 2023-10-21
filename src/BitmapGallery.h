#include <wx/wx.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

enum BitmapScaling : int
{
    Center = 0,
    Fit,
    FullWidth,
    FullHeight
};

class BitmapGallery : public wxWindow
{
public:
    BitmapGallery(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = 0);

    void OnPaint(wxPaintEvent &);

    void DrawBitmap(wxGraphicsContext *, const wxSize &);

    wxBitmap bitmap;

    BitmapScaling scaling;
};

BitmapGallery::BitmapGallery(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style)
    : wxWindow(parent, wxID_ANY, pos, size, wxFULL_REPAINT_ON_RESIZE | style)
{
    this->SetBackgroundStyle(wxBG_STYLE_PAINT); // Required

    this->Bind(wxEVT_PAINT, &BitmapGallery::OnPaint, this);
}

void BitmapGallery::OnPaint(wxPaintEvent &e)
{
    wxBufferedPaintDC dc(this);
    dc.Clear();

    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    if (gc && bitmap.IsOk())
    {
        const wxSize drawSize = this->GetClientSize();
        DrawBitmap(gc, drawSize);

        delete gc;
    }
}

void BitmapGallery::DrawBitmap(wxGraphicsContext *gc, const wxSize &drawSize)
{
    const auto windowSize = ToDIP(drawSize);
    const auto imageSize = bitmap.GetSize();

    double width = imageSize.GetWidth();
    double height = imageSize.GetHeight();

    if (scaling == BitmapScaling::Fit)
    {
        double scaleX = 1.0 * windowSize.x / imageSize.x;
        double scaleY = 1.0 * windowSize.y / imageSize.y;

        double scale = scaleX < scaleY ? scaleX : scaleY;
        width *= scale;
        height *= scale;
    }
    else if (scaling == BitmapScaling::FullWidth)
    {
        double scale = 1.0 * windowSize.x / imageSize.x;
        width *= scale;
        height *= scale;
    }
    else if (scaling == BitmapScaling::FullHeight)
    {
        double scale = 1.0 * windowSize.y / imageSize.y;
        width *= scale;
        height *= scale;
    }

    const double imageCenterX = width / 2;
    const double imageCenterY = height / 2;

    const double windowCenterX = windowSize.x / 2;
    const double windowCenterY = windowSize.y / 2;

    const double deltaRectangleX = windowCenterX - imageCenterX;
    const double deltaRectangleY = windowCenterY - imageCenterY;

    gc->DrawBitmap(bitmap,
                   FromDIP(deltaRectangleX), FromDIP(deltaRectangleY),
                   FromDIP(width), FromDIP(height));
}