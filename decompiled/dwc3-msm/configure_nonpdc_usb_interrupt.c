__int64 __fastcall configure_nonpdc_usb_interrupt(__int64 result, int *a2, char a3)
{
  __int64 v3; // x19
  unsigned int *v4; // x20
  char v5; // w21
  unsigned int *v6; // x19

  if ( a2 && (a3 & 1) != 0 && (a2[1] & 1) == 0 )
  {
    v3 = result;
    v4 = (unsigned int *)a2;
    v5 = a3;
    dwc3_dbg_print(*(_QWORD *)(result + 1256), 0xFFu, "IRQ_EN", *a2, (const char *)&unk_16A05);
    irq_set_irq_wake(*v4, 1);
    enable_irq(*v4);
    a3 = v5;
    result = v3;
    a2 = (int *)v4;
    *((_BYTE *)v4 + 4) = 1;
  }
  if ( a2 && (a3 & 1) == 0 && *((_BYTE *)a2 + 4) == 1 )
  {
    v6 = (unsigned int *)a2;
    dwc3_dbg_print(*(_QWORD *)(result + 1256), 0xFFu, "IRQ_DIS", *a2, (const char *)&unk_16A05);
    irq_set_irq_wake(*v6, 0);
    result = disable_irq_nosync(*v6);
    *((_BYTE *)v6 + 4) = 0;
  }
  return result;
}
