//
//  BitmapCache.cpp
//  xLights
//
//  Created by Daniel Kulp on 4/6/15.
//  Copyright (c) 2015 Daniel Kulp. All rights reserved.
//

#include "xLightsMain.h"


//#include "../include/bars.xpm"
#include "../include/bars-16.xpm"
#include "../include/bars-24.xpm"
#include "../include/bars-32.xpm"
#include "../include/bars-48.xpm"

//#include "../include/butterfly.xpm"
#include "../include/butterfly-16.xpm"
#include "../include/butterfly-24.xpm"
#include "../include/butterfly_32.xpm"
#include "../include/butterfly-48.xpm"

//#include "../include/circles.xpm"
#include "../include/circles-16.xpm"
#include "../include/circles-24.xpm"
#include "../include/circles-32.xpm"
#include "../include/circles-48.xpm"

#include "../include/ColorWash.xpm"
#include "../include/corofaces.xpm"

//#include "../include/curtain.xpm"
#include "../include/curtain-16.xpm"
#include "../include/curtain-24.xpm"
#include "../include/curtain-32.xpm"
#include "../include/curtain-48.xpm"


#include "../include/faces.xpm"

//#include "../include/fire.xpm"
#include "../include/fire-16.xpm"
#include "../include/fire-24.xpm"
#include "../include/fire-32.xpm"
#include "../include/fire-48.xpm"


//#include "../include/fireworks.xpm"
#include "../include/fireworks-16.xpm"
#include "../include/fireworks-24.xpm"
#include "../include/fireworks-32.xpm"
#include "../include/fireworks-48.xpm"

//#include "../include/garlands.xpm"
#include "../include/garlands-16.xpm"
#include "../include/garlands-24.xpm"
#include "../include/garlands-32.xpm"
#include "../include/garlands-48.xpm"

#include "../include/glediator.xpm"
//#include "../include/life.xpm"
#include "../include/life-16.xpm"
#include "../include/life-24.xpm"
#include "../include/life-32.xpm"
#include "../include/life-48.xpm"

//#include "../include/meteors.xpm"
#include "../include/meteors-16.xpm"
#include "../include/meteors-24.xpm"
#include "../include/meteors-32.xpm"
#include "../include/meteors-48.xpm"

#include "../include/morph.xpm"

#include "../include/Off.xpm"
#include "../include/On.xpm"
#include "../include/piano.xpm"

//#include "../include/pictures.xpm"
#include "../include/pictures-16.xpm"
#include "../include/pictures-24.xpm"
#include "../include/pictures-32.xpm"
#include "../include/pictures-48.xpm"

//#include "../include/pinwheel.xpm"
#include "../include/pinwheel-16.xpm"
#include "../include/pinwheel-24.xpm"
#include "../include/pinwheel-32.xpm"
#include "../include/pinwheel-48.xpm"


//#include "../include/ripple.xpm"
#include "../include/ripple-16.xpm"
#include "../include/ripple-24.xpm"
#include "../include/ripple-32.xpm"
#include "../include/ripple-48.xpm"

#include "../include/shimmer.xpm"
#include "../include/singleStrand.xpm"

//#include "../include/snowflakes.xpm"
#include "../include/snowflakes-16.xpm"
#include "../include/snowflakes-24.xpm"
#include "../include/snowflakes-32.xpm"
#include "../include/snowflakes-48.xpm"

//#include "../include/snowstorm.xpm"
#include "../include/snowstorm-16.xpm"
#include "../include/snowstorm-24.xpm"
#include "../include/snowstorm-32.xpm"
#include "../include/snowstorm-48.xpm"

//#include "../include/spirals.xpm"
#include "../include/spirals-16.xpm"
#include "../include/spirals-24.xpm"
#include "../include/spirals-32.xpm"
#include "../include/spirals-48.xpm"

//#include "../include/spirograph.xpm"
#include "../include/spirograph-16.xpm"
#include "../include/spirograph-24.xpm"
#include "../include/spirograph-32.xpm"
#include "../include/spirograph-48.xpm"

#include "../include/strobe.xpm"

//#include "../include/text.xpm"
#include "../include/text-16.xpm"
#include "../include/text-24.xpm"
#include "../include/text-32.xpm"
#include "../include/text-48.xpm"

