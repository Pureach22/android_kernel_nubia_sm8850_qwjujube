__int64 __fastcall battery_chg_update_prop_work(__int64 a1)
{
  int *v1; // x21
  __int64 *v2; // x20
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w9
  int v8; // w24
  int v9; // w8
  unsigned int i; // w22
  int v11; // w8
  int v12; // w0
  unsigned int *v13; // x8
  int v14; // w21
  int v15; // w22
  __int64 result; // x0
  __int64 v17; // x2
  signed int v18; // w22
  __int64 v19; // x2
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  int v24; // [xsp+8h] [xbp-18h]
  __int64 v25; // [xsp+Ch] [xbp-14h]
  int v26; // [xsp+14h] [xbp-Ch]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v1 = (int *)(a1 - 300);
  v2 = (__int64 *)(a1 - 736);
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 - 300);
  v25 = 0xD00000000LL;
  v26 = 0;
  v23 = 0x10000800ALL;
  v24 = v4;
  battery_chg_write(a1 - 736, (__int64)&v23, 0x18u, 0x3E8u);
  v25 = 0x400000000LL;
  v5 = *(_DWORD *)(a1 - 348);
  v26 = 0;
  v23 = 0x10000800ALL;
  v24 = v5;
  battery_chg_write((__int64)v2, (__int64)&v23, 0x18u, 0x3E8u);
  v6 = *(_DWORD *)(a1 - 348);
  v25 = 0;
  v26 = 0;
  v23 = 0x10000800ALL;
  v24 = v6;
  battery_chg_write((__int64)v2, (__int64)&v23, 0x18u, 0x3E8u);
  v7 = *(_DWORD *)(a1 - 348);
  v26 = 0;
  v25 = 0x900000000LL;
  v23 = 0x10000800ALL;
  v24 = v7;
  battery_chg_write((__int64)v2, (__int64)&v23, 0x18u, 0x3E8u);
  if ( v2 )
  {
    v8 = 0;
    while ( 1 )
    {
      if ( ((*(_DWORD *)(a1 + 412) >> v8) & 1) != 0 )
      {
        v9 = *(_DWORD *)(a1 - 348);
        HIDWORD(v25) = v8;
        v26 = 0;
        v23 = 0x10000800ALL;
        v24 = v9;
        LODWORD(v25) = 0;
        if ( (unsigned int)battery_chg_write((__int64)v2, (__int64)&v23, 0x18u, 0x3E8u) )
          break;
      }
      if ( ++v8 == 32 )
      {
        for ( i = 0; ; ++i )
        {
          if ( ((*(_DWORD *)(a1 + 416) >> i) & 1) != 0 )
          {
            v11 = *v1;
            HIDWORD(v25) = i;
            v26 = 0;
            v23 = 0x10000800ALL;
            v24 = v11;
            LODWORD(v25) = 0;
            v12 = battery_chg_write((__int64)v2, (__int64)&v23, 0x18u, 0x3E8u);
            if ( i > 0x1E || v12 )
              goto LABEL_13;
          }
          else if ( i > 0x1E )
          {
            goto LABEL_13;
          }
        }
      }
    }
  }
LABEL_13:
  v13 = *(unsigned int **)(a1 - 312);
  v14 = v13[13];
  v15 = *v13;
  result = printk(&unk_FB0D, "battery_chg_update_prop_work", *v13);
  if ( v14 == 7 && v15 && battery_chg_update_prop_work_last_oem_charger_type != 7 )
  {
    v18 = *(_DWORD *)(a1 + 304);
    if ( v18 <= 0 )
      v18 = (*(_DWORD *)(*(_QWORD *)(a1 - 360) + 16LL) + 50) / 0x64u;
    if ( v18 != *(_DWORD *)(a1 + 32) / 100 )
    {
      LOBYTE(v23) = 0;
      get_random_bytes(&v23, 1);
      v19 = (unsigned int)(v23 & 0xF) + 100 * v18;
      *(_DWORD *)(a1 + 32) = v19;
      if ( (int)v19 >= 10001 )
      {
        printk(&unk_10290, "battery_chg_update_prop_work", v19);
        v19 = 10000;
        *(_DWORD *)(a1 + 32) = 10000;
      }
      printk(&unk_11190, "battery_chg_update_prop_work", v19);
    }
    printk(&unk_10CFD, "battery_chg_update_prop_work", v17);
    v20 = ktime_get_with_offset(1);
    v21 = ns_to_timespec64(v20);
    v22 = *v2;
    *(_QWORD *)(a1 + 40) = v21;
    pm_wakeup_dev_event(v22, 1100, 1);
    cancel_delayed_work(a1 - 104);
    result = queue_delayed_work_on(32, system_wq, a1 - 104, 250);
    *(_BYTE *)(a1 + 48) = 0;
  }
  battery_chg_update_prop_work_last_oem_charger_type = v14;
  _ReadStatusReg(SP_EL0);
  return result;
}
