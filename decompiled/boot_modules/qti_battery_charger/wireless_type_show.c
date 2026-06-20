__int64 __fastcall wireless_type_show(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w9
  __int64 result; // x0
  __int64 v7; // x8
  const char *v8; // x3
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+8h] [xbp-18h]
  __int64 v11; // [xsp+Ch] [xbp-14h]
  int v12; // [xsp+14h] [xbp-Ch]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0x900000000LL;
  v5 = *(_DWORD *)(a1 + 476);
  v12 = 0;
  v9 = 0x10000800ALL;
  v10 = v5;
  LODWORD(result) = battery_chg_write(a1 - 8, (__int64)&v9, 0x18u, 0x3E8u);
  if ( (result & 0x80000000) == 0 )
  {
    v7 = *(unsigned int *)(*(_QWORD *)(a1 + 464) + 36LL);
    if ( (unsigned int)v7 <= 3 )
      v8 = (&qc_power_supply_wls_type_text)[v7];
    else
      v8 = "Unknown";
    LODWORD(result) = scnprintf(a3, 4096, "%s\n", v8);
  }
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
