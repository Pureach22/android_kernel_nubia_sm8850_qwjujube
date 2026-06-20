__int64 osif_vdev_mgr_set_mac_addr_response()
{
  void (*v0)(void); // x8

  if ( osif_vdev_mgr_legacy_ops )
  {
    v0 = *(void (**)(void))osif_vdev_mgr_legacy_ops;
    if ( *(_QWORD *)osif_vdev_mgr_legacy_ops )
    {
      if ( *((_DWORD *)v0 - 1) != 2130452855 )
        __break(0x8228u);
      v0();
    }
  }
  return 0;
}
