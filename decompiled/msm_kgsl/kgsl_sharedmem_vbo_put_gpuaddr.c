__int64 __fastcall kgsl_sharedmem_vbo_put_gpuaddr(__int64 a1)
{
  int v2; // w20
  char v3; // w23
  __int64 result; // x0
  __int64 v5; // x22
  unsigned int **v6; // x0
  __int64 v7; // x21
  unsigned int **v10; // x22
  unsigned int v16; // w10
  int v18; // w9
  __int64 v19; // x8
  __int64 (__fastcall *v20)(_QWORD); // x8

  if ( (*(_BYTE *)(a1 + 76) & 8) != 0 )
    v2 = 0;
  else
    v2 = kgsl_mmu_unmap_range(*(_QWORD *)a1, a1, 0, *(_QWORD *)(a1 + 40));
  v3 = v2 != 0;
  result = interval_tree_iter_first(a1 + 120, 0, -1);
  if ( result )
  {
    v5 = result;
    do
    {
      v7 = interval_tree_iter_next(v5, 0, -1);
      interval_tree_remove(v5, a1 + 120);
      if ( (*(_BYTE *)(a1 + 76) & 8) != 0 )
        v2 = kgsl_mmu_unmap_range(
               *(_QWORD *)a1,
               a1,
               *(_QWORD *)(v5 + 24),
               *(_QWORD *)(v5 + 32) - *(_QWORD *)(v5 + 24) + 1LL);
      v6 = (unsigned int **)(v5 - 8);
      if ( v2 )
        goto LABEL_7;
      _X8 = *v6;
      _X9 = *v6 + 93;
      __asm { PRFM            #0x11, [X9] }
      do
        v16 = __ldxr(_X9);
      while ( __stxr(v16 - 1, _X9) );
      if ( !_X8 || (unsigned __int64)_X8 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_7;
      __asm { PRFM            #0x11, [X8] }
      do
        v18 = __ldxr(_X8);
      while ( __stlxr(v18 - 1, _X8) );
      if ( v18 == 1 )
      {
        __dmb(9u);
        v10 = (unsigned int **)(v5 - 8);
        kgsl_mem_entry_destroy(_X8);
      }
      else
      {
        if ( v18 > 0 )
          goto LABEL_7;
        v10 = (unsigned int **)(v5 - 8);
        refcount_warn_saturate(_X8, 3);
      }
      v6 = v10;
LABEL_7:
      result = kfree(v6);
      v3 |= v2 != 0;
      v5 = v7;
    }
    while ( v7 );
  }
  if ( (v3 & 1) == 0 )
  {
    if ( *(_QWORD *)a1 )
    {
      v19 = *(_QWORD *)(*(_QWORD *)a1 + 96LL);
      if ( v19 )
      {
        v20 = *(__int64 (__fastcall **)(_QWORD))(v19 + 80);
        if ( v20 )
        {
          if ( *((_DWORD *)v20 - 1) != 1555154090 )
            __break(0x8228u);
          result = v20(a1);
        }
      }
    }
    *(_QWORD *)(a1 + 24) = 0;
    *(_QWORD *)a1 = 0;
  }
  return result;
}
