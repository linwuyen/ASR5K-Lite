#include "driverlib.h"
#include "device.h"
#include "sci_drv.h"

#define SCI_BAUD_RATE 115200U

void SCI_Init(void)
{
    GPIO_setPinConfig(GPIO_28_SCIA_RX);
    GPIO_setPinConfig(GPIO_29_SCIA_TX);
    GPIO_setPadConfig(28U, GPIO_PIN_TYPE_STD);
    GPIO_setPadConfig(29U, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(28U, GPIO_QUAL_ASYNC);

    SCI_disableModule(SCIA_BASE);
    SCI_setConfig(SCIA_BASE, DEVICE_LSPCLK_FREQ, SCI_BAUD_RATE,
                  SCI_CONFIG_WLEN_8 | SCI_CONFIG_STOP_ONE |
                  SCI_CONFIG_PAR_NONE);
    SCI_disableFIFO(SCIA_BASE);
    SCI_enableModule(SCIA_BASE);
    SCI_resetChannels(SCIA_BASE);
}

uint16_t SCI_ReadByte(void)
{
    return SCI_readCharBlockingNonFIFO(SCIA_BASE) & 0x00FFU;
}

void SCI_WriteByte(uint16_t data)
{
    SCI_writeCharBlockingNonFIFO(SCIA_BASE, data & 0x00FFU);
}
