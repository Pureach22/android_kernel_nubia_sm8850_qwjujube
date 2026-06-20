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
  __int64 v12; // x19
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 vdev_by_user; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x19
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned __int64 v42; // x9
  __int64 result; // x0
  const char *v44; // x2
  __int64 v45; // [xsp+0h] [xbp-10h] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a2;
  v45 = *a2;
  if ( !a1 )
  {
    v44 = "%s: NULL adapter";
LABEL_31:
    qdf_trace_msg(0x33u, 2u, v44, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_softap_deregister_sta", v45, v46);
LABEL_32:
    result = 4;
    goto LABEL_33;
  }
  if ( *(_DWORD *)a1 != 1885692259 )
  {
    v44 = "%s: Invalid adapter magic";
    goto LABEL_31;
  }
  if ( !v10 )
  {
    v44 = "%s: Invalid station";
    goto LABEL_31;
  }
  v11 = *(_QWORD *)(a1 + 24);
  if ( !v11 )
  {
    v44 = "%s: HDD context is null";
    goto LABEL_31;
  }
  v12 = v10 + 32;
  if ( *(unsigned __int8 *)(v10 + 32) == 255
    && *(unsigned __int8 *)(v10 + 33) == 255
    && *(unsigned __int8 *)(v10 + 34) == 255
    && *(unsigned __int8 *)(v10 + 35) == 255
    && *(unsigned __int8 *)(v10 + 36) == 255
    && *(unsigned __int8 *)(v10 + 37) == 255 )
  {
    v12 = a1 + 1617;
  }
  if ( (ucfg_ipa_is_enabled(a1) & 1) != 0 )
  {
    v14 = *(_QWORD *)(v10 + 16);
    if ( !v14 )
      v14 = *(_QWORD *)(a1 + 52824);
    if ( (unsigned int)ucfg_ipa_wlan_evt(
                         *(_QWORD *)(v11 + 8),
                         *(_QWORD *)(a1 + 32),
                         *(unsigned int *)(a1 + 40),
                         *(unsigned __int8 *)(v14 + 8),
                         1,
                         v12,
                         0) )
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: WLAN_CLIENT_DISCONNECT event failed",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hdd_softap_deregister_sta",
        v45,
        v46);
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52824), 0x61u, (__int64)"hdd_softap_deregister_sta");
  if ( !vdev_by_user )
    goto LABEL_32;
  v32 = vdev_by_user;
  ucfg_dp_del_latency_critical_client(
    vdev_by_user,
    *(unsigned __int8 *)(v10 + 164),
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31);
  _hdd_objmgr_put_vdev_by_user(
    v32,
    0x61u,
    (__int64)"hdd_softap_deregister_sta",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41);
  if ( *(unsigned __int8 *)(v10 + 32) != 255
    || *(unsigned __int8 *)(v10 + 33) != 255
    || *(unsigned __int8 *)(v10 + 34) != 255
    || *(unsigned __int8 *)(v10 + 35) != 255
    || *(unsigned __int8 *)(v10 + 36) != 255
    || *(unsigned __int8 *)(v10 + 37) != 255 )
  {
    v42 = *(unsigned __int8 *)(v10 + 164);
    if ( v42 <= 6 )
      --*(_WORD *)(*(_QWORD *)(a1 + 52824) + 2 * v42 + 2352);
  }
  hdd_sta_info_detach(a1 + 38848, &v45);
  wlan_mlme_update_oce_flags(*(_QWORD *)(v11 + 8));
  result = 0;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
