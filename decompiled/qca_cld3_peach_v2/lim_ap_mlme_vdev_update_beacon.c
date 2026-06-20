__int64 __fastcall lim_ap_mlme_vdev_update_beacon(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 session_by_vdev_id)
{
  __int64 result; // x0
  int v14; // w19
  _QWORD *context; // x0
  const char *v16; // x2
  int v17; // w9
  _QWORD v18[7]; // [xsp+8h] [xbp-38h] BYREF

  v18[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( session_by_vdev_id )
    goto LABEL_2;
  v14 = a2;
  context = _cds_get_context(53, (__int64)"lim_ap_mlme_vdev_update_beacon", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v16 = "%s: mac ctx is null";
    goto LABEL_12;
  }
  session_by_vdev_id = pe_find_session_by_vdev_id(
                         (__int64)context,
                         *(_BYTE *)(*(_QWORD *)(a1 + 520) + 168LL),
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10);
  a2 = v14;
  if ( !session_by_vdev_id )
  {
    v16 = "%s: session is NULL";
LABEL_12:
    qdf_trace_msg(0x35u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "lim_ap_mlme_vdev_update_beacon");
    result = 4;
    goto LABEL_13;
  }
LABEL_2:
  if ( *(_DWORD *)(session_by_vdev_id + 88) != 6 )
  {
    switch ( a2 )
    {
      case 3:
        memset(v18, 0, 48);
        v17 = *(unsigned __int8 *)(session_by_vdev_id + 10);
        LOWORD(v18[0]) = 5269;
        HIDWORD(v18[0]) = v17;
        scheduler_post_message_debug(
          0x35u,
          0x34u,
          52,
          (unsigned __int16 *)v18,
          0x2A5Au,
          (__int64)"lim_send_csa_restart_resp");
        break;
      case 2:
        lim_send_beacon_ind(
          *(_QWORD *)(session_by_vdev_id + 8608),
          session_by_vdev_id,
          2u,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10);
        break;
      case 0:
        lim_send_beacon_ind(
          *(_QWORD *)(session_by_vdev_id + 8608),
          session_by_vdev_id,
          0,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10);
        break;
    }
  }
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
