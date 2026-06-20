__int64 __fastcall label_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)sysfs_emit(a3, "%s\n", *(const char **)(a1 - 8));
}
