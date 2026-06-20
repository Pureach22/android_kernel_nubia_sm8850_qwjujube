__int64 __fastcall qcom_pdc_gic_enable(__int64 a1)
{
  pdc_enable_intr(a1, 1);
  return irq_chip_enable_parent(a1);
}
