__int64 __fastcall syncobj_timer(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w8
  unsigned int v5; // w21
  unsigned int v11; // w9
  __int64 v12; // x8
  __int64 v14; // x20
  _QWORD *v15; // x25
  unsigned __int64 v16; // x21
  __int64 v17; // x8
  int v18; // w9
  __int64 v19; // x28
  __int64 v20; // x24
  __int64 v21; // x23
  __int64 v22; // x0
  __int64 v23; // x28
  const char *v24; // x3
  __int64 v25; // x23
  __int64 (*v26)(void); // x8
  char v27; // w0
  const char *v28; // x8
  int v29; // w2
  int v30; // w24
  __int64 v31; // x8
  __int64 v32; // x22
  int v34; // w8
  int v36; // w9
  __int64 (__fastcall *v37)(_QWORD); // x8
  unsigned __int64 v40; // x9
  unsigned __int64 v43; // x10

  result = a1 - 80;
  if ( !result )
    return result;
  _X20 = (unsigned int *)(a1 - 48);
  v3 = *(_DWORD *)(a1 - 48);
  if ( v3 )
  {
    do
    {
      __asm { PRFM            #0x11, [X20] }
      do
        v11 = __ldxr(_X20);
      while ( v11 == v3 && __stxr(v3 + 1, _X20) );
      v5 = v3;
      if ( v11 == v3 )
        break;
      v5 = 0;
      v3 = v11;
    }
    while ( v11 );
  }
  else
  {
    v5 = 0;
  }
  if ( (((v5 + 1) | v5) & 0x80000000) != 0 )
  {
    v32 = result;
    refcount_warn_saturate(a1 - 48, 0);
    result = v32;
    if ( !v5 )
      return result;
  }
  else if ( !v5 )
  {
    return result;
  }
  v12 = *(_QWORD *)(a1 - 72);
  if ( !v12 )
  {
    __asm { PRFM            #0x11, [X20] }
    do
      v34 = __ldxr(_X20);
    while ( __stlxr(v34 - 1, _X20) );
    if ( v34 != 1 )
    {
      if ( v34 <= 0 )
        return refcount_warn_saturate(a1 - 48, 3);
      return result;
    }
    __dmb(9u);
    _X8 = *(unsigned int **)(a1 - 72);
    if ( !_X8 )
      goto LABEL_57;
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr(_X8);
    while ( __stlxr(v36 - 1, _X8) );
    if ( v36 == 1 )
    {
      __dmb(9u);
      v14 = result;
      kgsl_context_destroy((__int64)_X8);
    }
    else
    {
      if ( v36 > 0 )
        goto LABEL_57;
      v14 = result;
      refcount_warn_saturate(_X8, 3);
    }
    result = v14;
LABEL_57:
    v37 = *(__int64 (__fastcall **)(_QWORD))(a1 - 32);
    if ( *((_DWORD *)v37 - 1) != 287870130 )
      __break(0x8228u);
    return v37(result);
  }
  v15 = *(_QWORD **)(v12 + 40);
  dev_err(
    *v15,
    "kgsl: possible gpu syncpoint deadlock for context %u timestamp %u\n",
    *(_DWORD *)(v12 + 4),
    *(_DWORD *)(a1 - 60));
  _X8 = (unsigned __int64 *)(*(_QWORD *)(a1 - 72) + 32LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v40 = __ldxr(_X8);
  while ( __stxr(v40 | 0x400000, _X8) );
  kgsl_context_dump(*(unsigned int **)(a1 - 72));
  _X8 = (unsigned __int64 *)(*(_QWORD *)(a1 - 72) + 32LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v43 = __ldxr(_X8);
  while ( __stxr(v43 & 0xFFFFFFFFFFBFFFFFLL, _X8) );
  dev_err(*v15, "      pending events:\n");
  if ( *(_DWORD *)(a1 - 16) )
  {
    v16 = 0;
    do
    {
      if ( v16 <= 0x1F && ((*(_QWORD *)(a1 - 8) >> v16) & 1) != 0 )
      {
        v17 = *(_QWORD *)(a1 - 24) + 120 * v16;
        v18 = *(_DWORD *)(v17 + 4);
        switch ( v18 )
        {
          case 1:
            v19 = *(_QWORD *)(v17 + 48);
            if ( v19 && *(int *)(v19 + 8) >= 1 )
            {
              v20 = 0;
              v21 = 0;
              do
              {
                dev_err(*v15, "       [%u] FENCE %s\n", v16, (const char *)(*(_QWORD *)v19 + v20));
                ++v21;
                v20 += 74;
              }
              while ( v21 < *(int *)(v19 + 8) );
            }
            break;
          case 2:
            v23 = *(_QWORD *)(v17 + 48);
            v22 = *(_QWORD *)(v17 + 56);
            v24 = "not retired";
            v25 = *(_QWORD *)(v22 + 48);
            v26 = *(__int64 (**)(void))(*(_QWORD *)(v22 + 8) + 32LL);
            if ( v26 )
            {
              if ( *((_DWORD *)v26 - 1) != 1879296680 )
                __break(0x8228u);
              v27 = v26();
              v28 = "signaled";
              if ( (v25 & 1) == 0 )
                v28 = "retired but not signaled";
              if ( (v27 & 1) != 0 )
                v24 = v28;
              else
                v24 = "not retired";
            }
            dev_err(*v15, "       [%u] FENCE %s\n", v16, v24);
            if ( v23 )
            {
              v29 = *(_DWORD *)(v23 + 8);
              if ( v29 )
              {
                v30 = 1;
                v31 = v23;
                do
                {
                  dev_err(*v15, "       TIMELINE %d SEQNO %lld\n", v29, *(_QWORD *)v31);
                  v31 = v23 + 16LL * v30++;
                  v29 = *(_DWORD *)(v31 + 8);
                }
                while ( v29 );
              }
            }
            break;
          case 0:
            dev_err(
              *v15,
              "       [%u] TIMESTAMP %u:%u\n",
              v16,
              *(_DWORD *)(*(_QWORD *)(v17 + 16) + 4LL),
              *(_DWORD *)(v17 + 24));
            break;
        }
      }
      ++v16;
    }
    while ( v16 < *(unsigned int *)(a1 - 16) );
  }
  kref_put(a1 - 48, kgsl_drawobj_destroy_object);
  return dev_err(*v15, "--gpu syncpoint deadlock print end--\n");
}
