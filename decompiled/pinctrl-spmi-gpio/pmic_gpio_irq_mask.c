__int64 __fastcall pmic_gpio_irq_mask(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 48);
  irq_chip_mask_parent();
  return gpiochip_disable_irq(v1, *(unsigned int *)(a1 + 8));
}
