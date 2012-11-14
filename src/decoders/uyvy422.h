/*
    qarv, a Qt interface to aravis.
    Copyright (C) 2012  Jure Varlec <jure.varlec@ad-vega.si>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UYVY422_H
#define UYVY422_H

#include "api/qarvdecoder.h"
extern "C" {
#include <libswscale/swscale.h>
}

class UYVY422Decoder : public QArvDecoder {
public:
  UYVY422Decoder(QSize size);
  ~UYVY422Decoder();
  QImage decode(QByteArray frame);
  QString pixelFormat() { return "YUV422Packed"; }
  QString ffmpegPixelFormat() { return "uyvy422"; }
  bool isGrayscale() { return false; }

private:
  QSize size;
  struct SwsContext* ctx;
  const uint8_t* channel_pointers[3];
  int channel_strides[3];
  uint8_t* image_pointers[3];
  int image_strides[3];
};

class UYVY422Format : public QObject, public QArvPixelFormat {
  Q_OBJECT
  Q_INTERFACES(QArvPixelFormat)

public:
  QString pixelFormat() { return "YUV422Packed"; }
  QArvDecoder* makeDecoder(QSize size) { return new UYVY422Decoder(size); }
};

#endif