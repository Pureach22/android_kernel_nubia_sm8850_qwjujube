__int64 __fastcall init_deinit_service_ext2_ready_event_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 psoc_from_scn_hdl; // x0
  __int64 v15; // x19
  __int64 v16; // x24
  __int64 v17; // x20
  __int64 result; // x0
  unsigned int inited; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w25
  const char *v29; // x2
  const char *v30; // x2
  unsigned int v31; // w0
  unsigned int v32; // w0
  unsigned int v33; // w0
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  int v67; // w26
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  _DWORD *psoc_legacy_service_ready_cb; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x8
  void (__fastcall *v94)(__int64, __int64, __int64); // x8
  char v95; // w8
  __int64 v96; // x0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  char v105; // w8
  __int64 v106; // x0
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
  char v123; // [xsp+0h] [xbp-20h] BYREF
  __int64 v124; // [xsp+1h] [xbp-1Fh]
  _BYTE v125[23]; // [xsp+9h] [xbp-17h]

  *(_QWORD *)&v125[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v30 = "%s: scn handle NULL in service ready ext2 handler";
LABEL_19:
    qdf_trace_msg(0x49u, 2u, v30, a4, a5, a6, a7, a8, a9, a10, a11, "init_deinit_service_ext2_ready_event_handler");
    goto LABEL_20;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v30 = "%s: psoc is null in service ready ext2 handler";
    goto LABEL_19;
  }
  v15 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v15 )
  {
    v30 = "%s: target_psoc_info is null in service ready ext2 handler";
    goto LABEL_19;
  }
  v16 = *(_QWORD *)(v15 + 16);
  if ( !v16 )
  {
    v30 = "%s: wmi_handle is null in service ready ext2 handler";
    goto LABEL_19;
  }
  if ( *(_DWORD *)(v15 + 488) == 1 )
  {
LABEL_20:
    result = 4294967274LL;
    goto LABEL_21;
  }
  v17 = psoc_from_scn_hdl;
  result = init_deinit_populate_service_ready_ext2_param(*(_QWORD *)(v15 + 16), a2, v15 + 40);
  if ( (_DWORD)result )
    goto LABEL_31;
  if ( (wmi_service_enabled(v16, 235) & 1) != 0 )
  {
    target_if_set_reg_cc_ext_supp(v15, v17);
    *(_DWORD *)(v17 + 20) |= 0x10000000u;
  }
  if ( (wmi_service_enabled(v16, 236) & 1) != 0 )
    *(_BYTE *)(v15 + 361) = 1;
  if ( *(_DWORD *)(v15 + 964) )
  {
    result = init_deinit_populate_dbr_ring_cap_ext2(v17, v16, a2, v15 + 40);
    if ( (_DWORD)result )
      goto LABEL_31;
  }
  inited = init_deinit_populate_hal_reg_cap_ext2(v16, a2, v15 + 40);
  if ( inited )
  {
    v28 = inited;
    v29 = "%s: failed to populate hal reg cap ext2";
LABEL_30:
    qdf_trace_msg(
      0x49u,
      2u,
      v29,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "init_deinit_service_ext2_ready_event_handler");
    result = v28;
LABEL_31:
    *(_BYTE *)(v15 + 485) = 0;
    *(_DWORD *)(v15 + 488) = 2;
    goto LABEL_21;
  }
  v31 = init_deinit_populate_power_boost_cap_ext2(v16, a2, v15 + 40);
  if ( v31 )
  {
    v28 = v31;
    v29 = "%s: failed to populate power boost cap ext2";
    goto LABEL_30;
  }
  v32 = ((__int64 (__fastcall *)(__int64, __int64, __int64))init_deinit_populate_mac_phy_cap_ext2)(v16, a2, v15 + 40);
  if ( v32 )
  {
    v28 = v32;
    v29 = "%s: failed to populate mac phy cap ext2";
    goto LABEL_30;
  }
  v33 = init_deinit_populate_scan_radio_cap_ext2(v16, a2, v15 + 40);
  if ( v33 )
  {
    v28 = v33;
    v29 = "%s: failed to populate scan radio cap ext2";
    goto LABEL_30;
  }
  v34 = init_deinit_populate_msdu_idx_qtype_map_ext2(v16, a2, v15 + 40);
  if ( v34 )
  {
    v28 = v34;
    v29 = "%s: failed to populate msdu index qtype map ext2";
    goto LABEL_30;
  }
  if ( (unsigned int)init_deinit_populate_twt_cap_ext2(v17, v16, a2, v15 + 40) )
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: failed to populate twt cap ext2",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "init_deinit_service_ext2_ready_event_handler");
  if ( (unsigned int)init_deinit_populate_dbs_or_sbs_cap_ext2(v17, v16, a2, v15 + 40) )
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: failed to populate dbs_or_sbs cap ext2",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "init_deinit_service_ext2_ready_event_handler");
  v28 = init_deinit_populate_sap_coex_capability(v17, v16, a2);
  if ( v28 )
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: failed to populate sap_coex_capability ext2",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "init_deinit_service_ext2_ready_event_handler");
  if ( *(_DWORD *)(v15 + 1020) )
  {
    v28 = init_deinit_populate_aux_dev_cap_ext2(v17, v16, a2, v15 + 40);
    if ( v28 )
    {
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: failed to populate aux_dev cap ext2",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "init_deinit_service_ext2_ready_event_handler");
    }
    else
    {
      v67 = *(_DWORD *)(*(_QWORD *)(v15 + 5776) + 8LL) >> 1;
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: FW optimize power: %d",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "init_deinit_service_ext2_ready_event_handler",
        (*(_DWORD *)(*(_QWORD *)(v15 + 5776) + 8LL) & 2) != 0);
      *(_BYTE *)(v15 + 441) &= v67;
    }
  }
  if ( (wmi_service_enabled(v16, 254) & 1) != 0 )
  {
    v28 = init_deinit_populate_rcc_aoa_cap_ext2(v17, v16, a2, v15 + 40);
    if ( v28 )
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: failed to populate aoa cap ext2",
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        "init_deinit_service_ext2_ready_event_handler");
  }
  psoc_legacy_service_ready_cb = (_DWORD *)target_if_get_psoc_legacy_service_ready_cb();
  if ( psoc_legacy_service_ready_cb )
  {
    if ( *(psoc_legacy_service_ready_cb - 1) != 548044467 )
      __break(0x8228u);
    if ( ((unsigned int (__fastcall *)(__int64, __int64, __int64, _QWORD))psoc_legacy_service_ready_cb)(220, a1, a2, a3) )
    {
      v29 = "%s: Legacy callback return error!";
      goto LABEL_30;
    }
  }
  if ( (wmi_service_enabled(v16, 303) & 1) != 0 )
  {
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: Full bw nol supported",
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      "init_deinit_service_ext2_ready_event_handler");
    *(_BYTE *)(v15 + 436) = 1;
  }
  if ( (wlan_action_oui_v2_enabled(v17) & 1) != 0 )
  {
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: action oui v2 is enabled",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "init_deinit_service_ext2_ready_event_handler");
    *(_BYTE *)(v15 + 452) = 1;
  }
  v93 = *(_QWORD *)(v15 + 5792);
  if ( v93 )
  {
    v94 = *(void (__fastcall **)(__int64, __int64, __int64))(v93 + 168);
    if ( v94 )
    {
      if ( *((_DWORD *)v94 - 1) != -1559117844 )
        __break(0x8228u);
      v94(v17, v15, a2);
    }
  }
  v95 = *(_BYTE *)(v15 + 1048);
  v96 = *(_QWORD *)(v17 + 2808);
  v124 = 0;
  *(_QWORD *)v125 = 0;
  v123 = v95;
  *(_QWORD *)&v125[7] = 0;
  if ( (unsigned int)cdp_txrx_set_psoc_param(v96, 26, &v123) )
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to set fw_support_ml_mon",
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      "init_deinit_service_ext2_ready_event_handler");
  v105 = *(_BYTE *)(v15 + 1057);
  v106 = *(_QWORD *)(v17 + 2808);
  v124 = 0;
  *(_QWORD *)v125 = 0;
  v123 = v105;
  *(_QWORD *)&v125[7] = 0;
  if ( (unsigned int)cdp_txrx_set_psoc_param(v106, 30, &v123) )
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to set tx_vdev_nss_support",
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      "init_deinit_service_ext2_ready_event_handler");
  wlan_ipa_set_fw_cap_opt_dp_ctrl(v17, *(unsigned __int8 *)(v15 + 1056));
  target_if_regulatory_set_ext_tpc(v17);
  target_if_reg_set_lower_6g_edge_ch_info(v17);
  target_if_reg_set_disable_upper_6g_edge_ch_info(v17);
  v115 = target_if_set_regulatory_is_both_psd_eirp_support_for_sp(v17);
  *(_BYTE *)(v15 + 484) = 1;
  init_deinit_prepare_send_init_cmd(v17, v15, v115, v116, v117, v118, v119, v120, v121, v122);
  result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
