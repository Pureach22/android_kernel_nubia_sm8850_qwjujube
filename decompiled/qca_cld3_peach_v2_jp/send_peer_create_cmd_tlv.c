__int64 __fastcall send_peer_create_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int8 *v24; // x8
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7

  v4 = wmi_buf_alloc_fl(a1, 0x24u, "send_peer_create_cmd_tlv", 0x8F9u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 6357020;
  v5[2] = **(_DWORD **)a2;
  v5[3] = *(unsigned __int16 *)(*(_QWORD *)a2 + 4LL);
  v5[4] = *(_DWORD *)(a2 + 8);
  v5[1] = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(*(_QWORD *)(v4 + 224) + 32LL) = 1179648;
  qdf_mtrace(49, 100, 0x301u, v5[1], 0);
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       a1,
                       v6,
                       0x24u,
                       0x6001u,
                       "send_peer_create_cmd_tlv",
                       0x90Au,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_PEER_CREATE_CMDID",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "send_peer_create_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  else
  {
    v24 = *(unsigned __int8 **)a2;
    if ( *(_QWORD *)a2 )
    {
      v25 = *v24;
      v26 = v24[1];
      v27 = v24[2];
      v28 = v24[5];
    }
    else
    {
      v27 = 0;
      v25 = 0;
      v26 = 0;
      v28 = 0;
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: peer_addr %02x:%02x:%02x:**:**:%02x vdev_id %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "send_peer_create_cmd_tlv",
      v25,
      v26,
      v27,
      v28,
      *(_DWORD *)(a2 + 12));
    return 0;
  }
}
