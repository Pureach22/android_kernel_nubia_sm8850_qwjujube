__int64 __fastcall hdd_sysfs_ipaoptdpctrlrm_store(
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
  __int64 *context; // x20
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
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w21
  __int64 v66; // x20
  char *v68; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  char *v77; // x0
  char *v78; // x0
  char *v79; // x0
  char *v80; // x0
  char *v81; // x0
  char *v82; // x0
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // [xsp+8h] [xbp-68h] BYREF
  char *stringp; // [xsp+10h] [xbp-60h] BYREF
  __int64 v93; // [xsp+18h] [xbp-58h] BYREF
  __int64 v94; // [xsp+20h] [xbp-50h] BYREF
  __int64 v95; // [xsp+28h] [xbp-48h] BYREF
  _QWORD v96[6]; // [xsp+30h] [xbp-40h] BYREF
  __int16 v97; // [xsp+60h] [xbp-10h]
  __int64 v98; // [xsp+68h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v91 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_ipaoptdpctrlrm_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_ipaoptdpctrlrm_store",
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
    if ( !wlan_hdd_validate_modules_state((__int64)context, v24, v25, v26, v27, v28, v29, v30, v31)
      || (ucfg_ipa_is_enabled() & 1) == 0 )
    {
      a12 = -22;
      goto LABEL_14;
    }
    if ( !hdd_get_adapter((__int64)context, 0) && !hdd_get_adapter((__int64)context, 1) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: device mode not supporting opt_dp_ctrl",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "hdd_sysfs_ipaoptdpctrlrm_store");
      a12 = 0;
      goto LABEL_14;
    }
    v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488), &v91, (__int64)"hdd_sysfs_ipaoptdpctrlrm_store");
    if ( !v23 )
    {
      v97 = 0;
      memset(v96, 0, sizeof(v96));
      v94 = 0;
      v95 = 0;
      v93 = 0;
      qdf_trace_msg(0x33u, 8u, "%s: enter", v40, v41, v42, v43, v44, v45, v46, v47, "__hdd_sysfs_ipaoptdpctrlrm_store");
      if ( ucfg_dp_ipa_ctrl_debug_supported(*context) )
      {
        v56 = hdd_sysfs_validate_and_copy_buf(v96, 50, a11, a12);
        if ( v56 )
        {
          v65 = v56;
          v66 = jiffies;
          if ( _hdd_sysfs_ipaoptdpctrlrm_store___last_ticks_20 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid input",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "__hdd_sysfs_ipaoptdpctrlrm_store");
            _hdd_sysfs_ipaoptdpctrlrm_store___last_ticks_20 = v66;
          }
          a12 = v65;
          goto LABEL_42;
        }
        stringp = (char *)v96;
        v68 = strsep(&stringp, " ");
        if ( !v68 || (unsigned int)kstrtou8(v68, 0, &v93) )
          goto LABEL_16;
        if ( !(_BYTE)v93 )
          goto LABEL_43;
        v77 = strsep(&stringp, " ");
        if ( !v77 || (unsigned int)kstrtouint(v77, 0, (char *)&v93 + 4) )
          goto LABEL_16;
        if ( (unsigned __int8)v93 < 2u )
          goto LABEL_43;
        v78 = strsep(&stringp, " ");
        if ( !v78 || (unsigned int)kstrtouint(v78, 0, &v94) )
          goto LABEL_16;
        if ( (unsigned __int8)v93 < 3u )
          goto LABEL_43;
        v79 = strsep(&stringp, " ");
        if ( !v79 || (unsigned int)kstrtouint(v79, 0, (char *)&v94 + 4) )
          goto LABEL_16;
        if ( (unsigned __int8)v93 < 4u )
          goto LABEL_43;
        v80 = strsep(&stringp, " ");
        if ( !v80 || (unsigned int)kstrtouint(v80, 0, &v95) )
          goto LABEL_16;
        if ( (unsigned __int8)v93 < 5u )
          goto LABEL_43;
        v81 = strsep(&stringp, " ");
        if ( !v81 || (unsigned int)kstrtouint(v81, 0, (char *)&v95 + 4) )
          goto LABEL_16;
        if ( (unsigned __int8)v93 < 6u )
          goto LABEL_43;
        v82 = strsep(&stringp, " ");
        if ( !v82 || (unsigned int)kstrtouint(v82, 0, v96) )
          goto LABEL_16;
        if ( (unsigned __int8)v93 < 7u )
        {
LABEL_43:
          ucfg_ipa_set_opt_dp_ctrl_flt_rm(context[1], (unsigned __int8 *)&v93, v69, v70, v71, v72, v73, v74, v75, v76);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: exit",
            v83,
            v84,
            v85,
            v86,
            v87,
            v88,
            v89,
            v90,
            "__hdd_sysfs_ipaoptdpctrlrm_store");
          goto LABEL_42;
        }
        if ( strsep(&stringp, " ") )
        {
          __break(0x5512u);
          goto LABEL_41;
        }
      }
      else
      {
        a12 = (__int64)&unk_864000;
        context = (__int64 *)jiffies;
        if ( _hdd_sysfs_ipaoptdpctrlrm_store___last_ticks - jiffies + 125 < 0 )
        {
LABEL_41:
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: opt_dp_ctrl, ipa debug is not supported",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "__hdd_sysfs_ipaoptdpctrlrm_store");
          *(_QWORD *)(a12 + 1536) = context;
          a12 = -22;
          goto LABEL_42;
        }
      }
LABEL_16:
      a12 = -22;
LABEL_42:
      _osif_psoc_sync_op_stop(v91, (__int64)"hdd_sysfs_ipaoptdpctrlrm_store");
      goto LABEL_14;
    }
  }
  a12 = v23;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return a12;
}
