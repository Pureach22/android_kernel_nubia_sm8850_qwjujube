__int64 __fastcall wlan_ipa_setup_sys_pipe(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w8
  int v3; // w9
  int v5; // w8
  int v6; // w10
  unsigned int v7; // w20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v1 = *(_QWORD *)(a1 + 1464);
  if ( (*(_BYTE *)v1 & 0x40) != 0 )
  {
    return 0;
  }
  else
  {
    v2 = *(_DWORD *)(v1 + 4);
    v3 = *(unsigned __int8 *)(a1 + 6986);
    *(_QWORD *)(a1 + 1016) = wlan_ipa_w2i_cb;
    v5 = v2 + 8;
    if ( v3 )
      v6 = 12;
    else
      v6 = 10;
    *(_QWORD *)(a1 + 1008) = a1;
    *(_DWORD *)(a1 + 1004) = v5;
    *(_DWORD *)(a1 + 808) = 0;
    *(_DWORD *)(a1 + 1000) = v6;
    *(_DWORD *)(a1 + 896) = 0;
    *(_QWORD *)(a1 + 820) = 0x100000012LL;
    v7 = ipa_setup_sys_pipe(a1 + 808, a1 + 800);
    if ( v7 )
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Failed for RX pipe: %d",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "wlan_ipa_setup_rx_sys_pipe",
        v7);
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Failed for RX pipe: %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_ipa_setup_sys_pipe",
        v7);
      if ( a1 )
      {
        if ( *(_BYTE *)(a1 + 12) )
          *(_BYTE *)(a1 + 12) = 0;
        if ( *(_BYTE *)(a1 + 276) )
          *(_BYTE *)(a1 + 276) = 0;
        if ( *(_BYTE *)(a1 + 540) )
          *(_BYTE *)(a1 + 540) = 0;
        if ( *(_BYTE *)(a1 + 804) )
          *(_BYTE *)(a1 + 804) = 0;
      }
    }
    else
    {
      *(_BYTE *)(a1 + 804) = 1;
    }
  }
  return v7;
}
