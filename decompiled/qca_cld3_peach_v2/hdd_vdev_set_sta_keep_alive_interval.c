__int64 __fastcall hdd_vdev_set_sta_keep_alive_interval(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x24
  int v11; // w8
  const char *v12; // x4
  __int64 v13; // x19
  __int64 v14; // x20
  int v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x21
  __int64 link_info_by_vdev; // x0
  __int64 v35; // x20
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  __int64 v45; // x1
  __int64 result; // x0
  __int64 v47; // x4
  const char *v48; // x2
  const char *v49; // x3
  __int64 v50; // x0
  __int64 v51; // x1
  const char *v52; // x2
  const char *v53; // x3
  __int64 v54; // x20
  __int64 v55; // [xsp+8h] [xbp-28h] BYREF
  __int64 v56; // [xsp+10h] [xbp-20h]
  __int64 v57; // [xsp+18h] [xbp-18h]
  __int64 v58; // [xsp+20h] [xbp-10h]
  __int64 v59; // [xsp+28h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)*(unsigned __int16 *)(a2 + 4) - 256 <= 0xFFFFFF04 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Sta keep alive period: %d is out of range",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_vdev_set_sta_keep_alive_interval");
LABEL_27:
    result = 4294967274LL;
    goto LABEL_28;
  }
  v10 = *a1;
  v11 = *(_DWORD *)(*a1 + 40);
  if ( v11 > 2 )
  {
    if ( v11 <= 4 )
    {
      if ( v11 == 3 )
        v12 = "PM_P2P_GO_MODE";
      else
        v12 = "PM_NDI_MODE";
      goto LABEL_26;
    }
    if ( v11 == 5 )
    {
      v12 = "PM_NAN_DISC_MODE";
      goto LABEL_26;
    }
    if ( v11 == 6 )
    {
      v12 = "PM_LL_LT_SAP_MODE";
      goto LABEL_26;
    }
    goto LABEL_22;
  }
  if ( v11 )
  {
    if ( v11 == 1 )
    {
      v12 = "PM_SAP_MODE";
      goto LABEL_26;
    }
    if ( v11 == 2 )
    {
      v12 = "PM_P2P_CLIENT_MODE";
LABEL_26:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: This command is not supported for %s device mode",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "hdd_vdev_set_sta_keep_alive_interval",
        v12);
      goto LABEL_27;
    }
LABEL_22:
    v12 = "Unknown";
    goto LABEL_26;
  }
  v13 = *(_QWORD *)(v10 + 24);
  v14 = a1[4];
  v16 = *(unsigned __int16 *)(a2 + 4);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: sta keep alive interval = %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_vdev_set_sta_keep_alive_interval");
  *(_WORD *)(v10 + 71144) = v16;
  if ( (hdd_is_vdev_in_conn_state(a1) & 1) == 0 )
  {
    v47 = *((unsigned __int8 *)a1 + 8);
    v48 = "%s: Vdev (id %d) not in connected/started state, configure KEEPALIVE interval after connection";
    v49 = "hdd_vdev_set_sta_keep_alive_interval";
    goto LABEL_30;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(v14, v17, v18, v19, v20, v21, v22, v23, v24) & 1) == 0 )
  {
    v57 = 0;
    v58 = 0;
    v55 = 0;
    v56 = 0;
    qdf_mem_set(&v55, 0x20u, 0);
    v50 = *(_QWORD *)(v13 + 16);
    v51 = *((unsigned __int8 *)a1 + 8);
    goto LABEL_32;
  }
  v33 = *(_QWORD *)(v14 + 1360);
  if ( !v33 )
  {
    v52 = "%s: MLO dev context null";
    v53 = "hdd_ml_vdev_set_sta_keep_alive_interval";
    goto LABEL_35;
  }
  if ( *(_QWORD *)(v33 + 24) )
  {
    link_info_by_vdev = hdd_get_link_info_by_vdev(v13);
    if ( link_info_by_vdev )
    {
      v35 = link_info_by_vdev;
      if ( (hdd_is_vdev_in_conn_state(link_info_by_vdev) & 1) != 0 )
      {
        v57 = 0;
        v58 = 0;
        v55 = 0;
        v56 = 0;
        qdf_mem_set(&v55, 0x20u, 0);
        v44 = *(_QWORD *)(v13 + 16);
        v45 = *(unsigned __int8 *)(v35 + 8);
        HIDWORD(v55) = v16;
        LOBYTE(v55) = 1;
        if ( (unsigned int)sme_set_keep_alive(v44, v45, &v55) )
        {
LABEL_33:
          v52 = "%s: Failure to execute Keep Alive";
          v53 = "hdd_vdev_send_sta_keep_alive_interval";
LABEL_35:
          qdf_trace_msg(0x33u, 2u, v52, v25, v26, v27, v28, v29, v30, v31, v32, v53);
          goto LABEL_27;
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Vdev (id %d) not in connected/started state",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "hdd_ml_vdev_set_sta_keep_alive_interval",
          *(unsigned __int8 *)(v35 + 8));
      }
    }
  }
  if ( !*(_QWORD *)(v33 + 32) )
  {
    result = 0;
    goto LABEL_28;
  }
  result = hdd_get_link_info_by_vdev(v13);
  if ( result )
  {
    v54 = result;
    if ( (hdd_is_vdev_in_conn_state(result) & 1) != 0 )
    {
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      qdf_mem_set(&v55, 0x20u, 0);
      v50 = *(_QWORD *)(v13 + 16);
      v51 = *(unsigned __int8 *)(v54 + 8);
LABEL_32:
      HIDWORD(v55) = v16;
      LOBYTE(v55) = 1;
      result = sme_set_keep_alive(v50, v51, &v55);
      if ( !(_DWORD)result )
        goto LABEL_28;
      goto LABEL_33;
    }
    v47 = *(unsigned __int8 *)(v54 + 8);
    v48 = "%s: Vdev (id %d) not in connected/started state";
    v49 = "hdd_ml_vdev_set_sta_keep_alive_interval";
LABEL_30:
    qdf_trace_msg(0x33u, 8u, v48, v17, v18, v19, v20, v21, v22, v23, v24, v49, v47);
    result = 0;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
