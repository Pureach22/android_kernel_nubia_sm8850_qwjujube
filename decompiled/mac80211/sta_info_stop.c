__int64 __fastcall sta_info_stop(__int64 a1)
{
  timer_delete_sync(a1 + 1952);
  rhashtable_free_and_destroy(a1 + 1632, 0, 0);
  return rhashtable_free_and_destroy(a1 + 1792, 0, 0);
}
