/*
  Copyright (c) 2024 XDU-IRobot

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

/**
 * @file  modules/freertos.h
 * @brief 检测FreeRTOS是否可用
 */

#ifndef IROBOTEC_MODULES_FREERTOS_H
#define IROBOTEC_MODULES_FREERTOS_H

#if defined(__GNUC__) || defined(__clang__)
#if __has_include("cmsis_os.h")
#define IROBOTEC_USE_FREERTOS
#include "cmsis_os.h"
#else
#warning "FreeRTOS is not available."
#endif
#else
#error "Unsupported compiler, please use GCC or Clang."
#endif

#endif  // IROBOTEC_MODULES_FREERTOS_H
