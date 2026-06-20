unsigned int *__fastcall syncobj_destroy(_DWORD *a1)
{
  unsigned int *result; // x0
  __int64 v3; // x22
  unsigned __int64 v4; // x23
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x27
  int v9; // w9
  __int64 v10; // x27
  __int64 v12; // x8
  unsigned __int64 v19; // x10
  int v21; // w8
  int v23; // w8
  int v25; // w8
  int v28; // w8
  __int64 (__fastcall *v30)(_QWORD); // x8
  __int64 (*v31)(void); // x8

  result = (unsigned int *)timer_delete_sync(a1 + 20);
  if ( a1[16] )
  {
    v3 = 0;
    v4 = 0;
    _X20 = a1 + 8;
    while ( 1 )
    {
      v6 = *((_QWORD *)a1 + 7);
      v7 = 1LL << v4;
      _X11 = (unsigned __int64 *)&a1[2 * (v4 >> 6) + 18];
      __asm { PRFM            #0x11, [X11] }
      do
        v19 = __ldxr(_X11);
      while ( __stlxr(v19 & ~v7, _X11) );
      __dmb(0xBu);
      if ( (v19 & v7) == 0 )
        goto LABEL_4;
      v8 = v6 + v3;
      v9 = *(_DWORD *)(v6 + v3 + 4);
      if ( v9 == 2 )
        break;
      if ( v9 != 1 )
      {
        if ( v9 )
          goto LABEL_4;
        v10 = v6 + v3;
        kgsl_cancel_event(
          *(_QWORD *)a1,
          *(_QWORD *)(v6 + v3 + 16) + 64LL,
          *(unsigned int *)(v6 + v3 + 24),
          drawobj_sync_func,
          v6 + v3);
        result = *(unsigned int **)(v10 + 16);
        if ( !result )
          goto LABEL_4;
        __asm { PRFM            #0x11, [X0] }
        do
          v21 = __ldxr(result);
        while ( __stlxr(v21 - 1, result) );
        if ( v21 == 1 )
        {
          __dmb(9u);
          result = (unsigned int *)kgsl_context_destroy((__int64)result);
        }
        else if ( v21 <= 0 )
        {
          goto LABEL_28;
        }
        goto LABEL_4;
      }
      result = (unsigned int *)kgsl_sync_fence_async_cancel(*(_QWORD *)(v6 + v3 + 32));
      if ( !a1 )
        goto LABEL_4;
      __asm { PRFM            #0x11, [X20] }
      do
        v23 = __ldxr(_X20);
      while ( __stlxr(v23 - 1, _X20) );
      if ( v23 == 1 )
      {
        __dmb(9u);
        _X0 = *((unsigned int **)a1 + 1);
        if ( _X0 )
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v28 = __ldxr(_X0);
          while ( __stlxr(v28 - 1, _X0) );
          if ( v28 == 1 )
            goto LABEL_39;
LABEL_50:
          if ( v28 <= 0 )
            refcount_warn_saturate(_X0, 3);
        }
        goto LABEL_52;
      }
LABEL_3:
      if ( v23 <= 0 )
      {
        result = a1 + 8;
LABEL_28:
        result = (unsigned int *)refcount_warn_saturate(result, 3);
      }
LABEL_4:
      ++v4;
      v3 += 120;
      if ( v4 >= (unsigned int)a1[16] )
        goto LABEL_55;
    }
    result = (unsigned int *)dma_fence_remove_callback(*(_QWORD *)(v8 + 56), v8 + 64);
    v12 = *(_QWORD *)(v8 + 56);
    if ( !v12 )
      goto LABEL_35;
    result = (unsigned int *)(v12 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v25 = __ldxr(result);
    while ( __stlxr(v25 - 1, result) );
    if ( v25 == 1 )
    {
      __dmb(9u);
      result = (unsigned int *)dma_fence_release(result);
      if ( !a1 )
        goto LABEL_4;
    }
    else
    {
      if ( v25 > 0 )
      {
LABEL_35:
        if ( !a1 )
          goto LABEL_4;
        goto LABEL_36;
      }
      result = (unsigned int *)refcount_warn_saturate(result, 3);
      if ( !a1 )
        goto LABEL_4;
    }
LABEL_36:
    __asm { PRFM            #0x11, [X20] }
    do
      v23 = __ldxr(_X20);
    while ( __stlxr(v23 - 1, _X20) );
    if ( v23 == 1 )
    {
      __dmb(9u);
      _X0 = *((unsigned int **)a1 + 1);
      if ( _X0 )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v28 = __ldxr(_X0);
        while ( __stlxr(v28 - 1, _X0) );
        if ( v28 != 1 )
          goto LABEL_50;
LABEL_39:
        __dmb(9u);
        kgsl_context_destroy((__int64)_X0);
      }
LABEL_52:
      v30 = *((__int64 (__fastcall **)(_QWORD))a1 + 6);
      if ( *((_DWORD *)v30 - 1) != 287870130 )
        __break(0x8228u);
      result = (unsigned int *)v30(a1);
      goto LABEL_4;
    }
    goto LABEL_3;
  }
LABEL_55:
  if ( a1[18] )
  {
    result = *(unsigned int **)a1;
    v31 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)a1 + 8752LL) + 184LL);
    if ( v31 )
    {
      if ( *((_DWORD *)v31 - 1) != 2043251089 )
        __break(0x8228u);
      return (unsigned int *)v31();
    }
  }
  return result;
}
