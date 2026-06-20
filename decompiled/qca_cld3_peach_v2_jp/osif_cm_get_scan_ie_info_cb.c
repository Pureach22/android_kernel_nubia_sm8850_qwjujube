__int64 osif_cm_get_scan_ie_info_cb()
{
  __int64 (*v0)(void); // x8

  if ( !osif_cm_legacy_ops )
    return 16;
  v0 = *(__int64 (**)(void))(osif_cm_legacy_ops + 56);
  if ( !v0 )
    return 16;
  if ( *((_DWORD *)v0 - 1) != 1464747260 )
    __break(0x8228u);
  return v0();
}
