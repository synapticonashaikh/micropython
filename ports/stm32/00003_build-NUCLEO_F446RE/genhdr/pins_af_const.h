    { MP_ROM_QSTR(MP_QSTR_AF1_TIM1),       MP_ROM_INT(GPIO_AF1_TIM1) },
    { MP_ROM_QSTR(MP_QSTR_AF1_TIM2),       MP_ROM_INT(GPIO_AF1_TIM2) },
    { MP_ROM_QSTR(MP_QSTR_AF2_TIM3),       MP_ROM_INT(GPIO_AF2_TIM3) },
    { MP_ROM_QSTR(MP_QSTR_AF2_TIM4),       MP_ROM_INT(GPIO_AF2_TIM4) },
    { MP_ROM_QSTR(MP_QSTR_AF2_TIM5),       MP_ROM_INT(GPIO_AF2_TIM5) },
    { MP_ROM_QSTR(MP_QSTR_AF3_TIM10),      MP_ROM_INT(GPIO_AF3_TIM10) },
    { MP_ROM_QSTR(MP_QSTR_AF3_TIM11),      MP_ROM_INT(GPIO_AF3_TIM11) },
    { MP_ROM_QSTR(MP_QSTR_AF3_TIM8),       MP_ROM_INT(GPIO_AF3_TIM8) },
    { MP_ROM_QSTR(MP_QSTR_AF3_TIM9),       MP_ROM_INT(GPIO_AF3_TIM9) },
#if defined(MICROPY_HW_I2C1_SCL)
    { MP_ROM_QSTR(MP_QSTR_AF4_I2C1),       MP_ROM_INT(GPIO_AF4_I2C1) },
#endif
#if defined(MICROPY_HW_I2C2_SCL)
    { MP_ROM_QSTR(MP_QSTR_AF4_I2C2),       MP_ROM_INT(GPIO_AF4_I2C2) },
#endif
#if defined(MICROPY_HW_I2C3_SCL)
    { MP_ROM_QSTR(MP_QSTR_AF4_I2C3),       MP_ROM_INT(GPIO_AF4_I2C3) },
#endif
#if defined(MICROPY_HW_I2S1)
    { MP_ROM_QSTR(MP_QSTR_AF5_I2S1),       MP_ROM_INT(GPIO_AF5_I2S1) },
#endif
#if defined(MICROPY_HW_I2S2)
    { MP_ROM_QSTR(MP_QSTR_AF5_I2S2),       MP_ROM_INT(GPIO_AF5_I2S2) },
#endif
#if defined(MICROPY_HW_I2S3)
    { MP_ROM_QSTR(MP_QSTR_AF5_I2S3),       MP_ROM_INT(GPIO_AF5_I2S3) },
#endif
#if defined(MICROPY_HW_SPI1_SCK)
    { MP_ROM_QSTR(MP_QSTR_AF5_SPI1),       MP_ROM_INT(GPIO_AF5_SPI1) },
#endif
#if defined(MICROPY_HW_SPI2_SCK)
    { MP_ROM_QSTR(MP_QSTR_AF5_SPI2),       MP_ROM_INT(GPIO_AF5_SPI2) },
#endif
#if defined(MICROPY_HW_SPI3_SCK)
    { MP_ROM_QSTR(MP_QSTR_AF5_SPI3),       MP_ROM_INT(GPIO_AF5_SPI3) },
#endif
#if defined(MICROPY_HW_I2S2)
    { MP_ROM_QSTR(MP_QSTR_AF6_I2S2),       MP_ROM_INT(GPIO_AF6_I2S2) },
#endif
#if defined(MICROPY_HW_I2S3)
    { MP_ROM_QSTR(MP_QSTR_AF6_I2S3),       MP_ROM_INT(GPIO_AF6_I2S3) },
#endif
#if defined(MICROPY_HW_SPI3_SCK)
    { MP_ROM_QSTR(MP_QSTR_AF6_SPI3),       MP_ROM_INT(GPIO_AF6_SPI3) },
#endif
#if defined(MICROPY_HW_I2S2)
    { MP_ROM_QSTR(MP_QSTR_AF7_I2S2),       MP_ROM_INT(GPIO_AF7_I2S2) },
#endif
#if defined(MICROPY_HW_I2S3)
    { MP_ROM_QSTR(MP_QSTR_AF7_I2S3),       MP_ROM_INT(GPIO_AF7_I2S3) },
#endif
#if defined(MICROPY_HW_SPI2_SCK)
    { MP_ROM_QSTR(MP_QSTR_AF7_SPI2),       MP_ROM_INT(GPIO_AF7_SPI2) },
#endif
#if defined(MICROPY_HW_SPI3_SCK)
    { MP_ROM_QSTR(MP_QSTR_AF7_SPI3),       MP_ROM_INT(GPIO_AF7_SPI3) },
#endif
#if defined(MICROPY_HW_UART5_TX)
    { MP_ROM_QSTR(MP_QSTR_AF7_UART5),      MP_ROM_INT(GPIO_AF7_UART5) },
#endif
#if defined(MICROPY_HW_UART1_TX)
    { MP_ROM_QSTR(MP_QSTR_AF7_USART1),     MP_ROM_INT(GPIO_AF7_USART1) },
#endif
#if defined(MICROPY_HW_UART2_TX)
    { MP_ROM_QSTR(MP_QSTR_AF7_USART2),     MP_ROM_INT(GPIO_AF7_USART2) },
#endif
#if defined(MICROPY_HW_UART3_TX)
    { MP_ROM_QSTR(MP_QSTR_AF7_USART3),     MP_ROM_INT(GPIO_AF7_USART3) },
#endif
#if defined(MICROPY_HW_UART4_TX)
    { MP_ROM_QSTR(MP_QSTR_AF8_UART4),      MP_ROM_INT(GPIO_AF8_UART4) },
#endif
#if defined(MICROPY_HW_UART5_TX)
    { MP_ROM_QSTR(MP_QSTR_AF8_UART5),      MP_ROM_INT(GPIO_AF8_UART5) },
#endif
#if defined(MICROPY_HW_UART6_TX)
    { MP_ROM_QSTR(MP_QSTR_AF8_USART6),     MP_ROM_INT(GPIO_AF8_USART6) },
#endif
#if defined(MICROPY_HW_CAN1_TX)
    { MP_ROM_QSTR(MP_QSTR_AF9_CAN1),       MP_ROM_INT(GPIO_AF9_CAN1) },
#endif
#if defined(MICROPY_HW_CAN2_TX)
    { MP_ROM_QSTR(MP_QSTR_AF9_CAN2),       MP_ROM_INT(GPIO_AF9_CAN2) },
#endif
    { MP_ROM_QSTR(MP_QSTR_AF9_TIM12),      MP_ROM_INT(GPIO_AF9_TIM12) },
    { MP_ROM_QSTR(MP_QSTR_AF9_TIM13),      MP_ROM_INT(GPIO_AF9_TIM13) },
    { MP_ROM_QSTR(MP_QSTR_AF9_TIM14),      MP_ROM_INT(GPIO_AF9_TIM14) },
