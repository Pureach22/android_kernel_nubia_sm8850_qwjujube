__int64 __fastcall wlan_ipa_uc_disconnect_ap(
        _DWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  qdf_trace_msg(0x61u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_ipa_uc_disconnect_ap");
  if ( a1[274] != 1 )
  {
    if ( a1[306] == 1 )
    {
      if ( a1 == (_DWORD *)-1192LL )
        return 4;
    }
    else if ( a1[338] != 1 || a1 == (_DWORD *)-1320LL )
    {
      return 4;
    }
LABEL_9:
    v12 = wlan_ipa_uc_send_evt(a2, 3u, *(const void **)(a2 + 1008), (__int64)a1);
    qdf_trace_msg(0x61u, 8u, "%s: exit :%d", v13, v14, v15, v16, v17, v18, v19, v20, "wlan_ipa_uc_disconnect_ap", v12);
    return v12;
  }
  if ( a1 != (_DWORD *)-1064LL )
    goto LABEL_9;
  return 4;
}
