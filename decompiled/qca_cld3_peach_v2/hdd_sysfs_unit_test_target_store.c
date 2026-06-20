__int64 __fastcall hdd_sysfs_unit_test_target_store(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
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
  int v16; // w8
  __int64 v17; // x22
  int v18; // w0
  int v19; // w0
  int v20; // w21
  __int64 v21; // x20
  __int64 v22; // x20
  char *v23; // x0
  __int64 v24; // x21
  char *v26; // x0
  __int64 v27; // x20
  __int64 v28; // x20
  __int64 v29; // x21
  _BYTE *v30; // x22
  char *v31; // x0
  unsigned __int16 *v32; // x30
  unsigned int v33; // w0
  __int64 v34; // x20
  __int64 v35; // x20
  __int64 *v36; // [xsp+8h] [xbp-2B8h] BYREF
  __int64 v37; // [xsp+10h] [xbp-2B0h] BYREF
  char *stringp; // [xsp+18h] [xbp-2A8h] BYREF
  _BYTE v39[403]; // [xsp+24h] [xbp-29Ch] BYREF
  _BYTE s[257]; // [xsp+1B7h] [xbp-109h] BYREF
  __int64 v41; // [xsp+2B8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v36, (__int64)"hdd_sysfs_unit_test_target_store");
  if ( !v7 )
  {
    memset(s, 0, sizeof(s));
    memset(v39, 0, 0x190u);
    v16 = *(_DWORD *)(a1 + 1352);
    v37 = 0;
    if ( v16 == 4
      || !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_unit_test_target_store",
                          v8,
                          v9,
                          v10,
                          v11,
                          v12,
                          v13,
                          v14,
                          v15) )
    {
      v17 = *(_QWORD *)(a1 + 1336);
      v18 = _wlan_hdd_validate_context(
              v17,
              (__int64)"__hdd_sysfs_unit_test_target_store",
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15);
      if ( v18 )
      {
        a4 = v18;
        goto LABEL_7;
      }
      if ( wlan_hdd_validate_modules_state(v17, v8, v9, v10, v11, v12, v13, v14, v15) )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(v17 + 104) + 16LL) & 1) != 0 )
        {
          v19 = hdd_sysfs_validate_and_copy_buf((__int64)s, 257, a3, a4, v8, v9, v10, v11, v12, v13, v14, v15);
          if ( v19 )
          {
            v20 = v19;
            v21 = jiffies;
            if ( _hdd_sysfs_unit_test_target_store___last_ticks_6 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: invalid input",
                v8,
                v9,
                v10,
                v11,
                v12,
                v13,
                v14,
                v15,
                "__hdd_sysfs_unit_test_target_store");
              _hdd_sysfs_unit_test_target_store___last_ticks_6 = v21;
            }
            a4 = v20;
            if ( (v20 & 0x8000000000000000LL) == 0 )
              goto LABEL_23;
            goto LABEL_21;
          }
          qdf_trace_msg(
            0x33u,
            4u,
            "unit_test_target: count %zu buf_local:(%s) net_devname %s",
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            a4,
            s,
            a1 - 1080);
          stringp = s;
          v23 = strsep(&stringp, " ");
          if ( v23 )
          {
            if ( !(unsigned int)kstrtouint(v23, 0, (char *)&v37 + 4) )
            {
              v26 = strsep(&stringp, " ");
              if ( v26 )
              {
                if ( !(unsigned int)kstrtouint(v26, 0, &v37) )
                {
                  if ( HIDWORD(v37) < 0x9D )
                  {
                    if ( (int)v37 <= 100 )
                    {
                      if ( (int)v37 < 1 )
                      {
LABEL_39:
                        hdd_get_conparam();
                        v33 = sme_send_unit_test_cmd();
                        if ( !v33 )
                        {
LABEL_7:
                          if ( (a4 & 0x8000000000000000LL) == 0 )
                          {
LABEL_23:
                            _osif_vdev_sync_op_stop((__int64)v36, (__int64)"hdd_sysfs_unit_test_target_store");
                            goto LABEL_24;
                          }
LABEL_21:
                          v24 = jiffies;
                          if ( hdd_sysfs_unit_test_target_store___last_ticks - jiffies + 125 < 0 )
                          {
                            qdf_trace_msg(
                              0x33u,
                              2u,
                              "%s: errno_size %zd",
                              v8,
                              v9,
                              v10,
                              v11,
                              v12,
                              v13,
                              v14,
                              v15,
                              "hdd_sysfs_unit_test_target_store",
                              a4);
                            hdd_sysfs_unit_test_target_store___last_ticks = v24;
                          }
                          goto LABEL_23;
                        }
                        v34 = jiffies;
                        if ( _hdd_sysfs_unit_test_target_store___last_ticks_16 - jiffies + 125 < 0 )
                        {
                          qdf_trace_msg(
                            0x33u,
                            2u,
                            "%s: sme_send_unit_test_cmd returned %d",
                            v8,
                            v9,
                            v10,
                            v11,
                            v12,
                            v13,
                            v14,
                            v15,
                            "__hdd_sysfs_unit_test_target_store",
                            v33);
                          _hdd_sysfs_unit_test_target_store___last_ticks_16 = v34;
                        }
                      }
                      else
                      {
                        v29 = 0;
                        v30 = v39;
                        while ( 1 )
                        {
                          v31 = strsep(&stringp, " ");
                          if ( !v31 )
                            break;
                          if ( v29 == 101 )
                          {
                            __break(0x5512u);
                            __ldxr(v32);
                            return hdd_sysfs_modify_acl_create(v31);
                          }
                          if ( (unsigned int)kstrtouint(v31, 0, v30) )
                            goto LABEL_20;
                          ++v29;
                          v30 += 4;
                          if ( v29 >= (int)v37 )
                            goto LABEL_39;
                        }
                        v35 = jiffies;
                        if ( _hdd_sysfs_unit_test_target_store___last_ticks_14 - jiffies + 125 < 0 )
                        {
                          qdf_trace_msg(
                            0x33u,
                            2u,
                            "%s: not enough args(%d), expected args_num:%d",
                            v8,
                            v9,
                            v10,
                            v11,
                            v12,
                            v13,
                            v14,
                            v15,
                            "__hdd_sysfs_unit_test_target_store",
                            (unsigned int)v29,
                            (unsigned int)v37);
                          _hdd_sysfs_unit_test_target_store___last_ticks_14 = v35;
                        }
                      }
                    }
                    else
                    {
                      v28 = jiffies;
                      if ( _hdd_sysfs_unit_test_target_store___last_ticks_12 - jiffies + 125 < 0 )
                      {
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: Too many args %d",
                          v8,
                          v9,
                          v10,
                          v11,
                          v12,
                          v13,
                          v14,
                          v15,
                          "__hdd_sysfs_unit_test_target_store");
                        _hdd_sysfs_unit_test_target_store___last_ticks_12 = v28;
                      }
                    }
                  }
                  else
                  {
                    v27 = jiffies;
                    if ( _hdd_sysfs_unit_test_target_store___last_ticks_10 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: Invalid MODULE ID %d",
                        v8,
                        v9,
                        v10,
                        v11,
                        v12,
                        v13,
                        v14,
                        v15,
                        "__hdd_sysfs_unit_test_target_store");
                      _hdd_sysfs_unit_test_target_store___last_ticks_10 = v27;
                    }
                  }
                }
              }
            }
          }
        }
        else
        {
          v22 = jiffies;
          if ( _hdd_sysfs_unit_test_target_store___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              3u,
              "%s: UT framework is disabled",
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              "__hdd_sysfs_unit_test_target_store");
            _hdd_sysfs_unit_test_target_store___last_ticks = v22;
          }
        }
      }
    }
LABEL_20:
    a4 = -22;
    goto LABEL_21;
  }
  a4 = v7;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return a4;
}
