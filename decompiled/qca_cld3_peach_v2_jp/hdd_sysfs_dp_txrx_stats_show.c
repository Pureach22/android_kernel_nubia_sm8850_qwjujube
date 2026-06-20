__int64 __fastcall hdd_sysfs_dp_txrx_stats_show(
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
        const char *a11)
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
  _QWORD *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _DWORD *v39; // x8
  __int64 v40; // x19
  __int64 v41; // x20
  __int64 v42; // x20
  __int64 v43; // [xsp+0h] [xbp-10h] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dp_txrx_stats_show", a1, a2, a3, a4, a5, a6, a7, a8);
  v43 = 0;
  LODWORD(result) = _wlan_hdd_validate_context(
                      (__int64)context,
                      (__int64)"hdd_sysfs_dp_txrx_stats_show",
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20);
  if ( !(_DWORD)result )
  {
    LODWORD(result) = _osif_psoc_sync_op_start(
                        *(_QWORD *)(context[3] + 488LL),
                        &v43,
                        (__int64)"hdd_sysfs_dp_txrx_stats_show");
    if ( !(_DWORD)result )
    {
      v30 = _cds_get_context(71, (__int64)"__hdd_wlan_txrx_stats_show", v22, v23, v24, v25, v26, v27, v28, v29);
      if ( v30 )
      {
        v39 = *(_DWORD **)(*(_QWORD *)*v30 + 872LL);
        if ( v39 )
        {
          if ( *(v39 - 1) != 1601079185 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, const char *))v39)(v30, a11);
          v40 = (unsigned int)strlen(a11);
          goto LABEL_15;
        }
        v42 = jiffies;
        if ( _hdd_wlan_txrx_stats_show___last_ticks_6 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: txrx_sysfs_fill_stats is NULL",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "__hdd_wlan_txrx_stats_show",
            v43,
            v44);
          _hdd_wlan_txrx_stats_show___last_ticks_6 = v42;
        }
      }
      else
      {
        v41 = jiffies;
        if ( _hdd_wlan_txrx_stats_show___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: hdd dp_soc cds_get_context returned NULL",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "__hdd_wlan_txrx_stats_show",
            v43,
            v44);
          _hdd_wlan_txrx_stats_show___last_ticks = v41;
        }
      }
      v40 = -22;
LABEL_15:
      _osif_psoc_sync_op_stop(v43, (__int64)"hdd_sysfs_dp_txrx_stats_show");
      result = v40;
      goto LABEL_4;
    }
  }
  result = (int)result;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
