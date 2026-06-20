bool __fastcall p2p_is_vdev_wfd_r2_mode(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 216);
  if ( v1 )
    v1 = *(_QWORD *)(v1 + 80);
  return (unsigned __int8)(wlan_get_wfd_mode_from_vdev_id(v1, *(unsigned __int8 *)(a1 + 168)) - 1) < 2u;
}
