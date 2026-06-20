__int64 __fastcall msm_ssphy_qmp_notify_disconnect(__int64 *a1)
{
  __int64 v1; // x19
  int v3; // w8
  __int64 v4; // x8

  v1 = *a1;
  _pm_runtime_resume(*a1, 0);
  atomic_notifier_call_chain(a1 + 28, 0);
  v3 = *((_DWORD *)a1 + 4);
  if ( (v3 & 1) != 0 )
  {
    writel_relaxed(0);
    readl_relaxed(a1[46] + *(unsigned int *)(a1[69] + 12));
    v3 = *((_DWORD *)a1 + 4);
  }
  if ( (v3 & 0x800) == 0 )
  {
    v4 = *(_QWORD *)(v1 + 592);
    if ( v4 )
      *(_DWORD *)(v4 + 520) &= 0xFFFFFFF3;
  }
  *((_BYTE *)a1 + 546) = 0;
  _pm_runtime_suspend(v1, 0);
  return 0;
}
