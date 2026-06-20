__int64 __fastcall wls_psy_get_prop(__int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 drvdata; // x0
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v9; // x21
  int v10; // w0
  __int64 v11; // x9
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  int v13; // [xsp+8h] [xbp-18h]
  int v14; // [xsp+Ch] [xbp-14h]
  int v15; // [xsp+10h] [xbp-10h]
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = power_supply_get_drvdata();
  *a3 = -61;
  v6 = *(unsigned int *)(drvdata + 480);
  if ( (_DWORD)v6 )
  {
    v7 = 0;
    while ( *(_DWORD *)(*(_QWORD *)(drvdata + 464) + 4 * v7) != a2 )
    {
      if ( v6 == ++v7 )
        goto LABEL_5;
    }
    if ( (v7 & 0x80000000) == 0 )
    {
      v14 = 0;
      v15 = v7;
      v16 = 0;
      v12 = 0x10000800ALL;
      v9 = drvdata;
      v13 = *(_DWORD *)(drvdata + 484);
      v10 = battery_chg_write(drvdata, (__int64)&v12, 0x18u, 0x3E8u);
      if ( v10 < 0 )
      {
        LODWORD(v7) = v10;
      }
      else
      {
        v11 = v7 & 0x7FFFFFFF;
        LODWORD(v7) = 0;
        *a3 = *(_DWORD *)(*(_QWORD *)(v9 + 472) + 4 * v11);
      }
    }
  }
  else
  {
LABEL_5:
    if ( *(_QWORD *)(drvdata + 448) )
      printk(&unk_FCFE, "get_property_id", a2);
    LODWORD(v7) = -2;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v7;
}
