__int64 __fastcall pmic_gpio_set_mux(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 drvdata; // x0
  __int64 v7; // x1
  __int64 *v8; // x19
  unsigned __int16 *v9; // x21
  int v10; // w8
  char v11; // w9
  __int64 v12; // x2
  unsigned int v13; // w0
  unsigned int v14; // w0
  unsigned int v15; // w0
  __int64 v16; // x8
  unsigned int v17; // w19
  __int64 v18; // x2
  __int64 result; // x0

  drvdata = pinctrl_dev_get_drvdata();
  if ( a2 >= 0xA )
  {
    printk(&unk_CAB0, a2);
    return 4294967274LL;
  }
  v8 = (__int64 *)drvdata;
  v9 = *(unsigned __int16 **)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL) + 24LL * a3 + 16);
  v10 = *((unsigned __int8 *)v9 + 9);
  if ( (v10 & 1) == 0 )
  {
    if ( (a2 & 0xE) == 4 )
    {
      printk(&unk_CE6F, v7);
      return 4294967274LL;
    }
    if ( a2 > 5 )
      a2 -= 2;
  }
  v11 = *((_BYTE *)v9 + 8);
  *((_DWORD *)v9 + 8) = a2;
  *((_BYTE *)v9 + 3) = 1;
  if ( (v11 & 1) != 0 )
  {
    v12 = 3;
  }
  else
  {
    v12 = *((unsigned __int8 *)v9 + 6);
    if ( (_DWORD)v12 == 1 && (*((_BYTE *)v9 + 7) & 1) != 0 )
      v12 = 2;
  }
  if ( !v10 )
  {
    v13 = regmap_write(
            *(_QWORD *)(drvdata + 8),
            (unsigned int)*v9 + 64,
            (16 * (_DWORD)v12) | (2 * a2) | *((unsigned __int8 *)v9 + 4));
    if ( (v13 & 0x80000000) == 0 )
      goto LABEL_17;
LABEL_20:
    v16 = *v8;
    v17 = v13;
    v18 = 64;
    goto LABEL_24;
  }
  v13 = regmap_write(*(_QWORD *)(drvdata + 8), (unsigned int)*v9 + 64, v12);
  if ( (v13 & 0x80000000) != 0 )
    goto LABEL_20;
  v14 = regmap_write(v8[1], (unsigned int)*v9 + 74, (unsigned int)(*((_DWORD *)v9 + 9) - 1));
  if ( (v14 & 0x80000000) != 0 )
  {
    v16 = *v8;
    v17 = v14;
    v18 = 74;
    goto LABEL_24;
  }
  v15 = regmap_write(v8[1], (unsigned int)*v9 + 68, *((_DWORD *)v9 + 8) & 0xF | (*((unsigned __int8 *)v9 + 4) << 7));
  if ( (v15 & 0x80000000) != 0 )
  {
    v16 = *v8;
    v17 = v15;
    v18 = 68;
LABEL_24:
    dev_err(v16, "write 0x%x failed\n", v18);
    return v17;
  }
LABEL_17:
  result = regmap_write(v8[1], (unsigned int)*v9 + 70, *((unsigned __int8 *)v9 + 2) << 7);
  if ( (result & 0x80000000) != 0 )
  {
    v16 = *v8;
    v17 = result;
    v18 = 70;
    goto LABEL_24;
  }
  return result;
}
