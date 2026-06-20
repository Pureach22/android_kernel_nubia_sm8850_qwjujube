__int64 __fastcall sde_free_edid(_QWORD *a1)
{
  _QWORD *v1; // x19
  __int64 result; // x0

  v1 = (_QWORD *)*a1;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "%s +", "sde_free_edid");
  result = kfree(*v1);
  *v1 = 0;
  return result;
}
