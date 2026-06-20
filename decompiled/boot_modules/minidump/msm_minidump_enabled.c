__int64 msm_minidump_enabled()
{
  __int64 (*v0)(void); // x8

  if ( !md_core_0 )
    return 0;
  v0 = *(__int64 (**)(void))(md_core_0 + 56);
  if ( *((_DWORD *)v0 - 1) != 799902358 )
    __break(0x8228u);
  return v0() & 1;
}
