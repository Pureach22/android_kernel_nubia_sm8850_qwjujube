__int64 __fastcall dup_gh_sgl_desc(__int64 result)
{
  const void *v1; // x19
  size_t v2; // x20
  void *v3; // x0
  void *v4; // x21

  if ( result )
  {
    v1 = (const void *)result;
    v2 = (16LL * *(unsigned int *)result) | 6;
    v3 = (void *)_kvmalloc_node_noprof(v2, 0, 3264, 0xFFFFFFFFLL);
    if ( v3 )
    {
      v4 = v3;
      memcpy(v3, v1, v2);
      return (__int64)v4;
    }
    else
    {
      return -12;
    }
  }
  return result;
}
