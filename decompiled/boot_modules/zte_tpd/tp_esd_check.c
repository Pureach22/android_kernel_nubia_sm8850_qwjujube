__int64 tp_esd_check()
{
  __int64 (*v0)(void); // x8

  v0 = *(__int64 (**)(void))(tpd_cdev + 3296);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -2139014615 )
    __break(0x8228u);
  return v0() & 1;
}
