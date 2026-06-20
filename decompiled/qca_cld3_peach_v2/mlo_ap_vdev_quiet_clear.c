__int64 __fastcall mlo_ap_vdev_quiet_clear(
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
  __int64 v9; // x19
  __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  unsigned __int8 v20; // w21
  __int64 v21; // x8
  __int64 v22; // x4

  v9 = *(_QWORD *)(result + 1360);
  if ( v9 )
  {
    v10 = result;
    if ( *(_DWORD *)(result + 16) == 1 )
    {
      result = wlan_vdev_mlme_is_mlo_vdev(result, a2, a3, a4, a5, a6, a7, a8, a9);
      if ( (result & 1) != 0 )
      {
        result = mlo_get_link_vdev_ix(v9, v10);
        if ( (_BYTE)result != 0xFF )
        {
          v19 = *(_QWORD *)(v10 + 216);
          v20 = result;
          if ( v19 && (v21 = *(_QWORD *)(v19 + 80)) != 0 )
            v22 = *(unsigned __int8 *)(v21 + 48);
          else
            v22 = 255;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Quiet clear for PSOC:%d vdev:%d",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            "mlo_ap_vdev_quiet_clear",
            v22,
            *(unsigned __int8 *)(v10 + 168));
          return wlan_util_change_map_index(*(_QWORD *)(v9 + 2232) + 80LL, v20, 0);
        }
      }
    }
  }
  return result;
}
