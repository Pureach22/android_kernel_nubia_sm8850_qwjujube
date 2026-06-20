__int64 __fastcall msm_gpio_irq_ack(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x0
  __int64 v8; // x9
  __int64 v9; // x21
  unsigned int v10; // w0

  result = gpiochip_get_data(*(_QWORD *)(a1 + 48));
  v3 = *(_QWORD *)(a1 + 8);
  v4 = result + 8 * (v3 >> 6);
  if ( ((*(_QWORD *)(v4 + 848) >> v3) & 1) != 0 )
  {
    if ( ((*(_QWORD *)(v4 + 768) >> v3) & 1) != 0 )
      return msm_gpio_update_dual_edge_parent(a1);
  }
  else
  {
    v5 = result;
    v6 = *(_QWORD *)(*(_QWORD *)(result + 968) + 32LL) + 112 * v3;
    v7 = raw_spin_lock_irqsave(result + 764);
    v8 = *(_QWORD *)(v6 + 92);
    v9 = v7;
    if ( (v8 & 0x20) != 0 )
      v10 = 1 << v8;
    else
      v10 = 0;
    writel(
      v10,
      (unsigned int *)(*(_QWORD *)(v5 + 8 * ((*(_QWORD *)(v6 + 84) >> 5) & 3LL) + 976) + *(unsigned int *)(v6 + 72)));
    if ( ((*(_QWORD *)(v5 + 8LL * (*(_QWORD *)(a1 + 8) >> 6) + 768) >> *(_QWORD *)(a1 + 8)) & 1) != 0 )
      msm_gpio_update_dual_edge_pos(v5, v6);
    return raw_spin_unlock_irqrestore(v5 + 764, v9);
  }
  return result;
}
