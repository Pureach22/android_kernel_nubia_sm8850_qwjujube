__int64 __fastcall nl80211_send_wowlan(__int64 a1, __int64 a2, char a3)
{
  __int64 v5; // x21
  __int64 v6; // x23
  int v8; // w8
  __int64 result; // x0
  _WORD *v10; // x21
  int *v11; // x8
  int v12; // w9
  unsigned int v13; // w9
  unsigned int v14; // w11
  unsigned int v15; // w8
  unsigned int v16; // w10
  unsigned __int64 v17; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a2 + 1240) )
  {
    result = 0;
    goto LABEL_37;
  }
  v5 = *(_QWORD *)(a1 + 216);
  v6 = *(unsigned int *)(a1 + 208);
  v8 = nla_put(a1, 118, 0, 0);
  result = 4294967191LL;
  if ( (v8 & 0x80000000) == 0 )
  {
    v10 = (_WORD *)(v5 + v6);
    if ( v10 )
    {
      v11 = *(int **)(a2 + 1240);
      v12 = *v11;
      if ( (*v11 & 1) != 0 )
      {
        if ( (unsigned int)nla_put(a1, 1, 0, 0) )
          goto LABEL_35;
        v11 = *(int **)(a2 + 1240);
        v12 = *v11;
      }
      if ( (v12 & 4) != 0 )
      {
        if ( (unsigned int)nla_put(a1, 2, 0, 0) )
          goto LABEL_35;
        v11 = *(int **)(a2 + 1240);
        v12 = *v11;
      }
      if ( (v12 & 2) != 0 )
      {
        if ( (unsigned int)nla_put(a1, 3, 0, 0) )
          goto LABEL_35;
        v11 = *(int **)(a2 + 1240);
        v12 = *v11;
      }
      if ( (v12 & 8) != 0 )
      {
        if ( (unsigned int)nla_put(a1, 5, 0, 0) )
          goto LABEL_35;
        v11 = *(int **)(a2 + 1240);
        v12 = *v11;
      }
      if ( (v12 & 0x10) != 0 )
      {
        if ( (unsigned int)nla_put(a1, 6, 0, 0) )
          goto LABEL_35;
        v11 = *(int **)(a2 + 1240);
        v12 = *v11;
      }
      if ( (v12 & 0x20) != 0 )
      {
        if ( (unsigned int)nla_put(a1, 7, 0, 0) )
          goto LABEL_35;
        v11 = *(int **)(a2 + 1240);
        v12 = *v11;
      }
      if ( (v12 & 0x40) != 0 )
      {
        if ( (unsigned int)nla_put(a1, 8, 0, 0) )
          goto LABEL_35;
        v11 = *(int **)(a2 + 1240);
        v12 = *v11;
      }
      if ( (v12 & 0x80) != 0 )
      {
        if ( (unsigned int)nla_put(a1, 9, 0, 0) )
          goto LABEL_35;
        v11 = *(int **)(a2 + 1240);
      }
      if ( !v11[1] )
        goto LABEL_31;
      v17 = 0;
      v18 = 0;
      v13 = v11[1];
      v14 = v11[2];
      v16 = v11[3];
      v15 = v11[4];
      v17 = __PAIR64__(v16, v13);
      v18 = __PAIR64__(v15, v14);
      if ( !(unsigned int)nla_put(a1, 4, 16, &v17) )
      {
        v11 = *(int **)(a2 + 1240);
LABEL_31:
        if ( (*((_BYTE *)v11 + 1) & 1) == 0 || (LODWORD(v17) = v11[5], !(unsigned int)nla_put(a1, 18, 4, &v17)) )
        {
          if ( (a3 & 1) == 0 || !(unsigned int)nl80211_send_wowlan_tcp_caps(a2, a1) )
          {
            result = 0;
            *v10 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v10;
            goto LABEL_37;
          }
        }
      }
LABEL_35:
      result = 4294967191LL;
    }
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
