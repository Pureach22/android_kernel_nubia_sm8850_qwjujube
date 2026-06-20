__int64 __fastcall gdsc_debug_print_regs(__int64 a1)
{
  __int64 v1; // x20
  __int64 drvdata; // x0
  __int64 v3; // x1
  __int64 result; // x0
  __int64 v5; // x19
  _QWORD *i; // x23
  const char *v7; // x1
  __int64 v8; // x3
  int v9; // w0
  __int64 v10; // x1
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  int v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 120);
  drvdata = rdev_get_drvdata(v1);
  v12 = 0;
  v11 = 0;
  if ( drvdata )
  {
    v5 = drvdata;
    ww_mutex_lock(v1 + 152, 0);
    if ( *(_DWORD *)(v1 + 16) )
      printk(&unk_8AB9, "Device-Supply");
    for ( i = *(_QWORD **)(v1 + 40); i != (_QWORD *)(v1 + 40); i = (_QWORD *)*i )
    {
      if ( i[9] )
        v7 = (const char *)i[9];
      else
        v7 = "(null)-(null)";
      printk(&unk_8A00, v7);
    }
    ww_mutex_unlock(v1 + 152);
    if ( dword_2C8 )
      v8 = 3;
    else
      v8 = 1;
    v9 = regmap_bulk_read(*(_QWORD *)(v5 + 336), 0, &v11, v8);
    v10 = *(_QWORD *)(v5 + 8);
    if ( v9 )
    {
      result = printk(&unk_8A0C, v10);
    }
    else
    {
      printk(&unk_87E4, v10);
      result = printk(&unk_8E29, (unsigned int)v11);
    }
  }
  else
  {
    result = printk(&unk_8C25, v3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
