__int64 __fastcall send_add_ts_cmd_tlv(__int64 a1, unsigned __int8 *a2)
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
  _DWORD *v13; // x23
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w21

  *((_DWORD *)a2 + 16) = 0;
  v4 = wmi_buf_alloc_fl(a1, 0x14u, "send_add_ts_cmd_tlv", 0x740u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 12910608;
    v13[1] = *a2;
    v13[2] = (*(unsigned __int16 *)(a2 + 7) >> 11) & 7;
    v13[3] = 32 * *((unsigned __int16 *)a2 + 30);
    v13[4] = 1;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Addts vdev:%d, ac:%d, mediumTime:%d, downgrade_type:%d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_add_ts_cmd_tlv");
    wmi_mtrace(0x500Bu, v13[1], 0);
    if ( (unsigned int)wmi_unified_cmd_send_fl(
                         a1,
                         v14,
                         0x14u,
                         0x500Bu,
                         "send_add_ts_cmd_tlv",
                         0x752u,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22) )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send vdev ADDTS command",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "send_add_ts_cmd_tlv");
      v31 = 16;
      *((_DWORD *)a2 + 16) = 16;
      wmi_buf_free();
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 2;
  }
  return v31;
}
