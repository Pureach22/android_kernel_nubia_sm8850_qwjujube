__int64 __fastcall tgt_ipa_uc_offload_enable_disable(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 (__fastcall *v21)(__int64, __int64); // x8
  unsigned int v22; // w19

  qdf_trace_msg(0x61u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_ipa_uc_offload_enable_disable");
  if ( !a1 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: NULL psoc",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "tgt_ipa_uc_offload_enable_disable");
    return 29;
  }
  v20 = *(_QWORD *)(a1 + 2128);
  if ( !v20 )
    return 29;
  v21 = *(__int64 (__fastcall **)(__int64, __int64))(v20 + 2088);
  if ( v21 )
  {
    if ( *((_DWORD *)v21 - 1) != -1758023019 )
      __break(0x8228u);
    v22 = v21(a1, a2);
  }
  else
  {
    v22 = 16;
  }
  qdf_trace_msg(0x61u, 8u, "%s: exit", v12, v13, v14, v15, v16, v17, v18, v19, "tgt_ipa_uc_offload_enable_disable");
  return v22;
}
