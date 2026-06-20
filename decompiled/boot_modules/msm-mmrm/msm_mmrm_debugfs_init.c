unsigned __int64 msm_mmrm_debugfs_init()
{
  unsigned __int64 dir; // x0
  unsigned __int64 v1; // x19
  void *v2; // x0
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  dir = debugfs_create_dir("msm_mmrm", 0);
  if ( !dir || (v1 = dir, dir >= 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      goto LABEL_8;
    v2 = &unk_E074;
LABEL_13:
    printk(v2, "err ", "msm_mmrm_debugfs_init");
    goto LABEL_8;
  }
  if ( debugfs_create_file("info", 292, dir, &v4, &msm_mmrm_debugfs_info_fops) )
  {
    debugfs_create_u32("debug_level", 420, v1, &msm_mmrm_debug);
    debugfs_create_u8("allow_multiple_register", 420, v1, &msm_mmrm_allow_multiple_register);
    debugfs_create_u8("enable_throttle_feature", 420, v1, &msm_mmrm_enable_throttle_feature);
    goto LABEL_11;
  }
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
  {
    v2 = &unk_E0B1;
    goto LABEL_13;
  }
LABEL_8:
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
    printk(&unk_D39D, "err ", "msm_mmrm_debugfs_init");
  v1 = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v1;
}
