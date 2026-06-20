__int64 __fastcall wma_send_vdev_down_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0

  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * *(unsigned __int8 *)(a2 + 4));
  if ( (*(_DWORD *)(v11 + 16) & 0xFFFFFFFD) != 0 )
    return wlan_vdev_mlme_sm_deliver_evt(v11, 0x1Au, 8u, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  wlan_cm_bss_peer_delete_rsp(v11, *(_DWORD *)a2, a3, a4, a5, a6, a7, a8, a9, a10);
  return _qdf_mem_free(a2);
}
