__int64 __fastcall extract_mlo_vdev_bcast_tid_to_link_map_event_tlv(
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
        _BYTE *a11)
{
  unsigned int v11; // w4
  __int64 v14; // x23
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x24
  int v25; // w8

  if ( a10 )
  {
    v11 = *(_DWORD *)(a10 + 168);
    if ( v11 < 0x11 )
    {
      v14 = *(_QWORD *)(a10 + 160);
      if ( v14 )
      {
        *a11 = v11;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: num_vdevs:%d",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "extract_mlo_vdev_bcast_tid_to_link_map_event_tlv");
        if ( *(_DWORD *)(a10 + 168) )
        {
          v24 = 0;
          do
          {
            if ( v24 == 16 )
            {
              __break(0x5512u);
              JUMPOUT(0x6CD8EC);
            }
            v25 = *(_DWORD *)(v14 + 4);
            a11[v24 + 1] = v25;
            *(_DWORD *)&a11[4 * v24 + 20] = *(_DWORD *)(v14 + 4) >> 8;
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: vdev_id:%d expected_duration:%d",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "extract_mlo_vdev_bcast_tid_to_link_map_event_tlv",
              (unsigned __int8)v25);
            ++v24;
          }
          while ( v24 < *(unsigned int *)(a10 + 168) );
        }
      }
      else
      {
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: mlo_bcast_t2lm_info is not applicable",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "extract_mlo_vdev_bcast_tid_to_link_map_event_tlv");
      }
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: num_mlo_bcast_t2lm_info is greater than %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_vdev_bcast_tid_to_link_map_event_tlv",
        16);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s:  MGMT RX param_tlvs is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_mlo_vdev_bcast_tid_to_link_map_event_tlv");
    return 4;
  }
}
