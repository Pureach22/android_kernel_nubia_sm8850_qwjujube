__int64 __fastcall battery_chg_reboot_notify(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v5; // w0
  unsigned int v6; // w0
  _QWORD v8[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v9[3]; // [xsp+18h] [xbp-18h] BYREF

  v2 = a1 - 1096;
  v9[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0x20000800ALL;
  v8[1] = 71;
  v5 = battery_chg_write(a1 - 1096, (__int64)v8, 0x10u, 0x3E8u);
  if ( (v5 & 0x80000000) != 0 )
    printk(&unk_10938, "battery_chg_reboot_notify", v5);
  msleep(100);
  if ( a2 == 3 && (*(_BYTE *)(a1 - 51) & 1) != 0 && (*(_BYTE *)(a1 - 20) & 1) == 0 )
  {
    v9[0] = 0x10000800ALL;
    v9[1] = 54;
    v6 = battery_chg_write(v2, (__int64)v9, 0x10u, 0x3E8u);
    if ( (v6 & 0x80000000) != 0 )
      printk(&unk_10A9A, "battery_chg_ship_mode", v6);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
