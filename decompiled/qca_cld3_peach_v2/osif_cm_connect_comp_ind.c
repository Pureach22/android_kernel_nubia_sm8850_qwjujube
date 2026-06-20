__int64 osif_cm_connect_comp_ind()
{
  __int64 (*v0)(void); // x8

  if ( !osif_cm_legacy_ops )
    return 0;
  v0 = *(__int64 (**)(void))(osif_cm_legacy_ops + 8);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -1759620676 )
    __break(0x8228u);
  return v0();
}
