__int64 __fastcall ship_mode_en_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w20
  _QWORD v8[3]; // [xsp+8h] [xbp-18h] BYREF

  v8[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)kstrtobool(a3, a1 + 1037) )
  {
    a4 = -22;
  }
  else if ( *(_BYTE *)(a1 + 1037) == 1 && *(_BYTE *)(a1 + 1068) == 1 )
  {
    v8[0] = 0x10000800ALL;
    v8[1] = 54;
    v6 = battery_chg_write(a1 - 8, (__int64)v8, 0x10u, 0x3E8u);
    if ( v6 < 0 )
      printk(&unk_10A9A, "battery_chg_ship_mode", (unsigned int)v6);
    if ( v6 < 0 )
      a4 = v6;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
