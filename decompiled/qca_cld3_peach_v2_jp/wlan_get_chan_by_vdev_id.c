__int64 __fastcall wlan_get_chan_by_vdev_id(
        __int64 a1,
        __int64 a2,
        _QWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x0
  __int64 v13; // x19
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20
  const char *v24; // x2
  __int64 *active_channel; // x0
  __int64 v26; // x10
  __int64 v27; // x11

  if ( !a1 )
  {
    v24 = "%s: psoc object is NULL";
LABEL_7:
    qdf_trace_msg(0x1Fu, 2u, v24, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_get_chan_by_vdev_id");
    return 4;
  }
  v12 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 7);
  if ( !v12 )
  {
    v24 = "%s: vdev object is NULL";
    goto LABEL_7;
  }
  v13 = v12;
  if ( (unsigned int)wlan_vdev_mlme_is_active(v12)
    || (active_channel = (__int64 *)wlan_vdev_get_active_channel(v13)) == nullptr )
  {
    v23 = 4;
  }
  else
  {
    v14 = (unsigned int *)active_channel[3];
    v23 = 0;
    v26 = *active_channel;
    v27 = active_channel[1];
    a3[2] = active_channel[2];
    a3[3] = v14;
    *a3 = v26;
    a3[1] = v27;
  }
  wlan_objmgr_vdev_release_ref(v13, 7u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  return v23;
}
