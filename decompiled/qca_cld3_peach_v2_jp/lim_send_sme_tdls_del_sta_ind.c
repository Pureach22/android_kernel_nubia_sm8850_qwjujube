__int64 __fastcall lim_send_sme_tdls_del_sta_ind(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        unsigned __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x0
  __int64 result; // x0
  char v17; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v18[11]; // [xsp+9h] [xbp-17h] BYREF
  int v19; // [xsp+14h] [xbp-Ch]

  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Delete TDLS Peer %02x:%02x:%02x:**:**:%02xwith reason code: %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_send_sme_tdls_del_sta_ind",
    a2[338],
    a2[339],
    a2[340],
    a2[343],
    a4,
    0,
    0,
    *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808));
  v17 = *(_BYTE *)(a3 + 10);
  qdf_mem_copy(v18, a2 + 338, 6u);
  v15 = *(_QWORD *)(a1 + 21552);
  *(_WORD *)&v18[7] = 2;
  v19 = 6;
  result = tgt_tdls_event_handler(v15, &v17);
  _ReadStatusReg(SP_EL0);
  return result;
}
