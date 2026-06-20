__int64 __fastcall tmc_free_sg_table(_QWORD *a1)
{
  if ( a1[1] )
    vunmap();
  tmc_pages_free(a1 + 5, *a1, 1);
  if ( a1[2] )
    vunmap();
  tmc_pages_free(a1 + 8, *a1, 2);
  return kfree(a1);
}
