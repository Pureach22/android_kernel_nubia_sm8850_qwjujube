__int64 __fastcall wcd939x_surge_reset_routine(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 24LL) + 152LL);
  regcache_mark_dirty(*(_QWORD *)(v1 + 32));
  return regcache_sync(*(_QWORD *)(v1 + 32));
}
