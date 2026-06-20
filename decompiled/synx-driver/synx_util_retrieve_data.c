_QWORD *__fastcall synx_util_retrieve_data(
        unsigned int *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  _QWORD *v6; // x19
  __int64 v7; // x21
  __int64 v8; // x9
  _QWORD *v9; // x8
  __int64 v11; // x8
  unsigned int v18; // w9

  if ( a2 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_270AB, &unk_29207, "synx_util_retrieve_data", 1782, a2, a6);
    return nullptr;
  }
  else
  {
    v7 = *a1;
    raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 20512LL);
    v8 = *(_QWORD *)(*(_QWORD *)(synx_dev + 152) + 8 * ((unsigned __int64)(0x61C8864680B583EBLL * v7) >> 56) + 20520);
    v9 = (_QWORD *)(v8 - 24);
    if ( v8 )
      _ZF = v8 == 24;
    else
      _ZF = 1;
    if ( _ZF )
    {
      v6 = nullptr;
    }
    else
    {
      while ( *v9 != v7 )
      {
        v11 = v9[3];
        v6 = nullptr;
        if ( v11 )
        {
          v9 = (_QWORD *)(v11 - 24);
          if ( v9 )
            continue;
        }
        goto LABEL_18;
      }
      _X0 = (unsigned int *)(v9 + 2);
      __asm { PRFM            #0x11, [X0] }
      do
        v18 = __ldxr(_X0);
      while ( __stxr(v18 + 1, _X0) );
      if ( v18 )
      {
        v6 = v9;
        if ( (((v18 + 1) | v18) & 0x80000000) != 0 )
          refcount_warn_saturate(_X0, 1);
      }
      else
      {
        v6 = v9;
        refcount_warn_saturate(_X0, 2);
      }
    }
LABEL_18:
    raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 20512LL);
  }
  return v6;
}
