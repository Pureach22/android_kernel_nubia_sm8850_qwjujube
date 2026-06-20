__int64 __fastcall tgt_tdls_mgmt_frame_rx_cb(
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
  unsigned int ref; // w24
  __int64 comp_private_obj; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  int v37; // w25
  __int64 v38; // x24
  const char *v39; // x2
  __int64 vdev; // x0
  unsigned int *v41; // x8
  __int64 *v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 *v51; // x23
  _DWORD *v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  const void *v61; // x1
  int v62; // w8
  size_t v63; // x2
  __int64 v64; // x21
  __int64 v66; // x22
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // [xsp+8h] [xbp-38h] BYREF
  __int64 *v76; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v77)(__int64, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v78)(); // [xsp+20h] [xbp-20h]
  __int64 v79; // [xsp+28h] [xbp-18h]
  __int64 v80; // [xsp+30h] [xbp-10h]
  __int64 v81; // [xsp+38h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0,
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
    "tgt_tdls_mgmt_frame_rx_cb",
    a1,
    a2,
    a5);
  if ( a3 )
  {
    if ( a1 && a4 )
    {
      ref = wlan_objmgr_peer_try_get_ref(a2, 0x10u, v18, v19, v20, v21, v22, v23, v24, v25);
      if ( !ref )
      {
        v79 = 0;
        v80 = 0;
        v77 = nullptr;
        v78 = nullptr;
        v75 = 0;
        v76 = nullptr;
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xAu);
        if ( comp_private_obj )
        {
          if ( a2 )
          {
            v36 = *(_QWORD *)(a2 + 96);
            if ( v36 )
            {
              v37 = *(unsigned __int8 *)(v36 + 168);
              v38 = comp_private_obj;
              goto LABEL_14;
            }
            v39 = "%s: vdev is NULL in peer, drop this frame";
          }
          else
          {
            v38 = comp_private_obj;
            vdev = tdls_get_vdev(a1, 0x10u);
            if ( vdev )
            {
              v37 = *(unsigned __int8 *)(vdev + 168);
              wlan_objmgr_vdev_release_ref(vdev, 0x10u, v41, v28, v29, v30, v31, v32, v33, v34, v35);
LABEL_14:
              v42 = (__int64 *)qdf_mem_malloc_atomic_fl(0x10u, (__int64)"tgt_tdls_mgmt_frame_process_rx_cb", 0x105u);
              if ( v42 )
              {
                v51 = v42;
                v52 = qdf_mem_malloc_atomic_fl(
                        (unsigned int)a4[6] + 24LL,
                        (__int64)"tgt_tdls_mgmt_frame_process_rx_cb",
                        0x10Au);
                if ( v52 )
                {
                  v61 = *(const void **)(a3 + 224);
                  *v52 = a4[6];
                  v62 = *a4;
                  v52[2] = v37;
                  v52[3] = a5;
                  v52[1] = v62;
                  v52[4] = a4[9];
                  *v51 = v38;
                  v51[1] = (__int64)v52;
                  v63 = (unsigned int)a4[6];
                  v64 = (__int64)v52;
                  qdf_mem_copy(v52 + 5, v61, v63);
                  LOWORD(v75) = 2;
                  v76 = v51;
                  v77 = tdls_process_rx_frame;
                  v78 = tgt_tdls_mgmt_frame_rx_flush_cb;
                  ref = scheduler_post_message_debug(
                          0,
                          0,
                          73,
                          (unsigned __int16 *)&v75,
                          0x121u,
                          (__int64)"tgt_tdls_mgmt_frame_process_rx_cb");
                  if ( !ref )
                  {
                    _qdf_nbuf_free(a3);
                    wlan_objmgr_peer_release_ref(a2, 0x10u, v67, v68, v69, v70, v71, v72, v73, v74);
                    goto LABEL_22;
                  }
                  _qdf_mem_free(v64);
                  _qdf_mem_free((__int64)v51);
                  _qdf_nbuf_free(a3);
                }
                else
                {
                  v66 = jiffies;
                  if ( tgt_tdls_mgmt_frame_process_rx_cb___last_ticks - jiffies + 125 < 0 )
                  {
                    qdf_trace_msg(
                      0,
                      8u,
                      "%s: Failed to allocate rx mgmt frame",
                      v53,
                      v54,
                      v55,
                      v56,
                      v57,
                      v58,
                      v59,
                      v60,
                      "tgt_tdls_mgmt_frame_process_rx_cb");
                    tgt_tdls_mgmt_frame_process_rx_cb___last_ticks = v66;
                  }
                  _qdf_mem_free((__int64)v51);
                  ref = 2;
                }
              }
              else
              {
                ref = 2;
              }
              goto LABEL_20;
            }
            v39 = "%s: current tdls vdev is null, can't get vdev id";
          }
        }
        else
        {
          v39 = "%s: tdls ctx is NULL, drop this frame";
        }
        qdf_trace_msg(0, 2u, v39, v28, v29, v30, v31, v32, v33, v34, v35, "tgt_tdls_mgmt_frame_process_rx_cb");
        ref = 16;
LABEL_20:
        wlan_objmgr_peer_release_ref(a2, 0x10u, v43, v44, v45, v46, v47, v48, v49, v50);
      }
    }
    else
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: input is NULL mgmt_rx_params:%pK psoc:%pK, peer:%pK",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "tgt_tdls_mgmt_frame_rx_cb",
        a4,
        a1,
        a2);
      ref = 4;
    }
    _qdf_nbuf_free(a3);
    goto LABEL_22;
  }
  qdf_trace_msg(
    0,
    2u,
    "%s: rx frame buff is null buf:%pK",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "tgt_tdls_mgmt_frame_rx_cb",
    0);
  ref = 4;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return ref;
}
