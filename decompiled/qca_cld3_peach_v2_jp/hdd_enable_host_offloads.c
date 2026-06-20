__int64 __fastcall hdd_enable_host_offloads(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 vdev_by_user; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _QWORD *v46; // x22
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w0
  int v64; // w8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  const char *v73; // x2
  const char *v74; // x3
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int *v83; // x8
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_enable_host_offloads");
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52824), 0x56u, (__int64)"hdd_enable_host_offloads");
  if ( vdev_by_user )
  {
    v21 = vdev_by_user;
    if ( (ucfg_pmo_is_vdev_supports_offload() & 1) != 0 )
    {
      if ( (ucfg_pmo_is_vdev_connected(v21) & 1) != 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: enable offloads",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "hdd_enable_host_offloads");
        v38 = hdd_enable_arp_offload(a1, v21, a2);
        hdd_enable_ns_offload(a1, v21, a2, v38, v39, v40, v41, v42, v43, v44, v45);
        v46 = *(_QWORD **)(a1 + 24);
        if ( !(unsigned int)_wlan_hdd_validate_context(
                              (__int64)v46,
                              (__int64)"hdd_enable_mc_addr_filtering",
                              v47,
                              v48,
                              v49,
                              v50,
                              v51,
                              v52,
                              v53,
                              v54)
          && hdd_cm_is_vdev_associated(*(_DWORD **)(a1 + 52824)) )
        {
          v63 = ucfg_pmo_enable_mc_addr_filtering_in_fwr(*v46, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), a2);
          if ( v63 )
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: failed to enable mc list; status:%d",
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              "hdd_enable_mc_addr_filtering",
              v63);
        }
        v64 = *(_DWORD *)(a1 + 40);
        if ( !v64 )
        {
          if ( (unsigned int)hdd_send_igmp_offload_params(a1, v21, 1) )
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Failed to enable igmp offload",
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              "hdd_enable_igmp_offload");
          v64 = *(_DWORD *)(a1 + 40);
        }
        if ( v64 != 11 )
        {
          qdf_trace_msg(0x33u, 8u, "%s: enter", v55, v56, v57, v58, v59, v60, v61, v62, "hdd_enable_hw_filter");
          if ( (unsigned int)ucfg_pmo_enable_hw_filter_in_fwr(v21) )
            qdf_trace_msg(
              0x33u,
              4u,
              "%s: Failed to enable hardware filter",
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              "hdd_enable_hw_filter");
          qdf_trace_msg(0x33u, 8u, "%s: exit", v65, v66, v67, v68, v69, v70, v71, v72, "hdd_enable_hw_filter");
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: enter",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "hdd_enable_action_frame_patterns");
        if ( (unsigned int)ucfg_pmo_enable_action_frame_patterns(v21, 0) )
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: Failed to enable action frame patterns",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "hdd_enable_action_frame_patterns");
        v73 = "%s: exit";
        v74 = "hdd_enable_action_frame_patterns";
      }
      else
      {
        v73 = "%s: offload is not supported on disconnected vdevs";
        v74 = "hdd_enable_host_offloads";
      }
      qdf_trace_msg(0x33u, 8u, v73, v30, v31, v32, v33, v34, v35, v36, v37, v74);
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: offload is not supported on vdev opmode %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_enable_host_offloads",
        *(unsigned int *)(a1 + 40));
    }
    _hdd_objmgr_put_vdev_by_user(
      v21,
      0x56u,
      (__int64)"hdd_enable_host_offloads",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91);
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_enable_host_offloads");
  }
  return qdf_trace_msg(0x33u, 8u, "%s: exit", v75, v76, v77, v78, v79, v80, v81, v82, "hdd_enable_host_offloads");
}
