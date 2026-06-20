unsigned __int64 __fastcall hdd_sysfs_scan_config_store(
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
  char *v53; // x0
  char *v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // [xsp+8h] [xbp-58h] BYREF
  char v72[4]; // [xsp+14h] [xbp-4Ch] BYREF
  char v73[4]; // [xsp+18h] [xbp-48h] BYREF
  char v74[4]; // [xsp+1Ch] [xbp-44h] BYREF
  char *stringp; // [xsp+20h] [xbp-40h] BYREF
  char v76[4]; // [xsp+2Ch] [xbp-34h] BYREF
  _QWORD v77[4]; // [xsp+30h] [xbp-30h] BYREF
  char v78; // [xsp+50h] [xbp-10h]
  __int64 v79; // [xsp+58h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_scan_config_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_scan_config_store",
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
    v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488), &v71, (__int64)"hdd_sysfs_scan_config_store");
    if ( !v23 )
    {
      v78 = 0;
      v76[0] = 1;
      memset(v77, 0, sizeof(v77));
      v74[0] = 0;
      v73[0] = 0;
      v72[0] = 0;
      if ( wlan_hdd_validate_modules_state((__int64)context, v24, v25, v26, v27, v28, v29, v30, v31) )
      {
        v41 = hdd_sysfs_validate_and_copy_buf((__int64)v77, 33, a11, a12, v33, v34, v35, v36, v37, v38, v39, v40);
        if ( v41 )
        {
          v50 = v41;
          v51 = jiffies;
          if ( _hdd_sysfs_scan_config_store___last_ticks - jiffies + 125 < 0 )
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
              "__hdd_sysfs_scan_config_store");
            _hdd_sysfs_scan_config_store___last_ticks = v51;
          }
          a12 = v50;
          goto LABEL_13;
        }
        stringp = (char *)v77;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: set_scan_cfg: count %zu buf_local:(%s)",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "__hdd_sysfs_scan_config_store",
          a12,
          v77);
        v52 = strsep(&stringp, " ");
        if ( v52 )
        {
          if ( !(unsigned int)kstrtou8(v52, 0, v74) )
          {
            v53 = strsep(&stringp, " ");
            if ( v53 )
            {
              if ( !(unsigned int)kstrtou8(v53, 0, v73) )
              {
                v54 = strsep(&stringp, " ");
                if ( v54 )
                {
                  if ( !(unsigned int)kstrtou8(v54, 0, v72) )
                  {
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: Sysfs to set dual mac scan config",
                      v55,
                      v56,
                      v57,
                      v58,
                      v59,
                      v60,
                      v61,
                      v62,
                      "__hdd_sysfs_scan_config_store");
                    if ( (unsigned int)ucfg_policy_mgr_get_dual_mac_feature(*context, v76) )
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: can't get dual mac feature val, use def",
                        v63,
                        v64,
                        v65,
                        v66,
                        v67,
                        v68,
                        v69,
                        v70,
                        "__hdd_sysfs_scan_config_store");
                    if ( v76[0] == 1 )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: Dual mac feature is disabled from INI",
                        v63,
                        v64,
                        v65,
                        v66,
                        v67,
                        v68,
                        v69,
                        v70,
                        "__hdd_sysfs_scan_config_store");
                      a12 = -1;
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: %d %d %d",
                        v63,
                        v64,
                        v65,
                        v66,
                        v67,
                        v68,
                        v69,
                        v70,
                        "__hdd_sysfs_scan_config_store",
                        (unsigned __int8)v74[0],
                        (unsigned __int8)v73[0],
                        (unsigned __int8)v72[0]);
                      policy_mgr_set_dual_mac_scan_config(*context, v74[0], v73[0], v72[0]);
                    }
                    goto LABEL_13;
                  }
                }
              }
            }
          }
        }
      }
      a12 = -22;
LABEL_13:
      _osif_psoc_sync_op_stop(v71, (__int64)"hdd_sysfs_scan_config_store");
      goto LABEL_4;
    }
  }
  a12 = v23;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return a12;
}
