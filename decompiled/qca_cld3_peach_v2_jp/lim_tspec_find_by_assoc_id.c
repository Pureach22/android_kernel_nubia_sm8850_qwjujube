__int64 __fastcall lim_tspec_find_by_assoc_id(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int16 a10,
        __int64 a11,
        __int64 a12,
        _QWORD *a13)
{
  int v13; // w22
  __int64 v17; // x23
  __int64 result; // x0

  *a13 = 0;
  v13 = a10;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Trying to find tspec entry for assocId: %d pTsInfo->traffic.direction: %d pTsInfo->traffic.tsid: %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "lim_tspec_find_by_assoc_id",
    a10,
    (*(unsigned __int16 *)(a11 + 3) >> 5) & 3,
    (*(unsigned __int16 *)(a11 + 3) >> 1) & 0xF);
  v17 = 0;
  do
  {
    if ( *(_BYTE *)(a12 + v17) )
    {
      if ( *(unsigned __int16 *)(a12 + v17 + 8) == v13 )
      {
        result = qdf_mem_cmp((const void *)a11, (const void *)(a12 + v17 + 10), 0x3Au);
        if ( !(_DWORD)result )
        {
          *a13 = a12 + v17;
          return result;
        }
      }
    }
    v17 += 163;
  }
  while ( (_DWORD)v17 != 2445 );
  return 16;
}
