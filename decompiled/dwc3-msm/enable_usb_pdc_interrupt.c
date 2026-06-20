__int64 __fastcall enable_usb_pdc_interrupt(__int64 result, char a2)
{
  __int64 v2; // x19
  int v3; // w8
  __int64 v4; // x1
  __int64 v5; // x2

  v2 = result;
  if ( (a2 & 1) != 0 )
  {
    v3 = *(_DWORD *)(result + 488);
    if ( (v3 & 0x20) != 0 )
    {
      if ( *(_BYTE *)(result + 2561) == 1 )
      {
        v4 = result + 532;
LABEL_20:
        v5 = 1;
LABEL_24:
        configure_usb_wakeup_interrupt(result, v4, v5, 1);
        return configure_usb_wakeup_interrupt(v2, v2 + 548, 4, 1);
      }
      v4 = result + 540;
    }
    else
    {
      if ( (v3 & 0x10) == 0 )
      {
        ((void (*)(void))configure_usb_wakeup_interrupt)();
        v4 = v2 + 540;
        result = v2;
        if ( *(_BYTE *)(v2 + 736) )
          v5 = 4;
        else
          v5 = 1;
        goto LABEL_24;
      }
      if ( *(_BYTE *)(result + 2561) == 1 )
      {
        v4 = result + 540;
        goto LABEL_20;
      }
      v4 = result + 532;
    }
    v5 = 2;
    goto LABEL_24;
  }
  if ( result != -532 && *(_BYTE *)(result + 536) == 1 )
  {
    dwc3_dbg_print(
      *(_QWORD *)(result + 1256),
      0xFFu,
      "PDC_IRQ_DIS",
      *(_DWORD *)(result + 532),
      (const char *)&unk_16A05);
    irq_set_irq_wake(*(unsigned int *)(v2 + 532), 0);
    result = disable_irq_nosync(*(unsigned int *)(v2 + 532));
    *(_BYTE *)(v2 + 536) = 0;
  }
  if ( v2 != -540 && *(_BYTE *)(v2 + 544) == 1 )
  {
    dwc3_dbg_print(*(_QWORD *)(v2 + 1256), 0xFFu, "PDC_IRQ_DIS", *(_DWORD *)(v2 + 540), (const char *)&unk_16A05);
    irq_set_irq_wake(*(unsigned int *)(v2 + 540), 0);
    result = disable_irq_nosync(*(unsigned int *)(v2 + 540));
    *(_BYTE *)(v2 + 544) = 0;
  }
  if ( v2 != -548 && *(_BYTE *)(v2 + 552) == 1 )
  {
    dwc3_dbg_print(*(_QWORD *)(v2 + 1256), 0xFFu, "PDC_IRQ_DIS", *(_DWORD *)(v2 + 548), (const char *)&unk_16A05);
    irq_set_irq_wake(*(unsigned int *)(v2 + 548), 0);
    result = disable_irq_nosync(*(unsigned int *)(v2 + 548));
    *(_BYTE *)(v2 + 552) = 0;
  }
  return result;
}
