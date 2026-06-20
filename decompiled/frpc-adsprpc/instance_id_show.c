__int64 __fastcall instance_id_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)sysfs_emit(a3, "%d\n", *(_DWORD *)(a1 - 28));
}
