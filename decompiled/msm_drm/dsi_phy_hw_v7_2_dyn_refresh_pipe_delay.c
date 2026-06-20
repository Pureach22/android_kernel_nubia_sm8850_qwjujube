__int64 __fastcall dsi_phy_hw_v7_2_dyn_refresh_pipe_delay(__int64 result, unsigned int *a2)
{
  __int64 v2; // x19

  if ( a2 )
  {
    v2 = result;
    writel_relaxed_12(*a2, (unsigned int *)(*(_QWORD *)(result + 16) + 4LL));
    writel_relaxed_12(a2[1], (unsigned int *)(*(_QWORD *)(v2 + 16) + 8LL));
    if ( a2[3] )
    {
      writel_relaxed_12(a2[2], (unsigned int *)(*(_QWORD *)(v2 + 16) + 352LL));
      writel_relaxed_12(a2[3], (unsigned int *)(*(_QWORD *)(v2 + 16) + 732LL));
      writel_relaxed_12(a2[4], (unsigned int *)(*(_QWORD *)(v2 + 16) + 736LL));
    }
    return writel_relaxed_12(a2[5], (unsigned int *)(*(_QWORD *)(v2 + 16) + 12LL));
  }
  return result;
}
