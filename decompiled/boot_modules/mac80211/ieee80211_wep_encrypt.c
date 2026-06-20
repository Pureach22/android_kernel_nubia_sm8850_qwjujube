__int64 __fastcall ieee80211_wep_encrypt(__int64 a1, __int64 a2, const void *a3, unsigned int a4, unsigned int a5)
{
  int v5; // w8
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x25
  __int64 v13; // x26
  char v14; // w9
  __int64 v15; // x22
  __int64 v16; // x23
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x3
  __int16 v21; // [xsp+8h] [xbp-18h] BYREF
  char v22; // [xsp+Ah] [xbp-16h]
  _BYTE v23[13]; // [xsp+Bh] [xbp-15h] BYREF
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a2 + 116);
  memset(v23, 0, sizeof(v23));
  if ( v5 || *(_DWORD *)(a2 + 212) - *(_DWORD *)(a2 + 208) <= 3 )
  {
    __break(0x800u);
LABEL_3:
    result = 0xFFFFFFFFLL;
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v11 = ieee80211_wep_add_iv(a1, a2, a4, a5);
  if ( !v11 )
    goto LABEL_3;
  v12 = *(unsigned int *)(a2 + 112);
  v13 = *(_QWORD *)(a2 + 224);
  v14 = *(_BYTE *)(v11 + 2);
  v21 = *(_WORD *)v11;
  v22 = v14;
  if ( a4 < 0xE )
  {
    v15 = v11 + 4;
    v16 = v13 - (v11 + 4) + v12;
    memcpy(v23, a3, (int)a4);
    skb_put(a2, 4);
    *(_DWORD *)(v13 + v12) = ~(unsigned int)crc32_le(0xFFFFFFFFLL, v15, v16);
    arc4_setkey(a1 + 2544, &v21, a4 + 3);
    arc4_crypt(a1 + 2544, v15, v15, (unsigned int)(v16 + 4));
    memset((void *)(a1 + 2544), 0, 0x408u);
    result = 0;
    goto LABEL_8;
  }
  v17 = _fortify_panic(17);
  return ieee80211_wep_add_iv(v17, v18, v19, v20);
}
