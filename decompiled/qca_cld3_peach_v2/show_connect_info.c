__int64 __fastcall show_connect_info(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  long double v23; // q0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  int v33; // w0
  __int64 v34; // x24
  unsigned __int64 v35; // x23
  unsigned int v36; // w0
  __int64 v37; // x25
  unsigned __int64 v38; // x1
  unsigned int v39; // w23
  int v40; // w0
  int v41; // w8
  int v42; // w0
  __int64 v43; // x0
  __int64 v44; // x1
  __int64 v45; // x2
  __int64 v46; // x0
  __int64 *v47; // [xsp+18h] [xbp-28h] BYREF
  _QWORD v48[4]; // [xsp+20h] [xbp-20h] BYREF

  v48[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, &v47, (__int64)"show_connect_info");
  if ( !v5 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v6, v7, v8, v9, v10, v11, v12, v13, "__show_connect_info", a1 - 1080);
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__show_connect_info",
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22)
      || (v31 = *(_QWORD *)(a1 + 1336),
          (unsigned int)_wlan_hdd_validate_context(
                          v31,
                          (__int64)"__show_connect_info",
                          *(double *)&v23,
                          v24,
                          v25,
                          v26,
                          v27,
                          v28,
                          v29,
                          v30)) )
    {
      v14 = 0;
    }
    else
    {
      memset(v48, 0, 24);
      qdf_get_time_of_the_day_in_hr_min_sec_usec((__int64)v48, 24);
      *(double *)&v23 = scnprintf(a3, 4096, "\nTime at which this file generated = %s\n", (const char *)v48);
      if ( v33 < 4096 )
      {
        v34 = v33 & (unsigned int)~(v33 >> 31);
        v35 = 4096 - v34;
        *(double *)&v23 = scnprintf(a3 + v34, 4096 - v34, "\nVERSION DETAILS\n", *(double *)&v23);
        if ( (int)v36 < 1 )
        {
          v37 = 0;
        }
        else
        {
          v37 = v36;
          v38 = v35 - v36;
          if ( v35 <= v36 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: No sufficient buf_avail_len",
              *(double *)&v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "wlan_hdd_version_info");
            v37 = 4096 - v34;
          }
          else
          {
            v39 = v36;
            *(double *)&v23 = scnprintf(
                                a3 + v34 + v36,
                                v38,
                                "Host Driver Version: %s\nFirmware Version: %d.%d.%d.%d.%d.%d\nHardware Version: %s\n",
                                "5.2.1.137C",
                                *(_DWORD *)(v31 + 540),
                                *(_DWORD *)(v31 + 544),
                                *(_DWORD *)(v31 + 548),
                                *(_DWORD *)(v31 + 556),
                                *(_DWORD *)(v31 + 560),
                                *(_DWORD *)(v31 + 552),
                                (const char *)(v31 + 572));
            if ( v40 >= 1 )
              v37 = v40 + v39;
          }
        }
        v14 = v37 + v34;
        if ( (unsigned __int64)(v37 + v34) < 0x1000 )
        {
          v41 = *(_DWORD *)(a1 + 1352);
          if ( (v41 & 0xFFFFFFFD) != 0 )
          {
            *(double *)&v23 = scnprintf(a3 + v14, 4096 - v14, "Not in STA or P2P_CLIENT Mode\n", *(double *)&v23);
            if ( v42 >= 1 )
              v14 += (unsigned int)v42;
            goto LABEL_6;
          }
          v43 = a1 + 1312;
          v44 = a3 + v14;
          v45 = 4096 - v14;
          if ( v41 )
            v46 = wlan_hdd_p2p_connection_info(v43, v44, v45, v23);
          else
            v46 = wlan_hdd_connect_info(v43, v44, v45, v23);
          v14 += v46;
          if ( v14 < 4096 )
            goto LABEL_6;
        }
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: No sufficient buf_avail_len",
        *(double *)&v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "__show_connect_info");
      v14 = 4096;
    }
LABEL_6:
    qdf_trace_msg(0x33u, 8u, "%s: exit", *(double *)&v23, v24, v25, v26, v27, v28, v29, v30, "__show_connect_info");
    _osif_vdev_sync_op_stop((__int64)v47, (__int64)"show_connect_info");
    goto LABEL_7;
  }
  v14 = v5;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v14;
}
