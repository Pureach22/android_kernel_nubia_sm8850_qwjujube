__int64 __fastcall hdd_wlan_update_target_info(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = hif_get_target_info_handle(a2);
  if ( !result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Target info is Null",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "hdd_wlan_update_target_info");
  *(_DWORD *)(a1 + 528) = *(_DWORD *)(result + 4);
  return result;
}
