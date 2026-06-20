__int64 __fastcall wlan_hdd_init_mon_link(
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
  _QWORD *context; // x22
  __int64 vdev_by_user; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x23
  const void *v23; // x1
  unsigned int v24; // w0
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int mon_session; // w21
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  _DWORD **v52; // x8
  _DWORD *v53; // x8
  const char *v54; // x2
  bool v56; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v57; // [xsp+8h] [xbp-18h] BYREF
  int v58; // [xsp+10h] [xbp-10h]
  __int64 v59; // [xsp+18h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  v57 = 0;
  context = _cds_get_context(71, (__int64)"wlan_hdd_init_mon_link", a3, a4, a5, a6, a7, a8, a9, a10);
  v56 = 0;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a2, 0x61u, (__int64)"wlan_hdd_init_mon_link");
  if ( !vdev_by_user )
  {
    qdf_trace_msg(0x33u, 2u, "%s: failed to get vdev", v14, v15, v16, v17, v18, v19, v20, v21, "wlan_hdd_init_mon_link");
    mon_session = 4;
    goto LABEL_20;
  }
  v22 = vdev_by_user;
  ucfg_psoc_mlme_get_11be_capab(*a1, &v56);
  if ( v56 )
    v23 = (const void *)(a2 + 72);
  else
    v23 = (const void *)(v22 + 74);
  qdf_mem_copy((char *)&v57 + 2, v23, 6u);
  v24 = ucfg_dp_mon_register_txrx_ops(v22);
  if ( !v24 )
  {
    _hdd_objmgr_put_vdev_by_user(
      v22,
      0x61u,
      (__int64)"wlan_hdd_init_mon_link",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33);
    if ( context && *context && (v52 = *(_DWORD ***)(*context + 72LL)) != nullptr )
    {
      v53 = *v52;
      if ( v53 )
      {
        if ( *(v53 - 1) != -974215578 )
          __break(0x8228u);
        mon_session = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64 *))v53)(context, 0, &v57);
        if ( !mon_session )
        {
          mon_session = sme_create_mon_session(a1[2], (char *)&v57 + 2, *(unsigned __int8 *)(a2 + 8));
          if ( !mon_session )
            goto LABEL_20;
          v54 = "%s: sme_create_mon_session() failed to register. Status= %d [0x%08X]";
LABEL_19:
          qdf_trace_msg(
            0x33u,
            2u,
            v54,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "wlan_hdd_init_mon_link",
            mon_session,
            mon_session);
          goto LABEL_20;
        }
      }
      else
      {
        mon_session = 11;
      }
    }
    else
    {
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v44, v45, v46, v47, v48, v49, v50, v51, "cdp_peer_register");
      mon_session = 4;
    }
    v54 = "%s: cdp_peer_register() failed to register. Status= %d [0x%08X]";
    goto LABEL_19;
  }
  mon_session = v24;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: failed to register txrx ops. Status= %d [0x%08X]",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wlan_hdd_init_mon_link",
    mon_session,
    mon_session);
  _hdd_objmgr_put_vdev_by_user(
    v22,
    0x61u,
    (__int64)"wlan_hdd_init_mon_link",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43);
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return mon_session;
}
