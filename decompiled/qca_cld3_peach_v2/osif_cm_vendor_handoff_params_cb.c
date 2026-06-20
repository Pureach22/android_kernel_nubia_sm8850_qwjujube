__int64 osif_cm_vendor_handoff_params_cb()
{
  __int64 (*v0)(void); // x8

  if ( !osif_cm_legacy_ops )
    return 16;
  v0 = *(__int64 (**)(void))(osif_cm_legacy_ops + 88);
  if ( !v0 )
    return 16;
  if ( *((_DWORD *)v0 - 1) != -1796695762 )
    __break(0x8228u);
  return v0();
}
