__int64 __fastcall gh_rm_all_res_populated_cb(void *a1)
{
  if ( !a1 )
    return 4294967274LL;
  if ( gh_all_res_populated_fn )
    return 4294967280LL;
  gh_all_res_populated_fn = a1;
  return 0;
}
