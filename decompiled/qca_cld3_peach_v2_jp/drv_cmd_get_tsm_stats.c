__int64 __fastcall drv_cmd_get_tsm_stats(_DWORD *a1, __int64 a2, const char *a3, unsigned __int8 a4, __int64 *a5)
{
  __int64 v5; // x21
  unsigned int v6; // w8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  const char *v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w20
  __int64 v45; // x22
  __int64 v46; // x21
  __int64 v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x24
  __int64 v57; // x0
  unsigned int tsm_stats; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w20
  unsigned int v68; // w20
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w21
  int v78; // w8
  int v79; // w28
  int v80; // w22
  unsigned int v81; // w26
  unsigned int v82; // w23
  unsigned int v83; // w27
  unsigned int v84; // w24
  unsigned int v85; // w0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned __int16 *v94; // x0
  int v95; // w27
  int v96; // w22
  int v97; // w0
  signed int v98; // w8
  __int64 v99; // x19
  __int64 v100; // x20
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  int v109; // [xsp+8h] [xbp-C8h]
  unsigned int v110; // [xsp+30h] [xbp-A0h]
  unsigned int v111; // [xsp+34h] [xbp-9Ch]
  int v112; // [xsp+34h] [xbp-9Ch]
  int v113; // [xsp+38h] [xbp-98h]
  _BYTE v114[4]; // [xsp+3Ch] [xbp-94h] BYREF
  _QWORD v115[18]; // [xsp+40h] [xbp-90h] BYREF

  v115[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)a1;
  v6 = *(_DWORD *)(*(_QWORD *)a1 + 40LL);
  memset(v115, 0, 128);
  v114[0] = 0;
  if ( (v6 | 2) != 2 )
  {
    v27 = qdf_opmode_str(v6);
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Unsupported in mode %s(%d)",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "drv_cmd_get_tsm_stats",
      v27,
      *(unsigned int *)(v5 + 40));
    result = 4294967274LL;
    goto LABEL_19;
  }
  if ( !hdd_cm_is_vdev_associated(a1) )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Not associated!", v10, v11, v12, v13, v14, v15, v16, v17, "drv_cmd_get_tsm_stats");
    result = 4294967274LL;
    goto LABEL_19;
  }
  if ( (kstrtou8(&a3[a4 + 1], 10, v114) & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: kstrtou8 failed range [%d - %d]",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "drv_cmd_get_tsm_stats",
      0,
      15);
    result = 4294967274LL;
    goto LABEL_19;
  }
  if ( v114[0] < 0x10u )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Received Command to get tsm stats tid = %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "drv_cmd_get_tsm_stats");
    if ( v5 )
    {
      v44 = v114[0];
      v45 = *(_QWORD *)(v5 + 24);
      v46 = *(_QWORD *)(v5 + 52824);
      v47 = osif_request_alloc(hdd_get_tsm_stats_params);
      if ( v47 )
      {
        v56 = v47;
        v57 = osif_request_cookie(v47);
        tsm_stats = sme_get_tsm_stats(
                      *(_QWORD *)(v45 + 16),
                      hdd_get_tsm_stats_cb,
                      *(unsigned int *)(v46 + 300) | ((unsigned __int64)*(unsigned __int16 *)(v46 + 304) << 32),
                      v57,
                      v44);
        if ( tsm_stats )
        {
          v67 = tsm_stats;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Unable to retrieve tsm statistics",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "hdd_get_tsm_stats");
          v68 = qdf_status_to_os_return(v67);
          osif_request_put(v56);
          v77 = v68;
          if ( !v68 )
          {
            v78 = 0;
            v79 = 0;
            v80 = 0;
            v113 = 0;
            v81 = 0;
            v82 = 0;
            v83 = 0;
            v84 = 0;
            goto LABEL_21;
          }
        }
        else
        {
          v85 = osif_request_wait_for_response(v56);
          if ( !v85 )
          {
            v94 = (unsigned __int16 *)osif_request_priv(v56);
            v82 = v94[2];
            v81 = v94[3];
            v80 = *((_DWORD *)v94 + 3);
            v79 = v94[8];
            v110 = *v94;
            v111 = v94[1];
            v68 = v94[9];
            v77 = *((unsigned __int8 *)v94 + 20);
            v95 = v94[11];
            v113 = v94[4];
            osif_request_put(v56);
            v78 = v95;
            v84 = v110;
            v83 = v111;
LABEL_21:
            v112 = v80;
            v109 = v80;
            v96 = v78;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: UplinkPktQueueDly(%d) UplinkPktQueueDlyHist[0](%d) UplinkPktQueueDlyHist[1](%d) UplinkPktQueueDlyHist["
              "2](%d) UplinkPktQueueDlyHist[3](%d) UplinkPktTxDly(%u) UplinkPktLoss(%d) UplinkPktCount(%d) RoamingCount(%"
              "d) RoamingDly(%d)",
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              "drv_cmd_get_tsm_stats",
              v84,
              v83,
              v82,
              v81,
              v113,
              v109,
              v79,
              v68,
              v77,
              v78);
            scnprintf(
              v115,
              128,
              "%s %d %d:%d:%d:%d %u %d %d %d %d",
              a3,
              v84,
              v83,
              v82,
              v81,
              v113,
              v112,
              v79,
              v68,
              v77,
              v96);
            v98 = *((_DWORD *)a5 + 3);
            if ( v98 >= v97 + 1 )
              v98 = v97 + 1;
            v99 = v98;
            if ( (unsigned int)v98 >= 0x81 )
            {
              _copy_overflow(128, v98);
            }
            else
            {
              v100 = *a5;
              _check_object_size(v115, v98, 1);
              result = inline_copy_to_user(v100, v115, v99);
              if ( !result )
                goto LABEL_19;
            }
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: failed to copy data to user buffer",
              v101,
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              "drv_cmd_get_tsm_stats");
            result = 4294967282LL;
            goto LABEL_19;
          }
          v77 = v85;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: SME timed out while retrieving tsm statistics",
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            "hdd_get_tsm_stats");
          osif_request_put(v56);
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Request allocation failure",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "hdd_get_tsm_stats");
        v77 = -12;
      }
    }
    else
    {
      qdf_trace_msg(0x33u, 2u, "%s: adapter is NULL", v36, v37, v38, v39, v40, v41, v42, v43, "hdd_get_tsm_stats");
      v77 = -22;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to get tsm stats",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "drv_cmd_get_tsm_stats");
    result = v77;
    goto LABEL_19;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: tid value %d is out of range (Min: %d Max: %d)",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "drv_cmd_get_tsm_stats");
  result = 4294967274LL;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
