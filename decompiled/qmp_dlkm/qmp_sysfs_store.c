__int64 __fastcall qmp_sysfs_store(__int64 a1, __int64 a2, int *a3)
{
  *(_DWORD *)(a1 + 96) = *a3;
  *(_DWORD *)(a1 + 100) = a3[1];
  return *a3;
}
