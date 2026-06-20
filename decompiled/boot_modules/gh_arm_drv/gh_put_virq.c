__int64 __fastcall gh_put_virq(int a1)
{
  __int64 v1; // x19

  v1 = a1 - 32;
  if ( !idr_find(&gh_rm_free_virq_idr, v1) )
    return 4294967274LL;
  idr_remove(&gh_rm_free_virq_idr, v1);
  return 0;
}
