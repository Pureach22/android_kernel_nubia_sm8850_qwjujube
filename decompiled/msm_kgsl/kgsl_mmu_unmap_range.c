__int64 __fastcall kgsl_mmu_unmap_range(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 (*v5)(void); // x8
  __int64 v6; // x19
  unsigned __int64 v14; // x9

  if ( (*(_BYTE *)(a2 + 76) & 4) == 0 )
    return 4294967274LL;
  if ( result )
  {
    v4 = *(_QWORD *)(result + 96);
    if ( !v4 )
      return 0;
    v5 = *(__int64 (**)(void))(v4 + 32);
    if ( !v5 )
      return 0;
    v6 = result;
    if ( *((_DWORD *)v5 - 1) != -2009102421 )
      __break(0x8228u);
    result = v5();
    if ( !(_DWORD)result )
    {
      _X8 = (unsigned __int64 *)(v6 + 80);
      __asm { PRFM            #0x11, [X8] }
      do
        v14 = __ldxr(_X8);
      while ( __stxr(v14 - a4, _X8) );
      return 0;
    }
  }
  return result;
}
