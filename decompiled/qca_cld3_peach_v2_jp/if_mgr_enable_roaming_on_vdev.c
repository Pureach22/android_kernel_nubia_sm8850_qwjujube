__int64 __fastcall if_mgr_enable_roaming_on_vdev(
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
  __int64 v11; // x19
  unsigned int v12; // w20
  __int64 v13; // x21

  v11 = *(_QWORD *)(result + 80);
  if ( v11 )
  {
    if ( !*(_DWORD *)(a2 + 16) )
    {
      v12 = *(unsigned __int8 *)(a2 + 104);
      if ( *((unsigned __int8 *)a3 + 4) != v12 && *(_DWORD *)(a2 + 20) == 3 )
      {
        v13 = result;
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: Enable roaming for vdev_id %d, requestor %d",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_enable_roaming_on_vdev",
          *(unsigned __int8 *)(a2 + 104),
          *a3);
        mlme_set_rso_pending_disable_req_bitmap(v11, v12, *a3, 1);
        return wlan_cm_enable_rso(v13, v12, *a3, 43);
      }
    }
  }
  return result;
}
