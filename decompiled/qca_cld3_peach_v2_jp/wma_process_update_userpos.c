__int64 __fastcall wma_process_update_userpos(
        __int64 *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  qdf_trace_msg(0x36u, 8u, "%s: userPos = %x ", a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_update_userpos", *a2);
  wma_set_peer_param(a1, (__int64)a2 + 6, 8u, *a2, *((unsigned __int16 *)a2 + 2));
  return wma_set_ppsconfig(*((_BYTE *)a2 + 4), 2, 1u, v12, v13, v14, v15, v16, v17, v18, v19);
}
