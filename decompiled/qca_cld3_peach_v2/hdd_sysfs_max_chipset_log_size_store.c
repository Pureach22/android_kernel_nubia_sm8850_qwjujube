unsigned __int64 __fastcall hdd_sysfs_max_chipset_log_size_store(
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
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
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
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w21
  __int64 v52; // x20
  char *v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v63; // x23
  __int64 v64; // x20
  __int64 v65; // [xsp+8h] [xbp-48h] BYREF
  char *stringp; // [xsp+10h] [xbp-40h] BYREF
  unsigned int v67; // [xsp+1Ch] [xbp-34h] BYREF
  _QWORD v68[4]; // [xsp+20h] [xbp-30h] BYREF
  char v69; // [xsp+40h] [xbp-10h]
  __int64 v70; // [xsp+48h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_max_chipset_log_size_store", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    v23 = (__int64)context;
    v24 = _wlan_hdd_validate_context(
            (__int64)context,
            (__int64)"hdd_sysfs_max_chipset_log_size_store",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22);
    if ( v24
      || (v24 = _osif_psoc_sync_op_start(
                  *(_QWORD *)(*(_QWORD *)(v23 + 24) + 488LL),
                  &v65,
                  (__int64)"hdd_sysfs_max_chipset_log_size_store")) != 0 )
    {
      a12 = v24;
      goto LABEL_17;
    }
    v69 = 0;
    memset(v68, 0, sizeof(v68));
    v67 = 0;
    if ( wlan_hdd_validate_modules_state(v23, v25, v26, v27, v28, v29, v30, v31, v32) )
    {
      v42 = hdd_sysfs_validate_and_copy_buf((__int64)v68, 33, a11, a12, v34, v35, v36, v37, v38, v39, v40, v41);
      if ( v42 )
      {
        v51 = v42;
        v52 = jiffies;
        if ( _hdd_sysfs_max_chipset_log_size_store___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "__hdd_sysfs_max_chipset_log_size_store");
          _hdd_sysfs_max_chipset_log_size_store___last_ticks = v52;
        }
        a12 = v51;
        goto LABEL_16;
      }
      stringp = (char *)v68;
      v53 = strsep(&stringp, " ");
      if ( v53 )
      {
        if ( !(unsigned int)kstrtouint(v53, 0, &v67) )
        {
          v63 = jiffies;
          if ( _hdd_sysfs_max_chipset_log_size_store___last_ticks_46 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: max_chipset_log_size %d",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "__hdd_sysfs_max_chipset_log_size_store",
              v67);
            _hdd_sysfs_max_chipset_log_size_store___last_ticks_46 = v63;
          }
          if ( v67 - 1025 > 0xFFFFFC30 )
          {
            *(_WORD *)(v23 + 7116) = v67;
            goto LABEL_16;
          }
          v64 = jiffies;
          if ( _hdd_sysfs_max_chipset_log_size_store___last_ticks_47 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: max_chipset_log_size range is 50 to 1024",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "__hdd_sysfs_max_chipset_log_size_store");
            _hdd_sysfs_max_chipset_log_size_store___last_ticks_47 = v64;
          }
        }
      }
    }
    a12 = -22;
LABEL_16:
    _osif_psoc_sync_op_stop(v65, (__int64)"hdd_sysfs_max_chipset_log_size_store");
    goto LABEL_17;
  }
  v33 = jiffies;
  if ( hdd_sysfs_max_chipset_log_size_store___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: hdd_ctx is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_sysfs_max_chipset_log_size_store");
    hdd_sysfs_max_chipset_log_size_store___last_ticks = v33;
  }
  a12 = -22;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return a12;
}
