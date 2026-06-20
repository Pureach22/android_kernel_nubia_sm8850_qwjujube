__int64 __fastcall send_peer_rx_reorder_queue_setup_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x20
  int v7; // w3
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int8 *v25; // x8
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7

  v4 = wmi_buf_alloc_fl(a1, 0x28u, "send_peer_rx_reorder_queue_setup_cmd_tlv", 0x926u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 35979300;
  v5[2] = **(_DWORD **)a2;
  v5[3] = *(unsigned __int16 *)(*(_QWORD *)a2 + 4LL);
  v7 = *(unsigned __int16 *)(a2 + 10);
  v5[1] = v7;
  v5[4] = *(unsigned __int16 *)(a2 + 8);
  v5[5] = *(_DWORD *)(a2 + 12);
  v5[6] = *(_DWORD *)(a2 + 16);
  v5[7] = *(unsigned __int16 *)(a2 + 20);
  v5[8] = *(unsigned __int8 *)(a2 + 22);
  v5[9] = *(unsigned __int16 *)(a2 + 24);
  qdf_mtrace(49, 100, 0x313u, v7, 0);
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       a1,
                       v6,
                       0x28u,
                       0x6013u,
                       "send_peer_rx_reorder_queue_setup_cmd_tlv",
                       0x93Bu,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Fail to send WMI_PEER_REORDER_QUEUE_SETUP_CMDID",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "send_peer_rx_reorder_queue_setup_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  else
  {
    v25 = *(unsigned __int8 **)a2;
    if ( *(_QWORD *)a2 )
    {
      v26 = *v25;
      v27 = v25[1];
      v28 = v25[2];
      v29 = v25[5];
    }
    else
    {
      v28 = 0;
      v26 = 0;
      v27 = 0;
      v29 = 0;
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: peer_macaddr %02x:%02x:%02x:**:**:%02x vdev_id %d, tid %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "send_peer_rx_reorder_queue_setup_cmd_tlv",
      v26,
      v27,
      v28,
      v29,
      *(unsigned __int16 *)(a2 + 10),
      *(unsigned __int16 *)(a2 + 8));
    return 0;
  }
}
