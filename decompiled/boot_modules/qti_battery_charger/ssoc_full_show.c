__int64 __fastcall ssoc_full_show(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w9
  __int64 result; // x0
  __int64 v7; // [xsp+0h] [xbp-20h] BYREF
  int v8; // [xsp+8h] [xbp-18h]
  __int64 v9; // [xsp+Ch] [xbp-14h]
  int v10; // [xsp+14h] [xbp-Ch]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0x2300000000LL;
  v5 = *(_DWORD *)(a1 + 380);
  v10 = 0;
  v7 = 0x10000800ALL;
  v8 = v5;
  battery_chg_write(a1 - 8, (__int64)&v7, 0x18u, 0x3E8u);
  printk(&unk_10C0F, "ssoc_full_show", *(unsigned int *)(a1 + 1148));
  LODWORD(result) = scnprintf(a3, 4096, "%d\n", *(_DWORD *)(a1 + 1148));
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
