double __fastcall sde_edid_deinit(_QWORD *a1)
{
  _QWORD *v1; // x19
  double result; // d0

  v1 = (_QWORD *)*a1;
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "%s +", "sde_edid_deinit");
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "%s +", "sde_free_edid");
  }
  kfree(*v1);
  *v1 = 0;
  kfree(v1);
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(0, 0, 0, "%s -", "sde_edid_deinit");
  return result;
}
