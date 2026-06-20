__int64 __fastcall dp_rx_tid_setup_wifi3(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w26
  unsigned int v13; // w24
  unsigned int v14; // w20
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x25
  __int64 v25; // x23
  __int64 v26; // x8
  __int64 v27; // x9
  unsigned int updated; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x21
  __int64 v38; // x28
  _DWORD *v39; // x8
  int v40; // w0
  int v41; // w20
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned __int64 v51; // x22
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x8
  void (*v55)(void); // x8
  __int64 v56; // x27
  const char **v57; // x24
  char v58; // w0
  char v59; // w26
  __int64 v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  const char *v69; // x0
  const char *v70; // x2
  __int64 v71; // x0
  unsigned __int64 v72; // x10
  unsigned __int64 v73; // x9
  __int64 v74; // x8
  __int64 v75; // x12
  __int64 v76; // x9
  __int64 v77; // x8
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x20
  __int64 v87; // x27
  __int64 v88; // x28
  __int64 v89; // x24
  __int64 v90; // x22
  __int64 v91; // x26
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  unsigned int v100; // w22
  _DWORD *v101; // x8
  __int64 v102; // x23
  __int64 v103; // x24
  unsigned __int64 v104; // x26
  __int64 v105; // x25
  __int64 v106; // x27
  __int64 v107; // x21
  __int64 v108; // x28
  __int64 v109; // x20
  __int64 v111; // [xsp+8h] [xbp-28h]
  unsigned __int8 v112; // [xsp+10h] [xbp-20h]
  unsigned int v113; // [xsp+14h] [xbp-1Ch]
  __int64 v114; // [xsp+18h] [xbp-18h]
  __int64 v115; // [xsp+20h] [xbp-10h]
  unsigned int v116; // [xsp+28h] [xbp-8h]
  unsigned int v117; // [xsp+2Ch] [xbp-4h]

  if ( !*(_DWORD *)(a1 + 232) )
    return 16;
  v12 = a4;
  v13 = a3;
  v14 = a2;
  v15 = a1;
  v111 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 24LL) + 8LL);
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: tid_bitmap 0x%x, ba_window_size %d, start_seq %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "dp_rx_tid_setup_wifi3",
    a2,
    a3,
    a4);
  v24 = 0;
  v112 = 0;
  v116 = v13;
  v113 = v12;
  v115 = v15;
  while ( 2 )
  {
    v25 = 1LL << v24;
    if ( ((1LL << v24) & v14) == 0 )
      goto LABEL_4;
    v26 = *(_QWORD *)(v15 + 88) + 144 * v24;
    v27 = *(_QWORD *)(v26 + 32);
    *(_WORD *)(v26 + 72) = v13;
    if ( v27 )
    {
      updated = dp_rx_tid_update_wifi3(v15, v24, v13, v12, 0);
      if ( !updated )
      {
        qdf_trace_msg(
          0x81u,
          5u,
          "%s: Update tid %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "dp_rx_tid_setup_wifi3",
          (unsigned int)v24);
        v14 &= ~(_DWORD)v25;
        goto LABEL_4;
      }
      v100 = updated;
      qdf_trace_msg(
        0x81u,
        2u,
        "%s: Update tid %d fail",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "dp_rx_tid_setup_wifi3",
        (unsigned int)v24);
      return v100;
    }
    v117 = v14;
    v37 = *(_QWORD *)(v15 + 88) + 144 * v24;
    v38 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v15 + 24) + 24LL) + 8LL);
    *(_BYTE *)(v37 + 108) = 0;
    *(_DWORD *)(v37 + 104) = 0;
    *(_QWORD *)(v37 + 112) = 0;
    *(_WORD *)(v37 + 78) = 0;
    *(_QWORD *)(v37 + 4) = 0;
    *(_QWORD *)(v37 + 12) = 0;
    *(_DWORD *)(v37 + 20) = 0;
    v39 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(v38 + 1128) + 74392LL) + 1152LL);
    if ( v39 )
    {
      if ( *(v39 - 1) != 1946320769 )
        __break(0x8228u);
      v40 = ((__int64 (__fastcall *)(_QWORD, _QWORD))v39)(v13, (unsigned int)v24);
    }
    else
    {
      v40 = 128;
    }
    v41 = 11;
    *(_DWORD *)(v37 + 64) = v40;
    while ( 1 )
    {
      v42 = _qdf_mem_malloc(*(unsigned int *)(v37 + 64), "dp_single_rx_tid_setup", 671);
      *(_QWORD *)(v37 + 32) = v42;
      if ( !v42 )
      {
LABEL_40:
        qdf_trace_msg(
          0x81u,
          2u,
          "%s: %pK: Rx tid HW desc alloc failed: tid %d",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "dp_single_rx_tid_setup",
          v38,
          (unsigned int)v24);
LABEL_46:
        qdf_trace_msg(
          0x81u,
          2u,
          "%s: Set up tid %d fail, status=%d",
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          "dp_rx_tid_setup_wifi3",
          (unsigned int)v24,
          2);
        v12 = v113;
        v14 = v117 & ~(_DWORD)v25;
        ++v112;
        goto LABEL_4;
      }
      v51 = v42;
      if ( (v42 & 0x7F) != 0 )
      {
        _qdf_mem_free(v42);
        v52 = _qdf_mem_malloc((unsigned int)(*(_DWORD *)(v37 + 64) + 127), "dp_single_rx_tid_setup", 687);
        *(_QWORD *)(v37 + 32) = v52;
        if ( !v52 )
          goto LABEL_40;
        v51 = (v52 + 127) & 0xFFFFFFFFFFFFFF80LL;
        qdf_trace_msg(
          0x81u,
          8u,
          "%s: %pK: Total Size %d Aligned Addr %pK",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "dp_single_rx_tid_setup",
          v38,
          *(unsigned int *)(v37 + 64),
          v51);
      }
      *(_QWORD *)(v37 + 40) = v51;
      v53 = *(_QWORD *)(v38 + 1128);
      if ( v53 && (v54 = *(_QWORD *)(v53 + 74392)) != 0 )
      {
        v55 = *(void (**)(void))(v54 + 72);
        if ( v55 )
        {
          if ( *((_DWORD *)v55 - 1) != 1354169286 )
            __break(0x8228u);
          v55();
        }
      }
      else
      {
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: hal handle is NULL",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "hal_reo_qdesc_setup");
      }
      v56 = *(int *)(v37 + 64);
      v57 = *(const char ***)(*(_QWORD *)(v38 + 24) + 40LL);
      v58 = is_vmalloc_addr(v51);
      v59 = v58;
      if ( (v58 & 1) != 0 && (dma_map_single_attrs___already_done_1 & 1) == 0 )
        break;
      if ( (v58 & 1) == 0 )
        goto LABEL_34;
LABEL_29:
      v60 = *(_QWORD *)(v37 + 32);
      *(_QWORD *)(v37 + 56) = -1;
      _qdf_mem_free(v60);
      v13 = v116;
      v15 = v115;
      --v41;
      *(_QWORD *)(v37 + 32) = 0;
      if ( !v41 )
      {
        qdf_trace_msg(
          0x81u,
          2u,
          "%s: %pK: Rx tid %d desc alloc fail (lowmem)",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "dp_single_rx_tid_setup",
          v38,
          (unsigned int)v24);
        v86 = 0;
        v87 = 0;
        v114 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v115 + 24) + 24LL) + 8LL);
        do
        {
          if ( (((unsigned __int64)(unsigned int)(1 << v24) >> v87) & 1) != 0 )
          {
            v88 = *(_QWORD *)(v115 + 88) + v86;
            if ( *(_QWORD *)(v88 + 32) )
            {
              v89 = *(int *)(v88 + 64);
              v90 = *(_QWORD *)(v88 + 56);
              v91 = *(_QWORD *)(v114 + 24);
              qdf_mem_skb_total_dec(v89);
              dma_unmap_page_attrs(*(_QWORD *)(v91 + 40), v90, v89, 0, 0);
              _qdf_mem_free(*(_QWORD *)(v88 + 32));
              *(_QWORD *)(v88 + 32) = 0;
              *(_QWORD *)(v88 + 56) = 0;
            }
          }
          ++v87;
          v86 += 144;
        }
        while ( v87 != 17 );
        v13 = v116;
        goto LABEL_46;
      }
    }
    dma_map_single_attrs___already_done_1 = 1;
    v69 = (const char *)dev_driver_string(v57);
    v70 = v57[14];
    if ( !v70 )
      v70 = *v57;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v69, v70);
    __break(0x800u);
    if ( (v59 & 1) != 0 )
      goto LABEL_29;
