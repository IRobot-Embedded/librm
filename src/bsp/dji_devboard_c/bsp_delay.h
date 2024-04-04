
#ifndef EC_LIB_DJI_C_BSP_DELAY_H
#define EC_LIB_DJI_C_BSP_DELAY_H

#include "hal_wrapper/hal.h"

#if defined(STM32F407xx)

#include "bsp/interface/bsp_delay_interface.h"
#include "modules/typedefs.h"

namespace irobot_ec::bsp::dji_devboard_c {

/**
 * @brief 延时功能实现
 * @note  单例类，不能实例化，使用时通过bsp工厂获取实例
 */
class Delay : public DelayInterface {
 public:
  // 禁止实例化
  Delay(const Delay &) = delete;
  Delay &operator=(const Delay &) = delete;

  void DelayUs(uint32_t us) override;
  void DelayMs(uint32_t ms) override;

  static Delay &GetInstance();

 private:
  Delay() = default;
  ~Delay() = default;
};

}  // namespace irobot_ec::bsp::dji_devboard_c

#endif

#endif  // EC_LIB_DJI_C_BSP_DELAY_H