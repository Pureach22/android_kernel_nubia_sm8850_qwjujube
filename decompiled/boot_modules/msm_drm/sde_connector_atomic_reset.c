__int64 __fastcall sde_connector_atomic_reset(__int64 result)
{
  __int64 v1; // x1
  __int64 v2; // x19
  __int64 *v3; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x9
  void *v8; // x0
  void *v9; // x20

  if ( !result )
    return printk(&unk_242658, "sde_connector_atomic_reset");
  v1 = *(_QWORD *)(result + 2512);
  v2 = result;
  if ( v1 )
  {
    v3 = *(__int64 **)(v1 + 8);
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
                  return _drm_dev_dbg(0, 0, 0, "conn%d avoid reset for connector\n", *(_DWORD *)(result + 64));
                return result;
              }
            }
          }
        }
      }
    }
    sde_connector_atomic_destroy_state(result);
    *(_QWORD *)(v2 + 2512) = 0;
  }
  v8 = (void *)msm_property_alloc_state(v2 + 3312);
  if ( !v8 )
    return printk(&unk_227BC4, "sde_connector_atomic_reset");
  v9 = v8;
  msm_property_reset_state(v2 + 3312, v8);
  return _drm_atomic_helper_connector_reset(v2, v9);
}
