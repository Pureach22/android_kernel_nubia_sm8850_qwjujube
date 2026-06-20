__int64 __fastcall lim_ap_mlme_vdev_up_send(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 session_by_vdev_id)
{
  __int64 result; // x0
  __int64 v12; // x19
  int v13; // w9
  _QWORD *context; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  _QWORD v25[7]; // [xsp+8h] [xbp-38h] BYREF

  v25[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v25, 0, 48);
  if ( session_by_vdev_id )
    goto LABEL_2;
  context = _cds_get_context(53, (__int64)"lim_ap_mlme_vdev_up_send", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v24 = "%s: mac ctx is null";
    goto LABEL_9;
  }
  session_by_vdev_id = pe_find_session_by_vdev_id(
                         (__int64)context,
                         *(_BYTE *)(*(_QWORD *)(a1 + 504) + 104LL),
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23);
  if ( !session_by_vdev_id )
  {
    v24 = "%s: session is NULL";
LABEL_9:
    qdf_trace_msg(0x35u, 2u, v24, v16, v17, v18, v19, v20, v21, v22, v23, "lim_ap_mlme_vdev_up_send");
    result = 4;
    goto LABEL_10;
  }
LABEL_2:
  if ( *(_DWORD *)(session_by_vdev_id + 88) == 6 )
  {
    result = 0;
  }
  else
  {
    v12 = session_by_vdev_id;
    lim_configure_fd_for_existing_6ghz_sap(session_by_vdev_id, 1);
    v13 = *(unsigned __int8 *)(v12 + 10);
    LOWORD(v25[0]) = 4528;
    HIDWORD(v25[0]) = v13;
    result = scheduler_post_message_debug(
               0x35u,
               0x36u,
               54,
               (unsigned __int16 *)v25,
               0x2AA4u,
               (__int64)"lim_ap_mlme_vdev_up_send");
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
