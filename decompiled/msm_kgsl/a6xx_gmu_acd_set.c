__int64 __fastcall a6xx_gmu_acd_set(__int64 a1, char a2)
{
  unsigned int v2; // w8
  unsigned __int64 v3; // x9
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = -22;
  v3 = *(_QWORD *)(a1 - 384);
  v5[0] = a2;
  if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( *(_BYTE *)(a1 + 20433) == (a2 & 1) )
      v2 = 0;
    else
      v2 = adreno_power_cycle(a1, (void (__fastcall *)(__int64, __int64))set_acd, (__int64)v5);
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
