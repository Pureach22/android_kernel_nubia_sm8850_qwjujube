__int64 __fastcall lim_process_sme_set_addba_accept(
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
  __int64 v10; // x29
  __int64 v11; // x30

  if ( !a2 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Msg Buffer is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_process_sme_set_addba_accept",
             v10,
             v11);
  if ( *(_BYTE *)(a2 + 1) )
    *(_BYTE *)(result + 21621) = 0;
  else
    *(_BYTE *)(result + 21621) = 1;
  return result;
}
