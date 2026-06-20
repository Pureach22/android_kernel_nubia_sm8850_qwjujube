__int64 __fastcall lim_send_beacon(
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
  __int64 v10; // x8
  __int64 v12; // x0
  unsigned int v13; // w1
  __int64 result; // x0

  v10 = *(_QWORD *)(a2 + 16);
  if ( *(_DWORD *)(v10 + 20) == 2 )
  {
    v12 = *(_QWORD *)(a2 + 16);
    v13 = 11;
  }
  else if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3169LL) == 1 && *(_DWORD *)(v10 + 24) == 14 )
  {
    v12 = *(_QWORD *)(a2 + 16);
    v13 = 30;
  }
  else
  {
    result = wlan_vdev_is_up_active_state(*(_QWORD *)(a2 + 16));
    if ( !(_DWORD)result )
      return result;
    v12 = *(_QWORD *)(a2 + 16);
    v13 = 7;
  }
  return wlan_vdev_mlme_sm_deliver_evt(v12, v13, 0x2A28u, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
