__int64 msm_minidump_get_available_region()
{
  __int64 (*v0)(void); // x8

  if ( !md_core_0 )
    return 4294967280LL;
  v0 = *(__int64 (**)(void))(md_core_0 + 48);
  if ( *((_DWORD *)v0 - 1) != 1874538549 )
    __break(0x8228u);
  return v0();
}
