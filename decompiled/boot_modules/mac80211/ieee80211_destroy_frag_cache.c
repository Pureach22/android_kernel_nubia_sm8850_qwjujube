__int64 **__fastcall ieee80211_destroy_frag_cache(__int64 **result)
{
  __int64 *v1; // x1
  __int64 **i; // x19
  __int64 v3; // x8
  _QWORD *v4; // x9
  __int64 *j; // x1
  __int64 v6; // x8
  _QWORD *v7; // x9
  __int64 *k; // x1
  __int64 v9; // x8
  _QWORD *v10; // x9
  __int64 *m; // x1
  __int64 v12; // x8
  _QWORD *v13; // x9

  v1 = *result;
  for ( i = result; *i != (__int64 *)i && v1; v1 = *i )
  {
    --*((_DWORD *)i + 4);
    v3 = *v1;
    v4 = (_QWORD *)v1[1];
    *v1 = 0;
    v1[1] = 0;
    *(_QWORD *)(v3 + 8) = v4;
    *v4 = v3;
    result = (__int64 **)sk_skb_reason_drop(0);
  }
  for ( j = i[7]; j != (__int64 *)(i + 7) && j; j = i[7] )
  {
    --*((_DWORD *)i + 18);
    v6 = *j;
    v7 = (_QWORD *)j[1];
    *j = 0;
    j[1] = 0;
    *(_QWORD *)(v6 + 8) = v7;
    *v7 = v6;
    result = (__int64 **)sk_skb_reason_drop(0);
  }
  for ( k = i[14]; k != (__int64 *)(i + 14) && k; k = i[14] )
  {
    --*((_DWORD *)i + 32);
    v9 = *k;
    v10 = (_QWORD *)k[1];
    *k = 0;
    k[1] = 0;
    *(_QWORD *)(v9 + 8) = v10;
    *v10 = v9;
    result = (__int64 **)sk_skb_reason_drop(0);
  }
  for ( m = i[21]; m != (__int64 *)(i + 21) && m; m = i[21] )
  {
    --*((_DWORD *)i + 46);
    v12 = *m;
    v13 = (_QWORD *)m[1];
    *m = 0;
    m[1] = 0;
    *(_QWORD *)(v12 + 8) = v13;
    *v13 = v12;
    result = (__int64 **)sk_skb_reason_drop(0);
  }
  return result;
}
