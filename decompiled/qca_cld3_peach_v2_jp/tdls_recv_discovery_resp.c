__int64 __fastcall tdls_recv_discovery_resp(
        __int64 *a1,
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
  __int64 v11; // x8
  __int64 v12; // x8
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
  int v26; // w9
  __int64 v27; // x20
  __int64 *v28; // x8
  __int64 v29; // x7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w8
  __int64 result; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x0
  void (__fastcall *v49)(__int64, __int64, __int64 *); // x9
  const char *v50; // x2
  const char *v51; // x2
  __int64 v52; // [xsp+0h] [xbp-50h]
  __int64 v53; // [xsp+8h] [xbp-48h]
  __int64 v54; // [xsp+28h] [xbp-28h]
  __int64 v55; // [xsp+30h] [xbp-20h] BYREF
  __int64 v56; // [xsp+38h] [xbp-18h] BYREF
  __int64 v57; // [xsp+40h] [xbp-10h]
  __int64 v58; // [xsp+48h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_20;
  v10 = *a1;
  v56 = 0;
  v57 = 0;
  v55 = 0;
  if ( !v10 )
  {
    v50 = "%s: NULL vdev";
    goto LABEL_17;
  }
  v11 = *(_QWORD *)(v10 + 152);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v50 = "%s: can't get psoc";
LABEL_17:
    qdf_trace_msg(0, 2u, v50, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_18;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v12, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_18:
    v51 = "%s: tdls soc is NULL";
LABEL_19:
    qdf_trace_msg(0, 2u, v51, v16, v17, v18, v19, v20, v21, v22, v23, "tdls_recv_discovery_resp");
LABEL_20:
    result = 4294967274LL;
    goto LABEL_21;
  }
  v24 = comp_private_obj;
  peer = tdls_get_peer(a1, a2);
  if ( !peer )
  {
    v51 = "%s: curr_peer is NULL";
    goto LABEL_19;
  }
  v26 = *((_DWORD *)a1 + 192);
  v27 = peer;
  if ( !v26 || (v28 = a1, v29 = (unsigned int)(v26 - 1), *((_DWORD *)a1 + 192) = v29, v26 == 1) )
  {
    qdf_mc_timer_stop((__int64)(a1 + 70));
    v29 = *((unsigned int *)a1 + 192);
    v28 = a1;
  }
  qdf_trace_msg(
    0,
    8u,
    "%s: [TDLS] vdev:%d action:%d (%s) sent_count:%u from peer=%02x:%02x:%02x:**:**:%02x link_status %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "tdls_recv_discovery_resp",
    *(unsigned __int8 *)(*v28 + 104),
    14,
    "TDLS_DISCOVERY_RESPONSE",
    v29,
    *(unsigned __int8 *)(v27 + 24),
    *(unsigned __int8 *)(v27 + 25),
    *(unsigned __int8 *)(v27 + 26),
    *(unsigned __int8 *)(v27 + 29),
    *(_DWORD *)(v27 + 36),
    v54,
    v55,
    v56,
    v57,
    v58);
  v38 = *(_DWORD *)(v27 + 36);
  result = 0;
  *(_DWORD *)(v27 + 32) = 1;
  if ( v38 == 1 )
  {
    if ( *((_DWORD *)a1 + 188) >= *(char *)(v27 + 31) )
    {
      LODWORD(v53) = *((_DWORD *)a1 + 188);
      LODWORD(v52) = *(char *)(v27 + 31);
      qdf_trace_msg(
        0,
        8u,
        "%s: Rssi Threshold not met: %02x:%02x:%02x:**:**:%02x rssi = %d threshold = %d ",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "tdls_recv_discovery_resp",
        *(unsigned __int8 *)(v27 + 24),
        *(unsigned __int8 *)(v27 + 25),
        *(unsigned __int8 *)(v27 + 26),
        *(unsigned __int8 *)(v27 + 29),
        v52,
        v53);
      tdls_set_peer_link_status(v27, 0, 0xFFFFFFFFLL);
      result = 0;
      if ( *(_WORD *)(v27 + 42) )
        --*(_WORD *)(v27 + 42);
    }
    else
    {
      tdls_set_peer_link_status(v27, 2, 0);
      LODWORD(v53) = *((_DWORD *)a1 + 188);
      LODWORD(v52) = *(char *)(v27 + 31);
      qdf_trace_msg(
        0,
        8u,
        "%s: Rssi Threshold met: %02x:%02x:%02x:**:**:%02x rssi = %d threshold= %d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "tdls_recv_discovery_resp",
        *(unsigned __int8 *)(v27 + 24),
        *(unsigned __int8 *)(v27 + 25),
        *(unsigned __int8 *)(v27 + 26),
        *(unsigned __int8 *)(v27 + 29),
        v52,
        v53);
      qdf_mem_copy((char *)&v56 + 2, a2, 6u);
      v49 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v24 + 264);
      v48 = *(_QWORD *)(v24 + 272);
      v55 = *a1;
      if ( *((_DWORD *)v49 - 1) != 1890320457 )
        __break(0x8229u);
      v49(v48, 7, &v55);
      result = 0;
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
