__int64 __fastcall rmnet_wlan_genl_add_fwd_info(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x20
  __int64 v4; // x8
  char v6; // w8
  const char *v7; // x19
  const char **v8; // x20
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x10
  __int64 v12; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x9
  unsigned int *v15; // x9
  unsigned int v16; // w12
  __int64 v17; // x9
  unsigned int v18; // w19
  __int64 v19; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v21; // [xsp+20h] [xbp-10h]
  __int64 v22; // [xsp+28h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_QWORD *)a2[4];
  v20[1] = 0;
  v21 = 0;
  v19 = 0;
  v20[0] = 0;
  v3 = v2[3];
  if ( v3 && v2[4] && (v4 = v2[6]) != 0 )
  {
    BYTE1(v21) = *(_BYTE *)(v4 + 4);
    if ( strchr((const char *)(v3 + 4), 58) )
    {
      if ( (unsigned int)in6_pton(v3 + 4, (unsigned __int16)(*(_WORD *)v3 - 4), v20, 0xFFFFFFFFLL, 0) != 1 )
      {
        v8 = (const char **)a2[8];
        v7 = "FWD address is invalid in IPv6";
        goto LABEL_8;
      }
      v6 = 6;
    }
    else
    {
      if ( (unsigned int)in4_pton(v3 + 4, (unsigned __int16)(*(_WORD *)v3 - 4), v20, 0xFFFFFFFFLL, 0) != 1 )
      {
        v8 = (const char **)a2[8];
        v7 = "FWD address is invalid in IPv4";
        goto LABEL_8;
      }
      v6 = 4;
    }
    v11 = a2[4];
    v10 = a2[5];
    LOBYTE(v21) = v6;
    v19 = dev_get_by_name(v10, *(_QWORD *)(v11 + 32) + 4LL);
    if ( v19 )
    {
      result = rmnet_wlan_add_fwd_info(&v19, a2);
      v12 = v19;
      if ( v19 )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(StatusReg + 16);
        v14 = *(_QWORD *)(v12 + 1320);
        v15 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v14);
        do
          v16 = __ldxr(v15);
        while ( __stxr(v16 - 1, v15) );
        v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v17;
        if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
        {
          v18 = result;
          preempt_schedule_notrace();
          result = v18;
        }
      }
      goto LABEL_11;
    }
    v8 = (const char **)a2[8];
    v7 = "Invalid FWD device name";
  }
  else
  {
    v7 = "Must specify FWD device, address, and network";
    v8 = (const char **)a2[8];
  }
LABEL_8:
  do_trace_netlink_extack(v7);
  if ( v8 )
    *v8 = v7;
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
