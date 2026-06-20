__int64 __fastcall get_tsf_stats_for_csa_tlv(__int64 a1, unsigned __int8 a2)
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
  unsigned int v24; // w20

  v4 = wmi_buf_alloc_fl(a1, 8u, "get_tsf_stats_for_csa_tlv", 0xF0u);
  if ( !v4 )
    return 16;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 80412676;
  v13[1] = a2;
  qdf_trace_msg(0x31u, 8u, "get tsf stats for vdev_id %d", v5, v6, v7, v8, v9, v10, v11, v12);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             8u,
             0x3E00Bu,
             "get_tsf_stats_for_csa_tlv",
             0x101u,
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
    v24 = result;
    wmi_buf_free();
    return v24;
  }
  return result;
}
