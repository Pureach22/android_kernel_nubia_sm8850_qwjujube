__int64 __fastcall nl80211_put_radios(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x10
  __int64 v9; // x22
  __int64 v10; // x24
  __int64 v11; // x23
  __int64 v12; // x25
  _WORD *v13; // x23
  int *v14; // x24
  __int64 v15; // x25
  __int64 v16; // x26
  __int64 v17; // x28
  __int64 v18; // x27
  __int64 v19; // x21
  _WORD *v20; // x27
  __int64 v21; // x25
  __int64 v22; // x26
  __int64 v23; // x21
  __int64 v24; // x22
  int v25; // w8
  _WORD *v26; // x22
  int v27; // w8
  __int64 v28; // x20
  __int64 v29; // x21
  __int64 v30; // x23
  int v31; // w8
  unsigned __int64 v32; // x8
  _WORD *v33; // [xsp+8h] [xbp-18h]
  int v34; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 1496) )
  {
    v4 = *(_QWORD *)(a2 + 216);
    v5 = *(unsigned int *)(a2 + 208);
    v6 = nla_put(a2, 33099, 0, 0);
    result = 4294967191LL;
    if ( (v6 & 0x80000000) == 0 )
    {
      v8 = (_WORD *)(v4 + v5);
      if ( v4 + v5 )
      {
        if ( *(int *)(a1 + 1496) < 1 )
        {
LABEL_21:
          *v8 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v8;
          v23 = *(_QWORD *)(a2 + 216);
          v24 = *(unsigned int *)(a2 + 208);
          v25 = nla_put(a2, 33100, 0, 0);
          result = 4294967191LL;
          if ( (v25 & 0x80000000) == 0 )
          {
            v26 = (_WORD *)(v23 + v24);
            if ( v26 )
            {
              v27 = *(_DWORD *)(a1 + 88);
              v28 = *(_QWORD *)(a1 + 80);
              v29 = 0;
              v30 = v27 & (unsigned int)~(v27 >> 31);
              while ( v30 != v29 )
              {
                v31 = nl80211_put_ifcomb_data(a2, 1, (unsigned int)++v29, v28, 0x8000);
                v28 += 24;
                result = 4294967191LL;
                if ( v31 )
                  goto LABEL_31;
              }
              result = 0;
              *v26 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v26;
            }
          }
        }
        else
        {
          v9 = 0;
          v33 = v8;
          while ( 1 )
          {
            v10 = *(_QWORD *)(a1 + 1504);
            v11 = *(_QWORD *)(a2 + 216);
            v12 = *(unsigned int *)(a2 + 208);
            if ( (nla_put(a2, (unsigned int)v9 | 0x8000, 0, 0) & 0x80000000) != 0 )
              break;
            v13 = (_WORD *)(v11 + v12);
            if ( !v13 )
              break;
            v34 = v9;
            if ( (unsigned int)nla_put(a2, 1, 4, &v34) )
              break;
            v14 = (int *)(v10 + 32 * v9);
            if ( v14[2] >= 1 )
            {
              v15 = 0;
              v16 = 0;
              do
              {
                v17 = *(_QWORD *)v14;
                v18 = *(_QWORD *)(a2 + 216);
                v19 = *(unsigned int *)(a2 + 208);
                if ( (nla_put(a2, 32770, 0, 0) & 0x80000000) != 0 )
                  goto LABEL_28;
                v20 = (_WORD *)(v18 + v19);
                if ( !v20 )
                  goto LABEL_28;
                v34 = *(_DWORD *)(v17 + v15);
                if ( (unsigned int)nla_put(a2, 1, 4, &v34) )
                  goto LABEL_28;
                v34 = *(_DWORD *)(v17 + v15 + 4);
                if ( (unsigned int)nla_put(a2, 2, 4, &v34) )
                  goto LABEL_28;
                ++v16;
                v15 += 8;
                *v20 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v20;
              }
              while ( v16 < v14[2] );
            }
            if ( v14[6] >= 1 )
            {
              v21 = 0;
              v22 = 0;
              while ( !(unsigned int)nl80211_put_ifcomb_data(a2, 1, 3, *((_QWORD *)v14 + 2) + v21, 0x8000) )
              {
                ++v22;
                v21 += 24;
                if ( v22 >= v14[6] )
                  goto LABEL_20;
              }
              break;
            }
LABEL_20:
            ++v9;
            v8 = v33;
            *v13 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v13;
            if ( v9 >= *(int *)(a1 + 1496) )
              goto LABEL_21;
          }
LABEL_28:
          v32 = *(_QWORD *)(a2 + 224);
          if ( v32 > (unsigned __int64)v33 )
          {
            __break(0x800u);
            v32 = *(_QWORD *)(a2 + 224);
          }
          skb_trim(a2, (unsigned int)((_DWORD)v33 - v32));
          result = 4294967191LL;
        }
      }
    }
  }
  else
  {
    result = 0;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
