__int64 __fastcall ieee80211_crypto_aes_cmac_256_encrypt(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 result; // x0
  __int64 v5; // x0
  __int16 *v6; // x9
  __int16 v7; // w10
  __int64 v8; // x11
  __int64 v9; // x12
  int v10; // w3
  __int64 v11; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  _QWORD v20[4]; // [xsp+0h] [xbp-20h] BYREF

  v20[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 24);
  v2 = *(_QWORD *)(a1 + 56);
  memset(v20, 0, 20);
  if ( v1 == 1 )
  {
    if ( *(_QWORD *)(a1 + 8) == a1 + 8 )
      v3 = 0;
    else
      v3 = *(_QWORD *)(a1 + 8);
    if ( *(_QWORD *)(v3 + 72) && (*(_WORD *)(v2 + 552) & 0x400) == 0 )
      goto LABEL_13;
    if ( !*(_DWORD *)(v3 + 116) && (unsigned int)(*(_DWORD *)(v3 + 212) - *(_DWORD *)(v3 + 208)) > 0x19 )
    {
      v5 = skb_put(v3, 26);
      *(_WORD *)v5 = 6220;
      *(_WORD *)(v5 + 2) = *(char *)(v2 + 551);
      _X9 = (unsigned __int64 *)(v2 + 536);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v18 = __ldxr(_X9);
        v19 = v18 + 1;
      }
      while ( __stlxr(v19, _X9) );
      __dmb(0xBu);
      *(_WORD *)(v5 + 4) = v19;
      *(_BYTE *)(v5 + 6) = BYTE2(v19);
      *(_BYTE *)(v5 + 7) = BYTE3(v19);
      *(_BYTE *)(v5 + 8) = BYTE4(v19);
      *(_BYTE *)(v5 + 9) = BYTE5(v19);
      if ( !*(_QWORD *)(v3 + 72) )
      {
        v6 = *(__int16 **)(v3 + 224);
        v7 = *v6;
        v8 = *(_QWORD *)(v6 + 6);
        v9 = *(_QWORD *)(v6 + 2);
        v10 = *(_DWORD *)(v3 + 112) - 24;
        WORD1(v20[2]) = v6[10];
        v11 = *(_QWORD *)(v2 + 56);
        *(_QWORD *)((char *)&v20[1] + 2) = v8;
        LOWORD(v20[0]) = v7 & 0xC7FF;
        *(_QWORD *)((char *)v20 + 2) = v9;
        ieee80211_aes_cmac_256(v11, v20, (__int64)(v6 + 12), v10, v5 + 10);
      }
LABEL_13:
      result = 0;
      goto LABEL_14;
    }
  }
  __break(0x800u);
  result = 1;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
