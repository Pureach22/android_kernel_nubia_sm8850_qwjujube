unsigned int *__fastcall synx_util_remove_data(
        unsigned int *result,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x19
  __int64 v7; // x8
  _QWORD *v8; // x0
  __int64 v10; // x8
  _QWORD *v12; // x8
  __int64 v13; // x9
  _QWORD *v14; // x19
  int v19; // w9

  if ( result && (unsigned __int64)result <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( a2 )
    {
      if ( (synx_debug & 1) != 0 )
        return (unsigned int *)printk(&unk_270AB, &unk_29207, "synx_util_remove_data", 1826, a2, a6);
    }
    else
    {
      v6 = *result;
      raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 20512LL);
      v7 = *(_QWORD *)(*(_QWORD *)(synx_dev + 152) + 8 * ((unsigned __int64)(0x61C8864680B583EBLL * v6) >> 56) + 20520);
      v8 = (_QWORD *)(v7 - 24);
      if ( v7 )
        _ZF = v7 == 24;
      else
        _ZF = 1;
      if ( !_ZF )
      {
        while ( *v8 != v6 )
        {
          v10 = v8[3];
          if ( v10 )
          {
            v8 = (_QWORD *)(v10 - 24);
            if ( v10 != 24 )
              continue;
          }
          return (unsigned int *)raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 20512LL);
        }
        _X8 = (unsigned int *)(v8 + 2);
        __asm { PRFM            #0x11, [X8] }
        do
          v19 = __ldxr(_X8);
        while ( __stlxr(v19 - 1, _X8) );
        if ( v19 == 1 )
        {
          __dmb(9u);
          v12 = (_QWORD *)v8[4];
          if ( v12 )
          {
            v13 = v8[3];
            *v12 = v13;
            if ( v13 )
              *(_QWORD *)(v13 + 8) = v12;
            v8[3] = 0;
            v8[4] = 0;
          }
          if ( (synx_debug & 0x80) != 0 )
          {
            v14 = v8;
            printk(&unk_26D9C, &unk_25D36, "synx_util_destroy_data", 1795, *v8, v8);
            v8 = v14;
          }
          kfree(v8);
        }
        else if ( v19 <= 0 )
        {
          refcount_warn_saturate(v8 + 2, 3);
        }
      }
      return (unsigned int *)raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 20512LL);
    }
  }
  return result;
}
