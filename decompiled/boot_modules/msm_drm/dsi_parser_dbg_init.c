__int64 __fastcall dsi_parser_dbg_init(__int64 a1, __int64 a2)
{
  unsigned __int64 dir; // x0
  unsigned __int64 v4; // x19
  unsigned __int64 file; // x0
  unsigned int v6; // w21
  unsigned __int64 v7; // x0

  if ( a1 && a2 )
  {
    dir = debugfs_create_dir("parser", a2);
    v4 = dir;
    if ( dir && dir < 0xFFFFFFFFFFFFF001LL )
    {
      file = debugfs_create_file("init", 420, dir, a1, &dsi_parser_init_fops);
      v6 = file;
      if ( file
        && file <= 0xFFFFFFFFFFFFF000LL
        && (v7 = debugfs_create_file("node", 420, v4, a1, &dsi_parser_node_fops), v6 = v7, v7)
        && v7 <= 0xFFFFFFFFFFFFF000LL )
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: success\n");
        return 0;
      }
      else
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to create init debugfs\n");
        debugfs_remove(v4);
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to create parser debugfs\n");
      return (unsigned int)v4;
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid input\n");
    return 0;
  }
  return v6;
}
