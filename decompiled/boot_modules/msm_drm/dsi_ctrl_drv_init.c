__int64 __fastcall dsi_ctrl_drv_init(_QWORD *a1, __int64 a2)
{
  const char *v4; // x3
  unsigned __int64 dir; // x0
  unsigned __int64 v6; // x20
  unsigned __int64 file; // x0
  unsigned int v8; // w21
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x0
  __int64 v11; // x20
  __int64 v12; // x22
  __int64 phys_addr; // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v16; // [xsp+10h] [xbp-20h]
  __int64 v17; // [xsp+18h] [xbp-18h]
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  *(_QWORD *)s = 0;
  v16 = 0;
  if ( a1 )
  {
    mutex_lock(a1 + 4);
    v4 = (const char *)a1[2];
    *((_DWORD *)a1 + 405) = 0;
    *(_QWORD *)((char *)a1 + 1612) = 0;
    if ( a2 )
    {
      dir = debugfs_create_dir(v4, a2);
      v6 = dir;
      if ( dir && dir < 0xFFFFFFFFFFFFF001LL )
      {
        file = debugfs_create_file("state_info", 292, dir, a1, &state_info_fops);
        v8 = file;
        if ( file && file < 0xFFFFFFFFFFFFF001LL )
        {
          v9 = debugfs_create_file("reg_dump", 292, v6, a1, &reg_dump_fops);
          v8 = v9;
          if ( v9 && v9 < 0xFFFFFFFFFFFFF001LL )
          {
            debugfs_create_bool("enable_cmd_dma_stats", 384, v6, a1 + 362);
            v10 = debugfs_create_file("cmd_dma_stats", 292, v6, a1, &cmd_dma_stats_fops);
            v8 = v10;
            if ( v10 && v10 < 0xFFFFFFFFFFFFF001LL )
            {
              a1[357] = v6;
LABEL_20:
              snprintf(s, 0x20u, "dsi%d_ctrl", *((_DWORD *)a1 + 2));
              v11 = a1[12];
              v12 = msm_iomap_size(*a1, "dsi_ctrl");
              phys_addr = msm_get_phys_addr(*a1, "dsi_ctrl");
              sde_dbg_reg_register_base(s, v11, v12, phys_addr, 32);
              v8 = 0;
              goto LABEL_21;
            }
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: %s: Line count file failed, rc=%d\n",
              a1[2],
              (unsigned int)v10);
          }
          else
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: %s: reg dump file failed, rc=%d\n",
              a1[2],
              (unsigned int)v9);
          }
        }
        else
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: %s: state file failed, rc=%d\n",
            (const char *)a1[2],
            file);
        }
        debugfs_remove(v6);
        if ( !v8 )
          goto LABEL_20;
      }
      else
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: debugfs create dir failed, rc=%d\n",
          (const char *)a1[2],
          dir);
        v8 = v6;
        if ( !(_DWORD)v6 )
          goto LABEL_20;
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", v4);
      v8 = -22;
    }
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to init debug fs, rc=%d\n",
      (const char *)a1[2],
      v8);
LABEL_21:
    mutex_unlock(a1 + 4);
    goto LABEL_22;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
  v8 = -22;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v8;
}
