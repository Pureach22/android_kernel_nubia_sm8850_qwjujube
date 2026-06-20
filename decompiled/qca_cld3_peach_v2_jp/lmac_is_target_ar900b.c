__int64 __fastcall lmac_is_target_ar900b(
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
  unsigned int v10; // w8
  unsigned int v11; // w8
  const char *v12; // x2

  if ( !a1 )
  {
    v12 = "%s: psoc is null\n";
LABEL_7:
    qdf_trace_msg(0x49u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "lmac_is_target_ar900b");
    goto LABEL_8;
  }
  v9 = *(_QWORD *)(a1 + 2800);
  if ( !v9 )
  {
    v12 = "%s: target_psoc_info is null";
    goto LABEL_7;
  }
  v10 = *(_DWORD *)(v9 + 496);
  if ( v10 > 0x11 )
  {
LABEL_8:
    LOBYTE(v11) = 0;
    return v11 & 1;
  }
  v11 = 0x28200u >> v10;
  return v11 & 1;
}
