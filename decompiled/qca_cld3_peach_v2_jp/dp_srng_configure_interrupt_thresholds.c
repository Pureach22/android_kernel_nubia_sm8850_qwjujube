__int64 __fastcall dp_srng_configure_interrupt_thresholds(__int64 a1, _DWORD *a2, int a3, int a4)
{
  unsigned __int8 rx_rel_ring_id; // w0
  __int64 result; // x0
  int v10; // w8

  rx_rel_ring_id = wlan_cfg_get_rx_rel_ring_id(*(_QWORD *)(a1 + 40));
  if ( a3 == 13 )
  {
    if ( a4 == rx_rel_ring_id )
    {
      a2[9] = wlan_cfg_get_int_timer_threshold_other(*(_QWORD *)(a1 + 40));
      result = wlan_cfg_get_int_batch_threshold_other(*(_QWORD *)(a1 + 40));
      goto LABEL_9;
    }
  }
  else if ( !a3 )
  {
    if ( a4 == 7 )
    {
      a2[9] = 0;
      result = 1;
    }
    else
    {
      a2[9] = wlan_cfg_get_int_timer_threshold_rx(*(_QWORD *)(a1 + 40));
      result = wlan_cfg_get_int_batch_threshold_rx(*(_QWORD *)(a1 + 40));
    }
    goto LABEL_9;
  }
  a2[9] = *(_DWORD *)(*(_QWORD *)(a1 + 18688) + 12LL * a3);
  result = *(unsigned int *)(*(_QWORD *)(a1 + 18688) + 12LL * a3 + 4);
LABEL_9:
  a2[10] = result;
  v10 = *(_DWORD *)(*(_QWORD *)(a1 + 18688) + 12LL * a3 + 8);
  a2[11] = v10;
  if ( v10 )
    a2[12] |= 0x10000u;
  return result;
}
