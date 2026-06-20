__int64 mlme_cm_osif_disconnect_complete()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_cm_ops )
    return 0;
  v0 = *(__int64 (**)(void))(glbl_cm_ops + 32);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -1208853352 )
    __break(0x8228u);
  return v0();
}
