__int64 __fastcall hdd_init_nan_data_mode(__int64 a1)
{
  __int64 *v2; // x21
  unsigned int v3; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  __int64 result; // x0
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 vdev_by_user; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x20
  unsigned int v51; // w0
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
  unsigned int v77; // w0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int rts_profile; // w0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int v95; // w21
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  __int64 v113; // x19
  unsigned int *v114; // x8
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  unsigned int *v123; // x8
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  unsigned __int64 v138; // x9
  unsigned __int16 v139; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v140[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v141[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v142; // [xsp+18h] [xbp-8h]

  v142 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 **)(a1 + 24);
  v141[0] = 0;
  v140[0] = 0;
  v139 = 0;
  v3 = hdd_adapter_check_duplicate_session(a1);
  if ( v3 )
  {
    v12 = v3;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Duplicate session is existing with same mac address",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_init_nan_data_mode");
    result = qdf_status_to_os_return(v12);
    goto LABEL_24;
  }
  v14 = hdd_vdev_create(*(_QWORD *)(a1 + 52824), v4, v5, v6, v7, v8, v9, v10, v11);
  if ( v14 )
  {
    v23 = v14;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to create vdev: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_init_nan_data_mode",
      v14);
    result = v23;
    goto LABEL_24;
  }
  v24 = v2[2];
  if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*v2, v141) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: unable to get vht_enable2x2",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_init_nan_data_mode");
  sme_set_pdev_ht_vht_ies(v24, v141[0] != 0);
  sme_set_vdev_ies_per_band(v24, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), *(_DWORD *)(a1 + 40));
  hdd_roam_profile_init(*(__int64 **)(a1 + 52824), v33, v34, v35, v36, v37, v38, v39, v40);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52824), 0x61u, (__int64)"hdd_init_nan_data_mode");
  if ( !vdev_by_user )
  {
LABEL_10:
    hdd_vdev_destroy(*(_QWORD *)(a1 + 52824), v42, v43, v44, v45, v46, v47, v48, v49);
    result = 4294967285LL;
    goto LABEL_24;
  }
  v50 = vdev_by_user;
  v51 = hdd_wmm_adapter_init(a1, v42, v43, v44, v45, v46, v47, v48, v49);
  if ( v51 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: hdd_wmm_adapter_init() failed, status %d",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "hdd_init_nan_data_mode",
      v51);
    _hdd_objmgr_put_vdev_by_user(
      v50,
      0x61u,
      (__int64)"hdd_init_nan_data_mode",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68);
    goto LABEL_10;
  }
  _X8 = (unsigned __int64 *)(a1 + 1624);
  __asm { PRFM            #0x11, [X8] }
  do
    v138 = __ldxr(_X8);
  while ( __stxr(v138 | 2, _X8) );
  if ( (unsigned int)ucfg_get_enable_sifs_burst(*v2, v140) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get sifs burst value, use default",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "hdd_init_nan_data_mode");
  v77 = wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 48, v140[0], 2);
  if ( v77 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wmi_pdev_param_burst_enable set failed %d",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "hdd_init_nan_data_mode",
      v77);
  rts_profile = ucfg_fwol_get_rts_profile(*v2, &v139);
  if ( rts_profile )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: FAILED TO GET RTSCTS Profile status:%d",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "hdd_init_nan_data_mode",
      rts_profile);
  v95 = sme_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 44, v139, 1);
  if ( v95 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: FAILED TO SET RTSCTS Profile ret:%d",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "hdd_init_nan_data_mode",
      v95);
  hdd_set_netdev_flags(a1, v96, v97, v98, v99, v100, v101, v102, v103);
  hdd_tsf_auto_report_init(a1);
  v104 = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52824), 0x52u, (__int64)"update_ndi_state");
  if ( v104 )
  {
    v113 = v104;
    _ucfg_nan_set_ndi_state(v104, 0, (__int64)"os_if_nan_set_ndi_state", v105, v106, v107, v108, v109, v110, v111, v112);
    _hdd_objmgr_put_vdev_by_user(
      v113,
      0x52u,
      (__int64)"update_ndi_state",
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122);
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v105, v106, v107, v108, v109, v110, v111, v112, "update_ndi_state");
  }
  _hdd_objmgr_put_vdev_by_user(
    v50,
    0x61u,
    (__int64)"hdd_init_nan_data_mode",
    v123,
    v124,
    v125,
    v126,
    v127,
    v128,
    v129,
    v130,
    v131);
  result = v95;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
