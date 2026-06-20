__int64 __fastcall wlan_mlme_get_fw_optimized_power_cap(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x8

  if ( a1 && (v12 = *(_QWORD *)(a1 + 2800)) != 0 )
  {
    *a2 = *(_BYTE *)(v12 + 441);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: target psoc info is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_mlme_get_fw_optimized_power_cap",
      v10,
      v11);
    return 16;
  }
}
