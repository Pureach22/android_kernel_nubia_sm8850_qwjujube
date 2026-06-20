__int64 __fastcall ipa3_aux_napi_tx_complete(__int64 a1, signed int a2)
{
  unsigned int v4; // w20
  __int64 v5; // x22
  __int64 v6; // x26
  int v8; // w28
  unsigned int v9; // w8
  unsigned int v15; // w10
  int v16; // w27
  int v17; // w25
  __int64 v18; // x0
  unsigned int v21; // w8
  __int64 v22; // x0
  unsigned int *v24; // [xsp+8h] [xbp-8h]

  v4 = 0;
  v5 = a1 - 720;
  v6 = a1 + 912;
  _X24 = (unsigned int *)(a1 - 56);
  v24 = (unsigned int *)(a1 + 868);
  while ( 1 )
  {
    raw_spin_lock_bh(a1 + 964);
    v8 = a2 - v4;
    if ( (int)(a2 - v4) >= 1 )
    {
      while ( *(int *)(a1 - 56) >= 1 )
      {
        if ( *(_QWORD *)v6 == v6 )
        {
          if ( ipa3_ctx )
          {
            v18 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v18 )
              ipc_log_string(v18, "ipa %s:%d list is empty", "ipa3_napi_tx_complete", 501);
          }
          break;
        }
        v16 = *(unsigned __int8 *)(*(_QWORD *)v6 + 65LL);
        raw_spin_unlock_bh(a1 + 964);
        v17 = ipa3_write_done_common(v5);
        raw_spin_lock_bh(a1 + 964);
        if ( v16 == 1 )
        {
          v9 = *(_DWORD *)(a1 - 56);
          do
          {
            if ( !v9 )
              break;
            __asm { PRFM            #0x11, [X24] }
            while ( 1 )
            {
              v15 = __ldxr(_X24);
              if ( v15 != v9 )
                break;
              if ( !__stlxr(v9 - 1, _X24) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v15 == v9;
            v9 = v15;
          }
          while ( !_ZF );
        }
        v8 -= v17;
        if ( v8 <= 0 )
          break;
      }
    }
    raw_spin_unlock_bh(a1 + 964);
    v4 = a2 - v8;
    if ( a2 - v8 >= a2 )
      break;
    napi_complete_done(a1, 0);
    *(_DWORD *)(a1 + 868) = 0;
    if ( *(int *)(a1 - 56) < 1 )
      break;
    _X11 = v24;
    __asm { PRFM            #0x11, [X11] }
    while ( 1 )
    {
      v21 = __ldxr(v24);
      if ( v21 )
        break;
      if ( !__stlxr(1u, v24) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( v21 || (napi_schedule_prep(a1) & 1) == 0 )
      break;
    _napi_schedule(a1);
  }
  if ( ipa3_ctx )
  {
    v22 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v22 )
      ipc_log_string(v22, "ipa %s:%d the number of tx completions is: %d", "ipa3_aux_napi_tx_complete", 544, v4);
  }
  if ( (int)v4 >= a2 )
    return (unsigned int)a2;
  else
    return v4;
}
