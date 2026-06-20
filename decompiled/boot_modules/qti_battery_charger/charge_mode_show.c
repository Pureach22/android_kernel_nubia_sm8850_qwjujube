__int64 __fastcall charge_mode_show(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w9
  __int64 result; // x0
  int v7; // w3
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  int v9; // [xsp+8h] [xbp-18h]
  __int64 v10; // [xsp+Ch] [xbp-14h]
  int v11; // [xsp+14h] [xbp-Ch]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0x2500000000LL;
  v5 = *(_DWORD *)(a1 + 380);
  v11 = 0;
  v8 = 0x10000800ALL;
  v9 = v5;
  LODWORD(result) = battery_chg_write(a1 - 8, (__int64)&v8, 0x18u, 0x3E8u);
  if ( (result & 0x80000000) == 0 )
  {
    v7 = *(_DWORD *)(*(_QWORD *)(a1 + 368) + 148LL);
    *(_DWORD *)(a1 + 1056) = v7;
    LODWORD(result) = scnprintf(a3, 4096, "%d\n", v7);
  }
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
