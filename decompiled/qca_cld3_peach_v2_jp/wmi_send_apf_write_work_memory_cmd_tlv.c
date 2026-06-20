__int64 __fastcall wmi_send_apf_write_work_memory_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  int v2; // w9
  unsigned int v5; // w22
  int v6; // w23
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _DWORD *v16; // x8
  __int64 v17; // x20
  int v18; // w9
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w19

  v2 = *((_DWORD *)a2 + 4);
  if ( v2 )
    v5 = ((v2 + 3) & 0xFFFFFFFC) + 28;
  else
    v5 = 24;
  if ( v2 )
    v6 = (v2 + 3) & 0xFFFC | 0x110000;
  else
    v6 = 1114112;
  v7 = wmi_buf_alloc_fl(a1, v5, "wmi_send_apf_write_work_memory_cmd_tlv", 0x7Bu);
  if ( v7 )
  {
    v16 = *(_DWORD **)(v7 + 224);
    v17 = v7;
    *v16 = 46989332;
    v16[1] = *a2;
    v16[2] = *((_DWORD *)a2 + 1);
    v16[3] = *((_DWORD *)a2 + 2);
    v16[4] = *((_DWORD *)a2 + 3);
    v18 = *((_DWORD *)a2 + 4);
    v16[5] = v18;
    if ( v18 )
    {
      v16[6] = v6;
      qdf_mem_copy(v16 + 7, *((const void **)a2 + 3), *((unsigned int *)a2 + 4));
    }
    if ( (unsigned int)wmi_unified_cmd_send_fl(
                         a1,
                         v17,
                         v5,
                         0x36007u,
                         "wmi_send_apf_write_work_memory_cmd_tlv",
                         0x97u,
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
        "%s: Failed to write APF work memory",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "wmi_send_apf_write_work_memory_cmd_tlv");
      wmi_buf_free();
      return 16;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v27 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_alloc failed",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wmi_send_apf_write_work_memory_cmd_tlv");
  }
  return v27;
}
