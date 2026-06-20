__int64 mlme_vdev_ops_ext_hdl_multivdev_restart_resp()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_ops )
    return 0;
  v0 = *(__int64 (**)(void))(glbl_ops + 104);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != 1115142641 )
    __break(0x8228u);
  return v0();
}
