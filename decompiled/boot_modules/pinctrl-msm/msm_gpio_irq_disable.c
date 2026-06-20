__int64 __fastcall msm_gpio_irq_disable(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 data; // x21
  unsigned __int64 v4; // x1

  v1 = a1[6];
  data = gpiochip_get_data(v1);
  if ( a1[5] )
    irq_chip_disable_parent(a1);
  v4 = a1[1];
  if ( ((*(_QWORD *)(data + 8 * (v4 >> 6) + 848) >> v4) & 1) == 0 )
  {
    msm_gpio_irq_mask(a1);
    v4 = a1[1];
  }
  return gpiochip_disable_irq(v1, v4);
}
