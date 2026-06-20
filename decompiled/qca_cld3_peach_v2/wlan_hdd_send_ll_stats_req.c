void __fastcall wlan_hdd_send_ll_stats_req(
        unsigned __int8 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48,
        __int64 a49)
{
  __int64 v51; // x24
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x19
  __int64 *v61; // x8
  __int64 v62; // x23
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x24

  _ReadStatusReg(SP_EL0);
  v51 = *(_QWORD *)a1;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_send_ll_stats_req",
    *(_QWORD *)(*(_QWORD *)a1 + 32LL) + 296LL);
  if ( *(_DWORD *)(v51 + 1652) )
  {
    qdf_trace_msg(0x33u, 8u, "Previous ll_stats request is in progress", v52, v53, v54, v55, v56, v57, v58, v59);
    qdf_status_to_os_return(6u);
    JUMPOUT(0x39B728);
  }
  *(_DWORD *)(v51 + 1652) = 1;
  v60 = *(_QWORD *)a1;
  a48 = 0;
  a49 = 0;
  HIWORD(a47) = 0;
  v61 = *(__int64 **)(v60 + 24);
  if ( *((_BYTE *)v61 + 6945) == 1 )
  {
    v62 = *v61;
    if ( (ucfg_mc_cp_stats_is_req_pending(*v61, 1) & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Station stats request pending",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "wlan_hdd_set_station_stats_request_pending");
    }
    else if ( _hdd_objmgr_get_vdev_by_user((__int64)a1, 0x51u, (__int64)"wlan_hdd_set_station_stats_request_pending") )
    {
      if ( wlan_vdev_mlme_get_is_mlo_vdev(v62, a1[8]) )
      {
        v71 = **(_QWORD **)(v60 + 24);
        *(_BYTE *)(a2 + 12) = wlan_vdev_mlme_get_is_mlo_vdev(v71, *(unsigned __int8 *)(*(_QWORD *)(v60 + 52832) + 8LL));
        if ( (unsigned int)((__int64 (__fastcall *)(__int64, char *, _QWORD))mlo_get_mlstats_vdev_params)(
                             v71,
                             (char *)&a47 + 6,
                             *(unsigned __int8 *)(*(_QWORD *)(v60 + 52832) + 8LL)) )
          JUMPOUT(0x39A484);
        JUMPOUT(0x39A4BC);
      }
      JUMPOUT(0x39A5D8);
    }
  }
  JUMPOUT(0x39A684);
}
