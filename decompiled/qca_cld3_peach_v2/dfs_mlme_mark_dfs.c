__int64 __fastcall dfs_mlme_mark_dfs(
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
  unsigned int v10; // w19
  __int64 v11; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _DWORD v29[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v30; // [xsp+10h] [xbp-30h]
  __int64 v31; // [xsp+18h] [xbp-28h]
  __int64 v32; // [xsp+20h] [xbp-20h]
  __int64 v33; // [xsp+28h] [xbp-18h]
  __int64 v34; // [xsp+30h] [xbp-10h]
  __int64 v35; // [xsp+38h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    result = (__int64)wlan_pdev_peek_active_first_vdev(a1, 0xEu);
    if ( result )
    {
      v10 = *(unsigned __int8 *)(result + 168);
      v11 = result;
      v33 = 0;
      v34 = 0;
      v31 = 0;
      v32 = 0;
      v30 = 0;
      v29[0] = 5203;
      v29[1] = v10;
      scheduler_post_message_debug(0x27u, 0x34u, 52, (unsigned __int16 *)v29, 0x51u, (__int64)"dfs_send_radar_ind");
      qdf_trace_msg(
        0x27u,
        8u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: eWNI_SME_DFS_RADAR_FOUND pdev%d posted",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dfs_send_radar_ind",
        v10);
      result = wlan_objmgr_vdev_release_ref(v11, 0xEu, v20, v21, v22, v23, v24, v25, v26, v27, v28);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x27u,
               2u,
               "WLAN_DEBUG_DFS_ALWAYS : %s: null pdev",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "dfs_mlme_mark_dfs");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
