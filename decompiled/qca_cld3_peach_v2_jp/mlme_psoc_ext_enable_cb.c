__int64 mlme_psoc_ext_enable_cb()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_ops )
    return 0;
  v0 = *(__int64 (**)(void))(glbl_ops + 240);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -770124015 )
    __break(0x8228u);
  return v0();
}
