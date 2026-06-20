__int64 __fastcall lmac_get_tgt_revision(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  const char *v11; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2800);
    if ( v9 )
      return *(unsigned int *)(v9 + 48);
    v11 = "%s: target_psoc_info is null";
  }
  else
  {
    v11 = "%s: psoc is null";
  }
  qdf_trace_msg(0x49u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "lmac_get_tgt_revision");
  return 4294967274LL;
}
