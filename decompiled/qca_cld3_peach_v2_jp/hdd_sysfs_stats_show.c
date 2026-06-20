__int64 __fastcall hdd_sysfs_stats_show(__int64 a1, __int64 a2, __int64 a3)
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
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 *v34; // x24
  __int64 v35; // x22
  __int64 vdev_by_user; // x0
  __int64 v37; // x23
  __int64 v38; // x0
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  _DWORD *v48; // x21
  unsigned int *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int *v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x1
  int v68; // w9
  int v69; // w11
  int v70; // w13
  int v71; // w14
  int v72; // w7
  int v73; // w8
  int v74; // w10
  int v75; // w12
  int v76; // w6
  int v77; // w5
  int v78; // w4
  int v79; // w17
  int v80; // w0
  int v81; // w15
  int v82; // w16
  int *v83; // x2
  _DWORD *v84; // x3
  int v85; // t1
  unsigned int v86; // w0
  unsigned int v87; // w23
  __int64 v88; // x24
  _DWORD *v89; // x28
  int v90; // w4
  int v91; // w0
  const char *v92; // x3
  double v93; // d0
  int v94; // w0
  __int64 v95; // x22
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  _QWORD *context; // x0
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // x8
  _DWORD *v113; // x8
  __int64 v114; // x0
  int v115; // w0
  __int64 *v116; // [xsp+A0h] [xbp-20h] BYREF
  _BYTE v117[4]; // [xsp+A8h] [xbp-18h] BYREF
  _BYTE v118[4]; // [xsp+ACh] [xbp-14h] BYREF
  __int64 v119; // [xsp+B0h] [xbp-10h]

  v119 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v116 = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, &v116, (__int64)"hdd_sysfs_stats_show");
  if ( !v5 )
  {
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_stats_show",
                         v6,
                         v7,
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13) )
      goto LABEL_4;
    v23 = *(_QWORD *)(a1 + 1336);
    v24 = _wlan_hdd_validate_context(v23, (__int64)"__hdd_sysfs_stats_show", v15, v16, v17, v18, v19, v20, v21, v22);
    if ( v24 )
    {
      v14 = v24;
      goto LABEL_7;
    }
    if ( !wlan_hdd_validate_modules_state(v23, v25, v26, v27, v28, v29, v30, v31, v32) )
    {
LABEL_4:
      v14 = -22;
LABEL_7:
      _osif_vdev_sync_op_stop((__int64)v116, (__int64)"hdd_sysfs_stats_show");
      goto LABEL_8;
    }
    v34 = *(__int64 **)(a1 + 1336);
    v35 = *(_QWORD *)(a1 + 54136);
    v118[0] = 0;
    v117[0] = 0;
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(v35, 0x61u, (__int64)"hdd_sysfs_get_stats");
    if ( !vdev_by_user )
    {
LABEL_14:
      v14 = 0;
      goto LABEL_7;
    }
    v37 = vdev_by_user;
    v38 = _qdf_mem_malloc(0x9B8u, "hdd_sysfs_get_stats", 61);
    if ( !v38 )
    {
      _hdd_objmgr_put_vdev_by_user(
        v37,
        0x61u,
        (__int64)"hdd_sysfs_get_stats",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47);
      v14 = 0;
      goto LABEL_7;
    }
    v48 = (_DWORD *)v38;
    if ( (unsigned int)ucfg_dp_get_txrx_stats(v37, v38, v40, v41, v42, v43, v44, v45, v46, v47) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Unable to get stats from DP component",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "hdd_sysfs_get_stats");
      _hdd_objmgr_put_vdev_by_user(
        v37,
        0x61u,
        (__int64)"hdd_sysfs_get_stats",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66);
      _qdf_mem_free((__int64)v48);
      goto LABEL_14;
    }
    _hdd_objmgr_put_vdev_by_user(
      v37,
      0x61u,
      (__int64)"hdd_sysfs_get_stats",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57);
    ucfg_dp_get_disable_rx_ol_val(*v34, v118, v117);
    v67 = 0;
    v68 = 0;
    v69 = 0;
    v70 = 0;
    v71 = 0;
    v72 = 0;
    v73 = 0;
    v74 = 0;
    v75 = 0;
    v76 = 0;
    v77 = 0;
    v78 = 0;
    v79 = 0;
    v80 = 0;
    v81 = 0;
    v82 = 0;
    v83 = (int *)(v35 + 2712);
    do
    {
      v84 = &v48[v67];
      v67 += 19;
      v72 += *(v83 - 3);
      v73 += *(v83 - 2);
      v68 += *(v83 - 7);
      v69 += *(v83 - 6);
      v74 += *(v83 - 1);
      v71 += *(v83 - 4);
      v70 += *(v83 - 5);
      v85 = *v83;
      v83 += 12;
      v82 += v84[15];
      v81 += v84[16];
      v80 += v84[17];
      v75 += v85;
      v79 += v84[18];
      v78 += *v84;
      v77 += v84[1];
      v76 += v84[2];
    }
    while ( v67 != 608 );
    scnprintf(
      a3,
      4096,
      "\n"
      "Transmit[%lu] - called %u, dropped %u orphan %u,\n"
      "[dropped]    BK %u, BE %u, VI %u, VO %u\n"
      "[classified] BK %u, BE %u, VI %u, VO %u\n"
      "\n"
      "Receive[%lu] - packets %u, dropped %u, unsolict_arp_n_mcast_drp %u, delivered %u, refused %u\n"
      "GRO - agg %u non-agg %u flush_skip %u low_tput_flush %u disabled(conc %u low-tput %u)\n",
      jiffies,
      v78,
      v77,
      v76,
      v72,
      v73,
      v74,
      v75,
      v68,
      v69,
      v70,
      v71,
      jiffies,
      v82,
      v81,
      v48[608],
      v80,
      v79,
      v48[609],
      v48[611],
      v48[612],
      v48[613],
      v118[0],
      v117[0]);
    v87 = v86;
    v88 = 0;
    v89 = v48 + 18;
    do
    {
      v90 = *(v89 - 3);
      if ( v90 )
      {
        scnprintf(
          a3 + v87,
          4096LL - v87,
          "Rx CPU[%d]:packets %u, dropped %u, delivered %u, refused %u\n",
          v88,
          v90,
          *(v89 - 2),
          *(v89 - 1),
          *v89);
        v87 += v91;
      }
      ++v88;
      v89 += 19;
    }
    while ( v88 != 32 );
    if ( *(_BYTE *)(v35 + 4220) )
      v92 = "PAUSED";
    else
      v92 = "UNPAUSED";
    v93 = scnprintf(
            a3 + v87,
            4096LL - v87,
            "\nTX_FLOW\nCurrent status: %s\ntx-flow timer start count %u\npause count %u, unpause count %u",
            v92,
            *(_DWORD *)(v35 + 4232),
            *(_DWORD *)(v35 + 4224),
            *(_DWORD *)(v35 + 4228));
    v95 = v94 + v87;
    context = _cds_get_context(71, (__int64)"hdd_sysfs_get_stats", v93, v96, v97, v98, v99, v100, v101, v102);
    if ( context && *context )
    {
      v112 = *(_QWORD *)(*context + 88LL);
      if ( v112 )
      {
        v113 = *(_DWORD **)(v112 + 8);
        if ( v113 )
        {
          v114 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 54136) + 8LL);
          if ( *(v113 - 1) != 1684093571 )
            __break(0x8228u);
          v115 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v113)(v114, a3 + v95, (unsigned int)(4096 - v95));
          goto LABEL_34;
        }
      }
    }
    else
    {
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v104, v105, v106, v107, v108, v109, v110, v111, "cdp_stats");
    }
    v115 = 0;
LABEL_34:
    v14 = (unsigned int)(v95 + v115 + 1);
    _qdf_mem_free((__int64)v48);
    goto LABEL_7;
  }
  v14 = v5;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v14;
}
