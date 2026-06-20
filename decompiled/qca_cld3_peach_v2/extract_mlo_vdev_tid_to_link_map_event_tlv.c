__int64 __fastcall extract_mlo_vdev_tid_to_link_map_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v11; // x8
  __int64 v13; // x20

  if ( a10 )
  {
    v11 = *a10;
    *(_BYTE *)a11 = *(_DWORD *)(*a10 + 4);
    *(_DWORD *)(a11 + 4) = *(_DWORD *)(v11 + 8);
    *(_DWORD *)(a11 + 8) = *(_DWORD *)(v11 + 12);
    return 0;
  }
  else
  {
    v13 = jiffies;
    if ( extract_mlo_vdev_tid_to_link_map_event_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Param_buf is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_vdev_tid_to_link_map_event_tlv");
      extract_mlo_vdev_tid_to_link_map_event_tlv___last_ticks = v13;
    }
    return 16;
  }
}
