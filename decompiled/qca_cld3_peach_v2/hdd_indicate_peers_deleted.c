__int64 __fastcall hdd_indicate_peers_deleted(
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
  _QWORD *link_info_from_vdev; // x0
  _QWORD *v11; // x19
  const char *v12; // x2

  if ( a1 )
  {
    link_info_from_vdev = (_QWORD *)wlan_hdd_get_link_info_from_vdev(a1, a2);
    if ( link_info_from_vdev )
    {
      v11 = link_info_from_vdev;
      if ( !(unsigned int)_hdd_validate_adapter(*link_info_from_vdev, "hdd_indicate_peers_deleted") )
        return hdd_sap_indicate_disconnect_for_sta(*v11);
    }
    v12 = "%s: invalid vdev or adapter";
  }
  else
  {
    v12 = "%s: psoc obj is NULL";
  }
  return qdf_trace_msg(0x33u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_indicate_peers_deleted");
}
