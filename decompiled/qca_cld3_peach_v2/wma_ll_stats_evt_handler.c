__int64 __fastcall wma_ll_stats_evt_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  _QWORD *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _DWORD *v20; // x20
  unsigned int v21; // w4
  unsigned int v22; // w5
  unsigned int v23; // w8
  const char *v24; // x2
  unsigned int v25; // w1
  __int64 result; // x0
  unsigned int v27; // w9
  __int64 v28; // x23
  _DWORD *v29; // x22
  __int64 v30; // x26
  __int64 ll_stats_ext_buf; // x0
  __int64 v32; // x21
  __int64 v33; // x28
  char v34; // w8
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 v37; // x12
  __int64 v38; // x11
  _QWORD *v39; // x13
  __int64 v40; // x10
  __int64 v41; // x9
  __int64 v42; // x10
  int v43; // w10
  __int64 *v44; // x24
  unsigned int *v45; // x26
  unsigned __int64 v46; // x28
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int *v55; // x8
  __int64 v56; // x25
  __int64 v57; // x26
  int v58; // w8
  unsigned int v59; // w27
  _DWORD *v60; // x9
  __int64 v61; // [xsp+0h] [xbp-50h]
  __int64 v62; // [xsp+8h] [xbp-48h] BYREF
  __int64 v63; // [xsp+10h] [xbp-40h]
  __int64 v64; // [xsp+18h] [xbp-38h]
  __int64 v65; // [xsp+20h] [xbp-30h]
  __int64 v66; // [xsp+28h] [xbp-28h]
  __int64 v67; // [xsp+30h] [xbp-20h]
  unsigned int v68; // [xsp+3Ch] [xbp-14h] BYREF
  _QWORD v69[2]; // [xsp+40h] [xbp-10h] BYREF

  v69[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  context = _cds_get_context(53, (__int64)"wma_ll_stats_evt_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
  {
    v24 = "%s: NULL mac ptr. Exiting";
LABEL_13:
    v25 = 8;
LABEL_14:
    qdf_trace_msg(0x36u, v25, v24, v12, v13, v14, v15, v16, v17, v18, v19, "wma_ll_stats_evt_handler");
    goto LABEL_15;
  }
  if ( !context[1629] )
  {
    v24 = "%s: HDD callback is null";
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Posting MAC counters event to HDD",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wma_ll_stats_evt_handler");
  if ( !a10 )
  {
    v24 = "%s: param_buf is null";
    goto LABEL_13;
  }
  v20 = *(_DWORD **)a10;
  if ( !*(_QWORD *)a10 )
  {
    v24 = "%s: fixed_param is null";
    goto LABEL_13;
  }
  v21 = v20[7];
  v22 = v20[8];
  if ( v21 > *(_DWORD *)(a10 + 40) || v22 > *(_DWORD *)(a10 + 56) || (v23 = v20[14], v23 > *(_DWORD *)(a10 + 152)) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: excess num_peer_signal_stats:%d, num_peer_ac_tx_stats:%d, num_peer_ac_rx_stats:%d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_ll_stats_evt_handler");
LABEL_15:
    result = 4294967274LL;
    goto LABEL_16;
  }
  if ( v21 <= v22 )
    v27 = v20[8];
  else
    v27 = v20[7];
  if ( v27 <= v23 )
    v28 = v23;
  else
    v28 = v27;
  if ( !(_DWORD)v28 )
    goto LABEL_15;
  v29 = *(_DWORD **)(a10 + 16);
  v30 = *(_QWORD *)(a10 + 32);
  ll_stats_ext_buf = wma_get_ll_stats_ext_buf(&v68, (unsigned int)v28, *(_QWORD *)a10);
  if ( !ll_stats_ext_buf )
  {
    v24 = "%s: Fail to allocate stats buffer";
    v25 = 2;
    goto LABEL_14;
  }
  *(_DWORD *)(ll_stats_ext_buf + 12) = 0;
  *(_DWORD *)ll_stats_ext_buf = 1024;
  v32 = ll_stats_ext_buf;
  *(_DWORD *)(ll_stats_ext_buf + 20) = v28;
  *(_DWORD *)(ll_stats_ext_buf + 24) = 1;
  *(_DWORD *)(ll_stats_ext_buf + 28) = v20[1];
  v33 = ll_stats_ext_buf + 28;
  *(_DWORD *)(ll_stats_ext_buf + 32) = v20[2];
  *(_DWORD *)(ll_stats_ext_buf + 36) = v20[3];
  *(_DWORD *)(ll_stats_ext_buf + 40) = v20[4];
  *(_DWORD *)(ll_stats_ext_buf + 44) = v20[5];
  v34 = v20[6];
  *(_BYTE *)(ll_stats_ext_buf + 48) = v28;
  *(_BYTE *)(ll_stats_ext_buf + 49) = v34;
  v35 = ll_stats_ext_buf + 92;
  v69[0] = ll_stats_ext_buf + 92;
  *(_QWORD *)(ll_stats_ext_buf + 76) = ll_stats_ext_buf + 92;
  if ( (_DWORD)v28 == 1 )
  {
    v36 = 0;
LABEL_31:
    v40 = ll_stats_ext_buf + 272LL * (unsigned int)v36;
    v41 = v28 - v36;
    v42 = v40 + 96;
    do
    {
      --v41;
      *(_QWORD *)(v42 - 4) = -1;
      v42 += 272;
    }
    while ( v41 );
    goto LABEL_33;
  }
  v36 = (unsigned int)v28 & 0xFFFFFFFE;
  v37 = ll_stats_ext_buf;
  v38 = v36;
  do
  {
    v39 = (_QWORD *)(v37 + 364);
    *(_QWORD *)(v37 + 92) = -1;
    v38 -= 2;
    v37 += 544;
    *v39 = -1;
  }
  while ( v38 );
  if ( v36 != v28 )
    goto LABEL_31;
LABEL_33:
  v43 = v20[7];
  v68 -= 64;
  if ( v43 && v30 )
  {
    v61 = ll_stats_ext_buf + 28;
    v44 = (__int64 *)(ll_stats_ext_buf + 132);
    v45 = (unsigned int *)(v30 + 76);
    v46 = 1;
    do
    {
      *((_DWORD *)v44 - 10) = *(v45 - 17);
      *((_DWORD *)v44 - 9) = *(v45 - 18);
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: %d antennas for peer %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wma_ll_stats_evt_handler",
        v45[16],
        *(v45 - 17),
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67);
      if ( v68 < 0x8C || v44 == &qword_8 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid length of PEER signal",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "wma_ll_stats_evt_handler");
      }
      else
      {
        *((_DWORD *)v44 - 2) = *(v45 - 18);
        *((_DWORD *)v44 - 1) = *(v45 - 17);
        *((_DWORD *)v44 + 32) = v45[16];
        qdf_mem_copy(v44, v45 - 16, 0x20u);
        qdf_mem_copy(v44 + 4, v45 - 8, 0x20u);
        qdf_mem_copy(v44 + 8, v45, 0x20u);
        qdf_mem_copy(v44 + 12, v45 + 8, 0x20u);
        v68 -= 140;
      }
      if ( v46 >= (unsigned int)v20[7] )
        break;
      v55 = v45 + 17;
      v44 += 34;
      v45 += 36;
      ++v46;
    }
    while ( v55 );
    v35 = v69[0];
    v33 = v61;
  }
  v56 = 0;
  v57 = v35 + 272LL * (unsigned int)v28;
  v58 = *(unsigned __int8 *)(v32 + 49);
  *(_QWORD *)(v32 + 84) = v57;
  if ( v58 && v57 && v29 )
  {
    v56 = 0;
    v59 = 1;
    do
    {
      if ( v68 < 0x24 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid length of CCA",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wma_ll_stats_evt_handler");
      }
      else
      {
        v60 = (_DWORD *)(v57 + v56);
        *v60 = v29[1];
        v60[1] = v29[2];
        v60[2] = v29[3];
        v60[3] = v29[4];
        v60[4] = v29[5];
        v60[5] = v29[6];
        v60[6] = v29[7];
        v60[7] = v29[8];
        v60[8] = v29[9];
        v68 -= 36;
      }
      v56 += 36;
      if ( v59 >= *(unsigned __int8 *)(v32 + 49) )
        break;
      ++v59;
    }
    while ( v56 + v57 );
  }
  v69[0] = v57 + v56;
  if ( (unsigned int)wma_fill_tx_stats(v33, v20, a10, v69, &v68)
    || (unsigned int)wma_fill_rx_stats(v33, (int)v20, a10, (int)v69, (size_t)&v68)
    || (v63 = v32,
        LOWORD(v62) = 5257,
        HIDWORD(v62) = 0,
        result = scheduler_post_message_debug(
                   0x36u,
                   0x34u,
                   52,
                   (unsigned __int16 *)&v62,
                   0x722u,
                   (__int64)"wma_ll_stats_evt_handler"),
        (_DWORD)result) )
  {
    _qdf_mem_free(v32);
    goto LABEL_15;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
