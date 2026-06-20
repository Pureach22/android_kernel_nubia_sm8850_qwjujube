_QWORD *__fastcall hdd_abort_ongoing_sta_sae_connection(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *result; // x0
  _QWORD *v10; // x19
  _QWORD *v11; // x21
  unsigned int param; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21

  result = (_QWORD *)hdd_get_sta_connection_in_progress(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v10 = result;
    if ( (*(_BYTE *)(result[4] + 67LL) & 2) == 0 )
    {
      result = (_QWORD *)_hdd_objmgr_get_vdev_by_user(
                           *(_QWORD *)(*result + 52832LL),
                           6,
                           "hdd_abort_ongoing_sta_sae_connection");
      if ( result )
      {
        v11 = result;
        param = wlan_crypto_get_param((__int64)result, 7u);
        result = (_QWORD *)_hdd_objmgr_put_vdev_by_user(v11, 6, "hdd_abort_ongoing_sta_sae_connection");
        if ( (param & 0x80000000) != 0 )
        {
          v21 = jiffies;
          if ( hdd_abort_ongoing_sta_sae_connection___last_ticks - jiffies + 125 < 0 )
          {
            result = (_QWORD *)qdf_trace_msg(
                                 0x33u,
                                 8u,
                                 "%s: Invalid key_mgmt: %d",
                                 v13,
                                 v14,
                                 v15,
                                 v16,
                                 v17,
                                 v18,
                                 v19,
                                 v20,
                                 "hdd_abort_ongoing_sta_sae_connection",
                                 param);
            hdd_abort_ongoing_sta_sae_connection___last_ticks = v21;
          }
        }
        else if ( (param & 0x18000C00) != 0 )
        {
          return (_QWORD *)wlan_hdd_cm_issue_disconnect(*(_QWORD *)(*v10 + 52832LL), 8, 0);
        }
      }
    }
  }
  return result;
}
