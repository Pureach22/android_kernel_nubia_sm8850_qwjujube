__int64 __fastcall rmnet_shs_flush_table(unsigned int a1, unsigned int a2)
{
  __int64 v2; // x22
  __int64 v3; // x21
  __int64 *v4; // x24
  int cpu_qtail; // w23
  __int64 v6; // x1
  __int64 v7; // x25
  __int64 v8; // x8
  int v9; // w9
  int v10; // w27
  int v11; // w20
  __int64 *v12; // x19
  __int64 v13; // x28
  int v14; // w26
  __int64 v15; // x8
  unsigned int v16; // w19
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x1
  char *v20; // x8
  __int64 v21; // x10
  int v22; // w9
  int v23; // w11
  unsigned int v24; // w9
  char *v25; // x8
  unsigned __int64 v26; // x19
  _QWORD *v27; // x8
  unsigned __int64 *v28; // x23
  _QWORD *v29; // x19
  __int64 result; // x0
  __int64 v33; // [xsp+10h] [xbp-20h]
  _QWORD *v34; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v35[2]; // [xsp+20h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_spin_lock_bh(&rmnet_shs_ht_splock);
  v35[0] = 0;
  v34 = nullptr;
  rmnet_shs_update_cpu_proc_q_all_cpus();
  v2 = 0;
  v3 = 0;
  v33 = 0;
  do
  {
    v4 = &rmnet_shs_cpu_node_tbl[5 * v2];
    cpu_qtail = rmnet_shs_get_cpu_qtail(v2);
    v6 = 0;
    v7 = *v4;
    if ( (__int64 *)*v4 != v4 )
    {
      v8 = *v4;
      do
      {
        v9 = *(_DWORD *)(v8 + 60);
        v8 = *(_QWORD *)v8;
        v6 = (unsigned int)(v9 + v6);
      }
      while ( (__int64 *)v8 != v4 );
    }
    if ( rmnet_shs_inst_rate_switch )
    {
      rmnet_shs_core_prio_check((unsigned int)v2, v6);
      v7 = *v4;
    }
    if ( (__int64 *)v7 != v4 )
    {
      v10 = 0;
      while ( 1 )
      {
        v11 = *(_DWORD *)(v7 + 56);
        v12 = *(__int64 **)v7;
        if ( v11 )
        {
          v13 = *(_QWORD *)(v7 + 48);
          v14 = *(_DWORD *)(v7 + 60);
          if ( *(_BYTE *)(v7 + 152) )
            v3 = v7 - 64;
          if ( (unsigned int)rmnet_shs_chk_and_flush_node(v7 - 64, a1, a2, v35) )
          {
            if ( *(unsigned __int16 *)(v7 + 146) > 7uLL )
              goto LABEL_53;
            v10 += v14;
            HIDWORD(rmnet_shs_cpu_node_tbl[5 * *(unsigned __int16 *)(v7 + 146) + 3]) -= v11;
            v15 = *(unsigned __int16 *)(v7 + 146);
            *(_DWORD *)(v7 + 60) = 0;
            HIDWORD(v33) += v11;
            LODWORD(v33) = v33 + v13;
            if ( v2 == v15 )
            {
              cpu_qtail += v11;
              *(_DWORD *)(v7 + 124) = cpu_qtail;
            }
          }
        }
        v7 = (__int64)v12;
        if ( v12 == v4 )
          goto LABEL_19;
      }
    }
    v10 = 0;
LABEL_19:
    if ( rmnet_shs_inst_rate_switch )
    {
      if ( (unsigned int)rmnet_shs_is_lpwr_cpu(v2) && !*((_BYTE *)v4 + 36) )
      {
        v16 = rmnet_shs_inst_rate_interval;
        v17 = ktime_get_with_offset(1);
        v18 = ns_to_timespec64(v17);
        v20 = (char *)&rmnet_shs_cfg + 120 * v2;
        v21 = v19 - *((_QWORD *)v20 + 59) + 1000000000 * (v18 - *((_QWORD *)v20 + 58));
        if ( v16 <= 5 )
          v22 = 5;
        else
          v22 = v16;
        v23 = 1000000 * v22;
        v24 = *((_DWORD *)v20 + 120);
        v25 = v20 + 368;
        if ( v21 >= v23 )
        {
          if ( v24 > rmnet_shs_cpu_max_coresum[v2] )
            rmnet_shs_cpu_max_coresum[v2] = v24;
          *((_QWORD *)v25 + 12) = v18;
          *((_QWORD *)v25 + 13) = v19;
        }
        else
        {
          v10 += v24;
        }
        *((_DWORD *)v25 + 28) = v10;
      }
      rmnet_shs_core_prio_check((unsigned int)v2, 0);
    }
    if ( (unsigned int)rmnet_shs_get_cpu_qdiff(v2) >= rmnet_shs_cpu_max_qdiff[v2] )
      rmnet_shs_cpu_max_qdiff[v2] = rmnet_shs_get_cpu_qdiff(v2);
    ++v2;
  }
  while ( v2 != 8 );
  qword_19460 -= (unsigned int)v33;
  qword_19468 -= HIDWORD(v33);
  if ( v35[0] && v3 )
  {
    v26 = *(unsigned __int16 *)(v3 + 210);
    if ( v26 > 8 )
LABEL_53:
      __break(0x5512u);
    byte_1949F = 1;
    raw_spin_unlock_bh(&rmnet_shs_ht_splock);
    v27 = (_QWORD *)v35[0];
    *(_WORD *)(v3 + 218) = 0;
    v34 = v27;
    if ( v27 )
    {
      v28 = (unsigned __int64 *)&rmnet_shs_cpu_node_tbl[5 * (unsigned int)v26];
      do
      {
        v29 = (_QWORD *)*v27;
        *v27 = 0;
        rmnet_shs_cpu_node_remove(v3);
        rmnet_rx_handler(&v34);
        rmnet_shs_cpu_node_add(v3, v28);
        v27 = v29;
        v34 = v29;
      }
      while ( v29 );
    }
    raw_spin_lock_bh(&rmnet_shs_ht_splock);
    rmnet_shs_switch_disable();
    byte_1949F = 0;
    word_1948C = 0;
    BYTE1(dword_19499) = BYTE2(dword_19499);
  }
  if ( qword_19460 < 1 || qword_19468 <= 0 )
  {
    qword_19460 = 0;
    qword_19468 = 0;
    word_19492 = 512;
  }
  result = raw_spin_unlock_bh(&rmnet_shs_ht_splock);
  if ( (unsigned __int8)a2 == 1 )
  {
    if ( rmnet_shs_fall_back_timer && qword_19460 && qword_19468 )
    {
      if ( (hrtimer_active(&rmnet_shs_cfg) & 1) != 0 )
        hrtimer_cancel(&rmnet_shs_cfg);
      result = hrtimer_start_range_ns(&rmnet_shs_cfg, (unsigned int)(1000000 * rmnet_shs_timeout), 0, 1);
    }
    ++qword_1A2F8;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
