__int64 mlme_twt_osif_enable_complete_ind()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_twt_ops )
    return 0;
  v0 = *(__int64 (**)(void))glbl_twt_ops;
  if ( !*(_QWORD *)glbl_twt_ops )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -1104740360 )
    __break(0x8228u);
  return v0();
}
