__int64 __fastcall rmnet_shs_node_can_flush_pkts(__int64 a1, char a2)
{
  unsigned int v2; // w22
  unsigned int v4; // w20
  __int16 v5; // w21
  unsigned int v6; // w23
  unsigned int v7; // w21
  unsigned __int8 v8; // w0
  unsigned int cpu_qhead; // w0
  int v10; // w25
  unsigned int v11; // w26
  unsigned int v12; // w0
  unsigned int v13; // w24
  int v14; // w8
  _QWORD *v15; // x8
  unsigned __int64 v17; // x0
  int core_prio_flow; // w0
  __int64 v19; // x8
  __int64 v20; // x11
  unsigned int v21; // w11
  int v22; // w9
  __int16 v23; // w12
  char v24; // w8
  char v25; // w10
  char v26; // w0
  unsigned __int64 v27; // x8
  int v29; // w12
  __int16 v30; // w11
  char v31; // w9
  char v32; // w12
  char v33; // w9
  char v34; // w10
  char v35; // w9
  __int64 v36; // x3
  __int64 v37; // x5
  __int64 *v38; // x1
  __int64 v39; // x8
  __int64 v40; // x1
  unsigned __int64 StatusReg; // x24
  __int64 v42; // x0
  __int64 v43; // x8

  LOWORD(v2) = *(_WORD *)(a1 + 212);
  LOBYTE(v4) = a2;
  if ( *(_BYTE *)(a1 + 216) )
  {
    LOBYTE(v5) = dword_19499;
    goto LABEL_3;
  }
  v17 = *(unsigned __int16 *)(a1 + 210);
  if ( v17 >= 8 )
    goto LABEL_73;
  if ( BYTE4(rmnet_shs_cpu_node_tbl[5 * (unsigned int)v17 + 4]) && (unsigned int)rmnet_shs_is_lpwr_cpu(v17) )
  {
    core_prio_flow = rmnet_shs_get_core_prio_flow(
                       (unsigned __int8)(word_1949D & ~(rmnet_shs_halt_mask | byte_19496))
                     & (unsigned __int8)*(_WORD *)(a1 + 212));
    LOBYTE(v5) = core_prio_flow;
    if ( (core_prio_flow & 0x80000000) == 0 )
      goto LABEL_3;
    v19 = *(_QWORD *)(a1 + 88);
    if ( v19 )
    {
      v5 = *(_WORD *)(v19 + 316);
      goto LABEL_3;
    }
  }
  else
  {
    v20 = *(_QWORD *)(a1 + 88);
    if ( v20 )
    {
      v5 = *(_WORD *)(a1 + 210);
      v21 = *(unsigned __int16 *)(v20 + 316);
      v22 = rmnet_shs_halt_mask | (unsigned __int8)byte_19496;
      if ( (v22 & (1 << v5)) != 0
        || ((*(_QWORD *)((char *)&_cpu_active_mask + (((unsigned __int64)*(unsigned __int16 *)(a1 + 210) >> 3) & 0x1FF8)) >> *(_WORD *)(a1 + 210))
          & 1) == 0 )
      {
        v23 = *(_WORD *)(a1 + 212);
        v24 = word_1949D;
        if ( (((unsigned __int8)word_1949D >> v21) & 1) != 0 )
          v25 = word_1949D;
        else
          v25 = HIBYTE(word_1949D);
        if ( ((unsigned __int8)(v25 & ~(v22 | v5)) & (unsigned __int8)v23) != 0 )
          v24 = v25;
        v26 = rmnet_shs_get_core_prio_flow((unsigned __int8)(v24 & ~(_BYTE)v22) & (unsigned __int8)v23);
        v27 = *(unsigned __int16 *)(a1 + 210);
        LOBYTE(v5) = v26;
        if ( (((unsigned __int8)byte_19496 >> v27) & 1) != 0 )
        {
          ++qword_1A250;
        }
        else if ( ((*(_QWORD *)((char *)&_cpu_active_mask + ((v27 >> 3) & 0x1FF8)) >> v27) & 1) == 0 )
        {
          ++qword_1A2B0;
        }
      }
      else
      {
        v29 = 1 << v21;
        if ( ((1 << v21) & (unsigned __int8)byte_19496) != 0 )
        {
          v30 = *(_WORD *)(a1 + 212);
          v31 = v30 & ~(_BYTE)v22;
          if ( ((unsigned __int8)v29 & (unsigned __int8)word_1949D) != 0 )
            v32 = word_1949D;
          else
            v32 = HIBYTE(word_1949D);
          v33 = v32 & v31;
          if ( ((1 << v5) & (unsigned __int8)word_1949D) != 0 )
            v34 = word_1949D;
          else
            v34 = HIBYTE(word_1949D);
          if ( v33 )
            v35 = v32;
          else
            v35 = word_1949D;
          if ( v35 != v34 )
            LOBYTE(v5) = rmnet_shs_get_core_prio_flow((unsigned __int8)(v30 & ~byte_19496) & v35);
        }
        else
        {
          if ( v21 > 7 )
            goto LABEL_73;
          if ( !BYTE4(rmnet_shs_cpu_node_tbl[5 * v21 + 4]) )
            LOBYTE(v5) = v21;
        }
      }
      goto LABEL_3;
    }
  }
  LOBYTE(v5) = -1;
LABEL_3:
  v6 = rmnet_shs_idx_from_cpu(v5, *(_BYTE *)(a1 + 212));
  if ( (v6 & 0x80000000) != 0 )
    goto LABEL_74;
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = *(unsigned __int16 *)(a1 + 210);
      if ( (v6 & 0x80000000) != 0 || (*(_BYTE *)(a1 + 222) = 1, !(_BYTE)v2) )
      {
        *(_BYTE *)(a1 + 222) = 0;
        return 1;
      }
      if ( v6 == *(unsigned __int16 *)(a1 + 208) )
        return 1;
      if ( *(_BYTE *)(a1 + 216) )
        v8 = BYTE2(dword_19499);
      else
        v8 = v7;
      cpu_qhead = rmnet_shs_get_cpu_qhead(v8);
      v10 = *(_DWORD *)(a1 + 188);
      v11 = cpu_qhead;
      v2 = *(unsigned __int16 *)(a1 + 210);
      if ( *(_BYTE *)(a1 + 216) )
      {
        if ( !(_BYTE)v4 )
          return 0;
      }
      else if ( (unsigned __int8)v4 <= 3u && cpu_qhead < v10 + (unsigned int)*(unsigned __int16 *)(a1 + 218) )
      {
        if ( (unsigned int)rmnet_shs_get_cpu_qdiff(v2) )
          return 0;
        if ( __CFADD__(qword_1A328++, 1) )
          return 0;
      }
      if ( !rmnet_shs_switch_cores )
        return 1;
      v12 = rmnet_shs_cpu_from_idx(v6, *(unsigned __int8 *)(a1 + 212));
      if ( (v12 & 0x80000000) != 0 )
        return 1;
      v13 = v12;
      if ( v12 > 7 )
        goto LABEL_73;
      HIDWORD(rmnet_shs_cpu_node_tbl[5 * v12 + 3]) += *(_DWORD *)(a1 + 120);
      if ( *(unsigned __int16 *)(a1 + 210) > 7uLL )
        goto LABEL_73;
      HIDWORD(rmnet_shs_cpu_node_tbl[5 * *(unsigned __int16 *)(a1 + 210) + 3]) -= *(_DWORD *)(a1 + 120);
      v14 = *(unsigned __int16 *)(a1 + 218);
      *(_WORD *)(a1 + 208) = v6;
      *(_WORD *)(a1 + 210) = v12;
      if ( v11 < v10 + v14 )
        break;
      if ( v2 <= 7 )
        goto LABEL_18;
LABEL_73:
      __break(0x5512u);
LABEL_74:
      v6 = rmnet_shs_idx_from_cpu(*(_BYTE *)(a1 + 210), *(_BYTE *)(a1 + 212));
    }
    v40 = v10 - v11 + v14;
    ++qword_1A210;
    qword_1A218 += v40;
    rmnet_shs_cpu_ooo(v2, v40);
    v6 = *(unsigned __int8 *)(a1 + 216);
    rmnet_shs_get_cpu_qdiff(v2);
    rmnet_shs_get_cpu_qdiff(v13);
    printk(&unk_15ABE);
    if ( v2 > 7 )
      goto LABEL_73;
