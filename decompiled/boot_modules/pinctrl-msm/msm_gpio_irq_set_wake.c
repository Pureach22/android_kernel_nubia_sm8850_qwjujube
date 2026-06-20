__int64 __fastcall msm_gpio_irq_set_wake(_QWORD *a1, unsigned int a2)
{
  __int64 data; // x0

  data = gpiochip_get_data(a1[6]);
  if ( a1[5] && ((*(_QWORD *)(data + 8LL * (a1[1] >> 6) + 848) >> a1[1]) & 1) != 0 )
    return irq_chip_set_wake_parent(a1, a2);
  else
    return irq_set_irq_wake(*(unsigned int *)(data + 752), a2);
}
