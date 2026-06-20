__int64 __fastcall gh_rm_set_vcpu_affinity_cb(void *a1)
{
  if ( !a1 )
    return 4294967274LL;
  if ( gh_vcpu_affinity_set_fn )
    return 4294967280LL;
  gh_vcpu_affinity_set_fn = a1;
  return 0;
}
