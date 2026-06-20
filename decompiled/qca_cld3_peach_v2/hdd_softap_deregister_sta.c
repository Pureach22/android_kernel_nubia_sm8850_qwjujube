__int64 __fastcall hdd_softap_deregister_sta(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 v11; // x20
  __int64 is_mlo_vdev; // x0
  __int64 v14; // x19
  __int64 v15; // x8
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
  __int64 v33; // x19
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int64 v43; // x9
  __int64 result; // x0
  const char *v45; // x2
  _QWORD v46[3]; // [xsp+8h] [xbp-18h] BYREF

  v46[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a2;
  v46[0] = *a2;
  if ( !a1 )
  {
    v45 = "%s: NULL adapter";
LABEL_33:
    qdf_trace_msg(0x33u, 2u, v45, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_softap_deregister_sta");
    goto LABEL_34;
  }
  if ( *(_DWORD *)a1 != 1885692259 )
  {
    v45 = "%s: Invalid adapter magic";
    goto LABEL_33;
  }
  if ( !v10 )
  {
    v45 = "%s: Invalid station";
    goto LABEL_33;
  }
  v11 = *(_QWORD *)(a1 + 24);
  if ( !v11 )
  {
    v45 = "%s: HDD context is null";
    goto LABEL_33;
  }
  if ( *(unsigned __int8 *)(v10 + 32) == 255
    && *(unsigned __int8 *)(v10 + 33) == 255
    && *(unsigned __int8 *)(v10 + 34) == 255
    && *(unsigned __int8 *)(v10 + 35) == 255
    && *(unsigned __int8 *)(v10 + 36) == 255
    && *(unsigned __int8 *)(v10 + 37) == 255 )
  {
    v14 = a1 + 1617;
    if ( (ucfg_ipa_is_enabled(a1) & 1) == 0 )
      goto LABEL_19;
    goto LABEL_15;
  }
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(*(_QWORD *)(a1 + 52832) + 32LL), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (is_mlo_vdev & 1) == 0 || (v14 = v10 + 38, !(*(_DWORD *)(v10 + 38) | *(unsigned __int16 *)(v10 + 42))) )
    v14 = v10 + 32;
  if ( (ucfg_ipa_is_enabled(is_mlo_vdev) & 1) != 0 )
  {
LABEL_15:
    v15 = *(_QWORD *)(v10 + 16);
    if ( !v15 )
      v15 = *(_QWORD *)(a1 + 52832);
    if ( (unsigned int)ucfg_ipa_wlan_evt(
                         *(_QWORD *)(v11 + 8),
                         *(_QWORD *)(a1 + 32),
                         *(unsigned int *)(a1 + 40),
                         *(unsigned __int8 *)(v15 + 8),
                         1,
                         v14,
                         0) )
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: WLAN_CLIENT_DISCONNECT event failed",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hdd_softap_deregister_sta");
  }
LABEL_19:
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x61u, (__int64)"hdd_softap_deregister_sta");
  if ( !vdev_by_user )
  {
LABEL_34:
    result = 4;
    goto LABEL_35;
  }
  v33 = vdev_by_user;
  ucfg_dp_del_latency_critical_client(
    vdev_by_user,
    *(unsigned __int8 *)(v10 + 164),
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32);
  _hdd_objmgr_put_vdev_by_user(
    v33,
    0x61u,
    (__int64)"hdd_softap_deregister_sta",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42);
  if ( *(unsigned __int8 *)(v10 + 32) != 255
    || *(unsigned __int8 *)(v10 + 33) != 255
    || *(unsigned __int8 *)(v10 + 34) != 255
    || *(unsigned __int8 *)(v10 + 35) != 255
    || *(unsigned __int8 *)(v10 + 36) != 255
    || *(unsigned __int8 *)(v10 + 37) != 255 )
  {
    v43 = *(unsigned __int8 *)(v10 + 164);
    if ( v43 <= 6 )
      --*(_WORD *)(*(_QWORD *)(a1 + 52832) + 2 * v43 + 2624);
  }
  hdd_sta_info_detach(a1 + 38848, v46);
  wlan_mlme_update_oce_flags(*(_QWORD *)(v11 + 8));
  result = 0;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
