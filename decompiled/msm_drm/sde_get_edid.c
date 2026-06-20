double __fastcall sde_get_edid(__int64 a1, __int64 a2, __int64 **a3)
{
  __int64 *v3; // x19
  __int64 edid; // x0
  double result; // d0

  v3 = *a3;
  edid = drm_get_edid();
  *v3 = edid;
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "%s +\n", "sde_get_edid");
    edid = *v3;
  }
  if ( edid || (printk(&unk_23FDA1, "sde_get_edid"), *v3) )
    sde_parse_edid(v3);
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(0, 0, 0, "%s -\n", "sde_get_edid");
  return result;
}
