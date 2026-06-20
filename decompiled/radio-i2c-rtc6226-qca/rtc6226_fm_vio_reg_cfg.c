__int64 __fastcall rtc6226_fm_vio_reg_cfg(__int64 a1, char a2)
{
  _QWORD *v2; // x20
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x1
  void *v8; // x8
  unsigned int v9; // w19

  v2 = *(_QWORD **)(a1 + 1736);
  if ( !v2 )
  {
    printk(&unk_D06A, "rtc6226_fm_vio_reg_cfg");
    return 0;
  }
  v3 = *v2;
  if ( (a2 & 1) != 0 )
  {
    LODWORD(result) = regulator_set_voltage(v3, *((unsigned int *)v2 + 4), *((unsigned int *)v2 + 5));
    if ( (result & 0x80000000) == 0 )
    {
      result = regulator_enable(*v2);
      if ( (result & 0x80000000) == 0 )
      {
        *((_BYTE *)v2 + 28) = 1;
        return result;
      }
      v9 = result;
      printk(&unk_D128, v2[1]);
      regulator_set_voltage(*v2, 0, *((unsigned int *)v2 + 5));
      return v9;
    }
  }
  else
  {
    LODWORD(result) = regulator_disable(v3);
    if ( (result & 0x80000000) != 0 )
    {
      v7 = v2[1];
      v8 = &unk_DC83;
      goto LABEL_11;
    }
    v5 = *v2;
    v6 = *((unsigned int *)v2 + 5);
    *((_BYTE *)v2 + 28) = 0;
    result = regulator_set_voltage(v5, 0, v6);
    if ( (result & 0x80000000) == 0 )
      return result;
  }
  v7 = v2[1];
  v8 = &unk_D029;
LABEL_11:
  v9 = result;
  printk(v8, v7);
  return v9;
}
