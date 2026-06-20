__int64 __fastcall ieee80211_crypto_ccmp_encrypt(__int64 a1, unsigned int a2)
{
  __int64 v4; // x21
  int v5; // w0
  __int64 v6; // x8
  _WORD *v7; // x23
  int v8; // w24
  __int64 v9; // x27
  __int16 v10; // w8
  int v11; // w22
  int v12; // w28
  __int64 v13; // x24
  __int64 v14; // x8
  __int64 v15; // x24
  char v16; // w12
  int v17; // w23
  int *v18; // x22
  __int64 v19; // x0
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  __int64 result; // x0
  _BYTE v29[2]; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v30; // [xsp+2h] [xbp-3Eh]
  _QWORD v31[2]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v32[5]; // [xsp+18h] [xbp-28h] BYREF

  v32[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ieee80211_tx_set_protected(a1);
  v4 = a1 + 8;
  while ( 1 )
  {
    v4 = *(_QWORD *)v4;
    if ( v4 == a1 + 8 )
    {
      result = 0;
      goto LABEL_26;
    }
    v6 = *(_QWORD *)(v4 + 72);
    v7 = *(_WORD **)(v4 + 224);
    v8 = a2;
    v9 = *(_QWORD *)(a1 + 56);
    memset(v32, 0, 32);
    v31[0] = 0;
    v31[1] = 0;
    if ( !v6 )
      break;
    v10 = *(_WORD *)(v6 + 16);
    if ( (v10 & 0x22) != 0 )
    {
      v8 = 0;
      break;
    }
    if ( (v10 & 1) != 0 )
    {
      v8 = 0;
      v5 = 0;
      if ( (*v7 & 0xC) != 0 )
        goto LABEL_3;
      break;
    }
LABEL_2:
    v5 = 0;
LABEL_3:
    if ( v5 < 0 )
      goto LABEL_25;
  }
  v11 = ieee80211_hdrlen((unsigned __int16)*v7);
  if ( *(_DWORD *)(v4 + 116) )
  {
    if ( v8 > 0 )
      goto LABEL_24;
  }
  else if ( *(_DWORD *)(v4 + 212) - *(_DWORD *)(v4 + 208) < v8 )
  {
    goto LABEL_24;
  }
  if ( (((_DWORD)v7 - *(_DWORD *)(v4 + 216)) & 0xFFFFFFF8) != 0 )
  {
    v12 = *(_DWORD *)(v4 + 112);
    v13 = skb_push(v4, 8);
    memmove((void *)v13, (const void *)(v13 + 8), v11);
    v14 = *(_QWORD *)(v4 + 72);
    if ( !v14 || (*(_WORD *)(v14 + 16) & 0x20) == 0 )
    {
      _X9 = (unsigned __int64 *)(v9 + 536);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v26 = __ldxr(_X9);
        v27 = v26 + 1;
      }
      while ( __stlxr(v27, _X9) );
      __dmb(0xBu);
      v30 = bswap32(v27);
      v15 = v13 + v11;
      v16 = *(_BYTE *)(v9 + 551);
      v29[1] = BYTE4(v27);
      v5 = 0;
      v29[0] = BYTE5(v27);
      *(_WORD *)v15 = v27;
      *(_BYTE *)(v15 + 2) = 0;
      *(_BYTE *)(v15 + 3) = (v16 << 6) | 0x20;
      *(_BYTE *)(v15 + 4) = BYTE2(v27);
      *(_BYTE *)(v15 + 5) = BYTE3(v27);
      *(_BYTE *)(v15 + 6) = BYTE4(v27);
      *(_BYTE *)(v15 + 7) = BYTE5(v27);
      if ( !*(_QWORD *)(v4 + 72) )
      {
        v17 = v12 - v11;
        ccmp_special_blocks(v4, v29, v31, v32, (*(unsigned __int16 *)(v9 + 552) >> 11) & 1);
        v18 = *(int **)(v9 + 152);
        v19 = skb_put(v4, a2);
        v5 = aead_encrypt(v18, (__int64)v31, (char *)v32 + 2, bswap32(LOWORD(v32[0])) >> 16, v15 + 8, v17, v19);
      }
      goto LABEL_3;
    }
    goto LABEL_2;
  }
LABEL_24:
  __break(0x800u);
LABEL_25:
  result = 1;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
