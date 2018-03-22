/* --COPYRIGHT--,BSD
 * Copyright (c) 2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/*
 * ======== usbEventHandling.c ========
 * Event-handling placeholder functions.
 * All functios are called in interrupt context.
 */
#include <msp430-driverlib/MSP430F5xx_6xx/driverlib.h>

#include "USB_API/USB_Common/device.h"
#include "USB_API/USB_Common/defMSP430USB.h"
#include "descriptors.h"
#include "USB_API/USB_Common/usb.h"
#include "usb_event_handlers.h"

#ifdef _CDC_
#include "USB_API/USB_CDC_API/usbcdc.h"
#include "USB_API/USB_CDC_API/usbcdc_event_handlers.h"
#endif

#ifdef _HID_
#include "USB_API/USB_HID_API/usbhid.h"
#include "USB_API/USB_HID_API/usbhid_event_handlers.h"
#endif

#ifdef _MSC_
#include "USB_API/USB_MSC_API/usbmsc.h"
#include "USB_API/USB_MSC_API/usbmsc_event_handling.h"
#endif

#ifdef _PHDC_
#include "USB_API/USB_PHDC_API/usbphdc.h"
#endif


/*
 * If this function gets executed, it's a sign that the output of the 
 * USB PLL has failed. 
 * Returns TRUE to keep CPU awake.
 */
uint8_t USB_handleClockEvent(void)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return TRUE;             
}

/*
 * If this function gets executed, it indicates that a valid voltage has just 
 * been applied to the VBUS pin. 
 * Returns TRUE to keep CPU awake.
 */
uint8_t USB_handleVbusOnEvent(void)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    if (USB_enable() == USB_SUCCEED) {
            USB_reset();
            //generate rising edge on DP -> 
            //the host enumerates our device as full speed device
            USB_connect();
    }
    return TRUE;
}

/*
 * If this function gets executed, it indicates that a valid voltage has just 
 * been removed from the VBUS pin. 
 * Returns TRUE to keep CPU awake.
 */
uint8_t USB_handleVbusOffEvent(void)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return TRUE;
}

/*
 * If this function gets executed, it indicates that the USB host has issued 
 * a USB reset event to the device. 
 * Returns TRUE to keep CPU awake.
 */
uint8_t USB_handleResetEvent(void)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return TRUE;
}

/*
 * If this function gets executed, it indicates that the USB host has chosen 
 * to suspend this device after a period of active operation. 
 * Returns TRUE to keep CPU awake.
 */
uint8_t USB_handleSuspendEvent()
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here.
    return TRUE;                            
}

/*
 * If this function gets executed, it indicates that the USB host has chosen 
 * to resume this device after a period of suspended operation. 
 * Returns TRUE to keep CPU awake.
 */
uint8_t USB_handleResumeEvent()
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return TRUE;
}

/*
 * If this function gets executed, it indicates that the USB host has 
 * enumerated this device : after host assigned the address to the device.
 * Returns TRUE to keep CPU awake.
 */
uint8_t USB_handleEnumerationCompleteEvent()
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return TRUE;
}

/* This #define can be used to reduce latency times during crystal/PLL 
 * startups; see the Programmer's Guide for more information.
 */
#ifdef USE_TIMER_FOR_RESUME

/*
 * Indicates a USB resume is in progress, XT2 has been turned on, and the 
 * USB API requires the application to call USB_enable_PLL() after XT2 has 
 * stabilized.
 */
void USB_handleCrystalStartedEvent(void)
{
    // Unlike other events, these don't have a return value to wake main()
}


/*
 * Indicates a USB resume is in progress, the PLL has been turned on, and the 
 * USB API requires the application to call USB_enable_final() after the PLL
 * has locked.
 */
void USB_handlePLLStartedEvent(void)
{
    // Unlike other events, these don't have a return value to wake main()
}
#endif

#ifdef _CDC_

/*
 * This event indicates that new line coding params have been received from 
 * the host.
 * Return False to not wake the CPU if it was asleep.
 */
uint8_t USBCDC_handleSetLineCoding(uint8_t intfNum, uint32_t lBaudrate)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return FALSE;
}

/*
 * This event indicates that new line state has been received from the host
 * Return False to not wake the CPU if it was asleep.
 */
