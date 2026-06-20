__int64 __fastcall send_peer_cfr_capture_cmd_tlv(__int64 a1, __int64 a2)
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
  _DWORD *v13; // x8
  unsigned int v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x20u, "send_peer_cfr_capture_cmd_tlv", 0x19Fu);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    *v13 = 49479708;
    v13[2] = **(_DWORD **)(a2 + 8);
    v13[3] = *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 4LL);
    v13[1] = *(_DWORD *)a2;
    v13[4] = *(_DWORD *)(a2 + 16);
    v13[5] = *(_DWORD *)(a2 + 20);
    v13[6] = *(_DWORD *)(a2 + 24);
    v13[7] = *(_DWORD *)(a2 + 28);
    v14 = wmi_unified_cmd_send_fl(
            a1,
            v4,
            0x20u,
            0x601Au,
            "send_peer_cfr_capture_cmd_tlv",
            0x1B3u,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12);
    if ( v14 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_PEER_CFR_CAPTURE_CMDID",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "send_peer_cfr_capture_cmd_tlv");
      wmi_buf_free();
    }
  }
  else
  {
    v14 = 2;
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: %s:wmi_buf_alloc failed\n",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_peer_cfr_capture_cmd_tlv",
      "send_peer_cfr_capture_cmd_tlv");
  }
  return v14;
}
