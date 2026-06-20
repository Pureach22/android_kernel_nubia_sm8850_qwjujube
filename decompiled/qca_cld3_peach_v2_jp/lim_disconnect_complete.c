__int64 __fastcall lim_disconnect_complete(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  __int64 result; // x0
  __int64 v12; // x20

  v10 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(v10 + 24) == 15 )
    return wlan_vdev_mlme_sm_deliver_evt(v10, 0x1Du, 0x2A28u, a1, a2, a3, a4, a5, a6, a7, a8, a9);
  v12 = *(_QWORD *)(a1 + 8608);
  result = wlan_vdev_mlme_sm_deliver_evt(v10, 0x11u, 0x2A28u, a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (_DWORD)result )
    return lim_send_stop_bss_failure_resp(v12, a1);
  return result;
}
