__int64 __fastcall policy_mgr_sta_sap_dfs_enforce_scc(__int64 a1, unsigned int a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  __int64 v13; // x21
  __int64 cmpt_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  char v23; // w22
  const char *v24; // x2
  __int64 v25; // x0
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 result; // x0
  _BYTE v44[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44[0] = 0;
  if ( policy_mgr_get_context(a1) )
  {
    v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
    if ( v12 )
    {
      v13 = v12;
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v12, v4, v5, v6, v7, v8, v9, v10, v11);
      if ( cmpt_obj )
        v23 = *(_BYTE *)(cmpt_obj + 197);
      else
        v23 = 0;
      v25 = wlan_vdev_mlme_get_cmpt_obj(v13, v15, v16, v17, v18, v19, v20, v21, v22);
      if ( v25 )
        *(_BYTE *)(v25 + 197) = 0;
      wlan_objmgr_vdev_release_ref(v13, 0x18u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
      policy_mgr_get_dfs_sta_sap_go_scc_movement(a1, v44);
      if ( (v23 & 1) == 0 || (v44[0] & 1) == 0 )
      {
        result = qdf_trace_msg(
                   0x4Fu,
                   8u,
                   "%s: SAP / GO moved before STA: %u INI g_move_sap_go_1st_on_dfs_sta_csa: %u",
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   "policy_mgr_sta_sap_dfs_enforce_scc",
                   v23 & 1,
                   v44[0]);
        goto LABEL_16;
      }
      if ( !(unsigned int)policy_mgr_get_mode_by_vdev_id(a1, a2) )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: Enforce SCC",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "policy_mgr_sta_sap_dfs_enforce_scc");
        result = policy_mgr_check_concurrent_intf_and_restart_sap(a1, 0);
        goto LABEL_16;
      }
      v24 = "%s: CSA received on non-STA connection";
    }
    else
    {
      v24 = "%s: vdev is NULL";
    }
  }
  else
  {
    v24 = "%s: Invalid context";
  }
  result = qdf_trace_msg(0x4Fu, 2u, v24, v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_sta_sap_dfs_enforce_scc");
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
