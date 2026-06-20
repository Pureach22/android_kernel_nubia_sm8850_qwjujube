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
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  __int64 result; // x0
  int v35; // w2
  __int64 v36; // x5
  const char *v37; // x2
  __int64 v38; // x3
  int v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x5
  int v49; // w0
  const char *v50; // x2

  _ReadStatusReg(SP_EL0);
  v12 = *a1;
  v13 = *(_QWORD *)(*a1 + 152);
  v14 = *(unsigned __int8 *)(v12 + 104);
  if ( !v13 )
  {
    v36 = *a2;
    v37 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
LABEL_11:
    qdf_trace_msg(
      0x68u,
      2u,
      v37,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_connect_start",
      *(unsigned __int8 *)(v12 + 104),
      v36);
    v35 = 14;
LABEL_14:
    result = cm_send_connect_start_fail(a1, a2, v35);
    goto LABEL_15;
  }
  v15 = *(_QWORD *)(v13 + 80);
  if ( !v15 )
  {
    v36 = *a2;
    v37 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
    goto LABEL_11;
  }
  v16 = *(unsigned __int8 *)(v12 + 104);
  if ( !a2[1] )
  {
    if_mgr_deliver_event(v12, 0, 0, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( (unsigned int)mlme_cm_connect_start_ind(*a1, a2 + 2) )
    {
LABEL_13:
      v35 = 1;
      goto LABEL_14;
    }
    v16 = *(unsigned __int8 *)(*a1 + 104);
  }
  if ( !(unsigned int)cm_connect_fetch_candidates() )
  {
    v38 = *a2;
    *((_QWORD *)a2 + 103) = 0;
    a2[208] = 0;
    v39 = wlan_ll_sap_switch_bearer_on_sta_connect_start(v15, 0, v14, v38);
    v48 = *a2;
    if ( v39 )
    {
      v49 = policy_mgr_change_hw_mode_sta_connect(v15, *((_QWORD *)a2 + 103), v14, (unsigned int)v48);
      if ( v49 )
      {
        if ( v49 == 6 )
        {
          result = cm_ser_connect_req((__int64)a1, a2, v40, v41, v42, v43, v44, v45, v46, v47);
          if ( !(_DWORD)result )
            goto LABEL_15;
          v35 = 12;
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev %d cm_id 0x%x: Failed to set HW mode change",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "cm_connect_start",
            v14,
            *a2);
          v35 = 11;
        }
        goto LABEL_14;
      }
      v48 = *a2;
      v50 = "%s: vdev %d cm_id 0x%x: Connect will continue after HW mode change";
    }
    else
    {
      v50 = "%s: vdev %d cm_id 0x%x: Connect will continue after bearer switch";
    }
    qdf_trace_msg(0x68u, 8u, v50, v40, v41, v42, v43, v44, v45, v46, v47, "cm_connect_start", v14, v48);
    result = 0;
    goto LABEL_15;
  }
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
    *a2,
    0,
    a2[1]);
  if ( a2[1] )
    goto LABEL_13;
  v33 = wlan_sm_dispatch(a1[9], 1u, 0x368u, (__int64)a2, v25, v26, v27, v28, v29, v30, v31, v32);
  result = 0;
  if ( v33 )
  {
    v35 = 1;
    if ( v33 != 24 )
      goto LABEL_14;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
