__int64 __fastcall clk_branch2_hw_ctl_determine_rate(__int64 a1, _QWORD *a2)
{
  __int64 parent; // x0
  __int64 v4; // x8

  parent = clk_hw_get_parent(a1);
  if ( !parent )
    return 4294967274LL;
  a2[5] = parent;
  v4 = clk_round_rate(*(_QWORD *)(parent + 8), a2[1]);
  a2[4] = v4;
  return 0;
}
