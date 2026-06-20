__int64 __fastcall dfs_mlme_proc_cac(__int64 a1, unsigned int a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v12[1], 0, 40);
  v12[0] = 5258;
  scheduler_post_message_debug(0x27u, 0x34u, 52, (unsigned __int16 *)v12, 0x9Fu, (__int64)"dfs_mlme_proc_cac");
  result = qdf_trace_msg(
             0x27u,
             4u,
             "WLAN_DEBUG_DFS_ALWAYS : %s: eWNI_SME_DFS_CAC_COMPLETE vdev%d posted",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "dfs_mlme_proc_cac",
             a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
