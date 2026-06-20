__int64 __fastcall battery_chg_update_soc_work(__int64 a1)
{
  int *v1; // x22
  __int64 v2; // x21
  int v4; // w9
  int v5; // w20
  int v6; // w23
  int v7; // w8
  unsigned int i; // w22
  int v9; // w8
  int v10; // w0
  __int64 v11; // x2
  __int64 v12; // x0
  __int64 v13; // x20
  __int64 result; // x0
  __int64 v15; // [xsp+0h] [xbp-20h] BYREF
  int v16; // [xsp+8h] [xbp-18h]
  __int64 v17; // [xsp+Ch] [xbp-14h]
  int v18; // [xsp+14h] [xbp-Ch]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v1 = (int *)(a1 - 516);
  v2 = a1 - 904;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0x400000000LL;
  v4 = *(_DWORD *)(a1 - 516);
  v18 = 0;
  v15 = 0x10000800ALL;
  v16 = v4;
  v5 = 0;
  if ( (unsigned int)battery_chg_write(a1 - 904, (__int64)&v15, 0x18u, 0x3E8u) )
  {
    if ( *(_DWORD *)(a1 - 8) )
      goto LABEL_3;
LABEL_6:
    *(_DWORD *)(a1 - 8) = v5;
    if ( !v2 )
      goto LABEL_18;
    goto LABEL_7;
  }
  v5 = *(_DWORD *)(*(_QWORD *)(a1 - 528) + 16LL);
  if ( !*(_DWORD *)(a1 - 8) )
    goto LABEL_6;
LABEL_3:
  if ( !v2 )
    goto LABEL_18;
LABEL_7:
  v6 = 0;
  while ( 1 )
  {
    if ( ((*(_DWORD *)(a1 + 244) >> v6) & 1) != 0 )
    {
      v7 = *v1;
      HIDWORD(v17) = v6;
      v18 = 0;
      v15 = 0x10000800ALL;
      v16 = v7;
      LODWORD(v17) = 0;
      if ( (unsigned int)battery_chg_write(v2, (__int64)&v15, 0x18u, 0x3E8u) )
        break;
    }
    if ( ++v6 == 32 )
    {
      for ( i = 0; ; ++i )
      {
        if ( ((*(_DWORD *)(a1 + 248) >> i) & 1) != 0 )
        {
          v9 = *(_DWORD *)(a1 - 468);
          HIDWORD(v17) = i;
          v18 = 0;
          v15 = 0x10000800ALL;
          v16 = v9;
          LODWORD(v17) = 0;
          v10 = battery_chg_write(v2, (__int64)&v15, 0x18u, 0x3E8u);
          if ( i > 0x1E || v10 )
            goto LABEL_18;
        }
        else if ( i > 0x1E )
        {
          goto LABEL_18;
        }
      }
    }
  }
LABEL_18:
  v11 = *(unsigned int *)(a1 - 8);
  if ( (int)v11 - v5 > 0 || v5 - (int)v11 >= 1 )
  {
    printk(&unk_109F5, "battery_chg_update_soc_work", v11);
    v12 = *(_QWORD *)(a1 - 552);
    *(_DWORD *)(a1 - 8) = v5;
    power_supply_changed(v12);
  }
  if ( *(_BYTE *)(a1 + 148) )
    v13 = 2500;
  else
    v13 = 150000;
  printk(&unk_11E17, "battery_chg_update_soc_work", *(unsigned __int8 *)(a1 + 148));
  result = queue_delayed_work_on(32, system_wq, a1, v13);
  _ReadStatusReg(SP_EL0);
  return result;
}
