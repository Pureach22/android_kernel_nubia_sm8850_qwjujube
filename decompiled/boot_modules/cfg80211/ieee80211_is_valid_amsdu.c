bool __fastcall ieee80211_is_valid_amsdu(__int64 a1, unsigned __int8 a2)
{
  unsigned int v2; // w8
  unsigned int v5; // w21
  int v6; // w26
  unsigned __int16 v7; // w8
  int v8; // w9
  __int16 v9; // w10
  __int16 v10; // w9
  char v11; // w9
  int v12; // w8
  _BOOL8 result; // x0
  unsigned int v14; // w10
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 112);
  if ( v2 )
  {
    v5 = 0;
    while ( 1 )
    {
      v6 = v2 - v5;
      v15 = 0;
      if ( v2 - v5 < 4 || (skb_copy_bits(a1, v5 + 12, &v15, 4) & 0x80000000) != 0 )
        break;
      v7 = v15;
      if ( a2 > 1u || (v7 = __rev16((unsigned __int16)v15), a2) )
      {
        v8 = BYTE2(v15) & 3;
        if ( v8 == 1 )
          v9 = 12;
        else
          v9 = 6;
        if ( v8 == 2 )
          v10 = 18;
        else
          v10 = v9;
        v7 += v10;
      }
      v11 = v7;
      v12 = v7 + 14;
      result = v12 <= v6;
      if ( v12 <= v6 )
      {
        v14 = v12 + v5;
        v2 = *(_DWORD *)(a1 + 112);
        v5 = v14 + ((2 - v11) & 3);
        if ( v5 < v2 )
          continue;
      }
      goto LABEL_19;
    }
    result = 0;
  }
  else
  {
    result = 1;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
