unsigned __int64 __fastcall msm_gpio_get(__int64 a1, unsigned int a2)
{
  __int64 data; // x0
  __int64 v4; // x19

  data = gpiochip_get_data(a1);
  v4 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * a2;
  return ((unsigned __int64)(unsigned int)readl((unsigned int *)(*(_QWORD *)(data
                                                                           + 8 * ((*(_QWORD *)(v4 + 84) >> 5) & 3LL)
                                                                           + 976)
                                                               + *(unsigned int *)(v4 + 64))) >> ((*(_QWORD *)(v4 + 84) >> 47)
                                                                                                & 0x1F))
       & 1;
}
