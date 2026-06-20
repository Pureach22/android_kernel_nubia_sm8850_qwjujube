__int64 __fastcall skin_temp_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w8
  unsigned int v8; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v9; // [xsp+10h] [xbp-20h] BYREF
  int v10; // [xsp+18h] [xbp-18h]
  __int64 v11; // [xsp+1Ch] [xbp-14h]
  unsigned int v12; // [xsp+24h] [xbp-Ch]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  if ( (unsigned int)kstrtouint(a3, 10, &v8) )
  {
    a4 = -22;
  }
  else
  {
    printk(&unk_110CC, "skin_temp_store", v8);
    v11 = 0x2B00000000LL;
    v7 = *(_DWORD *)(a1 + 384);
    v9 = 0x10000800ALL;
    v12 = v8;
    v10 = v7;
    battery_chg_write(a1 - 8, (__int64)&v9, 0x18u, 0x3E8u);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
