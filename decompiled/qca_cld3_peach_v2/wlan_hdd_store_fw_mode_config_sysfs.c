unsigned __int64 __fastcall wlan_hdd_store_fw_mode_config_sysfs(
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
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w21
  __int64 v60; // x20
  char *v61; // x0
  char *v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x22
  __int64 v80; // x20
  __int64 v81; // [xsp+0h] [xbp-50h] BYREF
  __int64 v82; // [xsp+8h] [xbp-48h] BYREF
  char *stringp; // [xsp+10h] [xbp-40h] BYREF
  char v84[4]; // [xsp+1Ch] [xbp-34h] BYREF
  _QWORD v85[4]; // [xsp+20h] [xbp-30h] BYREF
  char v86; // [xsp+40h] [xbp-10h]
  __int64 v87; // [xsp+48h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v81 = 0;
  context = _cds_get_context(51, (__int64)"wlan_hdd_store_fw_mode_config_sysfs", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"wlan_hdd_store_fw_mode_config_sysfs",
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
    v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488), &v81, (__int64)"wlan_hdd_store_fw_mode_config_sysfs");
    if ( !v23 )
    {
      v86 = 0;
      v84[0] = 1;
      memset(v85, 0, sizeof(v85));
      v82 = 0;
      v33 = _wlan_hdd_validate_context(
              (__int64)context,
              (__int64)"__wlan_hdd_store_fw_mode_config_sysfs",
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31);
      if ( v33 )
      {
        a12 = v33;
      }
      else
      {
        if ( wlan_hdd_validate_modules_state((__int64)context, v34, v35, v36, v37, v38, v39, v40, v41) )
        {
          v50 = hdd_sysfs_validate_and_copy_buf((__int64)v85, 33, a11, a12, v42, v43, v44, v45, v46, v47, v48, v49);
          if ( v50 )
          {
            v59 = v50;
            v60 = jiffies;
            if ( _wlan_hdd_store_fw_mode_config_sysfs___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: invalid input",
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                "__wlan_hdd_store_fw_mode_config_sysfs",
                v81);
              _wlan_hdd_store_fw_mode_config_sysfs___last_ticks = v60;
            }
            a12 = v59;
            goto LABEL_15;
          }
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: set_fw_mode_cfg: count %zu buf_local:(%s)",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "__wlan_hdd_store_fw_mode_config_sysfs",
            a12,
            v85,
            v81);
          stringp = (char *)v85;
          v61 = strsep(&stringp, " ");
          if ( v61 )
          {
            if ( !(unsigned int)kstrtouint(v61, 0, (char *)&v82 + 4) )
            {
              v62 = strsep(&stringp, " ");
              if ( v62 )
              {
                if ( !(unsigned int)kstrtouint(v62, 0, &v82) )
                {
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: Sysfs to set dual fw mode config",
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    v68,
                    v69,
                    v70,
                    "__wlan_hdd_store_fw_mode_config_sysfs");
                  if ( (unsigned int)ucfg_policy_mgr_get_dual_mac_feature(*context, v84) )
                  {
                    v79 = jiffies;
                    if ( _wlan_hdd_store_fw_mode_config_sysfs___last_ticks_8 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: can't get dual mac feature val, use def",
                        v71,
                        v72,
                        v73,
                        v74,
                        v75,
                        v76,
                        v77,
                        v78,
                        "__wlan_hdd_store_fw_mode_config_sysfs");
                      _wlan_hdd_store_fw_mode_config_sysfs___last_ticks_8 = v79;
                    }
                  }
                  if ( v84[0] == 1 )
                  {
                    v80 = jiffies;
                    if ( _wlan_hdd_store_fw_mode_config_sysfs___last_ticks_10 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: Dual mac feature is disabled from INI",
                        v71,
                        v72,
                        v73,
                        v74,
                        v75,
                        v76,
                        v77,
                        v78,
                        "__wlan_hdd_store_fw_mode_config_sysfs");
                      _wlan_hdd_store_fw_mode_config_sysfs___last_ticks_10 = v80;
                    }
                    a12 = -1;
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: %d %d",
                      v71,
                      v72,
                      v73,
                      v74,
                      v75,
                      v76,
                      v77,
                      v78,
                      "__wlan_hdd_store_fw_mode_config_sysfs",
                      HIDWORD(v82),
                      (unsigned int)v82);
                    policy_mgr_set_dual_mac_fw_mode_config(*context, SBYTE4(v82), v82);
                  }
                  goto LABEL_15;
                }
              }
            }
          }
        }
        a12 = -22;
      }
LABEL_15:
      _osif_psoc_sync_op_stop(v81, (__int64)"wlan_hdd_store_fw_mode_config_sysfs");
      goto LABEL_4;
    }
  }
  a12 = v23;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return a12;
}
