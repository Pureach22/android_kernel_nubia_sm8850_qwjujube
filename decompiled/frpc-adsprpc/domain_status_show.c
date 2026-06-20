__int64 __fastcall domain_status_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)sysfs_emit(a3, "%d\n", *(unsigned __int8 *)(a1 - 30));
}
