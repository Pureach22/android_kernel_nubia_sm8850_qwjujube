__int64 __fastcall qcom_pdc_gic_disable(__int64 a1)
{
  pdc_enable_intr(a1, 0);
  return irq_chip_disable_parent(a1);
}
