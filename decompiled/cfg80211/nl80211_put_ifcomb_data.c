__int64 __fastcall nl80211_put_ifcomb_data(__int64 a1, char a2, unsigned int a3, __int64 a4, unsigned __int16 a5)
{
  int v5; // w22
  __int64 v9; // x23
  __int64 v10; // x24
  int v11; // w8
  __int64 result; // x0
  _WORD *v13; // x24
  __int64 v14; // x23
  __int64 v15; // x25
  int v16; // w8
  _WORD *v17; // x25
  unsigned __int64 v18; // x23
  unsigned __int64 v19; // x22
  __int64 v20; // x26
  __int64 v21; // x27
  int v22; // w8
  _WORD *v23; // x26
  __int64 v24; // x28
  __int64 v25; // x8
  __int64 v26; // x23
  unsigned int v27; // w27
  int v28; // w8
  _WORD *v29; // x28
  unsigned int v30; // w23
  bool v31; // cc
  int v32; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v5 = a5;
  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 216);
  v10 = *(unsigned int *)(a1 + 208);
  v11 = nla_put(a1, a5 | a3, 0, 0);
  result = 4294967191LL;
  if ( (v11 & 0x80000000) == 0 )
  {
    v13 = (_WORD *)(v9 + v10);
    if ( v13 )
    {
      v14 = *(_QWORD *)(a1 + 216);
      v15 = *(unsigned int *)(a1 + 208);
      v16 = nla_put(a1, v5 | 1u, 0, 0);
      result = 4294967191LL;
      if ( (v16 & 0x80000000) == 0 )
      {
        v17 = (_WORD *)(v14 + v15);
        if ( v17 )
        {
          if ( *(_BYTE *)(a4 + 14) )
          {
            v18 = 0;
            while ( 1 )
            {
              v19 = v18 + 1;
              v20 = *(_QWORD *)(a1 + 216);
              v21 = *(unsigned int *)(a1 + 208);
              v22 = nla_put(a1, (unsigned int)(v18 + 1), 0, 0);
              result = 4294967191LL;
              if ( v22 < 0 )
                break;
              v23 = (_WORD *)(v20 + v21);
              if ( !v23 )
                break;
              v32 = *(unsigned __int16 *)(*(_QWORD *)a4 + 4 * v18);
              if ( (unsigned int)nla_put(a1, 1, 4, &v32) )
                goto LABEL_24;
              v24 = *(unsigned int *)(a1 + 208);
              v25 = *(_QWORD *)a4 + 4 * v18;
              v26 = *(_QWORD *)(a1 + 216);
              v27 = *(unsigned __int16 *)(v25 + 2);
              v28 = nla_put(a1, 2, 0, 0);
              result = 4294967191LL;
              if ( v28 < 0 )
                break;
              v29 = (_WORD *)(v26 + v24);
              if ( !v29 )
                break;
              if ( v27 )
              {
                v30 = 0;
                while ( (v27 & 1) == 0 || !(unsigned int)nla_put(a1, v30, 0, 0) )
                {
                  v31 = v27 > 1;
                  ++v30;
                  v27 >>= 1;
                  if ( !v31 )
                    goto LABEL_7;
                }
                goto LABEL_24;
              }
LABEL_7:
              v18 = v19;
              *v29 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v29;
              *v23 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v23;
              if ( v19 >= *(unsigned __int8 *)(a4 + 14) )
                goto LABEL_20;
            }
          }
          else
          {
LABEL_20:
            *v17 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v17;
            if ( *(_BYTE *)(a4 + 15) == 1 && (unsigned int)nla_put(a1, 3, 0, 0)
              || (v32 = *(_DWORD *)(a4 + 8), (unsigned int)nla_put(a1, 4, 4, &v32))
              || (v32 = *(unsigned __int16 *)(a4 + 12), (unsigned int)nla_put(a1, 2, 4, &v32))
              || (a2 & 1) != 0
              && ((v32 = *(unsigned __int8 *)(a4 + 16), (unsigned int)nla_put(a1, 5, 4, &v32))
               || (v32 = *(unsigned __int8 *)(a4 + 17), (unsigned int)nla_put(a1, 6, 4, &v32)))
              || *(_DWORD *)(a4 + 20) && (v32 = *(_DWORD *)(a4 + 20), (unsigned int)nla_put(a1, 7, 4, &v32)) )
            {
LABEL_24:
              result = 4294967191LL;
            }
            else
            {
              result = 0;
              *v13 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v13;
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
