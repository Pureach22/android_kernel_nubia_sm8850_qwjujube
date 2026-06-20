__int64 __fastcall p2p_check_ap_assist_dfs_group_go_with_csa(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int s[129]; // [xsp+4h] [xbp-20Ch] BYREF
  __int64 v23; // [xsp+208h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v2 = *(_QWORD *)(a1 + 152);
  if ( v2 )
    v3 = *(_QWORD *)(v2 + 80);
  else
    v3 = 0;
  result = p2p_check_ap_assist_dfs_group_go(a1);
  if ( (_DWORD)result )
  {
    v13 = policy_mgr_qdf_opmode_to_pm_con_mode(v3, 3, 0xFFu, v5, v6, v7, v8, v9, v10, v11, v12);
    policy_mgr_get_pcl_for_vdev_id(
      v3,
      v13,
      (__int64)s,
      &s[128],
      (__int64)&s[102],
      0x66u,
      *(unsigned __int8 *)(a1 + 104),
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21);
    result = policy_mgr_change_sap_channel_with_csa(v3, *(unsigned __int8 *)(a1 + 104), s[0], 9u, 1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
