__int64 __fastcall dynamic_page_pool_release_pools(__int64 *a1)
{
  dynamic_page_pool_destroy(*a1);
  dynamic_page_pool_destroy(a1[1]);
  dynamic_page_pool_destroy(a1[2]);
  return kfree(a1);
}
