__int64 __fastcall kgsl_gpu_sysfs_attr_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v3)(__int64, __int64); // x8
  __int64 v4; // x0

  v3 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 16);
  if ( !v3 )
    return -5;
  v4 = a1 - 12992;
  if ( *((_DWORD *)v3 - 1) != -1951090457 )
    __break(0x8228u);
  return v3(v4, a3);
}
