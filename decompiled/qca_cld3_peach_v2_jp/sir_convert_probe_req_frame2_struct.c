__int64 __fastcall sir_convert_probe_req_frame2_struct(__int64 a1, __int64 a2, unsigned int a3, _BYTE *a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _BYTE *v17; // x19
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v39; // x21

  v8 = _qdf_mem_malloc(0x488u, "sir_convert_probe_req_frame2_struct", 2869);
  if ( !v8 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: malloc failed for probe request",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "sir_convert_probe_req_frame2_struct");
    return 16;
  }
  v17 = (_BYTE *)v8;
  qdf_mem_set(a4, 0x1C4u, 0);
  v21 = dot11f_unpack_probe_request(a1, a2, a3, (__int64)v17, 0, v18, v19, v20);
  if ( (v21 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to parse a Probe Request (0x%08x, %d bytes):",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sir_convert_probe_req_frame2_struct",
      v21,
      a3);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, a2, a3);
LABEL_9:
    _qdf_mem_free((__int64)v17);
    return 16;
  }
  if ( v21 )
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: There were warnings while unpacking a Probe Request (0x%08x, %d bytes):",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sir_convert_probe_req_frame2_struct",
      v21,
      a3);
  if ( *v17 )
  {
    a4[368] = 1;
    convert_ssid(a1, a4, v17);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Mandatory IE SSID not present!",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sir_convert_probe_req_frame2_struct");
  }
  if ( !v17[34] )
  {
    v39 = jiffies;
    if ( sir_convert_probe_req_frame2_struct___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Mandatory IE Supported Rates not present!",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "sir_convert_probe_req_frame2_struct");
      sir_convert_probe_req_frame2_struct___last_ticks = v39;
    }
    goto LABEL_9;
  }
  a4[369] = 1;
  convert_supp_rates(a1, a4 + 34, v17 + 34);
  if ( v17[305] )
  {
    a4[370] = 1;
    convert_ext_supp_rates(a1, a4 + 47, v17 + 305);
  }
  if ( v17[324] )
    qdf_mem_copy(a4 + 308, v17 + 324, 0x3Cu);
  if ( v17[836] )
  {
    a4[371] = 1;
    memcpy(a4 + 60, v17 + 836, 0xF6u);
  }
  if ( v17[404] )
    qdf_mem_copy(a4 + 376, v17 + 404, 0x10u);
  if ( v17[1086] )
    a4[372] = 1;
  if ( v17[420] )
    qdf_mem_copy(a4 + 392, v17 + 420, 0x3Cu);
  _qdf_mem_free((__int64)v17);
  return 0;
}
