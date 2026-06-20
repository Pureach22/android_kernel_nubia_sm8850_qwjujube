__int64 __fastcall sde_plane_duplicate_state(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v5; // x2
  int v6; // w8
  void *v8; // x0

  if ( !a1 )
  {
    v8 = &unk_226FC0;
LABEL_23:
    printk(v8, "sde_plane_duplicate_state");
    return 0;
  }
  v1 = *(_QWORD *)(a1 + 1768);
  if ( !v1 )
  {
    v8 = &unk_23C088;
    goto LABEL_23;
  }
  if ( *(_BYTE *)(v1 + 2760) == 1 )
  {
    *(_QWORD *)(v1 + 8) = 0;
    *(_BYTE *)(v1 + 2760) = 0;
  }
  v3 = msm_property_alloc_state(a1 + 3344);
  if ( v3 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "plane%d \n", *(_DWORD *)(a1 + 104));
    mutex_lock(a1 + 3424);
    msm_property_duplicate_state(a1 + 3344, v1, (void *)v3);
    mutex_unlock(a1 + 3424);
    *(_QWORD *)(v3 + 1752) = 0;
    mutex_lock(a1 + 3424);
    v4 = 0;
    if ( *(_DWORD *)(a1 + 3376) >= 0x17u )
      v4 = *(_QWORD *)(*(_QWORD *)(a1 + 3368) + 352LL);
    mutex_unlock(a1 + 3424);
    if ( *(_DWORD *)(a1 + 3376) < 0x17u )
      v5 = 0;
    else
      v5 = *(_QWORD *)(*(_QWORD *)(a1 + 3360) + 176LL);
    if ( (unsigned int)msm_property_atomic_set(a1 + 3344, v3 + 176, v5, v4) && (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "plane%d error clearing duplicated input fence\n", *(_DWORD *)(a1 + 104));
    *(_DWORD *)(v3 + 1772) = 0;
    *(_BYTE *)(v3 + 1785) = 0;
    _drm_atomic_helper_plane_duplicate_state(a1, v3);
    v6 = *(_DWORD *)(v3 + 1792);
    if ( v6 )
    {
      if ( v6 >= 1 )
        *(_DWORD *)(v3 + 32) += v6;
      *(_QWORD *)(v3 + 1792) = 0;
    }
  }
  else
  {
    printk(&unk_265D86, "sde_plane_duplicate_state");
  }
  return v3;
}
