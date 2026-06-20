__int64 __fastcall sde_dbg_debugfs_register(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  unsigned __int64 dir; // x0
  unsigned __int64 v4; // x19
  __int64 i; // x20
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v8; // [xsp+10h] [xbp-50h]
  __int64 v9; // [xsp+18h] [xbp-48h]
  __int64 v10; // [xsp+20h] [xbp-40h]
  __int64 v11; // [xsp+28h] [xbp-38h]
  __int64 v12; // [xsp+30h] [xbp-30h]
  __int64 v13; // [xsp+38h] [xbp-28h]
  __int64 v14; // [xsp+40h] [xbp-20h]
  __int64 v15; // [xsp+48h] [xbp-18h]
  __int64 v16; // [xsp+50h] [xbp-10h]
  __int64 v17; // [xsp+58h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  *(_QWORD *)s = 0;
  v8 = 0;
  if ( v1 && (v2 = *(_QWORD *)(v1 + 56)) != 0 )
  {
    dir = debugfs_create_dir("debug", *(_QWORD *)(*(_QWORD *)(v1 + 64) + 32LL));
    v4 = dir;
    if ( dir && dir < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(v2 + 5688) = dir;
      debugfs_create_file("dbg_ctrl", 384, dir, 0, &sde_dbg_ctrl_fops);
      debugfs_create_file("dump", 384, v4, 0, &sde_evtlog_fops);
      debugfs_create_file("recovery_reg", 256, v4, 0, &sde_recovery_reg_fops);
      debugfs_create_u32("enable", 384, v4, sde_dbg_base + 786452);
      debugfs_create_u32("reglog_enable", 384, v4, qword_2942A0 + 24612);
      debugfs_create_u32("panic", 384, v4, &dword_294350);
      debugfs_create_u32("dump_mode", 384, v4, &dword_29437C);
      debugfs_create_u64("reg_dump_blk_mask", 384, v4, &qword_294598);
      debugfs_create_u32("evtlog_dump", 384, v4, sde_dbg_base + 786456);
      debugfs_create_file("wakelock", 384, v4, v2 + 16, &sde_dbg_debugfs_register_sde_power_wakelock_debugfs_fops);
      for ( i = qword_2942A8; (__int64 *)i != &qword_2942A8; i = *(_QWORD *)i )
      {
        snprintf(s, 0x50u, "%s_off", (const char *)(i + 32));
        debugfs_create_file(s, 384, v4, i, &sde_off_fops);
        snprintf(s, 0x50u, "%s_reg", (const char *)(i + 32));
        debugfs_create_file(s, 256, v4, i, &sde_reg_fops);
      }
      result = 0;
    }
    else
    {
      printk(&unk_27782A, "sde_dbg_debugfs_register");
      *(_QWORD *)(v2 + 5688) = 0;
      result = 4294967274LL;
    }
  }
  else
  {
    printk(&unk_277803, "sde_dbg_debugfs_register");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
