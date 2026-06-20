__int64 __fastcall nl80211_parse_key(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x8
  __int64 v5; // x1
  __int64 result; // x0
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x9
  _WORD *v15; // x2
  __int64 v16; // x6
  __int64 v17; // x9
  int v18; // w10
  const char **v19; // x20
  const char *v20; // x19
  unsigned int v21; // w11
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  __int64 v23; // [xsp+8h] [xbp-18h]
  __int64 v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 40) = -1;
  *(_QWORD *)(a2 + 48) = 0;
  v4 = *(_QWORD **)(a1 + 32);
  v5 = v4[80];
  if ( v5 )
  {
    result = nl80211_parse_key_new(a1, v5, a2);
    if ( (_DWORD)result )
      goto LABEL_44;
  }
  else
  {
    v7 = v4[7];
    if ( v7 )
    {
      *(_QWORD *)a2 = v7 + 4;
      *(_DWORD *)(a2 + 16) = (unsigned __int16)(**(_WORD **)(*(_QWORD *)(a1 + 32) + 56LL) - 4);
      v4 = *(_QWORD **)(a1 + 32);
    }
    v8 = v4[10];
    if ( v8 )
    {
      *(_QWORD *)(a2 + 8) = v8 + 4;
      *(_DWORD *)(a2 + 20) = (unsigned __int16)(**(_WORD **)(*(_QWORD *)(a1 + 32) + 80LL) - 4);
      v4 = *(_QWORD **)(a1 + 32);
    }
    v9 = v4[8];
    if ( v9 )
    {
      *(_DWORD *)(a2 + 40) = *(unsigned __int8 *)(v9 + 4);
      v4 = *(_QWORD **)(a1 + 32);
    }
    v10 = v4[9];
    if ( v10 )
    {
      *(_DWORD *)(a2 + 28) = *(_DWORD *)(v10 + 4);
      v4 = *(_QWORD **)(a1 + 32);
    }
    v11 = v4[11];
    *(_BYTE *)(a2 + 48) = v11 != 0;
    v12 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 320LL);
    *(_BYTE *)(a2 + 49) = v12 != 0;
    if ( v11 )
      *(_WORD *)(a2 + 51) = 257;
    if ( v12 )
      *(_BYTE *)(a2 + 52) = 1;
    v13 = *(_QWORD *)(a1 + 32);
    v14 = *(_QWORD *)(v13 + 440);
    if ( v14 )
    {
      *(_DWORD *)(a2 + 44) = *(_DWORD *)(v14 + 4);
      v13 = *(_QWORD *)(a1 + 32);
    }
    v15 = *(_WORD **)(v13 + 880);
    if ( v15 )
    {
      v23 = 0;
      v24 = 0;
      v16 = *(_QWORD *)(a1 + 64);
      v22 = 0;
      result = _nla_parse(&v22, 2, v15 + 2, (unsigned __int16)(*v15 - 4), &nl80211_key_default_policy, 0, v16);
      if ( (_DWORD)result )
        goto LABEL_44;
      v17 = v24;
      *(_BYTE *)(a2 + 51) = v23 != 0;
      *(_BYTE *)(a2 + 52) = v17 != 0;
    }
  }
  v18 = *(unsigned __int8 *)(a2 + 49);
  if ( v18 + *(unsigned __int8 *)(a2 + 48) + (unsigned int)*(unsigned __int8 *)(a2 + 50) < 2 )
  {
    if ( ((v18 & 1) != 0 || *(_BYTE *)(a2 + 50)) && ((*(_BYTE *)(a2 + 51) & 1) != 0 || (*(_BYTE *)(a2 + 52) & 1) == 0) )
    {
      v19 = *(const char ***)(a1 + 64);
      v20 = "defmgmt/defbeacon key must be mcast";
      goto LABEL_32;
    }
    v21 = *(_DWORD *)(a2 + 40);
    if ( v21 != -1 )
    {
      if ( *(_BYTE *)(a2 + 49) )
      {
        if ( v21 - 6 <= 0xFFFFFFFD )
        {
          v19 = *(const char ***)(a1 + 64);
          v20 = "defmgmt key idx not 4 or 5";
          goto LABEL_32;
        }
      }
      else if ( *(_BYTE *)(a2 + 50) )
      {
        if ( v21 - 8 <= 0xFFFFFFFD )
        {
          v19 = *(const char ***)(a1 + 64);
          v20 = "defbeacon key idx not 6 or 7";
          goto LABEL_32;
        }
      }
      else if ( *(_BYTE *)(a2 + 48) )
      {
        if ( v21 >= 4 )
        {
          v19 = *(const char ***)(a1 + 64);
          v20 = "def key idx not 0-3";
          goto LABEL_32;
        }
      }
      else if ( v21 >= 8 )
      {
        v19 = *(const char ***)(a1 + 64);
        v20 = "key idx not 0-7";
        goto LABEL_32;
      }
    }
    result = 0;
    goto LABEL_44;
  }
  v19 = *(const char ***)(a1 + 64);
  v20 = "key with multiple default flags is invalid";
LABEL_32:
  do_trace_netlink_extack(v20);
  if ( v19 )
    *v19 = v20;
  result = 4294967274LL;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
