void *__fastcall sap_remove_mac_from_acl(
        __int64 a1,
        _WORD *a2,
        unsigned __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x4
  __int64 v23; // x22
  __int64 v24; // x0
  __int64 v25; // x21
  void *result; // x0

  qdf_trace_msg(0x39u, 8u, "%s: remove acl entered", a4, a5, a6, a7, a8, a9, a10, a11, "sap_remove_mac_from_acl");
  v22 = (unsigned __int16)*a2;
  if ( !a1 || (unsigned int)(v22 - 33) <= 0xFFFFFFDF )
    return (void *)qdf_trace_msg(
                     0x39u,
                     2u,
                     "%s: either buffer is NULL or size %d is incorrect",
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     "sap_remove_mac_from_acl",
                     v22);
  if ( (int)v22 - 1 > (unsigned int)a3 )
  {
    v23 = a3;
    v24 = a1 + 6LL * a3;
    do
    {
      v25 = v24 + 6;
      qdf_mem_copy((void *)v24, (const void *)(v24 + 6), 6u);
      v22 = (unsigned __int16)*a2;
      ++v23;
      v24 = v25;
    }
    while ( v23 < v22 - 1 );
  }
  result = qdf_mem_set((void *)(a1 + 6LL * (unsigned int)v22 - 6), 6u, 0);
  --*a2;
  return result;
}
