__int64 __fastcall _lim_process_neighbor_report(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x22
  unsigned int v5; // w20
  __int64 result; // x0
  __int64 v8; // x19
  unsigned int v9; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  v4 = *(_QWORD *)(a2 + 24);
  v5 = *(_DWORD *)(a2 + 40);
  result = _qdf_mem_malloc(0x2022u, "__lim_process_neighbor_report", 1375);
  if ( result )
  {
    v8 = result;
    if ( a3 )
    {
      v9 = dot11f_unpack_neighbor_report_response(a1, v4, v5, result, 0);
      if ( (v9 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to unpack and parse a Neighbor report response (0x%08x, %d bytes):",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "__lim_process_neighbor_report",
          v9,
          v5);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, v4, v5);
      }
      else
      {
        if ( v9 )
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: There were warnings while unpacking a Neighbor report response (0x%08x, %d bytes):",
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            "__lim_process_neighbor_report",
            v9,
            v5);
        rrm_process_neighbor_report_response(a1, v8, a3);
      }
    }
    return _qdf_mem_free(v8);
  }
  return result;
}
