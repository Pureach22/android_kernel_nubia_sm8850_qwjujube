__int64 __fastcall snapshot_sysfs_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x0
  __int64 (__fastcall *v4)(__int64, __int64); // x8

  v3 = a1 - 11320;
  if ( !v3 )
    return -5;
  v4 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 16);
  if ( !v4 )
    return -5;
  if ( *((_DWORD *)v4 - 1) != -1951090457 )
    __break(0x8228u);
  return v4(v3, a3);
}
