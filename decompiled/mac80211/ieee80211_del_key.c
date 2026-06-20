__int64 __fastcall ieee80211_del_key(__int64 a1, __int64 a2, unsigned int a3, unsigned __int8 a4, char a5, __int64 a6)
{
  __int64 v9; // x8
  __int64 bss; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 *v13; // x8
  __int64 result; // x0

  if ( (a3 & 0x80000000) != 0 )
  {
    v9 = a2 + 6304;
    if ( a6 )
      goto LABEL_5;
    goto LABEL_10;
  }
  if ( a3 >= 0xF )
    goto LABEL_28;
  v9 = *(_QWORD *)(a2 + 8LL * a3 + 7256);
  if ( !v9 )
    return 4294967294LL;
  if ( !a6 )
  {
LABEL_10:
    if ( a4 <= 3u && (a5 & 1) != 0 )
    {
LABEL_15:
      v13 = (__int64 *)(a2 + 8LL * a4 + 4584);
LABEL_23:
      v12 = *v13;
      goto LABEL_24;
    }
    if ( a4 <= 7u )
    {
      v12 = *(_QWORD *)(v9 + 8LL * a4 + 48);
      if ( a4 > 3u || v12 )
      {
LABEL_24:
        if ( v12 )
        {
          ieee80211_key_free();
          return 0;
        }
        return 4294967294LL;
      }
      goto LABEL_15;
    }
LABEL_28:
    __break(0x5512u);
    MEMORY[0xFFFFFFFFFA571850]();
    JUMPOUT(0x35858);
  }
LABEL_5:
  bss = sta_info_get_bss(a2 + 2688, a6);
  if ( !bss )
    return 4294967294LL;
  if ( (a3 & 0x80000000) != 0 )
  {
    v11 = bss + 1640;
  }
  else
  {
    v11 = *(_QWORD *)(bss + 8LL * a3 + 2568);
    if ( !v11 )
      return 4294967294LL;
  }
  if ( a4 <= 3u && (a5 & 1) != 0 )
  {
    v13 = (__int64 *)(bss + 8LL * a4 + 88);
    goto LABEL_23;
  }
  result = 4294967294LL;
  if ( a4 <= 7u && (a5 & 1) == 0 )
  {
    v13 = (__int64 *)(v11 + 8LL * a4 + 40);
    goto LABEL_23;
  }
  return result;
}
