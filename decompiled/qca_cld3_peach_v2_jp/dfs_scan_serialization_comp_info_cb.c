__int64 __fastcall dfs_scan_serialization_comp_info_cb(
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
  __int64 v10; // x19
  __int64 v11; // x0
  __int64 result; // x0
  const char *v13; // x2

  if ( !a2 )
  {
    v13 = "WLAN_DEBUG_DFS_ALWAYS : %s: comp_info is NULL";
    return qdf_trace_msg(0x27u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "dfs_scan_serialization_comp_info_cb");
  }
  if ( !a1 )
  {
    v13 = "WLAN_DEBUG_DFS_ALWAYS : %s: vdev is NULL";
    return qdf_trace_msg(0x27u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "dfs_scan_serialization_comp_info_cb");
  }
  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 )
  {
    v13 = "WLAN_DEBUG_DFS_ALWAYS : %s: pdev is NULL";
    return qdf_trace_msg(0x27u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "dfs_scan_serialization_comp_info_cb");
  }
  v11 = *(_QWORD *)(a1 + 152);
  *a2 = 0;
  result = tgt_dfs_is_5ghz_supported_in_pdev(v11);
  if ( (result & 1) != 0 )
  {
    result = wlan_objmgr_pdev_get_comp_private_obj(v10, 0x10u);
    if ( !result )
    {
      v13 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL";
      return qdf_trace_msg(0x27u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "dfs_scan_serialization_comp_info_cb");
    }
  }
  return result;
}
