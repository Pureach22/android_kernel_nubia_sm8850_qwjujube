__int64 __fastcall pmic_mpp_set_mux(__int64 a1, int a2, unsigned int a3)
{
  __int64 drvdata; // x0
  _QWORD *v7; // x19
  unsigned __int16 *v8; // x21
  int v9; // w8
  int v10; // w9
  int v11; // w9
  unsigned int v12; // w0
  __int64 result; // x0
  unsigned int v14; // w20
  int v15; // w2

  drvdata = pinctrl_dev_get_drvdata();
  v7 = (_QWORD *)drvdata;
  v8 = *(unsigned __int16 **)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL) + 24LL * a3 + 16);
  *((_DWORD *)v8 + 7) = a2;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      if ( *((_BYTE *)v8 + 5) == 1 )
      {
        if ( *((_BYTE *)v8 + 4) )
          v9 = 48;
        else
          v9 = 64;
        v10 = *((_DWORD *)v8 + 9);
        if ( !v10 )
          goto LABEL_20;
LABEL_18:
        v11 = 2 * v10 + 6;
        goto LABEL_23;
      }
      v9 = 80;
      v10 = *((_DWORD *)v8 + 9);
      if ( v10 )
        goto LABEL_18;
    }
    else
    {
      v9 = 96;
      v10 = *((_DWORD *)v8 + 9);
      if ( v10 )
        goto LABEL_18;
    }
  }
  else
  {
    if ( *((_BYTE *)v8 + 5) == 1 )
    {
      if ( *((_BYTE *)v8 + 4) )
        v9 = 32;
      else
        v9 = 0;
      v10 = *((_DWORD *)v8 + 9);
      if ( !v10 )
        goto LABEL_20;
      goto LABEL_18;
    }
    v9 = 16;
    v10 = *((_DWORD *)v8 + 9);
    if ( v10 )
      goto LABEL_18;
  }
LABEL_20:
  if ( *((_BYTE *)v8 + 6) )
    v11 = 2;
  else
    v11 = 0;
LABEL_23:
  v12 = regmap_write(
          *(_QWORD *)(drvdata + 8),
          (unsigned int)*v8 + 64,
          v11 | v9 | (unsigned int)*((unsigned __int8 *)v8 + 3));
  if ( (v12 & 0x80000000) != 0 )
  {
    v14 = v12;
    v15 = 64;
LABEL_28:
    dev_err(*v7, "write 0x%x failed\n", v15);
    return v14;
  }
  result = regmap_write(v7[1], (unsigned int)*v8 + 70, *((unsigned __int8 *)v8 + 2) << 7);
  if ( (result & 0x80000000) != 0 )
  {
    v14 = result;
    v15 = 70;
    goto LABEL_28;
  }
  return result;
}
