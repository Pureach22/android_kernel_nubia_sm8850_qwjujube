__int64 __fastcall hdd_ndp_new_peer_handler(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        unsigned int *a11,
        char a12)
{
  __int64 *context; // x0
  __int64 *v16; // x20
  __int64 *link_info_by_vdev; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x24
  __int64 v27; // x22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int16 v45; // w9
  __int64 v46; // x21
  char v47; // w2
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 vdev_by_user; // x0
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x24
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int *v106; // x8
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  long double v139; // q0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7

  context = _cds_get_context(51, (__int64)"hdd_ndp_new_peer_handler", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4294967274LL;
  v16 = context;
  link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev((__int64)context, a1);
  if ( link_info_by_vdev )
  {
    v26 = (__int64)link_info_by_vdev;
    v27 = *link_info_by_vdev;
    if ( (hdd_save_peer(
            (__int64)(link_info_by_vdev + 10),
            (unsigned __int8 *)a11,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25)
        & 1) != 0 )
    {
      v36 = _qdf_mem_malloc(0x180u, "hdd_ndp_new_peer_handler", 1226);
      if ( v36 )
      {
        v45 = *((_WORD *)a11 + 2);
        v46 = v36;
        *(_DWORD *)(v36 + 17) = *a11;
        v47 = *(_BYTE *)(v36 + 42);
        *(_WORD *)(v36 + 21) = v45;
        hdd_roam_register_sta(
          (__int64 *)v26,
          (unsigned __int8 *)(v36 + 17),
          v47,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44);
        if ( (a12 & 1) != 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Set ctx connection state to connected",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "hdd_ndp_new_peer_handler");
          if ( ucfg_dp_is_ol_enabled(*v16)
            && (ucfg_is_nan_dbs_supported(*v16, v56, v57, v58, v59, v60, v61, v62, v63) & 1) == 0
            && (ucfg_is_nan_conc_control_supported(*v16, v64, v65, v66, v67, v68, v69, v70, v71) & 1) == 0 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Disable LRO/GRO in NDI Mode",
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              "hdd_ndp_new_peer_handler");
            hdd_disable_rx_ol_in_concurrency(1, v80, v81, v82, v83, v84, v85, v86, v87);
          }
          *(_DWORD *)(v26 + 304) = 2;
          vdev_by_user = _hdd_objmgr_get_vdev_by_user(v26, 0x61u, (__int64)"hdd_ndp_new_peer_handler");
          if ( vdev_by_user )
          {
            v97 = vdev_by_user;
            ucfg_dp_bus_bw_compute_prev_txrx_stats(vdev_by_user, v89, v90, v91, v92, v93, v94, v95, v96);
            ucfg_nan_set_peer_mc_list(
              v97,
              *a11 | ((unsigned __int64)*((unsigned __int16 *)a11 + 2) << 32),
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              v104,
              v105);
            _hdd_objmgr_put_vdev_by_user(
              v97,
              0x61u,
              (__int64)"hdd_ndp_new_peer_handler",
              v106,
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114);
          }
          ucfg_dp_bus_bw_compute_timer_start(*v16, v89, v90, v91, v92, v93, v94, v95, v96);
          hdd_wmm_connect(v27, v115, v116, v117, v118, v119, v120, v121, v122);
          wlan_hdd_netif_queue_control(v27, 5u, 1u, v123, v124, v125, v126, v127, v128, v129, v130);
          if ( (ucfg_is_ndi_dbs_supported(*v16, v131, v132, v133, v134, v135, v136, v137, v138) & 1) == 0
            && (ucfg_is_nan_conc_control_supported(*v16, *(double *)&v139, v140, v141, v142, v143, v144, v145, v146) & 1) == 0 )
          {
            *(double *)&v139 = hdd_indicate_active_ndp_cnt(
                                 *v16,
                                 a1,
                                 1,
                                 *(double *)&v139,
                                 v147,
                                 v148,
                                 v149,
                                 v150,
                                 v151,
                                 v152,
                                 v153);
          }
          hdd_send_obss_scan_req(v16, 1, v139);
        }
        _qdf_mem_free(v46);
        return 0;
      }
      else
      {
        return 4294967284LL;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Ndp peer table full. cannot save new peer",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_ndp_new_peer_handler");
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid vdev", v18, v19, v20, v21, v22, v23, v24, v25, "hdd_ndp_new_peer_handler");
    return 4294967274LL;
  }
}
