__int64 __fastcall wmi_send_apf_read_work_memory_cmd_tlv(__int64 a1, unsigned __int8 *a2)
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w19

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "wmi_send_apf_read_work_memory_cmd_tlv", 0xA8u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    *v13 = 47054860;
    v13[1] = *a2;
    v13[2] = *((_DWORD *)a2 + 1);
    v13[3] = *((_DWORD *)a2 + 2);
    if ( (unsigned int)wmi_unified_cmd_send_fl(
                         a1,
                         v4,
                         0x10u,
                         0x36008u,
                         "wmi_send_apf_read_work_memory_cmd_tlv",
                         0xBAu,
                         v5,
                         v6,
                         v7,
                         v8,
                         v9,
                         v10,
                         v11,
                         v12) )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to get APF work memory",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wmi_send_apf_read_work_memory_cmd_tlv");
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
    v22 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_alloc failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wmi_send_apf_read_work_memory_cmd_tlv");
  }
  return v22;
}
