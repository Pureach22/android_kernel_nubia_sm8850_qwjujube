__int64 __fastcall cam_smmu_fw_dev_component_bind(__int64 a1)
{
  unsigned int v2; // w20
  __int64 result; // x0
  __int64 v4; // x0
  int v5; // w9
  __int64 v6; // x11
  __int64 v7; // x12
  _QWORD v8[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v9[3]; // [xsp+18h] [xbp-18h] BYREF

  v9[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v9[1] = 0;
  v8[0] = 0;
  v8[1] = 0;
  ktime_get_real_ts64(v9);
  v2 = of_count_phandle_with_args(*(_QWORD *)(a1 + 744), "memory-region", 0);
  if ( v2 < 3 )
  {
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_fw_dev_component_bind",
        5634,
        "Number of ICP fw memory region: %d",
        v2);
    if ( mem_trace_en == 1 )
      v4 = cam_mem_trace_alloc(32 * v2, 0xCC0u, 0, "cam_smmu_fw_dev_component_bind", 0x1603u);
    else
      v4 = _kvmalloc_node_noprof(32 * v2, 0, 3520, 0xFFFFFFFFLL);
    icp_fw = v4;
    if ( v4 )
    {
      if ( v2 )
      {
        v5 = 0;
        v6 = 0;
        do
        {
          *(_QWORD *)(icp_fw + v6) = a1;
          v7 = icp_fw + v6;
          v6 += 32;
          *(_DWORD *)(v7 + 16) = v5++;
        }
        while ( 32LL * v2 != v6 );
      }
      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_fw_dev_component_bind",
          5646,
          "Binding component: %s",
          *(const char **)(a1 - 16));
      ktime_get_real_ts64(v8);
      cam_record_bind_latency();
      result = 0;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_fw_dev_component_bind",
        5637,
        "Failed at allocating space for icp fw");
      result = 4294967284LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_fw_dev_component_bind",
      5630,
      "Failed at parsing number of memory region: %d, expected maximum memory region: %d",
      v2,
      2);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
