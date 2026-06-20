unsigned __int64 __fastcall hdd_sysfs_rf_test_mode_store(
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
  __int64 *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 *v23; // x20
  int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x20
  __int64 v34; // x8
  int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w21
  __int64 v45; // x20
  __int64 v46; // x21
  char *v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w8
  __int64 v58; // [xsp+8h] [xbp-48h] BYREF
  unsigned int v59; // [xsp+14h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v61[4]; // [xsp+20h] [xbp-30h] BYREF
  char v62; // [xsp+40h] [xbp-10h]
  __int64 v63; // [xsp+48h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_rf_test_mode_store", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    v23 = context;
    v24 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488), &v58, (__int64)"hdd_sysfs_rf_test_mode_store");
    if ( v24 )
    {
      a12 = v24;
    }
    else
    {
      v62 = 0;
      memset(v61, 0, sizeof(v61));
      v34 = *v23;
      v59 = 0;
      if ( v34 )
      {
        v35 = hdd_sysfs_validate_and_copy_buf((__int64)v61, 33, a11, a12, v25, v26, v27, v28, v29, v30, v31, v32);
        if ( v35 )
        {
          v44 = v35;
          v45 = jiffies;
          if ( _hdd_sysfs_rf_test_mode_store___last_ticks_7 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid input",
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              "__hdd_sysfs_rf_test_mode_store");
            _hdd_sysfs_rf_test_mode_store___last_ticks_7 = v45;
          }
          a12 = v44;
        }
        else
        {
          stringp = (char *)v61;
          v47 = strsep(&stringp, " ");
          if ( v47 && !(unsigned int)kstrtouint(v47, 0, &v59) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: rf_test_mode: 0x%x",
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              "__hdd_sysfs_rf_test_mode_store",
              v59);
            v56 = v59;
            if ( v59 >= 2 )
            {
              v56 = 1;
              v59 = 1;
            }
            wlan_mlme_set_rf_test_mode_enabled(*v23, v56 != 0);
          }
          else
          {
            a12 = -22;
          }
        }
      }
      else
      {
        v46 = jiffies;
        if ( _hdd_sysfs_rf_test_mode_store___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid hdd ctx",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "__hdd_sysfs_rf_test_mode_store");
          a12 = 0;
          _hdd_sysfs_rf_test_mode_store___last_ticks = v46;
        }
        else
        {
          a12 = 0;
        }
      }
      _osif_psoc_sync_op_stop(v58, (__int64)"hdd_sysfs_rf_test_mode_store");
    }
  }
  else
  {
    v33 = jiffies;
    if ( hdd_sysfs_rf_test_mode_store___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: invalid input",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hdd_sysfs_rf_test_mode_store");
      hdd_sysfs_rf_test_mode_store___last_ticks = v33;
    }
    a12 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a12;
}
