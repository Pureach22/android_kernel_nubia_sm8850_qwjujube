void *__fastcall sde_kms_vm_trusted_resource_deinit(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x20
  __int64 v4; // x20
  __int64 active; // x0
  __int64 v6; // x1

  if ( *(int *)(a1 + 3568) < 1 )
    return memset((void *)(a1 + 2536), 0, 0x150u);
  v2 = **(_QWORD **)(a1 + 3576);
  if ( (*(_BYTE *)(a1 + 2712) & 1) != 0 )
    sde_kms_free_splash_display_data(a1, a1 + 2712);
  dsi_display_set_active_state(v2, 0);
  if ( *(int *)(a1 + 3568) < 2 )
    return memset((void *)(a1 + 2536), 0, 0x150u);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 3576) + 8LL);
  if ( *(_BYTE *)(a1 + 2792) == 1 )
    sde_kms_free_splash_display_data(a1, a1 + 2792);
  dsi_display_set_active_state(v3, 0);
  if ( *(int *)(a1 + 3568) < 3 )
    return memset((void *)(a1 + 2536), 0, 0x150u);
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 3576) + 16LL);
  if ( *(_BYTE *)(a1 + 2872) == 1 )
    sde_kms_free_splash_display_data(a1, a1 + 2872);
  active = dsi_display_set_active_state(v4, 0);
  if ( *(int *)(a1 + 3568) <= 3 )
    return memset((void *)(a1 + 2536), 0, 0x150u);
  __break(0x5512u);
  return (void *)sde_kms_free_splash_display_data(active, v6);
}
