__int64 __fastcall rpmh_rsc_switch_channel(_QWORD *a1, int a2)
{
  writel_relaxed(1LL << a2, (unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 80LL)));
  rpmh_rsc_is_tcs_completed(a1, a2);
  return 0;
}
