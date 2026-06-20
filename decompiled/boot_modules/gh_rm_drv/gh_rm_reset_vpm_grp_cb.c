__int64 __fastcall gh_rm_reset_vpm_grp_cb(void *a1)
{
  if ( !a1 )
    return 4294967274LL;
  if ( gh_vpm_grp_reset_fn )
    return 4294967280LL;
  gh_vpm_grp_reset_fn = a1;
  return 0;
}
