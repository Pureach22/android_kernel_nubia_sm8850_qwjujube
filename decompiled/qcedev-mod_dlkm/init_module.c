__int64 init_module()
{
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v2; // [xsp+10h] [xbp-10h]
  __int64 v3; // [xsp+18h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)s = 0;
  v2 = 0;
  debug_dent = debugfs_create_dir("qcedev", 0);
  if ( (unsigned __int64)debug_dent <= 0xFFFFFFFFFFFFF000LL )
  {
    snprintf(s, 0xFu, "stats-%d", 1);
    debug_qcedev = 0;
    if ( !debugfs_create_file(s, 420, debug_dent) )
      debugfs_remove(debug_dent);
  }
  result = _platform_driver_register(qcedev_plat_driver, &_this_module);
  _ReadStatusReg(SP_EL0);
  return result;
}
