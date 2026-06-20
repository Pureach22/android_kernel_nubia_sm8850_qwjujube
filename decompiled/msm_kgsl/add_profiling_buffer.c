unsigned __int64 __fastcall add_profiling_buffer(
        unsigned __int64 result,
        __int64 a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        unsigned int a5,
        __int64 a6)
{
  _QWORD *v6; // x23
  unsigned __int64 v10; // x0
  unsigned int v11; // w20
  unsigned __int64 v13; // x5
  __int64 v14; // x4
  _QWORD *v15; // x8
  _QWORD *v16; // x9
  unsigned __int64 v17; // x10
  __int64 v19; // x12
  unsigned __int64 v20; // x11
  unsigned __int64 v21; // x14
  unsigned __int64 v22; // x12
  unsigned __int64 v23; // x24
  int v29; // w10

  if ( (*(_BYTE *)(a2 + 24) & 0x10) != 0 && !*(_QWORD *)(a2 + 128) )
  {
    v6 = (_QWORD *)result;
    v10 = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 24LL);
    if ( a5 )
    {
      v11 = a5;
      result = (unsigned __int64)kgsl_sharedmem_find_id(v10, a5);
      v13 = a3;
      v14 = a6;
      v15 = (_QWORD *)a2;
      v16 = v6;
      if ( !result )
        return dev_err(
                 *v16,
                 "ignore bad profile buffer ctxt %u id %d offset %lld gpuaddr %llx size %lld\n",
                 *(_DWORD *)(v15[1] + 4LL),
                 v11,
                 v14,
                 v13,
                 a4);
      v17 = *(_QWORD *)(result + 32) + a6;
    }
    else
    {
      v11 = 0;
      result = kgsl_sharedmem_find(v10, a3);
      v13 = a3;
      v17 = a3;
      v14 = a6;
      v15 = (_QWORD *)a2;
      v16 = v6;
      if ( !result )
        return dev_err(
                 *v16,
                 "ignore bad profile buffer ctxt %u id %d offset %lld gpuaddr %llx size %lld\n",
                 *(_DWORD *)(v15[1] + 4LL),
                 v11,
                 v14,
                 v13,
                 a4);
    }
    if ( result + 8 <= 0xFFFFFFFFFFFFF000LL )
    {
      v19 = a4 <= 1 ? 1LL : a4;
      if ( !__CFADD__(v13, v19) )
      {
        v20 = *(_QWORD *)(result + 32);
        if ( v20 <= v13 )
        {
          v21 = v19 + v13;
          v22 = *(_QWORD *)(result + 48) + v20;
          if ( v21 <= v22 && v17 <= 0xFFFFFFFFFFFFFFD7LL && v20 <= v17 && v17 + 40 <= v22 )
          {
            v15[16] = result;
            v15[17] = v17;
            return result;
          }
        }
      }
    }
    if ( result > 0xFFFFFFFFFFFFF000LL )
      return dev_err(
               *v16,
               "ignore bad profile buffer ctxt %u id %d offset %lld gpuaddr %llx size %lld\n",
               *(_DWORD *)(v15[1] + 4LL),
               v11,
               v14,
               v13,
               a4);
    __asm { PRFM            #0x11, [X0] }
    do
      v29 = __ldxr((unsigned int *)result);
    while ( __stlxr(v29 - 1, (unsigned int *)result) );
    if ( v29 == 1 )
    {
      __dmb(9u);
      v23 = v13;
      kgsl_mem_entry_destroy((_QWORD *)result);
    }
    else
    {
      if ( v29 > 0 )
        return dev_err(
                 *v16,
                 "ignore bad profile buffer ctxt %u id %d offset %lld gpuaddr %llx size %lld\n",
                 *(_DWORD *)(v15[1] + 4LL),
                 v11,
                 v14,
                 v13,
                 a4);
      v23 = v13;
      refcount_warn_saturate(result, 3);
    }
    v16 = v6;
    v15 = (_QWORD *)a2;
    v13 = v23;
    v14 = a6;
    return dev_err(
             *v16,
             "ignore bad profile buffer ctxt %u id %d offset %lld gpuaddr %llx size %lld\n",
             *(_DWORD *)(v15[1] + 4LL),
             v11,
             v14,
             v13,
             a4);
  }
  return result;
}
