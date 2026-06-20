__int64 __fastcall clk_rcg_bypass_determine_rate(__int64 a1, _QWORD *a2)
{
  unsigned int src_index; // w0
  __int64 parent_by_index; // x0
  __int64 v6; // x8

  src_index = qcom_find_src_index();
  parent_by_index = clk_hw_get_parent_by_index(a1, src_index);
  a2[5] = parent_by_index;
  if ( !parent_by_index )
    return 4294967274LL;
  v6 = clk_hw_round_rate(parent_by_index, a2[1]);
  a2[4] = v6;
  a2[1] = v6;
  return 0;
}
