__int64 __fastcall rmnet_wlan_genl_add_ll_tuple(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x20
  char v5; // w8
  const char *v6; // x19
  const char **v7; // x20
  __int64 result; // x0
  __int64 v9; // x9
  __int64 v10; // x20
  __int64 v11; // x8
  _QWORD v12[2]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a2 + 32);
  v13[1] = 0;
  v14 = 0;
  v12[1] = 0;
  v13[0] = 0;
  v12[0] = 0;
  v3 = v2[7];
  if ( v3 && v2[8] && v2[9] && v2[10] )
  {
    if ( strchr((const char *)(v3 + 4), 58) )
    {
      if ( (unsigned int)in6_pton(v3 + 4, (unsigned __int16)(*(_WORD *)v3 - 4), v12, 0xFFFFFFFFLL, 0) != 1 )
      {
        v7 = *(const char ***)(a2 + 64);
        v6 = "SRC address is invalid in IPv6";
        goto LABEL_9;
      }
      v5 = 6;
    }
    else
    {
      if ( (unsigned int)in4_pton(v3 + 4, (unsigned __int16)(*(_WORD *)v3 - 4), v12, 0xFFFFFFFFLL, 0) != 1 )
      {
        v7 = *(const char ***)(a2 + 64);
        v6 = "SRC address is invalid in IPv4";
        goto LABEL_9;
      }
      v5 = 4;
    }
    v9 = *(_QWORD *)(a2 + 32);
    BYTE4(v14) = v5;
    v10 = *(_QWORD *)(v9 + 64);
    if ( strchr((const char *)(v10 + 4), 58) )
    {
      if ( (unsigned int)in6_pton(v10 + 4, (unsigned __int16)(*(_WORD *)v10 - 4), v13, 0xFFFFFFFFLL, 0) != 1 )
      {
        v7 = *(const char ***)(a2 + 64);
        v6 = "DST address is invalid in IPv6";
        goto LABEL_9;
      }
    }
    else if ( (unsigned int)in4_pton(v10 + 4, (unsigned __int16)(*(_WORD *)v10 - 4), v13, 0xFFFFFFFFLL, 0) != 1 )
    {
      v7 = *(const char ***)(a2 + 64);
      v6 = "DST address is invalid in IPv4";
      goto LABEL_9;
    }
    v11 = *(_QWORD *)(a2 + 32);
    LOWORD(v14) = *(_WORD *)(*(_QWORD *)(v11 + 72) + 4LL);
    WORD1(v14) = *(_WORD *)(*(_QWORD *)(v11 + 80) + 4LL);
    rmnet_wlan_add_ll_tuple(v12);
    result = 0;
    goto LABEL_12;
  }
  v6 = "Must specify FWD device and address";
  v7 = *(const char ***)(a2 + 64);
LABEL_9:
  do_trace_netlink_extack(v6);
  if ( v7 )
    *v7 = v6;
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
