__int64 __fastcall dp_alloc_tx_ring_pair_by_index(
        _QWORD *a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w21
  const char *v11; // x2
  __int64 v14; // x20
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  unsigned int v18; // w3
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x4
  unsigned int v23; // w21
  _QWORD *v24; // x20
  _DWORD *v25; // x8

  v10 = a2;
  if ( a2 < 5u )
  {
    v14 = a1[5];
    qdf_trace_msg(0x45u, 8u, "%s: index %u", a3, a4, a5, a6, a7, a8, a9, a10, "dp_alloc_tx_ring_pair_by_index", a2);
    v18 = wlan_cfg_tx_ring_size(v14, v10, v15, v16, v17);
    if ( v10 == 4 && (*(_BYTE *)(v14 + 540) & 1) != 0 )
      v18 = wlan_cfg_ipa_tx_ring_size(v14);
    if ( !(unsigned int)dp_srng_alloc(a1, (__int64)&a1[10 * a2 + 844], 5u, v18, 0) )
    {
      v23 = wlan_cfg_tx_comp_ring_size(v14, v10, v19, v20, v21);
      if ( a2 == 4 && (*(_BYTE *)(v14 + 540) & 1) != 0 )
        v23 = wlan_cfg_ipa_tx_comp_ring_size(v14);
      wlan_cfg_get_dp_soc_nss_cfg(v14);
      if ( *(_BYTE *)(*(_QWORD *)(a1[5] + 776LL) + 4LL * a2 + 1) != 15 )
      {
        v24 = &a1[10 * a2];
        if ( (unsigned int)dp_srng_alloc(a1, (__int64)(v24 + 915), 0xDu, v23, 0) )
        {
          v11 = "%s: dp_srng_alloc failed for tx_comp_ring";
          goto LABEL_8;
        }
        v25 = (_DWORD *)a1[164];
        if ( v25 )
        {
          if ( *(v25 - 1) != -920731029 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, _QWORD *))v25)(a1, v24 + 915);
        }
      }
      return 0;
    }
    v11 = "%s: dp_srng_alloc failed for tcl_data_ring";
  }
  else
  {
    v11 = "%s: unexpected index!";
  }
LABEL_8:
  qdf_trace_msg(0x45u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "dp_alloc_tx_ring_pair_by_index");
  return 16;
}
