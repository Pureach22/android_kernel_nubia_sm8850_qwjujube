__int64 __fastcall target_if_direct_buf_rx_register_events(
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
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x8
  __int64 v21; // x19
  unsigned int v22; // w0
  __int64 v23; // x4
  unsigned int v24; // w19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && *(_QWORD *)(v9 + 16) )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 8u);
    if ( comp_private_obj )
    {
      v20 = *(_QWORD **)(a1 + 2800);
      if ( v20 )
        v20 = (_QWORD *)v20[2];
      v21 = comp_private_obj;
      v22 = wmi_unified_register_event_handler(
              v20,
              0xB8u,
              (__int64)target_if_direct_buf_rx_rsp_event_handler,
              *(_DWORD *)(comp_private_obj + 24),
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19);
      v23 = *(unsigned int *)(v21 + 24);
      v24 = v22;
      qdf_trace_msg(
        0x5Bu,
        4u,
        "%s: DBR Handler Context %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "target_if_direct_buf_rx_register_events",
        v23);
      if ( v24 )
        qdf_trace_msg(
          0x5Bu,
          8u,
          "%s: event handler not supported, ret=%d",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "target_if_direct_buf_rx_register_events",
          v24);
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x5Bu,
        2u,
        "%s: dir buf rx psoc object is null",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_direct_buf_rx_register_events");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x5Bu,
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
      "target_if_direct_buf_rx_register_events");
    return 4;
  }
}
