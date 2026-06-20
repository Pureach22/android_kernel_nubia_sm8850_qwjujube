unsigned __int64 __fastcall hdd_sysfs_dump_dp_trace_store(
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
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w20
  __int64 v51; // x21
  char *v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  char *v69; // x0
  __int64 v70; // x20
  __int64 v71; // [xsp+8h] [xbp-48h] BYREF
  unsigned int v72; // [xsp+14h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v74[4]; // [xsp+20h] [xbp-30h] BYREF
  char v75; // [xsp+40h] [xbp-10h]
  __int64 v76; // [xsp+48h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dump_dp_trace_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_dump_dp_trace_store",
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
    v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v71, (__int64)"hdd_sysfs_dump_dp_trace_store");
    if ( !v23 )
    {
      v75 = 0;
      memset(v74, 0, sizeof(v74));
      v72 = 0;
      if ( wlan_hdd_validate_modules_state((__int64)context, v24, v25, v26, v27, v28, v29, v30, v31) )
      {
        v41 = hdd_sysfs_validate_and_copy_buf((__int64)v74, 33, a11, a12, v33, v34, v35, v36, v37, v38, v39, v40);
        if ( v41 )
        {
          v50 = v41;
          v51 = jiffies;
          if ( _hdd_sysfs_dump_dp_trace_store___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid input",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "__hdd_sysfs_dump_dp_trace_store");
            _hdd_sysfs_dump_dp_trace_store___last_ticks = v51;
          }
          a12 = v50;
          goto LABEL_13;
        }
        stringp = (char *)v74;
        v52 = strsep(&stringp, " ");
        if ( v52 )
        {
          if ( !(unsigned int)kstrtouint(v52, 0, &v72) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: dump_dp_trace %d",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "__hdd_sysfs_dump_dp_trace_store",
              v72);
            switch ( v72 )
            {
              case 2u:
                v69 = strsep(&stringp, " ");
                if ( v69 && !(unsigned int)kstrtouint(v69, 0, &dump_dp_trace_count) )
                  goto LABEL_13;
                break;
              case 1u:
                qdf_dp_trace_enable_live_mode();
                goto LABEL_13;
              case 0u:
                qdf_dp_trace_disable_live_mode();
                goto LABEL_13;
              default:
                v70 = jiffies;
                if ( _hdd_sysfs_dump_dp_trace_store___last_ticks_12 - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: invalid input",
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    v68,
                    "__hdd_sysfs_dump_dp_trace_store");
                  _hdd_sysfs_dump_dp_trace_store___last_ticks_12 = v70;
                }
                break;
            }
          }
        }
      }
      a12 = -22;
LABEL_13:
      _osif_psoc_sync_op_stop(v71, (__int64)"hdd_sysfs_dump_dp_trace_store");
      goto LABEL_4;
    }
  }
  a12 = v23;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return a12;
}
