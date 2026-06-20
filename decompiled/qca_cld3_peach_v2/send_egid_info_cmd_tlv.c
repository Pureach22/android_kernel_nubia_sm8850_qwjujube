__int64 __fastcall send_egid_info_cmd_tlv(__int64 a1, const void *a2)
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
  __int64 v13; // x19
  _DWORD *v14; // x0
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
  unsigned int v31; // w19

  v4 = wmi_buf_alloc_fl(a1, 0x14u, "send_egid_info_cmd_tlv", 0x5940u);
  if ( v4 )
  {
    v13 = v4;
    v14 = *(_DWORD **)(v4 + 224);
    *v14 = 75366416;
    qdf_mem_copy(v14 + 1, a2, 0x10u);
    if ( (unsigned int)wmi_unified_cmd_send_fl(
                         a1,
                         v13,
                         0x14u,
                         0x2900Au,
                         "send_egid_info_cmd_tlv",
                         0x594Eu,
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
        "%s: Failed to send WMI command",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "send_egid_info_cmd_tlv");
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
    v31 = 2;
    qdf_trace_msg(0x31u, 2u, "%s: wmi_buf_alloc failed", v5, v6, v7, v8, v9, v10, v11, v12, "send_egid_info_cmd_tlv");
  }
  return v31;
}
