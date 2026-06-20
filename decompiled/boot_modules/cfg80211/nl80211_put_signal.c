__int64 __fastcall nl80211_put_signal(__int64 a1, char a2, _BYTE *a3, unsigned int a4)
{
  __int64 v6; // x22
  __int64 v7; // x23
  int v9; // w8
  __int64 result; // x0
  _WORD *v11; // x22
  int v12; // w8
  _BYTE v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_14;
  v6 = *(_QWORD *)(a1 + 216);
  v7 = *(unsigned int *)(a1 + 208);
  v9 = nla_put(a1, a4, 0, 0);
  result = 0;
  if ( (v9 & 0x80000000) == 0 )
  {
    v11 = (_WORD *)(v6 + v7);
    if ( v11 )
    {
      if ( (a2 & 1) == 0 || (v13[0] = *a3, v12 = nla_put(a1, 0, 1, v13), result = 0, !v12) )
      {
        if ( (a2 & 2) != 0 && (v13[0] = a3[1], (unsigned int)nla_put(a1, 1, 1, v13))
          || (a2 & 4) != 0 && (v13[0] = a3[2], (unsigned int)nla_put(a1, 2, 1, v13))
          || (a2 & 8) != 0 && (v13[0] = a3[3], (unsigned int)nla_put(a1, 3, 1, v13)) )
        {
          result = 0;
          goto LABEL_15;
        }
        *v11 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v11;
LABEL_14:
        result = 1;
      }
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
