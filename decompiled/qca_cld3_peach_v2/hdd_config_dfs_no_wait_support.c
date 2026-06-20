__int64 __fastcall hdd_config_dfs_no_wait_support(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _BOOL4 v13; // w20

  v3 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  result = _wlan_hdd_validate_context(v3, "hdd_config_dfs_no_wait_support");
  if ( !(_DWORD)result )
  {
    v13 = *(_BYTE *)(a2 + 4) != 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: configure dnw %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hdd_config_dfs_no_wait_support");
    ucfg_set_dfs_no_wait_support(*(_QWORD *)(v3 + 8), v13);
    return 0;
  }
  return result;
}
