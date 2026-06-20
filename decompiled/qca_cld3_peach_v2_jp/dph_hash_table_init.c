void __fastcall dph_hash_table_init(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  __int64 v3; // x8
  unsigned __int64 v4; // x9
  __int64 v5; // x10

  if ( *(_WORD *)(a2 + 16) )
  {
    v2 = 0;
    do
      *(_QWORD *)(*(_QWORD *)a2 + 8 * v2++) = 0;
    while ( v2 < *(unsigned __int16 *)(a2 + 16) );
    if ( *(_WORD *)(a2 + 16) )
    {
      v3 = 0;
      v4 = 0;
      do
      {
        *(_WORD *)(*(_QWORD *)(a2 + 8) + v3) &= ~1u;
        *(_WORD *)(*(_QWORD *)(a2 + 8) + v3) &= ~8u;
        v5 = *(_QWORD *)(a2 + 8) + v3;
        v3 += 952;
        *(_WORD *)(v5 + 336) = v4++;
      }
      while ( v4 < *(unsigned __int16 *)(a2 + 16) );
    }
  }
}
