__int64 __fastcall policy_mgr_sta_sap_dfs_scc_conc_check(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x27
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  __int64 result; // x0
  __int64 v26; // x0
  __int64 v27; // x20
  __int64 v28; // x23
  unsigned int operation_chan_freq_vdev_id; // w25
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
  unsigned __int64 v46; // x8
  unsigned int v47; // w22
  __int64 *v48; // x9
  unsigned int v49; // w24
  unsigned int v50; // w25
  __int64 v51; // x0
  __int64 v52; // x26
  __int64 cmpt_obj; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x0
  unsigned int *v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int *v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double (__fastcall *v89)(_QWORD); // x8
  unsigned int nondfs_preferred_channel; // w21
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  const char *v107; // x2
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  _BYTE v116[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v117; // [xsp+8h] [xbp-8h]

  v117 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v116[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v24 = "%s: Invalid context";
    goto LABEL_8;
  }
  if ( !a3 )
  {
    v24 = "%s: CSA IE Received event is NULL";
    goto LABEL_8;
  }
  v15 = context;
  policy_mgr_get_dfs_sta_sap_go_scc_movement(a1, v116);
  if ( (v116[0] & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: g_move_sap_go_1st_on_dfs_sta_csa is disabled",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_sta_sap_dfs_scc_conc_check");
    result = 11;
    goto LABEL_10;
  }
  if ( (unsigned int)policy_mgr_get_mode_by_vdev_id(a1, a2) )
  {
    v24 = "%s: CSA received on non-STA connection";
LABEL_8:
    qdf_trace_msg(0x4Fu, 2u, v24, v7, v8, v9, v10, v11, v12, v13, v14, "policy_mgr_sta_sap_dfs_scc_conc_check");
    result = 4;
    goto LABEL_10;
  }
  v26 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( !v26 )
  {
    v24 = "%s: vdev is NULL";
    goto LABEL_8;
  }
  v27 = *(_QWORD *)(v26 + 216);
  v28 = v26;
  operation_chan_freq_vdev_id = wlan_get_operation_chan_freq_vdev_id(v27, a2);
  if ( (wlan_reg_is_dfs_for_freq(v27, operation_chan_freq_vdev_id, v30, v31, v32, v33, v34, v35, v36, v37) & 1) == 0
    && (wlan_reg_is_freq_indoor() & 1) == 0 )
  {
    v107 = "%s: SAP / GO operating channel is non-DFS";
LABEL_51:
    qdf_trace_msg(0x4Fu, 2u, v107, v38, v39, v40, v41, v42, v43, v44, v45, "policy_mgr_sta_sap_dfs_scc_conc_check");
LABEL_52:
    wlan_objmgr_vdev_release_ref(v28, 0x18u, (unsigned int *)v46, v38, v39, v40, v41, v42, v43, v44, v45);
    result = 4;
    goto LABEL_10;
  }
  v46 = (unsigned __int8)a2;
  if ( BYTE4(qword_8D4F00) != 1
    || HIDWORD(pm_conc_connection_list) != operation_chan_freq_vdev_id
    || (v47 = qword_8D4F00, (_DWORD)qword_8D4F00 == (_DWORD)v46)
    || (v48 = &pm_conc_connection_list, v49 = pm_conc_connection_list, ((unsigned int)pm_conc_connection_list | 2) != 3) )
  {
    if ( BYTE4(qword_8D4F24) != 1
      || HIDWORD(qword_8D4F0C) != operation_chan_freq_vdev_id
      || (v47 = qword_8D4F24, (_DWORD)qword_8D4F24 == (_DWORD)v46)
      || (v48 = &qword_8D4F0C, v49 = qword_8D4F0C, ((unsigned int)qword_8D4F0C | 2) != 3) )
    {
      if ( BYTE4(qword_8D4F48) != 1
        || HIDWORD(qword_8D4F30) != operation_chan_freq_vdev_id
        || (v47 = qword_8D4F48, (_DWORD)qword_8D4F48 == (_DWORD)v46)
        || (v48 = &qword_8D4F30, v49 = qword_8D4F30, ((unsigned int)qword_8D4F30 | 2) != 3) )
      {
        if ( BYTE4(qword_8D4F6C) != 1
          || HIDWORD(qword_8D4F54) != operation_chan_freq_vdev_id
          || (v47 = qword_8D4F6C, (_DWORD)qword_8D4F6C == (_DWORD)v46)
          || (v48 = &qword_8D4F54, v49 = qword_8D4F54, ((unsigned int)qword_8D4F54 | 2) != 3) )
        {
          if ( BYTE4(qword_8D4F90) != 1 )
            goto LABEL_52;
          if ( HIDWORD(qword_8D4F78) != operation_chan_freq_vdev_id )
            goto LABEL_52;
          v47 = qword_8D4F90;
          if ( (_DWORD)qword_8D4F90 == (_DWORD)v46 )
            goto LABEL_52;
          v48 = &qword_8D4F78;
          v49 = qword_8D4F78;
          v46 = (unsigned int)qword_8D4F78 | 2;
          if ( (_DWORD)v46 != 3 )
            goto LABEL_52;
        }
      }
    }
  }
  v50 = *((_DWORD *)v48 + 2);
  v51 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v47, 24);
  if ( !v51 )
  {
    v107 = "%s: conc_vdev is NULL";
    goto LABEL_51;
  }
  v52 = v51;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v51, v38, v39, v40, v41, v42, v43, v44, v45);
  if ( cmpt_obj )
    *(_BYTE *)(cmpt_obj + 197) = 1;
  v62 = wlan_vdev_mlme_get_cmpt_obj(v28, v54, v55, v56, v57, v58, v59, v60, v61);
  if ( v62 )
  {
    v63 = (_DWORD *)(&off_0 + 1);
    *(_BYTE *)(v62 + 197) = 1;
  }
  wlan_objmgr_vdev_release_ref(v52, 0x18u, v63, v64, v65, v66, v67, v68, v69, v70, v71);
  wlan_objmgr_vdev_release_ref(v28, 0x18u, v72, v73, v74, v75, v76, v77, v78, v79, v80);
  v89 = *(double (__fastcall **)(_QWORD))(v15 + 448);
  if ( v89 )
  {
    if ( *((_DWORD *)v89 - 1) != 2029277559 )
      __break(0x8228u);
    v81 = v89(4);
  }
  nondfs_preferred_channel = *(_DWORD *)(a3 + 4);
  if ( (wlan_reg_is_dfs_for_freq(v27, nondfs_preferred_channel, v81, v82, v83, v84, v85, v86, v87, v88) & 1) != 0
    || (wlan_reg_is_freq_indoor() & 1) != 0
    || (wlan_reg_is_freq_enabled(v27, nondfs_preferred_channel, v91, v92, v93, v94, v95, v96, v97, v98) & 1) == 0 )
  {
    if ( wlan_reg_is_24ghz_ch_freq(nondfs_preferred_channel) )
    {
      nondfs_preferred_channel = wlan_reg_min_24ghz_chan_freq();
    }
    else if ( wlan_reg_is_5ghz_ch_freq(nondfs_preferred_channel) )
    {
      nondfs_preferred_channel = wlan_reg_min_5ghz_chan_freq();
      if ( (wlan_reg_is_dfs_for_freq(v27, nondfs_preferred_channel, v108, v109, v110, v111, v112, v113, v114, v115) & 1) != 0
        || (wlan_reg_is_freq_indoor() & 1) != 0 )
      {
        nondfs_preferred_channel = policy_mgr_get_nondfs_preferred_channel(a1, v49, 1, v47);
      }
    }
    else
    {
      nondfs_preferred_channel = (unsigned __int16)wlan_reg_min_6ghz_chan_freq();
    }
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Restart vdev: %u on freq: %u",
    v99,
    v100,
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    "policy_mgr_sta_sap_dfs_scc_conc_check",
    (unsigned __int8)v47,
    nondfs_preferred_channel);
  result = policy_mgr_change_sap_channel_with_csa(a1, v47, nondfs_preferred_channel, v50, 1);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
