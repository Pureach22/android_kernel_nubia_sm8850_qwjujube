unsigned __int64 *__fastcall synx_util_release_handle(
        unsigned __int64 *result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned __int64 v6; // x20
  unsigned __int64 *v7; // x19
  unsigned __int64 *v8; // x2
  unsigned __int64 *v10; // x8
  unsigned __int64 v11; // x9
  _QWORD *v12; // x2
  int v18; // w8

  if ( result && (unsigned __int64)result < 0xFFFFFFFFFFFFF001LL )
  {
    v6 = *result;
    if ( *result && v6 < 0xFFFFFFFFFFFFF001LL )
    {
      v7 = result;
      raw_spin_lock_bh(v6 + 264920);
      v8 = v7;
      _X0 = (unsigned int *)(v7 + 3);
      __asm { PRFM            #0x11, [X0] }
      do
        v18 = __ldxr(_X0);
      while ( __stlxr(v18 - 1, _X0) );
      if ( v18 == 1 )
      {
        __dmb(9u);
        v10 = (unsigned __int64 *)v7[10];
        if ( v10 )
        {
          v11 = v7[9];
          *v10 = v11;
          if ( v11 )
            *(_QWORD *)(v11 + 8) = v10;
          v7[9] = 0;
          v7[10] = 0;
        }
        if ( (synx_debug & 0x80) != 0 )
        {
          printk(
            &unk_2A487,
            &unk_25D36,
            "synx_util_destroy_handle",
            1257,
            *(_QWORD *)(*v7 + 104),
            *((unsigned int *)v7 + 7));
          v8 = v7;
        }
        v8[5] = 0xFFFFFFFE00000LL;
        v12 = v8 + 5;
        v12[1] = v12 + 1;
        v12[2] = v12 + 1;
        v12[3] = synx_util_destroy_handle_worker;
        queue_work_on(32, *(_QWORD *)(synx_dev + 168), v12);
      }
      else if ( v18 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      return (unsigned __int64 *)raw_spin_unlock_bh(v6 + 264920);
    }
    else if ( (synx_debug & 1) != 0 )
    {
      return (unsigned __int64 *)printk(&unk_2B010, &unk_29207, "synx_util_release_handle", 1273, a5, a6);
    }
  }
  else if ( (synx_debug & 1) != 0 )
  {
    return (unsigned __int64 *)printk(&unk_259F3, &unk_29207, "synx_util_release_handle", 1267, a5, a6);
  }
  return result;
}
