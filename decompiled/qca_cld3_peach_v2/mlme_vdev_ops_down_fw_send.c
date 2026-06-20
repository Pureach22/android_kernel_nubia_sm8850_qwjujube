__int64 mlme_vdev_ops_down_fw_send()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_ops )
    return 0;
  v0 = *(__int64 (**)(void))(glbl_ops + 72);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != 1263140689 )
    __break(0x8228u);
  return v0();
}
