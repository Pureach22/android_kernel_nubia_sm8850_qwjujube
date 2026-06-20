__int64 __fastcall ieee80211_color_change_finalize(__int64 *a1)
{
  __int64 v2; // x22
  int v3; // w0
  __int64 v4; // x8
  int v5; // w20
  __int64 v6; // x8
  __int64 v7; // x20
  char v8; // w23
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 *i; // x21
  __int64 v12; // x1
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v2 = *a1;
  *(_BYTE *)(a1[118] + 840) = 0;
  if ( *(_DWORD *)(*a1 + 4720) != 3 )
  {
    __break(0x800u);
LABEL_15:
    v12 = 144;
    goto LABEL_16;
  }
  if ( !a1[71] )
    goto LABEL_15;
  v3 = ieee80211_assign_beacon();
  v4 = a1[71];
  v5 = v3;
  if ( v4 )
  {
    kfree(*(_QWORD *)(v4 + 72));
    kfree(*(_QWORD *)(a1[71] + 80));
    kfree(a1[71]);
    a1[71] = 0;
  }
  if ( v5 < 0 )
    goto LABEL_15;
  v6 = a1[118];
  v7 = *a1;
  v8 = *(_BYTE *)(v6 + 841);
  v9 = *a1;
  *(_BYTE *)(v6 + 345) = v8;
  *(_BYTE *)(a1[118] + 346) = 1;
  ieee80211_link_info_change_notify(v9, a1, 0x20000000);
  if ( (*(_BYTE *)(v7 + 5112) & 1) == 0 )
  {
    if ( *(_QWORD *)(v7 + 5888) )
    {
      v10 = *(_QWORD *)(v7 + 1616);
      for ( i = *(__int64 **)(v10 + 4616); i != (__int64 *)(v10 + 4616); i = (__int64 *)*i )
      {
        if ( i != (__int64 *)v7 && i[736] == v7 + 4720 )
        {
          *((_BYTE *)i + 5153) = v8;
          *((_BYTE *)i + 5154) = 1;
          ieee80211_link_info_change_notify(i, i + 452, 0x20000000);
          v10 = *(_QWORD *)(v7 + 1616);
        }
      }
    }
  }
  v12 = 145;
LABEL_16:
  result = cfg80211_bss_color_notify(*(_QWORD *)(v2 + 1608), v12, 0, 0, *((unsigned int *)a1 + 2));
  _ReadStatusReg(SP_EL0);
  return result;
}
