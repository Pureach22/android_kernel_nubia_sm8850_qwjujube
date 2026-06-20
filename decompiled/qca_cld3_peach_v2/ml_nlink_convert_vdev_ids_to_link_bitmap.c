__int64 __fastcall ml_nlink_convert_vdev_ids_to_link_bitmap(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
{
  unsigned int v5; // w20
  __int64 v6; // x25
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w8
  unsigned int *v17; // x8
  __int64 v18; // x27

  if ( a3 )
  {
    v5 = 0;
    v6 = a3;
    do
    {
      v7 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 24);
      if ( v7 )
      {
        v16 = *(unsigned __int8 *)(v7 + 93);
        if ( v16 == 255 )
        {
          v18 = v7;
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: vdev %d has invalid link id %d",
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            "ml_nlink_convert_vdev_ids_to_link_bitmap",
            *a2,
            255);
          v7 = v18;
        }
        else
        {
          v17 = (unsigned int *)(unsigned int)(1 << v16);
          v5 |= (unsigned int)v17;
        }
        wlan_objmgr_vdev_release_ref(v7, 0x18u, v17, v8, v9, v10, v11, v12, v13, v14, v15);
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: vdev not found for vdev_id %d ",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "ml_nlink_convert_vdev_ids_to_link_bitmap",
          *a2);
      }
      --v6;
      ++a2;
    }
    while ( v6 );
  }
  else
  {
    return 0;
  }
  return v5;
}
