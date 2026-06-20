__int64 __fastcall bs_state_wlan_event(
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
  const char *v12; // x2
  __int64 v13; // x3
  const char *v14; // x2
  unsigned int v15; // w20
  unsigned int *v17; // x19
  __int64 v18; // x20
  unsigned int v19; // w21
  _DWORD **osif_cbk; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _DWORD *v29; // x8
  int v30; // w8
  __int64 *v31; // x8
  __int64 v32; // x8
  unsigned __int8 *v34; // x20
  __int64 v35; // x21
  unsigned int v36; // w22
  unsigned __int8 *v37; // x23
  _DWORD **v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _DWORD *v47; // x8
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v59; // w9
  unsigned int v60; // w9
  unsigned int v67; // w7
  unsigned int v69; // w7

  if ( !a12 )
  {
    v14 = "BS_SM request is null (via %s)";
LABEL_5:
    qdf_trace_msg(0xA1u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "bs_state_wlan_event");
    return 0;
  }
  if ( *a12 >= 6u )
  {
    v12 = "Invalid vdev id %d in BS_SM request";
    v13 = *a12;
LABEL_8:
    qdf_trace_msg(0xA1u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, v13);
    return 0;
  }
  v15 = *((_DWORD *)a12 + 3);
  if ( v15 >= 6 )
  {
    v12 = "Invalid source %d in BS_SM request";
    v13 = v15;
    goto LABEL_8;
  }
  if ( !a1 )
  {
    v14 = "BS_SM context is null (via %s)";
    goto LABEL_5;
  }
  if ( a2 == 1 )
  {
    if ( !*((_QWORD *)a12 + 2) )
    {
      qdf_trace_msg(
        0xA1u,
        2u,
        "%s: BS_SM_%d req_id 0x%x: NULL cbk, req_vdev %d src %d arg val %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "ll_lt_sap_handle_bs_to_non_wlan_in_wlan_state",
        *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
        *((unsigned int *)a12 + 1),
        *((_DWORD *)a12 + 6));
      return 1;
    }
    v17 = a1;
    if ( v15 == 5 )
    {
      v18 = *(_QWORD *)a1;
      v19 = *((_DWORD *)a12 + 2);
      osif_cbk = (_DWORD **)ll_sap_get_osif_cbk(a1);
      if ( osif_cbk )
      {
        v29 = *osif_cbk;
        if ( *osif_cbk )
        {
          if ( *(v29 - 1) != 1824459834 )
            __break(0x8228u);
          v21 = ((double (__fastcall *)(__int64, _QWORD, __int64))v29)(v18, v19, 5);
        }
      }
      wlan_sm_transition_to(*((_QWORD *)v17 + 10), 0, v21, v22, v23, v24, v25, v26, v27, v28);
      return 1;
    }
    v30 = *((_DWORD *)a12 + 1);
    if ( *((_QWORD *)a1 + 34) && a1[65] == v30 )
    {
      v31 = (__int64 *)(a1 + 64);
    }
    else if ( *((_QWORD *)a1 + 39) && a1[75] == v30 )
    {
      v31 = (__int64 *)(a1 + 74);
    }
    else if ( *((_QWORD *)a1 + 44) && a1[85] == v30 )
    {
      v31 = (__int64 *)(a1 + 84);
    }
    else if ( *((_QWORD *)a1 + 49) && a1[95] == v30 )
    {
      v31 = (__int64 *)(a1 + 94);
    }
    else
    {
      if ( !*((_QWORD *)a1 + 54) || a1[105] != v30 )
      {
        while ( 1 )
        {
LABEL_55:
          _X8 = a1 + 61;
          __asm { PRFM            #0x11, [X8] }
          do
          {
            v59 = __ldxr(_X8);
            v60 = v59 + 1;
          }
          while ( __stlxr(v60, _X8) );
          __dmb(0xBu);
          v32 = *((unsigned int *)a12 + 3);
          if ( (_DWORD)v32 == 2 )
          {
            _X8 = a1 + 60;
            __asm { PRFM            #0x11, [X8] }
            do
              v67 = __ldxr(_X8);
            while ( __stlxr(v67 + 1, _X8) );
            goto LABEL_59;
          }
          if ( (unsigned int)v32 <= 6 && *a12 < 6u )
            break;
          __break(0x5512u);
        }
        _X8 = &a1[6 * *a12 + 24 + v32];
        __asm { PRFM            #0x11, [X8] }
        do
          v69 = __ldxr(_X8);
        while ( __stlxr(v69 + 1, _X8) );
LABEL_59:
        __dmb(0xBu);
        v34 = a12;
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
          *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
          *((unsigned int *)a12 + 1),
          *a12,
          *((unsigned int *)a12 + 3),
          v60);
        ll_lt_sap_cache_bs_request(v17, v34);
        a12 = v34;
        v15 = *((_DWORD *)v34 + 3);
        a1 = v17;
        goto LABEL_46;
      }
      v31 = (__int64 *)(a1 + 104);
    }
    if ( !v31 )
      goto LABEL_55;
LABEL_46:
    v35 = *(_QWORD *)a1;
    v36 = *((_DWORD *)a12 + 2);
    v37 = a12;
    v38 = (_DWORD **)ll_sap_get_osif_cbk(a1);
    if ( v38 )
    {
      v47 = *v38;
      if ( *v38 )
      {
        if ( *(v47 - 1) != 1824459834 )
          __break(0x8228u);
        v39 = ((double (__fastcall *)(__int64, _QWORD, _QWORD))v47)(v35, v36, v15);
      }
    }
    v48 = *((_QWORD *)v17 + 10);
    *((_BYTE *)v17 + 92) = 1;
    wlan_sm_transition_to(v48, 1u, v39, v40, v41, v42, v43, v44, v45, v46);
    if ( (unsigned int)qdf_mc_timer_start((__int64)(v17 + 114), 0x1388u) )
      qdf_trace_msg(
        0xA1u,
        2u,
        "%s: BS_SM_%d req_id 0x%x: Failed to start timer",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "ll_lt_sap_handle_bs_to_non_wlan_in_wlan_state",
        *(unsigned __int8 *)(*(_QWORD *)v17 + 168LL),
        *((unsigned int *)v37 + 1));
    return 1;
  }
  if ( a2 )
    return 0;
  ll_lt_sap_invoke_req_callback_f(a1, a12, 6, "ll_lt_sap_handle_bs_to_wlan_in_wlan_state");
  return 1;
}
