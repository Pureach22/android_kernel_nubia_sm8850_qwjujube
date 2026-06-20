__int64 __fastcall _sta_info_destroy_part1(__int64 *a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  void (__fastcall *v4)(_QWORD); // x8
  __int64 i; // x23
  __int64 result; // x0
  void (__fastcall *v7)(__int64, __int64, __int64 *); // x8
  __int64 **v8; // x8
  __int64 *v9; // x9
  int v10; // w8
  __int64 v11; // x22
  void (__fastcall *v12)(__int64, __int64, __int64 *); // x8
  __int64 v13; // x9
  __int64 v14; // x1
  __int64 v15; // x9
  __int64 v16; // x1
  unsigned __int64 v23; // x9
  unsigned __int64 v26; // x10

  if ( !a1 )
    return 4294967294LL;
  v2 = a1[9];
  v1 = a1[10];
  _X8 = (unsigned __int64 *)(a1 + 27);
  __asm { PRFM            #0x11, [X8] }
  do
    v23 = __ldxr(_X8);
  while ( __stxr(v23 | 0x100, _X8) );
  ieee80211_sta_tear_down_BA_sessions(a1, 3u);
  if ( *(_QWORD *)(*(_QWORD *)(v2 + 464) + 760LL) )
  {
    v4 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v2 + 464) + 760LL);
    if ( *((_DWORD *)v4 - 1) != -698516357 )
      __break(0x8228u);
    v4(v2);
  }
  for ( i = 0; i != 15; ++i )
  {
    if ( (((unsigned __int64)*((unsigned __int16 *)a1 + 1436) >> i) & 1) != 0 )
      rhltable_remove(v2 + 1792, a1[i + 321] + 16, &link_sta_rht_params);
  }
  result = rhltable_remove(v2 + 1632, a1 + 6, &sta_rht_params);
  if ( (_DWORD)result )
  {
    __break(0x800u);
    return result;
  }
  if ( (a1[27] & 0x8000) != 0 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(v1 + 1616) + 1471LL) & 1) != 0
      || (*(_DWORD *)(v1 + 1624) & 0x20) != 0
      || (drv_tdls_cancel_channel_switch___already_done & 1) != 0 )
    {
      if ( (*(_BYTE *)(v1 + 1624) & 0x20) != 0 )
        goto LABEL_17;
    }
    else
    {
      v13 = *(_QWORD *)(v1 + 1608);
      drv_tdls_cancel_channel_switch___already_done = 1;
      if ( v13 )
        v14 = v13 + 296;
      else
        v14 = v1 + 1640;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v14);
      __break(0x800u);
      if ( (*(_BYTE *)(v1 + 1624) & 0x20) != 0 )
      {
LABEL_17:
        if ( *(_QWORD *)(*(_QWORD *)(v2 + 464) + 736LL) )
        {
          v7 = *(void (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(v2 + 464) + 736LL);
          if ( *((_DWORD *)v7 - 1) != -1656504592 )
            __break(0x8228u);
          v7(v2, v1 + 4720, a1 + 336);
        }
      }
    }
    _X8 = (unsigned __int64 *)(a1 + 27);
    __asm { PRFM            #0x11, [X8] }
    do
      v26 = __ldxr(_X8);
    while ( __stxr(v26 & 0xFFFFFFFFFFFF7FFFLL, _X8) );
  }
  v8 = (__int64 **)a1[1];
  if ( *v8 == a1 && (v9 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
  {
    v9[1] = (__int64)v8;
    *v8 = v9;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  v10 = *((unsigned __int8 *)a1 + 204);
  a1[1] = 0xDEAD000000000122LL;
  *((_BYTE *)a1 + 203) = 1;
  if ( v10 == 1 )
  {
    v11 = a1[10];
    if ( v11 && *(_DWORD *)(v11 + 4720) == 4 )
      v11 = *(_QWORD *)(v11 + 2032) - 2264LL;
    if ( (*(_BYTE *)(*(_QWORD *)(v11 + 1616) + 1471LL) & 1) != 0
      || (*(_DWORD *)(v11 + 1624) & 0x20) != 0
      || (drv_sta_pre_rcu_remove___already_done & 1) != 0 )
    {
      if ( (*(_BYTE *)(v11 + 1624) & 0x20) != 0 )
        goto LABEL_33;
    }
    else
    {
      v15 = *(_QWORD *)(v11 + 1608);
      drv_sta_pre_rcu_remove___already_done = 1;
      if ( v15 )
        v16 = v15 + 296;
      else
        v16 = v11 + 1640;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v16);
      __break(0x800u);
      if ( (*(_BYTE *)(v11 + 1624) & 0x20) != 0 )
      {
LABEL_33:
        v12 = *(void (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(v2 + 464) + 304LL);
        if ( v12 )
        {
          if ( *((_DWORD *)v12 - 1) != -1656504592 )
            __break(0x8228u);
          v12(v2, v11 + 4720, a1 + 336);
        }
      }
    }
  }
  if ( *(_DWORD *)(v1 + 4720) != 4 || *(__int64 **)(v1 + 2280) != a1 )
    return 0;
  result = 0;
  *(_QWORD *)(v1 + 2280) = 0;
  return result;
}
