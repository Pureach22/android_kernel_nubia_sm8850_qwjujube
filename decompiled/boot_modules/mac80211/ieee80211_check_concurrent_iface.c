__int64 __fastcall ieee80211_check_concurrent_iface(__int64 a1, int a2)
{
  __int64 v2; // x21
  __int64 *v5; // x8
  __int64 result; // x0
  int v7; // w11
  int v8; // w11

  v2 = *(_QWORD *)(a1 + 1616);
  if ( !(unsigned int)rtnl_is_locked() && (ieee80211_check_concurrent_iface___already_done & 1) == 0 )
  {
    ieee80211_check_concurrent_iface___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/mac80211/iface.c", 334);
    __break(0x800u);
  }
  v5 = *(__int64 **)(v2 + 4616);
  if ( v5 == (__int64 *)(v2 + 4616) )
    return ieee80211_check_combinations(a1, 0, 0, 0, 0xFFFFFFFFLL);
  result = 4294967220LL;
  while ( 1 )
  {
    if ( v5 == (__int64 *)a1 || (v5[204] & 1) == 0 )
      goto LABEL_7;
    v7 = *(_DWORD *)(a1 + 4720);
    if ( v7 != 6 )
    {
      if ( v7 == 11 )
      {
        if ( *((_DWORD *)v5 + 1180) != 6 )
          return 4294967280LL;
      }
      else if ( *((_DWORD *)v5 + 1180) == 11 )
      {
        return 4294967280LL;
      }
    }
    if ( a2 == 1 && *((_DWORD *)v5 + 1180) == 1 || (*((_BYTE *)v5 + 5638) & 1) != 0 )
      return 4294967280LL;
    if ( !(*(_DWORD *)((char *)v5 + 5842) ^ *(_DWORD *)(a1 + 5842)
         | *((unsigned __int16 *)v5 + 2923) ^ *(unsigned __int16 *)(a1 + 5846)) )
    {
      v8 = *((_DWORD *)v5 + 1180);
      if ( v8 == 10 || a2 == 10 || a2 == 6 || v8 == 6 )
      {
        if ( a2 != 4 )
          goto LABEL_7;
      }
      else
      {
        if ( a2 == 3 && v8 == 4 )
          goto LABEL_7;
        if ( a2 != 4 || (unsigned int)(v8 - 5) < 0xFFFFFFFE )
          return result;
      }
      if ( *(_BYTE *)(a1 + 81) == 1 )
      {
        if ( v8 != 3 )
          goto LABEL_7;
        if ( *((_WORD *)v5 + 2900) )
          return 4294967201LL;
      }
      else if ( v8 != 3 )
      {
        goto LABEL_7;
      }
      *(_QWORD *)(a1 + 2032) = v5 + 283;
    }
LABEL_7:
    v5 = (__int64 *)*v5;
    if ( v5 == (__int64 *)(v2 + 4616) )
      return ieee80211_check_combinations(a1, 0, 0, 0, 0xFFFFFFFFLL);
  }
}
