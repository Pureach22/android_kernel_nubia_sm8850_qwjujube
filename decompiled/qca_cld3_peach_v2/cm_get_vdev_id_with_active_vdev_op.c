void __fastcall cm_get_vdev_id_with_active_vdev_op(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned __int8 *a11)
{
  int v11; // w20
  unsigned int v12; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x9
  unsigned __int8 *v24; // x8

  if ( a11 )
  {
    v11 = *(unsigned __int8 *)(a10 + 168);
    if ( *a11 != v11 )
    {
      v12 = *(_DWORD *)(a10 + 16);
      if ( (v12 & 0xFFFFFFFD) == 0 )
      {
        if ( (cm_is_vdev_disconnecting(a10) & 1) == 0 )
          return;
        v24 = a11;
        v23 = 2;
LABEL_12:
        v24[v23] = v11;
        return;
      }
      if ( v12 <= 0xB && ((1 << v12) & 0x80A) != 0 )
      {
        if ( wlan_ser_is_non_scan_cmd_type_in_vdev_queue(a10, 0x15u, a1, a2, a3, a4, a5, a6, a7, a8) )
        {
          v23 = 1;
          v24 = a11;
        }
        else
        {
          if ( !wlan_ser_is_non_scan_cmd_type_in_vdev_queue(a10, 0x16u, v15, v16, v17, v18, v19, v20, v21, v22) )
            return;
          v24 = a11;
          v23 = 1;
        }
        goto LABEL_12;
      }
    }
  }
}
