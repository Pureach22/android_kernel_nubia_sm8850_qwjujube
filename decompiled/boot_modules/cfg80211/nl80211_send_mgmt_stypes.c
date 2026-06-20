__int64 __fastcall nl80211_send_mgmt_stypes(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x22
  __int64 v9; // x21
  __int64 v10; // x23
  __int64 v11; // x24
  int v12; // w8
  _WORD *v13; // x23
  unsigned int v14; // w24
  __int16 v15; // w25
  bool v16; // cc
  __int64 v17; // x21
  __int64 v18; // x22
  int v19; // w8
  _WORD *v20; // x22
  __int64 v21; // x21
  __int64 v22; // x23
  __int64 v23; // x24
  int v24; // w8
  _WORD *v25; // x23
  __int64 v26; // x8
  unsigned int v27; // w24
  __int16 v28; // w25
  _WORD v29[2]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v3 = *(_QWORD *)(a1 + 216);
    v4 = *(unsigned int *)(a1 + 208);
    v6 = nla_put(a1, 99, 0, 0);
    result = 4294967191LL;
    if ( (v6 & 0x80000000) == 0 )
    {
      v8 = (_WORD *)(v3 + v4);
      if ( v8 )
      {
        v9 = 0;
        while ( 1 )
        {
          v10 = *(_QWORD *)(a1 + 216);
          v11 = *(unsigned int *)(a1 + 208);
          v12 = nla_put(a1, (unsigned int)v9, 0, 0);
          result = 4294967191LL;
          if ( v12 < 0 )
            break;
          v13 = (_WORD *)(v10 + v11);
          if ( !v13 )
            break;
          v14 = *(unsigned __int16 *)(a2 + 4 * v9);
          if ( *(_WORD *)(a2 + 4 * v9) )
          {
            v15 = 0;
            while ( 1 )
            {
              if ( (v14 & 1) != 0 )
              {
                v29[0] = 16 * v15;
                if ( (unsigned int)nla_put(a1, 101, 2, v29) )
                  break;
              }
              v16 = v14 > 1;
              ++v15;
              v14 >>= 1;
              if ( !v16 )
                goto LABEL_5;
            }
LABEL_14:
            result = 4294967191LL;
            break;
          }
LABEL_5:
          ++v9;
          *v13 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v13;
          if ( v9 == 13 )
          {
            *v8 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v8;
            v17 = *(_QWORD *)(a1 + 216);
            v18 = *(unsigned int *)(a1 + 208);
            v19 = nla_put(a1, 100, 0, 0);
            result = 4294967191LL;
            if ( (v19 & 0x80000000) == 0 )
            {
              v20 = (_WORD *)(v17 + v18);
              if ( v20 )
              {
                v21 = 0;
                while ( 1 )
                {
                  v22 = *(_QWORD *)(a1 + 216);
                  v23 = *(unsigned int *)(a1 + 208);
                  v24 = nla_put(a1, (unsigned int)v21, 0, 0);
                  result = 4294967191LL;
                  if ( v24 < 0 )
                    break;
                  v25 = (_WORD *)(v22 + v23);
                  if ( !v25 )
                    break;
                  v26 = a2 + 4 * v21;
                  v27 = *(unsigned __int16 *)(v26 + 2);
                  if ( *(_WORD *)(v26 + 2) )
                  {
                    v28 = 0;
                    do
                    {
                      if ( (v27 & 1) != 0 )
                      {
                        v30 = 16 * v28;
                        if ( (unsigned int)nla_put(a1, 101, 2, &v30) )
                          goto LABEL_14;
                      }
                      v16 = v27 > 1;
                      ++v28;
                      v27 >>= 1;
                    }
                    while ( v16 );
                  }
                  ++v21;
                  *v25 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v25;
                  if ( v21 == 13 )
                  {
                    result = 0;
                    *v20 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v20;
                    goto LABEL_16;
                  }
                }
              }
            }
            break;
          }
        }
      }
    }
  }
  else
  {
    result = 0;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
