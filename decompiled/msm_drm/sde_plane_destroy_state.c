__int64 __fastcall sde_plane_destroy_state(__int64 a1, __int64 a2)
{
  __int64 v4; // x8

  if ( !a1 || !a2 )
    return printk(&unk_21644D, "sde_plane_destroy_state");
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "plane%d \n", *(_DWORD *)(a1 + 104));
  v4 = *(_QWORD *)(a2 + 16);
  if ( v4 )
    drm_mode_object_put(v4 + 24);
  if ( *(_QWORD *)(a2 + 1752) )
    sde_sync_put();
  *(_QWORD *)(a2 + 1752) = 0;
  return ((__int64 (__fastcall *)(__int64, __int64, __int64))msm_property_destroy_state)(a1 + 3344, a2, a2 + 176);
}
