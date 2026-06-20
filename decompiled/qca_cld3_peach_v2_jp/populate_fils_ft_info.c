void *__fastcall populate_fils_ft_info(
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
  _BYTE *v11; // x20
  void *result; // x0

  v11 = *(_BYTE **)(a11 + 9976);
  if ( v11 )
  {
    if ( (v11[354] & 1) != 0 )
    {
      a10[2] = v11[355];
      qdf_mem_copy(a10 + 3, v11 + 356, 0x10u);
      qdf_mem_copy(a10 + 19, v11 + 372, 0x20u);
      qdf_mem_copy(a10 + 51, v11 + 404, 0x20u);
      if ( v11[442] )
      {
        a10[136] = 1;
        qdf_mem_copy(a10 + 138, v11 + 443, (unsigned __int8)v11[442]);
        a10[137] = v11[442];
      }
      a10[83] = 1;
      qdf_mem_copy(a10 + 84, v11 + 436, 6u);
      qdf_mem_copy(a10 + 90, v11 + 492, 0x2Eu);
      result = qdf_mem_copy(a10 + 186, v11 + 538, 0x22u);
      *a10 = 1;
    }
    else
    {
      *a10 = 0;
      return (void *)qdf_trace_msg(
                       0x35u,
                       2u,
                       "%s: FT IE doesn't exist",
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       "populate_fils_ft_info");
    }
  }
  return result;
}
