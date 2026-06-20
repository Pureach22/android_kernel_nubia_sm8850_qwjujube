__int64 __fastcall send_set_sta_ps_param_cmd_tlv(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x19
  unsigned int v7; // w3
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_set_sta_ps_param_cmd_tlv", 0xCB1u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 7143436;
  v7 = *a2;
  v5[1] = *a2;
  v5[2] = a2[1];
  v5[3] = a2[2];
  qdf_mtrace(49, 100, 0x482u, v7, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x10u,
             0x9002u,
             "send_set_sta_ps_param_cmd_tlv",
             0xCC0u,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Set Sta Ps param Failed vdevId %d Param %d val %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "send_set_sta_ps_param_cmd_tlv",
      *a2,
      a2[1],
      a2[2]);
    wmi_buf_free();
    return 16;
  }
  return result;
}
