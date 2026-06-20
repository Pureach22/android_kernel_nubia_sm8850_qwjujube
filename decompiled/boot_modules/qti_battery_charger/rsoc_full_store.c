__int64 __fastcall rsoc_full_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w9
  int v8; // w8
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+8h] [xbp-18h]
  __int64 v11; // [xsp+Ch] [xbp-14h]
  int v12; // [xsp+14h] [xbp-Ch]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)kstrtouint(a3, 10, a1 + 1152) )
  {
    a4 = -22;
  }
  else
  {
    printk(&unk_11D05, "rsoc_full_store", *(unsigned int *)(a1 + 1152));
    v7 = *(_DWORD *)(a1 + 1152);
    v11 = 0x2400000000LL;
    v8 = *(_DWORD *)(a1 + 384);
    v9 = 0x10000800ALL;
    v12 = v7;
    v10 = v8;
    battery_chg_write(a1 - 8, (__int64)&v9, 0x18u, 0x3E8u);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
