__int64 __fastcall wlan_cm_sta_mlme_vdev_roam_notify(__int64 a1, unsigned __int16 a2, __int64 a3)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w19

  result = cm_roam_sync_event_handler_cb(*(_QWORD *)(a1 + 504), a3, a2);
  if ( (_DWORD)result )
  {
    v12 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to process roam synch event",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_cm_sta_mlme_vdev_roam_notify");
    return v12;
  }
  return result;
}
