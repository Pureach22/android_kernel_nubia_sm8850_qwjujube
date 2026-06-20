__int64 __fastcall send_peer_delete_all_cmd_tlv(__int64 a1, unsigned __int8 *a2)
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
  int v15; // w8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_peer_delete_all_cmd_tlv", 0x7ACu);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 53411860;
  v13[1] = *a2;
  v15 = *((_DWORD *)a2 + 1);
  if ( (v15 & 2) != 0 )
  {
    v13[2] |= 1u;
    if ( (v15 & 4) == 0 )
    {
LABEL_4:
      if ( (v15 & 0x40) == 0 )
        goto LABEL_5;
      goto LABEL_14;
    }
  }
  else if ( (v15 & 4) == 0 )
  {
    goto LABEL_4;
  }
  v13[2] |= 2u;
  if ( (v15 & 0x40) == 0 )
  {
LABEL_5:
    if ( (v15 & 0x400) == 0 )
      goto LABEL_6;
    goto LABEL_15;
  }
LABEL_14:
  v13[2] |= 4u;
  if ( (v15 & 0x400) == 0 )
  {
LABEL_6:
    if ( (v15 & 0x1000) == 0 )
      goto LABEL_8;
    goto LABEL_7;
  }
LABEL_15:
  v13[2] |= 0x10u;
  if ( (v15 & 0x1000) != 0 )
LABEL_7:
    v13[2] |= 0x40u;
LABEL_8:
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id %d peer_type_bitmap:%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_peer_delete_all_cmd_tlv");
  qdf_mtrace(49, 100, 0x2A4u, v13[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x18u,
             0x5024u,
             "send_peer_delete_all_cmd_tlv",
             0x7BEu,
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
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send peer del all command",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "send_peer_delete_all_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
