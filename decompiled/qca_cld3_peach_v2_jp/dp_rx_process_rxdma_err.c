__int64 __fastcall dp_rx_process_rxdma_err(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 *a4,
        char a5,
        unsigned __int8 a6,
        unsigned __int8 a7)
{
  unsigned int (__fastcall *v14)(_QWORD); // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x27
  void (*v24)(void); // x8
  __int64 (__fastcall *v25)(_QWORD); // x8
  int v26; // w26
  unsigned __int16 (__fastcall *v27)(_QWORD); // x8
  unsigned int v28; // w27
  __int64 result; // x0
  unsigned int v30; // w9
  unsigned int v31; // w8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w9
  int v41; // w9
  int v42; // w10
  char v43; // w8
  __int64 v44; // x23
  __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // x22
  int v48; // w8
  int v49; // w8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned __int8 (__fastcall *v58)(_QWORD); // x8
  int v59; // w10
  __int64 v60; // x22
  unsigned int v61; // w8
  __int64 *v62; // x9
  __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x9
  unsigned __int8 *v66; // x8
  _BOOL4 v67; // w10
  __int64 *v68; // x9
  int v69; // w11
  int v70; // w10

  v14 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1264LL);
  if ( *((_DWORD *)v14 - 1) != 855462014 )
    __break(0x8228u);
  if ( !v14(a3) )
  {
    v23 = jiffies;
    if ( dp_rx_process_rxdma_err___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: MSDU DONE failure",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "dp_rx_process_rxdma_err");
      dp_rx_process_rxdma_err___last_ticks = v23;
    }
    v24 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1240LL);
    if ( *((_DWORD *)v24 - 1) != 343547449 )
      __break(0x8228u);
    v24();
  }
  v25 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 536LL);
  if ( *((_DWORD *)v25 - 1) != 855462014 )
    __break(0x8228u);
  v26 = v25(a3);
  v27 = *(unsigned __int16 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1272LL);
  if ( *((_DWORD *)v27 - 1) != 855462014 )
    __break(0x8228u);
  v28 = v26 + v27(a3) + *(unsigned __int16 *)(a1 + 1138);
  result = wlan_cfg_rx_buffer_size(*(_QWORD *)(a1 + 40));
  if ( v28 > (unsigned __int16)result )
  {
    if ( a1 )
    {
      v65 = *(_QWORD *)(a1 + 13760) + v28;
      ++*(_QWORD *)(a1 + 13752);
      *(_QWORD *)(a1 + 13760) = v65;
    }
LABEL_70:
    if ( a2 )
      return _qdf_nbuf_free(a2);
    return result;
  }
  v30 = *(_DWORD *)(a2 + 112);
  v31 = v28 - v30;
  if ( v28 < v30 )
  {
    result = skb_trim(a2, v28);
    goto LABEL_24;
  }
  if ( *(_DWORD *)(a2 + 116) )
  {
    v31 = v28 - v30;
    if ( v28 != v30 )
    {
      v40 = 0;
      goto LABEL_21;
    }
  }
  else
  {
    v42 = *(_DWORD *)(a2 + 208);
    v41 = *(_DWORD *)(a2 + 212);
    if ( v41 - v42 < v31 )
    {
      v40 = v42 - v41;
LABEL_21:
      if ( (unsigned int)pskb_expand_head(a2, 0, v40 + v31, 2080) )
        dev_kfree_skb_any_reason(a2, 1);
    }
  }
  result = skb_put(a2, v28 - *(_DWORD *)(a2 + 112));
