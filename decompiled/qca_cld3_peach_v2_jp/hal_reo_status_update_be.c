__int64 __fastcall hal_reo_status_update_be(
        __int64 a1,
        __int64 a2,
        unsigned __int16 *a3,
        int a4,
        _DWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  if ( a4 <= 286 )
  {
    switch ( a4 )
    {
      case 172:
        hal_reo_rx_update_queue_status_be(a2, a3, a1);
        goto LABEL_18;
      case 285:
        hal_reo_queue_stats_status_be(a2, a3, a1);
        goto LABEL_18;
      case 286:
        hal_reo_flush_queue_status_be(a2, a3, a1);
        goto LABEL_18;
    }
LABEL_14:
    qdf_trace_msg(0x86u, 3u, "hal_soc %pK: no handler for TLV:%d", a6, a7, a8, a9, a10, a11, a12, a13, a1);
    return 16;
  }
  if ( a4 > 305 )
  {
    if ( a4 == 306 )
    {
      hal_reo_flush_timeout_list_status_be(a2, a3, a1);
      goto LABEL_18;
    }
    if ( a4 == 307 )
    {
      hal_reo_desc_thres_reached_status_be(a2, a3, a1);
      goto LABEL_18;
    }
    goto LABEL_14;
  }
  if ( a4 == 287 )
  {
    hal_reo_flush_cache_status_be(a2, a3, a1);
    goto LABEL_18;
  }
  if ( a4 != 288 )
    goto LABEL_14;
  hal_reo_unblock_cache_status_be(a2, a1, a3);
LABEL_18:
  *a5 = *a3;
  return 0;
}
