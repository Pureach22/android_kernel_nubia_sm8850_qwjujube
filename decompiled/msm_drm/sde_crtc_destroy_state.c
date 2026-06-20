__int64 __fastcall sde_crtc_destroy_state(__int64 *a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v5; // x9
  __int64 v6; // x21
  __int64 *i; // x22
  void *v9; // x0

  if ( !a1 || !a2 )
    return printk(&unk_253460, "sde_crtc_destroy_state");
  v3 = *a1;
  if ( !*a1 || (v5 = *(_QWORD *)(v3 + 56)) == 0 )
  {
    v9 = &unk_25E167;
LABEL_18:
    printk(v9, "_sde_crtc_get_kms");
    return printk(&unk_25E374, "sde_crtc_destroy_state");
  }
  v6 = *(_QWORD *)(v5 + 8);
  if ( !v6 )
  {
    v9 = &unk_234896;
    goto LABEL_18;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "crtc%d\n", *((_DWORD *)a1 + 28));
    v3 = *a1;
  }
  for ( i = *(__int64 **)(v3 + 816); i != (__int64 *)(v3 + 816); i = (__int64 *)*i )
  {
    if ( ((*(_DWORD *)(a2 + 20) >> *((_DWORD *)i + 15)) & 1) != 0 )
    {
      sde_rm_release(v6 + 2144, i - 1, 1);
      v3 = *a1;
    }
  }
  sde_cp_clear_state_info(a2);
  _drm_atomic_helper_crtc_destroy_state(a2);
  return ((__int64 (__fastcall *)(__int64 *, __int64, __int64))msm_property_destroy_state)(a1 + 325, a2, a2 + 768);
}
