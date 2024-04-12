/**
 * @file  components/supercap/supercap.h
 * @brief 超级电容
 */

#ifndef EC_LIB_COMPONENTS_SUPERCAP_SUPERCAP_H
#define EC_LIB_COMPONENTS_SUPERCAP_SUPERCAP_H

#include "hal/hal.h"
#if defined(HAL_CAN_MODULE_ENABLED)

#include "bsp/bsp.h"
#include "bsp/common/can_device.h"
#include "modules/typedefs.h"

namespace irobot_ec::components {

/**
 * @brief 超级电容的错误flags各位的定义
 */
enum class SuperCapError : u16 {
  kOverVoltage = 1u << 0,
  kOverCurrent = 1u << 1,
  kUnderVoltage = 1u << 2,
  kInputUnderVoltage = 1u << 3,
  kNoData = 1u << 4,

  // 5-15 reserved
};

/**
 * @brief 超级电容
 */
class SuperCap final : public bsp::CanDeviceBase {
 public:
  explicit SuperCap(bsp::CanBase &can);
  SuperCap() = delete;
  ~SuperCap() override = default;

  [[nodiscard]] f32 voltage() const;
  [[nodiscard]] f32 current() const;
  [[nodiscard]] bool error(SuperCapError error) const;

  void UpdateChassisBuffer(i16 power_buffer);
  void UpdateSettings(i16 power_limit, i16 output_limit, i16 input_limit, bool power_switch, bool enable_log);
  void RxCallback(const bsp::CanRxMsg *msg) override;

 private:
  u8 tx_buf_[8]{0};

  f32 voltage_{};
  f32 current_{};
  u16 error_flags_{};
};

}  // namespace irobot_ec::components

#endif

#endif  // EC_LIB_COMPONENTS_SUPERCAP_SUPERCAP_H
