__int64 cvp_hfi_isr()
{
  _ReadStatusReg(SP_EL0);
  disable_irq_nosync();
  return 2;
}
