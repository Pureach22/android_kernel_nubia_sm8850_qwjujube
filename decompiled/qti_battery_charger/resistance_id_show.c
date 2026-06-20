__int64 __fastcall resistance_id_show(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v5; // w0
  __int64 result; // x0
  _QWORD v7[3]; // [xsp+8h] [xbp-18h] BYREF

  v7[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0x10000800ALL;
  v7[1] = 0;
  v5 = battery_chg_write(a1 - 8, (__int64)v7, 0x10u, 0x3E8u);
  if ( (v5 & 0x80000000) != 0 )
    printk(&unk_11A0A, "battery_chg_get_resistance_id", v5);
  LODWORD(result) = scnprintf(a3, 4096, "%d\n", *(_DWORD *)(a1 + 1048));
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
