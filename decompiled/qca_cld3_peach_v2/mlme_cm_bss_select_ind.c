__int64 mlme_cm_bss_select_ind()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_ops )
    return 11;
  v0 = *(__int64 (**)(void))(glbl_ops + 136);
  if ( !v0 )
    return 11;
  if ( *((_DWORD *)v0 - 1) != 499740325 )
    __break(0x8228u);
  return v0();
}
