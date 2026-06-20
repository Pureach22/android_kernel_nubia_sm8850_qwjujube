__int64 __fastcall ieee80211_crypto_aes_gmac_encrypt(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 result; // x0
  __int64 v5; // x0
  __int16 *v6; // x14
  __int16 v7; // w15
  __int64 v8; // x16
  __int64 v9; // x17
  __int16 v10; // w13
  __int16 v11; // w13
  int v12; // w12
  int v13; // w10
  __int64 v14; // x8
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x9
  __int64 v23; // [xsp+0h] [xbp-30h] BYREF
  int v24; // [xsp+8h] [xbp-28h]
  _QWORD v25[4]; // [xsp+10h] [xbp-20h] BYREF

  v25[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 24);
  v2 = *(_QWORD *)(a1 + 56);
  memset(v25, 0, 20);
  v24 = 0;
  v23 = 0;
  if ( v1 == 1 )
  {
    if ( *(_QWORD *)(a1 + 8) == a1 + 8 )
      v3 = 0;
    else
      v3 = *(_QWORD *)(a1 + 8);
    if ( *(_QWORD *)(v3 + 72) && (*(_WORD *)(v2 + 552) & 0x400) == 0 )
    {
LABEL_12:
      result = 0;
      goto LABEL_13;
    }
    if ( !*(_DWORD *)(v3 + 116) && (unsigned int)(*(_DWORD *)(v3 + 212) - *(_DWORD *)(v3 + 208)) > 0x19 )
    {
      v5 = skb_put(v3, 26);
      *(_WORD *)v5 = 6220;
      *(_WORD *)(v5 + 2) = *(char *)(v2 + 551);
      _X8 = (unsigned __int64 *)(v2 + 536);
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v21 = __ldxr(_X8);
        v22 = v21 + 1;
      }
      while ( __stlxr(v22, _X8) );
      __dmb(0xBu);
      *(_WORD *)(v5 + 4) = v22;
      *(_BYTE *)(v5 + 6) = BYTE2(v22);
      *(_BYTE *)(v5 + 7) = BYTE3(v22);
      *(_BYTE *)(v5 + 8) = BYTE4(v22);
      *(_BYTE *)(v5 + 9) = BYTE5(v22);
      if ( !*(_QWORD *)(v3 + 72) )
      {
        v6 = *(__int16 **)(v3 + 224);
        v7 = *v6;
        v8 = *(_QWORD *)(v6 + 2);
        v9 = *(_QWORD *)(v6 + 6);
        BYTE6(v23) = BYTE5(v22);
        v10 = v6[10];
        HIBYTE(v23) = BYTE4(v22);
        *(_QWORD *)((char *)&v25[1] + 2) = v9;
        WORD1(v25[2]) = v10;
        v11 = v6[7];
        LOWORD(v25[0]) = v7 & 0xC7FF;
        v12 = *(_DWORD *)(v6 + 5);
        BYTE1(v24) = BYTE2(v22);
        v13 = *(_DWORD *)(v3 + 112);
        BYTE2(v24) = BYTE1(v22);
        v14 = *(_QWORD *)(v2 + 56);
        *(_QWORD *)((char *)v25 + 2) = v8;
        WORD2(v23) = v11;
        LODWORD(v23) = v12;
        LOBYTE(v24) = BYTE3(v22);
        HIBYTE(v24) = v22;
        result = (unsigned int)ieee80211_aes_gmac(
                                 v14,
                                 v25,
                                 (char *)&v23,
                                 (__int64)(v6 + 12),
                                 (unsigned int)(v13 - 24),
                                 v5 + 10) >> 31;
        goto LABEL_13;
      }
      goto LABEL_12;
    }
  }
  __break(0x800u);
  result = 1;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
