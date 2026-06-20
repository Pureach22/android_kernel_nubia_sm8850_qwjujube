__int64 __fastcall nl80211_put_iftype_akm_suites(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x22
  unsigned int v9; // w21
  unsigned int v10; // w24
  __int64 v11; // x25
  __int64 v12; // x26
  int v13; // w8
  _WORD *v14; // x25
  unsigned __int16 *v15; // x26
  __int64 v16; // x21
  __int64 v17; // x28
  unsigned int v18; // w27
  int v19; // w8
  _WORD *v20; // x28
  unsigned int v21; // w21
  bool v22; // cc

  if ( !*(_DWORD *)(a1 + 1184) )
    return 0;
  if ( !*(_QWORD *)(a1 + 1176) )
    return 0;
  v4 = *(_QWORD *)(a2 + 216);
  v5 = *(unsigned int *)(a2 + 208);
  v6 = nla_put(a2, 33052, 0, 0);
  result = 4294967191LL;
  if ( (v6 & 0x80000000) == 0 )
  {
    v8 = (_WORD *)(v4 + v5);
    if ( v8 )
    {
      if ( *(_DWORD *)(a1 + 1184) )
      {
        v9 = 0;
        while ( 1 )
        {
          v10 = v9 + 1;
          v11 = *(_QWORD *)(a2 + 216);
          v12 = *(unsigned int *)(a2 + 208);
          v13 = nla_put(a2, (v9 + 1) | 0x8000, 0, 0);
          result = 4294967191LL;
          if ( v13 < 0 )
            break;
          v14 = (_WORD *)(v11 + v12);
          if ( !v14 )
            break;
          v15 = (unsigned __int16 *)(*(_QWORD *)(a1 + 1176) + 24LL * (int)v9);
          v16 = *(_QWORD *)(a2 + 216);
          v17 = *(unsigned int *)(a2 + 208);
          v18 = *v15;
          v19 = nla_put(a2, 1, 0, 0);
          result = 4294967191LL;
          if ( v19 < 0 )
            break;
          v20 = (_WORD *)(v16 + v17);
          if ( !v20 )
            break;
          if ( v18 )
          {
            v21 = 0;
            while ( (v18 & 1) == 0 || !(unsigned int)nla_put(a2, v21, 0, 0) )
            {
              v22 = v18 > 1;
              ++v21;
              v18 >>= 1;
              if ( !v22 )
                goto LABEL_18;
            }
            return 4294967191LL;
          }
LABEL_18:
          *v20 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v20;
          if ( (unsigned int)nla_put(a2, 2, (unsigned int)(4 * *((_DWORD *)v15 + 4)), *((_QWORD *)v15 + 1)) )
            return 4294967191LL;
          v9 = v10;
          *v14 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v14;
          if ( v10 >= *(_DWORD *)(a1 + 1184) )
            goto LABEL_20;
        }
      }
      else
      {
LABEL_20:
        *v8 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v8;
        return 0;
      }
    }
  }
  return result;
}
