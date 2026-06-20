__int64 __fastcall read_property_id(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  __int64 v4; // [xsp+0h] [xbp-20h] BYREF
  int v5; // [xsp+8h] [xbp-18h]
  int v6; // [xsp+Ch] [xbp-14h]
  int v7; // [xsp+10h] [xbp-10h]
  int v8; // [xsp+14h] [xbp-Ch]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a3;
  v8 = 0;
  v4 = 0x10000800ALL;
  v5 = *(_DWORD *)(a2 + 36);
  v6 = 0;
  result = battery_chg_write(a1, &v4, 24, 1000);
  _ReadStatusReg(SP_EL0);
  return result;
}
