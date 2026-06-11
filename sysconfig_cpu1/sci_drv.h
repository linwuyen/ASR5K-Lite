#ifndef SCI_DRV_H
#define SCI_DRV_H

#include <stdint.h>

void SCI_Init(void);
uint16_t SCI_ReadByte(void);
void SCI_WriteByte(uint16_t data);

#endif
