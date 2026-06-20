__int64 __fastcall battery_cell_id_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%u\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) + 4780LL));
}
