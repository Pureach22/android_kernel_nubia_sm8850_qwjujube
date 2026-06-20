__int64 __fastcall nl80211_external_auth(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x20
  _QWORD *v3; // x21
  __int64 v4; // x19
  _WORD *v5; // x10
  __int64 v6; // x8
  __int64 v7; // x9
  bool v8; // zf
  size_t v9; // x2
  __int16 v10; // w10
  int v11; // w8
  __int64 v12; // x8
  _DWORD *v13; // x8
  __int64 result; // x0
  int v15; // w8
  size_t v16; // x21
  unsigned __int64 StatusReg; // x21
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x8
  _QWORD *v22; // [xsp+8h] [xbp-58h]
  _QWORD v23[5]; // [xsp+10h] [xbp-50h] BYREF
  __int64 v24; // [xsp+38h] [xbp-28h]
  __int64 v25; // [xsp+40h] [xbp-20h]
  __int64 v26; // [xsp+48h] [xbp-18h]
  __int64 v27; // [xsp+50h] [xbp-10h]
  __int64 v28; // [xsp+58h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[6];
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 856LL) )
  {
    result = 4294967201LL;
    goto LABEL_23;
  }
  v3 = (_QWORD *)a2[4];
  v4 = a2[7];
  v5 = (_WORD *)v3[52];
  if ( !v5 )
  {
    v15 = *(_DWORD *)(*(_QWORD *)(v4 + 992) + 8LL);
    if ( v15 != 9 && v15 != 3 )
      goto LABEL_21;
  }
  v6 = v3[245];
  if ( !v6 )
    goto LABEL_21;
  v7 = v3[72];
  if ( !v7 )
    goto LABEL_21;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  memset(v23, 0, sizeof(v23));
  if ( !v5 )
    goto LABEL_12;
  v9 = (unsigned __int8)(*v5 - 4);
  v8 = (unsigned __int8)(*v5 - 4) == 0;
  BYTE2(v24) = *v5 - 4;
  if ( v8 )
  {
LABEL_21:
    result = 4294967274LL;
    goto LABEL_23;
  }
  if ( (unsigned int)v9 >= 0x3F )
  {
    _fortify_panic(17, 62);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v18 = _traceiter_rdev_external_auth(0, v2 + 992, v4, v23);
      v21 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v21;
      if ( !v21 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v18, v19, v20);
    }
    goto LABEL_14;
  }
  if ( (unsigned int)v9 >= 0x21 && (nl80211_external_auth___already_done & 1) == 0 )
  {
    nl80211_external_auth___already_done = 1;
    v22 = a2;
    v16 = v9;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v9,
      "field \"params.ssid.ssid\" at ../soc-repo/net/wireless/nl80211.c:15825",
      0x20u);
    a2 = v22;
    v9 = v16;
    __break(0x800u);
  }
  v3 = (_QWORD *)a2[4];
  memcpy((char *)&v23[1] + 2, (const void *)(v3[52] + 4LL), v9);
  v6 = v3[245];
  v7 = v3[72];
LABEL_12:
  v10 = *(_WORD *)(v6 + 8);
  v11 = *(_DWORD *)(v6 + 4);
  LOWORD(v23[1]) = v10;
  HIDWORD(v23[0]) = v11;
  LOWORD(v25) = *(_WORD *)(v7 + 4);
  v12 = v3[85];
  if ( v12 )
    v26 = v12 + 4;
LABEL_14:
  v13 = *(_DWORD **)(*(_QWORD *)v2 + 856LL);
  if ( v13 )
  {
    if ( *(v13 - 1) != -763601745 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v13)(v2 + 992, v4, v23);
  }
  else
  {
    result = 4294967201LL;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
