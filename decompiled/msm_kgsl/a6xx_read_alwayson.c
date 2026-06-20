unsigned __int64 __fastcall a6xx_read_alwayson(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v4; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v5; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v6; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v4 = 0;
  v5 = 0;
  if ( (gmu_core_isenabled(a1) & 1) != 0 )
  {
    gmu_core_regread(a1, 129161, &v5);
    gmu_core_regread(a1, 129160, &v6);
    gmu_core_regread(a1, 129161, &v4);
    v2 = v5;
    if ( v5 != v4 )
    {
      gmu_core_regread(a1, 129160, &v6);
      v2 = v4;
    }
  }
  else
  {
    v6 = kgsl_regmap_read(a1 + 13200);
    v2 = kgsl_regmap_read(a1 + 13200);
  }
  _ReadStatusReg(SP_EL0);
  return v6 | (unsigned __int64)(v2 << 32);
}
