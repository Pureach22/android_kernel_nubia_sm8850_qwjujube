__int64 __fastcall nl80211_send_pmsr_capa(__int64 a1, __int64 a2)
{
  int *v2; // x21
  __int64 v4; // x20
  __int64 v5; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x20
  char v9; // w8
  __int64 v10; // x22
  __int64 v11; // x23
  int v12; // w8
  _WORD *v13; // x22
  __int64 v14; // x23
  __int64 v15; // x24
  int v16; // w8
  _WORD *v17; // x23
  char v18; // w8
  char v19; // w8
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(int **)(a1 + 2424);
  if ( !v2 )
  {
    result = 0;
    goto LABEL_7;
  }
  v4 = *(_QWORD *)(a2 + 216);
  v5 = *(unsigned int *)(a2 + 208);
  v6 = nla_put(a2, 273, 0, 0);
  result = 4294967191LL;
  if ( (v6 & 0x80000000) == 0 )
  {
    v8 = (_WORD *)(v4 + v5);
    if ( v8 )
    {
      v20 = *v2;
      if ( (unsigned int)nla_put(a2, 1, 4, &v20) )
      {
LABEL_5:
        result = 4294967191LL;
        goto LABEL_7;
      }
      v9 = *((_BYTE *)v2 + 4);
      if ( (v9 & 1) != 0 )
      {
        if ( (unsigned int)nla_put(a2, 2, 0, 0) )
          goto LABEL_5;
        v9 = *((_BYTE *)v2 + 4);
      }
      if ( (v9 & 2) != 0 && (unsigned int)nla_put(a2, 3, 0, 0) )
        goto LABEL_5;
      v10 = *(_QWORD *)(a2 + 216);
      v11 = *(unsigned int *)(a2 + 208);
      v12 = nla_put(a2, 4, 0, 0);
      result = 4294967191LL;
      if ( (v12 & 0x80000000) == 0 )
      {
        v13 = (_WORD *)(v10 + v11);
        if ( v13 )
        {
          if ( (*((_BYTE *)v2 + 18) & 1) == 0 )
            goto LABEL_16;
          v14 = *(_QWORD *)(a2 + 216);
          v15 = *(unsigned int *)(a2 + 208);
          v16 = nla_put(a2, 1, 0, 0);
          result = 4294967191LL;
          if ( (v16 & 0x80000000) == 0 )
          {
            v17 = (_WORD *)(v14 + v15);
            if ( v17 )
            {
              v18 = *((_BYTE *)v2 + 18);
              if ( (v18 & 2) != 0 )
              {
                if ( (unsigned int)nla_put(a2, 1, 0, 0) )
                  goto LABEL_5;
                v18 = *((_BYTE *)v2 + 18);
              }
              if ( (v18 & 4) != 0 )
              {
                if ( (unsigned int)nla_put(a2, 2, 0, 0) )
                  goto LABEL_5;
                v18 = *((_BYTE *)v2 + 18);
              }
              if ( (v18 & 8) != 0 )
              {
                if ( (unsigned int)nla_put(a2, 3, 0, 0) )
                  goto LABEL_5;
                v18 = *((_BYTE *)v2 + 18);
              }
              if ( (v18 & 0x10) != 0 && (unsigned int)nla_put(a2, 4, 0, 0) )
                goto LABEL_5;
              v20 = v2[2];
              if ( (unsigned int)nla_put(a2, 5, 4, &v20) )
                goto LABEL_5;
              v20 = v2[3];
              if ( (unsigned int)nla_put(a2, 6, 4, &v20) )
                goto LABEL_5;
              if ( ((char)v2[4] & 0x80000000) == 0 )
              {
                v20 = *((char *)v2 + 16);
                if ( (unsigned int)nla_put(a2, 7, 4, &v20) )
                  goto LABEL_5;
              }
              if ( *((_BYTE *)v2 + 17) )
              {
                v20 = *((unsigned __int8 *)v2 + 17);
                if ( (unsigned int)nla_put(a2, 8, 4, &v20) )
                  goto LABEL_5;
              }
              v19 = *((_BYTE *)v2 + 18);
              if ( (v19 & 0x20) != 0 )
              {
                if ( (unsigned int)nla_put(a2, 9, 0, 0) )
                  goto LABEL_5;
                v19 = *((_BYTE *)v2 + 18);
              }
              if ( (v19 & 0x40) != 0 && (unsigned int)nla_put(a2, 10, 0, 0) )
                goto LABEL_5;
              *v17 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v17;
LABEL_16:
              result = 0;
              *v13 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v13;
              *v8 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v8;
            }
          }
        }
      }
    }
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
