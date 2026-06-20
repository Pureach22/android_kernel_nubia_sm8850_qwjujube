__int64 __fastcall show_tdls_all_peers(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  int v15; // w0
  int v16; // w20
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  const char *v33; // x2
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w20
  int v44; // w0
  __int64 vdev_by_user; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x21
  int v56; // w0
  int v57; // w22
  unsigned int *v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 *v67[2]; // [xsp+0h] [xbp-10h] BYREF

  v67[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v67[0] = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, v67, (__int64)"show_tdls_all_peers");
  if ( v5 )
    goto LABEL_11;
  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v6, v7, v8, v9, v10, v11, v12, v13, "__show_tdls_all_peers", a1 - 1080);
  v14 = scnprintf(a3, 4096, "%s     getTdlsPeers:", (const char *)(a1 - 1080));
  v16 = v15;
  if ( (unsigned int)_hdd_validate_adapter(
                       a1 + 1312,
                       (__int64)"__show_tdls_all_peers",
                       v14,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23) )
  {
    v32 = v16;
    v33 = "\nHDD adapter is not valid\n";
LABEL_6:
    v35 = scnprintf(a3 + v32, 4096LL - v32, v33);
    goto LABEL_7;
  }
  if ( (unsigned int)_wlan_hdd_validate_context(
                       *(_QWORD *)(a1 + 1336),
                       (__int64)"__show_tdls_all_peers",
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31) )
  {
    v32 = v16;
    v33 = "\nHDD context is not valid\n";
    goto LABEL_6;
  }
  if ( (*(_DWORD *)(a1 + 1352) | 2) != 2 )
  {
    v32 = v16;
    v33 = "\nNo TDLS support for this adapter\n";
    goto LABEL_6;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 54136), 0x57u, (__int64)"__show_tdls_all_peers");
  if ( vdev_by_user )
  {
    v55 = vdev_by_user;
    wlan_cfg80211_tdls_get_all_peers(vdev_by_user, a3 + v16, 4096 - v16, v47, v48, v49, v50, v51, v52, v53, v54);
    v57 = v56;
    _hdd_objmgr_put_vdev_by_user(
      v55,
      0x57u,
      (__int64)"__show_tdls_all_peers",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66);
    v34 = v57;
  }
  else
  {
    v35 = scnprintf(a3 + v16, 4096LL - v16, "\nVDEV is NULL\n");
  }
LABEL_7:
  v43 = v34 + v16;
  if ( v43 == 4096 )
  {
    v5 = 4096;
  }
  else
  {
    v35 = scnprintf(a3 + v43, 4096LL - v43, "\n", v35);
    v5 = v44 + v43;
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v35, v36, v37, v38, v39, v40, v41, v42, "__show_tdls_all_peers");
  _osif_vdev_sync_op_stop((__int64)v67[0], (__int64)"show_tdls_all_peers");
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v5;
}
