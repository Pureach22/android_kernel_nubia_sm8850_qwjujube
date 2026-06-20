__int64 __fastcall sde_connector_atomic_destroy_state(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v5; // x21

  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 440);
    if ( v2 )
    {
      drm_mode_object_put(v2 + 24);
      *(_QWORD *)(a2 + 440) = 0;
      if ( a1 )
      {
        mutex_lock(a1 + 3392);
        if ( *(_DWORD *)(a1 + 3344) < 0xCu )
          v5 = 0;
        else
          v5 = *(_QWORD *)(*(_QWORD *)(a1 + 3336) + 176LL);
        mutex_unlock(a1 + 3392);
        *(_QWORD *)(a2 + 832) = v5;
        _drm_atomic_helper_connector_destroy_state(a2);
        return ((__int64 (__fastcall *)(__int64, __int64, __int64))msm_property_destroy_state)(a1 + 3312, a2, a2 + 448);
      }
      *(_QWORD *)(a2 + 832) = -1;
      _drm_atomic_helper_connector_destroy_state(a2);
    }
    else
    {
      _drm_atomic_helper_connector_destroy_state(a2);
      if ( a1 )
        return ((__int64 (__fastcall *)(__int64, __int64, __int64))msm_property_destroy_state)(a1 + 3312, a2, a2 + 448);
    }
    return kfree(a2);
  }
  return printk(&unk_279EAB, "sde_connector_atomic_destroy_state");
}
