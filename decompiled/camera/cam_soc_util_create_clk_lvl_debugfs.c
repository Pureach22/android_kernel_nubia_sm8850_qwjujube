__int64 __fastcall cam_soc_util_create_clk_lvl_debugfs(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x6
  const char *v4; // x5
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x4
  unsigned __int64 dir; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = result;
  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 3272);
  v9[0] = 0;
  if ( v2 )
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      v3 = *(_QWORD *)(result + 24);
      v4 = "Debugfs entry for %s already exists";
      v5 = debug_mdl & 0x20000;
      v6 = 4;
      v7 = 1830;
LABEL_12:
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                 3,
                 v5,
                 v6,
                 "cam_soc_util_create_clk_lvl_debugfs",
                 v7,
                 v4,
                 v3);
    }
  }
  else if ( (unsigned int)cam_debugfs_lookup_subdir("clk", v9) && (unsigned int)cam_debugfs_create_subdir("clk", v9) )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               0x20000,
               1,
               "cam_soc_util_create_clk_lvl_debugfs",
               1838,
               "DebugFS could not create clk directory!");
  }
  else
  {
    dir = debugfs_create_dir(*(_QWORD *)(v1 + 24), v9[0]);
    *(_QWORD *)(v1 + 3272) = dir;
    if ( !dir || dir >= 0xFFFFFFFFFFFFF001LL )
    {
      v3 = *(_QWORD *)(v1 + 24);
      v4 = "DebugFS could not create directory for dev:%s!";
      v5 = 0x20000;
      v6 = 1;
      v7 = 1847;
      goto LABEL_12;
    }
    debugfs_create_file("clk_lvl_options", 292, dir, v1, &cam_soc_util_clk_lvl_options);
    debugfs_create_file("clk_lvl_control", 420, *(_QWORD *)(v1 + 3272), v1, &cam_soc_util_clk_lvl_control);
    result = debugfs_create_file(
               "clk_lvl_control_low",
               420,
               *(_QWORD *)(v1 + 3272),
               v1,
               &cam_soc_util_clk_lvl_control_low);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
