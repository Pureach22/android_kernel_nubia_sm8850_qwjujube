__int64 __fastcall writeback_limit_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x21
  __int64 v5; // x20

  v4 = *(_QWORD *)(*(_QWORD *)(a1 - 224) + 88LL);
  down_read(v4 + 32);
  raw_spin_lock(v4 + 248);
  v5 = *(_QWORD *)(v4 + 256);
  raw_spin_unlock(v4 + 248);
  up_read(v4 + 32);
  return (int)scnprintf(a3, 4096, "%llu\n", v5);
}
