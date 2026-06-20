__int64 __fastcall msm_gpio_irq_enable(__int64 a1)
{
  __int64 v1; // x21
  __int64 data; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 48);
  data = gpiochip_get_data(v1);
  result = gpiochip_enable_irq(v1, *(unsigned int *)(a1 + 8));
  if ( *(_QWORD *)(a1 + 40) )
    result = irq_chip_enable_parent(a1);
  if ( ((*(_QWORD *)(data + 8LL * (*(_QWORD *)(a1 + 8) >> 6) + 848) >> *(_QWORD *)(a1 + 8)) & 1) == 0 )
    return msm_gpio_irq_unmask(a1);
  return result;
}
