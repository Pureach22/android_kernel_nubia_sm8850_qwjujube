__int64 __fastcall gh_rm_set_wdog_manage_cb(void *a1)
{
  if ( !a1 )
    return 4294967274LL;
  if ( gh_wdog_manage_fn )
    return 4294967280LL;
  gh_wdog_manage_fn = a1;
  return 0;
}