LABEL_34:
    v71 = dma_map_page_attrs(
            v57,
            ((unsigned __int64)(((__int64)(v51 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
            v51 & 0xFFF,
            v56,
            0,
            0);
    if ( v71 == -1 )
      goto LABEL_29;
    *(_QWORD *)(v37 + 56) = v71;
    qdf_mem_skb_total_inc(v56);
    v72 = jiffies;
    v73 = jiffies;
    v15 = v115;
    v74 = *(unsigned int *)(*(_QWORD *)(v38 + 40) + 132LL);
    if ( (_DWORD)v74 )
    {
      v75 = 56LL * *(unsigned int *)(v38 + 20168);
      *(_QWORD *)(*(_QWORD *)(v38 + 20160) + v75 + 8) = *(_QWORD *)(v37 + 56);
      *(_QWORD *)(*(_QWORD *)(v38 + 20160) + v75) = 1000 * (v72 / 0xFA) + 4 * (v73 % 0xFA);
      *(_QWORD *)(*(_QWORD *)(v38 + 20160) + v75 + 16) = v51;
      *(_QWORD *)(*(_QWORD *)(v38 + 20160) + v75 + 24) = *(_QWORD *)(v37 + 32);
      *(_DWORD *)(*(_QWORD *)(v38 + 20160) + v75 + 32) = *(unsigned __int16 *)(v115 + 16);
      *(_DWORD *)(*(_QWORD *)(v38 + 20160) + v75 + 36) = *(_DWORD *)v37;
      v76 = *(_QWORD *)(v38 + 20176);
      if ( v76 + 1 == v74 )
        v77 = 0;
      else
        v77 = v76 + 1;
      *(_QWORD *)(v38 + 20176) = v77;
    }
    v13 = v116;
    v14 = v117;
    v12 = v113;
LABEL_4:
    if ( ++v24 != 17 )
      continue;
    break;
  }
  if ( v14 )
  {
    if ( (dp_get_peer_vdev_roaming_in_progress(v15, v16, v17, v18, v19, v20, v21, v22, v23) & 1) != 0 )
    {
      v100 = 12;
      goto LABEL_56;
    }
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: peer %pK, tids 0x%x, multi_reo %d, s_seq %d, w_size %d",
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      "dp_rx_tid_setup_wifi3",
      v15,
      v14,
      *(unsigned __int8 *)(v111 + 20044),
      v12,
      v13);
    v101 = *(_DWORD **)(v111 + 1568);
    if ( *(v101 - 1) != -1687924027 )
      __break(0x8228u);
    v100 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD))v101)(v111, v15, v14, v13, 0);
    if ( v100 )
    {
LABEL_56:
      v102 = 0;
      v103 = 0;
      v104 = v14;
      v105 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v15 + 24) + 24LL) + 8LL);
      do
      {
        if ( ((v104 >> v103) & 1) != 0 )
        {
          v106 = *(_QWORD *)(v15 + 88) + v102;
          if ( *(_QWORD *)(v106 + 32) )
          {
            v107 = *(int *)(v106 + 64);
            v108 = *(_QWORD *)(v105 + 24);
            v109 = *(_QWORD *)(v106 + 56);
            qdf_mem_skb_total_dec(v107);
            dma_unmap_page_attrs(*(_QWORD *)(v108 + 40), v109, v107, 0, 0);
            _qdf_mem_free(*(_QWORD *)(v106 + 32));
            *(_QWORD *)(v106 + 32) = 0;
            *(_QWORD *)(v106 + 56) = 0;
          }
        }
        ++v103;
        v102 += 144;
      }
      while ( v103 != 17 );
    }
  }
  else
  {
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: tid_bitmap=0, no tid setup, setup_fail_cnt %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "dp_rx_tid_setup_wifi3",
      v112);
    return 16 * (unsigned int)(v112 != 0);
  }
  return v100;
}
