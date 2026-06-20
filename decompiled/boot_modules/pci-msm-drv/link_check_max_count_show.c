__int64 __fastcall link_check_max_count_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%d\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) + 1240LL));
}
