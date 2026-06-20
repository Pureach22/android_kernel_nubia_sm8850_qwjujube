__int64 __fastcall kgsl_count_hw_fences(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 v8; // x8
  unsigned __int64 v15; // x9
  unsigned __int64 v18; // x9
  unsigned __int64 v21; // x9

  v2 = *(_QWORD *)(result + 8);
  v3 = *(unsigned int *)(*(_QWORD *)(result + 40) + 14176LL);
  if ( (*(_QWORD *)(v2 + 128) & 1) == 0 )
  {
    if ( (*(_QWORD *)(a2 + 48) & 0x80000000) != 0
      || (*(_QWORD *)(a2 + 48) & 0x20000000) != 0
      || (v4 = *(_QWORD *)(a2 + 8), (_UNKNOWN *)v4 == &kgsl_sync_fence_ops) )
    {
      result = *(_QWORD *)(v2 + 144);
      if ( result || (v7 = a2, result = _kmalloc_noprof(16 * v3, 3520), a2 = v7, (*(_QWORD *)(v2 + 144) = result) != 0) )
      {
        v8 = *(unsigned int *)(v2 + 136);
        if ( (unsigned int)v8 >= (unsigned int)v3 )
        {
          _X8 = (unsigned __int64 *)(v2 + 128);
          __asm { PRFM            #0x11, [X8] }
          do
            v15 = __ldxr(_X8);
          while ( __stxr(v15 | 1, _X8) );
        }
        else
        {
          *(_DWORD *)(v2 + 136) = v8 + 1;
          *(_QWORD *)(result + 16 * v8) = a2;
        }
      }
      else
      {
        _X8 = (unsigned __int64 *)(v2 + 128);
        __asm { PRFM            #0x11, [X8] }
        do
          v18 = __ldxr(_X8);
        while ( __stxr(v18 | 1, _X8) );
      }
    }
    else if ( (*(_QWORD *)(a2 + 48) & 1) == 0 )
    {
      v5 = *(__int64 (__fastcall **)(_QWORD))(v4 + 32);
      if ( !v5 )
        goto LABEL_17;
      v6 = a2;
      if ( *((_DWORD *)v5 - 1) != 1879296680 )
        __break(0x8228u);
      result = v5(a2);
      if ( (result & 1) != 0 )
      {
        return dma_fence_signal(v6);
      }
      else
      {
LABEL_17:
        _X8 = (unsigned __int64 *)(v2 + 128);
        __asm { PRFM            #0x11, [X8] }
        do
          v21 = __ldxr(_X8);
        while ( __stxr(v21 | 1, _X8) );
      }
    }
  }
  return result;
}
