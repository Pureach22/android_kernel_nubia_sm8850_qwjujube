__int64 __fastcall charge_control_en_show(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w9
  unsigned int v6; // w0
  unsigned int v7; // w21
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+8h] [xbp-18h]
  __int64 v11; // [xsp+Ch] [xbp-14h]
  int v12; // [xsp+14h] [xbp-Ch]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0x1800000000LL;
  v5 = *(_DWORD *)(a1 + 380);
  v12 = 0;
  v9 = 0x10000800ALL;
  v10 = v5;
  v6 = battery_chg_write(a1 - 8, (__int64)&v9, 0x18u, 0x3E8u);
  if ( (v6 & 0x80000000) != 0 )
  {
    v7 = v6;
    printk(&unk_11154, "get_charge_control_en", v6);
  }
  else
  {
    *(_BYTE *)(a1 + 1135) = *(_DWORD *)(*(_QWORD *)(a1 + 368) + 96LL) != 0;
    v7 = scnprintf(a3, 4096, "%d\n");
  }
  _ReadStatusReg(SP_EL0);
  return (int)v7;
}
