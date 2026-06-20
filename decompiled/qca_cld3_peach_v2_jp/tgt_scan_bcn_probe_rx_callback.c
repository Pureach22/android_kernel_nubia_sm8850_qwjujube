__int64 __fastcall tgt_scan_bcn_probe_rx_callback(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        const void *a12,
        int a13)
{
  unsigned int v14; // w22
  void *v18; // x0
  __int64 v19; // x20
  void *v20; // x0
  int v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int ref; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  __int64 v40; // x22
  void *v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v52; // [xsp+8h] [xbp-38h] BYREF
  __int64 v53; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v54)(__int64, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v55)(__int64, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v56; // [xsp+28h] [xbp-18h]
  __int64 v57; // [xsp+30h] [xbp-10h]
  __int64 v58; // [xsp+38h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v57 = 0;
  v54 = nullptr;
  v55 = nullptr;
  v52 = 0;
  v53 = 0;
  v51 = 0;
  if ( (unsigned int)(a13 - 7) <= 0xFFFFFFFD )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: frame is not beacon or probe resp",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "tgt_scan_bcn_probe_rx_callback");
    v14 = 4;
    goto LABEL_20;
  }
  v18 = qdf_mem_malloc_atomic_fl(0x28u, (__int64)"tgt_scan_bcn_probe_rx_callback", 0x14Eu);
  if ( !v18 )
  {
    v14 = 2;
    goto LABEL_20;
  }
  v19 = (__int64)v18;
  v20 = qdf_mem_malloc_atomic_fl(0x60u, (__int64)"tgt_scan_bcn_probe_rx_callback", 0x154u);
  *(_QWORD *)(v19 + 8) = v20;
  if ( v20 )
  {
    if ( a13 == 5 )
      v21 = 80;
    else
      v21 = 128;
    *(_DWORD *)v19 = v21;
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, unsigned int *))scheduler_get_queue_size)(21, &v51)
      || v51 >= 0x97 )
    {
      v40 = jiffies;
      if ( tgt_scan_bcn_probe_rx_callback___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: Dropping beacon/probe frame, queue size %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "tgt_scan_bcn_probe_rx_callback",
          v51);
        tgt_scan_bcn_probe_rx_callback___last_ticks = v40;
      }
      v14 = 16;
      v39 = *(_QWORD *)(v19 + 8);
      if ( !v39 )
        goto LABEL_19;
    }
    else
    {
      ref = wlan_objmgr_psoc_try_get_ref(a1, 0xCu, v22, v23, v24, v25, v26, v27, v28, v29);
      if ( ref )
      {
        v14 = ref;
        qdf_trace_msg(
          0x15u,
          4u,
          "%s: unable to get reference",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "tgt_scan_bcn_probe_rx_callback");
        v39 = *(_QWORD *)(v19 + 8);
        if ( !v39 )
          goto LABEL_19;
      }
      else
      {
        v42 = *(void **)(v19 + 8);
        *(_QWORD *)(v19 + 16) = a1;
        *(_QWORD *)(v19 + 32) = a11;
        *(_BYTE *)(v19 + 24) = 0;
        qdf_mem_copy(v42, a12, 0x60u);
        v53 = v19;
        v54 = scm_handle_bcn_probe;
        v55 = scm_bcn_probe_flush_callback;
        v14 = scheduler_post_message_debug(
                0x15u,
                0x15u,
                21,
                (unsigned __int16 *)&v52,
                0x17Au,
                (__int64)"tgt_scan_bcn_probe_rx_callback");
        if ( !v14 )
          goto LABEL_22;
        wlan_objmgr_psoc_release_ref(a1, 0xCu, v43, v44, v45, v46, v47, v48, v49, v50);
        v39 = *(_QWORD *)(v19 + 8);
        if ( !v39 )
          goto LABEL_19;
      }
    }
    _qdf_mem_free(v39);
  }
  else
  {
    v14 = 2;
  }
LABEL_19:
  _qdf_mem_free(v19);
LABEL_20:
  if ( a11 )
    _qdf_nbuf_free(a11);
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v14;
}
