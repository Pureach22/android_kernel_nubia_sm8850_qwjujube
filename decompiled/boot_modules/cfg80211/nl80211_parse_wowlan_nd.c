__int64 __fastcall nl80211_parse_wowlan_nd(__int64 a1, __int64 a2, _WORD *a3, __int64 a4)
{
  __int64 v8; // x0
  unsigned int v9; // w22
  _QWORD *v10; // x23
  unsigned __int64 v11; // x8
  bool v12; // cf
  unsigned __int64 v13; // x9

  v8 = _kmalloc_cache_noprof(alloc_workqueue, 3520, 2688);
  if ( v8 )
  {
    if ( (*(_BYTE *)(a2 + 1) & 1) != 0 )
    {
      v10 = (_QWORD *)v8;
      v9 = _nla_parse(v8, 335, a3 + 2, (unsigned __int16)(*a3 - 4), &nl80211_policy, 0, 0);
      v8 = (__int64)v10;
      if ( !v9 )
      {
        v11 = nl80211_parse_sched_scan(a1 + 992, nullptr, v10, *(_DWORD *)(a2 + 20));
        v8 = (__int64)v10;
        if ( (_DWORD)v11 )
          v12 = v11 >= 0xFFFFFFFFFFFFF001LL;
        else
          v12 = 0;
        if ( v12 )
          v13 = 0;
        else
          v13 = v11;
        if ( v11 >= 0xFFFFFFFFFFFFF001LL )
          v9 = v11;
        else
          v9 = 0;
        *(_QWORD *)(a4 + 32) = v13;
      }
    }
    else
    {
      v9 = -95;
    }
    kfree(v8);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v9;
}
