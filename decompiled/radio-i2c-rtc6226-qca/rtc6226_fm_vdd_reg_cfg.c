__int64 __fastcall rtc6226_fm_vdd_reg_cfg(__int64 a1, char a2)
{
  _QWORD *v2; // x20
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x1
  unsigned int v6; // w0
  __int64 v7; // x0
  __int64 v8; // x2
  void *v9; // x8
  const char *v10; // x1
  unsigned int v11; // w19

  v2 = *(_QWORD **)(a1 + 1728);
  if ( !v2 )
  {
    printk(&unk_CF16, "rtc6226_fm_vdd_reg_cfg");
    return 0;
  }
  v3 = *v2;
  if ( (a2 & 1) != 0 )
  {
    LODWORD(result) = regulator_set_voltage(v3, *((unsigned int *)v2 + 4), *((unsigned int *)v2 + 5));
    if ( (result & 0x80000000) == 0 )
    {
      v5 = *((unsigned int *)v2 + 6);
      if ( (_DWORD)v5 && (v6 = regulator_set_load(*v2, v5), (v6 & 0x80000000) != 0) )
      {
        v11 = v6;
        printk(&unk_D536, "rtc6226_fm_vdd_reg_cfg");
      }
      else
      {
        result = regulator_enable(*v2);
        if ( (result & 0x80000000) == 0 )
        {
          *((_BYTE *)v2 + 28) = 1;
          return result;
        }
        v11 = result;
        printk(&unk_D128, v2[1]);
        regulator_set_voltage(*v2, 0, *((unsigned int *)v2 + 5));
      }
      return v11;
    }
LABEL_14:
    v10 = (const char *)v2[1];
    v9 = &unk_D029;
    goto LABEL_16;
  }
  LODWORD(result) = regulator_disable(v3);
  if ( (result & 0x80000000) != 0 )
  {
    v10 = (const char *)v2[1];
    v9 = &unk_D38A;
    goto LABEL_16;
  }
  v7 = *v2;
  v8 = *((unsigned int *)v2 + 5);
  *((_BYTE *)v2 + 28) = 0;
  result = regulator_set_voltage(v7, 0, v8);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_14;
  if ( *((_DWORD *)v2 + 6) )
  {
    result = regulator_set_load(*v2, 0);
    if ( (result & 0x80000000) != 0 )
    {
      v9 = &unk_D4CD;
      v10 = "rtc6226_fm_vdd_reg_cfg";
LABEL_16:
      v11 = result;
      printk(v9, v10);
      return v11;
    }
  }
  return result;
}
