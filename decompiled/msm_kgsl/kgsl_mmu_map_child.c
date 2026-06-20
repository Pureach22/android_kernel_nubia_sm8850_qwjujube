__int64 __fastcall kgsl_mmu_map_child(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x8
  __int64 (*v7)(void); // x8
  __int64 v8; // x20
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x9

  if ( (*(_BYTE *)(a2 + 76) & 4) == 0 || !*(_QWORD *)(a2 + 24) )
    return 4294967274LL;
  if ( result )
  {
    v6 = *(_QWORD *)(result + 96);
    if ( !v6 )
      return 0;
    v7 = *(__int64 (**)(void))(v6 + 8);
    if ( !v7 )
      return 0;
    v8 = result;
    if ( *((_DWORD *)v7 - 1) != -1289449528 )
      __break(0x8228u);
    result = v7();
    if ( !(_DWORD)result )
    {
      _X10 = (unsigned __int64 *)(v8 + 80);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v16 = __ldxr(_X10);
        v17 = v16 + a6;
      }
      while ( __stlxr(v17, _X10) );
      __dmb(0xBu);
      if ( v17 > *(_QWORD *)(v8 + 88) )
      {
        *(_QWORD *)(v8 + 88) = v17;
        return 0;
      }
      return 0;
    }
  }
  return result;
}
