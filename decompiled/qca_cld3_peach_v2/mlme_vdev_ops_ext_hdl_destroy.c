__int64 mlme_vdev_ops_ext_hdl_destroy()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_ops )
    return 0;
  v0 = *(__int64 (**)(void))(glbl_ops + 48);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -1843776435 )
    __break(0x8228u);
  return v0();
}
