unsigned __int64 __fastcall adreno_ib_add(__int64 a1, __int64 a2, int a3, int *a4)
{
  unsigned __int64 result; // x0
  int v7; // w11
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x12
  unsigned __int64 *v11; // x10
  __int64 v12; // x15
  unsigned __int64 v13; // x16
  unsigned __int64 v14; // x17
  bool v15; // w1
  unsigned __int64 v16; // x17
  unsigned __int64 v17; // x8
  __int64 v18; // x10
  unsigned int v21; // w9
  int v27; // w8

  if ( a4[2] > 999 )
    return 4294967289LL;
  result = kgsl_sharedmem_find(a1, a2);
  if ( result )
  {
    v7 = a4[2];
    v8 = *(_QWORD *)(result + 48);
    v9 = *(_QWORD *)(result + 32);
    if ( v7 < 1 )
      goto LABEL_24;
    v10 = v9 + v8;
    v11 = *(unsigned __int64 **)a4;
    v12 = (unsigned int)a4[2];
    while ( 1 )
    {
      if ( *((_DWORD *)v11 + 4) == a3 )
      {
        v13 = *v11;
        v14 = v11[1];
        v15 = __CFADD__(*v11, v14);
        if ( v8 <= ~v9 && !v15 && v10 > v13 )
        {
          v16 = v14 + v13;
          if ( v16 > v9 )
            break;
        }
      }
      --v12;
      v11 += 4;
      if ( !v12 )
        goto LABEL_24;
    }
    if ( v11 )
    {
      if ( v13 > v9 )
      {
        v13 = *(_QWORD *)(result + 32);
        *v11 = v9;
      }
      if ( v10 <= v16 )
        v17 = v16;
      else
        v17 = v9 + v8;
      v11[1] = v17 - v13;
      if ( result <= 0xFFFFFFFFFFFFF000LL )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v27 = __ldxr((unsigned int *)result);
        while ( __stlxr(v27 - 1, (unsigned int *)result) );
        if ( v27 == 1 )
        {
          __dmb(9u);
          kgsl_mem_entry_destroy();
        }
        else if ( v27 <= 0 )
        {
          refcount_warn_saturate(result, 3);
        }
      }
    }
    else
    {
LABEL_24:
      v18 = *(_QWORD *)a4 + 32LL * v7;
      *(_QWORD *)v18 = v9;
      *(_QWORD *)(v18 + 8) = v8;
      *(_DWORD *)(v18 + 16) = a3;
      *(_QWORD *)(v18 + 24) = result;
      ++a4[2];
      _X8 = (unsigned int *)(result + 56);
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 | 0x1000, _X8) );
    }
    return 0;
  }
  return result;
}
