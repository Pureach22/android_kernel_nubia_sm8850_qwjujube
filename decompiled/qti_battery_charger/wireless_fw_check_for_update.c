__int64 __fastcall wireless_fw_check_for_update(__int64 a1, int a2, int a3)
{
  int v3; // w8
  __int64 result; // x0
  __int64 v5; // [xsp+0h] [xbp-20h] BYREF
  int v6; // [xsp+8h] [xbp-18h]
  int v7; // [xsp+Ch] [xbp-14h]
  int v8; // [xsp+10h] [xbp-10h]
  int v9; // [xsp+14h] [xbp-Ch]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 64;
  v7 = a2;
  v5 = 0x10000800ALL;
  v3 = *(unsigned __int16 *)(a1 + 1084);
  *(_BYTE *)(a1 + 1078) = 0;
  v8 = a3;
  v9 = v3;
  result = battery_chg_write(a1, (__int64)&v5, 0x18u, 0x5DCu);
  _ReadStatusReg(SP_EL0);
  return result;
}
