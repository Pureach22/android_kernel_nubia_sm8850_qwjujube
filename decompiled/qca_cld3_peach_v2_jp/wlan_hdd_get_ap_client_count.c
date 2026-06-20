__int64 __fastcall wlan_hdd_get_ap_client_count(
        __int64 a1,
        __int64 a2,
        _WORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8

  if ( a1 )
  {
    v13 = *(_QWORD *)(a2 + 55512);
    if ( *(_BYTE *)(v13 + 257) == 1 )
    {
      *a3 = *(_WORD *)(v13 + 2352);
      a3[1] = *(_WORD *)(v13 + 2354);
      a3[2] = *(_WORD *)(v13 + 2356);
      a3[3] = *(_WORD *)(v13 + 2358);
      a3[4] = *(_WORD *)(v13 + 2360);
      a3[5] = *(_WORD *)(v13 + 2362);
      a3[6] = *(_WORD *)(v13 + 2364);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: hdd ctx is null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_hdd_get_ap_client_count",
      v11,
      v12);
    return 0;
  }
}
