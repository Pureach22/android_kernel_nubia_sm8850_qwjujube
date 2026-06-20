__int64 mlme_vdev_mgr_notify_set_mac_addr_response()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  if ( glbl_vdev_mgr_ops )
  {
    v0 = *(__int64 (**)(void))glbl_vdev_mgr_ops;
    if ( *(_QWORD *)glbl_vdev_mgr_ops )
    {
      if ( *((_DWORD *)v0 - 1) != 86102058 )
        __break(0x8228u);
      return v0();
    }
  }
  return result;
}
