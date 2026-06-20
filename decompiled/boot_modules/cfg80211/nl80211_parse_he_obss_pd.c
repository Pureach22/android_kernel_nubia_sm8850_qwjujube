__int64 __fastcall nl80211_parse_he_obss_pd(_WORD *a1, __int64 a2)
{
  int v2; // w8
  __int64 result; // x0
  __int64 v5; // x9
  __int64 v6; // [xsp+0h] [xbp-40h] BYREF
  __int64 v7; // [xsp+8h] [xbp-38h]
  __int64 v8; // [xsp+10h] [xbp-30h]
  __int64 v9; // [xsp+18h] [xbp-28h]
  __int64 v10; // [xsp+20h] [xbp-20h]
  __int64 v11; // [xsp+28h] [xbp-18h]
  __int64 v12; // [xsp+30h] [xbp-10h]
  __int64 v13; // [xsp+38h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (__int16)a1[1];
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v7 = 0;
  v8 = 0;
  v6 = 0;
  if ( v2 < 0 )
  {
    result = _nla_parse(&v6, 6, a1 + 2, (unsigned __int16)(*a1 - 4), &he_obss_pd_policy, 31, 0);
    if ( !(_DWORD)result )
    {
      if ( !v12 )
        goto LABEL_12;
      v5 = v7;
      *(_BYTE *)(a2 + 1) = *(_BYTE *)(v12 + 4);
      if ( v5 )
        *(_BYTE *)(a2 + 3) = *(_BYTE *)(v5 + 4);
      if ( v8 )
        *(_BYTE *)(a2 + 4) = *(_BYTE *)(v8 + 4);
      if ( v9 )
        *(_BYTE *)(a2 + 2) = *(_BYTE *)(v9 + 4);
      if ( *(unsigned __int8 *)(a2 + 3) <= (unsigned int)*(unsigned __int8 *)(a2 + 4) )
      {
        if ( v10 )
          *(_QWORD *)(a2 + 5) = *(_QWORD *)(v10 + 4);
        if ( v11 )
          *(_QWORD *)(a2 + 13) = *(_QWORD *)(v11 + 4);
        result = 0;
        *(_BYTE *)a2 = 1;
      }
      else
      {
LABEL_12:
        result = 4294967274LL;
      }
    }
  }
  else
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
