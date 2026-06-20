__int64 __fastcall io_stat_show(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v4; // x20
  __int64 v5; // x19

  v4 = *(_QWORD **)(*(_QWORD *)(a1 - 224) + 88LL);
  down_read(v4 + 4);
  v5 = (int)scnprintf(a3, 4096, "%8llu %8llu 0 %8llu\n", v4[14], v4[15], v4[16]);
  up_read(v4 + 4);
  return v5;
}
