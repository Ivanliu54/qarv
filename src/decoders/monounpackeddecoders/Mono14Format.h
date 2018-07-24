#pragma once

#include "decoders/monounpacked.h"
extern "C" {
  #include <arv.h>
}

namespace QArv
{

class Mono14Format : public QObject, public QArvPixelFormat {
    Q_OBJECT
    Q_INTERFACES(QArvPixelFormat)
    Q_PLUGIN_METADATA(IID "si.ad-vega.qarv.Mono14Format")
public:
    ArvPixelFormat pixelFormat() { return ARV_PIXEL_FORMAT_MONO_14; }
    QArvDecoder* makeDecoder(QSize size) {
        return new MonoUnpackedDecoder<uint16_t, 14, ARV_PIXEL_FORMAT_MONO_14>(
            size);
    }
};

}