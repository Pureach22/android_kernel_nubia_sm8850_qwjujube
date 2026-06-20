__int64 mlme_twt_osif_pause_complete_ind()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_twt_ops )
    return 0;
  v0 = *(__int64 (**)(void))(glbl_twt_ops + 40);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != 211918323 )
    __break(0x8228u);
  return v0();
}
