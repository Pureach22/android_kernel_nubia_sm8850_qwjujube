__int64 __fastcall bs_state_non_wlan_event(
        unsigned int *a1,
        __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        unsigned __int8 *a12)
{
  __int64 v12; // x8
  unsigned int v13; // w19
  __int64 v14; // x20
  int v15; // w8
  __int64 *v16; // x8
  unsigned int v17; // w8
  const char *v18; // x2
  const char *v19; // x2
  __int64 v21; // x0
  unsigned __int8 v22; // w1
  __int64 v23; // x8
  unsigned int *v27; // x19
  unsigned int v28; // w20
  unsigned int *v29; // x23
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  unsigned int v39; // w21
  unsigned int v40; // w22
  __int64 v41; // x20
  _DWORD **osif_cbk; // x0
  _DWORD *v43; // x8
  unsigned __int8 *v44; // x23
  __int64 *v45; // x21
  int v46; // w22
  _BOOL4 is_cur_cu_greater_than_th; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 *v56; // x0
  unsigned __int8 *v57; // x1
  __int64 v58; // x2
  __int64 *v59; // x20
  unsigned int v60; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w19
  unsigned int v72; // w9
  unsigned int v73; // w9
  unsigned int v80; // w7
  unsigned int v82; // w7

  if ( a2 != 4 )
  {
    if ( !a12 )
    {
      v19 = "BS_SM request is null (via %s)";
      goto LABEL_16;
    }
    v17 = *a12;
    if ( v17 < 6 )
    {
      v17 = *((_DWORD *)a12 + 3);
      if ( v17 < 6 )
        goto LABEL_2;
      v18 = "Invalid source %d in BS_SM request";
    }
    else
    {
      v18 = "Invalid vdev id %d in BS_SM request";
    }
    qdf_trace_msg(0xA1u, 2u, v18, a3, a4, a5, a6, a7, a8, a9, a10, v17);
    return 0;
  }
LABEL_2:
  if ( !a1 )
  {
    v19 = "BS_SM context is null (via %s)";
LABEL_16:
    qdf_trace_msg(0xA1u, 2u, v19, a3, a4, a5, a6, a7, a8, a9, a10, "bs_state_non_wlan_event");
    return 0;
  }
  if ( a2 == 4 )
  {
    v21 = *((_QWORD *)a1 + 10);
    v22 = 3;
    goto LABEL_46;
  }
  if ( a2 == 1 )
  {
    if ( *((_DWORD *)a12 + 3) == 5 )
    {
      qdf_trace_msg(
        0xA1u,
        8u,
        "%s: Bearer is already non-wlan",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "ll_lt_sap_handle_bs_to_non_wlan_in_non_wlan_state");
      return 1;
    }
    while ( 1 )
    {
      _X8 = a1 + 61;
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v72 = __ldxr(_X8);
        v73 = v72 + 1;
      }
      while ( __stlxr(v73, _X8) );
      __dmb(0xBu);
      v23 = *((unsigned int *)a12 + 3);
      if ( (_DWORD)v23 == 2 )
      {
        _X8 = a1 + 60;
        __asm { PRFM            #0x11, [X8] }
        do
          v80 = __ldxr(_X8);
        while ( __stlxr(v80 + 1, _X8) );
        goto LABEL_78;
      }
      if ( (unsigned int)v23 <= 6 && *a12 < 6u )
        break;
      __break(0x5512u);
    }
    _X8 = &a1[6 * *a12 + 24 + v23];
    __asm { PRFM            #0x11, [X8] }
    do
      v82 = __ldxr(_X8);
    while ( __stlxr(v82 + 1, _X8) );
LABEL_78:
    __dmb(0xBu);
    qdf_trace_msg(
      0xA1u,
      8u,
      "BS_SM_%d req_id 0x%x: vdev %d src %d count %d Total req count %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL),
      *((unsigned int *)a12 + 1),
      *a12,
      *((unsigned int *)a12 + 3),
      v73);
    v27 = (unsigned int *)a12;
    v28 = *((_DWORD *)a12 + 1);
    v29 = a1;
    if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(a1 + 156)) == 21
      && (unsigned int)qdf_mc_timer_stop((__int64)(a1 + 156)) )
    {
      qdf_trace_msg(
        0xA1u,
        2u,
        "%s: BS_SM_%d req_id 0x%x: failed to stop timer",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "ll_lt_sap_stop_bs_wlan_req_timer",
        *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL),
        v28);
    }
    ll_lt_sap_flush_bs_wlan_req(a1);
    if ( !a1[62] )
    {
      ll_lt_sap_invoke_req_callback_f(a1, v27, 6, "ll_lt_sap_handle_bs_to_non_wlan_in_non_wlan_state");
      return 1;
    }
    v38 = ll_lt_sap_cache_bs_request(a1, v27);
    v39 = v27[2];
    v40 = v27[3];
    v41 = *(_QWORD *)v29;
    osif_cbk = (_DWORD **)ll_sap_get_osif_cbk(v38);
    if ( osif_cbk )
    {
      v43 = *osif_cbk;
      if ( *osif_cbk )
      {
        if ( *(v43 - 1) != 1824459834 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD))v43)(v41, v39, v40);
      }
    }
    *((_BYTE *)v29 + 92) = 1;
    if ( (unsigned int)qdf_mc_timer_start((__int64)(v29 + 114), 0x1388u) )
      qdf_trace_msg(
        0xA1u,
        2u,
        "%s: BS_SM_%d req_id 0x%x: Failed to start timer",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "ll_lt_sap_handle_bs_to_non_wlan_in_non_wlan_state",
        *(unsigned __int8 *)(*(_QWORD *)v29 + 104LL),
        v27[1]);
    v21 = *((_QWORD *)v29 + 10);
    v22 = 1;
