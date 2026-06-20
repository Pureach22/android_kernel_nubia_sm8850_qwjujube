__int64 __fastcall kgsl_mmu_unmap(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x9
  __int64 (*v5)(void); // x9
  __int64 v6; // x22
  unsigned __int64 v8; // x20
  __int64 v9; // x8
  unsigned int v16; // w11
  unsigned __int64 v19; // x11
  unsigned int v22; // w10

  v2 = *(_QWORD *)(a2 + 40);
  if ( !v2 )
    return 4294967274LL;
  if ( (*(_BYTE *)(a2 + 76) & 4) != 0 )
    return 4294967274LL;
  v3 = *(_QWORD *)(result + 112);
  if ( (*(_DWORD *)(a2 + 48) & 8) == 0 )
    return 4294967274LL;
  if ( result )
  {
    v4 = *(_QWORD *)(result + 96);
    if ( !v4 )
      return 0;
    v5 = *(__int64 (**)(void))(v4 + 24);
    if ( !v5 )
      return 0;
    v6 = result;
    if ( (*(_DWORD *)(a2 + 48) & 1) != 0 )
      v8 = (v2 + 0x1FFF) & 0xFFFFFFFFFFFFF000LL;
    else
      v8 = *(_QWORD *)(a2 + 40);
    if ( *((_DWORD *)v5 - 1) != -1528462336 )
      __break(0x8229u);
    result = v5();
    if ( !(_DWORD)result )
    {
      _X8 = (unsigned int *)(v6 + 72);
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr(_X8);
      while ( __stxr(v16 - 1, _X8) );
      v9 = a2;
      _X10 = (unsigned __int64 *)(v6 + 80);
      __asm { PRFM            #0x11, [X10] }
      do
        v19 = __ldxr(_X10);
      while ( __stxr(v19 - v8, _X10) );
      if ( *(_DWORD *)(v6 + 24) >= 2u )
      {
        trace_gpu_mem_total();
        v9 = a2;
      }
      if ( !v9 || (*(_DWORD *)(v9 + 48) & 2) == 0 )
      {
        _X9 = (unsigned int *)(v9 + 48);
        __asm { PRFM            #0x11, [X9] }
        do
          v22 = __ldxr(_X9);
        while ( __stxr(v22 & 0xFFFFFFF7, _X9) );
        if ( (*(_BYTE *)(v9 + 72) & 0x80) == 0 )
          kgsl_trace_gpu_mem_total(v3 - 56, -(__int64)v8);
      }
      return 0;
    }
  }
  return result;
}
