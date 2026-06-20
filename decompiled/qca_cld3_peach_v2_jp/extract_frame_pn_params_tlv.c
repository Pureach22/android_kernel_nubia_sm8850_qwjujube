__int64 __fastcall extract_frame_pn_params_tlv(
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  const char *v23; // x2

  if ( (is_service_enabled_tlv(a1, 0x149u, a4, a5, a6, a7, a8, a9, a10, a11) & 1) == 0 )
    return 0;
  if ( a2 )
  {
    if ( a3 )
    {
      v21 = *(_QWORD *)(a2 + 80);
      if ( v21 )
      {
        qdf_mem_copy((void *)a3, (const void *)(v21 + 4), 8u);
        qdf_mem_copy((void *)(a3 + 8), (const void *)(v21 + 12), 8u);
      }
      return 0;
    }
    v23 = "%s: PN Params is NULL";
  }
  else
  {
    v23 = "%s: Got NULL point message from FW";
  }
  qdf_trace_msg(0x31u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "extract_frame_pn_params_tlv");
  return 4;
}
