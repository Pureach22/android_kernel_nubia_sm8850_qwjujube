__int64 __fastcall sub_18ACEC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int64 *v6; // x13
  unsigned __int64 v7; // kr00_8

  v7 = __ldaxp(v6);
  LODWORD(a6) = HIDWORD(v7);
  LODWORD(a5) = v7;
  return sde_hw_sspp_setup_scaler_cac(a1, a2, a3, a4, a5, a6);
}
