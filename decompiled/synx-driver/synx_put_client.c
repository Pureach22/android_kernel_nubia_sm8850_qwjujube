unsigned __int64 __fastcall synx_put_client(
        unsigned __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  _QWORD *v6; // x19
  _QWORD *v8; // x9
  __int64 v9; // x11
  int v15; // w8

  if ( result && (v6 = (_QWORD *)result, result < 0xFFFFFFFFFFFFF001LL) )
  {
    raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152));
    _X0 = (unsigned int *)(v6 + 15);
    __asm { PRFM            #0x11, [X0] }
    do
      v15 = __ldxr(_X0);
    while ( __stlxr(v15 - 1, _X0) );
    if ( v15 == 1 )
    {
      __dmb(9u);
      v8 = (_QWORD *)v6[33121];
      if ( v8 )
      {
        v9 = v6[33120];
        *v8 = v9;
        if ( v9 )
          *(_QWORD *)(v9 + 8) = v8;
        v6[33120] = 0;
        v6[33121] = 0;
      }
      v6[33116] = 0xFFFFFFFE00000LL;
      v6[33117] = v6 + 33117;
      v6[33118] = v6 + 33117;
      v6[33119] = synx_client_cleanup;
      queue_work_on(32, *(_QWORD *)(synx_dev + 168), v6 + 33116);
    }
    else if ( v15 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    return raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152));
  }
  else if ( (synx_debug & 1) != 0 )
  {
    return printk(&unk_2B010, &unk_29207, "synx_put_client", 1671, a5, a6);
  }
  return result;
}
