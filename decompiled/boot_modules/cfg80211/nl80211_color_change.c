__int64 __fastcall nl80211_color_change(__int64 a1, _QWORD *a2)
{
  _BYTE *v3; // x19
  __int64 v4; // x21
  _QWORD *v5; // x1
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x3
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x22
  int v12; // w0
  _WORD *v13; // x8
  unsigned __int64 v14; // x9
  int v15; // w8
  _WORD *v16; // x10
  unsigned __int64 v17; // x9
  __int64 v18; // x8
  unsigned int v19; // w19
  _QWORD s[47]; // [xsp+8h] [xbp-178h] BYREF

  s[46] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (_BYTE *)a2[6];
  memset(s, 0, 0x170u);
  if ( *(_QWORD *)(*(_QWORD *)v3 + 936LL)
    && (v3[1111] & 4) != 0
    && (v4 = a2[7], *(_DWORD *)(*(_QWORD *)(v4 + 992) + 8LL) == 3) )
  {
    v5 = (_QWORD *)a2[4];
    v6 = v5[303];
    if ( v6 && (v7 = v5[304]) != 0 && v5[305] )
    {
      v8 = a2[8];
      LOBYTE(s[45]) = *(_BYTE *)(v6 + 4);
      BYTE1(s[45]) = *(_BYTE *)(v7 + 4);
      result = nl80211_parse_beacon(v3, v5, &s[23], v8);
      if ( !(_DWORD)result )
      {
        v10 = _kmalloc_cache_noprof(alloc_workqueue, 3520, 2688);
        v11 = v10;
        if ( !v10 )
        {
          result = 4294967284LL;
          goto LABEL_24;
        }
        v12 = nla_parse_nested(v10, 335, *(_QWORD *)(a2[4] + 2440LL), &nl80211_policy, a2[8]);
        if ( v12 )
          goto LABEL_27;
        v12 = nl80211_parse_beacon(v3, v11, s, a2[8]);
        if ( v12 )
          goto LABEL_27;
        v13 = *(_WORD **)(v11 + 1488);
        if ( v13 )
        {
          if ( *v13 == 6 )
          {
            v14 = (unsigned __int16)v13[2];
            if ( s[13] > v14 )
            {
              v15 = *(unsigned __int8 *)(s[2] + v14);
              if ( v15 == LOBYTE(s[45]) )
              {
                v16 = *(_WORD **)(v11 + 1496);
                LOWORD(s[22]) = v14;
                if ( !v16 )
                {
LABEL_20:
                  v18 = *(_QWORD *)(a2[4] + 2504LL);
                  if ( v18 )
                    LOBYTE(v18) = *(_BYTE *)(v18 + 4);
                  BYTE2(s[45]) = v18;
                  v12 = rdev_color_change(v3, v4, s);
                  goto LABEL_27;
                }
                if ( *v16 == 6 )
                {
                  v17 = (unsigned __int16)v16[2];
                  if ( s[17] > v17 && *(unsigned __int8 *)(s[6] + v17) == v15 )
                  {
                    WORD1(s[22]) = v16[2];
                    goto LABEL_20;
                  }
                }
              }
            }
          }
        }
        v12 = -22;
LABEL_27:
        v19 = v12;
        kfree(s[32]);
        kfree(s[9]);
        kfree(s[33]);
        kfree(s[10]);
        kfree(v11);
        result = v19;
      }
    }
    else
    {
      result = 4294967274LL;
    }
  }
  else
  {
    result = 4294967201LL;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
