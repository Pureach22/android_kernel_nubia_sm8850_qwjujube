bool __fastcall a619_holi_gx_is_on(__int64 a1)
{
  char v1; // w8
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  gmu_core_regread(a1, 129232, &v3);
  v1 = v3;
  _ReadStatusReg(SP_EL0);
  return (v1 & 0xC0) == 0;
}
