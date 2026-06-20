__int64 __fastcall sched_early_upmigrate_store(int a1, int a2, char *a3, __int64 a4)
{
  return store_updown_migrate_handle(a1, a2, a3, a4, 1);
}
