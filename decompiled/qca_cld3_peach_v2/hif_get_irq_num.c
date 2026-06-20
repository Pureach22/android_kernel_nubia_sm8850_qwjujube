__int64 __fastcall hif_get_irq_num(
        __int64 a1,
        _DWORD *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 result; // x0
  __int64 v15; // x8
  __int64 i; // x9

  result = 4294967274LL;
  if ( a2 && a3 )
  {
    v15 = a1 + 28672;
    result = *(unsigned int *)(v15 + 2104);
    if ( (unsigned int)result > 1 )
    {
      if ( (unsigned int)result <= a3 )
      {
        if ( (int)result >= 1 )
        {
          for ( i = 0; i < result; ++i )
          {
            a2[i] = i + *(_DWORD *)(v15 + 2224) + 1;
            result = *(int *)(v15 + 2104);
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Not enough space in irq buffer to return irqs",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "hif_get_irq_num",
          v11,
          v12);
        return 4294967274LL;
      }
    }
    else
    {
      *a2 = *(_DWORD *)(v15 + 2224);
      return 1;
    }
  }
  return result;
}
