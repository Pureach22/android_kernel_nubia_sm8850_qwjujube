unsigned __int64 __fastcall hdd_sysfs_he_bss_color_store(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
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
  __int64 v24; // x21
  int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // w22
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
  unsigned int v63; // w0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x20
  __int64 *v73; // [xsp+8h] [xbp-48h] BYREF
  int v74; // [xsp+14h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v76[4]; // [xsp+20h] [xbp-30h] BYREF
  char v77; // [xsp+40h] [xbp-10h]
  __int64 v78; // [xsp+48h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v73 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v73, (__int64)"hdd_sysfs_he_bss_color_store");
  if ( !v7 )
  {
    v77 = 0;
    memset(v76, 0, sizeof(v76));
    v74 = 0;
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_he_bss_color_store",
                          v8,
                          v9,
                          v10,
                          v11,
                          v12,
                          v13,
                          v14,
                          v15) )
    {
      v24 = *(_QWORD *)(a1 + 1336);
      v25 = _wlan_hdd_validate_context(
              v24,
              (__int64)"__hdd_sysfs_he_bss_color_store",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23);
      if ( v25 )
      {
        a4 = v25;
        goto LABEL_7;
      }
      if ( wlan_hdd_validate_modules_state(v24, v26, v27, v28, v29, v30, v31, v32, v33) )
      {
        v43 = hdd_sysfs_validate_and_copy_buf((__int64)v76, 33, a3, a4, v35, v36, v37, v38, v39, v40, v41, v42);
        if ( v43 )
        {
          v52 = v43;
          v53 = jiffies;
          if ( _hdd_sysfs_he_bss_color_store___last_ticks - jiffies + 125 < 0 )
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
              "__hdd_sysfs_he_bss_color_store");
            _hdd_sysfs_he_bss_color_store___last_ticks = v53;
          }
          a4 = v52;
          goto LABEL_7;
        }
        stringp = (char *)v76;
        v54 = strsep(&stringp, " ");
        if ( v54 )
        {
          if ( !(unsigned int)kstrtouint(v54, 0, &v74) )
          {
            v63 = sme_set_he_bss_color(
                    *(_QWORD *)(v24 + 16),
                    *(_BYTE *)(*(_QWORD *)(a1 + 54136) + 8LL),
                    v74,
                    v55,
                    v56,
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    v62);
            if ( !v63 )
              goto LABEL_7;
            v72 = jiffies;
            if ( _hdd_sysfs_he_bss_color_store___last_ticks_5 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Failed to set HE BSS color, status %d",
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                "__hdd_sysfs_he_bss_color_store",
                v63);
              _hdd_sysfs_he_bss_color_store___last_ticks_5 = v72;
            }
          }
        }
      }
    }
    a4 = -22;
LABEL_7:
    _osif_vdev_sync_op_stop((__int64)v73, (__int64)"hdd_sysfs_he_bss_color_store");
    goto LABEL_8;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
