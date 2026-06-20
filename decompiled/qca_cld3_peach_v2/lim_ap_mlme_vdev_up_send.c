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
        __int64 a11)
{
  __int64 session_by_vdev_id; // x19
  __int64 result; // x0
  __int64 v14; // x0
  int v15; // w9
  _QWORD *context; // x0
  const char *v17; // x2
  _QWORD v18[7]; // [xsp+8h] [xbp-38h] BYREF

  session_by_vdev_id = a11;
  v18[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v18, 0, 48);
  if ( !a11 )
  {
    context = _cds_get_context(53, (__int64)"lim_ap_mlme_vdev_up_send", a2, a3, a4, a5, a6, a7, a8, a9);
    if ( context )
    {
      session_by_vdev_id = pe_find_session_by_vdev_id(
                             (__int64)context,
                             *(_BYTE *)(*(_QWORD *)(a1 + 520) + 168LL),
                             a2,
                             a3,
                             a4,
                             a5,
                             a6,
                             a7,
                             a8,
                             a9);
      if ( session_by_vdev_id )
        goto LABEL_2;
      v17 = "%s: session is NULL";
    }
    else
    {
      v17 = "%s: mac ctx is null";
    }
    qdf_trace_msg(0x35u, 2u, v17, a2, a3, a4, a5, a6, a7, a8, a9, "lim_ap_mlme_vdev_up_send");
    result = 4;
    goto LABEL_13;
  }
LABEL_2:
  if ( *(_DWORD *)(session_by_vdev_id + 88) == 6 )
  {
    result = 0;
  }
  else
  {
    v14 = *(_QWORD *)(a1 + 520);
    if ( *(_DWORD *)(v14 + 16) != 1 || (wlan_vdev_mlme_is_mlo_vdev(v14, a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
      lim_configure_fd_for_existing_6ghz_sap(session_by_vdev_id, 1);
    v15 = *(unsigned __int8 *)(session_by_vdev_id + 10);
    LOWORD(v18[0]) = 4528;
    HIDWORD(v18[0]) = v15;
    result = scheduler_post_message_debug(
               0x35u,
               0x36u,
               54,
               (unsigned __int16 *)v18,
               0x2AA4u,
               (__int64)"lim_ap_mlme_vdev_up_send");
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
