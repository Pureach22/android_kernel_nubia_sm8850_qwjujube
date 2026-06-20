__int64 __fastcall cm_connect_start(
        __int64 *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x8
  __int64 v13; // x0
  unsigned int v14; // w21
  __int64 v15; // x22
  unsigned int v16; // w23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x5
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x5
  const char *v35; // x2
  int v36; // w2
  __int64 v37; // x3
  int v38; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x5
  int v48; // w0
  __int64 result; // x0
  const char *v50; // x2
  int v51; // w8

  _ReadStatusReg(SP_EL0);
  v12 = *a1;
  v13 = *(_QWORD *)(*a1 + 216);
  v14 = *(unsigned __int8 *)(v12 + 168);
  if ( !v13 )
  {
    v34 = *a2;
    v35 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
LABEL_10:
    qdf_trace_msg(
      0x68u,
      2u,
      v35,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_connect_start",
      *(unsigned __int8 *)(v12 + 168),
      v34);
    v36 = 14;
LABEL_23:
    result = cm_send_connect_start_fail(a1, a2, v36);
    goto LABEL_24;
  }
  v15 = *(_QWORD *)(v13 + 80);
  if ( !v15 )
  {
    v34 = *a2;
    v35 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
    goto LABEL_10;
  }
  v16 = *(unsigned __int8 *)(v12 + 168);
  if ( !a2[1] )
  {
    if_mgr_deliver_event(v12, 0, 0, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( (unsigned int)mlme_cm_connect_start_ind(*a1, a2 + 2) )
      goto LABEL_22;
    v16 = *(unsigned __int8 *)(*a1 + 168);
  }
  if ( (unsigned int)cm_connect_fetch_candidates() || !a2[1] && *((_BYTE *)a2 + 1048) == 1 )
  {
    v25 = *a2;
    if ( *((_BYTE *)a2 + 1048) == 1 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d cm_id 0x%x:  Do scan for ssid for nontx profiles",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "cm_connect_get_candidates",
        v16,
        v25);
      if ( a2[1] )
        goto LABEL_22;
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        4u,
        "%s: vdev %d cm_id 0x%x: no valid candidate found, num_bss %d scan_id %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "cm_connect_get_candidates",
        v16,
        v25,
        0,
        a2[1]);
      if ( a2[1] )
        goto LABEL_22;
    }
    if ( (a2[204] & 1) == 0 )
    {
      v51 = wlan_sm_dispatch(a1[9], 1u, 0x9D8u, (__int64)a2, v26, v27, v28, v29, v30, v31, v32, v33);
      result = 0;
      if ( v51 )
      {
        v36 = 1;
        if ( v51 != 24 )
          goto LABEL_23;
      }
      goto LABEL_24;
    }
LABEL_22:
    v36 = 1;
    goto LABEL_23;
  }
  v37 = *a2;
  *((_QWORD *)a2 + 125) = 0;
  a2[252] = 0;
  v38 = wlan_ll_sap_switch_bearer_on_sta_connect_start(v15, 0, v14, v37);
  v47 = *a2;
  if ( !v38 )
  {
    v50 = "%s: vdev %d cm_id 0x%x: Connect will continue after bearer switch";
LABEL_30:
    qdf_trace_msg(0x68u, 8u, v50, v39, v40, v41, v42, v43, v44, v45, v46, "cm_connect_start", v14, v47);
    result = 0;
    goto LABEL_24;
  }
  v48 = policy_mgr_change_hw_mode_sta_connect(v15, *((_QWORD *)a2 + 125), v14, (unsigned int)v47);
  if ( !v48 )
  {
    v47 = *a2;
    v50 = "%s: vdev %d cm_id 0x%x: Connect will continue after HW mode change";
    goto LABEL_30;
  }
  if ( v48 != 6 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: Failed to set HW mode change",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "cm_connect_start",
      v14,
      *a2);
    v36 = 11;
    goto LABEL_23;
  }
  result = cm_ser_connect_req((__int64)a1, a2, v39, v40, v41, v42, v43, v44, v45, v46);
  if ( (_DWORD)result )
  {
    v36 = 12;
    goto LABEL_23;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
