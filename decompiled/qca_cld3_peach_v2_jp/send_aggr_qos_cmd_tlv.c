__int64 __fastcall send_aggr_qos_cmd_tlv(__int64 a1, unsigned __int16 *a2)
{
  __int64 v4; // x24
  __int64 i; // x25
  int v6; // w5
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
  unsigned __int16 *v23; // x28
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x26
  __int64 v34; // x23
  unsigned __int64 v35; // x8

  v4 = 0;
  for ( i = 29; ; i += 29 )
  {
    if ( ((*a2 >> v4) & 1) != 0 )
    {
      v23 = &a2[2 * v4];
      *((_DWORD *)v23 + 59) = 0;
      v24 = wmi_buf_alloc_fl(a1, 0x14u, "send_aggr_qos_cmd_tlv", 0x70Du);
      if ( !v24 )
        return 2;
      v33 = *(_QWORD *)(v24 + 224);
      v34 = v24;
      *(_DWORD *)v33 = 12910608;
      *(_DWORD *)(v33 + 4) = *((unsigned __int8 *)a2 + 253);
      v35 = ((unsigned __int64)*(unsigned __int16 *)((char *)&a2[i - 26] - 1) >> 11) & 7;
      v6 = (unsigned int)v35 <= 5 ? dword_A2EB50[v35] : 3;
      *(_DWORD *)(v33 + 8) = v6;
      *(_QWORD *)(v33 + 12) = 32 * (unsigned int)a2[i];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Addts vdev:%d, ac:%d, mediumTime:%d downgrade_type:%d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "send_aggr_qos_cmd_tlv");
      wmi_mtrace(0x500Bu, *(_DWORD *)(v33 + 4), 0);
      if ( (unsigned int)wmi_unified_cmd_send_fl(
                           a1,
                           v34,
                           0x14u,
                           0x500Bu,
                           "send_aggr_qos_cmd_tlv",
                           0x723u,
                           v7,
                           v8,
                           v9,
                           v10,
                           v11,
                           v12,
                           v13,
                           v14) )
        break;
    }
    if ( ++v4 == 4 )
      return 0;
  }
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Failed to send vdev ADDTS command",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "send_aggr_qos_cmd_tlv");
  *((_DWORD *)v23 + 59) = 16;
  wmi_buf_free();
  return 16;
}
