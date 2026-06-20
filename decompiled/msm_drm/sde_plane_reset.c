__int64 __fastcall sde_plane_reset(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x20
  __int64 *v3; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 *v9; // x0
  __int64 *v10; // x20

  if ( !result )
    return printk(&unk_226FC0, "sde_plane_reset");
  v1 = result;
  if ( (_drm_debug & 4) != 0 )
    result = _drm_dev_dbg(0, 0, 0, "plane%d \n", *(_DWORD *)(result + 104));
  v2 = *(_QWORD **)(v1 + 1768);
  if ( v2 )
  {
    v3 = (__int64 *)v2[1];
    if ( v3 )
    {
      v4 = v3[251];
      if ( v4 )
      {
        v5 = *v3;
        if ( v5 )
        {
          v6 = *(_QWORD *)(v5 + 56);
          if ( v6 )
          {
            v7 = *(_QWORD *)(v6 + 8);
            if ( v7 )
            {
              if ( *(_QWORD *)(v7 + 2128) && *(_BYTE *)(v4 + 9) == 1 )
              {
                if ( (_drm_debug & 4) != 0 )
                  return _drm_dev_dbg(0, 0, 0, "plane%d avoid reset for plane\n", *(_DWORD *)(v1 + 104));
                return result;
              }
            }
          }
        }
      }
    }
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "plane%d \n", *(_DWORD *)(v1 + 104));
    v8 = v2[2];
    if ( v8 )
      drm_mode_object_put(v8 + 24);
    if ( v2[219] )
      sde_sync_put();
    v2[219] = 0;
    ((void (__fastcall *)(__int64, _QWORD *, _QWORD *))msm_property_destroy_state)(v1 + 3344, v2, v2 + 22);
    *(_QWORD *)(v1 + 1768) = 0;
  }
  v9 = (__int64 *)msm_property_alloc_state(v1 + 3344);
  if ( !v9 )
    return printk(&unk_265D86, "sde_plane_reset");
  v10 = v9;
  result = msm_property_reset_state((int)v1 + 3344, v9);
  *v10 = v1;
  *(_QWORD *)(v1 + 1768) = v10;
  return result;
}
