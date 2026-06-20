__int64 __fastcall wlan_mlme_get_supported_wifi_generations_info(
        __int64 a1,
        _BYTE *a2,
        _BYTE *a3,
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

  if ( a1 && (v13 = *(_QWORD *)(a1 + 2800)) != 0 )
  {
    *a2 = *(_BYTE *)(v13 + 1058);
    *a3 = *(_BYTE *)(v13 + 1059);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: target psoc info is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_mlme_get_supported_wifi_generations_info",
      v11,
      v12);
    return 16;
  }
}
