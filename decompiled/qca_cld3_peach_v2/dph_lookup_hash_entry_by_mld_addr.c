__int64 __fastcall dph_lookup_hash_entry_by_mld_addr(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10,
        _WORD *a11,
        __int64 a12)
{
  __int64 v12; // x10
  __int64 result; // x0

  if ( !*(_QWORD *)a12 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: pHashTable is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "dph_lookup_hash_entry_by_mld_addr");
    return 0;
  }
  if ( !*(_WORD *)(a12 + 16) )
    return 0;
  v12 = 0;
  while ( 1 )
  {
    result = *(_QWORD *)(*(_QWORD *)a12 + 8 * v12);
    if ( result )
      break;
LABEL_4:
    if ( ++v12 == *(unsigned __int16 *)(a12 + 16) )
      return 0;
  }
  while ( *a10 != *(unsigned __int8 *)(result + 1080)
       || a10[1] != *(unsigned __int8 *)(result + 1081)
       || a10[2] != *(unsigned __int8 *)(result + 1082)
       || a10[3] != *(unsigned __int8 *)(result + 1083)
       || a10[4] != *(unsigned __int8 *)(result + 1084)
       || a10[5] != *(unsigned __int8 *)(result + 1085) )
  {
    result = *(_QWORD *)(result + 1072);
    if ( !result )
      goto LABEL_4;
  }
  *a11 = *(_WORD *)(result + 348);
  return result;
}
