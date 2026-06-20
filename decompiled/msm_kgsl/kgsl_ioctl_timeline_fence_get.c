__int64 __fastcall kgsl_ioctl_timeline_fence_get(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x20
  __int64 result; // x0
  unsigned int unused_fd_flags; // w22
  _QWORD *v10; // x0
  __int64 v12; // x20
  int v14; // w9
  __int64 v16; // x19
  int v22; // w8
  int v24; // w9

  v4 = kgsl_timeline_by_id(*a1, *(_DWORD *)(a3 + 8));
  if ( !v4 )
    return -19;
  v5 = v4;
  v6 = kgsl_timeline_fence_alloc(v4, *(_QWORD *)a3);
  if ( v6 < 0xFFFFFFFFFFFFF001LL )
  {
    unused_fd_flags = get_unused_fd_flags(0x80000);
    if ( (unused_fd_flags & 0x80000000) != 0 )
    {
      result = (int)unused_fd_flags;
      if ( !v6 )
      {
LABEL_20:
        if ( v5 > 0xFFFFFFFFFFFFF000LL )
          return result;
        _X8 = (unsigned int *)(v5 + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v24 = __ldxr(_X8);
        while ( __stlxr(v24 - 1, _X8) );
        if ( v24 == 1 )
        {
          __dmb(9u);
          v16 = result;
          kgsl_timeline_destroy((__int64)_X8);
        }
        else
        {
          if ( v24 > 0 )
            return result;
          v16 = result;
          refcount_warn_saturate(_X8, 3);
        }
        return v16;
      }
    }
    else
    {
      v10 = (_QWORD *)sync_file_create(v6);
      if ( v10 )
      {
        fd_install(unused_fd_flags, *v10);
        result = 0;
        *(_DWORD *)(a3 + 12) = unused_fd_flags;
        if ( !v6 )
          goto LABEL_20;
      }
      else
      {
        put_unused_fd(unused_fd_flags);
        result = -12;
        if ( !v6 )
          goto LABEL_20;
      }
    }
    _X8 = (unsigned int *)(v6 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stlxr(v14 - 1, _X8) );
    if ( v14 == 1 )
    {
      __dmb(9u);
      v12 = result;
      dma_fence_release(_X8);
    }
    else
    {
      if ( v14 > 0 )
        goto LABEL_20;
      v12 = result;
      refcount_warn_saturate(_X8, 3);
    }
    result = v12;
    goto LABEL_20;
  }
  if ( v5 <= 0xFFFFFFFFFFFFF000LL )
  {
    _X0 = (unsigned int *)(v5 + 32);
    __asm { PRFM            #0x11, [X0] }
    do
      v22 = __ldxr(_X0);
    while ( __stlxr(v22 - 1, _X0) );
    if ( v22 == 1 )
    {
      __dmb(9u);
      kgsl_timeline_destroy((__int64)_X0);
    }
    else if ( v22 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  return v6;
}
