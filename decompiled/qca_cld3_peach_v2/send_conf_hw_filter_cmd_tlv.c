__int64 __fastcall send_conf_hw_filter_cmd_tlv(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x22
  __int64 v22; // x19
  int v23; // w8
  int v24; // w8
  __int64 result; // x0
  const char *v26; // x4
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w20

  if ( a2 )
  {
    v12 = wmi_buf_alloc_fl(a1, 0x10u, "send_conf_hw_filter_cmd_tlv", 0x2C7u);
    if ( v12 )
    {
      v21 = *(_DWORD **)(v12 + 224);
      v22 = v12;
      *v21 = 40632332;
      v21[1] = *a2;
      v23 = a2[1];
      v21[2] = v23;
      if ( v23 == 1 )
        v24 = *((_DWORD *)a2 + 1);
      else
        v24 = -1;
      v21[3] = v24;
      if ( a2[1] )
        v26 = "enable";
      else
        v26 = "disable";
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Send %s hw filter mode: 0x%X for vdev id %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "send_conf_hw_filter_cmd_tlv",
        v26,
        *((unsigned int *)a2 + 1),
        *a2);
      wmi_mtrace(0x3B001u, v21[1], 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v22,
                 0x10u,
                 0x3B001u,
                 "send_conf_hw_filter_cmd_tlv",
                 0x2DEu,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34);
      if ( (_DWORD)result )
      {
        v43 = result;
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to configure hw filter %d",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "send_conf_hw_filter_cmd_tlv",
          (unsigned int)result);
        wmi_buf_free();
        return v43;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: req is null", a3, a4, a5, a6, a7, a8, a9, a10, "send_conf_hw_filter_cmd_tlv");
    return 4;
  }
  return result;
}
