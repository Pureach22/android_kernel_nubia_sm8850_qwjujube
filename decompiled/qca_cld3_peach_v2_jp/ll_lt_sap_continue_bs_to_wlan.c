__int64 __fastcall ll_lt_sap_continue_bs_to_wlan(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int *v11; // x23
  const char *v12; // x2
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  __int64 v22; // x20
  unsigned int v23; // w21
  _DWORD **osif_cbk; // x0
  _DWORD *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  if ( *((_DWORD *)a1 + 61) )
    return ll_lt_sap_flush_bs_wlan_req(a1);
  if ( a1[34] && *((_DWORD *)a1 + 66) == 1 )
  {
    v11 = (unsigned int *)(a1 + 32);
    if ( a1 == (__int64 *)-256LL )
    {
LABEL_24:
      qdf_trace_msg(
        0xA1u,
        2u,
        "BS_SM request is null (via %s)",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "ll_lt_sap_continue_bs_to_wlan");
      return qdf_trace_msg(
               0xA1u,
               2u,
               "%s: BS_SM vdev %d Invalid total ref count %d",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "ll_lt_sap_continue_bs_to_wlan",
               *(unsigned __int8 *)(*a1 + 104),
               *((unsigned int *)a1 + 61));
    }
  }
  else if ( a1[39] && *((_DWORD *)a1 + 76) == 1 )
  {
    v11 = (unsigned int *)(a1 + 37);
    if ( a1 == (__int64 *)-296LL )
      goto LABEL_24;
  }
  else if ( a1[44] && *((_DWORD *)a1 + 86) == 1 )
  {
    v11 = (unsigned int *)(a1 + 42);
    if ( a1 == (__int64 *)-336LL )
      goto LABEL_24;
  }
  else if ( a1[49] && *((_DWORD *)a1 + 96) == 1 )
  {
    v11 = (unsigned int *)(a1 + 47);
    if ( a1 == (__int64 *)-376LL )
      goto LABEL_24;
  }
  else
  {
    if ( !a1[54] )
      goto LABEL_24;
    if ( *((_DWORD *)a1 + 106) != 1 )
      goto LABEL_24;
    v11 = (unsigned int *)(a1 + 52);
    if ( a1 == (__int64 *)-416LL )
      goto LABEL_24;
  }
  if ( *(unsigned __int8 *)v11 >= 6u )
  {
    v12 = "Invalid vdev id %d in BS_SM request";
LABEL_27:
    qdf_trace_msg(0xA1u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9);
    return qdf_trace_msg(
             0xA1u,
             2u,
             "%s: BS_SM vdev %d Invalid total ref count %d",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "ll_lt_sap_continue_bs_to_wlan",
             *(unsigned __int8 *)(*a1 + 104),
             *((unsigned int *)a1 + 61));
  }
  v21 = v11[3];
  if ( v21 >= 6 )
  {
    v12 = "Invalid source %d in BS_SM request";
    goto LABEL_27;
  }
  v22 = *a1;
  v23 = v11[2];
  osif_cbk = (_DWORD **)ll_sap_get_osif_cbk(a1);
  if ( osif_cbk )
  {
    v25 = *osif_cbk;
    if ( *osif_cbk )
    {
      if ( *(v25 - 1) != 1824459834 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))v25)(v22, v23, v21);
    }
  }
  *((_BYTE *)a1 + 92) = 0;
  if ( (unsigned int)qdf_mc_timer_start((__int64)(a1 + 57), 0x1388u) )
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: BS_SM_%d req_id 0x%x: Failed to start timer",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "ll_lt_sap_continue_bs_to_wlan",
      *(unsigned __int8 *)(*a1 + 104),
      v11[1]);
  return wlan_sm_transition_to(a1[10], 2u, v26, v27, v28, v29, v30, v31, v32, v33);
}
