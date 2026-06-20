__int64 __fastcall venus_hfi_isr(__int64 a1)
{
  disable_irq_nosync(a1);
  return 2;
}
