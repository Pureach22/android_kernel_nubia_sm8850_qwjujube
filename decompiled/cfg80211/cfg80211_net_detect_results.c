__int64 __fastcall cfg80211_net_detect_results(__int64 a1, __int64 a2)
{
  int *v3; // x25
  __int64 v4; // x20
  __int64 v5; // x21
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x23
  __int64 v9; // x20
  __int64 v10; // x21
  __int64 v11; // x22
  __int64 v12; // x24
  _WORD *v13; // x24
  __int64 v14; // x22
  __int64 v15; // x27
  _WORD *v16; // x27
  __int64 v17; // x22
  unsigned __int64 v18; // x8
  unsigned __int64 *v19; // x20
  unsigned __int64 v20; // x8
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(int **)(a2 + 32);
  v4 = *(_QWORD *)(a1 + 216);
  v5 = *(unsigned int *)(a1 + 208);
  v6 = nla_put(a1, 19, 0, 0);
  result = 4294967206LL;
  if ( (v6 & 0x80000000) == 0 )
  {
    v8 = (_WORD *)(v4 + v5);
    if ( v4 + v5 )
    {
      if ( *v3 >= 1 )
      {
        v9 = 0;
        while ( 1 )
        {
          v10 = *(_QWORD *)&v3[2 * v9 + 2];
          v11 = *(_QWORD *)(a1 + 216);
          v12 = *(unsigned int *)(a1 + 208);
          if ( (nla_put(a1, (unsigned int)v9, 0, 0) & 0x80000000) != 0 )
            goto LABEL_22;
          v13 = (_WORD *)(v11 + v12);
          if ( !v13 )
            goto LABEL_22;
          if ( (unsigned int)nla_put(a1, 52, *(unsigned __int8 *)(v10 + 32), v10) )
            break;
          if ( *(_DWORD *)(v10 + 36) )
          {
            v14 = *(_QWORD *)(a1 + 216);
            v15 = *(unsigned int *)(a1 + 208);
            if ( (nla_put(a1, 44, 0, 0) & 0x80000000) != 0 || (v16 = (_WORD *)(v14 + v15)) == nullptr )
            {
              v19 = (unsigned __int64 *)(a1 + 224);
              v20 = *(_QWORD *)(a1 + 224);
              if ( v20 > (unsigned __int64)v13 )
                goto LABEL_27;
LABEL_21:
              skb_trim(a1, (unsigned int)((_DWORD)v13 - v20));
              goto LABEL_22;
            }
            if ( *(int *)(v10 + 36) >= 1 )
            {
              v17 = 0;
              while ( 1 )
              {
                v21 = *(_DWORD *)(v10 + 40 + 4 * v17);
                if ( (unsigned int)nla_put(a1, (unsigned int)v17, 4, &v21) )
                  break;
                if ( ++v17 >= *(int *)(v10 + 36) )
                  goto LABEL_5;
              }
              v19 = (unsigned __int64 *)(a1 + 224);
              v18 = *(_QWORD *)(a1 + 224);
              if ( v18 > (unsigned __int64)v16 )
              {
                __break(0x800u);
                v18 = *v19;
              }
              skb_trim(a1, (unsigned int)((_DWORD)v16 - v18));
              v20 = *(_QWORD *)(a1 + 224);
              if ( v20 <= (unsigned __int64)v13 )
                goto LABEL_21;
              goto LABEL_27;
            }
LABEL_5:
            *v16 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v16;
          }
          ++v9;
          *v13 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v13;
          if ( v9 >= *v3 )
            goto LABEL_22;
        }
        v19 = (unsigned __int64 *)(a1 + 224);
        v20 = *(_QWORD *)(a1 + 224);
        if ( v20 <= (unsigned __int64)v13 )
          goto LABEL_21;
LABEL_27:
        __break(0x800u);
        v20 = *v19;
        goto LABEL_21;
      }
LABEL_22:
      result = 0;
      *v8 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v8;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
