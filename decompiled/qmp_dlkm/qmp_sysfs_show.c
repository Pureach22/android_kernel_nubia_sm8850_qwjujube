__int64 __fastcall qmp_sysfs_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 32, "%d", *(_DWORD *)(a1 + 96));
}
