unsigned __int64 __fastcall hdd_sysfs_set_11be_fixed_rate(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  __int64 v25; // x23
  int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w22
  __int64 v36; // x20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // w21
  __int64 v56; // x20
  __int64 v57; // x20
  char *v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x20
  __int64 *v68; // [xsp+8h] [xbp-48h] BYREF
  char *stringp; // [xsp+10h] [xbp-40h] BYREF
  unsigned __int16 v70; // [xsp+1Ch] [xbp-34h] BYREF
  _QWORD v71[4]; // [xsp+20h] [xbp-30h] BYREF
  char v72; // [xsp+40h] [xbp-10h]
  __int64 v73; // [xsp+48h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v68, (__int64)"hdd_sysfs_set_11be_fixed_rate");
  if ( !v7 )
  {
    v72 = 0;
    memset(v71, 0, sizeof(v71));
    v70 = 0;
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_set_11be_fixed_rate",
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13,
                         v14,
                         v15) )
    {
      v24 = jiffies;
      if ( _hdd_sysfs_set_11be_fixed_rate___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: invalid adapter",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "__hdd_sysfs_set_11be_fixed_rate");
        _hdd_sysfs_set_11be_fixed_rate___last_ticks = v24;
      }
    }
    else
    {
      v25 = *(_QWORD *)(a1 + 1336);
      v26 = _wlan_hdd_validate_context(
              v25,
              (__int64)"__hdd_sysfs_set_11be_fixed_rate",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23);
      if ( v26 )
      {
        v35 = v26;
        v36 = jiffies;
        if ( _hdd_sysfs_set_11be_fixed_rate___last_ticks_4 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid hdd context",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "__hdd_sysfs_set_11be_fixed_rate");
          _hdd_sysfs_set_11be_fixed_rate___last_ticks_4 = v36;
        }
        a4 = v35;
        goto LABEL_11;
      }
      if ( wlan_hdd_validate_modules_state(v25, v27, v28, v29, v30, v31, v32, v33, v34) )
      {
        v46 = hdd_sysfs_validate_and_copy_buf((__int64)v71, 33, a3, a4, v38, v39, v40, v41, v42, v43, v44, v45);
        if ( v46 )
        {
          v55 = v46;
          v56 = jiffies;
          if ( _hdd_sysfs_set_11be_fixed_rate___last_ticks_8 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid input",
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "__hdd_sysfs_set_11be_fixed_rate");
            _hdd_sysfs_set_11be_fixed_rate___last_ticks_8 = v56;
          }
          a4 = v55;
          goto LABEL_11;
        }
        stringp = (char *)v71;
        v58 = strsep(&stringp, " ");
        if ( v58 && !(unsigned int)kstrtou16(v58, 0, &v70) )
        {
          hdd_set_11be_rate_code(a1 + 1312, v70, v59, v60, v61, v62, v63, v64, v65, v66);
          goto LABEL_11;
        }
        v67 = jiffies;
        if ( _hdd_sysfs_set_11be_fixed_rate___last_ticks_11 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "__hdd_sysfs_set_11be_fixed_rate");
          _hdd_sysfs_set_11be_fixed_rate___last_ticks_11 = v67;
        }
      }
      else
      {
        v57 = jiffies;
        if ( _hdd_sysfs_set_11be_fixed_rate___last_ticks_6 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid module state",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "__hdd_sysfs_set_11be_fixed_rate");
          _hdd_sysfs_set_11be_fixed_rate___last_ticks_6 = v57;
        }
      }
    }
    a4 = -22;
LABEL_11:
    _osif_vdev_sync_op_stop((__int64)v68, (__int64)"hdd_sysfs_set_11be_fixed_rate");
    goto LABEL_12;
  }
  a4 = v7;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return a4;
}
