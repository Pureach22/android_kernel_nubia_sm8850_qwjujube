__int64 __fastcall ieee80211_release_reorder_frame(__int64 result, unsigned int a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v4; // x19
  char v5; // w20
  __int64 *v6; // x1
  __int64 v7; // x8
  unsigned __int64 v8; // x9
  __int64 *i; // x8
  __int64 v10; // x9
  _QWORD *v11; // x10
  __int64 **v12; // x9
  __int64 v13; // x8
  _QWORD *v14; // x9
  __int64 v15; // x8

  v3 = *(_QWORD *)(result + 32) + 24LL * a2;
  v4 = result;
  v5 = a2;
  v6 = *(__int64 **)v3;
  if ( *(_QWORD *)v3 != v3 )
  {
    v7 = *(_QWORD *)(v3 + 8);
    v8 = *(_QWORD *)(result + 24);
    if ( v7 == v3 )
      v7 = 0;
    if ( v8 && ((v8 >> v5) & 1) != 0 || v7 && (*(_BYTE *)(v7 + 66) & 8) == 0 )
    {
      --*(_WORD *)(result + 146);
      for ( i = *(__int64 **)v3; *(_QWORD *)v3 != v3 && i; i = *(__int64 **)v3 )
      {
        --*(_DWORD *)(v3 + 16);
        v10 = *i;
        v11 = (_QWORD *)i[1];
        *i = 0;
        i[1] = 0;
        *(_QWORD *)(v10 + 8) = v11;
        *v11 = v10;
        *((_BYTE *)i + 75) |= 0x20u;
        v12 = *(__int64 ***)(a3 + 8);
        *i = a3;
        i[1] = (__int64)v12;
        *(_QWORD *)(a3 + 8) = i;
        *v12 = i;
        ++*(_DWORD *)(a3 + 16);
      }
    }
    else if ( v6 )
    {
      do
      {
        --*(_DWORD *)(v3 + 16);
        v13 = *v6;
        v14 = (_QWORD *)v6[1];
        *v6 = 0;
        v6[1] = 0;
        *(_QWORD *)(v13 + 8) = v14;
        *v14 = v13;
        result = sk_skb_reason_drop(0);
        v6 = *(__int64 **)v3;
      }
      while ( *(_QWORD *)v3 != v3 && v6 );
    }
  }
  v15 = *(_QWORD *)(v4 + 24);
  if ( v15 )
    *(_QWORD *)(v4 + 24) = v15 & ~(1LL << v5);
  *(_WORD *)(v4 + 144) = (*(_WORD *)(v4 + 144) + 1) & 0xFFF;
  return result;
}
