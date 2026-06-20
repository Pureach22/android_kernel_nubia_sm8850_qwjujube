__int64 __fastcall snapshot_sysfs_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x8
  __int64 v5; // x0

  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a2 + 24);
  if ( !v4 )
    return -5;
  v5 = a1 - 11320;
  if ( *((_DWORD *)v4 - 1) != 975047283 )
    __break(0x8228u);
  return v4(v5, a3, a4);
}
