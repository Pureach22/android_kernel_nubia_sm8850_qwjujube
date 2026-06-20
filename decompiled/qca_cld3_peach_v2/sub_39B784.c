// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_39B784@<X0>(
        __int64 a1@<X2>,
        __int64 a2@<X8>,
        double a3@<D0>,
        double a4@<D1>,
        double a5@<D2>,
        double a6@<D3>,
        double a7@<D4>,
        double a8@<D5>,
        double a9@<D6>,
        double a10@<D7>)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x22
  __int64 v46; // x20
  __int64 v47; // x23
  __int64 v48; // x1
  bool is_mlo_vdev; // w0
  unsigned int v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w20
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned __int8 v68; // w8
  __int64 v69; // x0
  int v70; // w20
  __int64 result; // x0
  __int64 v72; // x20
  __int64 v73; // x22
  __int64 *v74; // x25
  __int64 v75; // x27
  __int64 v76; // x28
  __int64 v77; // x29
  __int64 v78; // [xsp-310h] [xbp-310h]
  __int64 v79; // [xsp-308h] [xbp-308h] BYREF

  qdf_trace_msg(
    0x33u,
    2u,
    (const char *)(a1 + 340),
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_get_mlo_vdev_params",
    *(unsigned __int8 *)(a2 + v73));
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: unable to get vdev params for mlo stats",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlan_hdd_set_station_stats_request_pending");
  _hdd_objmgr_put_vdev_by_user(
    v72,
    0x51u,
    (__int64)"wlan_hdd_set_station_stats_request_pending",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26);
  v35 = qdf_trace_msg(0x33u, 8u, "Requesting LL_STATS only", v27, v28, v29, v30, v31, v32, v33, v34);
  *(_BYTE *)(v75 + 20) = 0;
  sme_radio_tx_mem_free(v35);
  v36 = osif_request_alloc(&wlan_hdd_send_ll_stats_req_params);
  if ( v36 )
  {
    v45 = v36;
    v46 = osif_request_cookie(v36);
    v47 = osif_request_priv(v45);
    *(_DWORD *)(v47 + 24) = *(_DWORD *)v75;
    *(_DWORD *)(v47 + 28) = *(_DWORD *)(v75 + 8);
    v48 = *(unsigned __int8 *)(v78 + 8);
    *(_BYTE *)(v47 + 48) = v48;
    is_mlo_vdev = wlan_vdev_mlme_get_is_mlo_vdev(*v74, v48);
    *(_BYTE *)(v47 + 49) = is_mlo_vdev;
    if ( is_mlo_vdev )
      *(_DWORD *)(v47 + 52) = *(_DWORD *)(v75 + 16);
    *(_QWORD *)(v47 + 40) = 0;
    *(_DWORD *)(v47 + 32) = 0;
    *(_QWORD *)v47 = v47;
    *(_QWORD *)(v47 + 8) = v47;
    *(_QWORD *)(v47 + 16) = 0x500000000LL;
    v50 = ((__int64 (__fastcall *)(__int64, __int64, __int64))sme_ll_stats_get_req)(v74[2], v75, v46);
    if ( v50 )
    {
      v59 = v50;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: sme_ll_stats_get_req Failed",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "wlan_hdd_send_ll_stats_req");
      qdf_status_to_os_return(v59);
      JUMPOUT(0x39A764);
    }
    if ( (unsigned int)osif_request_wait_for_response(v45) )
    {
      v68 = *(_BYTE *)(v76 + 42081) + 1;
      *(_BYTE *)(v76 + 42081) = v68;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Target response timed out request id %d request bitmap 0x%x ll_stats failure count %d",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "wlan_hdd_send_ll_stats_req",
        *(unsigned int *)(v47 + 24),
        *(unsigned int *)(v47 + 28),
        v68);
      raw_spin_lock(v47 + 32);
      *(_DWORD *)(v47 + 28) = 0;
      v69 = raw_spin_unlock(v47 + 32);
      sme_radio_tx_mem_free(v69);
    }
    else
    {
      *(_BYTE *)(v76 + 42081) = 0;
    }
    raw_spin_lock(v47 + 32);
    v70 = qdf_list_remove_front((_DWORD *)v47, &v79);
    raw_spin_unlock(v47 + 32);
    if ( v70 )
      JUMPOUT(0x39A8B0);
    JUMPOUT(0x39A9C0);
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Request Allocation Failure",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "wlan_hdd_send_ll_stats_req");
  result = 4294967284LL;
  if ( *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808) != *(_QWORD *)(v77 - 16) )
    JUMPOUT(0x39C5A4);
  return result;
}
