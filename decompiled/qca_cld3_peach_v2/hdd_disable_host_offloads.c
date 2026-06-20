__int64 __fastcall hdd_disable_host_offloads(
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
  unsigned int gtk_rsp; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int *v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  const char *v64; // x2
  const char *v65; // x3
  unsigned int v66; // w1
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  _QWORD *v83; // x22
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  unsigned int v100; // w0
  int v101; // w8
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 result; // x0
  _QWORD v111[3]; // [xsp+8h] [xbp-18h] BYREF

  v111[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_disable_host_offloads");
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x56u, (__int64)"hdd_disable_host_offloads");
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
          "%s: disable offloads",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "hdd_disable_host_offloads");
        v111[0] = wlan_hdd_cfg80211_update_replay_counter_cb;
        v111[1] = a1;
        gtk_rsp = ucfg_pmo_get_gtk_rsp(v21, v111);
        if ( gtk_rsp )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to send get gtk rsp status:%d",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "hdd_disable_gtk_offload",
            gtk_rsp);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: send get_gtk_rsp successful",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "hdd_disable_gtk_offload");
          if ( (unsigned int)ucfg_pmo_disable_gtk_offload_in_fwr(v21) )
            qdf_trace_msg(
              0x33u,
              4u,
              "%s: Failed to disable gtk offload",
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              "hdd_disable_gtk_offload");
        }
        v75 = hdd_disable_arp_offload(a1, v21, a2);
        hdd_disable_ns_offload(a1, v21, a2, v75, v76, v77, v78, v79, v80, v81, v82);
        v83 = *(_QWORD **)(a1 + 24);
        if ( !(unsigned int)_wlan_hdd_validate_context(
                              (__int64)v83,
                              (__int64)"hdd_disable_mc_addr_filtering",
                              v84,
                              v85,
                              v86,
                              v87,
                              v88,
                              v89,
                              v90,
                              v91) )
        {
          v100 = ucfg_pmo_disable_mc_addr_filtering_in_fwr(
                   *v83,
                   *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL),
                   a2);
          if ( v100 )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: failed to disable mc list; status:%d",
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              "hdd_disable_mc_addr_filtering",
              v100);
        }
        v101 = *(_DWORD *)(a1 + 40);
        if ( !v101 )
        {
          if ( (unsigned int)hdd_send_igmp_offload_params(a1, v21, 0) )
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Failed to disable igmp offload",
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              "hdd_disable_igmp_offload");
          v101 = *(_DWORD *)(a1 + 40);
        }
        if ( v101 != 11 )
        {
          qdf_trace_msg(0x33u, 8u, "%s: enter", v92, v93, v94, v95, v96, v97, v98, v99, "hdd_disable_hw_filter");
          if ( (unsigned int)ucfg_pmo_disable_hw_filter_in_fwr(v21) )
            qdf_trace_msg(
              0x33u,
              4u,
              "%s: Failed to disable hardware filter",
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              v109,
              "hdd_disable_hw_filter");
          qdf_trace_msg(0x33u, 8u, "%s: exit", v102, v103, v104, v105, v106, v107, v108, v109, "hdd_disable_hw_filter");
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: enter",
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          "hdd_disable_action_frame_patterns");
        if ( (unsigned int)ucfg_pmo_disable_action_frame_patterns(v21) )
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: Failed to disable action frame patterns",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "hdd_disable_action_frame_patterns");
        v64 = "%s: exit";
        v65 = "hdd_disable_action_frame_patterns";
        v66 = 8;
      }
      else
      {
        v64 = "%s: vdev is not connected";
        v65 = "hdd_disable_host_offloads";
        v66 = 4;
      }
      qdf_trace_msg(0x33u, v66, v64, v30, v31, v32, v33, v34, v35, v36, v37, v65);
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: offload is not supported on this vdev opmode: %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_disable_host_offloads",
        *(unsigned int *)(a1 + 40));
    }
    _hdd_objmgr_put_vdev_by_user(
      v21,
      0x56u,
      (__int64)"hdd_disable_host_offloads",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63);
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_disable_host_offloads");
  }
  result = qdf_trace_msg(0x33u, 8u, "%s: exit", v47, v48, v49, v50, v51, v52, v53, v54, "hdd_disable_host_offloads");
  _ReadStatusReg(SP_EL0);
  return result;
}
