__int64 __fastcall nl80211_get_ap_channel(__int64 a1, _QWORD *a2)
{
  _QWORD *i; // x8
  int v3; // w10
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 v8; // x11

  for ( i = *(_QWORD **)(a1 + 2328); ; i = (_QWORD *)*i )
  {
    if ( i == (_QWORD *)(a1 + 2328) )
      return 0;
    v3 = *((_DWORD *)i - 2);
    if ( v3 == 9 || v3 == 3 )
    {
      if ( i[33] )
        break;
    }
  }
  v6 = i[35];
  v5 = i[36];
  v8 = i[33];
  v7 = i[34];
  a2[2] = v6;
  a2[3] = v5;
  *a2 = v8;
  a2[1] = v7;
  return 1;
}
