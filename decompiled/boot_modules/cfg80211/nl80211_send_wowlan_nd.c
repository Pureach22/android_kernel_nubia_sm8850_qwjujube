__int64 __fastcall nl80211_send_wowlan_nd(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x22
  char v9; // w9
  __int64 v10; // x21
  __int64 v11; // x23
  int v12; // w8
  _WORD *v13; // x23
  unsigned int v14; // w21
  __int64 v15; // x21
  __int64 v16; // x23
  int v17; // w8
  _WORD *v18; // x23
  __int64 v19; // x21
  __int64 v20; // x24
  __int64 v21; // x25
  __int64 v22; // x26
  int v23; // w8
  _WORD *v24; // x25
  __int64 v25; // x21
  __int64 v26; // x23
  int v27; // w8
  _WORD *v28; // x23
  __int64 v29; // x24
  __int64 v30; // x21
  __int64 v31; // x25
  __int64 v32; // x26
  int v33; // w8
  _WORD *v34; // x25
  _BYTE v35[4]; // [xsp+0h] [xbp-10h] BYREF
  int v36; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    result = 0;
    goto LABEL_9;
  }
  v3 = *(_QWORD *)(a1 + 216);
  v4 = *(unsigned int *)(a1 + 208);
  v6 = nla_put(a1, 18, 0, 0);
  result = 4294967191LL;
  if ( (v6 & 0x80000000) == 0 )
  {
    v8 = (_WORD *)(v3 + v4);
    if ( v8 )
    {
      if ( *(_DWORD *)(a2 + 80) == 1 && (v36 = 1000 * **(_DWORD **)(a2 + 72), (unsigned int)nla_put(a1, 119, 4, &v36))
        || (v36 = *(_DWORD *)(a2 + 64), (unsigned int)nla_put(a1, 220, 4, &v36))
        || *(_BYTE *)(a2 + 96) == 1
        && ((v35[0] = *(_BYTE *)(a2 + 97), (unsigned int)nla_put(a1, 246, 1, v35))
         || (v9 = *(_BYTE *)(a2 + 104),
             LOBYTE(v36) = *(_DWORD *)(a2 + 100),
             BYTE1(v36) = v9,
             (unsigned int)nla_put(a1, 247, 2, &v36))) )
      {
LABEL_7:
        result = 4294967191LL;
        goto LABEL_9;
      }
      v10 = *(_QWORD *)(a1 + 216);
      v11 = *(unsigned int *)(a1 + 208);
      v12 = nla_put(a1, 44, 0, 0);
      result = 4294967191LL;
      if ( (v12 & 0x80000000) == 0 )
      {
        v13 = (_WORD *)(v10 + v11);
        if ( v13 )
        {
          if ( *(_DWORD *)(a2 + 20) )
          {
            v14 = 0;
            do
            {
              v36 = *(_DWORD *)(*(_QWORD *)(a2 + 192 + 8LL * (int)v14) + 4LL);
              if ( (unsigned int)nla_put(a1, v14, 4, &v36) )
                goto LABEL_7;
            }
            while ( ++v14 < *(_DWORD *)(a2 + 20) );
          }
          *v13 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v13;
          if ( *(_DWORD *)(a2 + 56) )
          {
            v15 = *(_QWORD *)(a1 + 216);
            v16 = *(unsigned int *)(a1 + 208);
            v17 = nla_put(a1, 132, 0, 0);
            result = 4294967191LL;
            if ( v17 < 0 )
              goto LABEL_9;
            v18 = (_WORD *)(v15 + v16);
            if ( !v18 )
              goto LABEL_9;
            if ( *(int *)(a2 + 56) >= 1 )
            {
              v19 = 0;
              v20 = 32;
              do
              {
                v21 = *(_QWORD *)(a1 + 216);
                v22 = *(unsigned int *)(a1 + 208);
                v23 = nla_put(a1, (unsigned int)v19, 0, 0);
                result = 4294967191LL;
                if ( v23 < 0 )
                  goto LABEL_9;
                v24 = (_WORD *)(v21 + v22);
                if ( !v24 )
                  goto LABEL_9;
                if ( (unsigned int)nla_put(
                                     a1,
                                     1,
                                     *(unsigned __int8 *)(*(_QWORD *)(a2 + 48) + v20),
                                     *(_QWORD *)(a2 + 48) + v20 - 32) )
                  goto LABEL_7;
                ++v19;
                v20 += 44;
                *v24 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v24;
              }
              while ( v19 < *(int *)(a2 + 56) );
            }
            *v18 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v18;
          }
          v25 = *(_QWORD *)(a1 + 216);
          v26 = *(unsigned int *)(a1 + 208);
          v27 = nla_put(a1, 225, 0, 0);
          result = 4294967191LL;
          if ( (v27 & 0x80000000) == 0 )
          {
            v28 = (_WORD *)(v25 + v26);
            if ( v28 )
            {
              if ( *(int *)(a2 + 80) < 1 )
              {
LABEL_40:
                result = 0;
                *v28 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v28;
                *v8 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v8;
              }
              else
              {
                v29 = 0;
                v30 = 0;
                while ( 1 )
                {
                  ++v30;
                  v31 = *(_QWORD *)(a1 + 216);
                  v32 = *(unsigned int *)(a1 + 208);
                  v33 = nla_put(a1, (unsigned int)v30, 0, 0);
                  result = 4294967191LL;
                  if ( v33 < 0 )
                    break;
                  v34 = (_WORD *)(v31 + v32);
                  if ( !v34 )
                    break;
                  v36 = *(_DWORD *)(*(_QWORD *)(a2 + 72) + v29);
                  if ( (unsigned int)nla_put(a1, 1, 4, &v36) )
                    goto LABEL_7;
                  if ( *(_DWORD *)(*(_QWORD *)(a2 + 72) + v29 + 4) )
                  {
                    v36 = *(_DWORD *)(*(_QWORD *)(a2 + 72) + v29 + 4);
                    if ( (unsigned int)nla_put(a1, 2, 4, &v36) )
                      goto LABEL_7;
                  }
                  v29 += 8;
                  *v34 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v34;
                  if ( v30 >= *(int *)(a2 + 80) )
                    goto LABEL_40;
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
