__int64 __fastcall dp_rx_buffer_pool_nbuf_free(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  unsigned int v5; // w21
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x21

  v5 = a3;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), v5) )
  {
    v6 = 0;
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 72);
  }
  result = wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40));
  if ( !(_DWORD)result )
    v5 = *(unsigned __int8 *)(v6 + 1);
  if ( v5 >= 5 || (v8 = v5, v5 > 1) )
  {
    __break(0x5512u);
    return ((__int64 (*)(void))qdf_nbuf_reset_0)();
  }
  else
  {
    v9 = a1 + 32LL * v5 + 18768;
    if ( *(_DWORD *)(a1 + 32 * v8 + 18784) <= 0x7Fu && (*(_BYTE *)(a1 + 32 * v8 + 18796) & 1) != 0 )
    {
      qdf_nbuf_reset_0(a2, *(unsigned __int8 *)(a1 + 12368 + 120LL * (unsigned int)v8 + 76));
      return skb_queue_tail(v9, a2);
    }
    else if ( a2 )
    {
      return _qdf_nbuf_free(a2);
    }
  }
  return result;
}
