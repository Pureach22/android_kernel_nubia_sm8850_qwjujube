__int64 __fastcall send_start_oemv2_data_cmd_tlv(
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
  unsigned __int64 v10; // x9
  __int16 v11; // w8
  __int64 v12; // x20
  __int64 result; // x0
  __int64 v14; // x20
  unsigned __int16 v15; // w22
  __int64 v16; // x20
  __int64 v19; // x0
  _DWORD *v20; // x23
  __int64 v21; // x19
  unsigned __int8 *v22; // x8
  __int64 v23; // x1
  __int64 v24; // x8
  __int64 (__fastcall *v25)(__int64, __int64); // x8
  int v26; // w0
  int v27; // w9
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w20
  __int64 v45; // x22

  if ( a2 && *((_QWORD *)a2 + 3) )
  {
    v10 = *((_QWORD *)a2 + 1);
    v11 = v10 + 3;
    if ( v10 > (((int)v10 + 3) & 0xFFFCuLL) )
    {
      v12 = jiffies;
      if ( send_start_oemv2_data_cmd_tlv___last_ticks_153 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: integer overflow while rounding up data_len",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "send_start_oemv2_data_cmd_tlv");
        send_start_oemv2_data_cmd_tlv___last_ticks_153 = v12;
        return 16;
      }
      return 16;
    }
    v15 = v11 & 0xFFFC;
    if ( (v11 & 0xFFFCu) >= 0x5FD )
    {
      v16 = jiffies;
      if ( send_start_oemv2_data_cmd_tlv___last_ticks_155 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: wmi_max_msg_size overflow for given data_len",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "send_start_oemv2_data_cmd_tlv");
        send_start_oemv2_data_cmd_tlv___last_ticks_155 = v16;
        return 16;
      }
      return 16;
    }
    v19 = wmi_buf_alloc_fl(a1, (unsigned __int16)(v15 + 24), "send_start_oemv2_data_cmd_tlv", 0x2025u);
    if ( v19 )
    {
      v20 = *(_DWORD **)(v19 + 224);
      v21 = v19;
      *v20 = 53608464;
      v22 = a2;
      v23 = a2[16];
      if ( a2[17] == 1 )
      {
        v24 = 3664;
        if ( a2[18] )
          v24 = 3704;
        v25 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + v24);
        if ( *((_DWORD *)v25 - 1) != -2112860426 )
          __break(0x8228u);
        v26 = v25(a1, v23);
        v22 = a2;
        LODWORD(v23) = v26;
      }
      v20[1] = *v22;
      v20[2] = *((_QWORD *)v22 + 1);
      v27 = v22[17];
      v20[5] = v15 | 0x110000;
      v20[3] = v27;
      v20[4] = v23;
      qdf_mem_copy(v20 + 6, *((const void **)v22 + 3), *((unsigned int *)v22 + 2));
      qdf_mtrace(49, 100, 0x1385u, 0xFFu, 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v21,
                 (unsigned __int16)(v15 + 24),
                 0x27005u,
                 "send_start_oemv2_data_cmd_tlv",
                 0x2047u,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35);
      if ( (_DWORD)result )
      {
        v44 = result;
        v45 = jiffies;
        if ( send_start_oemv2_data_cmd_tlv___last_ticks_157 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: Failed with ret = %d",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "send_start_oemv2_data_cmd_tlv",
            (unsigned int)result);
          send_start_oemv2_data_cmd_tlv___last_ticks_157 = v45;
        }
        wmi_buf_free();
        return v44;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    v14 = jiffies;
    if ( send_start_oemv2_data_cmd_tlv___last_ticks - jiffies + 125 >= 0 )
      return 16;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: oem data is not valid",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_start_oemv2_data_cmd_tlv");
    send_start_oemv2_data_cmd_tlv___last_ticks = v14;
    return 16;
  }
  return result;
}
