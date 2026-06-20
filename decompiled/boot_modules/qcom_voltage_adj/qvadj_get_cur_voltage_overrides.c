__int64 __fastcall qvadj_get_cur_voltage_overrides(_BYTE *a1, _BYTE *a2)
{
  __int64 result; // x0
  unsigned int v5; // w21
  __int64 v6; // x1
  unsigned int v7; // w8
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  result = 4294967274LL;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  if ( a1 && a2 )
  {
    mutex_lock(pd);
    v5 = regmap_read(*(_QWORD *)(pd + 48), 29009, &v8);
    if ( (v5 & 0x80000000) != 0 )
      printk(&unk_65D2, v5);
    mutex_unlock(pd);
    v7 = v8;
    if ( (v8 & 8) != 0 )
    {
      *a1 = v8 & 7;
      if ( (v7 & 0x80) != 0 )
      {
LABEL_7:
        result = v5;
        *a2 = (v7 >> 4) & 7;
        goto LABEL_8;
      }
    }
    else
    {
      *a1 = 0;
      printk(&unk_65AD, v6);
      v7 = v8;
      if ( (v8 & 0x80) != 0 )
        goto LABEL_7;
    }
    *a2 = 0;
    printk(&unk_666E, v6);
    result = v5;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
