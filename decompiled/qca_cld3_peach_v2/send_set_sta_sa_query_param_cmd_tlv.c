__int64 __fastcall send_set_sta_sa_query_param_cmd_tlv(__int64 a1, unsigned __int8 a2, int a3, int a4)
{
  unsigned int v8; // w24
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _DWORD *v18; // x24
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  v8 = 16;
  v9 = wmi_buf_alloc_fl(a1, 0x10u, "send_set_sta_sa_query_param_cmd_tlv", 0x32u);
  if ( v9 )
  {
    v18 = *(_DWORD **)(v9 + 224);
    v19 = v9;
    *v18 = 28704780;
    v18[1] = a2;
    v18[2] = a4;
    v18[3] = a3;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: STA sa query: vdev_id:%d interval:%u retry count:%d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "send_set_sta_sa_query_param_cmd_tlv");
    wmi_mtrace(0x35001u, v18[1], 0);
    if ( (unsigned int)wmi_unified_cmd_send_fl(
                         a1,
                         v19,
                         0x10u,
                         0x35001u,
                         "send_set_sta_sa_query_param_cmd_tlv",
                         0x46u,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27) )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to offload STA SA Query",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "send_set_sta_sa_query_param_cmd_tlv");
      wmi_buf_free();
      return 16;
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Exit",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "send_set_sta_sa_query_param_cmd_tlv");
      return 0;
    }
  }
  return v8;
}