//#include "../include/tree.xpm"
#include "../include/tree-16.xpm"
#include "../include/tree-24.xpm"
#include "../include/tree-32.xpm"
#include "../include/tree-48.xpm"

//#include "../include/twinkle.xpm"
#include "../include/twinkle-16.xpm"
#include "../include/twinkle-24.xpm"
#include "../include/twinkle-32.xpm"
#include "../include/twinkle-48.xpm"

//#include "../include/wave.xpm"
#include "../include/wave-16.xpm"
#include "../include/wave-24.xpm"
#include "../include/wave-32.xpm"
#include "../include/wave-48.xpm"


#ifdef __WXOSX__
double xlOSXGetMainScreenContentScaleFactor();
#endif

class EffectBitmapCache {
public:
    EffectBitmapCache() {
    }

    const wxBitmap &get(int size,
                        int eff,
                        const char **data16,
                        const char **data24,
                        const char **data32,
                        const char **data48) {

        std::map<int, wxBitmap> *data = &size16;
        const char ** dc = data16;
        if (size <= 16) {
            data = &size16;
            size = 16;
            dc = data16;
        } else if (size <= 24) {
            data = &size24;
            size = 24;
            dc = data24;
        } else if (size <= 32) {
            data = &size32;
            size = 32;
            dc = data32;
        } else {
            data = &size48;
            size = 48;
            dc = data48;
        }

#ifdef __WXOSX__
        double scale = 1.0;
        //Retina Display, use the larger icons with the scale factor set
        if (xlOSXGetMainScreenContentScaleFactor() > 1.9) {
            if (size == 16) {
                size = 32;
                scale = 2.0;
                dc = data32;
            } else if (size == 24) {
                size = 48;
                scale = 2.0;
                dc = data48;
            }
        }
        const wxBitmap &bmp = (*data)[eff];
        if (!bmp.IsOk()) {
            wxImage image(dc);
            if (image.GetSize() == wxSize(size, size)) {
                (*data)[eff] = wxBitmap(image, -1, scale);
            } else {
                wxImage scaled = image.Scale(size, size, wxIMAGE_QUALITY_HIGH);
                (*data)[eff] = wxBitmap(scaled, -1, scale);
            }
        }
#else
        const wxBitmap &bmp = (*data)[eff];
        if (!bmp.IsOk()) {
            wxImage image(dc);
            if (image.GetSize() == wxSize(size, size)) {
                (*data)[eff] = wxBitmap(image);
            } else {
                wxImage scaled = image.Scale(size, size, wxIMAGE_QUALITY_HIGH);
                (*data)[eff] = wxBitmap(scaled);
            }
        }
#endif
        return (*data)[eff];
    }

    std::map<int, wxBitmap> size16;
    std::map<int, wxBitmap> size24;
    std::map<int, wxBitmap> size32;
    std::map<int, wxBitmap> size48;

} effectBitmaps;


