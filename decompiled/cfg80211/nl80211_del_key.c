__int64 __fastcall nl80211_del_key(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x8
  _BYTE *v4; // x19
  __int64 v5; // x20
  __int64 v6; // x8
  unsigned int v7; // w21
  __int64 v8; // x24
  __int64 result; // x0
  __int64 v10; // x9
  int v11; // w8
  __int64 v12; // x22
  unsigned int v13; // w8
  bool v14; // zf
  __int64 v15; // x3
  _BOOL8 v16; // x4
  _DWORD *v17; // x8
  _QWORD v18[5]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v19; // [xsp+28h] [xbp-18h]
  __int64 v20; // [xsp+30h] [xbp-10h]
  __int64 v21; // [xsp+38h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[4];
  v19 = 0;
  v20 = 0;
  v4 = (_BYTE *)a2[6];
  v5 = a2[7];
  memset(v18, 0, sizeof(v18));
  v6 = *(_QWORD *)(v3 + 2504);
  if ( v6 )
    v7 = *(unsigned __int8 *)(v6 + 4);
  else
    v7 = -1;
  v8 = *(_QWORD *)(v5 + 992);
  result = nl80211_parse_key(a2, v18);
  if ( (_DWORD)result )
    goto LABEL_22;
  v10 = *(_QWORD *)(a2[4] + 48LL);
  if ( !v10 )
  {
    v11 = HIDWORD(v19);
    if ( HIDWORD(v19) != -1 )
    {
      v12 = 0;
      if ( HIDWORD(v19) > 1 )
        goto LABEL_21;
      goto LABEL_15;
    }
LABEL_14:
    v12 = 0;
    v11 = 0;
    HIDWORD(v19) = 0;
    goto LABEL_15;
  }
  v11 = HIDWORD(v19);
  v12 = v10 + 4;
  if ( HIDWORD(v19) == -1 )
  {
    if ( v10 != -4 )
    {
      v11 = 1;
      HIDWORD(v19) = 1;
      goto LABEL_15;
    }
    goto LABEL_14;
  }
  if ( HIDWORD(v19) > 1 )
  {
LABEL_21:
    result = 4294967274LL;
    goto LABEL_22;
  }
LABEL_15:
  if ( (cfg80211_valid_key_idx(v4, (unsigned int)v19, v11 != 0) & 1) == 0 )
    goto LABEL_21;
  if ( !*(_QWORD *)(*(_QWORD *)v4 + 80LL) )
  {
    result = 4294967201LL;
    goto LABEL_22;
  }
  v13 = *(_DWORD *)(v8 + 8);
  result = 4294967274LL;
  if ( v13 > 0xD )
  {
LABEL_26:
    if ( !v13 )
      goto LABEL_33;
    if ( v13 != 1 )
    {
      result = 0;
      goto LABEL_33;
    }
    v14 = *(_QWORD *)(v8 + 280) == 0;
    goto LABEL_29;
  }
  if ( ((1 << v13) & 0x2C60) != 0 )
    goto LABEL_33;
  if ( ((1 << v13) & 0x104) == 0 )
  {
    if ( v13 == 12 )
    {
      result = ~(*(char *)(*(_QWORD *)v8 + 119LL) >> 31) & 0xFFFFFFEA;
      goto LABEL_33;
    }
    goto LABEL_26;
  }
  v14 = (*(_BYTE *)(v8 + 164) & 1) == 0;
LABEL_29:
  if ( v14 )
    result = 4294967229LL;
  else
    result = 0;
LABEL_33:
  if ( !v12 || HIDWORD(v19) || (v4[1093] & 1) != 0 )
  {
    if ( !(_DWORD)result )
    {
      result = nl80211_validate_key_link_id(a2, v8, v7, HIDWORD(v19) == 1);
      if ( !(_DWORD)result )
      {
        v15 = (unsigned int)v19;
        v16 = HIDWORD(v19) == 1;
        v17 = *(_DWORD **)(*(_QWORD *)v4 + 80LL);
        if ( *(v17 - 1) != 1549052562 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(_BYTE *, __int64, _QWORD, __int64, _BOOL8, __int64))v17)(
                   v4 + 992,
                   v5,
                   v7,
                   v15,
                   v16,
                   v12);
      }
    }
  }
  else
  {
    result = 4294967294LL;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
