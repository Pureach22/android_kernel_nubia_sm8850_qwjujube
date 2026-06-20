__int64 __fastcall ieee80211_crypto_aes_gmac_decrypt(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x22
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x8
  bool v9; // cf
  _BOOL4 v10; // w8
  int v11; // w9
  __int16 v12; // w9
  __int64 v13; // x20
  unsigned int v14; // [xsp+8h] [xbp-38h]
  unsigned __int16 v15; // [xsp+Ch] [xbp-34h]
  _QWORD v16[2]; // [xsp+10h] [xbp-30h] BYREF
  _QWORD v17[2]; // [xsp+20h] [xbp-20h] BYREF
  int v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 8);
  v18 = 0;
  v2 = *(_QWORD *)(a1 + 56);
  v17[0] = 0;
  v17[1] = 0;
  v3 = *(_QWORD *)(v1 + 224);
  memset(v16, 0, 12);
  if ( (*(_WORD *)v3 & 0xC) != 0 )
  {
LABEL_2:
    result = 1;
    goto LABEL_20;
  }
  v5 = *(unsigned int *)(v1 + 112);
  result = 65539;
  if ( (unsigned int)v5 < 0x32 )
  {
    result = 65577;
    goto LABEL_20;
  }
  v6 = v3 + v5;
  if ( *(_BYTE *)(v3 + v5 - 26) == 76 && *(_BYTE *)(v6 - 25) == 24 )
  {
    LOBYTE(v14) = *(_BYTE *)(v6 - 17);
    BYTE1(v14) = *(_BYTE *)(v6 - 18);
    HIBYTE(v14) = *(_BYTE *)(v6 - 20);
    BYTE2(v14) = *(_BYTE *)(v6 - 19);
    LOBYTE(v15) = *(_BYTE *)(v6 - 21);
    HIBYTE(v15) = *(_BYTE *)(v6 - 22);
    v7 = bswap64(v14 | ((unsigned __int64)v15 << 32));
    v8 = bswap64(*(unsigned int *)(v2 + 48) | ((unsigned __int64)*(unsigned __int16 *)(v2 + 52) << 32));
    v9 = v7 >= v8;
    v10 = v7 > v8;
    v11 = !v9;
    if ( v10 - v11 <= 0 )
    {
      result = 65538;
      ++*(_DWORD *)(v2 + 64);
      goto LABEL_20;
    }
    if ( (*(_BYTE *)(v1 + 64) & 2) == 0 )
    {
      bip_aad(v1, (__int64)v17);
      v12 = *(_WORD *)(v3 + 14);
      LODWORD(v16[0]) = *(_DWORD *)(v3 + 10);
      WORD2(v16[0]) = v12;
      *(_DWORD *)((char *)v16 + 6) = v14;
      WORD1(v16[1]) = v15;
      v13 = _kmalloc_cache_noprof(_usecs_to_jiffies, 2080, 16);
      if ( !v13 )
      {
        result = 65545;
        goto LABEL_20;
      }
      if ( (ieee80211_aes_gmac(
              *(_QWORD *)(v2 + 56),
              v17,
              (char *)v16,
              *(_QWORD *)(v1 + 224) + 24LL,
              (unsigned int)(*(_DWORD *)(v1 + 112) - 24),
              v13)
          & 0x80000000) != 0
        || _crypto_memneq(v13, v6 - 16) )
      {
        ++*(_DWORD *)(v2 + 68);
        kfree(v13);
        result = 65537;
        goto LABEL_20;
      }
      kfree(v13);
    }
    *(_DWORD *)(v2 + 48) = v14;
    *(_WORD *)(v2 + 52) = v15;
    skb_trim(v1, (unsigned int)(*(_DWORD *)(v1 + 112) - 26));
    goto LABEL_2;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
