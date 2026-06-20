__int64 __fastcall send_peer_create_cmd_tlv(__int64 a1, __int64 a2)
{
  int mlo_params_size; // w22
  __int64 v5; // x0
  _DWORD *v6; // x23
  __int64 v7; // x20
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

  mlo_params_size = peer_create_mlo_params_size(a2);
  v5 = wmi_buf_alloc_fl(a1, mlo_params_size + 32, "send_peer_create_cmd_tlv", 0x8F9u);
  if ( !v5 )
    return 2;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 6357020;
  v6[2] = **(_DWORD **)a2;
  v6[3] = *(unsigned __int16 *)(*(_QWORD *)a2 + 4LL);
  v6[4] = *(_DWORD *)(a2 + 8);
  v6[1] = *(_DWORD *)(a2 + 12);
  peer_create_add_mlo_params(*(_QWORD *)(v5 + 224) + 32LL, a2);
  qdf_mtrace(49, 100, 0x301u, v6[1], 0);
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       a1,
                       v7,
                       mlo_params_size + 32,
                       0x6001u,
                       "send_peer_create_cmd_tlv",
                       0x90Au,
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
      "%s: Failed to send WMI_PEER_CREATE_CMDID",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "send_peer_create_cmd_tlv");
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
      "%s: peer_addr %02x:%02x:%02x:**:**:%02x vdev_id %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "send_peer_create_cmd_tlv",
      v26,
      v27,
      v28,
      v29,
      *(_DWORD *)(a2 + 12));
    return 0;
  }
}
