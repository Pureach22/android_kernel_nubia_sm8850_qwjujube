__int64 __fastcall rmnet_shs_assign(__int64 a1, unsigned __int64 a2)
{
  char v4; // w9
  int v5; // w21
  int v6; // w26
  unsigned __int64 StatusReg; // x8
  int v9; // w20
  __int64 *v10; // x8
  __int64 v11; // x22
  unsigned int v12; // w9
  int v13; // w8
  int least_utilized_core; // w0
  int v15; // w8
  __int16 v16; // w26
  __int64 v17; // x8
  int v18; // w9
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x4
  __int16 v27; // w8
  unsigned __int64 v28; // x8
  __int64 v29; // x10
  unsigned __int64 *v30; // x10
  unsigned __int64 v31; // x8
  __int64 v32; // x13
  __int64 v33; // x10
  __int64 v34; // x11
  __int64 v35; // x12
  __int64 v36; // x8
  __int64 v37; // x9
  __int64 v38; // x8
  __int64 v39; // x10
  __int64 v40; // x8
  __int64 v41; // x9
  __int64 v42; // x11
  __int64 v43; // x8
  __int64 v44; // x9
  int v45; // w9
  char v46; // w24
  int v47; // w21
  unsigned int v48; // w2
  unsigned int v49; // w0
  __int16 v50; // w8
  unsigned __int64 v51; // x19
  __int64 v52; // x0
  __int64 v53; // x8
  unsigned __int64 v60; // x9
  unsigned __int64 v63; // x10
  _BYTE v64[4]; // [xsp+Ch] [xbp-84h] BYREF
  _QWORD v65[16]; // [xsp+10h] [xbp-80h] BYREF

  v65[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_BYTE *)a2;
  v5 = (unsigned __int8)byte_19497;
  v64[0] = 0;
  memset(v65, 0, 120);
  if ( (v4 & 1) == 0 && !(unsigned int)rmnet_shs_is_skb_stamping_reqd(a1, v64) )
  {
    v9 = v64[0];
    rmnet_shs_deliver_skb();
    if ( v9 )
    {
      rmnet_shs_create_ping_boost_msg_resp(1, v65);
      rmnet_shs_genl_msg_direct_send_to_userspace(v65);
    }
    goto LABEL_119;
  }
  if ( !v5 || !byte_19494 )
  {
    rmnet_shs_deliver_skb();
LABEL_12:
    ++qword_1A3D0;
    goto LABEL_119;
  }
  if ( (*(_BYTE *)(a1 + 130) & 6) == 0 )
  {
    _skb_get_hash_net(0, a1);
    if ( *(_WORD *)(a2 + 2) )
      goto LABEL_7;
LABEL_16:
    v6 = *(_DWORD *)(a1 + 152);
    goto LABEL_17;
  }
  if ( !*(_WORD *)(a2 + 2) )
    goto LABEL_16;
LABEL_7:
  v6 = 57005;
  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(a1 + 152) = 57005;
  if ( *(_DWORD *)(StatusReg + 40) == BYTE1(dword_19499) && BYTE1(dword_19499) != BYTE2(dword_19499) )
  {
    netif_rx(a1);
    if ( rmnet_shs_max_qmap_steer < (unsigned int)(unsigned __int16)++word_1948C )
    {
      rmnet_shs_flush_table(8u, 0);
      rmnet_shs_switch_disable();
      word_1948C = 0;
      ++qword_1A490;
    }
    goto LABEL_119;
  }
LABEL_17:
  raw_spin_lock_bh(&rmnet_shs_ht_splock);
  v10 = (__int64 *)rmnet_shs_ht[(unsigned int)(1640531527 * v6) >> 23];
  if ( v10 )
  {
    while ( 1 )
    {
      v11 = (__int64)(v10 - 16);
      if ( v10 == &qword_80 )
        goto LABEL_21;
      if ( v6 == *((_DWORD *)v10 + 16) )
        break;
      v10 = (__int64 *)*v10;
      if ( !v10 )
        goto LABEL_21;
    }
    v15 = *((unsigned __int8 *)v10 + 95);
    if ( *(_BYTE *)(v11 + 223) )
    {
      if ( v15 != 2 )
        goto LABEL_56;
      if ( (unsigned int)rmnet_shs_is_filter_match(a1) )
      {
        *(_BYTE *)(v11 + 223) = 1;
LABEL_57:
        raw_spin_unlock_bh(&rmnet_shs_ht_splock);
        v39 = *(_QWORD *)(v11 + 152);
        if ( *(unsigned __int16 *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 6LL) <= 1u )
          v40 = 1;
        else
          v40 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 6LL);
        v41 = *(_QWORD *)(v11 + 160);
        v42 = *(_QWORD *)(v11 + 168);
        *(_QWORD *)(v11 + 144) += v40;
        v43 = v41 + *(unsigned int *)(a1 + 112);
        *(_QWORD *)(v11 + 152) = v39 + 1;
        *(_QWORD *)(v11 + 160) = v43;
        v44 = *(_QWORD *)(v11 + 176);
        *(_QWORD *)(v11 + 168) = v42 + *(unsigned int *)(a1 + 44);
        v38 = v44 + *(unsigned int *)(a1 + 48);
        goto LABEL_61;
      }
      v15 = *(unsigned __int8 *)(v11 + 223);
      if ( v15 == 2 )
      {
        *(_BYTE *)(v11 + 223) = 0;
      }
      else
      {
LABEL_56:
        if ( v15 == 1 )
          goto LABEL_57;
      }
    }
    if ( !*(_BYTE *)(v11 + 216) )
      goto LABEL_71;
    rmnet_shs_update_cpu_proc_q_all_cpus();
    v45 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40);
    if ( v45 != BYTE2(dword_19499) )
      ++qword_1A4A8;
    if ( (unsigned __int8)dword_19499 == BYTE2(dword_19499) )
    {
      ++*(_WORD *)(v11 + 218);
      rmnet_shs_chain_to_skb_list(a1, v11);
      if ( (rmnet_module_hook_is_set(4) & 1) == 0 )
      {
        v46 = 0;
        v47 = 2;
        ++qword_1A498;
        goto LABEL_77;
      }
      if ( (unsigned int)rmnet_shs_get_cpu_qhead(BYTE2(dword_19499)) >= *(_DWORD *)(v11 + 188)
                                                                      + (unsigned int)*(unsigned __int16 *)(v11 + 218) )
      {
        v46 = 0;
        v47 = 3;
        goto LABEL_77;
      }
      if ( rmnet_shs_max_qmap_pkt && *(_DWORD *)(v11 + 120) > (unsigned int)rmnet_shs_max_qmap_pkt )
      {
        v46 = 0;
        v47 = 1;
        ++rmnet_shs_flush_reason;
        goto LABEL_77;
      }
      goto LABEL_53;
    }
    v48 = *(unsigned __int16 *)(v11 + 210);
    if ( v48 != BYTE2(dword_19499) )
    {
      if ( BYTE2(dword_19499) > 8u )
        goto LABEL_113;
      rmnet_shs_cpu_node_move(v11, &rmnet_shs_cpu_node_tbl[5 * BYTE2(dword_19499)], v48);
      ++qword_1A260;
    }
    rmnet_shs_start_phy_switch(v11, a2, *(_QWORD *)(a1 + 16));
    netif_rx(a1);
    goto LABEL_76;
  }
