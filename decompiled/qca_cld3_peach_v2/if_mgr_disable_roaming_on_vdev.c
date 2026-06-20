__int64 __fastcall if_mgr_disable_roaming_on_vdev(
        __int64 result,
        __int64 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  unsigned int v12; // w19
  __int64 v13; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v11 = *(_QWORD *)(result + 80);
  if ( v11 )
  {
    v12 = *(unsigned __int8 *)(a2 + 168);
    if ( *((unsigned __int8 *)a3 + 4) != v12 && !*(_DWORD *)(a2 + 16) && *(_DWORD *)(a2 + 20) == 3 )
    {
      v13 = result;
      if ( wlan_cm_is_vdev_roaming(a2, a4, a5, a6, a7, a8, a9, a10, a11) || (mlo_is_link_recfg_in_progress(a2) & 1) != 0 )
      {
        return mlme_set_rso_pending_disable_req_bitmap(v11, v12, *a3, 0);
      }
      else
      {
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: Roaming disabled on vdev_id %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "if_mgr_disable_roaming_on_vdev",
          v12);
        return wlan_cm_disable_rso(v13, v12, *a3, 48);
      }
    }
  }
  return result;
}
