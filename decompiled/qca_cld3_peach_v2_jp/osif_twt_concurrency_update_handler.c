__int64 __fastcall osif_twt_concurrency_update_handler(__int64 a1, __int64 a2)
{
  unsigned int connection_count; // w23
  unsigned int v5; // w24
  unsigned int sap_mode_count; // w21
  unsigned int v7; // w25
  int v8; // w22
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w3
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  const char *v36; // x3
  const char *v37; // x2
  unsigned int v38; // w1
  __int64 v39; // x4
  __int64 v40; // x0
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w23
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned __int8 v59; // w21
  unsigned int macid_by_vdev_id; // w20
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w0
  char v70[4]; // [xsp+14h] [xbp-8Ch] BYREF
  __int64 v71; // [xsp+18h] [xbp-88h] BYREF
  __int64 v72; // [xsp+20h] [xbp-80h]
  _BYTE v73[12]; // [xsp+28h] [xbp-78h] BYREF
  __int64 v74; // [xsp+34h] [xbp-6Ch]
  __int64 v75; // [xsp+3Ch] [xbp-64h]
  __int64 v76; // [xsp+44h] [xbp-5Ch]
  __int64 v77; // [xsp+4Ch] [xbp-54h]
  __int64 v78; // [xsp+54h] [xbp-4Ch]
  __int64 v79; // [xsp+5Ch] [xbp-44h]
  __int64 v80; // [xsp+64h] [xbp-3Ch]
  __int64 v81; // [xsp+6Ch] [xbp-34h]
  int v82; // [xsp+74h] [xbp-2Ch]
  int v83; // [xsp+78h] [xbp-28h] BYREF
  char v84; // [xsp+7Ch] [xbp-24h]
  _QWORD v85[2]; // [xsp+80h] [xbp-20h] BYREF
  int v86; // [xsp+90h] [xbp-10h]
  __int64 v87; // [xsp+98h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v72 = 0;
  v84 = 0;
  v83 = 0;
  v86 = 0;
  v85[0] = 0;
  v85[1] = 0;
  v70[0] = 0;
  connection_count = policy_mgr_get_connection_count(a1);
  v5 = policy_mgr_mode_specific_connection_count(a1, 0, nullptr);
  sap_mode_count = policy_mgr_get_sap_mode_count(a1, nullptr);
  v7 = policy_mgr_mode_specific_connection_count(a1, 2, nullptr);
  v8 = policy_mgr_mode_specific_connection_count(a1, 3, nullptr);
  v71 = a1;
  result = qdf_trace_msg(
             0x48u,
             8u,
             "%s: Total connection %d, sta_count %d, sap_count %d p2p_cli_count %d p2p_go_count %d",
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             "osif_twt_concurrency_update_handler",
             connection_count,
             v5,
             sap_mode_count,
             v7,
             v8);
  if ( connection_count == 3 )
  {
    if ( (policy_mgr_current_concurrency_is_scc(a1) & 1) == 0 )
    {
      result = policy_mgr_current_concurrency_is_mcc(a1);
      if ( (result & 1) == 0 )
        goto LABEL_31;
    }
    LOBYTE(v72) = 0;
    if ( !(unsigned int)wlan_objmgr_pdev_iterate_obj_list(
                          a2,
                          2,
                          (void (__fastcall *)(__int64, __int64, __int64))osif_twt_check_and_set_wfd_mode,
                          (__int64)&v71,
                          0,
                          0x5Eu) )
    {
      result = wlan_objmgr_pdev_iterate_obj_list(
                 a2,
                 2,
                 (void (__fastcall *)(__int64, __int64, __int64))osif_twt_concurrency_update_on_scc_mcc,
                 (__int64)&v71,
                 0,
                 0x5Eu);
      if ( !(_DWORD)result )
        goto LABEL_31;
      v35 = "%s: 3port SCC/MCC conc fails";
LABEL_29:
      v36 = "osif_twt_concurrency_update_handler";
      goto LABEL_30;
    }
LABEL_17:
    v35 = "%s: TWT set mode fails";
    v36 = "osif_twt_iterate_all_concurrency_vdev";
LABEL_30:
    result = qdf_trace_msg(0x48u, 2u, v35, v27, v28, v29, v30, v31, v32, v33, v34, v36);
    goto LABEL_31;
  }
  if ( connection_count == 2 )
  {
    if ( (policy_mgr_current_concurrency_is_scc(a1) & 1) == 0 && (policy_mgr_current_concurrency_is_mcc(a1) & 1) == 0 )
    {
      result = policy_mgr_is_current_hwmode_dbs(a1);
      if ( (result & 1) == 0 )
        goto LABEL_31;
      result = wlan_objmgr_pdev_iterate_obj_list(
                 a2,
                 2,
                 (void (__fastcall *)(__int64, __int64, __int64))osif_twt_concurrency_update_on_dbs,
                 (__int64)&v71,
                 0,
                 0x5Eu);
      if ( !(_DWORD)result )
        goto LABEL_31;
      v35 = "%s: 2port DBS conc fails";
      goto LABEL_29;
    }
    LOBYTE(v72) = 0;
    if ( !(unsigned int)wlan_objmgr_pdev_iterate_obj_list(
                          a2,
                          2,
                          (void (__fastcall *)(__int64, __int64, __int64))osif_twt_check_and_set_wfd_mode,
                          (__int64)&v71,
                          0,
                          0x5Eu) )
    {
      result = wlan_objmgr_pdev_iterate_obj_list(
                 a2,
                 2,
                 (void (__fastcall *)(__int64, __int64, __int64))osif_twt_concurrency_update_on_scc_mcc,
                 (__int64)&v71,
                 0,
                 0x5Eu);
      if ( !(_DWORD)result )
        goto LABEL_31;
      v35 = "%s: 2port SCC/MCC conc fails";
      goto LABEL_29;
    }
    goto LABEL_17;
  }
  if ( connection_count != 1 )
  {
    v37 = "%s: Unexpected number of connections: %d";
    v38 = 8;
    v39 = connection_count;
    goto LABEL_19;
  }
  if ( v5 )
  {
    v26 = 0;
    goto LABEL_6;
  }
  if ( !v7 )
    goto LABEL_34;
  v40 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 2, 94);
  if ( !v40 )
  {
    result = qdf_trace_msg(
               0x48u,
               2u,
               "%s: vdev is null for P2P GO opmode",
               v42,
               v43,
               v44,
               v45,
               v46,
               v47,
               v48,
               v49,
               "osif_twt_is_p2p_cli_wfd_r2_mode");
    goto LABEL_34;
  }
  v50 = *(unsigned __int8 *)(v40 + 104);
  wlan_objmgr_vdev_release_ref(v40, 0x5Eu, v41, v42, v43, v44, v45, v46, v47, v48, v49);
  result = wlan_vdev_p2p_is_wfd_r2_mode(a1, v50, v51, v52, v53, v54, v55, v56, v57, v58);
  if ( (result & 1) == 0 )
  {
LABEL_34:
    if ( sap_mode_count )
    {
      policy_mgr_get_sap_mode_info(a1, (unsigned __int64)v85, (unsigned __int64)&v83);
      v59 = 1;
    }
    else
    {
      if ( !v8 )
        goto LABEL_31;
      result = osif_twt_is_p2p_go_wfd_r2_mode(a1);
      if ( (result & 1) == 0 )
        goto LABEL_31;
      v59 = 3;
      policy_mgr_get_mode_specific_conn_info(a1, (unsigned __int64)v85, (unsigned __int64)&v83, 3u);
    }
    macid_by_vdev_id = (unsigned __int8)policy_mgr_mode_get_macid_by_vdev_id(*(_QWORD *)(a2 + 80), (unsigned __int8)v83);
    v81 = 0;
    v80 = 0;
    v79 = 0;
    v78 = 0;
    v77 = 0;
    v76 = 0;
    v75 = 0;
    v74 = 0;
    *(_DWORD *)&v73[8] = 0;
    *(_QWORD *)v73 = macid_by_vdev_id;
    v82 = 1;
    osif_twt_responder_enable(a1, (__int64)v73);
    v74 = 0;
    *(_DWORD *)v73 = macid_by_vdev_id;
    *(_QWORD *)&v73[4] = 1;
    osif_twt_requestor_disable(a1, (__int64)v73);
    ucfg_twt_cfg_get_responder(a1, v70);
    v69 = osif_twt_send_responder_disable_per_vdev(a1, v83, v59, v70[0], v61, v62, v63, v64, v65, v66, v67, v68);
    if ( !v69 || (v39 = v69, v69 == 11) )
    {
      result = ucfg_twt_update_beacon_template();
      goto LABEL_31;
    }
    v37 = "%s: TWT responder VDEV disable cmd fails %d";
    v38 = 2;
LABEL_19:
    result = qdf_trace_msg(
               0x48u,
               v38,
               v37,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               "osif_twt_concurrency_update_handler",
               v39);
    goto LABEL_31;
  }
  v26 = 2;
LABEL_6:
  policy_mgr_get_mode_specific_conn_info(a1, (unsigned __int64)v85, (unsigned __int64)&v83, v26);
  *(_DWORD *)v73 = (unsigned __int8)policy_mgr_mode_get_macid_by_vdev_id(*(_QWORD *)(a2 + 80), (unsigned __int8)v83);
  v81 = 0;
  v80 = 0;
  v79 = 0;
  v78 = 0;
  v77 = 0;
  v76 = 0;
  v75 = 0;
  v74 = 0;
  *(_QWORD *)&v73[4] = 0;
  v82 = 1;
  result = ucfg_twt_set_requestor_enable_cmd_in_progress(a1);
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result != 6 )
      result = qdf_status_to_os_return(result);
  }
  else
  {
    osif_twt_requestor_enable(a1, (__int64)v73);
    result = ucfg_twt_reset_requestor_enable_cmd_in_progress(a1);
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
