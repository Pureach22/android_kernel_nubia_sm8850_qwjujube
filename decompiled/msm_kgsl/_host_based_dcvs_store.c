__int64 __fastcall host_based_dcvs_store(__int64 a1, unsigned __int64 a2)
{
  __int64 result; // x0
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  result = 0;
  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 <= 1 && *(unsigned __int8 *)(a1 + 14232) != a2 )
  {
    v4[0] = a2;
    result = adreno_power_cycle(a1, (void (__fastcall *)(__int64, __int64))toggle_host_based_dcvs, (__int64)v4);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
