__int64 mlme_cm_disconnect_complete_ind()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_ops )
    return 0;
  v0 = *(__int64 (**)(void))(glbl_ops + 200);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -1208853352 )
    __break(0x8228u);
  return v0();
}
