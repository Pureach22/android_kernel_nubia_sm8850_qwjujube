__int64 __fastcall target_if_consume_sscan_summary_report_gen3(
        __int64 result,
        __int64 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x4

  if ( !result || !a2 || !a3 )
    return qdf_trace_msg(
             0x56u,
             2u,
             "%s: null arguments: data %pK, fields %pK, rparams %pK.",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "target_if_consume_sscan_summary_report_gen3",
             result,
             a2,
             a3);
  *(_BYTE *)a2 = *(_DWORD *)(result + 8);
  *(_WORD *)(a2 + 2) = (*(_DWORD *)(result + 8) >> 18) & 0x3FF;
  *(_BYTE *)(a2 + 5) = *(int *)(result + 8) < 0;
  v11 = *a3;
  if ( (_DWORD)v11 == 1 )
  {
    *(_BYTE *)(a2 + 4) = *(_BYTE *)(result + 22) & 1;
  }
  else if ( (_DWORD)v11 )
  {
    return qdf_trace_msg(
             0x56u,
             2u,
             "%s: Invalid spectral report format version: %d.",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "target_if_consume_sscan_summary_report_gen3",
             v11,
             a2,
             a3);
  }
  else
  {
    *(_BYTE *)(a2 + 4) = (*(_DWORD *)(result + 16) & 0x40000000) != 0;
  }
  return result;
}
