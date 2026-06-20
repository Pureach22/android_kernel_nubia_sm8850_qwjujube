__int64 __fastcall tdls_recv_discovery_resp(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  __int64 peer; // x0
  __int64 v26; // x21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w8
  int v36; // w8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x0
  void (__fastcall *v63)(__int64, __int64, __int64 *); // x9
  __int64 result; // x0
  const char *v65; // x2
  const char *v66; // x2
  __int64 v67; // [xsp+0h] [xbp-50h]
  __int64 v68; // [xsp+8h] [xbp-48h]
  __int64 v69; // [xsp+28h] [xbp-28h]
  __int64 v70; // [xsp+30h] [xbp-20h] BYREF
  __int64 v71; // [xsp+38h] [xbp-18h] BYREF
  __int64 v72; // [xsp+40h] [xbp-10h]
  __int64 v73; // [xsp+48h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_25;
  v10 = *(_QWORD *)a1;
  v71 = 0;
  v72 = 0;
  v70 = 0;
  if ( !v10 )
  {
    v65 = "%s: NULL vdev";
    goto LABEL_22;
  }
  v12 = *(_QWORD *)(v10 + 216);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v65 = "%s: can't get psoc";
LABEL_22:
    qdf_trace_msg(0, 2u, v65, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_23;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_23:
    v66 = "%s: tdls soc is NULL";
LABEL_24:
    qdf_trace_msg(0, 2u, v66, v16, v17, v18, v19, v20, v21, v22, v23, "tdls_recv_discovery_resp");
LABEL_25:
    result = 4294967274LL;
    goto LABEL_26;
  }
  v24 = comp_private_obj;
  peer = tdls_get_peer(a1, a2);
  if ( !peer )
  {
    v66 = "%s: curr_peer is NULL";
    goto LABEL_24;
  }
  v26 = peer;
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)a1, v16, v17, v18, v19, v20, v21, v22, v23) & 1) == 0 )
  {
    v35 = *(_DWORD *)(a1 + 768);
    if ( !v35 || (v36 = v35 - 1, (*(_DWORD *)(a1 + 768) = v36) == 0) )
      qdf_mc_timer_stop(a1 + 560);
  }
  qdf_trace_msg(
    0,
    8u,
    "%s: [TDLS] vdev:%d action:%d (%s) sent_count:%u from peer=%02x:%02x:%02x:**:**:%02x link_status %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "tdls_recv_discovery_resp",
    *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
    14,
    "TDLS_DISCOVERY_RESPONSE",
    *(unsigned int *)(a1 + 768),
    *(unsigned __int8 *)(v26 + 24),
    *(unsigned __int8 *)(v26 + 25),
    *(unsigned __int8 *)(v26 + 26),
    *(unsigned __int8 *)(v26 + 29),
    *(_DWORD *)(v26 + 36),
    v69,
    v70,
    v71,
    v72,
    v73);
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)a1, v37, v38, v39, v40, v41, v42, v43, v44) & 1) != 0 )
  {
    v53 = *(_DWORD *)(v26 + 36);
    if ( v53 )
      goto LABEL_15;
    tdls_set_peer_link_status(v26, 1, 0);
  }
  v53 = *(_DWORD *)(v26 + 36);
LABEL_15:
  *(_DWORD *)(v26 + 32) = 1;
  if ( v53 != 1 )
    goto LABEL_30;
  if ( *(_DWORD *)(a1 + 752) >= *(char *)(v26 + 31) )
  {
    LODWORD(v68) = *(_DWORD *)(a1 + 752);
    LODWORD(v67) = *(char *)(v26 + 31);
    qdf_trace_msg(
      0,
      8u,
      "%s: Rssi Threshold not met: %02x:%02x:%02x:**:**:%02x rssi = %d threshold = %d ",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "tdls_recv_discovery_resp",
      *(unsigned __int8 *)(v26 + 24),
      *(unsigned __int8 *)(v26 + 25),
      *(unsigned __int8 *)(v26 + 26),
      *(unsigned __int8 *)(v26 + 29),
      v67,
      v68);
    tdls_set_peer_link_status(v26, 0, 0xFFFFFFFFLL);
    if ( *(_WORD *)(v26 + 42) )
    {
      result = 0;
      --*(_WORD *)(v26 + 42);
      goto LABEL_26;
    }
LABEL_30:
    result = 0;
    goto LABEL_26;
  }
  tdls_set_peer_link_status(v26, 2, 0);
  LODWORD(v68) = *(_DWORD *)(a1 + 752);
  LODWORD(v67) = *(char *)(v26 + 31);
  qdf_trace_msg(
    0,
    8u,
    "%s: Rssi Threshold met: %02x:%02x:%02x:**:**:%02x rssi = %d threshold= %d",
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    "tdls_recv_discovery_resp",
    *(unsigned __int8 *)(v26 + 24),
    *(unsigned __int8 *)(v26 + 25),
    *(unsigned __int8 *)(v26 + 26),
    *(unsigned __int8 *)(v26 + 29),
    v67,
    v68);
  qdf_mem_copy((char *)&v71 + 2, a2, 6u);
  v63 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v24 + 264);
  v62 = *(_QWORD *)(v24 + 272);
  v70 = *(_QWORD *)a1;
  if ( *((_DWORD *)v63 - 1) != 1890320457 )
    __break(0x8229u);
  v63(v62, 7, &v70);
  result = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
