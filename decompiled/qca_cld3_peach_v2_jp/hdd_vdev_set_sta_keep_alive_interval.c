__int64 __fastcall hdd_vdev_set_sta_keep_alive_interval(
        unsigned __int8 *a1,
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
  __int64 v10; // x22
  int v11; // w8
  const char *v12; // x4
  __int64 v13; // x21
  int v15; // w20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _QWORD v35[5]; // [xsp+8h] [xbp-28h] BYREF

  v35[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
LABEL_22:
    result = 4294967274LL;
    goto LABEL_23;
  }
  v10 = *(_QWORD *)a1;
  v11 = *(_DWORD *)(*(_QWORD *)a1 + 40LL);
  if ( v11 > 2 )
  {
    if ( v11 <= 4 )
    {
      if ( v11 == 3 )
        v12 = "PM_P2P_GO_MODE";
      else
        v12 = "PM_NDI_MODE";
      goto LABEL_21;
    }
    if ( v11 == 5 )
    {
      v12 = "PM_NAN_DISC_MODE";
      goto LABEL_21;
    }
    if ( v11 == 6 )
    {
      v12 = "PM_LL_LT_SAP_MODE";
      goto LABEL_21;
    }
    goto LABEL_17;
  }
  if ( v11 )
  {
    if ( v11 == 1 )
    {
      v12 = "PM_SAP_MODE";
      goto LABEL_21;
    }
    if ( v11 == 2 )
    {
      v12 = "PM_P2P_CLIENT_MODE";
LABEL_21:
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
      goto LABEL_22;
    }
LABEL_17:
    v12 = "Unknown";
    goto LABEL_21;
  }
  v13 = *(_QWORD *)(v10 + 24);
  v15 = *(unsigned __int16 *)(a2 + 4);
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
  *(_WORD *)(v10 + 57392) = v15;
  if ( (hdd_is_vdev_in_conn_state(a1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Vdev (id %d) not in connected/started state, configure KEEPALIVE interval after connection",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_vdev_set_sta_keep_alive_interval",
      a1[8]);
    result = 0;
    goto LABEL_23;
  }
  memset(v35, 0, 32);
  qdf_mem_set(v35, 0x20u, 0);
  v24 = *(_QWORD *)(v13 + 16);
  v25 = a1[8];
  HIDWORD(v35[0]) = v15;
  LOBYTE(v35[0]) = 1;
  result = sme_set_keep_alive(v24, v25, v35);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failure to execute Keep Alive",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "hdd_vdev_send_sta_keep_alive_interval");
    goto LABEL_22;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
