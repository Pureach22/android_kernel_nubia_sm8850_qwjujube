__int64 __fastcall msm_gem_prime_pin(__int64 a1)
{
  if ( !*(_QWORD *)(a1 + 240) )
    msm_gem_get_pages(a1);
  return 0;
}
