unsigned __int64 __fastcall hdd_sysfs_wlan_dbg_store(
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
  char *v53; // x0
  char *v54; // x0
  __int64 pidx; // x0
  __int64 v56; // [xsp+0h] [xbp-50h] BYREF
  int v57; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v58; // [xsp+10h] [xbp-40h] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v60[4]; // [xsp+20h] [xbp-30h] BYREF
  char v61; // [xsp+40h] [xbp-10h]
  __int64 v62; // [xsp+48h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_wlan_dbg_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_wlan_dbg_store",
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
    v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v56, (__int64)"hdd_sysfs_wlan_dbg_store");
    if ( !v23 )
    {
      v61 = 0;
      memset(v60, 0, sizeof(v60));
      v58 = 0;
      v57 = 0;
      if ( !wlan_hdd_validate_modules_state((__int64)context, v24, v25, v26, v27, v28, v29, v30, v31) )
        goto LABEL_12;
      v41 = hdd_sysfs_validate_and_copy_buf((__int64)v60, 33, a11, a12, v33, v34, v35, v36, v37, v38, v39, v40);
      if ( v41 )
      {
        v50 = v41;
        v51 = jiffies;
        if ( _hdd_sysfs_wlan_dbg_store___last_ticks - jiffies + 125 < 0 )
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
            "__hdd_sysfs_wlan_dbg_store",
            v56);
          _hdd_sysfs_wlan_dbg_store___last_ticks = v51;
        }
        a12 = v50;
        goto LABEL_13;
      }
      stringp = (char *)v60;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: set_wlan_dbg: count %zu buf_local:(%s)",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "__hdd_sysfs_wlan_dbg_store",
        a12,
        v60,
        v56);
      v52 = strsep(&stringp, " ");
      if ( v52
        && !(unsigned int)kstrtouint(v52, 0, (char *)&v58 + 4)
        && (v53 = strsep(&stringp, " ")) != nullptr
        && !(unsigned int)kstrtouint(v53, 0, &v58)
        && (v54 = strsep(&stringp, " ")) != nullptr
        && !(unsigned int)kstrtouint(v54, 0, &v57) )
      {
        pidx = qdf_get_pidx();
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, bool))qdf_print_set_category_verbose)(
          pidx,
          HIDWORD(v58),
          (unsigned int)v58,
          v57 != 0);
      }
      else
      {
LABEL_12:
        a12 = -22;
      }
LABEL_13:
      _osif_psoc_sync_op_stop(v56, (__int64)"hdd_sysfs_wlan_dbg_store");
      goto LABEL_4;
    }
  }
  a12 = v23;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return a12;
}
