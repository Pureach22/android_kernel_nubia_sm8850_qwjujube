void *__fastcall sme_add_qcn_ie(
        __int64 a1,
        __int64 a2,
        _WORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v11; // x9
  void *result; // x0

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 3336LL) & 1) == 0 )
    return (void *)qdf_trace_msg(
                     0x34u,
                     8u,
                     "%s: QCN IE is not supported",
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     "sme_add_qcn_ie");
  v11 = (unsigned __int16)*a3;
  if ( v11 >= 0x7F7 )
    return (void *)qdf_trace_msg(
                     0x34u,
                     2u,
                     "%s: IE buffer not enough for QCN IE",
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     "sme_add_qcn_ie");
  result = qdf_mem_copy((void *)(a2 + v11), &sme_add_qcn_ie_qcn_ie, 0xAu);
  *a3 += 10;
  return result;
}
