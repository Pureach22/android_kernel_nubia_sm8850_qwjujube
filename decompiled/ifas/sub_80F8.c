__int64 __fastcall sub_80F8(__int64 a1, long double a2)
{
  __int64 v2; // x29

  *(long double *)(v2 + 47744) = a2;
  return perfmgr_do_policy_cpu(a1);
}
