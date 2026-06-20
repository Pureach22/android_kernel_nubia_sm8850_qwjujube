__int64 __fastcall psoc_mlme_ext_hdl_destroy(
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
  __int64 result; // x0

  if ( a1 )
  {
    result = *(_QWORD *)(a1 + 8);
    if ( result )
    {
      _qdf_mem_free(result);
      *(_QWORD *)(a1 + 8) = 0;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: PSOC MLME is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "psoc_mlme_ext_hdl_destroy");
    return 16;
  }
  return result;
}
