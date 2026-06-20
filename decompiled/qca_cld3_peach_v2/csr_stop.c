__int64 __fastcall csr_stop(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _DWORD *comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x8
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 v41; // x20
  char *v42; // x23
  const char *v43; // x22
  const char *v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7

  if ( *(_BYTE *)(a1[1] + 6600LL) == 1 )
    ucfg_scan_unregister_event_handler(
      a1[2704],
      (__int64)csr_scan_event_handler,
      (__int64)a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9);
  comp_private_obj = (_DWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1[2703], 3u);
  if ( comp_private_obj )
  {
    *comp_private_obj |= 2u;
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: Psoc scan_disabled %x",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_scan_psoc_set_disable");
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_psoc_set_disable",
      919);
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: Failed to get scan object",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_scan_psoc_set_disable");
  }
  csr_purge_pdev_all_ser_cmd_list(a1);
  csr_cleanup_vdev_session(a1, 0);
  csr_cleanup_vdev_session(a1, 1);
  csr_cleanup_vdev_session(a1, 2);
  csr_cleanup_vdev_session(a1, 3);
  csr_cleanup_vdev_session(a1, 4);
  csr_cleanup_vdev_session(a1, 5);
  if ( a1 )
  {
    v35 = a1[2162];
    if ( v35 )
    {
      if ( *(_BYTE *)(v35 + 1) == 1 )
        ucfg_scan_flush_results(a1[2704], 0, v27, v28, v29, v30, v31, v32, v33, v34);
      v36 = a1[2162];
      if ( v36 )
      {
        if ( *(_BYTE *)(v36 + 97) == 1 )
          ucfg_scan_flush_results(a1[2704], 0, v27, v28, v29, v30, v31, v32, v33, v34);
        v37 = a1[2162];
        if ( v37 )
        {
          if ( *(_BYTE *)(v37 + 193) == 1 )
            ucfg_scan_flush_results(a1[2704], 0, v27, v28, v29, v30, v31, v32, v33, v34);
          v38 = a1[2162];
          if ( v38 )
          {
            if ( *(_BYTE *)(v38 + 289) == 1 )
              ucfg_scan_flush_results(a1[2704], 0, v27, v28, v29, v30, v31, v32, v33, v34);
            v39 = a1[2162];
            if ( v39 )
            {
              if ( *(_BYTE *)(v39 + 385) == 1 )
                ucfg_scan_flush_results(a1[2704], 0, v27, v28, v29, v30, v31, v32, v33, v34);
              v40 = a1[2162];
              if ( v40 && *(_BYTE *)(v40 + 481) == 1 )
                ucfg_scan_flush_results(a1[2704], 0, v27, v28, v29, v30, v31, v32, v33, v34);
            }
          }
        }
      }
    }
  }
  v41 = 0;
  v42 = (char *)a1 + 17244;
  do
  {
    if ( *(_DWORD *)&v42[4 * v41] )
    {
      v43 = mac_trace_getcsr_roam_state(0);
      v44 = mac_trace_getcsr_roam_state(*(_DWORD *)&v42[4 * v41]);
      qdf_trace_msg(
        0x34u,
        8u,
        "CSR RoamState[%d]: [ %s <== %s ]",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        (unsigned int)v41,
        v43,
        v44);
      if ( *(_DWORD *)&v42[4 * v41] == 2 )
        csr_roam_substate_change(a1, 0, (unsigned int)v41);
      *(_DWORD *)&v42[4 * v41] = 0;
    }
    csr_roam_substate_change(a1, 0, (unsigned int)v41++);
  }
  while ( v41 != 6 );
  return 0;
}
