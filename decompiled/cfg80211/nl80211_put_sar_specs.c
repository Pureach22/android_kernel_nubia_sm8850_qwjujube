__int64 __fastcall nl80211_put_sar_specs(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v5; // x24
  __int64 v6; // x21
  __int64 v7; // x22
  int v8; // w8
  __int64 result; // x0
  _WORD *v10; // x21
  unsigned __int64 v11; // x8
  __int64 v12; // x22
  __int64 v13; // x23
  _WORD *v14; // x22
  __int64 v15; // x24
  __int64 v16; // x23
  int v17; // w25
  __int64 v18; // x26
  __int64 v19; // x27
  _WORD *v20; // x26
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 2464);
  if ( v2 )
  {
    v5 = *(unsigned __int8 *)(v2 + 4);
    v6 = *(_QWORD *)(a2 + 216);
    v7 = *(unsigned int *)(a2 + 208);
    v8 = nla_put(a2, 33068, 0, 0);
    result = 4294967268LL;
    if ( (v8 & 0x80000000) == 0 )
    {
      v10 = (_WORD *)(v6 + v7);
      if ( v10 )
      {
        v21 = **(_DWORD **)(a1 + 2464);
        if ( !(unsigned int)nla_put(a2, 1, 4, &v21) )
        {
          v12 = *(_QWORD *)(a2 + 216);
          v13 = *(unsigned int *)(a2 + 208);
          if ( (nla_put(a2, 32770, 0, 0) & 0x80000000) == 0 )
          {
            v14 = (_WORD *)(v12 + v13);
            if ( v14 )
            {
              if ( !(_DWORD)v5 )
              {
LABEL_19:
                result = 0;
                *v14 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v14;
                *v10 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v10;
                goto LABEL_9;
              }
              v15 = 8 * v5;
              v16 = 0;
              v17 = 1;
              while ( 1 )
              {
                v18 = *(_QWORD *)(a2 + 216);
                v19 = *(unsigned int *)(a2 + 208);
                if ( (nla_put(a2, v17 | 0x8000u, 0, 0) & 0x80000000) != 0 )
                  break;
                v20 = (_WORD *)(v18 + v19);
                if ( !v20 )
                  break;
                v21 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 2464) + 8LL) + v16);
                if ( (unsigned int)nla_put(a2, 3, 4, &v21) )
                  break;
                v21 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 2464) + 8LL) + v16 + 4);
                if ( (unsigned int)nla_put(a2, 4, 4, &v21) )
                  break;
                v16 += 8;
                ++v17;
                *v20 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v20;
                if ( v15 == v16 )
                  goto LABEL_19;
              }
            }
          }
        }
        v11 = *(_QWORD *)(a2 + 224);
        if ( v11 > (unsigned __int64)v10 )
        {
          __break(0x800u);
          v11 = *(_QWORD *)(a2 + 224);
        }
        skb_trim(a2, (unsigned int)((_DWORD)v10 - v11));
        result = 4294967191LL;
      }
    }
  }
  else
  {
    result = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
