__int64 __fastcall sub_61B8(long double a1, long double a2, long double a3, long double a4, long double a5)
{
  const __int16 *v5; // x13
  int16x4x2_t v7; // 0:kr00_16.16

  v7 = vld2_dup_s16(v5);
  *(_QWORD *)&a4 = v7.val[0].n64_u64[0];
  *(_QWORD *)&a5 = v7.val[1].n64_u64[0];
  return qcom_mpam_config_monitor(a1, a2, a3, a4, a5);
}
