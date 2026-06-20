__int64 __fastcall _lim_process_send_disassoc_frame(
        __int64 a1,
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
  int v11; // w8
  char *v12; // x20
  __int64 session_by_vdev_id; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  const char *v25; // x2

  if ( !a2 )
  {
    v25 = "%s: NULL req";
    return qdf_trace_msg(0x35u, 2u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "__lim_process_send_disassoc_frame");
  }
  v12 = (char *)a2 + 5;
  v11 = *((unsigned __int8 *)a2 + 5);
  if ( (v11 & 1) != 0
    && (v11 != 255
     || *((unsigned __int8 *)a2 + 6) != 255
     || *((unsigned __int8 *)a2 + 7) != 255
     || *((unsigned __int8 *)a2 + 8) != 255
     || *((unsigned __int8 *)a2 + 9) != 255
     || *((unsigned __int8 *)a2 + 10) != 255) )
  {
    v25 = "%s: received invalid SME_DISASSOC_REQ message";
    return qdf_trace_msg(0x35u, 2u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "__lim_process_send_disassoc_frame");
  }
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, *((unsigned __int8 *)a2 + 4));
  if ( !session_by_vdev_id )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: session does not exist for given bssId %02x:%02x:%02x:**:**:%02x",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "__lim_process_send_disassoc_frame",
             *((unsigned __int8 *)a2 + 5),
             *((unsigned __int8 *)a2 + 6),
             *((unsigned __int8 *)a2 + 7),
             *((unsigned __int8 *)a2 + 10));
  v23 = session_by_vdev_id;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: msg_type %d len %d vdev_id %d mac: %02x:%02x:%02x:**:**:%02x reason %d wait_for_ack %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "__lim_process_send_disassoc_frame",
    *a2,
    a2[1],
    *((unsigned __int8 *)a2 + 4),
    *((unsigned __int8 *)a2 + 5),
    *((unsigned __int8 *)a2 + 6),
    *((unsigned __int8 *)a2 + 7),
    *((unsigned __int8 *)a2 + 10),
    a2[6],
    *((unsigned __int8 *)a2 + 14));
  return lim_send_disassoc_mgmt_frame(a1, a2[6], v12, v23, *((_BYTE *)a2 + 14) != 0);
}