LABEL_21:
  v12 = (unsigned __int8)word_1949D;
  v13 = (unsigned __int8)byte_19497 & ~(rmnet_shs_halt_mask | (unsigned __int8)byte_19496);
  if ( ((unsigned __int8)v13 & HIBYTE(word_1949D)) != 0 )
    v12 = HIBYTE(word_1949D);
  if ( *(_WORD *)(a2 + 2) )
  {
    least_utilized_core = rmnet_shs_wq_get_least_utilized_core(v13 & v12);
    if ( (least_utilized_core & 0x80000000) == 0 )
      goto LABEL_25;
LABEL_28:
    ++qword_1A438;
    goto LABEL_118;
  }
  least_utilized_core = rmnet_shs_get_core_prio_flow((unsigned __int8)v13 & (unsigned __int8)v12);
  if ( least_utilized_core < 0 )
    goto LABEL_28;
LABEL_25:
  if ( qword_19470 >= 701 )
  {
    ++qword_1A3E8;
LABEL_118:
    raw_spin_unlock_bh(&rmnet_shs_ht_splock);
    ++qword_1A3C8;
    rmnet_shs_deliver_skb();
    goto LABEL_119;
  }
  v16 = least_utilized_core;
  v11 = _kmalloc_cache_noprof(_rcu_read_unlock, 2336, 232);
  if ( !v11 )
  {
    ++qword_1A3D8;
    goto LABEL_118;
  }
  _X8 = &qword_19470;
  __asm { PRFM            #0x11, [X8] }
  do
    v60 = __ldxr((unsigned __int64 *)&qword_19470);
  while ( __stxr(v60 + 1, (unsigned __int64 *)&qword_19470) );
  v17 = *(_QWORD *)(a1 + 16);
  v18 = *(_DWORD *)(a1 + 152);
  *(_WORD *)(v11 + 210) = v16;
  *(_QWORD *)(v11 + 80) = v17;
  *(_DWORD *)(v11 + 192) = v18;
  *(_WORD *)(v11 + 208) = rmnet_shs_idx_from_cpu(v16, v5);
  *(_QWORD *)(v11 + 64) = v11 + 64;
  *(_QWORD *)(v11 + 72) = v11 + 64;
  rmnet_shs_get_update_skb_hdr_info(a1, v11);
  *(_BYTE *)(v11 + 225) = rmnet_shs_is_skb_l4s(a1, v19, v20, v21, v22);
  *(_BYTE *)(v11 + 226) = rmnet_shs_is_skb_ecn_capable(a1, v23, v24, v25, v26);
  rmnet_shs_wq_create_new_flow(v11);
  if ( !*(_QWORD *)(v11 + 88) )
  {
    _X9 = &qword_19470;
    __asm { PRFM            #0x11, [X9] }
    do
      v63 = __ldxr((unsigned __int64 *)&qword_19470);
    while ( __stxr(v63 - 1, (unsigned __int64 *)&qword_19470) );
    kfree(v11);
    goto LABEL_118;
  }
  if ( *(_WORD *)(a2 + 2) )
  {
    rmnet_shs_update_cpu_proc_q_all_cpus();
    rmnet_shs_start_phy_switch(v11, a2, *(_QWORD *)(a1 + 16));
  }
  else
  {
    v27 = (unsigned __int8)byte_19498;
    *(_WORD *)(v11 + 212) = (unsigned __int8)byte_19497;
    *(_WORD *)(v11 + 214) = v27;
  }
  v28 = *(unsigned __int16 *)(v11 + 210);
  if ( v28 > 8 )
  {
LABEL_113:
    __break(0x5512u);
    v51 = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v51 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v51 + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(v51 + 16);
      v52 = _traceiter_rmnet_shs_err(0, 7, 37, 3567, 3567, 3567, 3567, 0, 0);
      v53 = *(_QWORD *)(v51 + 16) - 1LL;
      *(_DWORD *)(v51 + 16) = v53;
      if ( !v53 || !*(_QWORD *)(v51 + 16) )
        preempt_schedule_notrace(v52);
    }
    goto LABEL_12;
  }
  v29 = *(_QWORD *)(v11 + 80);
  if ( v29 == -2688 )
    ++rmnet_shs_crit_err;
  else
    *(_BYTE *)(*(_QWORD *)(v11 + 88) + 324LL) = *(_BYTE *)(v29 + 2688);
  rmnet_shs_cpu_node_add(v11, (unsigned __int64 *)&rmnet_shs_cpu_node_tbl[5 * (unsigned int)v28]);
  v30 = &rmnet_shs_ht[(unsigned int)(1640531527 * *(_DWORD *)(a1 + 152)) >> 23];
  v31 = *v30;
  *(_QWORD *)(v11 + 128) = *v30;
  *(_QWORD *)(v11 + 136) = v30;
  atomic_store(v11 + 128, v30);
  if ( v31 )
    *(_QWORD *)(v31 + 8) = v11 + 128;
  if ( !(unsigned int)rmnet_shs_is_filter_match(a1) )
  {
    if ( *(_BYTE *)(v11 + 216) )
    {
      netif_rx(a1);
LABEL_53:
      raw_spin_unlock_bh(&rmnet_shs_ht_splock);
      goto LABEL_119;
    }
LABEL_71:
    rmnet_shs_chain_to_skb_list(a1, v11);
LABEL_76:
    v47 = 0;
    v46 = 1;
LABEL_77:
    if ( !(_BYTE)word_19492 && qword_19468 && rmnet_shs_fall_back_timer )
    {
      word_19492 = 1;
      raw_spin_unlock_bh(&rmnet_shs_ht_splock);
      if ( (hrtimer_active(&rmnet_shs_cfg) & 1) != 0 )
        hrtimer_cancel(&rmnet_shs_cfg);
      hrtimer_start_range_ns(&rmnet_shs_cfg, (unsigned int)(1000000 * rmnet_shs_timeout), 0, 1);
    }
    else
    {
      raw_spin_unlock_bh(&rmnet_shs_ht_splock);
    }
    if ( qword_19468 <= (unsigned int)rmnet_shs_pkts_store_limit )
    {
      if ( qword_19460 <= (unsigned int)rmnet_shs_byte_store_limit )
      {
        if ( (v46 & 1) != 0 )
        {
          v50 = *(_WORD *)a2;
          if ( qword_19468 && (v50 & 4) != 0 )
          {
            if ( rmnet_shs_stats_enabled )
              ++qword_1A310;
          }
          else if ( HIBYTE(word_19492) == 1 )
          {
            ++qword_1A2E0;
            if ( rmnet_shs_debug )
              trace_rmnet_shs_high_0();
          }
          else
          {
            if ( !qword_19468 || (v50 & 4) != 0 || byte_19495 == 1 )
              goto LABEL_119;
            ++qword_1A2F0;
          }
          v49 = 0;
        }
        else
        {
          if ( rmnet_shs_debug )
            trace_rmnet_shs_high_0();
          if ( rmnet_shs_stats_enabled )
            ++qword_1A318;
          v49 = v47;
        }
      }
      else
      {
        if ( rmnet_shs_stats_enabled )
          ++qword_1A2D8;
        v49 = 6;
      }
    }
    else
    {
      if ( rmnet_shs_stats_enabled )
        ++qword_1A2D0;
      v49 = 5;
    }
    rmnet_shs_flush_table(v49, 0);
    goto LABEL_119;
  }
  *(_BYTE *)(v11 + 223) = 1;
  raw_spin_unlock_bh(&rmnet_shs_ht_splock);
  v32 = *(unsigned int *)(a1 + 48);
  v33 = *(_QWORD *)(v11 + 168) + *(unsigned int *)(a1 + 44);
  v34 = *(_QWORD *)(v11 + 144);
  v35 = *(_QWORD *)(v11 + 152);
  if ( *(unsigned __int16 *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 6LL) <= 1u )
    v36 = 1;
  else
    v36 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 6LL);
  *(_QWORD *)(v11 + 160) += *(unsigned int *)(a1 + 112);
  *(_QWORD *)(v11 + 168) = v33;
  v37 = *(_QWORD *)(v11 + 176);
  *(_QWORD *)(v11 + 144) = v34 + v36;
  *(_QWORD *)(v11 + 152) = v35 + 1;
  v38 = v37 + v32;
LABEL_61:
  *(_QWORD *)(v11 + 176) = v38;
  rmnet_shs_ll_handler(a1, a2);
LABEL_119:
  _ReadStatusReg(SP_EL0);
  return 0;
}