uint8_t USBCDC_handleSetControlLineState(uint8_t intfNum, uint8_t lineState)
{
    return FALSE;
}

#endif

#ifdef _HID_
/*
 * This event indicates that data has been received for interface intfNum, 
 * but no data receive operation is underway.
 * Returns TRUE to keep CPU awake.
 */
uint8_t USBHID_handleDataReceived(uint8_t intfNum)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return TRUE;
}

/*
 * This event indicates that a send operation on interface intfNum has 
 * just been completed. 
 * Return False to not wake the CPU if it was asleep.
 */
uint8_t USBHID_handleSendCompleted(uint8_t intfNum)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return FALSE;
}

/*
 * This event indicates that a receive operation on interface intfNum has 
 * just been completed.*
 * Return False to not wake the CPU if it was asleep.
 */
uint8_t USBHID_handleReceiveCompleted(uint8_t intfNum)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return FALSE;
}

/*
 * This event indicates that a request to switch to or from Boot protocol
 * was received from the host
 */
uint8_t USBHID_handleBootProtocol(uint8_t protocol, uint8_t intfnum)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return FALSE;
}

/*
 * This event indicates that a Set_Report request was received from the host
 * The application needs to supply a buffer to retrieve the data that will be sent
 * as part of this request. This handler is passed the reportTypereportId(lower byte), the length of data
 * phase as well as the interface number.
 */
uint8_t *USBHID_handleEP0SetReport (uint8_t reportType, uint8_t reportId,
    uint16_t dataLength,
    uint8_t intfnum)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    switch (reportType) {
        case USB_REQ_HID_INPUT:
            //Return pointer to input Report Buffer
            return 0;
        case USB_REQ_HID_OUTPUT:
            //Return pointer to output Report Buffer
            return 0;
        case USB_REQ_HID_FEATURE:
            //Return pointer to feature Report Buffer
            return 0;
        default:
            return 0;
    }
}

/*
 * This event indicates that data as part of Set_Report request was received from the host
 * Tha application can return TRUE to wake up the CPU. If the application supplied a buffer
 * as part of USBHID_handleEP0SetReport, then this buffer will contain the Set Report data.
 */
uint8_t USBHID_handleEP0SetReportDataAvailable (uint8_t intfnum)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    //Process received data based on currentReportType
    return TRUE;
}

/*
 * This event indicates that a Get_Report request was received from the host
 * The application can supply a buffer of data that will be sent to the host.
 * This handler is passed the reportType, reportId, the requested length as well
 * as the interface number.
 */
uint8_t *USBHID_handleEP0GetReport (uint8_t reportType, uint8_t reportId,
    uint16_t requestedLength,
    uint8_t intfnum)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    //report data should be ready in buffers for Get Report.
    switch (reportType) {
        case USB_REQ_HID_INPUT:
            //Return pointer to input Report Buffer
            return 0;
        case USB_REQ_HID_OUTPUT:
            //Return pointer to OUTput Report Buffer
            return 0;
        case USB_REQ_HID_FEATURE:
            //Return pointer to FEATURE Report Buffer
            return 0;
        default:
            return 0;
    }
}

#endif

#ifdef _MSC_
uint8_t USBMSC_handleBufferEvent(void)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return FALSE;
}

#endif


#ifdef _PHDC_

/*
 * This event indicates that data has been received for interface intfNum, 
 * but no data receive operation is underway.
 * returns TRUE to keep CPU awake
 */
uint8_t USBPHDC_handleDataReceived(uint8_t intfNum)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return TRUE;
}

/*
 * This event indicates that a send operation on interface intfNum has just 
 * been completed.
 * returns TRUE to keep CPU awake
 */
uint8_t USBPHDC_handleSendCompleted(uint8_t intfNum)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return FALSE;
}

/*
 * This event indicates that a receive operation on interface intfNum has 
 * just been completed.
 */
uint8_t USBPHDC_handleReceiveCompleted(uint8_t intfNum)
{
    // TODO: Migrate this to the application layer
    // Application can place specific code here. 
    return FALSE;
}

#endif

/*----------------------------------------------------------------------------+
| End of source file                                                          |
+----------------------------------------------------------------------------*/
/*------------------------ Nothing Below This Line --------------------------*/
//Released_Version_5_10_00_17
