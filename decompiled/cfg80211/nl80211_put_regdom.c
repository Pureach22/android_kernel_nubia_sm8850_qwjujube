__int64 __fastcall nl80211_put_regdom(__int64 a1, __int64 a2)
{
  int v4; // w0
  __int64 result; // x0
  __int64 v6; // x21
  __int64 v7; // x22
  int v8; // w8
  _WORD *v9; // x24
  unsigned __int64 v10; // x21
  int *v11; // x25
  __int64 v12; // x22
  __int64 v13; // x23
  int v14; // w8
  _WORD *v15; // x26
  int max_bandwidth; // w22
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = strlen((const char *)(a1 + 20));
  if ( (unsigned int)nla_put(a2, 33, (unsigned int)(v4 + 1), a1 + 20)
    || *(_DWORD *)(a1 + 24) && (LOBYTE(v17) = *(_DWORD *)(a1 + 24), (unsigned int)nla_put(a2, 146, 1, &v17)) )
  {
LABEL_2:
    result = 4294967206LL;
  }
  else
  {
    v6 = *(_QWORD *)(a2 + 216);
    v7 = *(unsigned int *)(a2 + 208);
    v8 = nla_put(a2, 34, 0, 0);
    result = 4294967206LL;
    if ( (v8 & 0x80000000) == 0 )
    {
      v9 = (_WORD *)(v6 + v7);
      if ( v6 + v7 )
      {
        if ( *(_DWORD *)(a1 + 16) )
        {
          v10 = 0;
          v11 = (int *)(a1 + 112);
          while ( 1 )
          {
            v12 = *(_QWORD *)(a2 + 216);
            v13 = *(unsigned int *)(a2 + 208);
            v14 = nla_put(a2, (unsigned int)v10, 0, 0);
            result = 4294967206LL;
            if ( v14 < 0 )
              break;
            v15 = (_WORD *)(v12 + v13);
            if ( !(v12 + v13) )
              break;
            max_bandwidth = *(v11 - 19);
            if ( !max_bandwidth )
              max_bandwidth = reg_get_max_bandwidth(a1, v11 - 21);
            v17 = *v11;
            if ( (unsigned int)nla_put(a2, 1, 4, &v17) )
              goto LABEL_2;
            v17 = *(v11 - 21);
            if ( (unsigned int)nla_put(a2, 2, 4, &v17) )
              goto LABEL_2;
            v17 = *(v11 - 20);
            if ( (unsigned int)nla_put(a2, 3, 4, &v17) )
              goto LABEL_2;
            v17 = max_bandwidth;
            if ( (unsigned int)nla_put(a2, 4, 4, &v17) )
              goto LABEL_2;
            v17 = *(v11 - 18);
            if ( (unsigned int)nla_put(a2, 5, 4, &v17) )
              goto LABEL_2;
            v17 = *(v11 - 17);
            if ( (unsigned int)nla_put(a2, 6, 4, &v17) )
              goto LABEL_2;
            v17 = v11[1];
            if ( (unsigned int)nla_put(a2, 7, 4, &v17) )
              goto LABEL_2;
            if ( (*((_BYTE *)v11 + 2) & 0x10) != 0 )
            {
              LOBYTE(v17) = *((_BYTE *)v11 + 9);
              if ( (unsigned int)nla_put(a2, 8, 1, &v17) )
                goto LABEL_2;
            }
            ++v10;
            v11 += 24;
            *v15 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v15;
            if ( v10 >= *(unsigned int *)(a1 + 16) )
              goto LABEL_25;
          }
        }
        else
        {
LABEL_25:
          result = 0;
          *v9 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v9;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
