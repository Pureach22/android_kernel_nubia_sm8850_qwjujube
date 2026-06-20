__int64 __fastcall wlan_hdd_flush_pmksa_cache(__int64 a1)
{
  __int64 vdev_by_user; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x20
  unsigned int v11; // w19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "wlan_hdd_flush_pmksa_cache");
  if ( vdev_by_user )
  {
    v10 = vdev_by_user;
    v11 = wlan_crypto_set_del_pmksa(vdev_by_user, 0, 0, v2, v3, v4, v5, v6, v7, v8, v9);
    _hdd_objmgr_put_vdev_by_user(v10, 6, "wlan_hdd_flush_pmksa_cache");
    if ( v11 )
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Cannot flush PMKIDCache",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_hdd_flush_pmksa_cache");
  }
  else
  {
    return 16;
  }
  return v11;
}
