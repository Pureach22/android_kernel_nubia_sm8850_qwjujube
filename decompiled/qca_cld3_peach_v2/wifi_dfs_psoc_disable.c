__int64 __fastcall wifi_dfs_psoc_disable(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w19

  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))wlan_serialization_deregister_comp_info_cb)(a1, 16, 0);
  if ( (_DWORD)result )
  {
    v10 = result;
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: Serialize scan cmd deregister failed",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wifi_dfs_psoc_disable");
    return v10;
  }
  return result;
}
