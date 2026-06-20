__int64 __fastcall target_if_wifi_pos_register_events(
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
  __int64 v9; // x8
  _QWORD *v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  _QWORD *v21; // x0
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  _QWORD *v32; // x0
  __int64 v33; // x8
  _QWORD *v34; // x0
  __int64 result; // x0
  __int64 v36; // x8
  _QWORD *v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v46; // x2
  __int64 v47; // x8
  _QWORD *v48; // x0

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2800)) == 0 || (v11 = *(_QWORD **)(v9 + 16)) == nullptr )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: psoc or psoc->tgt_if_handle is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_wifi_pos_register_events");
    return 4;
  }
  wmi_unified_register_event_handler(
    v11,
    0xA6u,
    (__int64)target_if_wifi_pos_oem_rsp_ev_handler,
    0,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9);
  v20 = *(_QWORD *)(a1 + 2800);
  if ( v20 )
    v21 = *(_QWORD **)(v20 + 16);
  else
    v21 = nullptr;
  v22 = wmi_unified_register_event_handler(
          v21,
          0x1Au,
          (__int64)wifi_pos_oem_cap_ev_handler,
          0,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19);
  if ( v22
    || ((v31 = *(_QWORD *)(a1 + 2800)) == 0 ? (v32 = nullptr) : (v32 = *(_QWORD **)(v31 + 16)),
        (v22 = wmi_unified_register_event_handler(
                 v32,
                 0x1Bu,
                 (__int64)wifi_pos_oem_meas_rpt_ev_handler,
                 0,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30)) != 0
     || ((v33 = *(_QWORD *)(a1 + 2800)) == 0 ? (v34 = nullptr) : (v34 = *(_QWORD **)(v33 + 16)),
         (v22 = wmi_unified_register_event_handler(
                  v34,
                  0x1Cu,
                  (__int64)wifi_pos_oem_err_rpt_ev_handler,
                  0,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30)) != 0)) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: register_event_handler failed: err %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "target_if_wifi_pos_register_events",
      v22);
    return 4;
  }
  v36 = *(_QWORD *)(a1 + 2800);
  if ( v36 )
    v37 = *(_QWORD **)(v36 + 16);
  else
    v37 = nullptr;
  if ( (unsigned int)wmi_unified_register_event_handler(
                       v37,
                       0xFCu,
                       (__int64)target_if_wifi_pos_pasn_peer_create_ev_handler,
                       2u,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30) )
  {
    v46 = "%s: register pasn peer create event_handler failed";
LABEL_30:
    qdf_trace_msg(0x49u, 2u, v46, v38, v39, v40, v41, v42, v43, v44, v45, "target_if_wifi_pos_register_11az_events");
    return 0;
  }
  v47 = *(_QWORD *)(a1 + 2800);
  if ( v47 )
    v48 = *(_QWORD **)(v47 + 16);
  else
    v48 = nullptr;
  result = wmi_unified_register_event_handler(
             v48,
             0xFDu,
             (__int64)target_if_wifi_pos_pasn_peer_delete_ev_handler,
             2u,
             v38,
             v39,
             v40,
             v41,
             v42,
             v43,
             v44,
             v45);
  if ( (_DWORD)result )
  {
    v46 = "%s: register pasn peer delete event_handler failed";
    goto LABEL_30;
  }
  return result;
}
