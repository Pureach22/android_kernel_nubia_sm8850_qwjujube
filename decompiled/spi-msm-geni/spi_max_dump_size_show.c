__int64 __fastcall spi_max_dump_size_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4, "%d\n", *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL) + 524LL));
}
