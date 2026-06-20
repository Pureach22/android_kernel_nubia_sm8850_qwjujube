unsigned __int64 __fastcall hdd_sysfs_dp_txrx_stats_store(
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
        __int64 a11,
        unsigned __int64 a12)
{
  _QWORD *context; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _QWORD *v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD *v42; // x22
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  char *v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  const char *v60; // x2
  __int64 v61; // x20
  char *v62; // x0
  char *v63; // x0
  _DWORD *v64; // x8
  __int64 v65; // x1
  __int64 v66; // x2
  __int64 v67; // x3
  __int64 v68; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int8 v69[4]; // [xsp+14h] [xbp-2Ch] BYREF
  __int64 v70; // [xsp+18h] [xbp-28h] BYREF
  char *stringp; // [xsp+20h] [xbp-20h] BYREF
  _QWORD v72[3]; // [xsp+28h] [xbp-18h] BYREF

  v72[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dp_txrx_stats_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v68 = 0;
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_dp_txrx_stats_store",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22);
  if ( !v23 )
  {
    v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v68, (__int64)"hdd_sysfs_dp_txrx_stats_store");
    if ( !v23 )
    {
      memset(v72, 0, 11);
      v70 = 0;
      v69[0] = 0;
      v33 = _cds_get_context(71, (__int64)"__hdd_wlan_txrx_stats_store", v24, v25, v26, v27, v28, v29, v30, v31);
      if ( v33 )
      {
        if ( a12 <= 0xA )
        {
          v42 = v33;
          if ( wlan_hdd_validate_modules_state((__int64)context, v34, v35, v36, v37, v38, v39, v40, v41)
            && !(unsigned int)hdd_sysfs_validate_and_copy_buf(
                                (__int64)v72,
                                11,
                                a11,
                                a12,
                                v43,
                                v44,
                                v45,
                                v46,
                                v47,
                                v48,
                                v49,
                                v50) )
          {
            stringp = (char *)v72;
            v51 = strsep(&stringp, " ");
            if ( v51 )
            {
              if ( (unsigned int)kstrtouint(v51, 0, (char *)&v70 + 4) )
              {
                v60 = "%s: invalid stat type";
              }
              else
              {
                v62 = strsep(&stringp, " ");
                if ( v62 )
                {
                  if ( (unsigned int)kstrtouint(v62, 0, &v70) )
                  {
                    v60 = "%s: invalid mac_id";
                  }
                  else
                  {
                    v63 = strsep(&stringp, " ");
                    if ( !v63 || (unsigned int)kstrtou8(v63, 0, v69) )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: no vdev_id or invalid vdev_id",
                        v52,
                        v53,
                        v54,
                        v55,
                        v56,
                        v57,
                        v58,
                        v59,
                        "__hdd_wlan_txrx_stats_store");
                      v69[0] = -1;
                    }
                    v64 = *(_DWORD **)(*(_QWORD *)*v42 + 880LL);
                    if ( v64 )
                    {
                      v66 = (unsigned int)v70;
                      v65 = HIDWORD(v70);
                      v67 = v69[0];
                      if ( *(v64 - 1) != 1260721249 )
                        __break(0x8228u);
                      ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64))v64)(v42, v65, v66, v67);
                      goto LABEL_17;
                    }
                    v60 = "%s: txrx_sysfs_set_stat_type is NULL";
                  }
                }
                else
                {
                  v60 = "%s: no mac_id";
                }
              }
            }
            else
            {
              v60 = "%s: no stat type";
            }
            qdf_trace_msg(0x33u, 2u, v60, v52, v53, v54, v55, v56, v57, v58, v59, "__hdd_wlan_txrx_stats_store");
          }
        }
      }
      else
      {
        v61 = jiffies;
        if ( _hdd_wlan_txrx_stats_store___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: soc is NULL",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "__hdd_wlan_txrx_stats_store");
          _hdd_wlan_txrx_stats_store___last_ticks = v61;
        }
      }
      a12 = -22;
LABEL_17:
      _osif_psoc_sync_op_stop(v68, (__int64)"hdd_sysfs_dp_txrx_stats_store");
      goto LABEL_4;
    }
  }
  a12 = v23;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return a12;
}
