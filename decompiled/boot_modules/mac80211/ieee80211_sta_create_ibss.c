_QWORD *__fastcall ieee80211_sta_create_ibss(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w8
  int v6; // w8
  char v7; // w9
  char v8; // w10
  char v9; // w11
  char v10; // w8
  char v11; // w9
  __int16 v12; // w5
  _QWORD *result; // x0
  int v14; // [xsp+0h] [xbp-10h] BYREF
  __int16 v15; // [xsp+4h] [xbp-Ch]
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned __int8 *)(a1 + 2340);
  v15 = 0;
  v14 = 0;
  if ( v5 == 1 )
  {
    v6 = *(_DWORD *)(a1 + 2346);
    v15 = *(_WORD *)(a1 + 2350);
    v14 = v6;
  }
  else
  {
    get_random_bytes(&v14, 6);
    v7 = BYTE2(v14) ^ *(_BYTE *)(a1 + 5844);
    v8 = HIBYTE(v14) ^ *(_BYTE *)(a1 + 5845);
    v9 = *(_BYTE *)(a1 + 5842);
    BYTE1(v14) ^= *(_BYTE *)(a1 + 5843);
    v10 = *(_BYTE *)(a1 + 5846);
    BYTE2(v14) = v7;
    v11 = *(_BYTE *)(a1 + 5847);
    HIBYTE(v14) = v8;
    LOBYTE(v15) = v15 ^ v10;
    HIBYTE(v15) ^= v11;
    LOBYTE(v14) = (v14 ^ v9) & 0xFC | 2;
  }
  printk(&unk_B901D, a1 + 1640, &v14, a4);
  if ( *(_BYTE *)(a1 + 2342) )
    v12 = 18;
  else
    v12 = 2;
  result = _ieee80211_sta_join_ibss(a1, &v14, *(_WORD *)(a1 + 4858), a1 + 2400, *(_DWORD *)(a1 + 2336), v12, 0, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