LABEL_46:
    wlan_sm_transition_to(v21, v22, a3, a4, a5, a6, a7, a8, a9, a10);
    return 1;
  }
  if ( a2 )
    return 0;
  v12 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  v13 = *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL);
  if ( !v12 || (v14 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: BS_SM_%d req_id 0x%x: PSOC is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ll_lt_sap_handle_bs_to_wlan_in_non_wlan_state",
      *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL),
      *((unsigned int *)a12 + 1));
    return 1;
  }
  v15 = *((_DWORD *)a12 + 1);
  if ( *((_QWORD *)a1 + 34) && a1[65] == v15 )
  {
    v16 = (__int64 *)(a1 + 64);
    goto LABEL_58;
  }
  if ( *((_QWORD *)a1 + 39) && a1[75] == v15 )
  {
    v16 = (__int64 *)(a1 + 74);
    goto LABEL_58;
  }
  if ( *((_QWORD *)a1 + 44) && a1[85] == v15 )
  {
    v16 = (__int64 *)(a1 + 84);
    goto LABEL_58;
  }
  if ( *((_QWORD *)a1 + 49) && a1[95] == v15 )
  {
    v16 = (__int64 *)(a1 + 94);
    goto LABEL_58;
  }
  if ( *((_QWORD *)a1 + 54) && a1[105] == v15 )
  {
    v16 = (__int64 *)(a1 + 104);
LABEL_58:
    if ( v16 )
    {
      v44 = a12;
      v45 = (__int64 *)a1;
      v46 = 1;
      goto LABEL_62;
    }
  }
  v45 = (__int64 *)a1;
  v44 = a12;
  if ( !(unsigned int)ll_lt_sap_bs_decreament_ref_count() )
  {
    v46 = 0;
LABEL_62:
    is_cur_cu_greater_than_th = wlan_ll_sap_is_cur_cu_greater_than_th(v14, v13);
    if ( *((_BYTE *)v45 + 92) == 1 && ((v46 | !is_cur_cu_greater_than_th) & 1) != 0 )
    {
      v56 = v45;
      v57 = v44;
      if ( *((_DWORD *)v45 + 61) )
      {
        v58 = 0;
      }
      else
      {
        if ( (v46 & 1) == 0 )
        {
          ll_lt_sap_cache_bs_request(v45, v44);
          v56 = v45;
        }
        v59 = v56;
        v60 = qdf_mc_timer_start((__int64)(v56 + 78), 0x1388u);
        if ( v60 )
        {
          v69 = v60;
          qdf_trace_msg(
            0xA1u,
            2u,
            "%s: BS_SM_%d req_id 0x%x: Failed to start timer",
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            "ll_lt_sap_handle_bs_to_wlan_in_non_wlan_state",
            *(unsigned __int8 *)(*v59 + 104),
            *((unsigned int *)v44 + 1));
          ll_lt_sap_continue_bs_to_wlan(v59);
          v58 = v69;
          v57 = v44;
          v56 = v59;
        }
        else
        {
          v58 = 0;
          v56 = v59;
          v57 = v44;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0xA1u,
        8u,
        "%s: BS_SM_%d req_id 0x%x:  Non wlan requested %d or cu_greater_than_th %d (cached %d), don't switch to wlan",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "ll_lt_sap_handle_bs_to_wlan_in_non_wlan_state",
        v13,
        *((unsigned int *)v44 + 1),
        v46);
      v57 = v44;
      v58 = 0;
      v56 = v45;
    }
    ll_lt_sap_invoke_req_callback_f(v56, v57, v58, "ll_lt_sap_handle_bs_to_wlan_in_non_wlan_state");
  }
  return 1;
}
