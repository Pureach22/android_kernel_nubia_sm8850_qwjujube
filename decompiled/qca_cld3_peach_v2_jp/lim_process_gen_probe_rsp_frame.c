__int64 __fastcall lim_process_gen_probe_rsp_frame(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  unsigned int v26; // w20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // [xsp+0h] [xbp-10h]

  if ( !a3 || !a4 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: bcn_probe is null or invalid len %d",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "lim_process_gen_probe_rsp_frame",
             a4);
  if ( !a2 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: session_entry is NULL",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "lim_process_gen_probe_rsp_frame");
  result = _qdf_mem_malloc(0xD80u, "lim_process_gen_probe_rsp_frame", 184);
  if ( result )
  {
    v25 = result;
    v35 = a3[21];
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Generate Probe Resp for cu (len %d): %02x:%02x:%02x:**:**:%02x",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_process_gen_probe_rsp_frame",
      a4,
      a3[16],
      a3[17],
      a3[18],
      v35);
    ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(53, 8, a3, a4);
    v26 = a4 - 24;
    if ( (unsigned int)sir_convert_probe_frame2_struct(a1, (int)a3 + 24, v26, v25) || !*(_BYTE *)(v25 + 2460) )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Parse error ProbeResponse, length=%d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "lim_process_gen_probe_rsp_frame",
        v26);
    else
      lim_process_updated_ies_in_probe_rsp(a1, a2, v25);
    return _qdf_mem_free(v25);
  }
  return result;
}
