__int64 __fastcall _qmi_rmnet_bearer_get(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x20
  __int64 v5; // x0
  unsigned int v6; // w8
  __int64 v7; // x2
  __int64 *v8; // x19
  __int64 v9; // t1

  if ( a1 )
  {
    v4 = a1 + 56;
    while ( 1 )
    {
      v4 = *(_QWORD *)v4;
      if ( v4 == a1 + 56 )
        break;
      if ( *(unsigned __int8 *)(v4 + 16) == a2 )
      {
        if ( !v4 )
          break;
        ++*(_DWORD *)(v4 + 20);
        return v4;
      }
    }
  }
  v5 = _kmalloc_cache_noprof(ipa_register_notifier, 2336, 200);
  v4 = v5;
  if ( v5 )
  {
    v6 = 0x5000u / qmi_rmnet_scale_factor;
    *(_BYTE *)(v5 + 16) = a2;
    *(_QWORD *)(v5 + 20) = 0x500000000001LL;
    *(_QWORD *)(v5 + 60) = 0xFF000000FFLL;
    *(_QWORD *)(v5 + 72) = a1;
    *(_DWORD *)(v5 + 28) = v6;
    init_timer_key(v5 + 80, qmi_rmnet_watchdog_fn, 0, 0, 0);
    init_timer_key(v4 + 152, rmnet_ll_guard_fn, 0, 0, 0);
    v9 = *(_QWORD *)(a1 + 56);
    v8 = (__int64 *)(a1 + 56);
    v7 = v9;
    if ( *(__int64 **)(v9 + 8) != v8 || (__int64 *)v4 == v8 || v7 == v4 )
    {
      _list_add_valid_or_report(v4, v8, v7);
    }
    else
    {
      *(_QWORD *)(v7 + 8) = v4;
      *(_QWORD *)v4 = v7;
      *(_QWORD *)(v4 + 8) = v8;
      *v8 = v4;
    }
  }
  return v4;
}
