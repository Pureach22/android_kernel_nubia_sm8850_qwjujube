__int64 __fastcall hdd_sysfs_pm_pcl_store(
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
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
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
  int v50; // w21
  __int64 v51; // x20
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
  __int64 v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned __int64 v78; // x22
  __int64 v79; // x20
  __int64 v80; // [xsp+8h] [xbp-248h] BYREF
  char *stringp; // [xsp+10h] [xbp-240h] BYREF
  __int64 v82; // [xsp+18h] [xbp-238h] BYREF
  _DWORD s[102]; // [xsp+20h] [xbp-230h] BYREF
  _QWORD v84[13]; // [xsp+1B8h] [xbp-98h] BYREF
  _QWORD v85[4]; // [xsp+220h] [xbp-30h] BYREF
  char v86; // [xsp+240h] [xbp-10h]
  __int64 v87; // [xsp+248h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v80 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_pm_pcl_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_pm_pcl_store",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22);
  if ( v23
    || (v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v80, (__int64)"hdd_sysfs_pm_pcl_store")) != 0 )
  {
    a12 = v23;
LABEL_4:
    _ReadStatusReg(SP_EL0);
    return a12;
  }
  v86 = 0;
  memset(v85, 0, sizeof(v85));
  memset(v84, 0, 102);
  memset(s, 0, sizeof(s));
  v82 = 0;
  if ( !wlan_hdd_validate_modules_state((__int64)context, v25, v26, v27, v28, v29, v30, v31, v32) )
    goto LABEL_12;
  v41 = hdd_sysfs_validate_and_copy_buf((__int64)v85, 33, a11, a12, v33, v34, v35, v36, v37, v38, v39, v40);
  if ( v41 )
  {
    v50 = v41;
    v51 = jiffies;
    if ( _hdd_sysfs_pm_pcl_store___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x33u, 2u, "%s: invalid input", v42, v43, v44, v45, v46, v47, v48, v49, "__hdd_sysfs_pm_pcl_store");
      _hdd_sysfs_pm_pcl_store___last_ticks = v51;
    }
    a12 = v50;
    goto LABEL_13;
  }
  stringp = (char *)v85;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: pm_pcl: count %zu buf_local:(%s)",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "__hdd_sysfs_pm_pcl_store",
    a12,
    v85);
  v52 = strsep(&stringp, " ");
  if ( !v52 || (unsigned int)kstrtouint(v52, 0, &v82) )
    goto LABEL_12;
  if ( (*(_BYTE *)(context[13] + 16LL) & 1) == 0 )
  {
    v79 = jiffies;
    if ( _hdd_sysfs_pm_pcl_store___last_ticks_8 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: UT framework is disabled",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "__hdd_sysfs_pm_pcl_store");
      _hdd_sysfs_pm_pcl_store___last_ticks_8 = v79;
    }
LABEL_12:
    a12 = -22;
LABEL_13:
    _osif_psoc_sync_op_stop(v80, (__int64)"hdd_sysfs_pm_pcl_store");
    goto LABEL_4;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _DWORD *, char *, _QWORD *, __int64, __int64))policy_mgr_get_pcl)(
                       *context,
                       (unsigned int)v82,
                       s,
                       (char *)&v82 + 4,
                       v84,
                       102,
                       255) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: can't get pcl policy manager",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "__hdd_sysfs_pm_pcl_store");
  v69 = qdf_trace_msg(
          0x33u,
          8u,
          "%s: PCL Freq list for role[%d] is {",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "__hdd_sysfs_pm_pcl_store",
          (unsigned int)v82);
  if ( !HIDWORD(v82) )
  {
LABEL_21:
    qdf_trace_msg(0x33u, 8u, "%s: }--------->\n", v70, v71, v72, v73, v74, v75, v76, v77, "__hdd_sysfs_pm_pcl_store");
    goto LABEL_13;
  }
  v78 = 0;
  while ( v78 != 102 )
  {
    v69 = qdf_trace_msg(
            0x33u,
            8u,
            "%s:  %d, ",
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            "__hdd_sysfs_pm_pcl_store",
            (unsigned int)s[v78++]);
    if ( v78 >= HIDWORD(v82) )
      goto LABEL_21;
  }
  __break(0x5512u);
  __break(1u);
  return hdd_sysfs_pm_cminfo_show(v69);
}
