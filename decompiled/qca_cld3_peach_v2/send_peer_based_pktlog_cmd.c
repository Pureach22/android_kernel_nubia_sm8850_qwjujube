__int64 __fastcall send_peer_based_pktlog_cmd(__int64 a1, __int64 a2, unsigned __int8 a3, unsigned __int8 a4)
{
  __int64 v8; // x0
  __int64 v9; // x24
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v8 = wmi_buf_alloc_fl(a1, 0x24u, "send_peer_based_pktlog_cmd", 0xE49u);
  if ( v8 )
  {
    v9 = *(_QWORD *)(v8 + 224);
    v10 = v8;
    *(_DWORD *)v9 = 50397200;
    *(_DWORD *)(v9 + 4) = a3;
    *(_DWORD *)(v9 + 8) = a4;
    *(_DWORD *)(v9 + 16) = 1;
    qdf_mtrace(49, 100, 0x236u, a3, 0);
    *(_QWORD *)(v9 + 20) = 0x30200080012000CLL;
    *(_DWORD *)(v9 + 28) = *(_DWORD *)a2;
    *(_DWORD *)(v9 + 32) = *(unsigned __int16 *)(a2 + 4);
    v19 = wmi_unified_cmd_send_fl(
            a1,
            v10,
            0x24u,
            0x4036u,
            "send_peer_based_pktlog_cmd",
            0xE66u,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18);
    if ( v19 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send peer based pktlog command to FW =%d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "send_peer_based_pktlog_cmd",
        v19);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v19;
}
