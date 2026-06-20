__int64 __fastcall ipa_rm_dep_graph_create(__int64 *a1)
{
  __int64 v2; // x8
  __int64 result; // x0

  v2 = _kmalloc_cache_noprof(_kmalloc_noprof, 3520, 176);
  if ( v2 )
    result = 0;
  else
    result = 4294967284LL;
  *a1 = v2;
  return result;
}
