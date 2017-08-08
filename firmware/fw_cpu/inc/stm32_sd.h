#ifndef STM32_SD_H
#define STM32_SD_H

#include "stm32_inc.h"

typedef enum
{
/**
  * @brief  SD specific error defines
  */
  SD_CMD_CRC_FAIL                    = (1U),   /*!< Command response received (but CRC check failed)              */
  SD_DATA_CRC_FAIL                   = (2U),   /*!< Data block sent/received (CRC check failed)                   */
  SD_CMD_RSP_TIMEOUT                 = (3U),   /*!< Command response timeout                                      */
  SD_DATA_TIMEOUT                    = (4U),   /*!< Data timeout                                                  */
  SD_TX_UNDERRUN                     = (5U),   /*!< Transmit FIFO underrun                                        */
  SD_RX_OVERRUN                      = (6U),   /*!< Receive FIFO overrun                                          */
  SD_START_BIT_ERR                   = (7U),   /*!< Start bit not detected on all data signals in wide bus mode   */
  SD_CMD_OUT_OF_RANGE                = (8U),   /*!< Command's argument was out of range.                          */
  SD_ADDR_MISALIGNED                 = (9U),   /*!< Misaligned address                                            */
  SD_BLOCK_LEN_ERR                   = (10U),  /*!< Transferred block length is not allowed for the card or the number of transferred bytes does not match the block length */
  SD_ERASE_SEQ_ERR                   = (11U),  /*!< An error in the sequence of erase command occurs.            */
  SD_BAD_ERASE_PARAM                 = (12U),  /*!< An invalid selection for erase groups                        */
  SD_WRITE_PROT_VIOLATION            = (13U),  /*!< Attempt to program a write protect block                     */
  SD_LOCK_UNLOCK_FAILED              = (14U),  /*!< Sequence or password error has been detected in unlock command or if there was an attempt to access a locked card */
  SD_COM_CRC_FAILED                  = (15U),  /*!< CRC check of the previous command failed                     */
  SD_ILLEGAL_CMD                     = (16U),  /*!< Command is not legal for the card state                      */
  SD_CARD_ECC_FAILED                 = (17U),  /*!< Card internal ECC was applied but failed to correct the data */
  SD_CC_ERROR                        = (18U),  /*!< Internal card controller error                               */
  SD_GENERAL_UNKNOWN_ERROR           = (19U),  /*!< General or unknown error                                     */
  SD_STREAM_READ_UNDERRUN            = (20U),  /*!< The card could not sustain data transfer in stream read operation. */
  SD_STREAM_WRITE_OVERRUN            = (21U),  /*!< The card could not sustain data programming in stream mode   */
  SD_CID_CSD_OVERWRITE               = (22U),  /*!< CID/CSD overwrite error                                      */
  SD_WP_ERASE_SKIP                   = (23U),  /*!< Only partial address space was erased                        */
  SD_CARD_ECC_DISABLED               = (24U),  /*!< Command has been executed without using internal ECC         */
  SD_ERASE_RESET                     = (25U),  /*!< Erase sequence was cleared before executing because an out of erase sequence command was received */
  SD_AKE_SEQ_ERROR                   = (26U),  /*!< Error in sequence of authentication.                         */
  SD_INVALID_VOLTRANGE               = (27U),
  SD_ADDR_OUT_OF_RANGE               = (28U),
  SD_SWITCH_ERROR                    = (29U),
  SD_SDIO_DISABLED                   = (30U),
  SD_SDIO_FUNCTION_BUSY              = (31U),
  SD_SDIO_FUNCTION_FAILED            = (32U),
  SD_SDIO_UNKNOWN_FUNCTION           = (33U),

/**
  * @brief  Standard error defines
  */
  SD_INTERNAL_ERROR                  = (34U),
  SD_NOT_CONFIGURED                  = (35U),
  SD_REQUEST_PENDING                 = (36U),
  SD_REQUEST_NOT_APPLICABLE          = (37U),
  SD_INVALID_PARAMETER               = (38U),
  SD_UNSUPPORTED_FEATURE             = (39U),
  SD_UNSUPPORTED_HW                  = (40U),
  SD_ERROR                           = (41U),
  SD_OK                              = (0U)

} SD_ErrorTypedef;

