unsigned __int64 __fastcall synx_util_release_map_entry(unsigned __int64 result)
{
  unsigned __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  _QWORD *v5; // x8
  __int64 v6; // x9
  _QWORD *v7; // x19
  int v13; // w8

  if ( result )
  {
    v1 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v2 = *(_QWORD *)(synx_dev + 152);
      if ( (*(_DWORD *)(result + 16) & 0x100000) != 0 )
        v3 = 10256;
      else
        v3 = 18456;
      raw_spin_lock_bh(v2 + v3);
      _X0 = (unsigned int *)(v1 + 8);
      __asm { PRFM            #0x11, [X0] }
      do
        v13 = __ldxr(_X0);
      while ( __stlxr(v13 - 1, _X0) );
      if ( v13 == 1 )
      {
        __dmb(9u);
        v5 = *(_QWORD **)(v1 + 64);
        if ( v5 )
        {
          v6 = *(_QWORD *)(v1 + 56);
          *v5 = v6;
          if ( v6 )
            *(_QWORD *)(v6 + 8) = v5;
          *(_QWORD *)(v1 + 56) = 0;
          *(_QWORD *)(v1 + 64) = 0;
        }
        if ( (synx_debug & 0x80) != 0 )
          printk(&unk_26861, &unk_25D36, "synx_util_destroy_map_entry", 1213, *(unsigned int *)(v1 + 16), v1);
        *(_QWORD *)(v1 + 24) = 0xFFFFFFFE00000LL;
        v7 = (_QWORD *)(v1 + 24);
        v7[1] = v7 + 1;
        v7[2] = v7 + 1;
        v7[3] = synx_util_destroy_map_entry_worker;
        queue_work_on(32, *(_QWORD *)(synx_dev + 168), v7);
      }
      else if ( v13 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      return raw_spin_unlock_bh(v2 + v3);
    }
  }
  return result;
}
