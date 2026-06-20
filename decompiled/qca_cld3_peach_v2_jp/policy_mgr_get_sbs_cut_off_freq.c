__int64 __fastcall policy_mgr_get_sbs_cut_off_freq(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  unsigned int v21; // w8
  unsigned int v22; // w19

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_get_sbs_cut_off_freq");
    return 0;
  }
  v11 = (unsigned int *)context;
  if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) == 0 )
    return 0;
  result = v11[300];
  if ( !(_DWORD)result )
  {
    v21 = v11[323];
    if ( v21 <= v11[319] )
      v21 = v11[319];
    v22 = v21 - 1;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: sbs cutoff freq %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "policy_mgr_get_sbs_cut_off_freq",
      v21 - 1);
    return v22;
  }
  return result;
}
