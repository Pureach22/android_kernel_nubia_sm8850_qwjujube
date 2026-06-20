__int64 __fastcall msm_rng_read(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a1 + 48);
  if ( (*(_BYTE *)(v2 + 80) & 1) != 0 )
    return 0;
  else
    return msm_rng_direct_read(v2, a2);
}
