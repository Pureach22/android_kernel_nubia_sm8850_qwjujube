__int64 __fastcall kgsl_mmu_map(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 (**v4)(void); // x8
  __int64 (*v5)(void); // x8
  __int64 v6; // x22
  __int64 v8; // x8
  unsigned int v15; // w10
  unsigned __int64 v18; // x10
  unsigned __int64 v19; // x10
  unsigned int v22; // w9

  if ( !*(_QWORD *)(a2 + 24) )
    return 4294967274LL;
  v2 = *(_QWORD *)(result + 112);
  if ( (!a2 || (*(_DWORD *)(a2 + 48) & 2) == 0) && (*(_DWORD *)(a2 + 48) & 8) != 0 )
    return 4294967274LL;
  if ( (*(_BYTE *)(a2 + 76) & 4) != 0 )
    return 4294967274LL;
  if ( (*(_DWORD *)(a2 + 48) & 1) != 0 )
    LODWORD(v3) = (*(_QWORD *)(a2 + 40) + 0x1FFF) & 0xFFFFF000;
  else
    v3 = *(_QWORD *)(a2 + 40);
  if ( result )
  {
    v4 = *(__int64 (***)(void))(result + 96);
    if ( !v4 )
      return 0;
    v5 = *v4;
    if ( !v5 )
      return 0;
    v6 = result;
    if ( *((_DWORD *)v5 - 1) != -1528462336 )
      __break(0x8228u);
    result = v5();
    if ( !(_DWORD)result )
    {
      _X8 = (unsigned int *)(v6 + 72);
      __asm { PRFM            #0x11, [X8] }
      do
        v15 = __ldxr(_X8);
      while ( __stxr(v15 + 1, _X8) );
      v8 = a2;
      _X11 = (unsigned __int64 *)(v6 + 80);
      __asm { PRFM            #0x11, [X11] }
      do
      {
        v18 = __ldxr(_X11);
        v19 = v18 + (int)v3;
      }
      while ( __stlxr(v19, _X11) );
      __dmb(0xBu);
      if ( v19 > *(_QWORD *)(v6 + 88) )
        *(_QWORD *)(v6 + 88) = v19;
      if ( *(_DWORD *)(v6 + 24) >= 2u )
      {
        trace_gpu_mem_total();
        v8 = a2;
      }
      if ( (!v8 || (*(_DWORD *)(v8 + 48) & 2) == 0) && (*(_BYTE *)(v8 + 72) & 0x80) == 0 )
      {
        kgsl_trace_gpu_mem_total(v2 - 56, (int)v3);
        v8 = a2;
      }
      _X8 = (unsigned int *)(v8 + 48);
      __asm { PRFM            #0x11, [X8] }
      do
        v22 = __ldxr(_X8);
      while ( __stxr(v22 | 8, _X8) );
      return 0;
    }
  }
  return result;
}
