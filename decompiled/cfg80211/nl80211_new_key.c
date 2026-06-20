__int64 __fastcall nl80211_new_key(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x8
  unsigned int v7; // w22
  __int64 v8; // x23
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x10
  int v12; // w9
  __int64 v13; // x24
  const char **v14; // x20
  const char *v15; // x19
  __int64 v16; // x3
  __int64 v17; // x8
  unsigned int v18; // w9
  int v19; // w8
  const char **v20; // x21
  unsigned int v21; // w20
  const char *v22; // x19
  _QWORD v23[3]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v24; // [xsp+18h] [xbp-28h]
  __int64 v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[4];
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v4 = a2[6];
  v5 = a2[7];
  memset(v23, 0, sizeof(v23));
  v6 = *(_QWORD *)(v3 + 2504);
  if ( v6 )
    v7 = *(unsigned __int8 *)(v6 + 4);
  else
    v7 = -1;
  v8 = *(_QWORD *)(v5 + 992);
  result = nl80211_parse_key(a2, v23);
  if ( (_DWORD)result )
    goto LABEL_47;
  if ( !v23[0] )
  {
    v14 = (const char **)a2[8];
    v15 = "no key";
    goto LABEL_23;
  }
  v10 = a2[4];
  v11 = *(_QWORD *)(v10 + 48);
  if ( !v11 )
  {
    v12 = HIDWORD(v26);
    if ( HIDWORD(v26) != -1 )
    {
      v13 = 0;
      if ( HIDWORD(v26) >= 2 )
        goto LABEL_9;
      goto LABEL_13;
    }
LABEL_17:
    v13 = 0;
    HIDWORD(v26) = 0;
LABEL_18:
    v17 = *(_QWORD *)(v10 + 2256);
    v16 = 0;
    if ( v17 )
      LOWORD(v24) = *(_WORD *)(v17 + 4);
    goto LABEL_20;
  }
  v12 = HIDWORD(v26);
  v13 = v11 + 4;
  if ( HIDWORD(v26) == -1 )
  {
    if ( v11 != -4 )
    {
      v16 = 1;
      HIDWORD(v26) = 1;
      goto LABEL_20;
    }
    goto LABEL_17;
  }
  if ( HIDWORD(v26) >= 2 )
  {
LABEL_9:
    v14 = (const char **)a2[8];
    v15 = "key type not pairwise or group";
LABEL_23:
    do_trace_netlink_extack(v15);
    if ( v14 )
      *v14 = v15;
    result = 4294967274LL;
    goto LABEL_47;
  }
LABEL_13:
  if ( !v12 )
    goto LABEL_18;
  v16 = 1;
LABEL_20:
  if ( !*(_QWORD *)(*(_QWORD *)v4 + 64LL) )
  {
    result = 4294967201LL;
    goto LABEL_47;
  }
  if ( (unsigned int)cfg80211_validate_key_settings(v4, v23, (unsigned int)v26, v16, v13) )
  {
    v14 = (const char **)a2[8];
    v15 = "key setting validation failed";
    goto LABEL_23;
  }
  v18 = *(_DWORD *)(v8 + 8);
  v19 = -22;
  if ( v18 > 0xD )
    goto LABEL_36;
  if ( ((1 << v18) & 0x2C60) != 0 )
    goto LABEL_43;
  if ( ((1 << v18) & 0x104) != 0 )
  {
    if ( (*(_BYTE *)(v8 + 164) & 1) == 0 )
    {
LABEL_42:
      v19 = -67;
      goto LABEL_43;
    }
LABEL_39:
    result = nl80211_validate_key_link_id(a2, v8, v7, HIDWORD(v26) == 1);
    if ( (_DWORD)result )
      goto LABEL_47;
    result = rdev_add_key(v4, v5, v7);
    if ( !(_DWORD)result )
      goto LABEL_47;
    v20 = (const char **)a2[8];
    v21 = result;
    v22 = "key addition failed";
    goto LABEL_44;
  }
  if ( v18 == 12 )
  {
    if ( *(char *)(*(_QWORD *)v8 + 119LL) < 0 )
      goto LABEL_39;
    v19 = -22;
  }
  else
  {
LABEL_36:
    if ( v18 )
    {
      if ( v18 == 1 && !*(_QWORD *)(v8 + 280) )
        goto LABEL_42;
      goto LABEL_39;
    }
  }
LABEL_43:
  v20 = (const char **)a2[8];
  v21 = v19;
  v22 = "key not allowed";
LABEL_44:
  do_trace_netlink_extack(v22);
  if ( v20 )
    *v20 = v22;
  result = v21;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
