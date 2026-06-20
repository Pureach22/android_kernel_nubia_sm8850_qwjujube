__int64 mlme_send_scan_done_complete_cb()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  if ( glbl_vdev_mgr_ops )
  {
    v0 = *(__int64 (**)(void))(glbl_vdev_mgr_ops + 8);
    if ( v0 )
    {
      if ( *((_DWORD *)v0 - 1) != -1560483463 )
        __break(0x8228u);
      return v0();
    }
  }
  return result;
}
