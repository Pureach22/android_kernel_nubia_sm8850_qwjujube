__int64 __fastcall hdd_init_nan_data_mode(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v10; // x21
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w20
  const char *v21; // x2
  unsigned int v22; // w1
  unsigned int v23; // w0
  __int64 result; // x0
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w19
  __int64 v35; // x20
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 vdev_by_user; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x20
  unsigned int v62; // w0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int *v71; // x8
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
  unsigned int v88; // w0
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned int rts_profile; // w0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int v106; // w21
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double updated; // d0
  unsigned int *v117; // x8
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  unsigned __int64 v131; // x9
  unsigned __int16 v132; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v133[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v134[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v135; // [xsp+18h] [xbp-8h]

  v135 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)(a1 + 24);
  v134[0] = 0;
  v133[0] = 0;
  v132 = 0;
  v11 = hdd_adapter_fill_link_address(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( v11 )
  {
    v20 = v11;
    v21 = "%s: Link address derive failed";
    v22 = 8;
LABEL_5:
    qdf_trace_msg(0x33u, v22, v21, v12, v13, v14, v15, v16, v17, v18, v19, "hdd_init_nan_data_mode");
    result = qdf_status_to_os_return(v20);
    goto LABEL_6;
  }
  v23 = hdd_adapter_check_duplicate_session(a1);
  if ( v23 )
  {
    v20 = v23;
    v21 = "%s: Duplicate session is existing with same mac address";
    v22 = 2;
    goto LABEL_5;
  }
  v25 = hdd_vdev_create(*(_QWORD *)(a1 + 52832), v12, v13, v14, v15, v16, v17, v18, v19);
  if ( v25 )
  {
    v34 = v25;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to create vdev: %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_init_nan_data_mode",
      v25);
    result = v34;
    goto LABEL_6;
  }
  v35 = v10[2];
  if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*v10, v134) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: unable to get vht_enable2x2",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "hdd_init_nan_data_mode");
  sme_set_pdev_ht_vht_ies(v35, v134[0] != 0);
  sme_set_vdev_ies_per_band(v35, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), *(_DWORD *)(a1 + 40));
  hdd_roam_profile_init(*(__int64 **)(a1 + 52832), v44, v45, v46, v47, v48, v49, v50, v51);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x61u, (__int64)"hdd_init_nan_data_mode");
  if ( !vdev_by_user )
  {
LABEL_14:
    hdd_vdev_destroy(*(_QWORD *)(a1 + 52832), v53, v54, v55, v56, v57, v58, v59, v60);
    result = 4294967285LL;
    goto LABEL_6;
  }
  v61 = vdev_by_user;
  v62 = hdd_wmm_adapter_init(a1, v53, v54, v55, v56, v57, v58, v59, v60);
  if ( v62 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: hdd_wmm_adapter_init() failed, status %d",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "hdd_init_nan_data_mode",
      v62);
    _hdd_objmgr_put_vdev_by_user(
      v61,
      0x61u,
      (__int64)"hdd_init_nan_data_mode",
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79);
    goto LABEL_14;
  }
  _X8 = (unsigned __int64 *)(a1 + 1624);
  __asm { PRFM            #0x11, [X8] }
  do
    v131 = __ldxr(_X8);
  while ( __stxr(v131 | 2, _X8) );
  if ( (unsigned int)ucfg_get_enable_sifs_burst(*v10, v133) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get sifs burst value, use default",
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      "hdd_init_nan_data_mode");
  v88 = wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), 48, v133[0], 2);
  if ( v88 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wmi_pdev_param_burst_enable set failed %d",
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      "hdd_init_nan_data_mode",
      v88);
  rts_profile = ucfg_fwol_get_rts_profile(*v10, &v132);
  if ( rts_profile )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: FAILED TO GET RTSCTS Profile status:%d",
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      "hdd_init_nan_data_mode",
      rts_profile);
  v106 = sme_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), 44, v132, 1);
  if ( v106 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: FAILED TO SET RTSCTS Profile ret:%d",
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      "hdd_init_nan_data_mode",
      v106);
  hdd_set_netdev_flags(a1, v107, v108, v109, v110, v111, v112, v113, v114);
  v115 = hdd_tsf_auto_report_init(a1);
  updated = update_ndi_state(a1, v115);
  _hdd_objmgr_put_vdev_by_user(
    v61,
    0x61u,
    (__int64)"hdd_init_nan_data_mode",
    v117,
    updated,
    v118,
    v119,
    v120,
    v121,
    v122,
    v123,
    v124);
  result = v106;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
