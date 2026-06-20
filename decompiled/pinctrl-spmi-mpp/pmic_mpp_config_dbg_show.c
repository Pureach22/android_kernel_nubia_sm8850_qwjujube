__int64 __fastcall pmic_mpp_config_dbg_show(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 drvdata; // x0
  __int64 v7; // x8
  _QWORD *v8; // x20
  unsigned __int16 *v9; // x22
  __int64 result; // x0
  const char *v11; // x2
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x8
  const char *v15; // x2
  int v16; // w2
  const char *v17; // x1
  __int64 v18; // x0
  __int64 v19; // x2
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = pinctrl_dev_get_drvdata();
  v7 = *(_QWORD *)(a1 + 16);
  v8 = (_QWORD *)drvdata;
  v9 = *(unsigned __int16 **)(*(_QWORD *)(v7 + 8) + 24LL * a3 + 16);
  seq_printf(a2, " mpp%-2d:", a3 + 1);
  if ( (v9[1] & 1) == 0 )
  {
    v17 = " ---";
    v18 = a2;
    v19 = 4;
LABEL_21:
    result = seq_write(v18, v17, v19);
    goto LABEL_22;
  }
  if ( *((_BYTE *)v9 + 5) == 1 )
  {
    v20 = 0;
    result = regmap_read(v8[1], (unsigned int)*v9 + 16, &v20);
    if ( (result & 0x80000000) != 0 )
    {
      result = dev_err(*v8, "read 0x%x failed\n", 16);
      goto LABEL_22;
    }
    if ( v20 < 0 )
    {
LABEL_22:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    *((_BYTE *)v9 + 3) = v20 & 1;
  }
  if ( *((_BYTE *)v9 + 4) )
    v11 = "out";
  else
    v11 = "in";
  v12 = seq_printf(a2, " %-4s", v11);
  v13 = *((unsigned int *)v9 + 7);
  if ( (unsigned int)v13 < 3 )
  {
    seq_printf(a2, " %-7s", pmic_mpp_functions[v13]);
    seq_printf(a2, " vin-%d", *((_DWORD *)v9 + 3));
    v12 = seq_printf(a2, " %d", *((_DWORD *)v9 + 5));
    if ( *((_BYTE *)v9 + 7) != 1 )
    {
LABEL_13:
      if ( *((_BYTE *)v9 + 3) )
        v15 = "high";
      else
        v15 = "low";
      result = seq_printf(a2, " %-4s", v15);
      v16 = *((_DWORD *)v9 + 9);
      if ( v16 )
        result = seq_printf(a2, " dtest%d", v16);
      if ( *((_BYTE *)v9 + 6) != 1 )
        goto LABEL_22;
      v17 = " paired";
      v18 = a2;
      v19 = 7;
      goto LABEL_21;
    }
    v14 = *((unsigned int *)v9 + 6);
    if ( (unsigned int)v14 <= 3 )
    {
      seq_printf(a2, " %-8s", pmic_mpp_config_dbg_show_biases[v14]);
      goto LABEL_13;
    }
  }
  __break(0x5512u);
  return pmic_mpp_direction_input(v12);
}
