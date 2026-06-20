__int64 __fastcall send_set_mac_address_cmd_tlv(__int64 a1, unsigned __int8 *a2)
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  int v24; // [xsp+0h] [xbp-30h]
  int v25; // [xsp+8h] [xbp-28h]
  int v26; // [xsp+10h] [xbp-20h]
  int v27; // [xsp+18h] [xbp-18h]
  int v28; // [xsp+20h] [xbp-10h]

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_set_mac_address_cmd_tlv", 0x58A4u);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 67567636;
  v13[1] = *a2;
  v13[2] = *(_DWORD *)(a2 + 1);
  v13[3] = *(unsigned __int16 *)(a2 + 5);
  v13[4] = *(_DWORD *)(a2 + 7);
  v13[5] = *(unsigned __int16 *)(a2 + 11);
  v26 = a2[8];
  v28 = a2[12];
  v27 = a2[9];
  v25 = a2[7];
  v24 = a2[6];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev %d mac_addr %02x:%02x:%02x:**:**:%02x mld_addr %02x:%02x:%02x:**:**:%02x",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_set_mac_address_cmd_tlv",
    v24,
    v25,
    v26,
    v27,
    v28);
  qdf_mtrace(49, 100, 0x2B0u, v13[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x18u,
             0x5030u,
             "send_set_mac_address_cmd_tlv",
             0x58B8u,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( (_DWORD)result )
  {
    wmi_buf_free();
    return 16;
  }
  return result;
}
