__int64 __fastcall dp_rx_peer_map_handler(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 a3,
        unsigned int a4,
        unsigned __int16 *a5,
        unsigned __int16 a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  unsigned int v22; // w26
  unsigned int v23; // w24
  __int64 v24; // x7
  int v25; // w8
  int v26; // w9
  int v27; // w10
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v37; // x20
  __int64 v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 add_id; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x25
  __int64 v57; // x20
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x8
  __int64 v67; // x4
  __int64 v68; // x5
  __int64 v69; // x6
  __int64 v70; // x7
  unsigned int v71; // w8
  unsigned int v78; // w10
  __int64 v80; // x10
  __int64 v81; // x11
  __int64 v82; // x10
  __int64 v83; // x11
  __int64 v84; // x10
  __int64 v85; // x8
  __int64 v86; // x8
  _DWORD *v87; // x8
  __int64 v88; // x2
  __int64 v89; // x3
  __int64 v91; // x0
  unsigned int v93; // w9

  v22 = (unsigned __int16)a2;
  v23 = a3;
  if ( a5 )
  {
    v24 = *(unsigned __int8 *)a5;
    v25 = *((unsigned __int8 *)a5 + 1);
    v26 = *((unsigned __int8 *)a5 + 2);
    v27 = *((unsigned __int8 *)a5 + 5);
  }
  else
  {
    v26 = 0;
    v24 = 0;
    v25 = 0;
    v27 = 0;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: peer_map_event (soc:%pK): peer_id %d, hw_peer_id %d, peer_mac %02x:%02x:%02x:**:**:%02x, vdev_id %d",
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    "dp_rx_peer_map_handler",
    a1,
    (unsigned __int16)a2,
    a3,
    v24,
    v25,
    v26,
    v27,
    (unsigned __int8)a4);
  if ( a1 )
    ++*(_DWORD *)(a1 + 17560);
  if ( !a7 )
  {
    if ( (*(_BYTE *)(a1 + 17706) & 1) == 0 && (int)wlan_cfg_get_max_ast_idx(*(_QWORD *)(a1 + 40)) <= (int)v23 )
    {
      qdf_trace_msg(
        0x81u,
        2u,
        "%s: %pK: invalid hw_peer_id: %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "dp_rx_peer_map_handler",
        a1,
        v23);
      v91 = printk(
              &unk_AAA255,
              "0",
              "dp_rx_peer_map_handler",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_peer.c");
      dump_stack(v91);
    }
    add_id = dp_peer_find_add_id((_QWORD *)a1, a5, a2, a4, 1, v28, v29, v30, v31, v32, v33, v34, v35);
    if ( add_id )
    {
      v56 = *(_QWORD *)(add_id + 24);
      *(_WORD *)(add_id + 498) = a6;
      v57 = add_id;
      *(_WORD *)(add_id + 496) = a3;
      if ( *(_DWORD *)(v56 + 32) == 3 && (*(_BYTE *)(add_id + 120) & 0x20) == 0 )
      {
        if ( (unsigned int)qdf_mem_cmp((const void *)(add_id + 44), (const void *)(v56 + 96), 6u) )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: %pK: STA vdev bss_peer",
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "dp_rx_peer_map_handler",
            a1);
          v66 = *(_QWORD *)v57;
          *(_BYTE *)(v57 + 120) |= 1u;
          if ( v66 )
            *(_BYTE *)(v66 + 88) |= 2u;
        }
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: bss ast_hash 0x%x, ast_index 0x%x",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "dp_rx_peer_map_handler",
          a6,
          v23);
        *(_WORD *)(v56 + 76) = a6;
        *(_WORD *)(v56 + 78) = a3;
        dp_tx_cfg_astidx_cache_mapping_wrapper(a1);
      }
      if ( (*(_BYTE *)(a1 + 17706) & 1) == 0 && !*(_QWORD *)(v57 + 32) )
      {
        if ( a5 )
        {
          v67 = *(unsigned __int8 *)a5;
          v68 = *((unsigned __int8 *)a5 + 1);
          v69 = *((unsigned __int8 *)a5 + 2);
          v70 = *((unsigned __int8 *)a5 + 5);
        }
        else
        {
          v69 = 0;
          v67 = 0;
          v68 = 0;
          v70 = 0;
        }
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Add self ast from map %02x:%02x:%02x:**:**:%02x",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "dp_rx_peer_map_handler",
          v67,
          v68,
          v69,
          v70);
      }
      if ( *(_BYTE *)(*(_QWORD *)(a1 + 1128) + 74576LL)
        && *(_QWORD *)(*(_QWORD *)(v57 + 88) + 32LL)
        && (*(_DWORD *)(v57 + 408) != 1 || !*(_QWORD *)(v57 + 416)) )
      {
        v80 = *(unsigned int *)(*(_QWORD *)(a1 + 40) + 132LL);
        if ( (_DWORD)v80 )
        {
          *(_QWORD *)(*(_QWORD *)(a1 + 20200) + 24LL * *(_QWORD *)(a1 + 20248)) = 1000 * (jiffies / 0xFAuLL)
                                                                                + 4 * (jiffies % 0xFAuLL);
          *(_DWORD *)(*(_QWORD *)(a1 + 20200) + 24LL * *(_QWORD *)(a1 + 20248) + 8) = *(unsigned __int16 *)(v57 + 16);
          *(_DWORD *)(*(_QWORD *)(a1 + 20200) + 24LL * *(_QWORD *)(a1 + 20248) + 12) = *(_QWORD *)(*(_QWORD *)(v57 + 88)
                                                                                                 + 56LL);
          *(_DWORD *)(*(_QWORD *)(a1 + 20200) + 24LL * *(_QWORD *)(a1 + 20248) + 16) = 0;
          v81 = *(_QWORD *)(a1 + 20248);
          v82 = v81 + 1 == v80 ? 0LL : v81 + 1;
          v83 = *(_QWORD *)(a1 + 40);
          *(_QWORD *)(a1 + 20248) = v82;
          v84 = *(unsigned int *)(v83 + 132);
          if ( (_DWORD)v84 )
          {
            *(_QWORD *)(*(_QWORD *)(a1 + 20200) + 24LL * *(_QWORD *)(a1 + 20248)) = 1000 * (jiffies / 0xFAuLL)
                                                                                  + 4 * (jiffies % 0xFAuLL);
            *(_DWORD *)(*(_QWORD *)(a1 + 20200) + 24LL * *(_QWORD *)(a1 + 20248) + 8) = *(unsigned __int16 *)(v57 + 16);
            *(_DWORD *)(*(_QWORD *)(a1 + 20200) + 24LL * *(_QWORD *)(a1 + 20248) + 12) = *(_QWORD *)(*(_QWORD *)(v57 + 88) + 2360LL);
            *(_DWORD *)(*(_QWORD *)(a1 + 20200) + 24LL * *(_QWORD *)(a1 + 20248) + 16) = 16;
            v85 = *(_QWORD *)(a1 + 20248);
            if ( v85 + 1 == v84 )
              v86 = 0;
            else
              v86 = v85 + 1;
            *(_QWORD *)(a1 + 20248) = v86;
          }
        }
      }
      v87 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 360LL);
      if ( v87 )
      {
        v88 = *(unsigned __int16 *)(v57 + 16);
        v89 = *(unsigned __int8 *)(*(_QWORD *)(v57 + 24) + 59LL);
        if ( *(v87 - 1) != -1684742716 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64))v87)(a1, 0, v88, v89, v57 + 44);
      }
    }
    return 0;
  }
  if ( (*(_BYTE *)(a1 + 17706) & 1) != 0 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13304);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13304);
    *(_QWORD *)(a1 + 13312) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 13324) <= v22 )
    goto LABEL_15;
  v37 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * (unsigned __int16)a2);
  if ( v37 )
  {
    if ( *(unsigned __int8 *)(v37 + 388) <= 2u )
    {
      v71 = *(_DWORD *)(v37 + 40);
      while ( v71 )
      {
        _X12 = (unsigned int *)(v37 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v78 = __ldxr(_X12);
          if ( v78 != v71 )
            break;
          if ( !__stlxr(v71 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v78 == v71;
        v71 = v78;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v37 + 316);
          __asm { PRFM            #0x11, [X8] }
          do
            v93 = __ldxr(_X8);
          while ( __stxr(v93 + 1, _X8) );
          goto LABEL_16;
        }
      }
    }
LABEL_15:
    v37 = 0;
  }
LABEL_16:
  v38 = *(_QWORD *)(a1 + 13312);
  if ( (v38 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13312) = v38 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13304);
    if ( !v37 )
      return 0;
    goto LABEL_18;
  }
  raw_spin_unlock(a1 + 13304);
  if ( v37 )
LABEL_18:
    dp_peer_unref_delete(v37, 0xDu, v39, v40, v41, v42, v43, v44, v45, v46);
  return 0;
}
