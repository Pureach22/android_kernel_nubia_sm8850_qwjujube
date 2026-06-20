__int64 __fastcall send_ap_suspend_cmd_tlv(__int64 a1, __int64 a2)
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
  unsigned int v23; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x14u, "send_ap_suspend_cmd_tlv", 0xDD6u);
  if ( v4 )
  {
    v5 = *(_DWORD **)(v4 + 224);
    v6 = v4;
    *v5 = 81461264;
    v5[1] = *(_DWORD *)a2;
    v5[4] = *(_DWORD *)(a2 + 12);
    qdf_mem_copy(v5 + 2, (const void *)(a2 + 4), 8u);
    qdf_mtrace(49, 100, 0xEA7u, v5[1], 0);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev_id:%d is_ap_suspend:%d, mld_addr: %02x:%02x:%02x:**:**:%02x",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "send_ap_suspend_cmd_tlv",
      (unsigned int)v5[1],
      (unsigned int)v5[4],
      *(unsigned __int8 *)(a2 + 4),
      *(unsigned __int8 *)(a2 + 5),
      *(unsigned __int8 *)(a2 + 6),
      *(unsigned __int8 *)(a2 + 9));
    v23 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0x14u,
            0x1D027u,
            "send_ap_suspend_cmd_tlv",
            0xDE9u,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22);
    if ( v23 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send set AP suspend command, ret = %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "send_ap_suspend_cmd_tlv",
        v23);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v23;
}
