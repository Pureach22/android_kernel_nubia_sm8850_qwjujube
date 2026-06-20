__int64 __fastcall wma_update_frag_params(
        __int64 result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  unsigned int v12; // w23
  unsigned __int8 v13; // w24

  if ( *(_WORD *)(result + 162) )
  {
    v10 = result;
    v12 = 0;
    v13 = 0;
    do
    {
      if ( *(_QWORD *)(*(_QWORD *)(v10 + 520) + 488LL * v13) )
      {
        result = wma_vdev_set_param(*(_QWORD *)v10, v12, 2u, a2, a3, a4, a5, a6, a7, a8, a9, a10);
        if ( (_DWORD)result )
          result = qdf_trace_msg(
                     0x36u,
                     2u,
                     "%s: Update cfg params failed for vdevId %d",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "wma_update_frag_params",
                     v12);
      }
      v12 = ++v13;
    }
    while ( *(unsigned __int16 *)(v10 + 162) > (unsigned int)v13 );
  }
  return result;
}
