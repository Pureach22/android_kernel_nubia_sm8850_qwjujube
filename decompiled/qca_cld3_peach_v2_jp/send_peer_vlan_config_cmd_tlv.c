__int64 __fastcall send_peer_vlan_config_cmd_tlv(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  int v16; // w10
  int v17; // w9
  unsigned int v18; // w9
  int v19; // w9
  unsigned int v20; // w9
  int v21; // w11
  unsigned int v22; // w9
  int v23; // w11
  int v24; // w9
  unsigned int v25; // w9
  unsigned int v26; // w9
  unsigned int v27; // w9
  unsigned int v28; // w9
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v6 = wmi_buf_alloc_fl(a1, 0x18u, "send_peer_vlan_config_cmd_tlv", 0x224u);
  if ( !v6 )
    return 2;
  v15 = *(_QWORD *)(v6 + 224);
  *(_DWORD *)v15 = 55574548;
  *(_DWORD *)(v15 + 4) = *(_DWORD *)a2;
  *(_DWORD *)(v15 + 8) = *(unsigned __int16 *)(a2 + 4);
  *(_DWORD *)(v15 + 20) = *((unsigned __int8 *)a3 + 6);
  LOWORD(v16) = *a3;
  if ( (*a3 & 1) != 0 )
  {
    v17 = *(_DWORD *)(v15 + 12);
    *(_DWORD *)(v15 + 12) = v17 & 0xFFFFFFFE;
    v18 = v17 & 0xFFFFFFFA | *a3 & 1;
    *(_DWORD *)(v15 + 12) = v18;
    v19 = v18 | *a3 & 4;
    *(_DWORD *)(v15 + 12) = v19;
    v16 = *a3;
    if ( (~v16 & 0xC) == 0 )
    {
      v20 = v19 & 0xFFFFFFF7;
      v21 = *(unsigned __int16 *)(v15 + 18);
      *(_DWORD *)(v15 + 12) = v20;
      v19 = v20 | *a3 & 8;
      *(_DWORD *)(v15 + 12) = v19;
      *(_DWORD *)(v15 + 16) = v21 << 16;
      *(_DWORD *)(v15 + 16) = a3[1] | ((unsigned __int16)v21 << 16);
      v16 = *a3;
    }
    if ( (~v16 & 0x14) == 0 )
    {
      v22 = v19 & 0xFFFFFFEF;
      v23 = *(unsigned __int16 *)(v15 + 16);
      *(_DWORD *)(v15 + 12) = v22;
      *(_DWORD *)(v15 + 12) = v22 | *a3 & 0x10;
      *(_DWORD *)(v15 + 16) = v23;
      *(_DWORD *)(v15 + 16) = v23 | (a3[2] << 16);
      LOWORD(v16) = *a3;
    }
  }
  if ( (v16 & 2) != 0 )
  {
    v24 = *(_DWORD *)(v15 + 12);
    *(_DWORD *)(v15 + 12) = v24 & 0xFFFFFFFD;
    v25 = v24 & 0xFFFFFFDD | *a3 & 2;
    *(_DWORD *)(v15 + 12) = v25;
    v26 = v25 & 0xFFFFFF9F | *a3 & 0x20;
    *(_DWORD *)(v15 + 12) = v26;
    v27 = v26 & 0xFFFFFF3F | *a3 & 0x40;
    *(_DWORD *)(v15 + 12) = v27;
    v28 = v27 & 0xFFFFFE7F | *a3 & 0x80;
    *(_DWORD *)(v15 + 12) = v28;
    *(_DWORD *)(v15 + 12) = v28 | *a3 & 0x100;
  }
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x18u,
             0x601Eu,
             "send_peer_vlan_config_cmd_tlv",
             0x234u,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send peer hw vlan acceleration command",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "send_peer_vlan_config_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
