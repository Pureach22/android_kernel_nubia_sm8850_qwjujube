__int64 __fastcall adsp_debug_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w10
  unsigned int v7; // w0
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  int v10; // [xsp+10h] [xbp-10h]
  int v11; // [xsp+14h] [xbp-Ch]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)kstrtouint(a3, 10, a1 + 1060) )
  {
    a4 = -22;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 1060);
    v9 = 0x10000800ALL;
    v10 = 256;
    v11 = v6;
    v7 = battery_chg_write(a1 - 8, (__int64)&v9, 0x10u, 0x3E8u);
    if ( (v7 & 0x80000000) != 0 )
      printk(&unk_11A0A, "battery_chg_set_adsp_debug", v7);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
