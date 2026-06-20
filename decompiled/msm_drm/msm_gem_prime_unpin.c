void __fastcall msm_gem_prime_unpin(__int64 a1)
{
  if ( !*(_QWORD *)(a1 + 240) )
    msm_gem_put_pages();
}
