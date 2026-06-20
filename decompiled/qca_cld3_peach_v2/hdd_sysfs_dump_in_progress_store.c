__int64 __fastcall hdd_sysfs_dump_in_progress_store(
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
        __int64 a12)
{
  _QWORD *context; // x20
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
  int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w21
  __int64 v43; // x20
  char *v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x22
  __int64 v54; // [xsp+8h] [xbp-48h] BYREF
  unsigned int v55; // [xsp+14h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v57[4]; // [xsp+20h] [xbp-30h] BYREF
  char v58; // [xsp+40h] [xbp-10h]
  __int64 v59; // [xsp+48h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dump_in_progress_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_dump_in_progress_store",
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
    v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v54, (__int64)"hdd_sysfs_dump_in_progress_store");
    if ( !v23 )
    {
      v58 = 0;
      memset(v57, 0, sizeof(v57));
      v55 = 0;
      if ( !wlan_hdd_validate_modules_state((__int64)context, v24, v25, v26, v27, v28, v29, v30, v31) )
        goto LABEL_15;
      v33 = hdd_sysfs_validate_and_copy_buf(v57, 33, a11, a12);
      if ( v33 )
      {
        v42 = v33;
        v43 = jiffies;
        if ( _hdd_sysfs_dump_in_progress_store___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "__hdd_sysfs_dump_in_progress_store");
          _hdd_sysfs_dump_in_progress_store___last_ticks = v43;
        }
        a12 = v42;
        goto LABEL_16;
      }
      stringp = (char *)v57;
      v44 = strsep(&stringp, " ");
      if ( !v44 || (unsigned int)kstrtouint(v44, 0, &v55) )
        goto LABEL_15;
      v53 = jiffies;
      if ( _hdd_sysfs_dump_in_progress_store___last_ticks_8 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: dump in progress %d",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "__hdd_sysfs_dump_in_progress_store",
          v55);
        _hdd_sysfs_dump_in_progress_store___last_ticks_8 = v53;
      }
      if ( v55 <= 1 )
        *((_BYTE *)context + 7113) = v55;
      else
LABEL_15:
        a12 = -22;
LABEL_16:
      _osif_psoc_sync_op_stop(v54, (__int64)"hdd_sysfs_dump_in_progress_store");
      goto LABEL_4;
    }
  }
  a12 = v23;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return a12;
}
