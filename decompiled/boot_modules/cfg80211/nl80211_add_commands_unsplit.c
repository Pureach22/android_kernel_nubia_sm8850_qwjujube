__int64 __fastcall nl80211_add_commands_unsplit(_BYTE *a1, __int64 a2)
{
  _QWORD *v4; // x8
  unsigned int v5; // w20
  _QWORD *v6; // x8
  _QWORD *v8; // x8
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD **)a1;
  if ( *(_QWORD *)(*(_QWORD *)a1 + 24LL) )
  {
    v9 = 7;
    if ( (unsigned int)nla_put(a2, 1, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
    v5 = 1;
    if ( !*(_QWORD *)(*(_QWORD *)a1 + 40LL) )
    {
LABEL_4:
      if ( !v4[8] )
        goto LABEL_5;
      goto LABEL_13;
    }
  }
  else
  {
    v5 = 0;
    if ( !v4[5] )
      goto LABEL_4;
  }
  ++v5;
  v9 = 6;
  if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
    goto LABEL_71;
  v4 = *(_QWORD **)a1;
  if ( !*(_QWORD *)(*(_QWORD *)a1 + 64LL) )
  {
LABEL_5:
    if ( !v4[14] )
      goto LABEL_6;
    goto LABEL_15;
  }
LABEL_13:
  ++v5;
  v9 = 11;
  if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
    goto LABEL_71;
  v4 = *(_QWORD **)a1;
  if ( !*(_QWORD *)(*(_QWORD *)a1 + 112LL) )
  {
LABEL_6:
    if ( !v4[17] )
      goto LABEL_7;
    goto LABEL_17;
  }
LABEL_15:
  ++v5;
  v9 = 15;
  if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
    goto LABEL_71;
  v4 = *(_QWORD **)a1;
  if ( !*(_QWORD *)(*(_QWORD *)a1 + 136LL) )
  {
LABEL_7:
    if ( !v4[22] )
      goto LABEL_8;
    goto LABEL_19;
  }
LABEL_17:
  ++v5;
  v9 = 19;
  if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
    goto LABEL_71;
  v4 = *(_QWORD **)a1;
  if ( !*(_QWORD *)(*(_QWORD *)a1 + 176LL) )
  {
LABEL_8:
    if ( !v4[30] )
      goto LABEL_23;
    goto LABEL_21;
  }
LABEL_19:
  ++v5;
  v9 = 23;
  if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
    goto LABEL_71;
  v4 = *(_QWORD **)a1;
  if ( *(_QWORD *)(*(_QWORD *)a1 + 240LL) )
  {
LABEL_21:
    ++v5;
    v9 = 29;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
LABEL_23:
  if ( v4[35] )
  {
    ++v5;
    v9 = 25;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( v4[42] )
  {
    ++v5;
    v9 = 37;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( v4[43] )
  {
    ++v5;
    v9 = 38;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( v4[44] )
  {
    ++v5;
    v9 = 39;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( v4[45] )
  {
    ++v5;
    v9 = 40;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( v4[49] )
  {
    ++v5;
    v9 = 43;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( v4[31] )
  {
    ++v5;
    v9 = 68;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( v4[60] )
  {
    ++v5;
    v9 = 52;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( v4[61] )
  {
    ++v5;
    v9 = 53;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( v4[62] )
  {
    ++v5;
    v9 = 54;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( (a1[1094] & 0x20) != 0 && v4[63] )
  {
    ++v5;
    v9 = 55;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( v4[58] )
  {
    ++v5;
    v9 = 57;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v4 = *(_QWORD **)a1;
  }
  if ( !v4[65] )
    goto LABEL_63;
  ++v5;
  v9 = 59;
  if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
  {
LABEL_71:
    v5 = -105;
    goto LABEL_72;
  }
  v4 = *(_QWORD **)a1;
LABEL_63:
  if ( v4[66] )
  {
    ++v5;
    v9 = 67;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
  }
  if ( (a1[1092] & 8) != 0 )
  {
    ++v5;
    v9 = 49;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
  }
  v6 = *(_QWORD **)a1;
  if ( *(_QWORD *)(*(_QWORD *)a1 + 312LL) || v6[14] || v6[31] )
  {
    ++v5;
    v9 = 65;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v6 = *(_QWORD **)a1;
  }
  if ( (a1[1093] & 0x80) != 0 )
  {
    if ( v6[77] )
    {
      ++v5;
      v9 = 82;
      if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
        goto LABEL_71;
      v6 = *(_QWORD **)a1;
    }
    if ( v6[78] )
    {
      ++v5;
      v9 = 81;
      if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
        goto LABEL_71;
      v6 = *(_QWORD **)a1;
    }
  }
  if ( a1[1129] && v6[74] )
  {
    ++v5;
    v9 = 75;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v6 = *(_QWORD **)a1;
  }
  if ( v6[79] )
  {
    ++v5;
    v9 = 84;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v6 = *(_QWORD **)a1;
  }
  if ( v6[80] )
  {
    ++v5;
    v9 = 87;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
  }
  if ( (a1[1094] & 4) != 0 )
  {
    ++v5;
    v9 = 85;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
  }
  v8 = *(_QWORD **)a1;
  if ( *(_QWORD *)(*(_QWORD *)a1 + 656LL) )
  {
    ++v5;
    v9 = 89;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v8 = *(_QWORD **)a1;
  }
  if ( v8[51] )
  {
    ++v5;
    v9 = 92;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v8 = *(_QWORD **)a1;
  }
  if ( v8[56] )
  {
    ++v5;
    v9 = 45;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v8 = *(_QWORD **)a1;
  }
  if ( v8[46] || v8[42] )
  {
    ++v5;
    v9 = 46;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
    v8 = *(_QWORD **)a1;
  }
  if ( v8[48] || v8[44] )
  {
    ++v5;
    v9 = 48;
    if ( (unsigned int)nla_put(a2, v5, 4, &v9) )
      goto LABEL_71;
  }
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return v5;
}
