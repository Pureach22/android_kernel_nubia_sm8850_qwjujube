__int64 __fastcall wlan_hdd_set_wlm_client_latency_level(
        __int64 a1,
        int a2,
        __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  __int64 v12; // x8
  unsigned int v13; // w19
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  __int64 v24; // x0
  __int64 v26; // x8

  v11 = a1 + 52104;
  v12 = a1 + 52104;
  if ( *(_BYTE *)(a1 + 52112) == 1 )
  {
    if ( *(_DWORD *)(a1 + 52108) == a2 )
    {
LABEL_3:
      v13 = *(_DWORD *)v12;
      *(_WORD *)(v12 + 10) = a3;
      goto LABEL_14;
    }
    v12 = a1 + 52120;
    if ( *(_BYTE *)(a1 + 52128) == 1 )
    {
      if ( *(_DWORD *)(a1 + 52124) == a2 )
        goto LABEL_3;
      v12 = a1 + 52136;
      if ( *(_BYTE *)(a1 + 52144) == 1 )
      {
        if ( *(_DWORD *)(a1 + 52140) == a2 )
          goto LABEL_3;
        v12 = a1 + 52152;
        if ( *(_BYTE *)(a1 + 52160) == 1 )
        {
          if ( *(_DWORD *)(a1 + 52156) == a2 )
            goto LABEL_3;
          v12 = a1 + 52168;
          if ( *(_BYTE *)(a1 + 52176) == 1 )
          {
            if ( *(_DWORD *)(a1 + 52172) != a2 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Max client ID reached",
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                "wlan_hdd_get_set_client_info_id");
              return 4;
            }
            goto LABEL_3;
          }
        }
      }
    }
  }
  v13 = *(_DWORD *)v12;
  *(_DWORD *)(v12 + 4) = a2;
  *(_BYTE *)(v12 + 8) = 1;
  *(_WORD *)(v12 + 10) = a3;
  *(_BYTE *)(v12 + 12) = 0;
LABEL_14:
  result = wlan_hdd_set_wlm_latency_level(a1, a3, 1LL << v13, 0, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( (_DWORD)result )
  {
    v23 = result;
    v24 = qdf_trace_msg(
            0x33u,
            8u,
            "%s: Fail to set latency level for client_id:%d",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "wlan_hdd_set_wlm_client_latency_level",
            v13);
    if ( v13 >= 5 )
    {
      __break(0x5512u);
      __asm { LDTRSH          X20, [X1,#0xD3] }
      return hdd_set_mac_chan_width(v24);
    }
    else
    {
      result = v23;
      v26 = v11 + 16LL * v13;
      *(_BYTE *)(v26 + 8) = 0;
      *(_DWORD *)v26 = v13;
      *(_DWORD *)(v26 + 4) = 0;
      *(_WORD *)(v26 + 10) = 0;
      *(_BYTE *)(v26 + 12) = 0;
    }
  }
  return result;
}
