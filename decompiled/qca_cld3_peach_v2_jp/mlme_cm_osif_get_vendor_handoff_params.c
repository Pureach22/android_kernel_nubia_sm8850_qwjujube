__int64 mlme_cm_osif_get_vendor_handoff_params()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_cm_ops )
    return 16;
  v0 = *(__int64 (**)(void))(glbl_cm_ops + 128);
  if ( !v0 )
    return 16;
  if ( *((_DWORD *)v0 - 1) != -1796695762 )
    __break(0x8228u);
  return v0();
}
