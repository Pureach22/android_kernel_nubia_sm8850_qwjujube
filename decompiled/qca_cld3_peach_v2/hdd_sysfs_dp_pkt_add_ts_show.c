__int64 __fastcall hdd_sysfs_dp_pkt_add_ts_show(
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
        __int64 a11)
{
  _QWORD *context; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x19
  __int64 v31[2]; // [xsp+0h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31[0] = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dp_pkt_add_ts_show", a1, a2, a3, a4, a5, a6, a7, a8);
  LODWORD(result) = _wlan_hdd_validate_context(
                      (__int64)context,
                      (__int64)"hdd_sysfs_dp_pkt_add_ts_show",
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20);
  if ( (_DWORD)result
    || (LODWORD(result) = _osif_psoc_sync_op_start(
                            *(_QWORD *)(context[3] + 488LL),
                            v31,
                            (__int64)"hdd_sysfs_dp_pkt_add_ts_show"),
        (_DWORD)result) )
  {
    result = (int)result;
  }
  else
  {
    if ( wlan_hdd_validate_modules_state((__int64)context, v22, v23, v24, v25, v26, v27, v28, v29) )
      v30 = (int)qdf_show_dp_pkt_add_ts_info(a11, 4096);
    else
      v30 = -22;
    _osif_psoc_sync_op_stop(v31[0], (__int64)"hdd_sysfs_dp_pkt_add_ts_show");
    result = v30;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
