void *__fastcall sde_crtc_duplicate_state(_QWORD *a1)
{
  __int64 v1; // x20
  __int64 v3; // x8
  void *v4; // x21
  void *v5; // x0
  void *v6; // x0

  if ( !a1 || (v1 = a1[251]) == 0 )
  {
    v5 = &unk_253460;
LABEL_14:
    printk(v5, "sde_crtc_duplicate_state");
    return nullptr;
  }
  if ( !*a1 || (v3 = *(_QWORD *)(*a1 + 56LL)) == 0 )
  {
    v6 = &unk_25E167;
LABEL_13:
    printk(v6, "_sde_crtc_get_kms");
    v5 = &unk_234896;
    goto LABEL_14;
  }
  if ( !*(_QWORD *)(v3 + 8) )
  {
    v6 = &unk_234896;
    goto LABEL_13;
  }
  if ( *(_BYTE *)(v1 + 6904) == 1 )
  {
    *(_DWORD *)(v1 + 12) = 0;
    *(_DWORD *)(a1[251] + 16LL) = 0;
    *(_DWORD *)(a1[251] + 20LL) = 0;
    *(_BYTE *)(a1[251] + 8LL) = 0;
    *(_BYTE *)(v1 + 6904) = 0;
  }
  v4 = (void *)msm_property_alloc_state(a1 + 325);
  if ( v4 )
  {
    mutex_lock(a1 + 335);
    msm_property_duplicate_state((_DWORD)a1 + 2600, v1, v4);
    mutex_unlock(a1 + 335);
    sde_cp_duplicate_state_info(v1, (int)v4);
    _drm_atomic_helper_crtc_duplicate_state(a1, v4);
  }
  else
  {
    printk(&unk_219686, "sde_crtc_duplicate_state");
  }
  return v4;
}
