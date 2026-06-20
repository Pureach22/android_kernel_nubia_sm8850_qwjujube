__int64 __fastcall extract_wlan_radar_event_info_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8

  if ( a10 )
  {
    v13 = *a10;
    *(_BYTE *)a11 = *(_BYTE *)(*a10 + 32);
    *(_DWORD *)(a11 + 4) = *(_DWORD *)(v13 + 20);
    *(_DWORD *)(a11 + 8) = *(_DWORD *)(v13 + 16);
    *(_BYTE *)(a11 + 12) = *(_BYTE *)(v13 + 33);
    *(_DWORD *)(a11 + 16) = *(_DWORD *)(v13 + 12);
    *(_DWORD *)(a11 + 24) = *(_DWORD *)(v13 + 8);
    *(_DWORD *)(a11 + 20) = *(_DWORD *)(v13 + 4);
    *(_DWORD *)(a11 + 28) = *(_DWORD *)(v13 + 36);
    *(_BYTE *)(a11 + 34) = *(_DWORD *)(v13 + 40);
    *(_BYTE *)(a11 + 33) = *(_DWORD *)(v13 + 44);
    if ( (*(_BYTE *)(v13 + 52) & 1) != 0 )
    {
      *(_BYTE *)(a11 + 36) = 1;
      *(_BYTE *)(a11 + 35) = *(_DWORD *)(v13 + 48);
    }
    else
    {
      *(_BYTE *)(a11 + 36) = 0;
    }
    *(_BYTE *)(a11 + 32) = *(_BYTE *)(v13 + 35);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid wlan radar event buf",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_wlan_radar_event_info_tlv",
      v11,
      v12);
    return 16;
  }
}
