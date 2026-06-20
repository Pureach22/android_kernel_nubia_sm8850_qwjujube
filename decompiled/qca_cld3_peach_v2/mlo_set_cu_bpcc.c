__int64 __fastcall mlo_set_cu_bpcc(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 result; // x0
  unsigned __int8 *v13; // x8

  v11 = *(_QWORD *)(a1 + 1360);
  if ( !v11 )
  {
    qdf_trace_msg(0x8Fu, 8u, "%s: ML dev ctx is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "mlo_set_cu_bpcc");
    return 4;
  }
  if ( a2 == 255 )
  {
    qdf_trace_msg(0x8Fu, 8u, "%s: Invalid link_id %d", a4, a5, a6, a7, a8, a9, a10, a11, "mlo_set_cu_bpcc", 255);
    return 4;
  }
  v13 = *(unsigned __int8 **)(v11 + 3880);
  if ( v13[6] != a2 )
  {
    if ( v13[54] == a2 )
    {
      v13 += 48;
    }
    else
    {
      if ( v13[102] != a2 )
        return 4;
      v13 += 96;
    }
  }
  result = 0;
  v13[7] = a3;
  return result;
}
