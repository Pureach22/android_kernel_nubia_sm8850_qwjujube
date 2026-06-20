__int64 __fastcall wireless_boost_en_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  int v7; // w8
  _BYTE v8[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v9; // [xsp+10h] [xbp-20h] BYREF
  int v10; // [xsp+18h] [xbp-18h]
  __int64 v11; // [xsp+1Ch] [xbp-14h]
  int v12; // [xsp+24h] [xbp-Ch]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  if ( (unsigned int)kstrtobool(a3, v8) )
  {
    result = -22;
  }
  else
  {
    printk(&unk_1087A, "wireless_boost_en_store", v8[0]);
    v11 = 0x600000000LL;
    v7 = *(_DWORD *)(a1 + 480);
    v9 = 0x10000800ALL;
    v12 = v8[0];
    v10 = v7;
    LODWORD(result) = battery_chg_write(a1 - 8, (__int64)&v9, 0x18u, 0x3E8u);
    if ( (int)result >= 0 )
      result = a4;
    else
      result = (int)result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
