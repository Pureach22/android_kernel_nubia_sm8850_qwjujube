__int64 __fastcall hdd_sysfs_direct_link_ut_cmd_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
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
  int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w21
  char *v44; // x0
  char *v45; // x0
  char *v46; // x0
  char *v47; // x0
  char *v48; // x0
  char *v49; // x0
  char *v50; // x0
  char *v51; // x0
  char *v52; // x0
  char *v53; // x0
  char *v54; // x0
  __int16 v55; // w8
  unsigned int v56; // w0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 *v65; // [xsp+8h] [xbp-248h] BYREF
  char *stringp; // [xsp+10h] [xbp-240h] BYREF
  __int64 v67; // [xsp+18h] [xbp-238h] BYREF
  __int64 v68; // [xsp+20h] [xbp-230h] BYREF
  __int64 v69; // [xsp+28h] [xbp-228h] BYREF
  __int64 v70; // [xsp+30h] [xbp-220h] BYREF
  __int64 v71; // [xsp+38h] [xbp-218h] BYREF
  int v72; // [xsp+40h] [xbp-210h] BYREF
  _BYTE s[513]; // [xsp+47h] [xbp-209h] BYREF
  __int64 v74; // [xsp+248h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v65, (__int64)"hdd_sysfs_direct_link_ut_cmd_store");
  if ( !v7 )
  {
    v72 = 0;
    v70 = 0;
    v71 = 0;
    v68 = 0;
    v69 = 0;
    v67 = 0;
    memset(s, 0, sizeof(s));
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_direct_link_ut_cmd_store",
                          v8,
                          v9,
                          v10,
                          v11,
                          v12,
                          v13,
                          v14,
                          v15) )
    {
      v24 = _wlan_hdd_validate_context(
              *(_QWORD *)(a1 + 1336),
              (__int64)"__hdd_sysfs_direct_link_ut_cmd_store",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23);
      if ( v24 )
      {
        a4 = v24;
        goto LABEL_7;
      }
      if ( wlan_hdd_validate_modules_state(*(_QWORD *)(a1 + 1336), v25, v26, v27, v28, v29, v30, v31, v32) )
      {
        v34 = hdd_sysfs_validate_and_copy_buf(s, 513, a3, a4);
        if ( v34 )
        {
          v43 = v34;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "__hdd_sysfs_direct_link_ut_cmd_store");
          a4 = v43;
          goto LABEL_7;
        }
        stringp = s;
        v44 = strsep(&stringp, " ");
        if ( v44 )
        {
          if ( !(unsigned int)kstrtouint(v44, 0, &v67) && (unsigned int)v67 <= 5 )
          {
            if ( (v67 & 5) == 0 )
              goto LABEL_36;
            v45 = strsep(&stringp, " ");
            if ( v45 )
            {
              if ( !(unsigned int)kstrtouint(v45, 0, (char *)&v67 + 4) )
              {
                v46 = strsep(&stringp, " ");
                if ( v46 )
                {
                  if ( !(unsigned int)kstrtouint(v46, 0, &v68) )
                  {
                    v47 = strsep(&stringp, " ");
                    if ( v47 )
                    {
                      if ( !(unsigned int)kstrtouint(v47, 0, (char *)&v68 + 4) )
                      {
                        v48 = strsep(&stringp, " ");
                        if ( v48 )
                        {
                          if ( !(unsigned int)kstrtouint(v48, 0, &v69) )
                          {
                            v49 = strsep(&stringp, " ");
                            if ( v49 )
                            {
                              if ( !(unsigned int)kstrtou16(v49, 0, (char *)&v69 + 4) )
                              {
                                v50 = strsep(&stringp, " ");
                                if ( v50 )
                                {
                                  qdf_mac_parse((__int64)v50, (_BYTE *)&v69 + 6);
                                  if ( (_DWORD)v67 == 1 )
                                  {
                                    v55 = *(_WORD *)(a1 + 2933);
                                    HIDWORD(v70) = *(_DWORD *)(a1 + 2929);
                                    LOWORD(v71) = v55;
                                    goto LABEL_36;
                                  }
                                  if ( (_DWORD)v67 != 3
                                    || (v51 = strsep(&stringp, " ")) != nullptr
                                    && (qdf_mac_parse((__int64)v51, (_BYTE *)&v70 + 4),
                                        (v52 = strsep(&stringp, " ")) != nullptr)
                                    && (qdf_ipv4_parse((__int64)v52, (unsigned int *)((char *)&v71 + 2)),
                                        (v53 = strsep(&stringp, " ")) != nullptr)
                                    && (qdf_ipv4_parse((__int64)v53, (unsigned int *)((char *)&v71 + 6)),
                                        (v54 = strsep(&stringp, " ")) != nullptr)
                                    && !(unsigned int)kstrtou16(v54, 0, (char *)&v72 + 2) )
                                  {
LABEL_36:
                                    v56 = os_if_qmi_wfds_send_ut_cmd_req_msg(&v67);
                                    if ( v56 )
                                      qdf_trace_msg(
                                        0x33u,
                                        2u,
                                        "%s: failed to send command %d",
                                        v57,
                                        v58,
                                        v59,
                                        v60,
                                        v61,
                                        v62,
                                        v63,
                                        v64,
                                        "__hdd_sysfs_direct_link_ut_cmd_store",
                                        v56);
                                    goto LABEL_7;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    a4 = -22;
LABEL_7:
    _osif_vdev_sync_op_stop((__int64)v65, (__int64)"hdd_sysfs_direct_link_ut_cmd_store");
    goto LABEL_8;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
