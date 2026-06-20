__int64 __fastcall battery_chg_get_oem_charger_type(__int64 a1, __int64 a2)
{
  int v4; // w9
  __int64 result; // x0
  __int64 v6; // [xsp+0h] [xbp-20h] BYREF
  int v7; // [xsp+8h] [xbp-18h]
  __int64 v8; // [xsp+Ch] [xbp-14h]
  int v9; // [xsp+14h] [xbp-Ch]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0xD00000000LL;
  v4 = *(_DWORD *)(a2 + 436);
  v9 = 0;
  v6 = 0x10000800ALL;
  v7 = v4;
  result = battery_chg_write(a2, &v6, 24, 1000);
  if ( (result & 0x80000000) == 0 )
    result = scnprintf(a1, 4096, "%d\n", *(_DWORD *)(*(_QWORD *)(a2 + 424) + 52LL));
  _ReadStatusReg(SP_EL0);
  return result;
}