typedef struct
{
  __IO uint8_t  CSDStruct;            /*!< CSD structure                         */
  __IO uint8_t  SysSpecVersion;       /*!< System specification version          */
  __IO uint8_t  Reserved1;            /*!< Reserved                              */
  __IO uint8_t  TAAC;                 /*!< Data read access time 1               */
  __IO uint8_t  NSAC;                 /*!< Data read access time 2 in CLK cycles */
  __IO uint8_t  MaxBusClkFrec;        /*!< Max. bus clock frequency              */
  __IO uint16_t CardComdClasses;      /*!< Card command classes                  */
  __IO uint8_t  RdBlockLen;           /*!< Max. read data block length           */
  __IO uint8_t  PartBlockRead;        /*!< Partial blocks for read allowed       */
  __IO uint8_t  WrBlockMisalign;      /*!< Write block misalignment              */
  __IO uint8_t  RdBlockMisalign;      /*!< Read block misalignment               */
  __IO uint8_t  DSRImpl;              /*!< DSR implemented                       */
  __IO uint8_t  Reserved2;            /*!< Reserved                              */
  __IO uint32_t DeviceSize;           /*!< Device Size                           */
  __IO uint8_t  MaxRdCurrentVDDMin;   /*!< Max. read current @ VDD min           */
  __IO uint8_t  MaxRdCurrentVDDMax;   /*!< Max. read current @ VDD max           */
  __IO uint8_t  MaxWrCurrentVDDMin;   /*!< Max. write current @ VDD min          */
  __IO uint8_t  MaxWrCurrentVDDMax;   /*!< Max. write current @ VDD max          */
  __IO uint8_t  DeviceSizeMul;        /*!< Device size multiplier                */
  __IO uint8_t  EraseGrSize;          /*!< Erase group size                      */
  __IO uint8_t  EraseGrMul;           /*!< Erase group size multiplier           */
  __IO uint8_t  WrProtectGrSize;      /*!< Write protect group size              */
  __IO uint8_t  WrProtectGrEnable;    /*!< Write protect group enable            */
  __IO uint8_t  ManDeflECC;           /*!< Manufacturer default ECC              */
  __IO uint8_t  WrSpeedFact;          /*!< Write speed factor                    */
  __IO uint8_t  MaxWrBlockLen;        /*!< Max. write data block length          */
  __IO uint8_t  WriteBlockPaPartial;  /*!< Partial blocks for write allowed      */
  __IO uint8_t  Reserved3;            /*!< Reserved                              */
  __IO uint8_t  ContentProtectAppli;  /*!< Content protection application        */
  __IO uint8_t  FileFormatGrouop;     /*!< File format group                     */
  __IO uint8_t  CopyFlag;             /*!< Copy flag (OTP)                       */
  __IO uint8_t  PermWrProtect;        /*!< Permanent write protection            */
  __IO uint8_t  TempWrProtect;        /*!< Temporary write protection            */
  __IO uint8_t  FileFormat;           /*!< File format                           */
  __IO uint8_t  ECC;                  /*!< ECC code                              */
  __IO uint8_t  CSD_CRC;              /*!< CSD CRC                               */
  __IO uint8_t  Reserved4;            /*!< Always 1                              */

} SD_CSDTypedef;

typedef struct
{
  __IO uint8_t  ManufacturerID;  /*!< Manufacturer ID       */
  __IO uint16_t OEM_AppliID;     /*!< OEM/Application ID    */
  __IO uint32_t ProdName1;       /*!< Product Name part1    */
  __IO uint8_t  ProdName2;       /*!< Product Name part2    */
  __IO uint8_t  ProdRev;         /*!< Product Revision      */
  __IO uint32_t ProdSN;          /*!< Product Serial Number */
  __IO uint8_t  Reserved1;       /*!< Reserved1             */
  __IO uint16_t ManufactDate;    /*!< Manufacturing Date    */
  __IO uint8_t  CID_CRC;         /*!< CID CRC               */
  __IO uint8_t  Reserved2;       /*!< Always 1              */

} SD_CIDTypedef;

typedef struct
{
    SD_CSDTypedef       SD_csd;         /*!< SD card specific data register         */
    SD_CIDTypedef       SD_cid;         /*!< SD card identification number register */
    uint64_t            CardCapacity;   /*!< Card capacity                          */
    uint32_t            CardBlockSize;  /*!< Card block size                        */
    uint16_t            RCA;            /*!< SD relative card address               */
    uint8_t             CardType;       /*!< SD card type                           */
} SD_CardInfo;

class STM32_SD
{
public:
    static uint32_t init();
private:
    static uint32_t m_card_type;
    static uint32_t m_RCA;
    static uint32_t m_CSD[4];
    static uint32_t m_CID[4];
    static SD_CardInfo  m_card_info;

    static void init_gpio();
    static void init_low(uint32_t clock_edge, uint32_t clock_bypass,
                         uint32_t clock_power_save, uint32_t bus_wide,
                         uint32_t hw_control, uint32_t clock_div);

    static SD_ErrorTypedef power_ON();
    static SD_ErrorTypedef initialize_cards();

    static void send_command(uint32_t arg, uint32_t cmd_idx, uint32_t resp,
                             uint32_t wait_IT, uint32_t cpsm);
    static SD_ErrorTypedef cmd_error();
    static SD_ErrorTypedef cmd_resp7_error();
    static SD_ErrorTypedef cmd_resp1_error(uint32_t SD_CMD);
    static SD_ErrorTypedef cmd_resp3_error();
    static SD_ErrorTypedef cmd_resp2_error();
    static SD_ErrorTypedef cmd_resp6_error(uint8_t SD_CMD, uint32_t *pRCA);

    static SD_ErrorTypedef get_card_info();
    static SD_ErrorTypedef select_deselect(uint32_t addr);

    static inline void enable_SDIO() { BIT_BAND_PER(SDIO->CLKCR, SDIO_CLKCR_CLKEN) = ENABLE; }
    static inline void disable_SDIO() { BIT_BAND_PER(SDIO->CLKCR, SDIO_CLKCR_CLKEN) = DISABLE; }

    static inline void power_state_ON() { SDIO->POWER = SDIO_POWER_PWRCTRL; }
    static inline void power_state_OFF() { SDIO->POWER = 0; }

    static inline uint32_t get_flag(uint32_t flag_msk) { return (SDIO->STA & flag_msk); }
    static inline void clear_flag(uint32_t flag_msk) { SDIO->ICR = flag_msk; }

    static inline uint32_t get_cmd_response() { return SDIO->RESPCMD; }
    static inline uint32_t get_response(uint32_t SDIO_RESP) { return (&SDIO->RESP1)[SDIO_RESP >> 2]; }

    static inline uint32_t get_power_state() { return (SDIO->POWER & SDIO_POWER_PWRCTRL); }
};

#endif // STM32_SD_H