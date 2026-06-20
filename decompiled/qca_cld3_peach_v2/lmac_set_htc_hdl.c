__int64 __fastcall lmac_set_htc_hdl(
        __int64 result,
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
  __int64 v10; // x8
  const char *v11; // x2

  if ( result )
  {
    v10 = *(_QWORD *)(result + 2800);
    if ( v10 )
    {
      *(_QWORD *)(v10 + 8) = a2;
      return result;
    }
    v11 = "%s: target_psoc_info is null";
  }
  else
  {
    v11 = "%s: psoc is null";
  }
  return qdf_trace_msg(0x49u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "lmac_set_htc_hdl");
}
