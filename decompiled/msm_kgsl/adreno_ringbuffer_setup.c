unsigned __int64 __fastcall adreno_ringbuffer_setup(
        __int64 a1,
        __int64 a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  unsigned __int64 v8; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 result; // x0
  char v14; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a2 + 1304);
  if ( !v8 || v8 >= 0xFFFFFFFFFFFFF001LL )
    *(_QWORD *)(a2 + 1304) = kgsl_allocate_global(a1, 4096, 0, 0x1000000, 0, "profile_desc");
  v12 = *(_QWORD *)(a2 + 8);
  if ( v12 && v12 < 0xFFFFFFFFFFFFF001LL
    || (result = kgsl_allocate_global(
                   a1,
                   0x8000,
                   4096,
                   0x1000000,
                   (*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL) >> 5) & 0x40,
                   "ringbuffer"),
        *(_QWORD *)(a2 + 8) = result,
        result < 0xFFFFFFFFFFFFF001LL) )
  {
    if ( *(_QWORD *)(a2 + 72) == a2 + 72 )
    {
      *(_DWORD *)(a2 + 28) = a3;
      kgsl_add_event_group(a1, a2 + 40, 0, (int)rb_readtimestamp, a2, "rb_events-%d", a3, a8, v14);
      *(_DWORD *)(a2 + 36) = 0;
      _init_waitqueue_head(a2 + 1256, "&rb->ts_expire_waitq", &adreno_ringbuffer_setup___key);
      *(_DWORD *)(a2 + 1292) = 0;
      return 0;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
