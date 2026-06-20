__int64 __fastcall lim_sap_move_to_cac_wait_state(
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
  return wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(a1 + 16), 0xAu, 0x2A28u, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
