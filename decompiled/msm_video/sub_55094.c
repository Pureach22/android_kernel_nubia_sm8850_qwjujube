__int64 __fastcall sub_55094(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return msm_vidc_ts_reorder_get_first_timestamp(a1, a2, a3, a4, a5, a6, _ReadStatusReg(ARM64_SYSREG(3, 4, 7, 11, 3)));
}
