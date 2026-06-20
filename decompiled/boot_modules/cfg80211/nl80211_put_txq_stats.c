__int64 __fastcall nl80211_put_txq_stats(__int64 a1, int *a2, unsigned int a3)
{
  __int64 v5; // x21
  __int64 v6; // x22
  int v7; // w8
  __int64 result; // x0
  _WORD *v9; // x21
  int v10; // w8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 216);
  v6 = *(unsigned int *)(a1 + 208);
  v7 = nla_put(a1, a3, 0, 0);
  result = 0;
  if ( (v7 & 0x80000000) == 0 )
  {
    v9 = (_WORD *)(v5 + v6);
    if ( v9 )
    {
      v10 = *a2;
      if ( (*a2 & 2) != 0 )
      {
        v11 = a2[1];
        if ( (unsigned int)nla_put(a1, 1, 4, &v11) )
          goto LABEL_35;
        v10 = *a2;
      }
      if ( (v10 & 4) != 0 )
      {
        v11 = a2[2];
        if ( (unsigned int)nla_put(a1, 2, 4, &v11) )
          goto LABEL_35;
        v10 = *a2;
      }
      if ( (v10 & 8) != 0 )
      {
        v11 = a2[3];
        if ( (unsigned int)nla_put(a1, 3, 4, &v11) )
          goto LABEL_35;
        v10 = *a2;
      }
      if ( (v10 & 0x10) != 0 )
      {
        v11 = a2[4];
        if ( (unsigned int)nla_put(a1, 4, 4, &v11) )
          goto LABEL_35;
        v10 = *a2;
      }
      if ( (v10 & 0x20) != 0 )
      {
        v11 = a2[5];
        if ( (unsigned int)nla_put(a1, 5, 4, &v11) )
          goto LABEL_35;
        v10 = *a2;
      }
      if ( (v10 & 0x40) != 0 )
      {
        v11 = a2[6];
        if ( (unsigned int)nla_put(a1, 6, 4, &v11) )
          goto LABEL_35;
        v10 = *a2;
      }
      if ( (v10 & 0x80) != 0 )
      {
        v11 = a2[7];
        if ( (unsigned int)nla_put(a1, 7, 4, &v11) )
          goto LABEL_35;
        v10 = *a2;
      }
      if ( (v10 & 0x100) != 0 )
      {
        v11 = a2[8];
        if ( (unsigned int)nla_put(a1, 8, 4, &v11) )
          goto LABEL_35;
        v10 = *a2;
      }
      if ( (v10 & 0x200) != 0 )
      {
        v11 = a2[9];
        if ( (unsigned int)nla_put(a1, 9, 4, &v11) )
          goto LABEL_35;
        v10 = *a2;
      }
      if ( (v10 & 0x400) == 0 )
      {
LABEL_33:
        if ( (v10 & 0x800) == 0 || (v11 = a2[11], !(unsigned int)nla_put(a1, 11, 4, &v11)) )
        {
          result = 1;
          *v9 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v9;
          goto LABEL_36;
        }
        goto LABEL_35;
      }
      v11 = a2[10];
      if ( !(unsigned int)nla_put(a1, 10, 4, &v11) )
      {
        v10 = *a2;
        goto LABEL_33;
      }
LABEL_35:
      result = 0;
    }
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
