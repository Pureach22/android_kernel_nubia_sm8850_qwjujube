__int64 md_get_region()
{
  __int64 (*v0)(void); // x9

  v0 = *(__int64 (**)(void))(md_core_0 + 64);
  if ( *((_DWORD *)v0 - 1) != -775352890 )
    __break(0x8229u);
  return v0();
}
