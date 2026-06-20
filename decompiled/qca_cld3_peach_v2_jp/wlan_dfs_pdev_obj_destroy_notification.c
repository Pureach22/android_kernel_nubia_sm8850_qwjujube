__int64 __fastcall wlan_dfs_pdev_obj_destroy_notification(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 v11; // x20
  void (__fastcall *v12)(__int64, __int64, __int64); // x8

  if ( a1 )
  {
    result = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x10u);
    if ( result )
    {
      v11 = result;
      dfs_detach(result);
      v12 = (void (__fastcall *)(__int64, __int64, __int64))off_869060;
      if ( *((_DWORD *)off_869060 - 1) != -446440414 )
        __break(0x8228u);
      v12(a1, 16, v11);
      *(_QWORD *)(v11 + 14936) = 0;
      dfs_destroy_object();
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: PDEV is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_dfs_pdev_obj_destroy_notification");
    return 16;
  }
  return result;
}
