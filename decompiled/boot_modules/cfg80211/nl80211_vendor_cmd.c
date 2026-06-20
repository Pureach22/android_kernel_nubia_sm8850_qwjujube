__int64 __fastcall nl80211_vendor_cmd(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x10
  __int64 v6; // x22
  bool v7; // cf
  __int64 v8; // x0
  unsigned int v9; // w8
  _QWORD *v10; // x9
  __int64 v11; // x12
  __int64 v12; // x13
  __int64 v13; // x11
  int v14; // w12
  int v15; // w13
  __int64 i; // x23
  int v17; // w10
  __int64 v18; // x10
  _WORD *v19; // x24
  _WORD *v20; // x2
  const char **v21; // x21
  int v22; // w10
  __int64 v23; // x3
  const char *v24; // x19
  _QWORD *v25; // x19
  unsigned int v27; // w26
  unsigned int v28; // w0
  _DWORD *v29; // x8

  v3 = *(_QWORD *)(a2 + 48);
  v4 = _cfg80211_wdev_from_attrs(v3, *(void **)(a2 + 40), *(_QWORD *)(a2 + 32));
  v5 = *(_QWORD *)(v3 + 2360);
  if ( !v5 )
    return (unsigned int)-95;
  v6 = v4;
  v7 = __CFADD__(v4, 4095);
  v8 = v3 + 992;
  if ( !v7 )
  {
    if ( *(_QWORD *)v6 != v8 )
      return (unsigned int)-22;
LABEL_7:
    v10 = *(_QWORD **)(a2 + 32);
    v11 = v10[195];
    if ( !v11 )
      return (unsigned int)-22;
    v12 = v10[196];
    if ( !v12 )
      return (unsigned int)-22;
    v13 = *(unsigned int *)(v3 + 2376);
    if ( (int)v13 >= 1 )
    {
      v14 = *(_DWORD *)(v11 + 4);
      v15 = *(_DWORD *)(v12 + 4);
      for ( i = v5 + 32; *(_DWORD *)(i - 32) != v14 || *(_DWORD *)(i - 28) != v15; i += 56 )
      {
        if ( !--v13 )
          return (unsigned int)-95;
      }
      v17 = *(_DWORD *)(i - 24);
      if ( (v17 & 3) == 0 )
      {
        v6 = 0;
        goto LABEL_23;
      }
      if ( v6 && ((v17 & 2) == 0 || *(_QWORD *)(v6 + 32)) )
      {
        if ( (v17 & 4) != 0 )
        {
          v18 = *(_QWORD *)(v6 + 32);
          if ( v18 )
          {
            if ( (*(_QWORD *)(v18 + 168) & 1) == 0 )
              return (unsigned int)-100;
          }
          else if ( *(_BYTE *)(v6 + 66) != 1 )
          {
            return (unsigned int)-100;
          }
        }
LABEL_23:
        if ( *(_QWORD *)(i - 16) )
        {
          v19 = (_WORD *)v10[197];
          if ( v19 )
          {
            v20 = v19 + 2;
            v21 = *(const char ***)(a2 + 64);
            v22 = (__int16)v19[1];
            v23 = (unsigned __int16)(*v19 - 4);
            if ( *(_QWORD *)i == -61 )
            {
              if ( v22 < 0 )
              {
                v24 = "unexpected nested data";
LABEL_32:
                do_trace_netlink_extack(v24);
                if ( v21 )
                {
                  *v21 = v24;
                  v21[1] = (const char *)v19;
                  v25 = v21 + 2;
                  v9 = -22;
LABEL_42:
                  *v25 = 0;
                  return v9;
                }
                return (unsigned int)-22;
              }
            }
            else
            {
              if ( (v22 & 0x80000000) == 0 )
              {
                v24 = "expected nested data";
                goto LABEL_32;
              }
              v27 = (unsigned __int16)(*v19 - 4);
              v28 = _nla_validate(
                      v19 + 2,
                      (unsigned __int16)(*v19 - 4),
                      *(unsigned int *)(i + 8),
                      *(_QWORD *)i,
                      31,
                      *(_QWORD *)(a2 + 64));
              v23 = v27;
              v20 = v19 + 2;
              v9 = v28;
              v8 = v3 + 992;
              if ( v9 )
                return v9;
            }
          }
          else
          {
            v20 = nullptr;
            v23 = 0;
          }
          *(_QWORD *)(v3 + 296) = a2;
          v25 = (_QWORD *)(v3 + 296);
          v29 = *(_DWORD **)(i - 16);
          if ( *(v29 - 1) != 1990973027 )
            __break(0x8228u);
          v9 = ((__int64 (__fastcall *)(__int64, __int64, _WORD *, __int64))v29)(v8, v6, v20, v23);
          goto LABEL_42;
        }
        return (unsigned int)-95;
      }
      return (unsigned int)-22;
    }
    return (unsigned int)-95;
  }
  v9 = v6;
  if ( (_DWORD)v6 == -22 )
  {
    v6 = 0;
    goto LABEL_7;
  }
  return v9;
}
