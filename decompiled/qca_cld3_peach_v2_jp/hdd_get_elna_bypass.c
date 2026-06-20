__int64 __fastcall hdd_get_elna_bypass(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 vdev_by_user; // x0
  __int64 v6; // x21
  unsigned int elna_bypass; // w19

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 70, "hdd_get_elna_bypass");
  if ( vdev_by_user )
  {
    v6 = vdev_by_user;
    elna_bypass = os_if_fwol_get_elna_bypass(vdev_by_user, a2, a3);
    _hdd_objmgr_put_vdev_by_user(v6, 70, "hdd_get_elna_bypass");
  }
  else
  {
    return (unsigned int)-22;
  }
  return elna_bypass;
}
