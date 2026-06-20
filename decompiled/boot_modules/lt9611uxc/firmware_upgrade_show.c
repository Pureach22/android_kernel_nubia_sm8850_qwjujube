__int64 __fastcall firmware_upgrade_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%d\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) + 4024LL));
}
