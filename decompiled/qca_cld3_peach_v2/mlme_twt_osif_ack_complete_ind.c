__int64 mlme_twt_osif_ack_complete_ind()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_twt_ops )
    return 0;
  v0 = *(__int64 (**)(void))(glbl_twt_ops + 16);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -1868956434 )
    __break(0x8228u);
  return v0();
}
