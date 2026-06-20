__int64 __fastcall hdd_check_and_set_tdls_disconn_params(
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
  __int64 v9; // x8
  __int64 v10; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w8

  v9 = *(_QWORD *)(result + 216);
  if ( v9 )
  {
    v10 = *(_QWORD *)(v9 + 80);
    if ( v10 )
    {
      result = wlan_hdd_get_link_info_from_vdev(a2, a3, a4, a5, a6, a7, a8, a9, v10, *(_BYTE *)(result + 168));
      if ( result )
      {
        v19 = *(_DWORD *)(result + 688);
        if ( v19 > 0xB || ((1 << v19) & 0xFB0) == 0 )
          return hdd_cm_netif_queue_enable(*(_QWORD *)result, v11, v12, v13, v14, v15, v16, v17, v18);
      }
    }
  }
  return result;
}
