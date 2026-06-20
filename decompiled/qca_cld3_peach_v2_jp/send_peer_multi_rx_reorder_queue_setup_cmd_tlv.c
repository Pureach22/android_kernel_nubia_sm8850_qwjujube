__int64 __fastcall send_peer_multi_rx_reorder_queue_setup_cmd_tlv(__int64 a1, __int64 a2)
{
  unsigned int v3; // w21
  __int64 v5; // x0
  _DWORD *v6; // x9
  __int64 v7; // x20
  __int64 v8; // x8
  __int64 v9; // x12
  _DWORD *v10; // x10
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned __int8 *v28; // x8
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7

  v3 = 28 * *(unsigned __int8 *)(a2 + 284) + 20;
  v5 = wmi_buf_alloc_fl(a1, v3, "send_peer_multi_rx_reorder_queue_setup_cmd_tlv", 0x95Fu);
  if ( !v5 )
    return 2;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  v8 = 0;
  v9 = a2;
  *v6 = 80019468;
  v6[2] = **(_DWORD **)(a2 + 272);
  v6[3] = *(unsigned __int16 *)(*(_QWORD *)(a2 + 272) + 4LL);
  v6[1] = *(unsigned __int16 *)(a2 + 286);
  v6[4] = (28 * *(unsigned __int8 *)(a2 + 284)) | 0x120000;
  v10 = v6 + 5;
  do
  {
    if ( (((unsigned __int64)*(unsigned int *)(a2 + 280) >> v8) & 1) != 0 )
    {
      *v10 = 80085016;
      v10[1] = v8;
      v10[2] = *(_QWORD *)v9;
      v10[3] = *(_DWORD *)(v9 + 4);
      v10[4] = *(unsigned __int16 *)(v9 + 8);
      v10[5] = *(unsigned __int8 *)(v9 + 12);
      v10[6] = *(unsigned __int16 *)(v9 + 10);
      v10 += 7;
    }
    ++v8;
    v9 += 16;
  }
  while ( v8 != 17 );
  qdf_mtrace(49, 100, 0x326u, v6[1], 0);
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       a1,
                       v7,
                       v3,
                       0x6026u,
                       "send_peer_multi_rx_reorder_queue_setup_cmd_tlv",
                       0x991u,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Send WMI_PEER_MULTILE_REORDER_QUEUE_SETUP_CMDID fail",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "send_peer_multi_rx_reorder_queue_setup_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  else
  {
    v28 = *(unsigned __int8 **)(a2 + 272);
    if ( v28 )
    {
      v29 = *v28;
      v30 = v28[1];
      v31 = v28[2];
      v32 = v28[5];
    }
    else
    {
      v31 = 0;
      v29 = 0;
      v30 = 0;
      v32 = 0;
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: peer_mac %02x:%02x:%02x:**:**:%02x vdev_id %d, bitmap 0x%x, num %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "send_peer_multi_rx_reorder_queue_setup_cmd_tlv",
      v29,
      v30,
      v31,
      v32,
      *(unsigned __int16 *)(a2 + 286),
      *(_DWORD *)(a2 + 280),
      *(unsigned __int8 *)(a2 + 284));
    return 0;
  }
}
