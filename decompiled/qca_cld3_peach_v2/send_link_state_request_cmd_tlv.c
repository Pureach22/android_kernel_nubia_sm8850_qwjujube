__int64 __fastcall send_link_state_request_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x22
  __int64 v14; // x19
  int v15; // w1
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_link_state_request_cmd_tlv", 0x850u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 76087308;
    v15 = *a2;
    v13[1] = v15;
    v13[2] = *(_DWORD *)(a2 + 1);
    v13[3] = *(unsigned __int16 *)(a2 + 5);
    wmi_mtrace(0x48008u, v15, 0);
    v24 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            0x10u,
            0x48008u,
            "send_link_state_request_cmd_tlv",
            0x865u,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23);
    if ( v24 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send ml link state command to FW: %d vdev id %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "send_link_state_request_cmd_tlv",
        v24,
        (unsigned int)v13[1]);
      wmi_buf_free();
    }
  }
  else
  {
    v24 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi buf alloc failed for vdev id %d while link state cmd send: ",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_link_state_request_cmd_tlv",
      *a2);
  }
  return v24;
}
