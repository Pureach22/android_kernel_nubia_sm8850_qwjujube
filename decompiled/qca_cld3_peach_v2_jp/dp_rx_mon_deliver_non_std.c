__int64 __fastcall dp_rx_mon_deliver_non_std(__int64 *a1, int a2)
{
  __int64 v4; // x2
  __int64 v5; // x21
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x22
  __int64 v9; // x8
  _DWORD **v10; // x8
  _DWORD *v11; // x23
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 v22; // x0
  __int64 v24; // [xsp+0h] [xbp+0h] BYREF

  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(a1[5]) && (unsigned __int8)wlan_cfg_get_pdev_idx(a1[5], a2) )
    return 4;
  v5 = a1[9];
  if ( !v5 )
    return 4;
  v6 = *(_QWORD *)(v5 + 95560);
  if ( !v6 )
    return 4;
  if ( (unsigned __int8)a2 >= 3u )
  {
    __break(0x5512u);
    __arm_mte_set_tag((void *)(v4 - 3616), &v24);
    JUMPOUT(0x5E9F40);
  }
  v7 = v6 + 18528LL * (a2 & 3);
  v8 = v7 + 8;
  if ( v7 == -8 )
    return 4;
  v9 = *(_QWORD *)(v7 + 16);
  if ( !v9 )
    return 4;
  v10 = *(_DWORD ***)(v9 + 42696);
  if ( !v10 )
    return 4;
  v11 = *v10;
  if ( !*v10 )
    return 4;
  v12 = _qdf_nbuf_alloc(a1[3], 512, 512, 4, 0, "dp_rx_mon_deliver_non_std", 2414);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x85u,
      8u,
      "%s: %pK: mon_skb=%pK ",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_rx_mon_deliver_non_std",
      a1,
      0);
    return 4;
  }
  v21 = v12;
  if ( *(_DWORD *)(v12 + 112) )
    skb_trim(v12, 0);
  else
    skb_put(v12, 0);
  *(_QWORD *)v21 = 0;
  *(_WORD *)(v8 + 3462) = *(_DWORD *)(v8 + 3264);
  if ( !(unsigned int)qdf_nbuf_update_radiotap(v8 + 3336, v21, *(_DWORD *)(v21 + 224) - *(_DWORD *)(v21 + 216)) )
  {
    ++*(_DWORD *)(v5 + 404);
    _qdf_nbuf_free(v21);
    return 4;
  }
  v22 = *(_QWORD *)(*(_QWORD *)(v8 + 8) + 88LL);
  if ( *(v11 - 1) != 1866648346 )
    __break(0x8237u);
  ((void (__fastcall *)(__int64, __int64, _QWORD))v11)(v22, v21, 0);
  return 0;
}
