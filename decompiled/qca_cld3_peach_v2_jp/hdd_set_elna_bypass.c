__int64 __fastcall hdd_set_elna_bypass(__int64 a1, __int64 a2)
{
  __int64 vdev_by_user; // x0
  __int64 v4; // x20
  unsigned int v5; // w19

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 70, "hdd_set_elna_bypass");
  if ( vdev_by_user )
  {
    v4 = vdev_by_user;
    v5 = os_if_fwol_set_elna_bypass(vdev_by_user, a2);
    _hdd_objmgr_put_vdev_by_user(v4, 70, "hdd_set_elna_bypass");
  }
  else
  {
    return (unsigned int)-22;
  }
  return v5;
}
