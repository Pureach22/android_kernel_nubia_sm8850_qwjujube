__int64 __fastcall dp_ipa_set_perf_level(int a1, int a2, unsigned int a3)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _DWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = a1;
  v12[1] = a2;
  result = ipa_wdi_set_perf_profile_per_inst(a3, v12);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: ipa_wdi_set_perf_profile fail, code %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_ipa_set_perf_level",
      (unsigned int)result);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
