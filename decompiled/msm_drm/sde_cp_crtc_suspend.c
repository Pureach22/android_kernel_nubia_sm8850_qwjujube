__int64 __fastcall sde_cp_crtc_suspend(__int64 a1)
{
  __int64 v2; // x0

  if ( !a1 )
    return _drm_err("crtc %pK\n", nullptr);
  sde_cp_crtc_mark_features_dirty((_QWORD *)a1);
  v2 = raw_spin_lock_irqsave(a1 + 7752);
  *(_BYTE *)(a1 + 7672) = 0;
  return raw_spin_unlock_irqrestore(a1 + 7752, v2);
}
