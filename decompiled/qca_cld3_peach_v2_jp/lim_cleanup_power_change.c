__int64 __fastcall lim_cleanup_power_change(__int64 result, __int64 a2)
{
  int v2; // w2
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  v2 = *(_DWORD *)(a2 + 7036);
  if ( (v2 | 2) == 2 )
  {
    result = lim_get_concurrent_session(result, *(_BYTE *)(a2 + 10), v2);
    if ( result )
      return wlan_set_tpc_update_required_for_sta(*(_QWORD *)(result + 16), 0, v3, v4, v5, v6, v7, v8, v9, v10);
  }
  return result;
}