LABEL_18:
    if ( BYTE4(rmnet_shs_cpu_node_tbl[5 * v2 + 4]) )
    {
      BYTE5(rmnet_shs_cpu_node_tbl[5 * v13 + 4]) = 1;
      v15 = &rmnet_shs_switch_reason;
    }
    else if ( (((unsigned int)rmnet_shs_halt_mask >> v2) & 1) != 0 )
    {
      v15 = &unk_1A268;
    }
    else
    {
      v15 = &unk_1A208;
    }
    v4 = *(unsigned __int16 *)(a1 + 210);
    ++*v15;
    if ( v4 > 8 )
      goto LABEL_73;
    rmnet_shs_update_cpu_proc_q_all_cpus();
    if ( v4 != 8 )
      break;
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v42 = _traceiter_rmnet_shs_low(0, 6, 25, v36, v7, v37, 3567, a1);
      v43 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v43;
      if ( !v43 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v42);
    }
  }
  v38 = &rmnet_shs_cpu_node_tbl[5 * v4];
  v39 = *(_QWORD *)(a1 + 88);
  *(_DWORD *)(a1 + 188) = *(_DWORD *)(a1 + 120) + *((_DWORD *)v38 + 4);
  if ( v39 )
    *(_WORD *)(v39 + 316) = v13;
  rmnet_shs_cpu_node_move(a1, v38, v2);
  if ( rmnet_shs_debug )
    return 1;
  return 1;
}
