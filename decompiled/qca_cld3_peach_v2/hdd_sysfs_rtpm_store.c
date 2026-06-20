__int64 __fastcall hdd_sysfs_rtpm_store(
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
  int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w20
  __int64 v43; // x21
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  char *v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x21
  int v62; // w0
  __int64 v63; // x20
  __int64 v64; // [xsp+8h] [xbp-48h] BYREF
  unsigned int v65; // [xsp+14h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v67[4]; // [xsp+20h] [xbp-30h] BYREF
  char v68; // [xsp+40h] [xbp-10h]
  __int64 v69; // [xsp+48h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_rtpm_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_rtpm_store",
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
    v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v64, (__int64)"hdd_sysfs_rtpm_store");
    if ( !v23 )
    {
      v68 = 0;
      memset(v67, 0, sizeof(v67));
      v65 = 0;
      if ( wlan_hdd_validate_modules_state((__int64)context, v24, v25, v26, v27, v28, v29, v30, v31) )
      {
        v33 = hdd_sysfs_validate_and_copy_buf(v67, 33, a11, a12);
        if ( v33 )
        {
          v42 = v33;
          v43 = jiffies;
          if ( _hdd_sysfs_rtpm_store___last_ticks - jiffies + 125 < 0 )
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
              "__hdd_sysfs_rtpm_store");
            _hdd_sysfs_rtpm_store___last_ticks = v43;
          }
          a12 = v42;
          goto LABEL_22;
        }
        if ( hdd_is_any_sta_connected((__int64)context, v34, v35, v36, v37, v38, v39, v40, v41) )
        {
          stringp = (char *)v67;
          v52 = strsep(&stringp, " ");
          if ( v52 && !(unsigned int)kstrtoint(v52, 0, &v65) )
          {
            v61 = jiffies;
            if ( _hdd_sysfs_rtpm_store___last_ticks_10 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: rtpm %d",
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                "__hdd_sysfs_rtpm_store",
                v65);
              _hdd_sysfs_rtpm_store___last_ticks_10 = v61;
            }
            v62 = v65;
            if ( v65 == -1 )
            {
              hif_rtpm_restore_autosuspend_delay();
            }
            else
            {
              if ( !v65 )
                v62 = -1;
              hif_rtpm_set_autosuspend_delay(v62);
            }
            goto LABEL_22;
          }
        }
        else
        {
          v63 = jiffies;
          if ( _hdd_sysfs_rtpm_store___last_ticks_7 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: No STA is connected",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "__hdd_sysfs_rtpm_store");
            _hdd_sysfs_rtpm_store___last_ticks_7 = v63;
          }
        }
      }
      a12 = -22;
LABEL_22:
      _osif_psoc_sync_op_stop(v64, (__int64)"hdd_sysfs_rtpm_store");
      goto LABEL_4;
    }
  }
  a12 = v23;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return a12;
}
