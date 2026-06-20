__int64 __fastcall sub_4A909C(__int64 a1, __int64 a2, __int64 a3, long double a4, long double a5)
{
  __int64 v5; // x23

  *(long double *)(v5 + 800) = a4;
  *(long double *)(v5 + 816) = a5;
  return csr_roam_start_beacon_req(a1, a2, a3);
}
