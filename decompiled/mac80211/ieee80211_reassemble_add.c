__int64 __fastcall ieee80211_reassemble_add(__int64 a1, __int64 a2, __int64 a3, _QWORD **a4, __int64 a5)
{
  unsigned int v5; // w8
  char v7; // w19
  __int16 v8; // w20
  __int64 v9; // x22
  __int64 *v10; // x1
  __int64 v12; // x8
  _QWORD *v13; // x9
  _QWORD *v14; // x8
  _QWORD *v15; // x9
  __int64 v17; // x8

  v5 = *(_DWORD *)(a1 + 224);
  *(_DWORD *)(a1 + 224) = v5 + 1;
  if ( v5 >= 5 )
  {
    __break(0x5512u);
    return ieee80211_reassemble_find(a1, a2, a3, a4, a5);
  }
  else
  {
    v7 = a3;
    v8 = a2;
    if ( v5 + 1 >= 4 )
      *(_DWORD *)(a1 + 224) = 0;
    v9 = a1 + 56LL * v5;
    v10 = *(__int64 **)v9;
    if ( *(_QWORD *)v9 != v9 && v10 != nullptr )
    {
      do
      {
        --*(_DWORD *)(v9 + 16);
        v12 = *v10;
        v13 = (_QWORD *)v10[1];
        *v10 = 0;
        v10[1] = 0;
        *(_QWORD *)(v12 + 8) = v13;
        *v13 = v12;
        sk_skb_reason_drop(0);
        v10 = *(__int64 **)v9;
      }
      while ( *(_QWORD *)v9 != v9 && v10 );
    }
    v14 = *a4;
    v15 = *(_QWORD **)(v9 + 8);
    *v14 = v9;
    v14[1] = v15;
    *(_QWORD *)(v9 + 8) = v14;
    *v15 = v14;
    ++*(_DWORD *)(v9 + 16);
    *a4 = nullptr;
    v17 = jiffies;
    LOBYTE(v15) = *(_BYTE *)(v9 + 39);
    *(_WORD *)(v9 + 32) = v8;
    *(_BYTE *)(v9 + 38) = v7;
    *(_QWORD *)(v9 + 24) = v17;
    *(_BYTE *)(v9 + 39) = (unsigned __int8)v15 & 0xFE;
    *(_DWORD *)(v9 + 34) = 0;
    return v9;
  }
}
