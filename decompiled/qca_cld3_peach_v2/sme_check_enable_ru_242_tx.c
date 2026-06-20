__int64 __fastcall sme_check_enable_ru_242_tx(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  result = qdf_trace_msg(
             0x34u,
             8u,
             "%s: Config VDEV for RU 242 Tx, usr cfg %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "sme_check_enable_ru_242_tx",
             *(unsigned __int8 *)(a1 + 21784));
  if ( *(_BYTE *)(a1 + 21784) )
  {
    result = wma_cli_set_command(a2, 21, 0, 1);
    if ( (_DWORD)result )
      return qdf_trace_msg(
               0x34u,
               2u,
               "%s: Failed to set VDEV BW to 20MHz",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "sme_check_enable_ru_242_tx");
  }
  return result;
}
