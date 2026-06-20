__int64 __fastcall lim_copy_and_free_hlp_data_from_session(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x9
  const void *v11; // x3
  __int64 v12; // x19

  v10 = *(_QWORD *)(result + 9976);
  v11 = *(const void **)(v10 + 1608);
  if ( v11 )
  {
    if ( *(_WORD *)(v10 + 1602) )
    {
      v12 = result;
      cds_copy_hlp_info(
        (int *)(v10 + 1589),
        (int *)(v10 + 1595),
        *(_WORD *)(v10 + 1602),
        v11,
        a2 + 393,
        a2 + 399,
        (unsigned __int16 *)(a2 + 406),
        (void *)(a2 + 408),
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10);
      result = _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v12 + 9976) + 1608LL));
      *(_QWORD *)(*(_QWORD *)(v12 + 9976) + 1608LL) = 0;
      *(_WORD *)(*(_QWORD *)(v12 + 9976) + 1602LL) = 0;
    }
  }
  return result;
}
