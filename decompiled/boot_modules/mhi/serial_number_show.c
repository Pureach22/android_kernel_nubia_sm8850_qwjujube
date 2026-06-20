__int64 __fastcall serial_number_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)sysfs_emit(a3, "Serial Number: %u\n", *(_DWORD *)(*(_QWORD *)(a1 - 24) + 244LL));
}
