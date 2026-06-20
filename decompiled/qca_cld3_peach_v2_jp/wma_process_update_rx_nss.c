__int64 __fastcall wma_process_update_rx_nss(
        __int64 *a1,
        unsigned __int16 *a2,
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
  __int64 v11; // x8
  int v12; // w8
  unsigned int v13; // w11
  __int16 v14; // w10
  unsigned __int16 v16; // w8

  v10 = a1[3];
  if ( !v10 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: target psoc info is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wma_process_update_rx_nss");
  v11 = *(_QWORD *)(v10 + 2800);
  if ( !v11 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: target psoc info is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wma_process_update_rx_nss");
  v12 = *(_DWORD *)(v11 + 688);
  v13 = *a2;
  if ( v12 >= 2 )
    v14 = 2;
  else
    v14 = v12;
  if ( v12 < (int)v13 || v13 > 2 )
    v16 = v14;
  else
    v16 = *a2;
  *(_BYTE *)(a1[65] + 488LL * a2[1] + 236) = v16;
  *a2 = v16;
  qdf_trace_msg(0x36u, 8u, "%s: Rx Nss = %d", a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_update_rx_nss", v16);
  return wma_set_peer_param(a1, (__int64)(a2 + 2), 5u, *a2, a2[1]);
}
