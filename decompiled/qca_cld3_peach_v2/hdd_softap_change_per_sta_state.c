__int64 __fastcall hdd_softap_change_per_sta_state(
        unsigned __int8 *a1,
        unsigned __int8 *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x8
  __int64 sta_info_by_mac; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x23
  const void *v25; // x1
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w21
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 vdev_by_user; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x22
  unsigned int *v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x4
  __int64 v63; // x5
  __int64 v64; // x6
  __int64 v65; // x7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v75; // [xsp+18h] [xbp-18h] BYREF
  int v76; // [xsp+20h] [xbp-10h] BYREF
  __int16 v77; // [xsp+24h] [xbp-Ch]
  __int64 v78; // [xsp+28h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)a1;
  v77 = 0;
  v76 = 0;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "hdd_softap_change_per_sta_state",
    *(_QWORD *)(v14 + 32) + 296LL);
  sta_info_by_mac = hdd_get_sta_info_by_mac(*(_QWORD *)a1 + 38848LL, a2, 26, 1);
  v75 = sta_info_by_mac;
  if ( sta_info_by_mac )
  {
    v24 = sta_info_by_mac;
    if ( *(unsigned __int16 *)(sta_info_by_mac + 36) ^ 0xFFFF | ~*(_DWORD *)(sta_info_by_mac + 32) )
      v25 = a2;
    else
      v25 = a1 + 72;
    qdf_mem_copy(&v76, v25, 6u);
    v34 = hdd_change_peer_state(a1, (__int64)&v76, a3, v26, v27, v28, v29, v30, v31, v32, v33);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Vdev %d, Station %02x:%02x:%02x:**:**:%02x changed to state %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "hdd_softap_change_per_sta_state",
      a1[8],
      (unsigned __int8)v76,
      BYTE1(v76),
      BYTE2(v76),
      HIBYTE(v77),
      a3);
    if ( !v34 )
    {
      *(_DWORD *)(v24 + 44) = 3;
      vdev_by_user = _hdd_objmgr_get_vdev_by_user((__int64)a1, 6u, (__int64)"hdd_softap_change_per_sta_state");
      if ( vdev_by_user )
      {
        v52 = vdev_by_user;
        p2p_peer_authorized(vdev_by_user, a2, v44, v45, v46, v47, v48, v49, v50, v51);
        _hdd_objmgr_put_vdev_by_user(
          v52,
          6u,
          (__int64)"hdd_softap_change_per_sta_state",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61);
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: vdev is NULL",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "hdd_softap_change_per_sta_state");
      }
    }
    hdd_put_sta_info_ref(*(_QWORD *)a1 + 38848LL, &v75, 1, 26);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v66, v67, v68, v69, v70, v71, v72, v73, "hdd_softap_change_per_sta_state");
  }
  else
  {
    if ( a2 )
    {
      v62 = *a2;
      v63 = a2[1];
      v64 = a2[2];
      v65 = a2[5];
    }
    else
    {
      v64 = 0;
      v62 = 0;
      v63 = 0;
      v65 = 0;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Failed to find right station MAC: %02x:%02x:%02x:**:**:%02x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_softap_change_per_sta_state",
      v62,
      v63,
      v64,
      v65);
    v34 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v34;
}
