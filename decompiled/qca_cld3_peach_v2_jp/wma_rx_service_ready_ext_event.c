__int64 __fastcall wma_rx_service_ready_ext_event(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  __int64 v41; // x21
  const char *v42; // x2
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  char v60; // w8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x1
  char v70; // w8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  bool v79; // w1
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  char v112; // w8
  char v113; // w0
  __int64 v114; // x4
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7

  context = _cds_get_context(71, (__int64)"wma_rx_service_ready_ext_event", a3, a4, a5, a6, a7, a8, a9, a10);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", v13, v14, v15, v16, v17, v18, v19, v20, "wma_rx_service_ready_ext_event");
  if ( !a1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "__wma_validate_handle",
      "wma_rx_service_ready_ext_event");
    return 4294967274LL;
  }
  v29 = *(_QWORD *)(a1 + 24);
  if ( v29 && (v30 = *(_QWORD *)(v29 + 2800)) != 0 )
    v31 = *(_QWORD *)(v30 + 16);
  else
    v31 = 0;
  if ( (unsigned int)_wmi_validate_handle(
                       v31,
                       (__int64)"wma_rx_service_ready_ext_event",
                       v21,
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28) )
    return 4294967274LL;
  v40 = *(_QWORD *)(a1 + 24);
  if ( !v40 || (v41 = *(_QWORD *)(v40 + 2800)) == 0 )
  {
    v42 = "%s: target psoc info is NULL";
    goto LABEL_15;
  }
  if ( !a2 )
  {
    v42 = "%s: Invalid event";
    goto LABEL_15;
  }
  if ( !*a2 )
  {
    v42 = "%s: Invalid buffer";
    goto LABEL_15;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: WMA <-- WMI_SERVICE_READY_EXT_EVENTID",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "wma_rx_service_ready_ext_event");
  if ( (unsigned int)qdf_mc_timer_stop(a1 + 2928) )
  {
    v42 = "%s: Failed to stop the service ready ext timer";
LABEL_15:
    qdf_trace_msg(0x36u, 2u, v42, v32, v33, v34, v35, v36, v37, v38, v39, "wma_rx_service_ready_ext_event");
    return 4294967274LL;
  }
  wma_populate_soc_caps(v41);
  if ( (unsigned int)wma_update_hw_mode_list(a1, v41) )
  {
    v42 = "%s: Failed to update hw mode list";
    goto LABEL_15;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: WMA --> WMI_INIT_CMDID",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "wma_rx_service_ready_ext_event");
  wma_update_hw_mode_config(a1, v41, v44, v45, v46, v47, v48, v49, v50, v51);
  *(_BYTE *)(v41 + 487) = 1;
  wlan_dp_update_peer_map_unmap_version();
  *(_BYTE *)(v41 + 439) = (unsigned int)cds_get_conparam() == 4;
  if ( (wmi_service_enabled(v31, 0xA2u, v52, v53, v54, v55, v56, v57, v58, v59) & 1) != 0 )
  {
    cdp_cfg_set_new_htt_msg_format(context, 1);
    v60 = *(_BYTE *)(v41 + 232) | 8;
  }
  else
  {
    cdp_cfg_set_new_htt_msg_format(context, 0);
    v60 = *(_BYTE *)(v41 + 232) & 0xF7;
  }
  *(_BYTE *)(v41 + 232) = v60;
  if ( (unsigned int)cds_get_conparam() != 5
    && (wlan_mlme_get_peer_unmap_conf(*(_QWORD *)(a1 + 24)) & 1) != 0
    && (wmi_service_enabled(v31, 0xA3u, v61, v62, v63, v64, v65, v66, v67, v68) & 1) != 0 )
  {
    v69 = 1;
    v70 = *(_BYTE *)(v41 + 232) | 0x10;
  }
  else
  {
    v69 = 0;
    v70 = *(_BYTE *)(v41 + 232) & 0xEF;
  }
  *(_BYTE *)(v41 + 232) = v70;
  cdp_cfg_set_peer_unmap_conf_support(context, v69);
  v79 = *(_BYTE *)(a1 + 3953) == 1 && (wmi_service_enabled(v31, 0xB6u, v71, v72, v73, v74, v75, v76, v77, v78) & 1) != 0;
  *(_BYTE *)(v41 + 341) = v79;
  v80 = cdp_cfg_set_tx_compl_tsf64(context);
  *(_BYTE *)(v41 + 359) = 0;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0xC3u, v80, v81, v82, v83, v84, v85, v86, v87) & 1) != 0 )
    v88 = ucfg_nan_set_vdev_creation_supp_by_fw(*(_QWORD *)(a1 + 24), 1);
  if ( (wmi_service_enabled(v31, 0x55u, v88, v89, v90, v91, v92, v93, v94, v95) & 1) == 0 )
    *(_DWORD *)(a1 + 2916) = *(_DWORD *)(v41 + 740);
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0x43u, v96, v97, v98, v99, v100, v101, v102, v103) & 1) != 0 )
  {
    if ( (ucfg_nan_is_vdev_creation_allowed(*(_QWORD *)(a1 + 24)) & 1) != 0
      || (unsigned int)cds_get_conparam() == 5
      || (cfg_nan_get_enable(*(_QWORD *)(a1 + 24)) & 1) == 0 )
    {
      *(_BYTE *)(v41 + 358) = 1;
    }
    else
    {
      --*(_DWORD *)(v41 + 64);
      wma_update_num_peers_tids(a1, v41 + 64);
    }
  }
  v112 = *(_BYTE *)(v41 + 232);
  *(_DWORD *)(v41 + 200) = 0;
  *(_BYTE *)(v41 + 232) = v112 & 0xDF;
  v113 = wmi_service_enabled(v31, 0xF4u, v104, v105, v106, v107, v108, v109, v110, v111);
  v114 = *(unsigned int *)(v41 + 64);
  *(_BYTE *)(v41 + 396) = v113 & 1;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: num_vdevs: %u",
    v115,
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    "wma_rx_service_ready_ext_event",
    v114);
  wma_init_dbr_params(a1);
  target_if_mgmt_rx_srng_update_support(*(_QWORD *)(a1 + 24), v31);
  return 0;
}
