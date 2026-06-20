__int64 osif_vdev_mgr_get_p2p_wdev()
{
  __int64 (*v0)(void); // x8

  if ( !osif_vdev_mgr_legacy_ops )
    return 0;
  v0 = *(__int64 (**)(void))(osif_vdev_mgr_legacy_ops + 16);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != 1359792503 )
    __break(0x8228u);
  return v0();
}
