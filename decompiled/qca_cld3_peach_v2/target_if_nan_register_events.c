__int64 __fastcall target_if_nan_register_events(
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
  _QWORD *v10; // x20
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2800)) == 0 || (v10 = *(_QWORD **)(v9 + 16)) == nullptr )
  {
    qdf_trace_msg(0x49u, 2u, "%s: handle is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_nan_register_events");
    return 16;
  }
  v12 = wmi_unified_register_event_handler(
          *(_QWORD **)(v9 + 16),
          0x1Du,
          (__int64)target_if_nan_rsp_handler,
          1u,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9);
  if ( v12
    || (v12 = wmi_unified_register_event_handler(
                v10,
                0x9Du,
                (__int64)target_if_ndp_initiator_rsp_handler,
                1u,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20)) != 0 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi event registration failed, ret: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_nan_register_events",
      v12);
    return 16;
  }
  LODWORD(result) = wmi_unified_register_event_handler(
                      v10,
                      0xA3u,
                      (__int64)target_if_nan_dmesg_handler,
                      0,
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20);
  if ( (_DWORD)result
    || (LODWORD(result) = wmi_unified_register_event_handler(
                            v10,
                            0x9Eu,
                            (__int64)target_if_ndp_ind_handler,
                            1u,
                            v22,
                            v23,
                            v24,
                            v25,
                            v26,
                            v27,
                            v28,
                            v29),
        (_DWORD)result)
    || (LODWORD(result) = wmi_unified_register_event_handler(
                            v10,
                            0x9Fu,
                            (__int64)&target_if_ndp_confirm_handler,
                            1u,
                            v22,
                            v23,
                            v24,
                            v25,
                            v26,
                            v27,
                            v28,
                            v29),
        (_DWORD)result)
    || (LODWORD(result) = wmi_unified_register_event_handler(
                            v10,
                            0xA0u,
                            (__int64)target_if_ndp_responder_rsp_handler,
                            1u,
                            v22,
                            v23,
                            v24,
                            v25,
                            v26,
                            v27,
                            v28,
                            v29),
        (_DWORD)result)
    || (LODWORD(result) = wmi_unified_register_event_handler(
                            v10,
                            0xA1u,
                            (__int64)target_if_ndp_end_ind_handler,
                            1u,
                            v22,
                            v23,
                            v24,
                            v25,
                            v26,
                            v27,
                            v28,
                            v29),
        (_DWORD)result)
    || (LODWORD(result) = wmi_unified_register_event_handler(
                            v10,
                            0xA2u,
                            (__int64)target_if_ndp_end_rsp_handler,
                            1u,
                            v22,
                            v23,
                            v24,
                            v25,
                            v26,
                            v27,
                            v28,
                            v29),
        (_DWORD)result)
    || (LODWORD(result) = wmi_unified_register_event_handler(
                            v10,
                            0xA4u,
                            (__int64)&target_if_ndp_sch_update_handler,
                            1u,
                            v22,
                            v23,
                            v24,
                            v25,
                            v26,
                            v27,
                            v28,
                            v29),
        (_DWORD)result)
    || (result = wmi_unified_register_event_handler(
                   v10,
                   0xA5u,
                   (__int64)target_if_ndp_host_event_handler,
                   1u,
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29),
        (_DWORD)result) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi event registration failed, ret: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "target_if_nan_register_events",
      (unsigned int)result);
    target_if_nan_deregister_events(a1);
    return 16;
  }
  return result;
}
