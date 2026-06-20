__int64 __fastcall dph_lookup_hash_entry(
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
  int v12; // w8
  int v13; // w9
  int v14; // w10
  int v15; // w11
  int v16; // w12
  int v17; // w13
  __int64 result; // x0

  if ( *(_QWORD *)a12 )
  {
    v12 = *a10;
    v13 = a10[1];
    v14 = a10[2];
    v15 = a10[3];
    v16 = a10[4];
    v17 = a10[5];
    result = *(_QWORD *)(*(_QWORD *)a12
                       + 8LL * ((v13 + v12 + v14 + v15 + v16 + v17) % (unsigned int)*(unsigned __int16 *)(a12 + 16)));
    if ( result )
    {
      while ( v12 != *(unsigned __int8 *)(result + 338)
           || v13 != *(unsigned __int8 *)(result + 339)
           || v14 != *(unsigned __int8 *)(result + 340)
           || v15 != *(unsigned __int8 *)(result + 341)
           || v16 != *(unsigned __int8 *)(result + 342)
           || v17 != *(unsigned __int8 *)(result + 343) )
      {
        result = *(_QWORD *)(result + 936);
        if ( !result )
          return result;
      }
      *a11 = *(_WORD *)(result + 336);
    }
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: pHashTable is NULL", a1, a2, a3, a4, a5, a6, a7, a8, "dph_lookup_hash_entry");
    return 0;
  }
  return result;
}
