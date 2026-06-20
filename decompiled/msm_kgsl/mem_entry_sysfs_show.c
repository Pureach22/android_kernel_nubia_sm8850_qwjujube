__int64 __fastcall mem_entry_sysfs_show(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v2)(__int64, __int64); // x8
  __int64 v3; // x1
  __int64 v4; // x0

  v2 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 40);
  v3 = *(unsigned int *)(a2 + 32);
  v4 = a1 - 104;
  if ( *((_DWORD *)v2 - 1) != 413728843 )
    __break(0x8228u);
  return v2(v4, v3);
}
