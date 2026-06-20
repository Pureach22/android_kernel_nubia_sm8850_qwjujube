__int64 __fastcall ieee80211_reassemble_find(__int64 a1, __int64 *a2, __int64 a3, int a4, __int64 a5)
{
  unsigned int v5; // w26
  int v8; // w21
  __int64 v9; // x22
  int v10; // w23
  int v11; // w25
  __int64 v12; // x24
  __int64 v13; // x8
  __int64 v14; // x8
  _QWORD *v15; // x9

  v5 = *(_DWORD *)(a1 + 224);
  v8 = a3;
  v9 = a1;
  v10 = (int)a2;
  v11 = 0;
  while ( 1 )
  {
    if ( (int)(v5 - 1) >= 0 )
      --v5;
    else
      v5 = 3;
    if ( v5 >= 5 )
      break;
    v12 = v9 + 56LL * v5;
    a2 = *(__int64 **)v12;
    if ( *(_QWORD *)v12 != v12
      && *(unsigned __int16 *)(v12 + 32) == v8
      && *(unsigned __int8 *)(v12 + 38) == a4
      && *(unsigned __int16 *)(v12 + 36) + 1 == v10 )
    {
      v13 = a2[28];
      if ( ((*(_WORD *)v13 ^ *(_WORD *)a5) & 0xC) == 0
        && !(*(_DWORD *)(v13 + 4) ^ *(_DWORD *)(a5 + 4) | *(unsigned __int16 *)(v13 + 8) ^ *(unsigned __int16 *)(a5 + 8))
        && !(*(_DWORD *)(v13 + 10) ^ *(_DWORD *)(a5 + 10)
           | *(unsigned __int16 *)(v13 + 14) ^ *(unsigned __int16 *)(a5 + 14)) )
      {
        if ( *(_QWORD *)(v12 + 24) - jiffies + 500LL >= 0 )
          return v12;
        if ( a2 )
        {
          do
          {
            --*(_DWORD *)(v12 + 16);
            v14 = *a2;
            v15 = (_QWORD *)a2[1];
            *a2 = 0;
            a2[1] = 0;
            *(_QWORD *)(v14 + 8) = v15;
            *v15 = v14;
            a1 = sk_skb_reason_drop(0);
            a2 = *(__int64 **)v12;
          }
          while ( *(_QWORD *)v12 != v12 && a2 );
        }
      }
    }
    if ( ++v11 == 4 )
      return 0;
  }
  __break(0x5512u);
  return skb_put_data_0(a1, a2, a3);
}
