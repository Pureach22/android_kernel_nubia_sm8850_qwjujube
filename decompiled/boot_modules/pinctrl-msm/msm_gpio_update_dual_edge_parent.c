__int64 __fastcall msm_gpio_update_dual_edge_parent(__int64 a1)
{
  __int64 data; // x0
  __int64 v3; // x23
  __int64 *v4; // x19
  __int64 v5; // x22
  int v6; // w25
  unsigned int v7; // w21
  __int64 result; // x0
  int v10; // w8
  __int64 v11; // x0

  data = gpiochip_get_data(*(_QWORD *)(a1 + 48));
  v3 = data + 976;
  v4 = (__int64 *)data;
  v5 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * *(_QWORD *)(a1 + 8);
  v6 = -101;
  if ( ((unsigned int)readl((unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL))
                                           + *(unsigned int *)(v5 + 64)))
      & (1 << (*(_QWORD *)(v5 + 84) >> 47))) != 0 )
    v7 = 2;
  else
    v7 = 1;
  do
  {
    irq_chip_set_type_parent(a1, v7);
    result = readl((unsigned int *)(*(_QWORD *)(v3 + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL))
                                  + *(unsigned int *)(v5 + 64)));
    v10 = result & (1 << (*(_QWORD *)(v5 + 84) >> 47));
    if ( v7 == 1 )
    {
      if ( !v10 )
        return result;
      v7 = 2;
    }
    else
    {
      if ( v10 )
        return result;
      v7 = 1;
    }
  }
  while ( !__CFADD__(v6++, 1) );
  if ( (msm_gpio_update_dual_edge_parent___print_once & 1) == 0 )
  {
    v11 = *v4;
    msm_gpio_update_dual_edge_parent___print_once = 1;
    return dev_warn(v11, "dual-edge irq failed to stabilize\n");
  }
  return result;
}
