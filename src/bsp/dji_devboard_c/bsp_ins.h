/**
 * @file    bsp/dji_devboard_c/bsp_ins.h
 * @brief   大疆C板惯导
 * @todo    温控未实现
 */

#ifndef EC_LIB_DJI_C_BSP_INS_H
#define EC_LIB_DJI_C_BSP_INS_H

#include "hal_wrapper/hal.h"

#if defined(HAL_I2C_MODULE_ENABLED) && defined(HAL_SPI_MODULE_ENABLED) && defined(HAL_TIM_MODULE_ENABLED) && \
    defined(STM32F407xx)

#include "i2c.h"
#include "spi.h"
#include "tim.h"

#include "bsp/interface/bsp_ins_interface.h"
#include "components/sensor/bmi088/bmi088.h"
#include "components/sensor/ist8310/ist8310.h"
#include "modules/algorithm/mahony/mahony_ahrs.h"
#include "modules/typedefs.h"

namespace irobot_ec::bsp::dji_devboard_c {

/**
 * @brief 大疆C板惯导功能实现
 * @note  单例类，不能实例化，使用时通过bsp工厂获取实例
 */
class Ins : public InsInterface {
 public:
  explicit Ins(fp32 sample_rate = 1000.0f);
  ~Ins() override = default;

  [[nodiscard]] fp32 acc_x() const override;
  [[nodiscard]] fp32 acc_y() const override;
  [[nodiscard]] fp32 acc_z() const override;
  [[nodiscard]] fp32 gyro_x() const override;
  [[nodiscard]] fp32 gyro_y() const override;
  [[nodiscard]] fp32 gyro_z() const override;
  [[nodiscard]] fp32 mag_x() const override;
  [[nodiscard]] fp32 mag_y() const override;
  [[nodiscard]] fp32 mag_z() const override;
  [[nodiscard]] fp32 yaw() const override;
  [[nodiscard]] fp32 pitch() const override;
  [[nodiscard]] fp32 roll() const override;
  [[nodiscard]] fp32 quat_w() const override;
  [[nodiscard]] fp32 quat_x() const override;
  [[nodiscard]] fp32 quat_y() const override;
  [[nodiscard]] fp32 quat_z() const override;
  [[nodiscard]] fp32 temperature() const;

  void Update() override;
  void BypassMagnetometer(bool bypass);

 private:
  components::sensor::BMI088 bmi088_;
  components::sensor::IST8310 ist8310_;
  modules::algorithm::MahonyAhrs mahony_;
  TIM_HandleTypeDef *heater_pwm_;

  fp32 acc_[3]{0};
  fp32 gyro_[3]{0};
  fp32 mag_[3]{0};
  fp32 ypr_[3]{0};
  fp32 quaternion_[4]{0};
  fp32 temperature_{};

  bool bypass_mag_{true};
};

}  // namespace irobot_ec::bsp::dji_devboard_c

#endif

#endif  // EC_LIB_DJI_C_BSP_INS_H
