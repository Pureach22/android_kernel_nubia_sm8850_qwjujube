__int64 __fastcall msm_gem_prime_vmap(__int64 a1, unsigned __int64 *a2)
{
  unsigned __int64 vaddr; // x0
  unsigned __int64 v4; // x8
  bool v5; // cc
  __int64 result; // x0

  vaddr = msm_gem_get_vaddr(a1);
  v4 = vaddr;
  if ( vaddr )
    v5 = vaddr > 0xFFFFFFFFFFFFF000LL;
  else
    v5 = 1;
  result = v5;
  *a2 = v4;
  return result;
}
