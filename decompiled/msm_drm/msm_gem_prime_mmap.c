__int64 __fastcall msm_gem_prime_mmap(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = drm_gem_mmap_obj();
  if ( (result & 0x80000000) == 0 )
    return msm_gem_mmap_obj(*(_QWORD *)(a2 + 96), a2);
  return result;
}
