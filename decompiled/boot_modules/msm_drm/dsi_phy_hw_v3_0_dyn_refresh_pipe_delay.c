__int64 __fastcall dsi_phy_hw_v3_0_dyn_refresh_pipe_delay(__int64 result, unsigned int *a2)
{
  __int64 v3; // x20

  if ( a2 )
  {
    v3 = result;
    writel_relaxed_9(*a2, (unsigned int *)(*(_QWORD *)(result + 16) + 4LL));
    writel_relaxed_9(a2[1], (unsigned int *)(*(_QWORD *)(v3 + 16) + 8LL));
    return writel_relaxed_9(a2[5], (unsigned int *)(*(_QWORD *)(v3 + 16) + 12LL));
  }
  return result;
}
