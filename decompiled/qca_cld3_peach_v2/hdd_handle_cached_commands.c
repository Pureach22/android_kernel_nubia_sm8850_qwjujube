_QWORD *hdd_handle_cached_commands()
{
  __int64 vdev_sync_arr; // x19
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  _QWORD *result; // x0
  __int64 i; // x24
  __int64 *v11; // x22
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x23
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  vdev_sync_arr = osif_get_vdev_sync_arr();
  result = _cds_get_context(51, (__int64)"hdd_handle_cached_commands", v1, v2, v3, v4, v5, v6, v7, v8);
  if ( result )
  {
    for ( i = 0; i != 144; i += 24 )
    {
      v11 = (__int64 *)(vdev_sync_arr + i);
      if ( vdev_sync_arr + i )
      {
        if ( *(_BYTE *)(vdev_sync_arr + i + 16) == 1 )
        {
          result = (_QWORD *)osif_vdev_get_cached_cmd(vdev_sync_arr + i);
          v20 = *v11;
          if ( *v11 )
          {
            if ( (unsigned __int8)result == 1 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Handling cached interface down command for %s",
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                "hdd_handle_cached_commands",
                *(_QWORD *)(v20 + 2720) + 296LL);
              if ( (*(_DWORD *)(v20 + 2728) | 2) == 3 )
                hdd_hostapd_stop_no_trans((_QWORD *)v20, v21, v22, v23, v24, v25, v26, v27, v28);
              else
                hdd_stop_no_trans(v20, v21, v22, v23, v24, v25, v26, v27, v28);
              result = (_QWORD *)osif_vdev_cache_command(vdev_sync_arr + i, 0);
            }
          }
        }
      }
    }
  }
  return result;
}
