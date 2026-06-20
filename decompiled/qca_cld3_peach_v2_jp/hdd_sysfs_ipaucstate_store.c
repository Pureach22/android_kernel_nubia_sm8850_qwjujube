__int64 __fastcall hdd_sysfs_ipaucstate_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
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
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x20
  int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // w21
  __int64 v53; // x20
  char *v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 *v63; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v64[4]; // [xsp+14h] [xbp-1Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-18h] BYREF
  int v66; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v67; // [xsp+28h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v63, (__int64)"hdd_sysfs_ipaucstate_store");
  if ( !v7 )
  {
    v66 = 0;
    v64[0] = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter", v8, v9, v10, v11, v12, v13, v14, v15, "__hdd_sysfs_ipaucstate_store");
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_ipaucstate_store",
                          v16,
                          v17,
                          v18,
                          v19,
                          v20,
                          v21,
                          v22,
                          v23) )
    {
      v32 = *(_QWORD *)(a1 + 1336);
      v33 = _wlan_hdd_validate_context(
              v32,
              (__int64)"__hdd_sysfs_ipaucstate_store",
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
        a4 = v33;
        goto LABEL_7;
      }
      if ( wlan_hdd_validate_modules_state(v32, v34, v35, v36, v37, v38, v39, v40, v41)
        && (ucfg_ipa_is_enabled() & 1) != 0 )
      {
        v43 = hdd_sysfs_validate_and_copy_buf(&v66, 4, a3, a4);
        if ( v43 )
        {
          v52 = v43;
          v53 = jiffies;
          if ( _hdd_sysfs_ipaucstate_store___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid input",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "__hdd_sysfs_ipaucstate_store");
            _hdd_sysfs_ipaucstate_store___last_ticks = v53;
          }
          a4 = v52;
          goto LABEL_7;
        }
        stringp = (char *)&v66;
        v54 = strsep(&stringp, " ");
        if ( v54 && !(unsigned int)kstrtou8(v54, 0, v64) )
        {
          if ( v64[0] > 2u )
          {
            if ( v64[0] == 3 )
            {
              ucfg_ipa_uc_rt_debug_host_dump(*(_QWORD *)(v32 + 8), v55, v56, v57, v58, v59, v60, v61, v62);
            }
            else if ( v64[0] == 4 )
            {
              ucfg_ipa_dump_info(*(_QWORD *)(v32 + 8), v55, v56, v57, v58, v59, v60, v61, v62);
            }
          }
          else if ( v64[0] == 1 )
          {
            ucfg_ipa_uc_stat(*(_QWORD *)(v32 + 8), v55, v56, v57, v58, v59, v60, v61, v62);
          }
          else if ( v64[0] == 2 )
          {
            ucfg_ipa_uc_info(*(_QWORD *)(v32 + 8), v55, v56, v57, v58, v59, v60, v61, v62);
          }
          qdf_trace_msg(0x33u, 8u, "%s: exit", v55, v56, v57, v58, v59, v60, v61, v62, "__hdd_sysfs_ipaucstate_store");
          goto LABEL_7;
        }
      }
    }
    a4 = -22;
LABEL_7:
    _osif_vdev_sync_op_stop((__int64)v63, (__int64)"hdd_sysfs_ipaucstate_store");
    goto LABEL_8;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
