__int64 __fastcall ieee80211_tdls_add_link_ie(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v7; // x22
  __int64 result; // x0
  __int16 v9; // w9
  __int64 v10; // x8
  int v11; // w9
  __int16 v12; // w8
  __int64 v13; // x9
  int v14; // w8
  __int16 v15; // w9

  v7 = *(_QWORD *)a1 + 5842LL;
  result = skb_put(a2, 20);
  *(_WORD *)result = 4709;
  v9 = *(_WORD *)(a1 + 540);
  *(_DWORD *)(result + 2) = *(_DWORD *)(a1 + 536);
  if ( (a4 & 1) != 0 )
    v10 = v7;
  else
    v10 = a3;
  *(_WORD *)(result + 6) = v9;
  v11 = *(_DWORD *)v10;
  v12 = *(_WORD *)(v10 + 4);
  *(_DWORD *)(result + 8) = v11;
  if ( (a4 & 1) != 0 )
    v13 = a3;
  else
    v13 = v7;
  *(_WORD *)(result + 12) = v12;
  v14 = *(_DWORD *)v13;
  v15 = *(_WORD *)(v13 + 4);
  *(_DWORD *)(result + 14) = v14;
  *(_WORD *)(result + 18) = v15;
  return result;
}
