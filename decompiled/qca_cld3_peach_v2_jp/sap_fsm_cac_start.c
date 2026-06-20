__int64 __fastcall sap_fsm_cac_start(
        unsigned int *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *context; // x0
  __int64 v22; // x19
  const char *v23; // x2
  __int64 v24; // x19
  _DWORD *v25; // x26
  const char *v26; // x2
  __int64 v27; // x25
  bool v28; // zf
  __int64 v29; // x0
  __int64 active_channel; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w0
  __int64 result; // x0
  __int64 v41; // x3
  unsigned int v42; // w21
  unsigned int v43; // w20
  __int64 v44; // [xsp+0h] [xbp-10h] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a2 + 14809) )
    goto LABEL_11;
  v12 = a3;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: sapdfs: starting dfs cac timer on sapctx[%pK]",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sap_fsm_cac_start",
    a1);
  LODWORD(v44) = 0;
  if ( !a1 )
  {
    v23 = "%s: null sap_ctx";
LABEL_9:
    qdf_trace_msg(0x39u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "sap_start_dfs_cac_timer", v44, v45);
    goto LABEL_10;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !context )
  {
    v23 = "%s: Invalid MAC context";
    goto LABEL_9;
  }
  v22 = (__int64)context;
  if ( *((_BYTE *)a1 + 1627) == 1 )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: cac timer offloaded to firmware",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sap_start_dfs_cac_timer",
      v44,
      v45);
  }
  else
  {
    v41 = *a1;
    HIDWORD(v44) = 0;
    ((void (__fastcall *)(unsigned int *, char *, __int64 *, __int64, unsigned int *))sap_get_cac_dur_dfs_region)(
      a1,
      (char *)&v44 + 4,
      &v44,
      v41,
      a1 + 375);
    v42 = HIDWORD(v44);
    if ( !HIDWORD(v44) )
      goto LABEL_10;
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: sapdfs: SAP_DFS_CHANNEL_CAC_START on CH freq %d, CAC_DUR-%d sec",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sap_start_dfs_cac_timer",
      *a1,
      HIDWORD(v44) / 0x3E8uLL,
      v44,
      v45);
    qdf_mc_timer_init(v22 + 14640, 0, (__int64)sap_dfs_cac_timer_callback, v22);
    if ( (unsigned int)qdf_mc_timer_start(v22 + 14640, v42) )
    {
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: failed to start cac timer",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "sap_start_dfs_cac_timer");
      *(_BYTE *)(v22 + 14809) = 0;
      qdf_mc_timer_destroy(v22 + 14640);
      goto LABEL_10;
    }
  }
  *(_BYTE *)(v22 + 14809) = 1;
LABEL_10:
  a3 = v12;
LABEL_11:
  v24 = 0;
  v25 = (_DWORD *)(a3 + 14824);
  while ( 1 )
  {
    v27 = *((_QWORD *)v25 - 1);
    v28 = (*v25 | 2) != 3 || v27 == 0;
    if ( v28 || (*(_BYTE *)(v27 + 1554) & 1) != 0 )
      goto LABEL_14;
    v29 = *(_QWORD *)(v27 + 16);
    if ( v29 )
      break;
    v26 = "%s: vdev invalid";
LABEL_13:
    qdf_trace_msg(0x39u, 8u, v26, a4, a5, a6, a7, a8, a9, a10, a11, "sap_operating_on_dfs", v44);
LABEL_14:
    ++v24;
    v25 += 4;
    if ( v24 == 6 )
    {
      result = 0;
      goto LABEL_27;
    }
  }
  active_channel = wlan_vdev_get_active_channel(v29);
  if ( !active_channel )
  {
    v26 = "%s: Couldn't get vdev active channel";
    goto LABEL_13;
  }
  if ( (*(_WORD *)(active_channel + 6) & 6) == 0 )
    goto LABEL_14;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: sapdfs: Signaling eSAP_DFS_CAC_START to HDD for sapctx[%pK]",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sap_cac_start_notify",
    v27);
  v39 = sap_signal_hdd_event(v27, 0, 0xEu, nullptr, v31, v32, v33, v34, v35, v36, v37, v38);
  if ( !v39 )
  {
    *(_BYTE *)(v27 + 1554) = 1;
    goto LABEL_14;
  }
  v43 = v39;
  qdf_trace_msg(
    0x39u,
    2u,
    "%s: Failed setting isCacStartNotified on interface[%d]",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sap_cac_start_notify",
    (unsigned int)v24);
  result = v43;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
