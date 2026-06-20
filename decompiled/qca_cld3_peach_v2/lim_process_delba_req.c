__int64 __fastcall lim_process_delba_req(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 **context; // x0
  __int64 v15; // x24
  __int64 v16; // x26
  __int64 **v17; // x21
  unsigned int v18; // w22
  __int64 result; // x0
  __int64 v20; // x19
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  unsigned int (__fastcall *v31)(__int64 **, __int64, __int64, __int64, __int64); // x8
  __int64 v32; // x2
  __int64 v33; // x4
  __int64 v34; // x3
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x21

  context = (__int64 **)_cds_get_context(71, (__int64)"lim_process_delba_req", a4, a5, a6, a7, a8, a9, a10, a11);
  v16 = *(_QWORD *)(a2 + 16);
  v15 = *(_QWORD *)(a2 + 24);
  v17 = context;
  v18 = *(_DWORD *)(a2 + 40);
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, v15, v18);
  result = _qdf_mem_malloc(6u, "lim_process_delba_req", 1902);
  if ( result )
  {
    v20 = result;
    v21 = dot11f_unpack_delba_req(a1, v15, v18, result, 0);
    if ( (v21 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to unpack and parse (0x%08x, %d bytes)",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "lim_process_delba_req",
        v21,
        v18);
    }
    else
    {
      if ( v21 )
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: warning: unpack addba Req(0x%08x, %d bytes)",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "lim_process_delba_req",
          v21,
          v18);
      if ( v17 && *v17 )
      {
        v30 = **v17;
        if ( v30 )
        {
          v31 = *(unsigned int (__fastcall **)(__int64 **, __int64, __int64, __int64, __int64))(v30 + 456);
          if ( v31 )
          {
            v32 = *(unsigned __int8 *)(a3 + 10);
            v33 = *(unsigned __int16 *)(v20 + 4);
            v34 = *(unsigned __int16 *)(v20 + 2) >> 12;
            if ( *((_DWORD *)v31 - 1) != -1625683282 )
              __break(0x8228u);
            if ( v31(v17, v16 + 10, v32, v34, v33) )
            {
              v43 = jiffies;
              if ( lim_process_delba_req___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Failed to process delba request",
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  "lim_process_delba_req");
                lim_process_delba_req___last_ticks = v43;
              }
            }
          }
        }
      }
      else
      {
        qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v22, v23, v24, v25, v26, v27, v28, v29, "cdp_delba_process");
      }
    }
    return _qdf_mem_free(v20);
  }
  return result;
}
