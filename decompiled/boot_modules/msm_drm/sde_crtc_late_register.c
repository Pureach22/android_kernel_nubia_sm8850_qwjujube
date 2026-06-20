__int64 __fastcall sde_crtc_late_register(__int64 *a1)
{
  __int64 v1; // x8
  __int64 v3; // x9
  __int64 v4; // x20
  __int64 dir; // x0
  void *v7; // x0

  if ( !a1 )
    return 4294967274LL;
  v1 = *a1;
  if ( !*a1 || (v3 = *(_QWORD *)(v1 + 56)) == 0 )
  {
    v7 = &unk_25E167;
LABEL_13:
    printk(v7, "_sde_crtc_get_kms");
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(v3 + 8);
  if ( !v4 )
  {
    v7 = &unk_234896;
    goto LABEL_13;
  }
  dir = debugfs_create_dir(a1 + 272, *(_QWORD *)(*(_QWORD *)(v1 + 64) + 32LL));
  a1[549] = dir;
  if ( !dir )
    return 4294967284LL;
  debugfs_create_file("status", 256, dir, a1, &sde_crtc_init_debugfs_debugfs_status_fops);
  debugfs_create_file("state", 256, a1[549], a1, &sde_crtc_debugfs_state_fops);
  debugfs_create_file("misr_data", 384, a1[549], a1, &sde_crtc_init_debugfs_debugfs_misr_fops);
  debugfs_create_file("fps", 256, a1[549], a1, &sde_crtc_init_debugfs_debugfs_fps_fops);
  debugfs_create_file("fence_status", 256, a1[549], a1, &sde_crtc_init_debugfs_debugfs_fence_fops);
  if ( *(_DWORD *)(*(_QWORD *)(v4 + 152) + 52LL) )
  {
    debugfs_create_file(
      "hwfence_features_mask",
      384,
      a1[549],
      a1,
      &sde_crtc_init_debugfs_debugfs_hw_fence_features_fops);
    debugfs_create_u32("hwfence_out_fences_skip", 384, a1[549], a1 + 992);
  }
  return 0;
}
