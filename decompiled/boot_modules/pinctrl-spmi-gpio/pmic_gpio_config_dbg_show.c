__int64 __fastcall pmic_gpio_config_dbg_show(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 drvdata; // x0
  __int64 v7; // x8
  _QWORD *v8; // x20
  unsigned __int16 *v9; // x22
  __int64 result; // x0
  unsigned int v11; // w8
  unsigned int v12; // w20
  const char *v13; // x2
  const char *v14; // x2
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = pinctrl_dev_get_drvdata();
  v7 = *(_QWORD *)(a1 + 16);
  v8 = (_QWORD *)drvdata;
  v9 = *(unsigned __int16 **)(*(_QWORD *)(v7 + 8) + 24LL * a3 + 16);
  seq_printf(a2, " gpio%-2d:", a3 + 1);
  v18 = 0;
  if ( (regmap_read(v8[1], (unsigned int)*v9 + 70, &v18) & 0x80000000) != 0 )
  {
    dev_err(*v8, "read 0x%x failed\n", 70);
    goto LABEL_3;
  }
  if ( v18 <= 127 )
  {
LABEL_3:
    result = seq_write(a2, " ---", 4);
    goto LABEL_25;
  }
  if ( *((_BYTE *)v9 + 7) != 1 )
    goto LABEL_8;
  v18 = 0;
  result = regmap_read(v8[1], (unsigned int)*v9 + 16, &v18);
  if ( (result & 0x80000000) != 0 )
  {
    result = dev_err(*v8, "read 0x%x failed\n", 16);
    goto LABEL_25;
  }
  if ( (v18 & 0x80000000) == 0 )
  {
    *((_BYTE *)v9 + 4) = v18 & 1;
LABEL_8:
    v11 = *((_DWORD *)v9 + 8);
    if ( *((_BYTE *)v9 + 9) & 1 | (v11 < 4) )
      v12 = *((_DWORD *)v9 + 8);
    else
      v12 = v11 + 2;
    if ( *((_BYTE *)v9 + 8) == 1 )
    {
      seq_write(a2, " analog-pass", 12);
    }
    else
    {
      if ( *((_BYTE *)v9 + 6) )
        v13 = "out";
      else
        v13 = "in";
      seq_printf(a2, " %-4s", v13);
    }
    if ( *((_BYTE *)v9 + 4) )
      v14 = "high";
    else
      v14 = "low";
    seq_printf(a2, " %-4s", v14);
    if ( v12 >= 0xA
      || (seq_printf(a2, " %-7s", pmic_gpio_functions[v12]),
          seq_printf(a2, " vin-%d", *((_DWORD *)v9 + 4)),
          v15 = *((unsigned int *)v9 + 6),
          (unsigned int)v15 > 5)
      || (seq_printf(a2, " %-27s", pmic_gpio_config_dbg_show_biases[v15]),
          v16 = *((unsigned int *)v9 + 5),
          (unsigned int)v16 > 2)
      || (seq_printf(a2, " %-10s", pmic_gpio_config_dbg_show_buffer_types[v16]),
          v17 = *((unsigned int *)v9 + 7),
          (unsigned int)v17 > 3) )
    {
      __break(0x5512u);
    }
    seq_printf(a2, " %-7s", pmic_gpio_config_dbg_show_strengths[v17]);
    seq_printf(a2, " atest-%d", *((_DWORD *)v9 + 9));
    result = seq_printf(a2, " dtest-%d", *((_DWORD *)v9 + 10));
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
