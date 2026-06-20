__int64 __fastcall wlan_dfs_pdev_obj_create_notification(
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
  __int64 v9; // x20
  __int64 dfs_txops; // x0
  _DWORD *v12; // x8
  _QWORD *v13; // x21
  const char *v14; // x2
  __int64 result; // x0
  __int64 v16; // x2
  unsigned int (__fastcall *v17)(__int64, __int64, __int64, _QWORD); // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int64 (__fastcall *v27)(_QWORD); // x8
  char v28; // w0
  __int64 v29; // x8
  __int64 (__fastcall *v30)(_QWORD); // x8
  char v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 (__fastcall *v40)(_QWORD); // x8
  char v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x8
  __int64 comp_private_obj; // x0
  __int64 v52; // x8
  __int64 (__fastcall *v53)(_QWORD); // x9
  char v54; // w0
  int v55; // [xsp+4h] [xbp-1Ch] BYREF
  int v56; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v57[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v58[2]; // [xsp+10h] [xbp-10h] BYREF

  v58[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58[0] = 0;
  v57[0] = 0;
  v55 = 0;
  v56 = 0;
  if ( !a1 )
  {
    v14 = "WLAN_DEBUG_DFS_ALWAYS : %s: null pdev";
    goto LABEL_12;
  }
  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v14 = "WLAN_DEBUG_DFS_ALWAYS : %s: null psoc";
    goto LABEL_12;
  }
  wlan_reg_get_freq_range(a1, nullptr, nullptr, &v56, &v55);
  dfs_txops = wlan_psoc_get_dfs_txops(v9);
  if ( !dfs_txops || (v12 = *(_DWORD **)(dfs_txops + 112)) == nullptr )
  {
    v14 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_tx_ops is null";
    goto LABEL_12;
  }
  v13 = (_QWORD *)dfs_txops;
  if ( *(v12 - 1) != -1393108416 )
    __break(0x8228u);
  if ( !((unsigned int (__fastcall *)(__int64, _BYTE *))v12)(a1, v57) )
  {
    if ( (v57[0] & 1) != 0 )
    {
      if ( (unsigned int)dfs_create_object((__int64)v58) == 1 )
      {
        v14 = "WLAN_DEBUG_DFS_ALWAYS : %s: failed to create object";
        goto LABEL_12;
      }
      v16 = v58[0];
      v17 = (unsigned int (__fastcall *)(__int64, __int64, __int64, _QWORD))global_dfs_to_mlme;
      if ( *((_DWORD *)global_dfs_to_mlme - 1) != 663692385 )
        __break(0x8228u);
      if ( v17(a1, 16, v16, 0) )
      {
        v26 = "WLAN_DEBUG_DFS_ALWAYS : %s: obj attach failed";
LABEL_26:
        qdf_trace_msg(0x27u, 2u, v26, v18, v19, v20, v21, v22, v23, v24, v25, "wlan_dfs_pdev_obj_create_notification");
        dfs_destroy_object();
        goto LABEL_13;
      }
      *(_QWORD *)(v58[0] + 14936LL) = a1;
      v27 = (__int64 (__fastcall *)(_QWORD))v13[16];
      if ( !v27 )
      {
        v26 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_is_tgt_offload is null";
        goto LABEL_26;
      }
      if ( *((_DWORD *)v27 - 1) != -1548408 )
        __break(0x8228u);
      v28 = v27(v9);
      v29 = v58[0];
      *(_BYTE *)(v58[0] + 14954LL) = v28 & 1;
      if ( !v29 || (*(_BYTE *)(v29 + 1) & 1) != 0 )
        qdf_trace_msg(
          0x27u,
          4u,
          "WLAN_DEBUG_DFS : %s: dfs_offload %d",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "wlan_dfs_pdev_obj_create_notification");
      v30 = (__int64 (__fastcall *)(_QWORD))v13[17];
      if ( !v30 )
      {
        v26 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_is_tgt_bangradar_320_supp is null";
        goto LABEL_26;
      }
      if ( *((_DWORD *)v30 - 1) != -1548408 )
        __break(0x8228u);
      v31 = v30(v9);
      *(_BYTE *)(v58[0] + 14955LL) = v31 & 1;
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_bangradar_320_support %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "wlan_dfs_pdev_obj_create_notification");
      v40 = (__int64 (__fastcall *)(_QWORD))v13[18];
      if ( !v40 )
      {
        v26 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_is_radar_found_chan_freq_eq_center_freq is null";
        goto LABEL_26;
      }
      if ( *((_DWORD *)v40 - 1) != -1548408 )
        __break(0x8228u);
      v41 = v40(v9);
      v50 = v58[0];
      *(_BYTE *)(v58[0] + 14956LL) = v41 & 1;
      if ( !v50 || (*(_BYTE *)(v50 + 1) & 1) != 0 )
        qdf_trace_msg(
          0x27u,
          4u,
          "WLAN_DEBUG_DFS : %s: dfs_is_radar_found_chan_freq_eq_center_freq %d",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "wlan_dfs_pdev_obj_create_notification");
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v9, 0x10u);
      v52 = v58[0];
      *(_QWORD *)(v58[0] + 14944LL) = comp_private_obj;
      v53 = (__int64 (__fastcall *)(_QWORD))v13[25];
      if ( v53 )
      {
        if ( *((_DWORD *)v53 - 1) != -1102235987 )
          __break(0x8229u);
        v54 = v53(a1);
        v52 = v58[0];
        *(_BYTE *)(v58[0] + 80LL) = v54 & 1;
      }
      else
      {
        *(_BYTE *)(v52 + 80) = 0;
      }
      if ( (unsigned int)dfs_attach(v52) == 1 )
      {
        v26 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_attch failed";
        goto LABEL_26;
      }
    }
    else if ( !v58[0] || (*((_BYTE *)&off_0 + v58[0] + 1) & 1) != 0 )
    {
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS : %s: Do not allocate DFS object for 2G, pdev_id = %d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_dfs_pdev_obj_create_notification",
        *(unsigned __int8 *)(a1 + 40));
      result = 0;
      goto LABEL_14;
    }
    result = 0;
    goto LABEL_14;
  }
  v14 = "WLAN_DEBUG_DFS_ALWAYS : %s: Failed to get is_5ghz value";
LABEL_12:
  qdf_trace_msg(0x27u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dfs_pdev_obj_create_notification");
LABEL_13:
  result = 16;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
