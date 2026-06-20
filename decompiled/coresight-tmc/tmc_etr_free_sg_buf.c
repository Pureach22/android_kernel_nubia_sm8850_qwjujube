__int64 __fastcall tmc_etr_free_sg_buf(__int64 result)
{
  __int64 *v1; // x19
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x0

  v1 = *(__int64 **)(result + 56);
  if ( v1 )
  {
    v2 = *v1;
    v3 = *(_QWORD *)(*v1 + 8);
    if ( v3 )
      vunmap(v3);
    tmc_pages_free((int *)(v2 + 40), *(_QWORD *)v2, 1u);
    v4 = *(_QWORD *)(v2 + 16);
    if ( v4 )
      vunmap(v4);
    tmc_pages_free((int *)(v2 + 64), *(_QWORD *)v2, 2u);
    kfree(v2);
    return kfree(v1);
  }
  return result;
}
