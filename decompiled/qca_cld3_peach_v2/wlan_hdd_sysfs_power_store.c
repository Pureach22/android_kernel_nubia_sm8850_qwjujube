__int64 __fastcall wlan_hdd_sysfs_power_store(
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
  int v23; // w8
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w0
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
  const char *v54; // x21
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x5
  __int64 v64; // [xsp+0h] [xbp-40h] BYREF
  char *stringp; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v66[4]; // [xsp+10h] [xbp-30h] BYREF
  char v67; // [xsp+30h] [xbp-10h]
  __int64 v68; // [xsp+38h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64 = 0;
  context = _cds_get_context(51, (__int64)"wlan_hdd_sysfs_power_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"wlan_hdd_sysfs_power_store",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22);
  result = 0;
  if ( !v23 )
  {
    LODWORD(result) = _osif_psoc_sync_op_start(
                        *(_QWORD *)(context[3] + 488LL),
                        &v64,
                        (__int64)"wlan_hdd_sysfs_power_store");
    if ( (_DWORD)result )
    {
      result = (int)result;
      goto LABEL_18;
    }
    v67 = 0;
    memset(v66, 0, sizeof(v66));
    v33 = _wlan_hdd_validate_context(
            (__int64)context,
            (__int64)"__hdd_sysfs_power_level_store",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32);
    if ( v33 )
    {
      a12 = v33;
LABEL_17:
      _osif_psoc_sync_op_stop(v64, (__int64)"wlan_hdd_sysfs_power_store");
      result = a12;
      goto LABEL_18;
    }
    if ( !wlan_hdd_validate_modules_state((__int64)context, v34, v35, v36, v37, v38, v39, v40, v41) )
      goto LABEL_16;
    v42 = hdd_sysfs_validate_and_copy_buf(v66, 33, a11, a12);
    if ( v42 )
    {
      v51 = v42;
      v52 = jiffies;
      if ( _hdd_sysfs_power_level_store___last_ticks - jiffies + 125 < 0 )
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
          "__hdd_sysfs_power_level_store",
          v64);
        _hdd_sysfs_power_level_store___last_ticks = v52;
      }
      a12 = v51;
      goto LABEL_17;
    }
    stringp = (char *)v66;
    v53 = strsep(&stringp, " ");
    if ( !v53 )
    {
LABEL_16:
      a12 = -22;
      goto LABEL_17;
    }
    v54 = v53;
    if ( !strncasecmp(v53, "VLP", 3u) )
    {
      v63 = 2;
    }
    else
    {
      if ( !strncasecmp(v54, "LP", 2u) )
      {
        v63 = 0;
        *((_BYTE *)context + 7122) = 0;
LABEL_23:
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: power level %s(%d)",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "__hdd_sysfs_power_level_store",
          v54,
          v63,
          v64);
        goto LABEL_17;
      }
      if ( !strncasecmp(v54, "SP", 2u) )
        v63 = 1;
      else
        v63 = 3;
    }
    *((_BYTE *)context + 7122) = v63;
    goto LABEL_23;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
