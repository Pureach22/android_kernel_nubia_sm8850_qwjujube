__int64 __fastcall wireless_fw_version_show(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v5; // w0
  unsigned int v6; // w20
  __int64 v8; // [xsp+Ch] [xbp-14h] BYREF
  int v9; // [xsp+14h] [xbp-Ch]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0x10000800ALL;
  v9 = 68;
  v5 = battery_chg_write(a1 - 8, (__int64)&v8, 0xCu, 0x5DCu);
  if ( (v5 & 0x80000000) != 0 )
  {
    v6 = v5;
    printk(&unk_119D7, "wireless_fw_version_show", v5);
  }
  else
  {
    v6 = scnprintf(a3, 4096, "%#x\n", *(_DWORD *)(a1 + 1072));
  }
  _ReadStatusReg(SP_EL0);
  return (int)v6;
}
