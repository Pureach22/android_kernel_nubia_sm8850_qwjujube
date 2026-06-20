void *__fastcall sap_add_mac_to_acl(
        __int64 a1,
        _WORD *a2,
        const void *a3,
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
  __int64 v23; // x23
  __int64 v24; // x24
  __int64 v25; // x22
  bool v26; // cc
  void *result; // x0

  qdf_trace_msg(0x39u, 8u, "%s: add acl entered", a4, a5, a6, a7, a8, a9, a10, a11, "sap_add_mac_to_acl");
  v22 = (unsigned __int16)*a2;
  if ( !a1 || (unsigned int)v22 >= 0x21 )
    return (void *)qdf_trace_msg(
                     0x39u,
                     8u,
                     "%s: either buffer is NULL or size = %d is incorrect",
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     "sap_add_mac_to_acl",
                     v22);
  v23 = (unsigned int)(v22 - 1);
  if ( *a2 )
  {
    v24 = v23 + 1;
    v25 = a1 + 6LL * (unsigned int)v23;
    while ( (int)qdf_mem_cmp((const void *)v25, a3, 6u) >= 1 )
    {
      qdf_mem_copy((void *)(v25 + 6), (const void *)v25, 6u);
      v26 = v24-- <= 1;
      LODWORD(v23) = v23 - 1;
      v25 -= 6;
      if ( v26 )
      {
        LODWORD(v23) = -1;
        break;
      }
    }
  }
  result = qdf_mem_copy((void *)(a1 + 6LL * (int)v23 + 6), a3, 6u);
  ++*a2;
  return result;
}
