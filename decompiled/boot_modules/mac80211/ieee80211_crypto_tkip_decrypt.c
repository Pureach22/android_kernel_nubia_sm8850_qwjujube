__int64 __fastcall ieee80211_crypto_tkip_decrypt(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x20
  unsigned __int8 *v4; // x23
  __int16 v5; // w22
  int v6; // w0
  int v7; // w22
  __int64 v8; // x8
  __int64 result; // x0
  unsigned int v10; // w9

  v1 = *(_QWORD *)(a1 + 8);
  v3 = *(_QWORD *)(a1 + 56);
  v4 = *(unsigned __int8 **)(v1 + 224);
  v5 = *(_WORD *)v4;
  v6 = ieee80211_hdrlen(*(unsigned __int16 *)v4);
  if ( (v5 & 0xC) != 8 )
    return 1;
  v7 = v6;
  v8 = *(_QWORD *)(a1 + 40);
  result = 65569;
  if ( v8 )
  {
    v10 = *(_DWORD *)(v1 + 112) - v7;
    if ( v10 >= 0xC )
    {
      if ( *(_DWORD *)(v1 + 116) )
      {
        if ( !_pskb_pull_tail(v1) )
          return 65545;
        v4 = *(unsigned __int8 **)(v1 + 224);
        v8 = *(_QWORD *)(a1 + 40);
        v10 = *(_DWORD *)(v1 + 112) - v7;
      }
      if ( (unsigned int)ieee80211_tkip_decrypt_data(
                           *(_QWORD *)(a1 + 16) + 3576LL,
                           v3,
                           &v4[v7],
                           v10,
                           (unsigned __int16 *)(v8 + 2688),
                           (__int64)(v4 + 4),
                           (*(_DWORD *)(v1 + 64) >> 1) & 1,
                           *(_DWORD *)(a1 + 72),
                           (unsigned int *)(a1 + 80),
                           (_WORD *)(a1 + 84)) )
        return 65570;
      if ( (*(_BYTE *)(v1 + 66) & 0x80) == 0 )
        skb_trim(v1, (unsigned int)(*(_DWORD *)(v1 + 112) - 4));
      memmove((void *)(*(_QWORD *)(v1 + 224) + 8LL), *(const void **)(v1 + 224), v7);
      skb_pull(v1, 8);
      return 1;
    }
  }
  return result;
}
