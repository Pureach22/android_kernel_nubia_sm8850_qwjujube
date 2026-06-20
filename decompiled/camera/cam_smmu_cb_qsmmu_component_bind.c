__int64 __fastcall cam_smmu_cb_qsmmu_component_bind(__int64 a1)
{
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v4[3]; // [xsp+18h] [xbp-18h] BYREF

  v4[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  v4[1] = 0;
  v3[0] = 0;
  v3[1] = 0;
  ktime_get_real_ts64(v4);
  if ( (cam_populate_smmu_context_banks(a1, 1) & 0x80000000) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_cb_qsmmu_component_bind",
      5716,
      "Failed in populating context banks");
    result = 4294967284LL;
  }
  else
  {
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_cb_qsmmu_component_bind",
        5720,
        "QSMMU CB component bound successfully");
    ktime_get_real_ts64(v3);
    cam_record_bind_latency();
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
