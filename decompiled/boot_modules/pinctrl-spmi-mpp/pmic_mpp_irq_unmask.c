__int64 __fastcall pmic_mpp_irq_unmask(__int64 a1)
{
  gpiochip_enable_irq(*(_QWORD *)(a1 + 48), *(unsigned int *)(a1 + 8));
  return irq_chip_unmask_parent(a1);
}