const wxBitmap &xLightsFrame::GetIcon(int effectID, wxString &toolTip, int size)
{
    switch(effectID)
    {
        case xLightsFrame::RGB_EFFECTS_e::eff_OFF:
            toolTip = "Off";
            return effectBitmaps.get(size, effectID, Off, Off, Off, Off);
        case xLightsFrame::RGB_EFFECTS_e::eff_ON:
            toolTip = "On";
            return effectBitmaps.get(size, effectID, On, On, On, On);
        case xLightsFrame::RGB_EFFECTS_e::eff_BARS:
            toolTip = "Bars";
            return effectBitmaps.get(size, effectID, bars_16, bars_24, bars_32, bars_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_BUTTERFLY:
            toolTip = "Butterfly";
            return effectBitmaps.get(size, effectID, butterfly_16, butterfly_24, butterfly_32, butterfly_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_CIRCLES:
            toolTip = "Circles";
            return effectBitmaps.get(size, effectID, circles_16, circles_24, circles_32, circles_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_COLORWASH:
            toolTip = "ColorWash";
            return effectBitmaps.get(size, effectID, ColorWash, ColorWash, ColorWash, ColorWash);
        case xLightsFrame::RGB_EFFECTS_e::eff_COROFACES:
            toolTip = "Coro Faces";
            return effectBitmaps.get(size, effectID, corofaces, corofaces, corofaces, corofaces);
        case xLightsFrame::RGB_EFFECTS_e::eff_CURTAIN:
            toolTip = "Curtain";
            return effectBitmaps.get(size, effectID, curtain_16, curtain_24, curtain_32, curtain_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_FACES:
            toolTip = "Matrix Faces";
            return effectBitmaps.get(size, effectID, faces, faces, faces, faces);
        case xLightsFrame::RGB_EFFECTS_e::eff_FIRE:
            toolTip = "Fire";
            return effectBitmaps.get(size, effectID, fire_16, fire_24, fire_32, fire_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_FIREWORKS:
            toolTip = "Fireworks";
            return effectBitmaps.get(size, effectID, fireworks_16, fireworks_24, fireworks_32, fireworks_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_GARLANDS:
            toolTip = "Garlands";
            return effectBitmaps.get(size, effectID, garlands_16, garlands_24, garlands_32, garlands_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_GLEDIATOR:
            toolTip = "Glediator";
            return effectBitmaps.get(size, effectID, glediator, glediator, glediator, glediator);
        case xLightsFrame::RGB_EFFECTS_e::eff_LIFE:
            toolTip = "Life";
            return effectBitmaps.get(size, effectID, life_16, life_24, life_32, life_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_METEORS:
            toolTip = "Meteors";
            return effectBitmaps.get(size, effectID, meteors_16, meteors_24, meteors_32, meteors_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_MORPH:
            toolTip = "Morph";
            return effectBitmaps.get(size, effectID, morph, morph, morph, morph);
        case xLightsFrame::RGB_EFFECTS_e::eff_PIANO:
            toolTip = "Piano";
            return effectBitmaps.get(size, effectID, piano, piano, piano, piano);
        case xLightsFrame::RGB_EFFECTS_e::eff_PICTURES:
            toolTip = "Pictures";
            return effectBitmaps.get(size, effectID, pictures_16, pictures_24, pictures_32, pictures_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_PINWHEEL:
            toolTip = "Pinwheel";
            return effectBitmaps.get(size, effectID, pinwheel_16, pinwheel_24, pinwheel_32, pinwheel_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_RIPPLE:
            toolTip = "Ripple";
            return effectBitmaps.get(size, effectID, ripple_16, ripple_24, ripple_32, ripple_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_SHIMMER:
            toolTip = "Shimmer";
            return effectBitmaps.get(size, effectID, shimmer, shimmer, shimmer, shimmer);
        case xLightsFrame::RGB_EFFECTS_e::eff_SINGLESTRAND:
            toolTip = "Single Strand";
            return effectBitmaps.get(size, effectID, singleStrand, singleStrand, singleStrand, singleStrand);
        case xLightsFrame::RGB_EFFECTS_e::eff_SNOWFLAKES:
            toolTip = "Snow Flakes";
            return effectBitmaps.get(size, effectID, snowflakes_16, snowflakes_24, snowflakes_32, snowflakes_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_SNOWSTORM:
            toolTip = "Snow Storm";
            return effectBitmaps.get(size, effectID, snowstorm_16, snowstorm_24, snowstorm_32, snowstorm_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_SPIRALS:
            toolTip = "Spirals";
            return effectBitmaps.get(size, effectID, spirals_16, spirals_24, spirals_32, spirals_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_SPIROGRAPH:
            toolTip = "Spirograph";
            return effectBitmaps.get(size, effectID, spirograph_16, spirograph_24, spirograph_32, spirograph_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_STROBE:
            toolTip = "Strobe";
            return effectBitmaps.get(size, effectID, strobe, strobe, strobe, strobe);
        case xLightsFrame::RGB_EFFECTS_e::eff_TEXT:
            toolTip = "Text";
            return effectBitmaps.get(size, effectID, text_16, text_24, text_32, text_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_TREE:
            toolTip = "Tree";
            return effectBitmaps.get(size, effectID, tree_16, tree_24, tree_32, tree_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_TWINKLE:
            toolTip = "Twinkle";
            return effectBitmaps.get(size, effectID, twinkle_16, twinkle_24, twinkle_32, twinkle_48);
        case xLightsFrame::RGB_EFFECTS_e::eff_WAVE:
            toolTip = "Wave";
            return effectBitmaps.get(size, effectID, wave_16, wave_24, wave_32, wave_48);
        default:
            break;
    }
    toolTip = "Off";
    return effectBitmaps.get(size, effectID, Off, Off, Off, Off);
}
