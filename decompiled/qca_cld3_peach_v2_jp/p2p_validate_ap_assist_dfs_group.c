__int64 __fastcall p2p_validate_ap_assist_dfs_group(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  int v4; // w8
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int s[129]; // [xsp+4h] [xbp-20Ch] BYREF
  __int64 v26; // [xsp+208h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  if ( v2 )
    v3 = *(_QWORD *)(v2 + 80);
  else
    v3 = 0;
  if ( (unsigned __int8)(wlan_get_wfd_mode_from_vdev_id(v3, *(unsigned __int8 *)(a1 + 104)) - 1) > 1u )
    goto LABEL_9;
  v4 = *(_DWORD *)(a1 + 16);
  if ( v4 == 2 )
  {
    result = p2p_check_ap_assist_dfs_group_cli(a1);
    goto LABEL_10;
  }
  if ( v4 == 3 )
  {
    memset(s, 0, sizeof(s));
    v5 = *(_QWORD *)(a1 + 152);
    if ( v5 )
      v6 = *(_QWORD *)(v5 + 80);
    else
      v6 = 0;
    result = p2p_check_ap_assist_dfs_group_go(a1);
    if ( (_DWORD)result )
    {
      v16 = policy_mgr_qdf_opmode_to_pm_con_mode(v6, 3, 0xFFu, v8, v9, v10, v11, v12, v13, v14, v15);
      policy_mgr_get_pcl_for_vdev_id(
        v6,
        v16,
        (__int64)s,
        &s[128],
        (__int64)&s[102],
        0x66u,
        *(unsigned __int8 *)(a1 + 104),
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24);
      result = policy_mgr_change_sap_channel_with_csa(v6, *(unsigned __int8 *)(a1 + 104), s[0], 9u, 1);
    }
  }
  else
  {
LABEL_9:
    result = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
