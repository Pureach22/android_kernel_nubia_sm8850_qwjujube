__int64 __fastcall nl80211_msg_put_wmm_rules(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  __int64 v5; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x22
  __int64 v9; // x20
  _BYTE *v10; // x21
  __int64 v11; // x23
  __int64 v12; // x24
  int v13; // w8
  _WORD *v14; // x23
  _WORD v15[2]; // [xsp+8h] [xbp-18h] BYREF
  __int16 v16; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v17[4]; // [xsp+10h] [xbp-10h] BYREF
  __int16 v18; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 216);
  v5 = *(unsigned int *)(a1 + 208);
  v6 = nla_put(a1, 18, 0, 0);
  result = 4294967191LL;
  if ( (v6 & 0x80000000) == 0 )
  {
    v8 = (_WORD *)(v4 + v5);
    if ( v8 )
    {
      v9 = 0;
      v10 = (_BYTE *)(a2 + 26);
      while ( 1 )
      {
        v11 = *(_QWORD *)(a1 + 216);
        v12 = *(unsigned int *)(a1 + 208);
        v13 = nla_put(a1, (unsigned int)v9, 0, 0);
        result = 4294967191LL;
        if ( v13 < 0 )
          break;
        v14 = (_WORD *)(v11 + v12);
        if ( !v14 )
          break;
        v15[0] = *((_WORD *)v10 - 3);
        if ( (unsigned int)nla_put(a1, 1, 2, v15)
          || (v16 = *((_WORD *)v10 - 2), (unsigned int)nla_put(a1, 2, 2, &v16))
          || (v17[0] = *v10, (unsigned int)nla_put(a1, 3, 1, v17))
          || (v18 = *((_WORD *)v10 - 1), (unsigned int)nla_put(a1, 4, 2, &v18)) )
        {
          result = 4294967191LL;
          break;
        }
        ++v9;
        v10 += 8;
        *v14 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v14;
        if ( v9 == 4 )
        {
          result = 0;
          *v8 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v8;
          break;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
