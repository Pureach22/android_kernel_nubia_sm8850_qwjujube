__int64 __fastcall hdd_sysfs_thermal_cfg_store(
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
  __int64 *context; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  __int64 v24; // x0
  unsigned int thermal_temp; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  unsigned int v35; // w21
  __int64 v36; // x21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x20
  char *v55; // x0
  char *v56; // x0
  char *v57; // x0
  char *v58; // x0
  char *v59; // x0
  char *v60; // x0
  char *v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int v70; // w0
  __int64 v71; // [xsp+0h] [xbp-150h] BYREF
  unsigned __int16 v72; // [xsp+Ch] [xbp-144h] BYREF
  unsigned __int16 v73[2]; // [xsp+10h] [xbp-140h] BYREF
  int v74; // [xsp+14h] [xbp-13Ch] BYREF
  __int64 v75; // [xsp+18h] [xbp-138h] BYREF
  __int64 v76; // [xsp+20h] [xbp-130h] BYREF
  char *stringp; // [xsp+28h] [xbp-128h] BYREF
  _QWORD v78[7]; // [xsp+30h] [xbp-120h] BYREF
  __int64 v79; // [xsp+68h] [xbp-E8h]
  __int64 v80; // [xsp+70h] [xbp-E0h]
  __int64 v81; // [xsp+78h] [xbp-D8h] BYREF
  __int64 v82; // [xsp+80h] [xbp-D0h]
  __int64 v83; // [xsp+88h] [xbp-C8h]
  __int64 v84; // [xsp+90h] [xbp-C0h]
  __int64 v85; // [xsp+98h] [xbp-B8h]
  __int64 v86; // [xsp+A0h] [xbp-B0h]
  __int64 v87; // [xsp+A8h] [xbp-A8h]
  __int64 v88; // [xsp+B0h] [xbp-A0h]
  __int64 v89; // [xsp+B8h] [xbp-98h]
  __int64 v90; // [xsp+C0h] [xbp-90h]
  __int64 v91; // [xsp+C8h] [xbp-88h]
  __int64 v92; // [xsp+D0h] [xbp-80h]
  __int64 v93; // [xsp+D8h] [xbp-78h]
  __int64 v94; // [xsp+E0h] [xbp-70h]
  __int64 v95; // [xsp+E8h] [xbp-68h]
  __int64 v96; // [xsp+F0h] [xbp-60h]
  __int64 v97; // [xsp+F8h] [xbp-58h]
  __int64 v98; // [xsp+100h] [xbp-50h]
  __int64 v99; // [xsp+108h] [xbp-48h]
  __int64 v100; // [xsp+110h] [xbp-40h]
  __int64 v101; // [xsp+118h] [xbp-38h]
  _QWORD v102[4]; // [xsp+120h] [xbp-30h] BYREF
  char v103; // [xsp+140h] [xbp-10h]
  __int64 v104; // [xsp+148h] [xbp-8h]

  v104 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_thermal_cfg_store", a1, a2, a3, a4, a5, a6, a7, a8);
  LODWORD(result) = _wlan_hdd_validate_context(
                      (__int64)context,
                      (__int64)"hdd_sysfs_thermal_cfg_store",
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22);
  if ( !(_DWORD)result )
  {
    LODWORD(result) = _osif_psoc_sync_op_start(
                        *(_QWORD *)(context[3] + 488),
                        &v71,
                        (__int64)"hdd_sysfs_thermal_cfg_store");
    if ( !(_DWORD)result )
    {
      v103 = 0;
      memset(v102, 0, sizeof(v102));
      v76 = 0;
      stringp = nullptr;
      v100 = 0;
      v101 = 0;
      v98 = 0;
      v99 = 0;
      v96 = 0;
      v97 = 0;
      v94 = 0;
      v95 = 0;
      v92 = 0;
      v93 = 0;
      v90 = 0;
      v91 = 0;
      v88 = 0;
      v89 = 0;
      v86 = 0;
      v87 = 0;
      v84 = 0;
      v85 = 0;
      v82 = 0;
      v83 = 0;
      v80 = 0;
      v81 = 0;
      v79 = 0;
      memset(v78, 0, sizeof(v78));
      v24 = *context;
      v75 = 0;
      v74 = 0;
      v73[0] = 0;
      v72 = 0;
      thermal_temp = ucfg_fwol_get_thermal_temp(v24, v78);
      if ( thermal_temp )
      {
        v34 = jiffies;
        if ( _hdd_sysfs_thermal_cfg_store___last_ticks - jiffies + 125 < 0 )
        {
          v35 = thermal_temp;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to get fwol thermal obj",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "__hdd_sysfs_thermal_cfg_store",
            v71);
          thermal_temp = v35;
          _hdd_sysfs_thermal_cfg_store___last_ticks = v34;
        }
        v36 = thermal_temp;
        goto LABEL_17;
      }
      if ( !wlan_hdd_validate_modules_state((__int64)context, v26, v27, v28, v29, v30, v31, v32, v33) )
        goto LABEL_16;
      v45 = hdd_sysfs_validate_and_copy_buf((__int64)v102, 33, a11, a12, v37, v38, v39, v40, v41, v42, v43, v44);
      if ( v45 )
      {
        LODWORD(v36) = v45;
        v54 = jiffies;
        if ( _hdd_sysfs_thermal_cfg_store___last_ticks_5 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "__hdd_sysfs_thermal_cfg_store",
            v71);
          _hdd_sysfs_thermal_cfg_store___last_ticks_5 = v54;
        }
        v36 = (int)v36;
        goto LABEL_17;
      }
      stringp = (char *)v102;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: thermal_cfg: count %zu buf_local:(%s)",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "__hdd_sysfs_thermal_cfg_store",
        a12,
        v102,
        v71);
      v55 = strsep(&stringp, " ");
      if ( !v55 )
        goto LABEL_16;
      if ( !(unsigned int)kstrtouint(v55, 0, (char *)&v76 + 4)
        && (v56 = strsep(&stringp, " ")) != nullptr
        && !(unsigned int)kstrtouint(v56, 0, &v76)
        && (v57 = strsep(&stringp, " ")) != nullptr
        && !(unsigned int)kstrtouint(v57, 0, (char *)&v75 + 4)
        && (v58 = strsep(&stringp, " ")) != nullptr
        && !(unsigned int)kstrtouint(v58, 0, &v75)
        && (v59 = strsep(&stringp, " ")) != nullptr
        && !(unsigned int)kstrtou16(v59, 0, v73)
        && (v60 = strsep(&stringp, " ")) != nullptr
        && !(unsigned int)kstrtou16(v60, 0, &v72)
        && (v61 = strsep(&stringp, " ")) != nullptr
        && !(unsigned int)kstrtouint(v61, 0, &v74) )
      {
        v36 = -22;
        if ( HIDWORD(v76) > 1 || HIDWORD(v75) > 0x64 || (unsigned int)v75 > 3 || v72 <= (unsigned int)v73[0] )
          goto LABEL_17;
        HIDWORD(v81) = HIDWORD(v76);
        LODWORD(v82) = v76;
        HIDWORD(v85) = HIDWORD(v75);
        LODWORD(v86) = v75;
        HIDWORD(v84) = v74;
        hdd_thermal_fill_clientid_priority(
          (__int64)context,
          1,
          BYTE3(v79),
          BYTE4(v79),
          (__int64)&v81,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69);
        v70 = sme_set_thermal_throttle_cfg(context[2], &v81);
        if ( !v70 )
        {
          if ( v74 )
          {
            v36 = a12;
            goto LABEL_17;
          }
          v70 = sme_set_thermal_mgmt(context[2], v73[0], v72);
          v36 = a12;
          if ( !v70 )
            goto LABEL_17;
        }
        v36 = (int)qdf_status_to_os_return(v70);
      }
      else
      {
LABEL_16:
        v36 = -22;
      }
LABEL_17:
      _osif_psoc_sync_op_stop(v71, (__int64)"hdd_sysfs_thermal_cfg_store");
      result = v36;
      goto LABEL_4;
    }
  }
  result = (int)result;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
