__int64 __fastcall hdd_roam_register_tdlssta(
        __int64 a1,
        const void *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x19
  __int64 v15; // x0
  __int64 vdev_by_user; // x0
  __int64 v17; // x22
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _DWORD **v36; // x8
  _DWORD *v37; // x8
  __int64 v39; // [xsp+8h] [xbp-18h] BYREF
  int v40; // [xsp+10h] [xbp-10h]
  __int64 v41; // [xsp+18h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  v39 = 0;
  context = _cds_get_context(71, (__int64)"hdd_roam_register_tdlssta", a4, a5, a6, a7, a8, a9, a10, a11);
  qdf_mem_copy((char *)&v39 + 2, a2, 6u);
  v15 = *(_QWORD *)(a1 + 52824);
  LOBYTE(v39) = a3;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(v15, 97, "hdd_roam_register_tdlssta");
  if ( !vdev_by_user )
  {
    v18 = 4;
    goto LABEL_18;
  }
  v17 = vdev_by_user;
  v18 = ucfg_dp_tdlsta_register_txrx_ops(vdev_by_user);
  _hdd_objmgr_put_vdev_by_user(v17, 97, "hdd_roam_register_tdlssta");
  if ( v18 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: DP tx/rx ops register failed Status: %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "hdd_roam_register_tdlssta",
      v18);
    goto LABEL_18;
  }
  v27 = wlan_mlme_get_peer_ch_width(**(_QWORD **)(a1 + 24), (unsigned __int8 *)&v39 + 2) - 1;
  if ( v27 > 6 )
  {
    v40 = 0;
    if ( !context )
    {
LABEL_16:
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v28, v29, v30, v31, v32, v33, v34, v35, "cdp_peer_register");
      v18 = 4;
LABEL_17:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: cdp_peer_register() failed Status: %d [0x%08X]",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_roam_register_tdlssta",
        v18,
        v18);
      goto LABEL_18;
    }
  }
  else
  {
    v40 = dword_9FF410[v27];
    if ( !context )
      goto LABEL_16;
  }
  if ( !*context )
    goto LABEL_16;
  v36 = *(_DWORD ***)(*context + 72LL);
  if ( !v36 )
    goto LABEL_16;
  v37 = *v36;
  if ( !v37 )
  {
    v18 = 11;
    goto LABEL_17;
  }
  if ( *(v37 - 1) != -974215578 )
    __break(0x8228u);
  v18 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64 *))v37)(context, 0, &v39);
  if ( v18 )
    goto LABEL_17;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v18;
}
