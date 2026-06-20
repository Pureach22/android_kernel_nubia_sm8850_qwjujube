__int64 __fastcall kgsl_mmu_map_zero_page_to_range(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 (*v5)(void); // x8
  __int64 v6; // x20
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x9

  if ( (*(_BYTE *)(a2 + 76) & 4) == 0 || !*(_QWORD *)(a2 + 24) )
    return 4294967274LL;
  if ( result )
  {
    v4 = *(_QWORD *)(result + 96);
    if ( !v4 )
      return 0;
    v5 = *(__int64 (**)(void))(v4 + 16);
    if ( !v5 )
      return 0;
    v6 = result;
    if ( *((_DWORD *)v5 - 1) != -2009102421 )
      __break(0x8228u);
    result = v5();
    if ( !(_DWORD)result )
    {
      _X10 = (unsigned __int64 *)(v6 + 80);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v14 = __ldxr(_X10);
        v15 = v14 + a4;
      }
      while ( __stlxr(v15, _X10) );
      __dmb(0xBu);
      if ( v15 > *(_QWORD *)(v6 + 88) )
      {
        *(_QWORD *)(v6 + 88) = v15;
        return 0;
      }
      return 0;
    }
  }
  return result;
}
