__int64 mlme_vdev_ops_multivdev_restart_fw_cmd_send()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_ops )
    return 0;
  v0 = *(__int64 (**)(void))(glbl_ops + 80);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -2099273483 )
    __break(0x8228u);
  return v0();
}
