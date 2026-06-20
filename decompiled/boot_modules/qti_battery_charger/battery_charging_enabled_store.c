__int64 __fastcall battery_charging_enabled_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w10
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  int v9; // [xsp+8h] [xbp-18h]
  __int64 v10; // [xsp+Ch] [xbp-14h]
  int v11; // [xsp+14h] [xbp-Ch]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)kstrtobool(a3, a1 + 1039) )
  {
    a4 = -22;
  }
  else
  {
    v7 = *(_DWORD *)(a1 + 384);
    if ( (*(_BYTE *)(a1 + 1039) & 1) != 0 )
    {
      v10 = 0x1F00000000LL;
      v11 = -1;
    }
    else
    {
      v11 = 0;
      v10 = 0x1F00000000LL;
    }
    v8 = 0x10000800ALL;
    v9 = v7;
    battery_chg_write(a1 - 8, (__int64)&v8, 0x18u, 0x3E8u);
    printk(&unk_107CD, "battery_charging_enabled_store", 31);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
