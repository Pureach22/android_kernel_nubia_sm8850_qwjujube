__int64 __fastcall ucfg_nan_discovery_req(
        __int64 *a1,
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
  __int64 v10; // x19
  __int64 *v11; // x20
  int v12; // w23
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  __int64 v32; // x0
  unsigned int ref; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w8
  __int64 v52; // x9
  __int64 comp_private_obj; // x0
  unsigned int v54; // w21
  void *v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x20
  unsigned int v74; // w19
  unsigned int v75; // w20
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int v84; // w21
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int v93; // w24
  unsigned int v94; // w23
  char driver_state; // w21
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  unsigned int v104; // w0
  __int64 v105; // x6
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  __int64 v130; // [xsp+8h] [xbp-38h] BYREF
  void *v131; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v132)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v133)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v134; // [xsp+28h] [xbp-18h]
  __int64 v135; // [xsp+30h] [xbp-10h]
  __int64 v136; // [xsp+38h] [xbp-8h]

  v136 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v134 = 0;
  v135 = 0;
  v132 = nullptr;
  v133 = nullptr;
  v130 = 0;
  v131 = nullptr;
  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 1u, "%s: NAN Discovery req is null", a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_nan_discovery_req");
    result = 29;
    goto LABEL_29;
  }
  if ( !a2 )
  {
    v10 = *a1;
    if ( *a1 )
    {
      v11 = a1;
      v12 = 0;
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*a1, 0xFu);
      if ( comp_private_obj )
      {
        v22 = comp_private_obj;
        ref = wlan_objmgr_psoc_try_get_ref(v10, 0x14u, v14, v15, v16, v17, v18, v19, v20, v21);
        if ( ref )
          goto LABEL_28;
        v51 = 24;
        v52 = 8;
        goto LABEL_19;
      }
      goto LABEL_25;
    }
LABEL_24:
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_psoc_priv_obj");
    goto LABEL_25;
  }
  if ( a2 == 2 )
  {
    v10 = *a1;
    if ( *a1 )
    {
      v11 = a1;
      v12 = 2;
      v32 = wlan_objmgr_psoc_get_comp_private_obj(*a1, 0xFu);
      if ( v32 )
      {
        v22 = v32;
        ref = wlan_objmgr_psoc_try_get_ref(v10, 0x14u, v14, v15, v16, v17, v18, v19, v20, v21);
        if ( ref )
          goto LABEL_28;
        v42 = nan_set_discovery_state(*v11, 3, v34, v35, v36, v37, v38, v39, v40, v41);
        if ( v42 )
          goto LABEL_32;
        v51 = 24;
        v52 = 12;
        goto LABEL_19;
      }
LABEL_25:
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: nan psoc priv object is NULL",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "ucfg_nan_discovery_req");
      result = 4;
      goto LABEL_29;
    }
    goto LABEL_24;
  }
  if ( a2 != 1 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: in correct message req type: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_nan_discovery_req",
      a2);
    result = 4;
    goto LABEL_29;
  }
  v10 = *a1;
  if ( !*a1 )
    goto LABEL_24;
  v11 = a1;
  v12 = 1;
  v13 = wlan_objmgr_psoc_get_comp_private_obj(*a1, 0xFu);
  if ( !v13 )
    goto LABEL_25;
  v22 = v13;
  if ( (policy_mgr_is_sta_mon_concurrency(v10) & 1) != 0 )
  {
    result = 4;
    goto LABEL_29;
  }
  ref = wlan_objmgr_psoc_try_get_ref(v10, 0x14u, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( ref )
  {
LABEL_28:
    v74 = ref;
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Couldn't obtain psoc ref",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "ucfg_nan_discovery_req");
    result = v74;
    goto LABEL_29;
  }
  v42 = nan_discovery_pre_enable(v11[2], *((_DWORD *)v11 + 2), v34, v35, v36, v37, v38, v39, v40, v41);
  if ( v42 )
  {
LABEL_32:
    v75 = v42;
    wlan_objmgr_psoc_release_ref(v10, 0x14u, v43, v44, v45, v46, v47, v48, v49, v50);
    result = v75;
    goto LABEL_29;
  }
  v51 = 40;
  v52 = 24;
LABEL_19:
  v54 = v51 + *(unsigned __int16 *)((char *)v11 + v52);
  v55 = (void *)_qdf_mem_malloc(v54, "ucfg_nan_discovery_req", 838);
  v131 = v55;
  if ( !v55 )
  {
    wlan_objmgr_psoc_release_ref(v10, 0x14u, v56, v57, v58, v59, v60, v61, v62, v63);
    result = 2;
    goto LABEL_29;
  }
  qdf_mem_copy(v55, v11, v54);
  LOWORD(v130) = v12;
  v132 = nan_discovery_scheduled_handler;
  v133 = nan_discovery_flush_callback;
  if ( v12 )
  {
    v64 = osif_request_alloc(ucfg_nan_discovery_req_params);
    if ( !v64 )
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: Request allocation failure",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "ucfg_nan_discovery_req");
      nan_discovery_flush_callback((unsigned __int16 *)&v130, v122, v123, v124, v125, v126, v127, v128, v129);
      result = 2;
      goto LABEL_29;
    }
    v73 = v64;
    *(_QWORD *)(v22 + 296) = osif_request_cookie(v64);
    if ( v12 == 2 )
      *(_BYTE *)(v22 + 285) = 1;
  }
  else
  {
    v73 = 0;
  }
  result = scheduler_post_message_debug(
             0x53u,
             0x53u,
             72,
             (unsigned __int16 *)&v130,
             0x362u,
             (__int64)"ucfg_nan_discovery_req");
  if ( (_DWORD)result )
  {
    v84 = result;
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: failed to post msg to NAN component, status: %d",
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      "ucfg_nan_discovery_req",
      (unsigned int)result);
    nan_discovery_flush_callback((unsigned __int16 *)&v130, v85, v86, v87, v88, v89, v90, v91, v92);
    result = v84;
  }
  if ( v12 )
  {
    v93 = v12;
    v94 = result;
    driver_state = cds_get_driver_state(v76, v77, v78, v79, v80, v81, v82, v83);
    if ( (driver_state & 8) != 0 )
    {
      v105 = 0;
    }
    else
    {
      v104 = osif_request_wait_for_response(v73);
      v105 = v104;
      if ( !v104 )
      {
        if ( v93 != 2 )
          goto LABEL_50;
        goto LABEL_49;
      }
    }
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: NAN request: %u recovery %d or timed out %d",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "ucfg_nan_discovery_req",
      v93,
      (unsigned __int8)(driver_state & 8) >> 3,
      v105);
    if ( v93 != 2 )
    {
      nan_set_discovery_state(v10, 0, v106, v107, v108, v109, v110, v111, v112, v113);
      if ( (ucfg_is_nan_dbs_supported(v10, v114, v115, v116, v117, v118, v119, v120, v121) & 1) != 0 )
        policy_mgr_check_n_start_opportunistic_timer(v10);
      nan_handle_emlsr_concurrency();
      ucfg_tdls_notify_connect_failure(v10);
      goto LABEL_50;
    }
    nan_disable_cleanup(v10, v106, v107, v108, v109, v110, v111, v112, v113);
LABEL_49:
    *(_BYTE *)(v22 + 285) = 0;
LABEL_50:
    osif_request_put(v73);
    result = v94;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
