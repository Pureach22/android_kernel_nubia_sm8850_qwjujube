__int64 __fastcall sde_plane_late_register(__int64 *a1)
{
  __int64 v1; // x8
  __int64 v3; // x9
  __int64 v4; // x20
  __int64 v5; // x9
  __int64 v6; // x22
  __int64 v7; // x21
  __int64 dir; // x0
  __int64 v9; // x8
  void *v11; // x0

  if ( !a1 || (v1 = *a1) == 0 )
  {
    v11 = &unk_26FEB0;
LABEL_17:
    printk(v11, "_sde_plane_init_debugfs");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(v1 + 56);
  if ( !v3 || (v4 = *(_QWORD *)(v3 + 8)) == 0 )
  {
    v11 = &unk_25EA03;
    goto LABEL_17;
  }
  v5 = a1[276];
  if ( !v5 )
    return 0;
  v6 = *(_QWORD *)(v5 + 56);
  if ( !v6 )
    return 0;
  v7 = *(_QWORD *)(v6 + 48);
  if ( !v7 )
    return 0;
  dir = debugfs_create_dir(a1 + 416, *(_QWORD *)(*(_QWORD *)(v1 + 64) + 32LL));
  a1[532] = dir;
  if ( dir )
  {
    debugfs_create_x64("features", 256, dir, a1 + 242);
    v9 = *(_QWORD *)(v6 + 32);
    if ( (v9 & 0x40000C) != 0 )
    {
      debugfs_create_bool("default_scaling", 384, a1[532], a1 + 533);
      v9 = *(_QWORD *)(v6 + 32);
    }
    if ( (v9 & 0x800000) != 0 )
    {
      debugfs_create_u32("in_rot_max_downscale_rt_num", 384, a1[532], a1[415] + 1256);
      debugfs_create_u32("in_rot_max_downscale_rt_denom", 384, a1[532], a1[415] + 1260);
      debugfs_create_u32("in_rot_max_downscale_nrt", 384, a1[532], a1[415] + 1264);
      debugfs_create_u32("in_rot_max_height", 384, a1[532], a1[415] + 1276);
    }
    debugfs_create_u32("xin_id", 256, a1[532], v6 + 56);
    debugfs_create_x32("creq_vblank", 384, a1[532], v7 + 8);
    debugfs_create_x32("danger_vblank", 384, a1[532], v7 + 12);
    debugfs_create_file("disable_danger", 384, a1[532], v4, &sde_plane_danger_enable);
    return 0;
  }
  return 4294967284LL;
}
