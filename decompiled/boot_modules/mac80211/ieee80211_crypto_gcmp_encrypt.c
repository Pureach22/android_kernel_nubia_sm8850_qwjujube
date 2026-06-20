__int64 __fastcall ieee80211_crypto_gcmp_encrypt(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w0
  __int64 v4; // x8
  _WORD *v5; // x22
  __int64 v6; // x25
  __int16 v7; // w8
  int v8; // w23
  int v9; // w21
  int v10; // w26
  __int64 v11; // x23
  __int64 v12; // x8
  char v13; // w12
  __int64 v14; // x23
  int v15; // w22
  int *v16; // x21
  __int64 v17; // x0
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x8
  __int64 result; // x0
  _BYTE v27[2]; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v28; // [xsp+2h] [xbp-3Eh]
  _QWORD v29[2]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v30[5]; // [xsp+18h] [xbp-28h] BYREF

  v30[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ieee80211_tx_set_protected(a1);
  v2 = a1 + 8;
  while ( 1 )
  {
    v2 = *(_QWORD *)v2;
    if ( v2 == a1 + 8 )
    {
      result = 0;
      goto LABEL_27;
    }
    v4 = *(_QWORD *)(v2 + 72);
    v5 = *(_WORD **)(v2 + 224);
    v6 = *(_QWORD *)(a1 + 56);
    memset(v30, 0, 32);
    v29[0] = 0;
    v29[1] = 0;
    if ( !v4 )
    {
      v8 = 16;
      goto LABEL_9;
    }
    v7 = *(_WORD *)(v4 + 16);
    if ( (v7 & 0x22) != 0 )
    {
      v8 = 0;
      goto LABEL_9;
    }
    if ( (v7 & 1) != 0 )
      break;
LABEL_2:
    v3 = 0;
LABEL_3:
    if ( v3 < 0 )
      goto LABEL_26;
  }
  v8 = 0;
  v3 = 0;
  if ( (*v5 & 0xC) != 0 )
    goto LABEL_3;
LABEL_9:
  v9 = ieee80211_hdrlen((unsigned __int16)*v5);
  if ( *(_DWORD *)(v2 + 116) )
  {
    if ( v8 > 0 )
      goto LABEL_25;
  }
  else if ( *(_DWORD *)(v2 + 212) - *(_DWORD *)(v2 + 208) < v8 )
  {
    goto LABEL_25;
  }
  if ( (((_DWORD)v5 - *(_DWORD *)(v2 + 216)) & 0xFFFFFFF8) != 0 )
  {
    v10 = *(_DWORD *)(v2 + 112);
    v11 = skb_push(v2, 8);
    memmove((void *)v11, (const void *)(v11 + 8), v9);
    v12 = *(_QWORD *)(v2 + 72);
    *(_WORD *)(v2 + 184) += 8;
    if ( !v12 || (*(_WORD *)(v12 + 16) & 0x20) == 0 )
    {
      _X9 = (unsigned __int64 *)(v6 + 536);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v24 = __ldxr(_X9);
        v25 = v24 + 1;
      }
      while ( __stlxr(v25, _X9) );
      __dmb(0xBu);
      v28 = bswap32(v25);
      v13 = *(_BYTE *)(v6 + 551);
      v14 = v11 + v9;
      v27[1] = BYTE4(v25);
      v3 = 0;
      v27[0] = BYTE5(v25);
      *(_WORD *)v14 = v25;
      *(_BYTE *)(v14 + 2) = 0;
      *(_BYTE *)(v14 + 3) = (v13 << 6) | 0x20;
      *(_BYTE *)(v14 + 4) = BYTE2(v25);
      *(_BYTE *)(v14 + 5) = BYTE3(v25);
      *(_BYTE *)(v14 + 6) = BYTE4(v25);
      *(_BYTE *)(v14 + 7) = BYTE5(v25);
      if ( !*(_QWORD *)(v2 + 72) )
      {
        v15 = v10 - v9;
        gcmp_special_blocks(v2, v27, v29, v30, (*(unsigned __int16 *)(v6 + 552) >> 11) & 1);
        v16 = *(int **)(v6 + 152);
        v17 = skb_put(v2, 16);
        v3 = aead_encrypt(v16, (__int64)v29, (char *)v30 + 2, bswap32(LOWORD(v30[0])) >> 16, v14 + 8, v15, v17);
      }
      goto LABEL_3;
    }
    goto LABEL_2;
  }
LABEL_25:
  __break(0x800u);
LABEL_26:
  result = 1;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
