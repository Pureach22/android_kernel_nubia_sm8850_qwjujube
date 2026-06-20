__int64 __fastcall cnss_debugfs_create(__int64 a1)
{
  unsigned __int64 dir; // x19
  unsigned __int64 StatusReg; // x8
  const char *v4; // x1
  __int16 v5; // w9
  const char *v6; // x8
  char s[16]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 15);
  if ( (cnss_is_dual_wlan_enabled() & 1) != 0 )
    snprintf(s, 0xFu, "cnss_%d", *(_DWORD *)(a1 + 7800));
  else
    strcpy(s, "cnss");
  dir = debugfs_create_dir(s, 0);
  if ( dir < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(a1 + 6256) = dir;
    debugfs_create_file("pin_connect_result", 420, dir, a1, &cnss_pin_connect_fops);
    debugfs_create_file("stats", 420, dir, a1, &cnss_stats_fops);
    LODWORD(dir) = 0;
  }
  else
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v4 = "irq";
    }
    else
    {
      v5 = *(_DWORD *)(StatusReg + 16);
      v6 = (const char *)(StatusReg + 2320);
      if ( (v5 & 0xFF00) != 0 )
        v4 = "soft_irq";
      else
        v4 = v6;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v4,
      "cnss_debugfs_create",
      3,
      3,
      "Unable to create debugfs %d\n",
      dir);
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)dir;
}
