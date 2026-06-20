__int64 __fastcall sde_connector_atomic_duplicate_state(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 v4; // x8

  if ( a1 && (v2 = *(_QWORD *)(a1 + 2512)) != 0 )
  {
    if ( *(_BYTE *)(v2 + 3260) == 1 )
    {
      *(_QWORD *)(v2 + 8) = 0;
      *(_BYTE *)(v2 + 3260) = 0;
    }
    v3 = msm_property_alloc_state(a1 + 3312);
    if ( v3 )
    {
      mutex_lock(a1 + 3392);
      msm_property_duplicate_state(a1 + 3312, v2, (void *)v3);
      mutex_unlock(a1 + 3392);
      _drm_atomic_helper_connector_duplicate_state(a1, v3);
      v4 = *(_QWORD *)(v3 + 440);
      if ( v4 )
        drm_mode_object_get(v4 + 24);
      if ( *(_BYTE *)(v3 + 3228) == 1 )
      {
        *(_BYTE *)(v3 + 3228) = 0;
        *(_DWORD *)(v3 + 3224) = 0;
      }
    }
    else
    {
      printk(&unk_227BC4, "sde_connector_atomic_duplicate_state");
    }
  }
  else
  {
    printk(&unk_265F8D, "sde_connector_atomic_duplicate_state");
    return 0;
  }
  return v3;
}
