__int64 __fastcall l23_rdy_poll_timeout_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%llu\n", *(_QWORD *)(*(_QWORD *)(a1 + 152) + 1560LL));
}
