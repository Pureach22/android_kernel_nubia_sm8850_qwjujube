__int64 __fastcall ieee80211_color_change_bss_config_notify(__int64 *a1, char a2, int a3, __int64 a4)
{
  __int64 v5; // x20
  bool v6; // w22
  __int64 result; // x0
  __int64 v8; // x8
  __int64 *i; // x21

  v5 = *a1;
  *(_BYTE *)(a1[118] + 345) = a2;
  v6 = a3 != 0;
  *(_BYTE *)(a1[118] + 346) = a3 != 0;
  result = ieee80211_link_info_change_notify(v5, a1, a4 | 0x20000000);
  if ( (*(_BYTE *)(v5 + 5112) & 1) == 0 )
  {
    if ( *(_QWORD *)(v5 + 5888) )
    {
      v8 = *(_QWORD *)(v5 + 1616);
      for ( i = *(__int64 **)(v8 + 4616); i != (__int64 *)(v8 + 4616); i = (__int64 *)*i )
      {
        if ( i != (__int64 *)v5 && i[736] == v5 + 4720 )
        {
          *((_BYTE *)i + 5153) = a2;
          *((_BYTE *)i + 5154) = v6;
          result = ieee80211_link_info_change_notify(i, i + 452, 0x20000000);
          v8 = *(_QWORD *)(v5 + 1616);
        }
      }
    }
  }
  return result;
}
