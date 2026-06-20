__int64 __fastcall a6xx_hw_isidle(__int64 a1)
{
  bool v2; // zf
  __int64 result; // x0
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  if ( (gmu_core_isenabled(a1) & 1) != 0 )
  {
    gmu_core_regread(a1, 146188, &v4);
    v2 = (v4 & 0x800000) == 0;
  }
  else
  {
    if ( (unsigned int)kgsl_regmap_read(a1 + 13200) > 1
      || (*(_DWORD *)(a1 + 20888) & (unsigned int)kgsl_regmap_read(a1 + 13200)) != 0 )
    {
      result = 0;
      goto LABEL_9;
    }
    v2 = *(_DWORD *)(a1 + 20416) == 0;
  }
  result = v2;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