LABEL_24:
  v43 = *(_BYTE *)(a2 + 84);
  *(_QWORD *)a2 = 0;
  *(_BYTE *)(a2 + 84) = v43 | 5;
  if ( a4 )
  {
    v44 = *a4;
    if ( *a4 )
    {
      result = dp_rx_skip_tlvs(a1, a2, v26);
      if ( a5 == 8 )
      {
        v45 = *(_QWORD *)(a2 + 224);
        if ( *(_WORD *)(v45 + 12) == 129 )
        {
          if ( *(_WORD *)(v45 + 20) != 16962 )
            goto LABEL_47;
          v46 = *(_QWORD *)(v44 + 24);
          if ( v46 )
            ++*(_DWORD *)(v46 + 480);
          if ( !*(_DWORD *)(v44 + 64) )
          {
LABEL_47:
            v58 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 496LL);
            if ( *((_DWORD *)v58 - 1) != -1147376687 )
              __break(0x8228u);
            if ( v58(a3) && *(_DWORD *)(v44 + 44) == 2 )
            {
              v66 = *(unsigned __int8 **)(a2 + 224);
              v67 = *v66 == 255 && v66[1] == 255 && v66[2] == 255 && v66[3] == 255 && v66[4] == 255 && v66[5] == 255;
              v68 = a4 + 278;
              ++a4[407 * a7 + 376];
              if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
                v69 = *(unsigned __int16 *)(a2 + 66);
              else
                v69 = 0;
              v68[407 * a7 + 99] += (unsigned int)(*(_DWORD *)(a2 + 112) + v69);
              if ( !v67 )
                goto LABEL_65;
              ++v68[407 * a7 + 100];
              if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
                v70 = *(unsigned __int16 *)(a2 + 66);
              else
                v70 = 0;
              v61 = *(_DWORD *)(a2 + 112) + v70;
              v62 = &v68[407 * a7 + 101];
            }
            else
            {
              ++a4[407 * a7 + 374];
              if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
                v59 = *(unsigned __int16 *)(a2 + 66);
              else
                v59 = 0;
              v61 = *(_DWORD *)(a2 + 112) + v59;
              v62 = &a4[407 * a7 + 375];
            }
            *v62 += v61;
LABEL_65:
            if ( !*(_DWORD *)(v44 + 44) )
              return dp_rx_deliver_raw((_QWORD *)v44, (__int64 *)a2, (__int64)a4, a7);
            ++a4[4];
            v63 = *(_QWORD *)(a2 + 224);
            *(_DWORD *)(a2 + 48) |= 0x80u;
            _qdf_nbuf_data_is_ipv4_eapol_pkt(v63);
            return dp_rx_deliver_to_stack(a1, v44, (__int64)a4, a2, 0);
          }
          goto LABEL_45;
        }
      }
      if ( *(_DWORD *)(v44 + 44) )
      {
        result = _qdf_nbuf_is_ipv4_wapi_pkt(a2);
        if ( (result & 1) != 0 )
          goto LABEL_47;
        if ( *(_DWORD *)(v44 + 42444) == 2 )
        {
          result = _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a2 + 224));
          if ( (result & 1) != 0 )
            goto LABEL_47;
        }
      }
      v49 = *(_DWORD *)(v44 + 64);
      if ( a5 != 5 || v49 )
      {
        if ( !v49 )
          goto LABEL_47;
LABEL_45:
        if ( (unsigned int)dp_rx_filter_mesh_packets() )
        {
          dp_rx_fill_mesh_stats();
          goto LABEL_47;
        }
        result = qdf_trace_msg(
                   0x82u,
                   5u,
                   "%s: %pK: mesh pkt filtered",
                   v50,
                   v51,
                   v52,
                   v53,
                   v54,
                   v55,
                   v56,
                   v57,
                   "dp_rx_process_rxdma_err",
                   a1);
        v64 = *(_QWORD *)(v44 + 24);
        if ( v64 )
          ++*(_DWORD *)(v64 + 392);
        goto LABEL_70;
      }
    }
    else
    {
      v60 = jiffies;
      if ( dp_rx_process_rxdma_err___last_ticks_28 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x82u,
                   5u,
                   "%s: %pK: INVALID vdev %pK OR osif_rx",
                   v32,
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   "dp_rx_process_rxdma_err",
                   a1,
                   0);
        dp_rx_process_rxdma_err___last_ticks_28 = v60;
      }
    }
    if ( a2 )
      result = _qdf_nbuf_free(a2);
    if ( a1 )
      ++*(_DWORD *)(a1 + 13692);
  }
  else
  {
    v47 = jiffies;
    if ( dp_rx_process_rxdma_err___last_ticks_26 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: txrx_peer is NULL",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "dp_rx_process_rxdma_err");
      dp_rx_process_rxdma_err___last_ticks_26 = v47;
    }
    if ( a1 )
    {
      ++*(_QWORD *)(a1 + 13720);
      if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
        v48 = *(unsigned __int16 *)(a2 + 66);
      else
        v48 = 0;
      *(_QWORD *)(a1 + 13728) += (unsigned int)(*(_DWORD *)(a2 + 112) + v48);
    }
    return dp_rx_process_invalid_peer_wrapper(a1, a2, 1, a6);
  }
  return result;
}
