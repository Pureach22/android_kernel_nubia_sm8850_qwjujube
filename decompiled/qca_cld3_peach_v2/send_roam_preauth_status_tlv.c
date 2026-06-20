__int64 __fastcall send_roam_preauth_status_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
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
  __int64 result; // x0
  int v24; // [xsp+0h] [xbp-10h]
  int v25; // [xsp+8h] [xbp-8h]

  v4 = wmi_buf_alloc_fl(a1, 0x28u, "send_roam_preauth_status_tlv", 0x18F1u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 53805072;
  v5[1] = *(_DWORD *)a2;
  v5[2] = *(_DWORD *)(a2 + 4);
  v5[3] = *(_DWORD *)(a2 + 8);
  v5[4] = *(unsigned __int16 *)(a2 + 12);
  v5[5] = 1114128;
  qdf_mem_copy(v5 + 6, (const void *)(a2 + 14), 0x10u);
  v25 = *(unsigned __int8 *)(a2 + 13);
  v24 = *(unsigned __int8 *)(a2 + 10);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id:%d status:%d bssid:%02x:%02x:%02x:**:**:%02x",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "send_roam_preauth_status_tlv",
    (unsigned int)v5[1],
    (unsigned int)v5[2],
    *(unsigned __int8 *)(a2 + 8),
    *(unsigned __int8 *)(a2 + 9),
    v24,
    v25);
  wmi_mtrace(0xB018u, v5[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x28u,
             0xB018u,
             "send_roam_preauth_status_tlv",
             0x190Cu,
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
