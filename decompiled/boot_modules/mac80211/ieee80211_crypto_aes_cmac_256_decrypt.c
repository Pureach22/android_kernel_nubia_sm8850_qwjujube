__int64 __fastcall ieee80211_crypto_aes_cmac_256_decrypt(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  _WORD *v3; // x8
  __int64 result; // x0
  __int64 v5; // x9
  char *v6; // x21
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x8
  bool v9; // cf
  _BOOL4 v10; // w8
  int v11; // w9
  unsigned int v12; // [xsp+8h] [xbp-38h]
  unsigned __int16 v13; // [xsp+Ch] [xbp-34h]
  _QWORD v14[2]; // [xsp+10h] [xbp-30h] BYREF
  _QWORD v15[2]; // [xsp+20h] [xbp-20h] BYREF
  int v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 8);
  v16 = 0;
  v2 = *(_QWORD *)(a1 + 56);
  v15[0] = 0;
  v15[1] = 0;
  v3 = *(_WORD **)(v1 + 224);
  v14[0] = 0;
  v14[1] = 0;
  if ( (*v3 & 0xC) != 0 )
  {
LABEL_2:
    result = 1;
    goto LABEL_16;
  }
  v5 = *(unsigned int *)(v1 + 112);
  result = 65539;
  if ( (unsigned int)v5 < 0x32 )
  {
    result = 65576;
    goto LABEL_16;
  }
  v6 = (char *)v3 + v5;
  if ( *((_BYTE *)v3 + v5 - 26) == 76 && *(v6 - 25) == 24 )
  {
    LOBYTE(v12) = *(v6 - 17);
    BYTE1(v12) = *(v6 - 18);
    HIBYTE(v12) = *(v6 - 20);
    BYTE2(v12) = *(v6 - 19);
    LOBYTE(v13) = *(v6 - 21);
    HIBYTE(v13) = *(v6 - 22);
    v7 = bswap64(v12 | ((unsigned __int64)v13 << 32));
    v8 = bswap64(*(unsigned int *)(v2 + 48) | ((unsigned __int64)*(unsigned __int16 *)(v2 + 52) << 32));
    v9 = v7 >= v8;
    v10 = v7 > v8;
    v11 = !v9;
    if ( v10 - v11 <= 0 )
    {
      result = 65538;
      ++*(_DWORD *)(v2 + 64);
      goto LABEL_16;
    }
    if ( (*(_BYTE *)(v1 + 64) & 2) == 0 )
    {
      bip_aad(v1, (__int64)v15);
      ieee80211_aes_cmac_256(
        *(_QWORD *)(v2 + 56),
        v15,
        *(_QWORD *)(v1 + 224) + 24LL,
        *(_DWORD *)(v1 + 112) - 24,
        (__int64)v14);
      if ( _crypto_memneq(v14, v6 - 16) )
      {
        result = 65537;
        ++*(_DWORD *)(v2 + 68);
        goto LABEL_16;
      }
    }
    *(_DWORD *)(v2 + 48) = v12;
    *(_WORD *)(v2 + 52) = v13;
    skb_trim(v1, (unsigned int)(*(_DWORD *)(v1 + 112) - 26));
    goto LABEL_2;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
