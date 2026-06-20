__int64 __fastcall nl80211_set_key(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x8
  __int64 v4; // x19
  _BYTE *v5; // x20
  __int64 v6; // x8
  unsigned int v7; // w21
  __int64 v8; // x23
  __int64 result; // x0
  unsigned int v10; // w8
  __int64 v11; // x8
  const char *v12; // x19
  const char **v13; // x20
  _QWORD v14[4]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v15; // [xsp+20h] [xbp-20h]
  __int64 v16; // [xsp+28h] [xbp-18h]
  __int64 v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[4];
  v16 = 0;
  v17 = 0;
  v15 = 0;
  v5 = (_BYTE *)a2[6];
  v4 = a2[7];
  memset(v14, 0, sizeof(v14));
  v6 = *(_QWORD *)(v3 + 2504);
  if ( v6 )
    v7 = *(unsigned __int8 *)(v6 + 4);
  else
    v7 = -1;
  v8 = *(_QWORD *)(v4 + 992);
  result = nl80211_parse_key(a2, v14);
  if ( (_DWORD)result )
    goto LABEL_23;
  if ( (v16 & 0x80000000) != 0 )
    goto LABEL_22;
  if ( (v17 & 1) == 0 )
  {
    if ( (v17 & 0x100) != 0 )
    {
      if ( (v17 & 0x1000000) == 0 && BYTE4(v17) == 1 )
      {
        if ( *(_QWORD *)(*(_QWORD *)v5 + 96LL) )
        {
          result = nl80211_key_allowed(v8);
          if ( !(_DWORD)result )
          {
            result = nl80211_validate_key_link_id(a2, v8, v7, 0);
            if ( !(_DWORD)result )
              result = rdev_set_default_mgmt_key(v5, v4, v7, (unsigned int)v16);
          }
          goto LABEL_23;
        }
        goto LABEL_31;
      }
    }
    else if ( (v17 & 0x10000) != 0 || (_DWORD)v15 == 2 )
    {
      if ( BYTE2(v17) == 1 )
      {
        if ( (v17 & 0x1000000) == 0 && BYTE4(v17) == 1 )
        {
          if ( *(_QWORD *)(*(_QWORD *)v5 + 104LL) )
          {
            result = nl80211_key_allowed(v8);
            if ( !(_DWORD)result )
            {
              result = nl80211_validate_key_link_id(a2, v8, v7, 0);
              if ( !(_DWORD)result )
                result = rdev_set_default_beacon_key(v5, v4, v7, (unsigned int)v16);
            }
            goto LABEL_23;
          }
LABEL_31:
          result = 4294967201LL;
          goto LABEL_23;
        }
      }
      else if ( (_DWORD)v15 == 2 && (v5[1108] & 0x10) != 0 )
      {
        v11 = *(_QWORD *)(a2[4] + 48LL);
        if ( v11 )
        {
          result = 4294967274LL;
          if ( (unsigned int)v16 <= 1 && v11 != -4 )
          {
            if ( v7 == -1 )
            {
              result = rdev_add_key(v5, v4, 0xFFFFFFFFLL);
              goto LABEL_23;
            }
            v12 = "link ID not allowed for pairwise key";
            goto LABEL_54;
          }
          goto LABEL_23;
        }
      }
    }
LABEL_22:
    result = 4294967274LL;
    goto LABEL_23;
  }
  if ( !*(_QWORD *)(*(_QWORD *)v5 + 88LL) )
    goto LABEL_31;
  v10 = *(_DWORD *)(v8 + 8);
  result = 4294967274LL;
  if ( v10 > 0xD )
    goto LABEL_42;
  if ( ((1 << v10) & 0x2C60) == 0 )
  {
    if ( ((1 << v10) & 0x104) != 0 )
    {
      if ( (*(_BYTE *)(v8 + 164) & 1) == 0 )
      {
LABEL_49:
        result = 4294967229LL;
        goto LABEL_23;
      }
      goto LABEL_45;
    }
    if ( v10 == 12 )
    {
      if ( (*(char *)(*(_QWORD *)v8 + 119LL) & 0x80000000) == 0 )
        goto LABEL_23;
LABEL_45:
      if ( *(_WORD *)(v8 + 1472) )
      {
        if ( v7 != -1 )
        {
          if ( (((unsigned __int64)*(unsigned __int16 *)(v8 + 1472) >> v7) & 1) == 0 )
          {
            v12 = "invalid link ID for MLO group key";
            goto LABEL_54;
          }
LABEL_52:
          result = rdev_set_default_key(v5, v4, v7, (unsigned int)v16, BYTE3(v17), BYTE4(v17));
          goto LABEL_23;
        }
        v12 = "link ID must for MLO group key";
      }
      else
      {
        if ( v7 == -1 )
          goto LABEL_52;
        v12 = "link ID not allowed for non-MLO group key";
      }
LABEL_54:
      v13 = (const char **)a2[8];
      do_trace_netlink_extack(v12);
      if ( v13 )
      {
        *v13 = v12;
        result = 4294967274LL;
        goto LABEL_23;
      }
      goto LABEL_22;
    }
LABEL_42:
    if ( !v10 )
      goto LABEL_23;
    if ( v10 == 1 && !*(_QWORD *)(v8 + 280) )
      goto LABEL_49;
    goto LABEL_45;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
