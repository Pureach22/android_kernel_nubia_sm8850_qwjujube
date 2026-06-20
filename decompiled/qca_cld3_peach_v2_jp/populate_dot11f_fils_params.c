void *__fastcall populate_dot11f_fils_params(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _BYTE *a10,
        __int64 a11)
{
  unsigned __int8 *v11; // x20
  size_t v13; // x2
  void *result; // x0
  size_t v15; // x2

  v11 = *(unsigned __int8 **)(a11 + 9976);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: FILS RSN IE length %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "populate_dot11f_fils_rsn",
    v11[95]);
  if ( v11[95] )
  {
    a10[167] = 1;
    v13 = v11[95];
    a10[168] = v13;
    qdf_mem_copy(a10 + 169, v11 + 96, v13);
  }
  a10[570] = 1;
  result = qdf_mem_copy(a10 + 571, v11 + 70, 8u);
  if ( v11[1020] )
  {
    a10[837] = 1;
    v15 = v11[1020];
    a10[838] = v15;
    return qdf_mem_copy(a10 + 839, v11 + 972, v15);
  }
  return result;
}
