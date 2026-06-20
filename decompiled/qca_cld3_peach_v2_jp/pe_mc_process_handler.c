__int64 __fastcall pe_mc_process_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0

  context = _cds_get_context(53, (__int64)"pe_mc_process_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return 16;
  if ( *(_DWORD *)context != 1 )
    lim_message_processor();
  return 0;
}
