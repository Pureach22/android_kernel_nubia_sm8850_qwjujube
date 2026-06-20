__int64 __fastcall tgt_p2p_mgmt_frame_rx_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int *a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 comp_private_obj; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  int sta_vdev_id; // w24
  __int64 v37; // x23
  unsigned int v38; // w20
  const char *v40; // x2
  __int64 *v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 *v50; // x22
  _DWORD *v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  const void *v60; // x1
  int v61; // w8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x21
  unsigned int v71; // w1
  __int64 v72; // x21
  unsigned __int8 *v73; // x0
  unsigned int v74; // w1
  __int64 v75; // [xsp+8h] [xbp-48h] BYREF
  __int64 *v76; // [xsp+10h] [xbp-40h]
  __int64 (__fastcall *v77)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-38h]
  __int64 (__fastcall *v78)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-30h]
  __int64 v79; // [xsp+28h] [xbp-28h]
  __int64 v80; // [xsp+30h] [xbp-20h]
  __int64 v81; // [xsp+38h] [xbp-18h] BYREF
  __int64 v82; // [xsp+40h] [xbp-10h]
  __int64 v83; // [xsp+48h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v79 = 0;
  v80 = 0;
  v77 = nullptr;
  v78 = nullptr;
  v75 = 0;
  v76 = nullptr;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: psoc:%pK, peer:%pK, type:%d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "tgt_p2p_mgmt_frame_rx_cb",
    a1,
    a2,
    a5);
  if ( !a4 )
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: mgmt rx params is NULL",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "tgt_p2p_mgmt_frame_rx_cb");
    v38 = 4;
    if ( !a3 )
      goto LABEL_8;
LABEL_7:
    _qdf_nbuf_free(a3);
    goto LABEL_8;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( !comp_private_obj )
  {
    v40 = "%s: p2p ctx is NULL, drop this frame";
LABEL_20:
    v71 = 2;
    goto LABEL_21;
  }
  if ( a2 )
  {
    v35 = *(_QWORD *)(a2 + 96);
    if ( v35 )
    {
      sta_vdev_id = *(unsigned __int8 *)(v35 + 168);
      v37 = comp_private_obj;
      goto LABEL_11;
    }
    v40 = "%s: vdev is NULL in peer, drop this frame";
    goto LABEL_20;
  }
  sta_vdev_id = *(_DWORD *)(comp_private_obj + 216);
  v37 = comp_private_obj;
  if ( sta_vdev_id == -1 )
  {
    if ( (p2p_is_sta_vdev_usage_allowed_for_p2p_dev(a1) & 1) == 0
      || !(unsigned int)policy_mgr_mode_specific_connection_count(a1, 3, nullptr)
      || (v73 = *(unsigned __int8 **)(a3 + 224),
          v74 = a4[6],
          v81 = 0,
          v82 = 0,
          p2p_get_frame_info(v73, v74, (__int64)&v81, v27, v28, v29, v30, v31, v32, v33, v34),
          (_DWORD)v82 == 17) )
    {
      v40 = "%s: vdev id of current roc invalid";
      v71 = 8;
LABEL_21:
      qdf_trace_msg(0x4Eu, v71, v40, v27, v28, v29, v30, v31, v32, v33, v34, "tgt_p2p_mgmt_frame_rx_cb");
      v38 = 16;
      if ( !a3 )
        goto LABEL_8;
      goto LABEL_7;
    }
    sta_vdev_id = (unsigned __int8)p2p_psoc_priv_get_sta_vdev_id(a1);
  }
LABEL_11:
  v41 = (__int64 *)qdf_mem_malloc_atomic_fl(0x10u, (__int64)"tgt_p2p_mgmt_frame_rx_cb", 0x18Eu);
  if ( !v41 )
  {
    v70 = jiffies;
    if ( tgt_p2p_mgmt_frame_rx_cb___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: Failed to allocate rx mgmt event",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "tgt_p2p_mgmt_frame_rx_cb");
      tgt_p2p_mgmt_frame_rx_cb___last_ticks = v70;
    }
LABEL_25:
    v38 = 2;
    if ( !a3 )
      goto LABEL_8;
    goto LABEL_7;
  }
  v50 = v41;
  v51 = qdf_mem_malloc_atomic_fl((unsigned int)a4[6] + 24LL, (__int64)"tgt_p2p_mgmt_frame_rx_cb", 0x196u);
  if ( !v51 )
  {
    v72 = jiffies;
    if ( tgt_p2p_mgmt_frame_rx_cb___last_ticks_24 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: Failed to allocate rx mgmt frame",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "tgt_p2p_mgmt_frame_rx_cb");
      tgt_p2p_mgmt_frame_rx_cb___last_ticks_24 = v72;
    }
    goto LABEL_25;
  }
  v60 = *(const void **)(a3 + 224);
  *v51 = a4[6];
  v61 = *a4;
  v51[2] = sta_vdev_id;
  v51[3] = a5;
  v51[1] = v61;
  v51[4] = a4[2] - 96;
  *v50 = v37;
  v50[1] = (__int64)v51;
  qdf_mem_copy(v51 + 5, v60, (unsigned int)a4[6]);
  LOWORD(v75) = 2;
  v76 = v50;
  v77 = p2p_process_evt;
  v78 = p2p_event_flush_callback;
  v38 = scheduler_post_message_debug(
          0x4Eu,
          0x4Eu,
          73,
          (unsigned __int16 *)&v75,
          0x1AEu,
          (__int64)"tgt_p2p_mgmt_frame_rx_cb");
  if ( v38 )
  {
    _qdf_mem_free(v50[1]);
    _qdf_mem_free((__int64)v50);
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: post msg fail:%d",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "tgt_p2p_mgmt_frame_rx_cb",
      v38);
  }
  if ( a3 )
    goto LABEL_7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v38;
}
