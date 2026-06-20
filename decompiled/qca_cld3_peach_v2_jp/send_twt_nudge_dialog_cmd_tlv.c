__int64 __fastcall send_twt_nudge_dialog_cmd_tlv(__int64 a1, __int64 a2)
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
  __int64 v14; // x19
  int v15; // w9
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  unsigned int v25; // w20
  int v26; // [xsp+0h] [xbp-30h]
  int v27; // [xsp+8h] [xbp-28h]
  int v28; // [xsp+10h] [xbp-20h]
  int v29; // [xsp+18h] [xbp-18h]
  int v30; // [xsp+20h] [xbp-10h]

  v4 = wmi_buf_alloc_fl(a1, 0x20u, "send_twt_nudge_dialog_cmd_tlv", 0x143u);
  if ( !v4 )
    return 16;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 61603868;
  v13[1] = *(_DWORD *)a2;
  v13[2] = *(_DWORD *)(a2 + 4);
  v13[3] = *(unsigned __int16 *)(a2 + 8);
  v13[4] = *(_DWORD *)(a2 + 12);
  v13[5] = *(_DWORD *)(a2 + 16) / 0x3E8u;
  v13[6] = *(_DWORD *)(a2 + 20);
  v15 = *(_DWORD *)(a2 + 24);
  v13[7] = v15;
  v30 = v15;
  v29 = *(unsigned __int8 *)(a2 + 9);
  v28 = *(unsigned __int8 *)(a2 + 6);
  v27 = *(unsigned __int8 *)(a2 + 5);
  v26 = *(unsigned __int8 *)(a2 + 4);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id: %d dialog_id: %d duration(in ms): %u next_twt_size: %d peer_macaddr: %02x:%02x:%02x:**:**:%02x sp_start_offset: %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_twt_nudge_dialog_cmd_tlv",
    v26,
    v27,
    v28,
    v29,
    v30);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x20u,
             0x3E009u,
             "send_twt_nudge_dialog_cmd_tlv",
             0x15Du,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23);
  if ( (_DWORD)result )
  {
    v25 = result;
    wmi_buf_free();
    return v25;
  }
  return result;
}
