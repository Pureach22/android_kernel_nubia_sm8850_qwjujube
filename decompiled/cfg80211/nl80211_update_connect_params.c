__int64 __fastcall nl80211_update_connect_params(__int64 a1, _QWORD *a2)
{
  _BYTE *v3; // x0
  _QWORD *v4; // x8
  __int64 v5; // x1
  _WORD *v6; // x9
  char v7; // w3
  unsigned int updated; // w8
  char v9; // w10
  __int64 v10; // x9
  _WORD *v11; // x13
  _WORD *v12; // x14
  __int64 v13; // x12
  _WORD *v14; // x11
  __int16 v15; // w12
  __int64 v16; // x8
  unsigned int v17; // w11
  bool v20; // w12
  _QWORD s[51]; // [xsp+8h] [xbp-198h] BYREF

  s[50] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x190u);
  v3 = (_BYTE *)a2[6];
  if ( !*(_QWORD *)(*(_QWORD *)v3 + 376LL) )
  {
    updated = -95;
    goto LABEL_19;
  }
  v4 = (_QWORD *)a2[4];
  v5 = a2[7];
  v6 = (_WORD *)v4[42];
  if ( v6 )
  {
    v7 = 1;
    s[7] = v6 + 2;
    s[8] = (unsigned __int16)(*v6 - 4);
  }
  else
  {
    v7 = 0;
  }
  v9 = v3[1105];
  v10 = *(_QWORD *)(v5 + 992);
  v11 = (_WORD *)v4[249];
  if ( (v9 & 0x40) == 0 )
  {
    if ( v11 )
    {
LABEL_18:
      updated = -22;
      goto LABEL_19;
    }
    goto LABEL_13;
  }
  if ( !v11 )
  {
LABEL_13:
    if ( v4[250] || v4[251] || v4[252] )
      goto LABEL_18;
    goto LABEL_16;
  }
  v12 = (_WORD *)v4[250];
  if ( !v12 )
    goto LABEL_18;
  v13 = v4[251];
  if ( !v13 )
    goto LABEL_18;
  v14 = (_WORD *)v4[252];
  if ( !v14 )
    goto LABEL_18;
  v7 |= 2u;
  s[40] = v11 + 2;
  s[41] = (unsigned __int16)(*v11 - 4);
  s[42] = v12 + 2;
  s[43] = (unsigned __int16)(*v12 - 4);
  v15 = *(_WORD *)(v13 + 4);
  s[45] = v14 + 2;
  LOWORD(s[44]) = v15;
  s[46] = (unsigned __int16)(*v14 - 4);
LABEL_16:
  v16 = v4[53];
  if ( !v16 )
  {
LABEL_37:
    if ( (*(_BYTE *)(v10 + 164) & 1) != 0 )
      updated = rdev_update_connect_params();
    else
      updated = -67;
    goto LABEL_19;
  }
  v17 = *(_DWORD *)(v16 + 4);
  if ( v17 > 7 )
    goto LABEL_18;
  if ( (v3[1100] & 0x20) != 0 )
  {
    if ( (~v17 & 6) == 0 )
      goto LABEL_18;
    goto LABEL_31;
  }
  v20 = (v3[1108] & 0x40) == 0 && v17 == 4;
  updated = -22;
  if ( (~v17 & 6) != 0 && !v20 )
  {
LABEL_31:
    if ( v17 == 5 && (v9 & 0x40) == 0 || (v9 & 0x40) != 0 && v17 == 5 && (v7 & 2) == 0 )
      goto LABEL_18;
    LODWORD(s[6]) = v17;
    goto LABEL_37;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return updated;
}
