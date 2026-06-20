__int64 __fastcall sde_connector_get_dpms(__int64 a1)
{
  unsigned int v2; // w19

  if ( a1 )
  {
    mutex_lock(a1 + 2816);
    v2 = *(_DWORD *)(a1 + 3288);
    mutex_unlock(a1 + 2816);
  }
  else
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "invalid connector\n");
    return 3;
  }
  return v2;
}
