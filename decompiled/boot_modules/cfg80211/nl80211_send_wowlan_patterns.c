__int64 __fastcall nl80211_send_wowlan_patterns(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v3; // x20
  __int64 v4; // x21
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x23
  __int64 v9; // x24
  __int64 v10; // x20
  __int64 v11; // x21
  __int64 v12; // x25
  int v13; // w8
  _WORD *v14; // x25
  __int64 v15; // x8
  unsigned int v16; // w21
  int v17; // w9
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 1248);
  if ( *(_DWORD *)(v2 + 24) )
  {
    v3 = *(_QWORD *)(a1 + 216);
    v4 = *(unsigned int *)(a1 + 208);
    v6 = nla_put(a1, 4, 0, 0);
    result = 4294967191LL;
    if ( (v6 & 0x80000000) == 0 )
    {
      v8 = (_WORD *)(v3 + v4);
      if ( v3 + v4 )
      {
        if ( *(int *)(v2 + 24) < 1 )
        {
LABEL_14:
          result = 0;
          *v8 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v8;
        }
        else
        {
          v9 = 0;
          v10 = 0;
          while ( 1 )
          {
            ++v10;
            v11 = *(_QWORD *)(a1 + 216);
            v12 = *(unsigned int *)(a1 + 208);
            v13 = nla_put(a1, (unsigned int)v10, 0, 0);
            result = 4294967191LL;
            if ( v13 < 0 )
              break;
            v14 = (_WORD *)(v11 + v12);
            if ( !v14 )
              break;
            v15 = *(_QWORD *)(v2 + 8) + v9;
            v16 = *(_DWORD *)(v15 + 16);
            v17 = v16 + 7;
            if ( (int)(v16 + 7) < 0 )
              v17 = v16 + 14;
            if ( (unsigned int)nla_put(a1, 1, (unsigned int)(v17 >> 3), *(_QWORD *)v15)
              || (unsigned int)nla_put(a1, 2, v16, *(_QWORD *)(*(_QWORD *)(v2 + 8) + v9 + 8))
              || (v18 = *(_DWORD *)(*(_QWORD *)(v2 + 8) + v9 + 20), (unsigned int)nla_put(a1, 3, 4, &v18)) )
            {
              result = 4294967191LL;
              break;
            }
            v9 += 24;
            *v14 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v14;
            if ( v10 >= *(int *)(v2 + 24) )
              goto LABEL_14;
          }
        }
      }
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
