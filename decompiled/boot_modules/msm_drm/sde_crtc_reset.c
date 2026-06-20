__int64 __fastcall sde_crtc_reset(__int64 result)
{
  __int64 v1; // x1
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 *v5; // x0
  __int64 *v6; // x20
  __int64 v7; // x8

  if ( !result )
    return printk(&unk_25E167, "sde_crtc_reset");
  v1 = *(_QWORD *)(result + 2008);
  v2 = result;
  if ( v1 )
  {
    if ( *(_QWORD *)result )
    {
      v3 = *(_QWORD *)(*(_QWORD *)result + 56LL);
      if ( v3 )
      {
        v4 = *(_QWORD *)(v3 + 8);
        if ( v4 )
        {
          if ( *(_QWORD *)(v4 + 2128) && *(_BYTE *)(v1 + 9) == 1 )
          {
            if ( (_drm_debug & 4) != 0 )
              return _drm_dev_dbg(0, 0, 0, "avoiding reset for crtc:%d\n", *(_DWORD *)(result + 112));
            return result;
          }
        }
      }
    }
    sde_crtc_destroy_state(result);
    *(_QWORD *)(v2 + 2008) = 0;
  }
  v5 = (__int64 *)msm_property_alloc_state(v2 + 2600);
  if ( !v5 )
    return printk(&unk_219686, "sde_crtc_reset");
  v6 = v5;
  result = msm_property_reset_state((int)v2 + 2600, v5);
  v7 = v6[120];
  *v6 = v2;
  v6[225] = 1000000 * v7;
  *(_QWORD *)(v2 + 2008) = v6;
  return result;
}
