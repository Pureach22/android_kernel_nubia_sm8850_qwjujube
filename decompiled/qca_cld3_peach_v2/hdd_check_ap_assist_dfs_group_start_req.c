__int64 __fastcall hdd_check_ap_assist_dfs_group_start_req(__int64 a1, __int64 a2, __int16 a3, unsigned int a4)
{
  __int64 vdev_by_user; // x0
  __int64 v8; // x8
  __int64 v9; // x19
  __int64 v10; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x22
  unsigned int v20; // w20
  unsigned __int8 v21; // w22
  unsigned int ap_assist_dfs_params; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _BYTE v40[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v41[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v42[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v43; // [xsp+10h] [xbp-10h] BYREF
  __int16 v44; // [xsp+14h] [xbp-Ch]
  __int64 v45; // [xsp+18h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42[0] = 0;
  v41[0] = 0;
  v40[0] = 0;
  v44 = 0;
  v43 = 0;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_check_ap_assist_dfs_group_start_req");
  if ( vdev_by_user )
  {
    v8 = *(_QWORD *)(vdev_by_user + 216);
    v9 = vdev_by_user;
    if ( v8 )
    {
      v10 = *(_QWORD *)(v8 + 80);
      ucfg_mlme_get_dfs_master_capability(v10, v42);
      if ( v42[0] == 1 )
      {
        v19 = jiffies;
        if ( hdd_check_ap_assist_dfs_group_start_req___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Driver is DFS Master Cap so ignore checks",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            "hdd_check_ap_assist_dfs_group_start_req");
          v20 = 0;
          hdd_check_ap_assist_dfs_group_start_req___last_ticks = v19;
        }
        else
        {
          v20 = 0;
        }
      }
      else
      {
        v21 = ucfg_p2p_fw_support_ap_assist_dfs_group(v10, v11, v12, v13, v14, v15, v16, v17, v18);
        ap_assist_dfs_params = ucfg_p2p_extract_ap_assist_dfs_params(v9, a2, a3, 1, a4, 1);
        if ( ap_assist_dfs_params )
        {
          v20 = ap_assist_dfs_params;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Error parsing P2P2 IE",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "hdd_check_ap_assist_dfs_group_start_req");
        }
        else
        {
          ucfg_p2p_get_ap_assist_dfs_params(v9, v40, v41, nullptr, (__int64)&v43, nullptr, nullptr);
          if ( ((v40[0] ^ 1) & v41[0] & v21 & 1) != 0 )
          {
            v20 = ucfg_p2p_check_ap_assist_dfs_group_go(v9);
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: error GO DFS owner %d, FW CAP %d",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "hdd_check_ap_assist_dfs_group_start_req");
            v20 = 16;
          }
        }
      }
    }
    else
    {
      v20 = 4;
    }
    _hdd_objmgr_put_vdev_by_user(v9, 6, "hdd_check_ap_assist_dfs_group_start_req");
  }
  else
  {
    v20 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v20;
}
