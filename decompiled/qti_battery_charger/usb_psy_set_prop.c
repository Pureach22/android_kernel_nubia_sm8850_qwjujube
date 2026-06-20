__int64 __fastcall usb_psy_set_prop(__int64 a1, unsigned int a2, unsigned int *a3)
{
  __int64 drvdata; // x0
  __int64 v6; // x8
  __int64 v7; // x1

  drvdata = power_supply_get_drvdata();
  v6 = *(unsigned int *)(drvdata + 432);
  if ( (_DWORD)v6 )
  {
    v7 = 0;
    while ( *(_DWORD *)(*(_QWORD *)(drvdata + 416) + 4 * v7) != a2 )
    {
      if ( v6 == ++v7 )
        goto LABEL_5;
    }
    if ( (v7 & 0x80000000) == 0 )
    {
      if ( a2 == 38 )
        LODWORD(v7) = usb_psy_set_icl((_DWORD *)drvdata, v7, *a3);
      else
        LODWORD(v7) = 0;
    }
  }
  else
  {
LABEL_5:
    if ( *(_QWORD *)(drvdata + 400) )
      printk(&unk_FCFE, "get_property_id", a2);
    LODWORD(v7) = -2;
  }
  return (unsigned int)v7;
}
