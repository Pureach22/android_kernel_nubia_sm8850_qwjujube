__int64 __fastcall hdd_get_sta_keepalive_interval(
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
  __int64 v10; // x22
  int v11; // w8
  __int64 *v12; // x21
  const char *v13; // x4
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 vdev_by_user; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x21
  unsigned int keepalive_period; // w20
  __int64 result; // x0
  const char *v36; // x2
  __int64 v37; // [xsp+0h] [xbp-10h] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  LODWORD(v37) = 0;
  v11 = *(_DWORD *)(v10 + 40);
  v12 = *(__int64 **)(v10 + 24);
  if ( v11 > 2 )
  {
    if ( v11 <= 4 )
    {
      if ( v11 == 3 )
        v13 = "PM_P2P_GO_MODE";
      else
        v13 = "PM_NDI_MODE";
      goto LABEL_19;
    }
    if ( v11 == 5 )
    {
      v13 = "PM_NAN_DISC_MODE";
      goto LABEL_19;
    }
    if ( v11 == 6 )
    {
      v13 = "PM_LL_LT_SAP_MODE";
      goto LABEL_19;
    }
LABEL_15:
    v13 = "Unknown";
    goto LABEL_19;
  }
  if ( !v11 )
  {
    if ( (hdd_is_vdev_in_conn_state(a1) & 1) != 0 )
    {
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 88, "hdd_get_sta_keepalive_interval");
      if ( !vdev_by_user )
      {
        v36 = "%s: vdev is NULL";
LABEL_28:
        qdf_trace_msg(0x33u, 2u, v36, v25, v26, v27, v28, v29, v30, v31, v32, "hdd_get_sta_keepalive_interval", v37);
        goto LABEL_20;
      }
      v33 = vdev_by_user;
      keepalive_period = (unsigned __int16)wlan_mlme_get_keepalive_period(
                                             vdev_by_user,
                                             v25,
                                             v26,
                                             v27,
                                             v28,
                                             v29,
                                             v30,
                                             v31,
                                             v32);
      LODWORD(v37) = keepalive_period;
      _hdd_objmgr_put_vdev_by_user(v33, 88, "hdd_get_sta_keepalive_interval");
    }
    else
    {
      keepalive_period = *(unsigned __int16 *)(v10 + 71144);
      if ( *(_WORD *)(v10 + 71144) )
      {
        LODWORD(v37) = *(unsigned __int16 *)(v10 + 71144);
      }
      else
      {
        ucfg_mlme_get_sta_keep_alive_period(*v12, (int *)&v37);
        keepalive_period = v37;
      }
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: STA KEEPALIVE interval = %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_get_sta_keepalive_interval",
      keepalive_period,
      v37,
      v38);
    WORD2(v37) = v37;
    result = nla_put(a2, 108, 2, (char *)&v37 + 4);
    if ( !(_DWORD)result )
      goto LABEL_21;
    v36 = "%s: nla_put failure";
    goto LABEL_28;
  }
  if ( v11 == 1 )
  {
    v13 = "PM_SAP_MODE";
    goto LABEL_19;
  }
  if ( v11 != 2 )
    goto LABEL_15;
  v13 = "PM_P2P_CLIENT_MODE";
LABEL_19:
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
    "hdd_get_sta_keepalive_interval",
    v13,
    v37,
    v38);
LABEL_20:
  result = 4294967274LL;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
