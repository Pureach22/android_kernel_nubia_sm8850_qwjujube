__int64 __fastcall ipc_log_context_destroy(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x9
  _QWORD *v4; // x8
  _QWORD *v5; // x22
  __int64 v6; // x0
  _QWORD *v7; // x10
  __int64 *v8; // x8
  __int64 v9; // x9
  __int64 v10; // x11
  _QWORD *i; // x9
  _QWORD **v13; // x21
  _QWORD *v14; // x8
  __int64 v15; // x10
  int v21; // w8

  if ( a1 )
  {
    debugfs_remove(*(_QWORD *)(a1 + 136));
    raw_spin_lock(a1 + 160);
    *(_BYTE *)(a1 + 204) = 1;
    complete_all(a1 + 168);
    v2 = *(_QWORD **)(a1 + 144);
    if ( v2 != (_QWORD *)(a1 + 144) )
    {
      do
      {
        v5 = (_QWORD *)*v2;
        v4 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v4 == v2 && (_QWORD *)v5[1] == v2 )
        {
          v5[1] = v4;
          *v4 = v5;
        }
        else
        {
          _list_del_entry_valid_or_report(v2);
          v2 = v3;
        }
        *v2 = 0xDEAD000000000100LL;
        v2[1] = 0xDEAD000000000122LL;
        kfree(v2);
        v2 = v5;
      }
      while ( v5 != (_QWORD *)(a1 + 144) );
    }
    raw_spin_unlock(a1 + 160);
    v6 = raw_write_lock_irqsave(&context_list_lock_lha1);
    v7 = *(_QWORD **)(a1 + 64);
    v8 = (__int64 *)(a1 + 56);
    v9 = v6;
    if ( *v7 == a1 + 56 && (v10 = *v8, *(__int64 **)(*v8 + 8) == v8) )
    {
      *(_QWORD *)(v10 + 8) = v7;
      *v7 = v10;
    }
    else
    {
      _list_del_entry_valid_or_report(a1 + 56);
    }
    *(_QWORD *)(a1 + 56) = 0xDEAD000000000100LL;
    *(_QWORD *)(a1 + 64) = 0xDEAD000000000122LL;
    raw_write_unlock_irqrestore(&context_list_lock_lha1, v9);
    _X0 = (unsigned int *)(a1 + 200);
    __asm { PRFM            #0x11, [X0] }
    do
      v21 = __ldxr(_X0);
    while ( __stlxr(v21 - 1, _X0) );
    if ( v21 == 1 )
    {
      __dmb(9u);
      v13 = (_QWORD **)(a1 + 72);
      for ( i = *(_QWORD **)(a1 + 72); i != v13; i = *v13 )
      {
        v14 = (_QWORD *)i[1];
        if ( (_QWORD *)*v14 == i && (v15 = *i, *(_QWORD **)(*i + 8LL) == i) )
        {
          *(_QWORD *)(v15 + 8) = v14;
          *v14 = v15;
        }
        else
        {
          _list_del_entry_valid_or_report(i);
        }
        *i = 0xDEAD000000000100LL;
        i[1] = 0xDEAD000000000122LL;
        kfree(i - 6);
      }
      kfree(a1);
    }
    else if ( v21 <= 0 )
    {
      refcount_warn_saturate();
    }
  }
  return 0;
}
