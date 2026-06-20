__int64 __fastcall msm_gem_prime_get_sg_table(_QWORD *a1)
{
  __int64 v1; // x1

  v1 = a1[52];
  if ( v1 )
    return drm_prime_pages_to_sg(a1[1], v1, a1[27] >> 12);
  __break(0x800u);
  return 0;
}
