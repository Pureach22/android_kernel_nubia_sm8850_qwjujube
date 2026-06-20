__int64 __fastcall process_sysfs_show(__int64 a1, __int64 a2)
{
  __int64 (*v2)(void); // x8

  v2 = *(__int64 (**)(void))(a2 + 16);
  if ( *((_DWORD *)v2 - 1) != 1275563868 )
    __break(0x8228u);
  return v2();
}
