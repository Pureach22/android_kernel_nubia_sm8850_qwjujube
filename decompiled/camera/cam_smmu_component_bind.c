__int64 __fastcall cam_smmu_component_bind(__int64 a1)
{
  bool v2; // w9
  __int64 v3; // x0
  bool v4; // w9
  __int64 v5; // x0
  unsigned int csf_version; // w20
  _QWORD v8[2]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v9[2]; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int64 v10[2]; // [xsp+20h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v9[1] = 0;
  v8[0] = 0;
  v8[1] = 0;
  ktime_get_real_ts64(v9);
  qword_394068 = 0xFFFFFFFE00000LL;
  qword_394070 = (__int64)&qword_394070;
  qword_394078 = (__int64)&qword_394070;
  qword_394080 = (__int64)cam_smmu_page_fault_work;
  _mutex_init(&unk_394088, "&iommu_cb_set.payload_list_lock", &cam_smmu_component_bind___key_231);
  dword_3940F4 = 0;
  qword_3940B8 = (__int64)&qword_3940B8;
  qword_3940C0 = (__int64)&qword_3940B8;
  v10[0] = 0;
  if ( (unsigned int)cam_debugfs_create_subdir("smmu", v10) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_create_debug_fs",
      5555,
      "DebugFS could not create directory!");
  }
  else
  {
    qword_3940C8 = v10[0];
    debugfs_create_bool("cb_dump_enable", 420);
    debugfs_create_bool("map_profile_enable", 420);
    debugfs_create_file("fatal_pf_mask", 420, qword_3940C8, 0, &cam_smmu_fatal_pf_mask);
    debugfs_create_bool("disable_buf_tracking", 420);
  }
  v2 = of_find_property(*(_QWORD *)(a1 + 744), "force_cache_allocs", 0) != 0;
  v3 = *(_QWORD *)(a1 + 744);
  byte_3940F8 = v2;
  v4 = of_find_property(v3, "need_shared_buffer_padding", 0) != 0;
  v5 = *(_QWORD *)(a1 + 744);
  byte_3940F9 = v4;
  byte_3940FA = of_find_property(v5, "expanded_memory", 0) != 0;
  cam_common_register_mini_dump_cb((__int64)cam_smmu_mini_dump_cb, "cam_smmu", 0);
  csf_version = cam_smmu_fetch_csf_version(&qword_3940E8);
  if ( csf_version )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_component_bind",
      5767,
      "Failed to fetch CSF version: %d",
      csf_version);
  }
  else
  {
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_component_bind",
        5774,
        "Main component bound successfully");
    ktime_get_real_ts64(v8);
    cam_record_bind_latency();
  }
  _ReadStatusReg(SP_EL0);
  return csf_version;
}
