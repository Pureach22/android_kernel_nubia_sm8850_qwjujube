_QWORD *__fastcall target_if_psoc_spectral_init(
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
  _QWORD *result; // x0
  const char *v11; // x2

  if ( a1 )
  {
    result = (_QWORD *)_qdf_mem_malloc(0x70u, "target_if_psoc_spectral_init", 4231);
    if ( result )
    {
      *result = a1;
      return result;
    }
    v11 = "%s: Spectral lmac psoc object allocation failed";
  }
  else
  {
    v11 = "%s: psoc is null";
  }
  qdf_trace_msg(0x56u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_psoc_spectral_init");
  return nullptr;
}
