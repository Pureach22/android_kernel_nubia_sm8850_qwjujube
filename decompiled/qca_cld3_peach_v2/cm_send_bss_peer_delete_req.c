__int64 __fastcall cm_send_bss_peer_delete_req(
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
  _QWORD *context; // x0
  _QWORD *v11; // x19
  unsigned int v12; // w20

  context = _cds_get_context(54, (__int64)"cm_send_bss_peer_delete_req", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v11 = context;
  v12 = *(unsigned __int8 *)(a1 + 168);
  if ( (unsigned int)wlan_vdev_mlme_is_init_state(a1) )
    return wma_delete_peer_on_vdev_stop(v11, v12);
  wma_remove_bss_peer_on_failure(v11, v12);
  return 0;
}
