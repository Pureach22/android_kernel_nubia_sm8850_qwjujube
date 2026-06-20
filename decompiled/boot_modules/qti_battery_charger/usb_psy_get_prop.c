__int64 __fastcall usb_psy_get_prop(__int64 a1, unsigned int a2, int *a3)
{
  __int64 drvdata; // x0
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v9; // x22
  int v10; // w0
  __int64 v11; // x9
  int v12; // w8
  int v13; // w9
  __int64 v14; // [xsp+0h] [xbp-20h] BYREF
  int v15; // [xsp+8h] [xbp-18h]
  int v16; // [xsp+Ch] [xbp-14h]
  int v17; // [xsp+10h] [xbp-10h]
  int v18; // [xsp+14h] [xbp-Ch]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = power_supply_get_drvdata();
  *a3 = -61;
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
      v16 = 0;
      v17 = v7;
      v18 = 0;
      v14 = 0x10000800ALL;
      v9 = drvdata;
      v15 = *(_DWORD *)(drvdata + 436);
      v10 = battery_chg_write(drvdata, (__int64)&v14, 0x18u, 0x3E8u);
      if ( v10 < 0 )
      {
        LODWORD(v7) = v10;
      }
      else
      {
        v11 = v7 & 0x7FFFFFFF;
        LODWORD(v7) = 0;
        v12 = *(_DWORD *)(*(_QWORD *)(v9 + 424) + 4 * v11);
        *a3 = v12;
        if ( a2 == 52 )
        {
          if ( v12 > 0 )
            v13 = 5;
          else
            v13 = -5;
          *a3 = (v13 + v12) / 10;
        }
      }
    }
  }
  else
  {
LABEL_5:
    if ( *(_QWORD *)(drvdata + 400) )
      printk(&unk_FCFE, "get_property_id", a2);
    LODWORD(v7) = -2;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v7;
}
