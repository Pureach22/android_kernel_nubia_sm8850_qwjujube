__int64 __fastcall sme_set_neighbor_lookup_rssi_threshold(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0

  if ( (unsigned __int8)a2 < 6u )
  {
    result = qdf_mutex_acquire(a1 + 12776);
    if ( !(_DWORD)result )
    {
      cm_neighbor_roam_update_config(*(_QWORD *)(a1 + 21560), a2, a3, 3u);
      qdf_mutex_release(a1 + 12776);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid vdev_id: %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_set_neighbor_lookup_rssi_threshold");
    return 4;
  }
  return result;
}
