__int64 __fastcall configure_usb_wakeup_interrupt(__int64 result, int *a2, unsigned int a3, char a4)
{
  __int64 v4; // x21
  unsigned int *v5; // x22
  char v7; // w23
  unsigned int *v8; // x19

  if ( a2 && (a4 & 1) != 0 && (a2[1] & 1) == 0 )
  {
    v4 = result;
    v5 = (unsigned int *)a2;
    v7 = a4;
    dwc3_dbg_print(*(_QWORD *)(result + 1256), 0xFFu, "PDC_IRQ_EN", *a2, (const char *)&unk_16A05);
    dwc3_dbg_print(*(_QWORD *)(v4 + 1256), 0xFFu, "PDC_IRQ_POL", a3, (const char *)&unk_16A05);
    irq_set_irqchip_state(*v5, 0, 0);
    irq_set_irq_type(*v5, a3);
    irq_set_irq_wake(*v5, 1);
    enable_irq(*v5);
    a4 = v7;
    result = v4;
    a2 = (int *)v5;
    *((_BYTE *)v5 + 4) = 1;
  }
  if ( a2 && (a4 & 1) == 0 && *((_BYTE *)a2 + 4) == 1 )
  {
    v8 = (unsigned int *)a2;
    dwc3_dbg_print(*(_QWORD *)(result + 1256), 0xFFu, "PDC_IRQ_DIS", *a2, (const char *)&unk_16A05);
    irq_set_irq_wake(*v8, 0);
    result = disable_irq_nosync(*v8);
    *((_BYTE *)v8 + 4) = 0;
  }
  return result;
}
