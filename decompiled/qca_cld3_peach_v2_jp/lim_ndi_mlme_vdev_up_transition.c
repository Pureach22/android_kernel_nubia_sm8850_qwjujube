__int64 __fastcall lim_ndi_mlme_vdev_up_transition(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( *(_DWORD *)(result + 88) == 6 )
    return wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(result + 16), 7u, 0x2A28u, result, a2, a3, a4, a5, a6, a7, a8, a9);
  return result;
}
