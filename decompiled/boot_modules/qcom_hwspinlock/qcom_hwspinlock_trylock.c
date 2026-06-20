__int64 __fastcall qcom_hwspinlock_trylock(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 16);
  v3 = 0;
  result = regmap_field_update_bits_base(v1, 0xFFFFFFFFLL, 1, 0, 0, 0);
  if ( !(_DWORD)result )
  {
    result = regmap_field_read(v1, &v3);
    if ( !(_DWORD)result )
      result = v3 == 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
