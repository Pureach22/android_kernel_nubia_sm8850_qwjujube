__int64 __fastcall ucfg_scan_suspend_handler(__int64 a1)
{
  _DWORD *comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 pdev_by_id; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  void *v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x21
  _QWORD *first_vdev; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x22
  int v49; // w8
  unsigned int *v50; // x8
  unsigned int v51; // w21
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7

  comp_private_obj = (_DWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    *comp_private_obj |= 1u;
    qdf_trace_msg(0x15u, 8u, "%s: Psoc scan_disabled %x", v3, v4, v5, v6, v7, v8, v9, v10, "wlan_scan_psoc_set_disable");
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_psoc_set_disable",
      919);
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: Failed to get scan object",
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
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 0xCu);
  if ( pdev_by_id )
  {
    v28 = pdev_by_id;
    if ( (unsigned int)wlan_get_pdev_status(pdev_by_id, v20, v21, v22, v23, v24, v25, v26, v27) )
    {
      v29 = qdf_mem_malloc_atomic_fl(0x20u, (__int64)"scan_cancel_pdev_scan", 0x4DAu);
      if ( v29 )
      {
        v38 = (__int64)v29;
        first_vdev = wlan_objmgr_pdev_get_first_vdev(v28, 0xCu);
        if ( first_vdev )
        {
          *(_QWORD *)v38 = first_vdev;
          v48 = (__int64)first_vdev;
          *(_DWORD *)(v38 + 16) = -1;
          v49 = *(unsigned __int8 *)(v28 + 40);
          *(_QWORD *)(v38 + 20) = 0xFFFFFFFF00000003LL;
          *(_DWORD *)(v38 + 28) = v49;
          v51 = ucfg_scan_cancel_sync(v38, v40, v41, v42, v43, v44, v45, v46, v47);
          if ( v51 )
            qdf_trace_msg(
              0x15u,
              2u,
              "%s: Cancel scan request failed",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "scan_cancel_pdev_scan");
          wlan_objmgr_vdev_release_ref(v48, 0xCu, v50, v52, v53, v54, v55, v56, v57, v58, v59);
        }
        else
        {
          qdf_trace_msg(
            0x15u,
            2u,
            "%s: Failed to get vdev",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "scan_cancel_pdev_scan");
          _qdf_mem_free(v38);
          v51 = 4;
        }
      }
      else
      {
        v51 = 2;
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: Failed to allocate memory",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "scan_cancel_pdev_scan");
      }
    }
    else
    {
      v51 = 0;
    }
    scm_disable_obss_pdev_scan(a1, v28);
    wlan_objmgr_pdev_release_ref(v28, 0xCu, v60, v61, v62, v63, v64, v65, v66, v67, v68);
    if ( v51 )
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: failed to cancel scan for pdev_id %d",
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        "ucfg_scan_suspend_handler",
        0);
  }
  else
  {
    return 0;
  }
  return v51;
}
