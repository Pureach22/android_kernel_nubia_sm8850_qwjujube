__int64 __fastcall poll_gdsc_status(__int64 a1, int a2)
{
  __int64 v4; // x21
  int v5; // w23
  unsigned int v6; // w22
  bool v7; // zf
  char v8; // w9
  bool v9; // vf
  int v10; // w8
  __int64 result; // x0
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 352);
  v5 = *(_DWORD *)(a1 + 508);
  if ( !v4 || (*(_BYTE *)(a1 + 515) & 1) != 0 )
  {
    v7 = v4 == 0;
    v4 = *(_QWORD *)(a1 + 336);
    v8 = !v7;
    if ( (((unsigned __int8)v8 | *(_BYTE *)(a1 + 515)) & 1) != 0 )
      v6 = 4;
    else
      v6 = 0;
  }
  else
  {
    v6 = 0;
  }
  v12 = 0;
  if ( v5 < 1 )
  {
LABEL_23:
    result = 4294967186LL;
    goto LABEL_24;
  }
  while ( 1 )
  {
    regmap_read(v4, v6, &v12);
    v10 = v12;
    if ( a2 == 1 )
      break;
    if ( *(_BYTE *)(a1 + 515) )
    {
      v12 &= 0x8000u;
      if ( (v10 & 0x8000) != 0 )
        goto LABEL_22;
    }
    else
    {
      v12 = v12 >= 0;
      if ( v10 >= 0 )
        goto LABEL_22;
    }
LABEL_13:
    _const_udelay(4295);
    v9 = __OFSUB__(v5--, 1);
    if ( (v5 < 0) ^ v9 | (v5 == 0) )
      goto LABEL_23;
  }
  if ( *(_BYTE *)(a1 + 515) )
  {
    v12 &= 0x10000u;
    if ( (v10 & 0x10000) != 0 )
      goto LABEL_22;
    goto LABEL_13;
  }
  v12 &= 0x80000000;
  if ( (v10 & 0x80000000) == 0 )
    goto LABEL_13;
LABEL_22:
  result = 0;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
