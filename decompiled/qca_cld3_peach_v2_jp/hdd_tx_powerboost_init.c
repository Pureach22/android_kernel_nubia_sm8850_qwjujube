__int64 __fastcall hdd_tx_powerboost_init(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v11; // x0
  void *v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  const char *v57; // x2
  unsigned int v58; // w1
  __int64 v60; // x0
  __int64 v61; // [xsp+8h] [xbp-18h] BYREF
  int v62; // [xsp+10h] [xbp-10h]
  __int64 v63; // [xsp+18h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 8464) & 1) != 0 )
  {
    v9 = *(_QWORD *)a1;
    v61 = 0;
    if ( !v9 || (v11 = *(_QWORD *)(v9 + 2120)) == 0 )
    {
      qdf_trace_msg(0x33u, 2u, "%s: TPB: Invalid qdf dev", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_tx_powerboost_init_dma");
      v40 = 16;
      goto LABEL_10;
    }
    *(_DWORD *)(a1 + 8576) = 102400;
    v12 = (void *)qdf_aligned_mem_alloc_consistent_fl(
                    v11,
                    (unsigned int *)(a1 + 8576),
                    (__int64 *)(a1 + 8552),
                    (__int64 *)(a1 + 8568),
                    (__int64 *)(a1 + 8560),
                    8u,
                    (__int64)"hdd_tx_powerboost_init_dma",
                    0x77u);
    v21 = *(unsigned int *)(a1 + 8576);
    *(_QWORD *)(a1 + 8544) = v12;
    if ( !v12 )
    {
      v40 = 2;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: TPB: DMA buffer allocation failed, size: %u",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "hdd_tx_powerboost_init_dma",
        v21);
      goto LABEL_10;
    }
    qdf_mem_set(v12, (unsigned int)v21, 0);
    v22 = *(_QWORD *)(a1 + 8560);
    v62 = *(_DWORD *)(a1 + 8576);
    _qdf_dmaaddr_to_32s(v22, &v61, (_DWORD *)&v61 + 1);
    v31 = ucfg_reg_txpb_send_dma_addr(*(_QWORD *)(a1 + 8), (__int64)&v61, v23, v24, v25, v26, v27, v28, v29, v30);
    if ( v31 )
    {
      v40 = v31;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: TPB: ucfg_reg_txpb_send_dma_addr failed: %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "hdd_tx_powerboost_init_dma",
        v31);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: TPB: DMA address sent to firmware",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "hdd_tx_powerboost_init_dma");
LABEL_10:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: TPB: init dma failed: %d",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "hdd_tx_powerboost_init",
        v40);
      goto LABEL_11;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TPB: DMA address sent to firmware",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "hdd_tx_powerboost_init_dma");
    _qdf_wake_lock_create((_QWORD *)(a1 + 8584), (__int64)"txpb_wake_lock");
    _qdf_runtime_lock_init((__int64 *)(a1 + 8784), "&hdd_ctx->tx_pb.txpb_runtime_lock");
    qdf_mutex_create(a1 + 8816);
    *(_QWORD *)(a1 + 8792) = a1 + 8792;
    *(_QWORD *)(a1 + 8800) = a1 + 8792;
    v60 = *(_QWORD *)a1;
    *(_QWORD *)(a1 + 8808) = 0x500000000LL;
    ucfg_reg_txpb_register_callback(v60, (__int64)wlan_hdd_cfg80211_tx_pb_callback, a1);
    v57 = "%s: TPB: init done";
    v58 = 8;
  }
  else
  {
    v57 = "%s: TPB: feature not enabled";
    v58 = 3;
  }
  qdf_trace_msg(0x33u, v58, v57, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_tx_powerboost_init");
  v40 = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v40;
}
