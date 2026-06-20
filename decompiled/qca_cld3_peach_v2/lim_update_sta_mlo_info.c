__int64 __fastcall lim_update_sta_mlo_info(
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
  char is_mlo_recv_assoc; // w0
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0

  if ( *(_BYTE *)(a2 + 256) != 1 || (lim_is_mlo_conn(a1, a3) & 1) == 0 )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: is not mlo capable",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_update_sta_mlo_info");
  qdf_mem_copy((void *)(a2 + 366), a3 + 540, 6u);
  is_mlo_recv_assoc = lim_is_mlo_recv_assoc(a3);
  v14 = *(unsigned __int8 *)(a2 + 366);
  v15 = *(unsigned __int8 *)(a2 + 367);
  v16 = *(unsigned __int8 *)(a2 + 368);
  v17 = *(unsigned __int8 *)(a2 + 371);
  *(_BYTE *)(a2 + 372) = is_mlo_recv_assoc & 1;
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: mld mac %02x:%02x:%02x:**:**:%02x assoc peer %d",
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             "lim_update_sta_mlo_info",
             v14,
             v15,
             v16,
             v17,
             is_mlo_recv_assoc & 1);
  *(_WORD *)(a2 + 380) = a3[632];
  *(_WORD *)(a2 + 382) = a3[633];
  return result;
}
