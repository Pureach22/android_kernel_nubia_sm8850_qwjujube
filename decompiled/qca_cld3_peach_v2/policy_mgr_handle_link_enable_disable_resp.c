__int64 __fastcall policy_mgr_handle_link_enable_disable_resp(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x20
  unsigned int v14; // w24
  __int64 context; // x0
  __int64 v18; // x25
  __int64 v19; // x22
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  bool v36; // zf
  int v37; // w24
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x4
  const char *v41; // x2
  unsigned int v42; // w1
  __int64 result; // x0
  char is_nlink_service_supported; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x1
  _BOOL4 v54; // w23
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w4
  int v64; // w8
  _BOOL4 v65; // w9
  _QWORD v66[4]; // [xsp+20h] [xbp-20h] BYREF

  v66[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 216);
  memset(v66, 0, 24);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v41 = "%s: Psoc is Null";
LABEL_17:
    v42 = 2;
LABEL_18:
    result = qdf_trace_msg(
               0x4Fu,
               v42,
               v41,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "policy_mgr_handle_link_enable_disable_resp");
    goto LABEL_19;
  }
  v14 = *(unsigned __int8 *)(a1 + 168);
  context = policy_mgr_get_context(*(_QWORD *)(v11 + 80));
  if ( !context )
  {
    v41 = "%s: Invalid Context";
    goto LABEL_17;
  }
  v18 = *(_QWORD *)(a1 + 216);
  if ( !v18 )
  {
    v41 = "%s: Pdev is NULL";
    v42 = 8;
    goto LABEL_18;
  }
  v19 = context;
  if ( (ucfg_mlme_check_bit_in_rso_disabled_bitmap(v12, v14, 64) & 1) != 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: enable roaming for RSO_SET_LINK",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "policy_mgr_handle_link_enable_disable_resp");
    wlan_cm_enable_rso(v18, v14, 64, 43);
  }
  qdf_mutex_acquire(v19 + 56);
  if ( a2 )
    v36 = a3 == nullptr;
  else
    v36 = 1;
  v37 = !v36;
  if ( v36 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: arguments or event empty for vdev %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "policy_mgr_handle_link_enable_disable_resp",
      *(unsigned __int8 *)(a1 + 168));
    goto LABEL_23;
  }
  v38 = *(unsigned int *)(a2 + 32);
  v39 = *(unsigned int *)(a2 + 36);
  v40 = *a3;
  if ( (_DWORD)v40 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Set link status %d, for mode %d reason %d vdev bitmask 0x%x",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "policy_mgr_handle_link_enable_disable_resp",
      v40,
      v38,
      v39,
      *(unsigned int *)(a2 + 84));
    goto LABEL_23;
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Req mode %d reason %d loop %d bitmask[0] = 0x%x, resp: active %d inactive %d, active[0] 0x%x inactive[0] 0x%x",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "policy_mgr_handle_link_enable_disable_resp",
    (unsigned int)v38,
    (unsigned int)v39,
    *(unsigned __int8 *)(a2 + 104),
    *(unsigned int *)(a2 + 84),
    a3[2],
    a3[5],
    a3[3],
    a3[6]);
  v63 = *(_DWORD *)(a2 + 32);
  if ( v63 <= 3 )
  {
    switch ( v63 )
    {
      case 1:
        policy_mgr_handle_force_active_resp(v12, a1, a2, a3);
        goto LABEL_60;
      case 2:
        policy_mgr_handle_force_inactive_resp(v12, a1, a2, a3);
        goto LABEL_60;
      case 3:
        policy_mgr_handle_force_active_num_resp(v12, a1, a2, a3);
        goto LABEL_60;
    }
LABEL_43:
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid request req mode %d",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "policy_mgr_handle_link_enable_disable_resp");
    goto LABEL_60;
  }
  if ( v63 > 5 )
  {
    if ( v63 == 6 )
    {
      policy_mgr_handle_force_active_inactive_resp(v12, a1, a2, a3);
      goto LABEL_60;
    }
    if ( v63 == 7 )
      goto LABEL_60;
    goto LABEL_43;
  }
  if ( v63 == 4 )
    policy_mgr_handle_force_inactive_num_resp(v12, a1, a2, a3);
  else
    policy_mgr_handle_no_force_resp(v12, a1, a2, a3);
LABEL_60:
  if ( *(_DWORD *)(a2 + 36) == 3 )
    policy_mgr_trigger_roam_on_link_removal(a1);
LABEL_23:
  policy_mgr_set_link_in_progress(v19, 0);
  is_nlink_service_supported = ml_is_nlink_service_supported(v12);
  if ( !a3 || !a2 || (is_nlink_service_supported & 1) == 0 )
  {
    result = qdf_mutex_release(v19 + 56);
    if ( !a2 )
      goto LABEL_19;
    v54 = 1;
    if ( (*(_BYTE *)(a2 + 105) & 1) != 0 )
      goto LABEL_48;
    goto LABEL_47;
  }
  if ( !*a3 && *(_BYTE *)(a2 + 103) == 1 )
  {
    if ( *(unsigned __int8 *)(a2 + 104) <= 2u )
    {
      qdf_mem_set(v66, 0x18u, 0);
      v53 = *(unsigned __int8 *)(a1 + 168);
      ++LOBYTE(v66[0]);
      v54 = ml_nlink_conn_change_notify(v12, v53, 19, v66) == 0;
      goto LABEL_46;
    }
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: unexpected post_re_evaluate_loops %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "policy_mgr_handle_link_enable_disable_resp");
  }
  v54 = 1;
LABEL_46:
  result = qdf_mutex_release(v19 + 56);
  if ( (*(_BYTE *)(a2 + 105) & 1) != 0 )
    goto LABEL_48;
LABEL_47:
  if ( *(_DWORD *)(a2 + 32) == 7 )
  {
LABEL_48:
    v64 = 0;
    if ( !v37 )
      goto LABEL_19;
    goto LABEL_51;
  }
  v64 = 1;
  if ( !v37 )
    goto LABEL_19;
LABEL_51:
  if ( *a3 )
    v65 = 0;
  else
    v65 = v54;
  if ( (v64 & v65) == 1 )
    result = policy_mgr_check_concurrent_intf_and_restart_sap(v12, 0);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
