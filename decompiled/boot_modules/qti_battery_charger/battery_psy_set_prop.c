__int64 __fastcall battery_psy_set_prop(__int64 a1, int a2, unsigned int *a3)
{
  unsigned __int8 *drvdata; // x0
  unsigned int v6; // w20
  unsigned int v7; // w8
  unsigned __int8 *v8; // x21
  int v9; // w10
  unsigned int v10; // w19
  unsigned int v11; // w8
  bool v12; // zf
  int v13; // w8
  unsigned __int8 *v14; // x21
  void *v16; // x0
  const char *v17; // x1
  __int64 v18; // x2
  void *v19; // x0
  const char *v20; // x1
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  __int64 v22; // [xsp+8h] [xbp-18h]
  unsigned int v23; // [xsp+10h] [xbp-10h]
  int v24; // [xsp+14h] [xbp-Ch]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = (unsigned __int8 *)power_supply_get_drvdata();
  if ( a2 == 36 )
  {
    v6 = *a3;
    if ( *a3 - 101 > 0xFFFFFFD1 )
    {
      if ( drvdata[1143] == 1 )
      {
        v11 = drvdata[1141];
        v12 = v6 <= v11 || v11 == 0;
        v21 = 0x10000800ALL;
        v22 = 0x100000048LL;
        if ( v12 )
          v13 = 5;
        else
          v13 = v6 - v11;
        v14 = drvdata;
        v23 = v6;
        v24 = v13;
        v10 = battery_chg_write((__int64)drvdata, (__int64)&v21, 0x18u, 0x3E8u);
        if ( (v10 & 0x80000000) != 0 )
        {
          printk(&unk_111E9, "battery_psy_set_charge_threshold", v10);
          v19 = &unk_10022;
          v20 = "battery_psy_set_charge_end_threshold";
          goto LABEL_32;
        }
        drvdata = v14;
      }
      else
      {
        v10 = 0;
      }
      drvdata[1142] = v6;
      goto LABEL_26;
    }
    v16 = &unk_1122C;
    v17 = "battery_psy_set_charge_end_threshold";
    v18 = 55;
LABEL_29:
    printk(v16, v17, v18);
    v10 = -22;
    goto LABEL_26;
  }
  if ( a2 != 35 )
  {
    v10 = -22;
    goto LABEL_26;
  }
  v6 = *a3;
  if ( *a3 - 96 <= 0xFFFFFFD1 )
  {
    v16 = &unk_115A6;
    v17 = "battery_psy_set_charge_start_threshold";
    v18 = 50;
    goto LABEL_29;
  }
  if ( drvdata[1143] != 1 )
  {
    v10 = 0;
    drvdata[1141] = v6;
    goto LABEL_26;
  }
  v7 = drvdata[1142];
  v8 = drvdata;
  if ( v7 >= v6 )
  {
    v9 = v7 - v6;
  }
  else
  {
    v7 = v6 + 5;
    v9 = 5;
  }
  if ( v7 >= 0x64 )
    v7 = 100;
  v21 = 0x10000800ALL;
  v22 = 0x100000048LL;
  v23 = v7;
  v24 = v9;
  v10 = battery_chg_write((__int64)drvdata, (__int64)&v21, 0x18u, 0x3E8u);
  if ( (v10 & 0x80000000) != 0 )
  {
    printk(&unk_111E9, "battery_psy_set_charge_threshold", v10);
    v19 = &unk_11384;
    v20 = "battery_psy_set_charge_start_threshold";
LABEL_32:
    printk(v19, v20, v6);
    goto LABEL_26;
  }
  v8[1141] = v6;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v10;
}
